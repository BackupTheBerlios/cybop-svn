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

#ifndef ITEM_CALCULATOR_SOURCE
#define ITEM_CALCULATOR_SOURCE

#include "../../../constant/abstraction/operation/operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/integer/add_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/divide_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/multiply_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/subtract_integer_calculator.c"
#include "../../../logger/logger.c"

/**
 * Calculates left- with right item.
 *
 * @param p0 the result (left unchanged in case of an error)
 * @param p1 the left item
 * @param p2 the right item
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 */
void calculate_item(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate item.");

    // CAUTION! The sizes do NOT have to be identical,
    // since they just represent allocated memory.
    // For calculation, only the count (actual number of elements)
    // is of interest.

    // The left data, count.
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    void* lc = *NULL_POINTER_MEMORY_MODEL;
    // The right data, count.
    void* rd = *NULL_POINTER_MEMORY_MODEL;
    void* rc = *NULL_POINTER_MEMORY_MODEL;

    // Get left data, count.
    copy_array_forward((void*) &ld, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &lc, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get right data, count.
    copy_array_forward((void*) &rd, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &rc, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    calculate_array(p0, ld, rd, p3, p4, lc, rc, p6, p7);
}

/* ITEM_CALCULATOR_SOURCE */
#endif