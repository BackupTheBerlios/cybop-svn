/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_COPIER_SOURCE
#define ITEM_COPIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/memoriser/reallocator/item_reallocator.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../executor/modifier/assigner.c"
#include "../../logger/logger.c"

//
// Example 1: Replacement WITHOUT adjustment (set) of size and count (ds remains as is):
//
// d = "Have a nice day"
// dc = 15
// ds = 15
// s = "fine"
// sc = 4
// index = 7
// set(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // The new size
// ns = 7 // Added index
// ns = 11 // Added sc
// ns < ds
// --> ds is NOT changed
// --> resulting d = "Have a fine day"
//
// Example 2: Replacement WITH adjustment (set_adjust) of size and count (ds gets shrinked):
//
// d = "green"
// dc = 5
// ds = 5
// s = "red"
// sc = 3
// index = 0
// set_adjust(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // The new size
// ns = 0 // Added index
// ns = 3 // Added sc
// ns < ds
// --> ds IS changed from 5 to 3 and d reallocated
// --> resulting d = "red"
// --> if ds was not made smaller, the resulting d would be
//     "reden" with a count of 5, representing a non-existing
//     colour value, which would cause errors
//
// Example 3: Replacement WITH adjustment (set_adjust) of size and count (ds gets enlarged):
//
// d = "Have a nice day"
// dc = 15
// ds = 15
// s = "daydream"
// sc = 8
// index = 12
// set_adjust(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // The new size
// ns = 12 // Added index
// ns = 20 // Added sc
// ns > ds
// --> ds IS changed from 15 to 20 and d reallocated
// --> resulting d = "Have a nice daydream"
//

/**
 * Adjusts the destination item container.
 *
 * CAUTION! Simply adding the source- to the destination count
 * is not always correct! The source is added to the destination
 * at position index and not always appended at the end,
 * i.e. existing elements may be overwritten as well.
 * Therefore, the COUNT is added to the destination INDEX.
 *
 * An extra number one does NOT have to be added!
 * The index plus count is just right.
 *
 * @param p0 the item container
 * @param p1 the operand abstraction
 * @param p2 the count
 * @param p3 the item container index
 */
void copy_item_adjust(void* p0, void* p1, void* p2, void* p3) {

    // The new count.
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Add item container index.
    add_integer((void*) &c, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Add count (number of elements to be copied) to new destination count.
    // CAUTION! Do NOT use source count here, since not all of the source has to be copied.
    add_integer((void*) &c, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Reallocate item.
    reallocate_item(p0, (void*) &c, p1);

    // Set destination count.
    //
    // CAUTION! Do NOT set the destination size here!
    // It was already set in the "reallocate_item" function.
    //
    // Efficiency:
    // One might think that performance would be better
    // if the size would be enlarged in greater blocks,
    // not one by one.
    // But this IS done here! If many elements are to be copied,
    // then their count (number of elements) is added to the size,
    // so that reallocation is necessary only once,
    // and not for each single element.
    copy_item_element_set(p0, (void*) &c, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
}

/**
 * Copies (sets) the array to the item container element.
 *
 * If DATA (not count or size) are set, then the item
 * container count is adjusted automatically.
 *
 * @param p0 the item container
 * @param p1 the array
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the item container index
 * @param p5 the array index
 * @param p6 the item container element index
 */
void copy_item_element_set(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy item element set.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_array_count((void*) &r, p6, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DATA_ITEM_MEMORY_NAME, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Resize the item container's data element.
        // If a count or size are copied, then the following is NOT needed.
        copy_item_adjust(p0, p2, p3, p4);
    }

    // The item container element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get item container element.
    // CAUTION! Get item container element ONLY AFTER
    // having reallocated the item above!
    // Otherwise, a wrong DATA_ITEM pointer will be returned
    // and cause a "Segmentation fault".
    copy_array((void*) &e, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Set array to item container element.
    copy_array(e, p1, p2, p3, p4, p5);
}

/**
 * Copies (appends) the array to the item container element.
 *
 * @param p0 the item container
 * @param p1 the array
 * @param p2 the operand abstraction
 * @param p3 the count
 */
void copy_item_element_append(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy item element append.");

}

/**
 * Copies (gets) the array from the item container element.
 *
 * @param p0 the array
 * @param p1 the item container
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the array index
 * @param p5 the item container index
 * @param p6 the item container element index
 */
void copy_item_element_get(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy item element get.");

    // The item container element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get item container element.
    copy_array((void*) &e, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Get array from item container element.
    copy_array(p0, e, p2, p3, p4, p5);
}

/**
 * Copies count source item elements into the destination item at position index.
 *
 * CAUTION! The size of the destination has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination item
 * @param p1 the source item
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void copy_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy item.");

    // Resize the item container's data element.
    // If a count or size are copied, then the following is NOT needed.
    copy_item_adjust(p0, p2, p3, p4);

    // The destination data.
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source data.
    void* sd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination data.
    copy_array((void*) &dd, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get source data.
    copy_array((void*) &sd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // Set source- to destination data.
    copy_array(dd, sd, p2, p3, p4, p5);
}

/* ITEM_COPIER_SOURCE */
#endif
