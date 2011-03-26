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

#ifndef DOUBLE_EQUALITY_COMPARATOR_SOURCE
#define DOUBLE_EQUALITY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Compares two double values for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_equal_double(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        double* rv = (double*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            double* lv = (double*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare double values for equality.");

                if (*lv == *rv) {

                    *r = *NUMBER_1_INTEGER_MEMORY_MODEL;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare double values for equality. The result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare double values for equality. The left value is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare double values for equality. The right value is null.");
    }
}

/* DOUBLE_EQUALITY_COMPARATOR_SOURCE */
#endif
