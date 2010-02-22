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
 * @version $RCSfile: boolean_converter.c,v $ $Revision: 1.24 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_ENCODER_SOURCE
#define BOOLEAN_ENCODER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/cybol/boolean_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/primitive_memory_name.c"
#include "../../logger/logger.c"
#include "../../executor/memoriser/allocator.c"
#include "../../executor/comparator/array_equality_comparator.c"

/**
 * Encodes the boolean model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_boolean(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* s = (int*) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ds = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* dc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        void** d = (void**) p0;

                        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode boolean.");

                        if (*sc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            if (*s == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                // Set destination character vector.
                                *ds = *dc + *TRUE_BOOLEAN_CYBOL_MODEL_COUNT;

                                // Reallocate destination character vector.
                                reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                                // Set source into destination character vector.
                                set_array_elements(*d, p1, TRUE_BOOLEAN_CYBOL_MODEL, TRUE_BOOLEAN_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                                // Increment destination count.
                                *dc = *dc + *TRUE_BOOLEAN_CYBOL_MODEL_COUNT;

                            } else {

                                // Set destination character vector.
                                *ds = *dc + *FALSE_BOOLEAN_CYBOL_MODEL_COUNT;

                                // Reallocate destination character vector.
                                reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                                // Set source into destination character vector.
                                set_array_elements(*d, p1, FALSE_BOOLEAN_CYBOL_MODEL, FALSE_BOOLEAN_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                                // Increment destination count.
                                *dc = *dc + *FALSE_BOOLEAN_CYBOL_MODEL_COUNT;
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode boolean. The source count is zero.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode boolean. The destination is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode boolean. The destination count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode boolean. The destination size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode boolean. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode boolean. The source count is null.");
    }
}

/* BOOLEAN_ENCODER_SOURCE */
#endif
