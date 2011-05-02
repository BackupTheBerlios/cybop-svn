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
 * @version $RCSfile: allocator.c,v $ $Revision: 1.34 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EQUALITY_COMPARATOR_SOURCE
#define EQUALITY_COMPARATOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/comparator/container_comparator.c"

/**
 * Compares two models for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the left model count
 * @param p3 the right model
 * @param p4 the right model count
 * @param p5 the model abstraction
 * @param p6 the model abstraction count
 */
void compare_equal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare for equality.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            compare_equal_complex(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            compare_equal_date_time(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            compare_equal_fraction(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) MODEL_MEMORY_ABSTRACTION, (void*) MODEL_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            compare_equal_model(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            compare_equal_part(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p5, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_container(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare for equality. The operand abstraction is unknown.");
    }
}

/* EQUALITY_COMPARATOR_SOURCE */
#endif
