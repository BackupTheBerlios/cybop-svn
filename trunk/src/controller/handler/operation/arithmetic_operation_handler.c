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
 * @version $RCSfile: arithmetic_operation_handler.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARITHMETIC_OPERATION_HANDLER_SOURCE
#define ARITHMETIC_OPERATION_HANDLER_SOURCE

#include "../../../applicator/calculator/addition_calculator.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/cybol/operation/arithmetic_operation_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../logger/logger.c"

/**
 * Handles the arithmetic operation signal.
 *
 * @param p0 the comparison result
 * @param p1 the signal model array (operation)
 * @param p2 the signal model array (operation) count
 * @param p3 the signal details array (parametres)
 * @param p4 the signal details array (parametres) count
 * @param p5 the knowledge memory part
 */
void handle_arithmetic_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle arithmetic operation.");

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) ADD_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) ADD_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                calculate_addition(p3, p4, p5);
            }
        }

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                calculate_division(p3, p4, p5);
            }
        }

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                calculate_multiplication(p3, p4, p5);
            }
        }

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                calculate_subtraction(p3, p4, p5);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle arithmetic operation. The comparison result is null.");
    }
}

/* ARITHMETIC_OPERATION_HANDLER_SOURCE */
#endif
