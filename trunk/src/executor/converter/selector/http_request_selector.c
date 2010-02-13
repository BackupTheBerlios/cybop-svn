/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef HTTP_REQUEST_SELECTOR_SOURCE
#define HTTP_REQUEST_SELECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/http/header/entity_header_http_name.c"
#include "../../constant/name/http/header/general_header_http_name.c"
#include "../../constant/name/http/header/request_header_http_name.c"
#include "../../constant/name/http/header/response_header_http_name.c"
#include "../../constant/name/http/separator_http_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/detector.c"

//
// An http server request delivers message data in text format (like MIME 1.0),
// and consists of the following three parts:
// 1 request line containing request method, file path and protocol version
// 2 headers containing meta data, of which some have the form of variables
// 3 body containing optional user data (such as an encoded/serialised xhtml page)
//
// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).
// The end of the headers is demarcated by an empty line (CRLF without any space).
//
// HTTP request and response messages use a generic message format for transferring
// entities (the payload of the message). Both types of message consist of a:
// - start-line
// - zero or more header fields (also known as "headers")
// - an empty line (i.e., a line with nothing preceding the CRLF)
//   indicating the end of the header fields
// - possibly a message-body
//
// Example with GET method 1:
//
// GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
// host: de.wikipedia.org
//
// The value pairs (parameters) of the example are:
//
// -------------------------------------
// Argument         Value
// -------------------------------------
// search           Katzen
// go               Artikel
// -------------------------------------
//
// Example with GET method 2:
//
// GET /residenz/test.html HTTP/1.1
// user-agent: Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Debian)
// accept: text/html, image/jpeg, image/png, text/*, image/*,// /*
// accept-encoding: x-gzip, x-deflate, gzip, deflate
// accept-charset: utf-8, utf-8;q=0.5, *;q=0.5
// accept-language: en, de, pl
// host: 127.0.0.1:1971
// connection: Keep-Alive
//
// Example with POST method:
//
// POST /wiki/Spezial:Search HTTP/1.1
// host: de.wikipedia.org
// content-type: application/x-www-form-urlencoded
// content-length: 24
//
// search=Katzen&go=Artikel
//

//
// Forward declarations.
//

void process_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void process_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void process_http_request_protocol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void process_http_request_header_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void process_http_request_header_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void process_http_request_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void process_http_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Selects the http request method.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void select_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request method.");

        //
        // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
        // if a detection is to be taking place!
        // Many "detect" functions are called in a sequence, below.
        // If the result of one detection function was positive (r == 1),
        // then that function increments the current position and decrements the remaining count.
        // In this case, further detection functions following afterwards might detect
        // further characters and CHANGE the current position and remaining count, and so forth,
        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
        // Therefore, the checks for (r == 0) below avoid another detection,
        // if the result already has a value unequal zero.
        //
        // CAUTION! If a detection was successful, then the current position and remaining count
        // were already adapted within the corresponding "detect" function (as called below),
        // so that they now point to the first character following the detected character sequence.
        // Any "process" function called afterwards can rely on this and start processing right away.
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_uri(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request method. The break flag is null.");
    }
}

/**
 * Selects the http request uri.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void select_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request uri.");

        //
        // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
        // if a detection is to be taking place!
        // Many "detect" functions are called in a sequence, below.
        // If the result of one detection function was positive (r == 1),
        // then that function increments the current position and decrements the remaining count.
        // In this case, further detection functions following afterwards might detect
        // further characters and CHANGE the current position and remaining count, and so forth,
        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
        // Therefore, the checks for (r == 0) below avoid another detection,
        // if the result already has a value unequal zero.
        //
        // CAUTION! If a detection was successful, then the current position and remaining count
        // were already adapted within the corresponding "detect" function (as called below),
        // so that they now point to the first character following the detected character sequence.
        // Any "process" function called afterwards can rely on this and start processing right away.
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_protocol(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request uri. The break flag is null.");
    }
}

/**
 * Selects the http request protocol.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void select_http_request_protocol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request protocol.");

        //
        // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
        // Before the request response line final element http name (ending with "carriage return"
        // and "line feed") can be identified, the possibility of a body begin http name
        // (twice "carriage return" and "line feed") indicating the message body
        // has to be considered:
        // - twice "carriage return" and "line feed"
        // - "carriage return" and "line feed"
        //
        // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
        // if a detection is to be taking place!
        // Many "detect" functions are called in a sequence, below.
        // If the result of one detection function was positive (r == 1),
        // then that function increments the current position and decrements the remaining count.
        // In this case, further detection functions following afterwards might detect
        // further characters and CHANGE the current position and remaining count, and so forth,
        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
        // Therefore, the checks for (r == 0) below avoid another detection,
        // if the result already has a value unequal zero.
        //
        // CAUTION! If a detection was successful, then the current position and remaining count
        // were already adapted within the corresponding "detect" function (as called below),
        // so that they now point to the first character following the detected character sequence.
        // Any "process" function called afterwards can rely on this and start processing right away.
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) BODY_BEGIN_HTTP_NAME, (void*) BODY_BEGIN_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_body(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_header_argument(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request protocol. The break flag is null.");
    }
}

/**
 * Selects the http request header argument.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 * @param p9 the header argument
 * @param p10 the header argument count
 */
void select_http_request_header_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request header argument.");

        //
        // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
        // if a detection is to be taking place!
        // Many "detect" functions are called in a sequence, below.
        // If the result of one detection function was positive (r == 1),
        // then that function increments the current position and decrements the remaining count.
        // In this case, further detection functions following afterwards might detect
        // further characters and CHANGE the current position and remaining count, and so forth,
        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
        // Therefore, the checks for (r == 0) below avoid another detection,
        // if the result already has a value unequal zero.
        //
        // CAUTION! If a detection was successful, then the current position and remaining count
        // were already adapted within the corresponding "detect" function (as called below),
        // so that they now point to the first character following the detected character sequence.
        // Any "process" function called afterwards can rely on this and start processing right away.
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) HEADER_ARGUMENT_HTTP_NAME, (void*) HEADER_ARGUMENT_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_header_value(p0, p1, p2, p3, p4, p5, p7, p8, p9, p10);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header argument. The break flag is null.");
    }
}

/**
 * Selects the http request header value.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void select_http_request_header_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request header value.");

        //
        // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
        // Before the header value http name or header http name (ending with "carriage return"
        // and "line feed") can be identified, the possibility of a body begin
        // (twice "carriage return" and "line feed") indicating the message body
        // has to be considered:
        // - twice "carriage return" and "line feed"
        // - "carriage return" and "line feed"
        //
        // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
        // if a detection is to be taking place!
        // Many "detect" functions are called in a sequence, below.
        // If the result of one detection function was positive (r == 1),
        // then that function increments the current position and decrements the remaining count.
        // In this case, further detection functions following afterwards might detect
        // further characters and CHANGE the current position and remaining count, and so forth,
        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
        // Therefore, the checks for (r == 0) below avoid another detection,
        // if the result already has a value unequal zero.
        //
        // CAUTION! If a detection was successful, then the current position and remaining count
        // were already adapted within the corresponding "detect" function (as called below),
        // so that they now point to the first character following the detected character sequence.
        // Any "process" function called afterwards can rely on this and start processing right away.
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) BODY_BEGIN_HTTP_NAME, (void*) BODY_BEGIN_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_body(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) HEADER_HTTP_NAME, (void*) HEADER_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_header_argument(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header value. The break flag is null.");
    }
}

/**
 * Selects the http request header.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the header argument
 * @param p4 the header argument count
 * @param p5 the header value
 * @param p6 the header value count
 */
void select_http_request_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request header.");

    // The decoded header argument wide character array.
    void* ha = *NULL_POINTER_MEMORY_MODEL;
    int hac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int has = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The decoded header value wide character array.
    void* hv = *NULL_POINTER_MEMORY_MODEL;
    int hvc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int hvs = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate decoded header argument wide character array.
    allocate((void*) &ha, (void*) &has, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
    // Allocate decoded header value wide character array.
    allocate((void*) &hv, (void*) &hvs, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    // Decode encoded character array into decoded header argument wide character array.
    decode_utf_8_unicode_character_vector((void*) &ha, (void*) &hac, (void*) &has, p3, p4);
    // Decode encoded character array into decoded header value wide character array.
    decode_utf_8_unicode_character_vector((void*) &hv, (void*) &hvc, (void*) &hvs, p5, p6);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // The entity headers.
    //

/*??
    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME, (void*) CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    //
    // The request headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) FROM_REQUEST_HEADER_HTTP_NAME, (void*) FROM_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) HOST_REQUEST_HEADER_HTTP_NAME, (void*) HOST_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) RANGE_REQUEST_HEADER_HTTP_NAME, (void*) RANGE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) REFERER_REQUEST_HEADER_HTTP_NAME, (void*) REFERER_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) TE_REQUEST_HEADER_HTTP_NAME, (void*) TE_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_TE_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) VARY_REQUEST_HEADER_HTTP_NAME, (void*) VARY_REQUEST_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME, (void*) CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    //
    // The response headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) AGE_RESPONSE_HEADER_HTTP_NAME, (void*) AGE_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME, (void*) CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    //
    // The general headers.
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) DATE_GENERAL_HEADER_HTTP_NAME, (void*) DATE_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_DATE_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) VIA_GENERAL_HEADER_HTTP_NAME, (void*) VIA_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_VIA_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(ha, (void*) &hac, (void*) WARNING_GENERAL_HEADER_HTTP_NAME, (void*) WARNING_GENERAL_HEADER_HTTP_NAME_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append_part(p0, p1, p2,
                (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME, (void*) CYBOI_WARNING_GENERAL_HEADER_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT,
                hv, (void*) &hvc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
        }
    }
*/

    // Deallocate decoded header argument wide character array.
    deallocate((void*) &ha, (void*) &has, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
    // Deallocate decoded header value wide character array.
    deallocate((void*) &hv, (void*) &hvs, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
}

/**
 * Selects the http request body.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void select_http_request_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request body.");

        //
        // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
        // if a detection is to be taking place!
        // Many "detect" functions are called in a sequence, below.
        // If the result of one detection function was positive (r == 1),
        // then that function increments the current position and decrements the remaining count.
        // In this case, further detection functions following afterwards might detect
        // further characters and CHANGE the current position and remaining count, and so forth,
        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
        // Therefore, the checks for (r == 0) below avoid another detection,
        // if the result already has a value unequal zero.
        //
        // CAUTION! If a detection was successful, then the current position and remaining count
        // were already adapted within the corresponding "detect" function (as called below),
        // so that they now point to the first character following the detected character sequence.
        // Any "process" function called afterwards can rely on this and start processing right away.
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) BODY_END_HTTP_NAME, (void*) BODY_END_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request body. The break flag is null.");
    }
}

/* HTTP_REQUEST_SELECTOR_SOURCE */
#endif
