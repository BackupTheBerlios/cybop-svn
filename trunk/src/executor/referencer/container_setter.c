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
 * @version $RCSfile: accessor.c,v $ $Revision: 1.24 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_SETTER_SOURCE
#define ELEMENT_SETTER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/equality/array_equality_comparator.c"
#include "../../executor/memoriser/reallocator.c"
#include "../../executor/modifier/replacer/array_replacer.c"
#include "../../executor/modifier/replacer/compound_replacer.c"
#include "../../executor/modifier/replacer/part_replacer.c"
#include "../../executor/modifier/replacer/signal_memory_replacer.c"

//
// Example 1: Replacement WITHOUT adjustment (replace) of size and count (ds remains as is):
//
// d = "Have a nice day"
// dc = 15
// ds = 15
// s = "fine"
// sc = 4
// index = 7
// replace(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // The new size
// ns = 7 // Added index
// ns = 11 // Added sc
// ns < ds
// --> ds is NOT changed
// --> resulting d = "Have a fine day"
//
// Example 2: Replacement WITH adjustment (replace_adjust) of size and count (ds gets shrinked):
//
// d = "green"
// dc = 5
// ds = 5
// s = "red"
// sc = 3
// index = 0
// replace_adjust(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
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
// Example 3: Replacement WITH adjustment (replace_adjust) of size and count (ds gets enlarged):
//
// d = "Have a nice day"
// dc = 15
// ds = 15
// s = "daydream"
// sc = 8
// index = 12
// replace_adjust(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // The new size
// ns = 12 // Added index
// ns = 20 // Added sc
// ns > ds
// --> ds IS changed from 15 to 20 and d reallocated
// --> resulting d = "Have a nice daydream"
//

/**
 * Sets the elements of the source- into the destination container,
 * starting from the given index.
 *
 * @param p0 the destination container
 * @param p1 the source container
 * @param p2 the destination container index
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void set_container(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set container.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The source element.
        void* se = *NULL_POINTER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            get_element((void*) &se, p1, (void*) &j, p3, p4);
            set_element(p0, se, (void*) &j, p3, p4);

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare containers. The right container count is null.");
    }
}

/* ELEMENT_SETTER_SOURCE */
#endif
