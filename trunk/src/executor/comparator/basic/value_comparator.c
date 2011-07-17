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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VALUE_COMPARATOR_SOURCE
#define VALUE_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/character_comparator.c"
#include "../../../executor/comparator/basic/double_comparator.c"
#include "../../../executor/comparator/basic/fraction_comparator.c"
#include "../../../executor/comparator/basic/integer_comparator.c"
#include "../../../executor/comparator/basic/pointer_comparator.c"
#include "../../../executor/comparator/basic/unsigned_long_comparator.c"
#include "../../../executor/comparator/basic/wide_character_comparator.c"
#include "../../../logger/logger.c"

//
// Models of abstraction "complex" or "fraction" are not
// considered as container, since the comparison of their
// elements follows special rules.
//
// Example:
//
// The two fractions 4 / 2 and 2 / 1 are identical even though
// their numerators and denominators differ. If the fractions
// were treated as containers and their elements compared one by one,
// then neither the numerators 4 and 2 nor the denominators 2 and 1
// would be equal.
//
// Therefore, such constructs are static and treated as
// primitive data types, but NOT as dynamic containers.
// The number of their elements is fixed.
// The fraction has two elements: numerator and denominator.
// It needs a special comparison function that knows how to
// treat fractions correctly.
//

/**
 * Compares the left- with the right value.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 */
void compare_value(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare value.");

        // The comparison result.
        // CAUTION! It is used instead of if-else statements.
        // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_character(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_double(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *FRACTION_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_fraction(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_pointer(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_unsigned_long(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_wide_character(p0, p1, p2, p3);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare value. The operand abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare value. The operand abstraction is null.");
    }
}

/**
 * Compares the left- with the right value
 * using the given index to calculate an offset.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the index
 */
void compare_value_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare value offset.");

    // The left value, right value.
    // CAUTION! They HAVE TO BE initialised with p1 and p2,
    // since an offset is added below.
    void* l = p1;
    void* r = p2;

    // Add offset to left value, right value.
    add_offset((void*) &l, p4, p5);
    add_offset((void*) &r, p4, p5);

    // Compare left value with right value.
    compare_value(p0, l, r, p3, p4);
}

/* VALUE_COMPARATOR_SOURCE */
#endif
