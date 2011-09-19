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

#ifndef VALUE_CALCULATOR_SOURCE
#define VALUE_CALCULATOR_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/double_comparator.c"
#include "../../../executor/comparator/basic/fraction_comparator.c"
#include "../../../executor/comparator/basic/integer_comparator.c"
#include "../../../executor/comparator/basic/part_comparator.c"
#include "../../../executor/comparator/basic/pointer_comparator.c"
#include "../../../executor/comparator/basic/unsigned_long_comparator.c"
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
 * Calculates the result using the given operand and operation.
 *
 * @param p0 the result, which is the operand BEFORE the operation
 * @param p1 the operand
 * @param p2 the operation abstraction
 * @param p3 the operand abstraction
 */
void calculate_value(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate value.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_double(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) FRACTION_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_fraction(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) ITEM_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_item(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_part(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_pointer(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_unsigned_long(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not calculate value. The operand abstraction is unknown.");
    }
}

/**
 * Calculates the result using the given operand and operation
 * using the given index to calculate an offset.
 *
 * @param p0 the result, which is the operand BEFORE the operation
 * @param p1 the operand
 * @param p2 the operation abstraction
 * @param p3 the operand abstraction
 * @param p4 the index
 */
void calculate_value_offset(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate value offset.");

    // The result value, operand value.
    // CAUTION! They HAVE TO BE initialised with p0 and p1,
    // since an offset is added below.
    void* r = p0;
    void* o = p1;

    // Add offset.
    add_offset((void*) &r, p3, p4);
    add_offset((void*) &o, p3, p4);

    calculate_value(r, o, p2, p3);
}

/* VALUE_CALCULATOR_SOURCE */
#endif
