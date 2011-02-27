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
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/modifier/appender.c"
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

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *l) {

                break;
            }

            // Encode character tabulation character.
//??            encode_character_vector(p0, p1, p2, (void*) CHARACTER_TABULATION_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            // Encode space character.
            append(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode space character.
            append(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode space character.
            append(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode space character.
            append(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

            // Increment loop count.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode html indentation. The indentation level is null.");
    }
}

/* INDENTATION_HTML_ENCODER_SOURCE */
#endif
