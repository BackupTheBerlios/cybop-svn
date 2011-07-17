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
 * @version $RCSfile: http_request_selector.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HEADER_FIELD_HTTP_REQUEST_SELECTOR_SOURCE
#define HEADER_FIELD_HTTP_REQUEST_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/header/cyboi_entity_header_http_name.c"
#include "../../../../constant/name/http/header/cyboi_general_header_http_name.c"
#include "../../../../constant/name/http/header/cyboi_request_header_http_name.c"
#include "../../../../constant/name/http/header/cyboi_response_header_http_name.c"
#include "../../../../constant/name/http/header/entity_header_http_name.c"
#include "../../../../constant/name/http/header/general_header_http_name.c"
#include "../../../../constant/name/http/header/request_header_http_name.c"
#include "../../../../constant/name/http/header/response_header_http_name.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

//
// CAUTION! This comment is valid for all "select" functions below.
//
// The comparison result HAS TO BE ZERO (r == 0),
// if a detection is to be taking place!
//
// Many "detect" functions are called in a sequence, below.
// If the result of one detection function was positive (r == 1), then that
// function increments the current position and decrements the remaining count.
// In this case, further detection functions following afterwards might detect
// further characters and CHANGE the current position and remaining count,
// and so forth, which would have the effect of "JUMPING" over some characters
// and produce WRONG RESULTS!
//
// Therefore, the checks for (r == 0) below avoid another detection,
// if the result already has a value unequal zero.
//
// CAUTION! If a detection was successful, then the current position and remaining count
// were already adapted within the corresponding "detect" function (as called below),
// so that they now point to the first character following the detected character sequence.
// Any "decode" function called afterwards can rely on this and start processing right away.
//

/**
 * Converts the given characters to wide characters and
 * appends them to the destination.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 */
void select_http_request_header_field_append_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Decode encoded character array into serialised wide character array.
    decode_utf_8_unicode_character_vector((void*) &s, sc, ss, p7, p8);

    append_part(p0, p1, p2, p3, p4, p5, p6, s, sc, p9, p10);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Selects the http request header field.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the header argument
 * @param p4 the header argument count
 * @param p5 the header value
 * @param p6 the header value count
 */
void select_http_request_header_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request header field.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // The entity headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    //
    // The request headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) FROM_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) FROM_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) HOST_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) HOST_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) RANGE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) RANGE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) REFERER_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) REFERER_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) TE_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) TE_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) VARY_REQUEST_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) VARY_REQUEST_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    //
    // The response headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) AGE_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) AGE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    //
    // The general headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) DATE_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) DATE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) VIA_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) VIA_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p3, (void*) WARNING_GENERAL_HEADER_HTTP_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) WARNING_GENERAL_HEADER_HTTP_NAME_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            select_http_request_header_field_append_part(p0, p1, p2,
                (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }
}

/* HEADER_FIELD_HTTP_REQUEST_SELECTOR_SOURCE */
#endif
