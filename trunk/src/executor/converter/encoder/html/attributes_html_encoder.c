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

#ifndef ATTRIBUTES_HTML_ENCODER_SOURCE
#define ATTRIBUTES_HTML_ENCODER_SOURCE

#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../../../executor/modifier/appender.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the html attribute.
 *
 * @param p0 the destination html data (Hand over as reference!)
 * @param p1 the destination html data count
 * @param p2 the destination html data size
 * @param p3 the source details
 * @param p4 the source details count
 * @param p5 the source details part index
 */
void encode_html_attribute(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode html attribute.");

    // The source part details name, abstraction, model, details.
    void** n = NULL_POINTER_MEMORY_MODEL;
    void** nc = NULL_POINTER_MEMORY_MODEL;
    void** ns = NULL_POINTER_MEMORY_MODEL;
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;

    // Get details part at index.
    get_compound_element_by_index(p3, p4, p5,
        (void*) &n, (void*) &nc, (void*) &ns,
        (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms,
        (void*) &d, (void*) &dc, (void*) &ds);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_array_equal_wide_character((void*) &r, *n, *nc, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT);

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Only add attribute, if the details part name is NOT "tag"!

        // Encode space character.
        append(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        // Encode attribute name.
        append(p0, p1, p2, *n, *nc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        // Encode equals sign character.
        append(p0, p1, p2, (void*) EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        // Encode quotation mark character.
        append(p0, p1, p2, (void*) QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        // Encode space character.
        append(p0, p1, p2, *m, *mc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
        // Encode quotation mark character.
        append(p0, p1, p2, (void*) QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    }
}

/**
 * Encodes the html attributes.
 *
 * @param p0 the destination html data (Hand over as reference!)
 * @param p1 the destination html data count
 * @param p2 the destination html data size
 * @param p3 the source details
 * @param p4 the source details count
 */
void encode_html_attributes(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode html attributes.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Iterate through details parts.
        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            encode_html_attribute(p0, p1, p2, p3, p4, (void*) &j);

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode html attributes. The source details count is null.");
    }
}

/* ATTRIBUTES_HTML_ENCODER_SOURCE */
#endif
