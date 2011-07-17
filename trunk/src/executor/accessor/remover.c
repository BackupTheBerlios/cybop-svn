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

#ifndef REMOVER_SOURCE
#define REMOVER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/remover/array_remover.c"
#include "../../executor/accessor/remover/compound_remover.c"
#include "../../executor/accessor/remover/signal_memory_remover.c"
#include "../../executor/comparator/all/array_all_comparator.c"

/**
 * Removes the element.
 *
 * CAUTION! Do NOT rename this procedure to "remove",
 * as that name is already used by libc functionality stdio.h:152.
 *
 * @param p0 the model
 * @param p1 the model size
 * @param p2 the model index
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void remove_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_array_elements(p0, p1, p2, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_complex_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_compound_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_datetime_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_array_elements(p0, p1, p2, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_fraction_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_array_elements(p0, p1, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_internal_memory_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) POINTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_array_elements(p0, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_signal_memory_element(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_array_elements(p0, p1, p2, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            remove_array_elements(p0, p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not remove element. The abstraction is unknown.");
    }
}

/* REMOVER_SOURCE */
#endif
