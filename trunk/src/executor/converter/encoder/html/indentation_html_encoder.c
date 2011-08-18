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
 * @version $RCSfile: html_converter.c,v $ $Revision: 1.25 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INDENTATION_HTML_ENCODER_SOURCE
#define INDENTATION_HTML_ENCODER_SOURCE

#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the html indentation.
 *
 * @param p0 the destination html data (Hand over as reference!)
 * @param p1 the destination html data count
 * @param p2 the destination html data size
 * @param p3 the indentation level (only for beautifying the resulting html code)
 */
void encode_html_indentation(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* l = (int*) p3;

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (j >= *l) {

                break;
            }

            // Encode character tabulation character.
//??            encode_character_vector(p0, p1, p2, (void*) CHARACTER_TABULATION_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            // Encode space character.
            overwrite_array(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            // Encode space character.
            overwrite_array(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            // Encode space character.
            overwrite_array(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            // Encode space character.
            overwrite_array(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

            // Increment loop count.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode html indentation. The indentation level is null.");
    }
}

/* INDENTATION_HTML_ENCODER_SOURCE */
#endif
