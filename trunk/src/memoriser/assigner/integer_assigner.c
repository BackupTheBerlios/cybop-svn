/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: integer_assigner.c,v $ $Revision: 1.1 $ $Date: 2009-07-30 22:05:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_ASSIGNER_SOURCE
#define INTEGER_ASSIGNER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Sets the integer array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements
 * @param p3 the elements count
 */
/*
void set_integer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* i = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *sc) {

                            break;
                        }

                        //?? TEST START
                        assign(d, s, j, INTEGER);

// @param p0 the destination base db
// @param p1 the index i
// @param p1 the multiplicator j
void assign_integer(void* p0, void* p1, void* p2, void* p3) {

    // The destination base.
    void* db = (void*) (p0 + (*i * *INTEGER_PRIMITIVE_SIZE));
    // The offset.
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The source element.
    int* se = (int*) *NULL_POINTER_MEMORY_MODEL;
    // The destination element.
    int* de = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Determine offset.
    o = j * *INTEGER_PRIMITIVE_SIZE;

    // Determine source and destination element.
    se = (int*) (p2 + o);
    de = (int*) (db + o);

    // Set destination element.
    *de = *se;
}

void assign(void* p0, void* p1, void* p2, void* p3) {

    if (INTEGER) {

        assign_integer();

    } else ...
}
                        //?? TEST END

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}
*/

/* INTEGER_ASSIGNER_SOURCE */
#endif
