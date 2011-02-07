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

#ifndef REPLACER_SOURCE
#define REPLACER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../executor/memoriser/reallocator.c"

//
// Example 1: Replacement WITHOUT adjustment of size and count:
//
// d = "Have a nice day"
// dc = 15
// ds = 15
// s = "fine"
// sc = 4
// index = 7
// replace(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // Add index
// ns = 7 // Add sc
// ns = 11
// ns < ds
// --> ds is NOT changed
// --> resulting d = "Have a fine day"
//
// Example 2: Replacement WITH adjustment of size and count (sc < dc):
//
// d = "green"
// dc = 5
// ds = 5
// s = "red"
// sc = 3
// index = 0
// replace(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // Add index
// ns = 0 // Add sc
// ns = 3
// ns < ds
// --> ds IS changed from 5 to 3 and d reallocated
// --> resulting d = "red"
// --> if ds was not made smaller, the resulting d would be
//     "reden" with a count of 5, representing a non-existing
//     colour value, which would cause errors
//
// Example 3: Replacement WITH adjustment of size and count (sc < dc):
//
// d = "Have a nice day"
// dc = 15
// ds = 15
// s = "daydream"
// sc = 8
// index = 12
// replace(d, dc, ds, s, sc, index, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
// ns = 0 // Add index
// ns = 12 // Add sc
// ns = 20
// ns > ds
// --> ds IS changed from 15 to 20 and d reallocated
// --> resulting d = "Have a nice daydream"
//

/**
 * Replaces the elements at the given index.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the source element
 * @param p2 the source element count
 * @param p3 the index
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void replace(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** d = (void**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace elements.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                replace_array(*d, p1, p2, p3, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    //??            set_complex_element(*d, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    //??            set_compound_element(*d, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    //??            set_datetime_element(*d, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                replace_array(*d, p1, p2, p3, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    //??            set_fraction_element(*d, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                replace_array(*d, p1, p2, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    //??            set_internal_memory_element(*d, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                replace_array(*d, p1, p2, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

    //??            set_signal_memory_element(*d, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                replace_array(*d, p1, p2, p3, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p4, p5, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                replace_array(*d, p1, p2, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not replace elements. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace elements. The destination is null.");
    }
}

/**
 * Replaces the elements at the given index and adjusts (grows or shrinks)
 * the destination size.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source element
 * @param p4 the source element count
 * @param p5 the index
 * @param p6 the abstraction
 * @param p7 the abstraction count
 */
void replace_adjust(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace elements and adjust size.");

    // The new destination size.
    int ns = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Add destination index to new destination size.
    add_integer((void*) &ns, p5, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Add source count to new destination size.
    add_integer((void*) &ns, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // CAUTION! The destination array needs to be resized not only
    // if the source array is greater, but also if it is smaller!
    // If this was not done, false results might occur.
    //

    // Assign destination size.
    assign(p2, (void*) &ns, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Reallocate destination.
    reallocate(p0, p1, p2, p6, p7);

    // Adjust destination count.
    //
    // CAUTION! Only adjust destination count AFTER having
    // reallocated the destination, because the "reallocate"
    // function relies on the previous count when copying
    // elements to the new allocated destination.
    assign(p1, (void*) &ns, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    replace(p0, p3, p4, p5, p6, p7);
}

/* REPLACER_SOURCE */
#endif
