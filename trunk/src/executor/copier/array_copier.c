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

#ifndef ARRAY_COPIER_SOURCE
#define ARRAY_COPIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/copier/offset_adder.c"
#include "../../executor/copier/value_copier.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../executor/modifier/assigner.c"
#include "../../logger/logger.c"

/**
 * Copies count source array elements into the destination array
 * at position index.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the operand abstraction
 * @param p3 the count
 */
void copy_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy array elements.");

                // The loop variable.
                int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (j >= *c) {

                        break;
                    }

                    copy_value_offset(p0, p1, p2, (void*) &j, (void*) &j);

                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy array elements. The destination array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy array elements. The source array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy array elements. The count is null.");
    }
}

/**
 * Copies source array into destination array starting from the given offset.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void copy_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy array.");

    // The destination array, source array.
    // CAUTION! They HAVE TO BE initialised with p0 and p1,
    // since an offset is added below.
    void* d = p0;
    void* s = p1;

    // Add offset.
    add_offset((void*) &d, p2, p4);
    add_offset((void*) &s, p2, p5);

    copy_array_elements(d, s, p2, p3);
}

/* ARRAY_COPIER_SOURCE */
#endif
