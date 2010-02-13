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

#ifndef BOOLEAN_DECODER_SOURCE
#define BOOLEAN_DECODER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/cybol/boolean_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/primitive_memory_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Decodes the byte stream and creates a boolean model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_boolean(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int** d = (int**) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode boolean.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_array_elements(p3, (void*) TRUE_BOOLEAN_CYBOL_MODEL, (void*) TRUE_BOOLEAN_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set boolean value to "true", in other words the integer value to "one".
                        set_array_elements(*d, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);

                        // Increment destination count.
                        *dc = *dc + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_array_elements(p3, (void*) FALSE_BOOLEAN_CYBOL_MODEL, (void*) FALSE_BOOLEAN_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set boolean value to "false", in other words the integer value to "zero".
                        set_array_elements(*d, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) FALSE_BOOLEAN_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);

                        // Increment destination count.
                        *dc = *dc + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode boolean. The value cannot be interpreted.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode boolean. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode boolean. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode boolean. The source count is null.");
    }
}

/* BOOLEAN_DECODER_SOURCE */
#endif
