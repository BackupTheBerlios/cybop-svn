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

#ifndef HTML_ENCODER_SOURCE
#define HTML_ENCODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../executor/accessor/appender/array_appender.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/encoder/html/node_html_encoder.c"
#include "../../../logger/logger.c"

/**
 * Encodes a compound model into html format.
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
 */
void encode_html(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode html.");

    // The tree level.
    int l = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
    fwprintf(stdout, L"TEST html 0 a: %ls\n", (wchar_t*) p3);
    fwprintf(stdout, L"TEST html 0 ac: %i\n", *((int*) p4));
    fwprintf(stdout, L"TEST html 0 m: %ls\n", (wchar_t*) p5);
    fwprintf(stdout, L"TEST html 0 mc: %i\n", *((int*) p6));
    fwprintf(stdout, L"TEST html 0 d: %ls\n", (wchar_t*) p7);
    fwprintf(stdout, L"TEST html 0 dc: %i\n", *((int*) p8));
*/

    // Encode html root node.
    encode_html_node(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, (void*) &l);
}

/* HTML_ENCODER_SOURCE */
#endif
