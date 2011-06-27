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
 * @version $RCSfile: comparator.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_ARRAY_COMPARATOR_SOURCE
#define COUNT_ARRAY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/array_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares left- and right array count.
 *
 * The actual elements comparison happens in another function.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the left array count
 * @param p3 the right array
 * @param p4 the right array count
 * @param p5 the operation abstraction
 * @param p6 the operand abstraction
 */
void compare_array_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* lc = (int*) p2;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array count.");

            if (*lc == *rc) {

                compare_array(p0, p1, p3, p5, p6, p4);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array count. The left array count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array count. The right array count is null.");
    }
}

/* COUNT_ARRAY_COMPARATOR_SOURCE */
#endif