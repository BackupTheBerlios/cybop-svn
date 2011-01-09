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
 * @version $RCSfile: http_request_compound_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_RESPONSE_HEADER_ENTRY_SELECTOR_SOURCE
#define HTTP_RESPONSE_HEADER_ENTRY_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/model/uri/scheme_uri_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/converter/decoder/uri/http_uri_decoder.c"
#include "../../../../logger/logger.c"

/**
 * Selects http response header entry.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 */
void select_http_response_header_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http response header entry.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p3, p4, (void*) CYBOI_SET_COOKIE_HEADER_HTTP_NAME, (void*) CYBOI_SET_COOKIE_HEADER_HTTP_NAME_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO: encode to UTF-8 yet BEFORE adding below!

            // CAUTION! Use standard http constants here (mostly starting with capital first letter).
            append_array_elements(p0, p1, p2, (void*) SET_COOKIE_HEADER_HTTP_NAME, (void*) SET_COOKIE_HEADER_HTTP_NAME_COUNT, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            append_array_elements(p0, p1, p2, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            append_array_elements(p0, p1, p2, p7, p8, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            append_array_elements(p0, p1, p2, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not select http response header entry. The header entry is unknown.");
    }
}

/* HTTP_RESPONSE_HEADER_ENTRY_SELECTOR_SOURCE */
#endif
