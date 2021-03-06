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
 * @version $RCSfile: numeric_character_reference_converter.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NUMERIC_CHARACTER_REFERENCE_ENCODER_SOURCE
#define NUMERIC_CHARACTER_REFERENCE_ENCODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/character/character_constants.c"
#include "../../../constant/character/numeric_character_reference_constants.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Encodes a character into a numeric character reference (html escape code).
 *
 * @param p0 the destination numeric character reference (html escape code) (Hand over as reference!)
 * @param p1 the destination numeric character reference (html escape code) count
 * @param p2 the destination numeric character reference (html escape code) size
 * @param p3 the source character
 * @param p4 the source character count
 */
void encode_numeric_character_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER_MEMORY_MODEL;
                int tc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int ts = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_all_array((void*) &r, p3, p4, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }
*/

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Add temporary value to destination.
                    overwrite_array(p0, (void*) t, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) &tc, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode numeric character reference. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode numeric character reference. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode numeric character reference. The destination size is null.");
    }
}

/* NUMERIC_CHARACTER_REFERENCE_ENCODER_SOURCE */
#endif
