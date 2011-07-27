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

#ifndef HEADER_ENTRY_HTTP_RESPONSE_SELECTOR_SOURCE
#define HEADER_ENTRY_HTTP_RESPONSE_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/model/uri/scheme_uri_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/converter/decoder/uri/http_uri_decoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Converts the given wide characters to characters and
 * appends them to the destination.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void select_http_response_header_entry_overwrite_array(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The character array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;

    // Allocate character array.
    allocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Encode wide character array into multibyte character array.
    encode_utf_8_unicode_character_vector((void*) &a, ac, as, p3, p4);

    overwrite_array(p0, a, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, ac, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

    // Deallocate character array.
    deallocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

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
 * @param p11 the source message model count
 */
void select_http_response_header_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http response header entry.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // The entity headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Nothing is to be done here.
            // The content length is ALWAYS added.
            // See function "encode_http_response_header"!
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    //
    // The request headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) FROM_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) FROM_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) HOST_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HOST_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) RANGE_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) REFERER_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) REFERER_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) TE_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) TE_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) VARY_REQUEST_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) VARY_REQUEST_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    //
    // The response headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) AGE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) AGE_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    //
    // The general headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) DATE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) DATE_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) VIA_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) VIA_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            overwrite_array(p0, (void*) WARNING_GENERAL_HEADER_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WARNING_GENERAL_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
            select_http_response_header_entry_overwrite_array(p0, p1, p2, p7, p8);
            overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }
}

/* HEADER_ENTRY_HTTP_RESPONSE_SELECTOR_SOURCE */
#endif
