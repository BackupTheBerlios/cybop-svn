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
 * @version $RCSfile: arithmetic_operation_handler.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARITHMETIC_OPERATION_HANDLER_SOURCE
#define ARITHMETIC_OPERATION_HANDLER_SOURCE

#include "../../../applicator/calculator/addition_calculator.c"
#include "../../../constant/model/cybol/operation/arithmetic_operation_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../logger/logger.c"

/**
 * Handles the arithmetic operation signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the model / signal / operation
 * @param p11 the model / signal / operation count
 * @param p12 the details / parameters
 * @param p13 the details / parameters count
 * @param p14 the signal priority (Hand over as reference!)
 * @param p15 the signal identification (Hand over as reference!)
 * @param p16 the comparison result
 */
void handle_arithmetic_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle arithmetic operation.");

    // The comparison result.
    int* r = (int*) p16;

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) ADD_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) ADD_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            calculate_addition(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            calculate_division(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            calculate_multiplication(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            calculate_subtraction(p12, p13, p1, p2, p3);
        }
    }
}

/* ARITHMETIC_OPERATION_HANDLER_SOURCE */
#endif
