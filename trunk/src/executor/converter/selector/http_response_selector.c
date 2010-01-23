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
 * @version $RCSfile: http_response_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_RESPONSE_SELECTOR_SOURCE
#define HTTP_RESPONSE_SELECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/xml_cybol_name.c"
#include "../../constant/name/xml_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/detector.c"

//
// An http server response delivers message data in text format (like MIME 1.0),
// and consists of the following three parts:
// 1 status line containing protocol version and status code
// 2 headers containing meta data, of which some have the form of variables
// 3 body containing optional user data (such as an encoded/serialised xhtml page)
//
// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).
// The end of the headers is demarcated by an empty line (CRLF without any space).
//
// Header variables are NOT case-sensitive and have the following syntax:
// variable: statement[=value] [,statement2][=value2] [...]
//
// The following example shows the headers "Content-type", "Content-length" and "Set-cookie":
//
// Content-type: text/html
// Content-length: 114
// Set-cookie: usr=id541296, domain=bolege.de secure
//
// The following lines show an example http answer with protocol, headers and body,
// sent from a server back to the client:
//
// HTTP/1.0 200 OK
// Date: Fri, 13 Jan 2006 15:12:48 GMT
// Last-Modified: Tue, 10 Jan 2006 11:18:20 GMT
// Content-Language: de
// Content-Encoding: gzip
// Content-Type: text/html; charset=utf-8
//
// <xhtml xmlns="http://www.w3.org/1999/xhtml">
// <head>
//     <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
//     </meta>
//     <meta name="author" content="Generated by CYBOI">
// ...
//

/**
 * Encodes an http response status line.
 *
 * @param p0 the destination http response (Hand over as reference!)
 * @param p1 the destination http response count
 * @param p2 the destination http response size
 * @param p3 the source details (always of abstraction "compound")
 * @param p4 the source details count
 */
/*??
void encode_http_response_status_line(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode http response status line.");

    // Encode http protocol version.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL, (void*) NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http protocol version separator.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) PROTOCOL_VERSION_SEPARATOR_HTTP_NAME, (void*) PROTOCOL_VERSION_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http status code.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) OK_200_STATUS_CODE_HTTP_MODEL, (void*) OK_200_STATUS_CODE_HTTP_MODEL_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Encodes http response headers.
 *
 * @param p0 the destination http response (Hand over as reference!)
 * @param p1 the destination http response count
 * @param p2 the destination http response size
 * @param p3 the source details (always of abstraction "compound")
 * @param p4 the source details count
 * @param p5 the body count
 */
/*??
void encode_http_response_headers(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode http response headers.");

    // Encode content type http header.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) CONTENT_TYPE_HEADER_HTTP_NAME, (void*) CONTENT_TYPE_HEADER_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http header argument separator.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode content type as mime type.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) HTML_TEXT_MIME_ABSTRACTION, (void*) HTML_TEXT_MIME_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http header value separator.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) HEADER_VALUE_SEPARATOR_HTTP_NAME, (void*) HEADER_VALUE_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode charset http header variable.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) CHARSET_VARIABLE_HTTP_NAME, (void*) CHARSET_VARIABLE_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http header value assignment separator.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) HEADER_VALUE_ASSIGNMENT_SEPARATOR_HTTP_NAME, (void*) HEADER_VALUE_ASSIGNMENT_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http charset value.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) ISO_8859_1_CHARACTER_SET_MODEL, (void*) ISO_8859_1_CHARACTER_SET_MODEL_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http header separator.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode content length http header.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) CONTENT_LENGTH_HEADER_HTTP_NAME, (void*) CONTENT_LENGTH_HEADER_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode http header argument separator.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Encode content length as http body's length.
    // CAUTION! The source is an integer value!
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p5, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
}

/**
 * Encodes an http response body.
 *
 * @param p0 the destination http response (Hand over as reference!)
 * @param p1 the destination http response count
 * @param p2 the destination http response size
 * @param p3 the source model (of abstraction "character")
 * @param p4 the source model count
 */
/*??
void encode_http_response_body(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode http response body.");

    // Encode http body which was already encoded from a cyboi model into a
    // character byte stream and handed over as such.
    encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p3, p4, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Encodes a compound into an http response.
 *
 * @param p0 the destination http response (Hand over as reference!)
 * @param p1 the destination http response count
 * @param p2 the destination http response size
 * @param p3 the source model (of abstraction "character")
 * @param p4 the source model count
 * @param p5 the source details (always of abstraction "compound")
 * @param p6 the source details count
 */
/*??
void encode_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** d = (void**) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode http response.");

                // The temporary body.
                void* b = *NULL_POINTER_MEMORY_MODEL;
                int bc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int bs = bc;

                // Allocate temporary body.
                allocate_array((void*) &b, (void*) &bs, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Encode body containing optional user data (such as an encoded/serialised xhtml page).
                //
                // CAUTION! This has to be done at FIRST, because the body size
                // is to be written into the headers below!
                encode_http_response_body((void*) &b, (void*) &bc, (void*) &bs, p3, p4);
                // Encode status line containing protocol version and status code.
                encode_http_response_status_line(p0, p1, p2, p5, p6);
                // Encode http response line separator.
                encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    (void*) RESPONSE_LINE_SEPARATOR_HTTP_NAME, (void*) RESPONSE_LINE_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Encode headers containing meta data, of which some have the form of variables.
                //
                // CAUTION! The body count is handed over as additional parameter.
                encode_http_response_headers(p0, p1, p2, p5, p6, (void*) &bc);
                // Encode http headers separator.
                encode(p0, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    (void*) HEADERS_SEPARATOR_HTTP_NAME, (void*) HEADERS_SEPARATOR_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                if ((*dc + bc) > *ds) {

                    // Increase destination http response size by the body count.
                    *ds = *dc + bc;

                    // Reallocate destination http response using the new size.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                }

                // Copy temporary body to the end of the actual destination http response.
                set_array_elements(*d, p1, b, (void*) &bc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Increase destination http response count by the body count.
                *dc = *dc + bc;

                // Deallocate temporary body.
                deallocate_array((void*) &b, (void*) &bs, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode http response. The destination http response is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode http response. The destination http response count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode http response. The destination http response size is null.");
    }
}

/* HTTP_RESPONSE_SELECTOR_SOURCE */
#endif
