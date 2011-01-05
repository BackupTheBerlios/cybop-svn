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

#ifndef STRUCTURED_TAG_CONTENT_HTML_ENCODER_SOURCE
#define STRUCTURED_TAG_CONTENT_HTML_ENCODER_SOURCE

#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void encode_html_node(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Encodes an html structured tag content.
 *
 * @param p0 the destination html data (Hand over as reference!)
 * @param p1 the destination html data count
 * @param p2 the destination html data size
 * @param p3 the source part model
 * @param p4 the source part model count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 * @param p7 the indentation level (only for beautifying the resulting html code)
 */
void encode_html_structured_tag_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode html structured tag content.");

        // The source part name, abstraction, model, details.
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

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Iterate through compound parts.
        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            // Get part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &n, (void*) &nc, (void*) &ns,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            // Recursively call this operation for the part model.
            encode_html_node(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p5, p6, p7);

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode html structured tag content. The source count is null.");
    }
}

/* STRUCTURED_TAG_CONTENT_HTML_ENCODER_SOURCE */
#endif
