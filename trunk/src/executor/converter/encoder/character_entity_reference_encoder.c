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
 * @version $RCSfile: character_entity_reference_converter.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ENTITY_REFERENCE_ENCODER_SOURCE
#define CHARACTER_ENTITY_REFERENCE_ENCODER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/html_character_entity_constants.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/**
 * Encodes a character into a character entity reference (html escape reference).
 *
 * @param p0 the destination character entity reference (html escape reference)
 * @param p1 the destination character entity reference (html escape reference) count
 * @param p2 the destination character entity reference (html escape reference) size
 * @param p3 the source character
 * @param p4 the source character count
 */
/*??
void encode_character_entity_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                    compare_arrays(p3, p4, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }
*/

/*??
                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);
                    }

                    // Add temporary value to destination.
                    set_element(*d, p1, (void*) t, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode character entity reference. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode character entity reference. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode character entity reference. The destination size is null.");
    }
}
*/

/* CHARACTER_ENTITY_REFERENCE_ENCODER_SOURCE */
#endif
