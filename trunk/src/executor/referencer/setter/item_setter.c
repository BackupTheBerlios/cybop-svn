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

#ifndef ITEM_SETTER_SOURCE
#define ITEM_SETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/modifier/assigner.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

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
 * Sets count source item elements into the destination item
 * at position index.
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
void set_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set item.");

    // The destination data, count.
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    // The source data, count.
    void* sd = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;

    // Get destination data, count.
    get((void*) &dd, p0, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dc, p0, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get source data, count.
    get((void*) &sd, p1, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sc, p1, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // Set source- to destination data.
    set_array_offset(dd, sd, p2, p3, p4, p5);

    // The new destination count.
    // CAUTION! Simply adding the source- to the destination count
    // is not always correct! The source is added to the destination
    // at position index and not always appended at the end,
    // i.e. existing elements may be overwritten as well.
    // Therefore, the source count is added to the destination index
    // PLUS ONE, because count is always one value greater than index.
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Add destination index to new destination count.
    add_integer((void*) &c, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Add source count to new destination count.
    add_integer((void*) &c, sc, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Set destination count.
    set_array(dc, (void*) &c, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* ITEM_SETTER_SOURCE */
#endif
