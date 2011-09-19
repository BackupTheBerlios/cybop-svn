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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_ALL_CALCULATOR_SOURCE
#define ARRAY_ALL_CALCULATOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../executor/comparator/basic/array_comparator.c"
#include "../../../executor/comparator/basic/integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Calculates all elements of the left- with those of the right array.
 *
 * @param p0 the result (left unchanged in case of an error)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the left array count
 * @param p6 the right array count
 */
void calculate_all_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Calculate all array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    compare_integer_equal((void*) &r, p5, p6);

    if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

        // CAUTION! Both, the left- or the right array count may be
        // handed over alternatively as count parametre, since they are equal.
        calculate_array(p0, p1, p2, p3, p4, p6, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate all array. The left array count is not equal to the right array count.");
    }
}

/* ARRAY_ALL_CALCULATOR_SOURCE */
#endif
