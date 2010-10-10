/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef SETTER_SOURCE
#define SETTER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../executor/memoriser/reallocator.c"

/**
 * Sets the element.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source element (Hand over as reference!)
 * @param p4 the source element count
 * @param p5 the index
 * @param p6 the abstraction
 * @param p7 the abstraction count
 */
void set(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set element.");

    // Adjust destination size.
    add_integer(p2, p4, (void*) INTEGER_MEMORY_ABSTRACTION);

    // Reallocate destination.
    reallocate(p0, p1, p2, p6, p7);

    // Adjust destination count.
    //
    // CAUTION! Only adjust destination count AFTER having
    // reallocated the destination, because the "reallocate"
    // functions relies on the previous count when copying
    // elements to the new allocated destination.
    add_integer(p1, p4, (void*) INTEGER_MEMORY_ABSTRACTION);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array_elements(p0, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_complex_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_compound_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_datetime_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array_elements(p0, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_fraction_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array_elements(p0, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_internal_memory_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array_elements(p0, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_signal_memory_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array_elements(p0, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p6, p7, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array_elements(p0, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not set element. The abstraction is unknown.");
    }
}

/* SETTER_SOURCE */
#endif
