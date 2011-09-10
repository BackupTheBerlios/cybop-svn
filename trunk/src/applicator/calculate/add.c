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
 * @version $RCSfile: addition_calculator.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/arithmetic/addition_arithmetic_operation_cybol_name.c"
#include "../../executor/calculator/fraction_adder/fraction_fraction_adder.c"
#include "../../executor/calculator/integer_adder/integer_integer_adder.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Adds two summands resulting in the sum.
 *
 * Expected parametres:
 * - abstraction (required): the abstraction of the summand 1, summand 2 and sum parameters
 * - summand_1 (required): the first summand for the addition
 * - summand_2 (required): the second summand for the addition
 * - sum (required): the sum resulting from the addition
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_add(void* p0, int* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply add.");

    // The abstraction part.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The summand 1 part.
    void* s1 = *NULL_POINTER_MEMORY_MODEL;
    // The summand 2 part.
    void* s2 = *NULL_POINTER_MEMORY_MODEL;
    // The sum part.
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // The abstraction part model.
    void* am = *NULL_POINTER_MEMORY_MODEL;

    // The abstraction part model data.
    void* amd = *NULL_POINTER_MEMORY_MODEL;

    // Get abstraction part.
    get_name_array((void*) &a, p0, (void*) ABSTRACTION_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get summand 1 part.
    get_name_array((void*) &s1, p0, (void*) SUMMAND_1_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) SUMMAND_1_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get summand 2 part.
    get_name_array((void*) &s2, p0, (void*) SUMMAND_2_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) SUMMAND_2_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get sum part.
    get_name_array((void*) &s, p0, (void*) SUM_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) SUM_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get abstraction part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get abstraction part model data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // CAUTION! Do NOT use the "add" operation for characters!
    // They may be concatenated by using the "append" operation.

    // Add first summand to sum.
    add_integer(s, s1, amd);
    // Add second summand to sum.
    add_integer(s, s2, amd);
}

/* ADD_SOURCE */
#endif
