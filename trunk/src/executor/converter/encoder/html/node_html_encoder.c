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

#ifndef NODE_HTML_ENCODER_SOURCE
#define NODE_HTML_ENCODER_SOURCE

#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/channel/cybol_channel.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/converter/encoder/html/begin_tag_html_encoder.c"
#include "../../../../executor/converter/encoder/html/end_tag_html_encoder.c"
#include "../../../../executor/converter/encoder/html/structured_tag_content_html_encoder.c"
#include "../../../../executor/converter/encoder/html/tag_content_html_encoder.c"
#include "../../../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Encodes an html node.
 *
 * @param p0 the destination html data (Hand over as reference!)
 * @param p1 the destination html data count
 * @param p2 the destination html data size
 * @param p3 the source part abstraction
 * @param p4 the source part abstraction count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part details
 * @param p8 the source part details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the indentation level (only for beautifying the resulting html code)
 */
void encode_html_node(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    if (p11 != *NULL_POINTER_MEMORY_MODEL) {

        int* l = (int*) p11;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode html node.");

        // The source part tag name, abstraction, model, details.
        void** tn = NULL_POINTER_MEMORY_MODEL;
        void** tnc = NULL_POINTER_MEMORY_MODEL;
        void** tns = NULL_POINTER_MEMORY_MODEL;
        void** ta = NULL_POINTER_MEMORY_MODEL;
        void** tac = NULL_POINTER_MEMORY_MODEL;
        void** tas = NULL_POINTER_MEMORY_MODEL;
        void** tm = NULL_POINTER_MEMORY_MODEL;
        void** tmc = NULL_POINTER_MEMORY_MODEL;
        void** tms = NULL_POINTER_MEMORY_MODEL;
        void** td = NULL_POINTER_MEMORY_MODEL;
        void** tdc = NULL_POINTER_MEMORY_MODEL;
        void** tds = NULL_POINTER_MEMORY_MODEL;

        // Get source part tag from details.
        get_universal_compound_element_by_name(
            (void*) &tn, (void*) &tnc, (void*) &tns,
            (void*) &ta, (void*) &tac, (void*) &tas,
            (void*) &tm, (void*) &tmc, (void*) &tms,
            (void*) &td, (void*) &tdc, (void*) &tds,
            p7, p8,
            (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT,
            p9, p10);

        encode_html_begin_tag(p0, p1, p2, *tm, *tmc, p7, p8, p9, p10, p11);

        // The new indentation level, which is the old incremented by one.
        int nl = *l + *NUMBER_1_INTEGER_MEMORY_MODEL;

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_equal_wide_character((void*) &r, p3, p4, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_html_structured_tag_content(p0, p1, p2, p5, p6, p9, p10, (void*) &nl);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array_equal_wide_character((void*) &r, p3, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                encode_html_tag_content(p0, p1, p2, p5, p6, (void*) &nl);
            }
        }

        encode_html_end_tag(p0, p1, p2, *tm, *tmc, p11);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode html node. The indentation level is null.");
    }
}

/* NODE_HTML_ENCODER_SOURCE */
#endif
