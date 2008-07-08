/*
 * $RCSfile: http_response_converter.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.9 $ $Date: 2008-07-08 07:11:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_RESPONSE_CONVERTER_SOURCE
#define HTTP_RESPONSE_CONVERTER_SOURCE

#include "../../globals/constants/character/set/character_set_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/http/http_header_constants.c"
#include "../../globals/constants/http/http_header_variable_constants.c"
#include "../../globals/constants/http/http_protocol_version_constants.c"
#include "../../globals/constants/http/http_separator_constants.c"
#include "../../globals/constants/http/http_status_code_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/mime_type/text_mime_type_constants.c"
#include "../../globals/logger/logger.c"

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
 * Decodes an http response into a compound.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source http response
 * @param p7 the source http response count
 */
void decode_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode http response.");
}

/**
 * Encodes an http response status line.
 *
 * @param p0 the destination http response (Hand over as reference!)
 * @param p1 the destination http response count
 * @param p2 the destination http response size
 * @param p3 the source details (always of abstraction "compound")
 * @param p4 the source details count
 */
void encode_http_response_status_line(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode http response status line.");

    // Encode http protocol version.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_1_1_PROTOCOL_VERSION, (void*) HTTP_1_1_PROTOCOL_VERSION_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http protocol version separator.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_PROTOCOL_VERSION_SEPARATOR, (void*) HTTP_PROTOCOL_VERSION_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http status code.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_200_OK_STATUS_CODE, (void*) HTTP_200_OK_STATUS_CODE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
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
void encode_http_response_headers(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode http response headers.");

    // Encode content type http header.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CONTENT_TYPE_HTTP_HEADER, (void*) CONTENT_TYPE_HTTP_HEADER_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http header argument separator.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_HEADER_ARGUMENT_SEPARATOR, (void*) HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode content type as mime type.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTML_TEXT_MIME_TYPE, (void*) HTML_TEXT_MIME_TYPE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http header value separator.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_HEADER_VALUE_SEPARATOR, (void*) HTTP_HEADER_VALUE_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode charset http header variable.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CHARSET_HTTP_HEADER_VARIABLE, (void*) CHARSET_HTTP_HEADER_VARIABLE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http header value assignment separator.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_HEADER_VALUE_ASSIGNMENT_SEPARATOR, (void*) HTTP_HEADER_VALUE_ASSIGNMENT_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http charset value.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) ISO_8859_1_CHARACTER_SET, (void*) ISO_8859_1_CHARACTER_SET_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http header separator.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_HEADER_SEPARATOR, (void*) HTTP_HEADER_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode content length http header.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CONTENT_LENGTH_HTTP_HEADER, (void*) CONTENT_LENGTH_HTTP_HEADER_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode http header argument separator.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_HEADER_ARGUMENT_SEPARATOR, (void*) HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Encode content length as http body's length.
    // CAUTION! The source is an integer value!
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        p5, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
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
void encode_http_response_body(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode http response body.");

    // Encode http body which was already encoded from a cyboi model into a
    // character byte stream and handed over as such.
    encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        p3, p4, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
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
void encode_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode http response.");

                // The temporary body.
                void* b = *NULL_POINTER;
                int bc = *NUMBER_0_INTEGER;
                int bs = bc;

                // Allocate temporary body.
                allocate_array((void*) &b, (void*) &bs, (void*) WIDE_CHARACTER_ARRAY);

                // Encode body containing optional user data (such as an encoded/serialised xhtml page).
                //
                // CAUTION! This has to be done at FIRST, because the body size
                // is to be written into the headers below!
                encode_http_response_body((void*) &b, (void*) &bc, (void*) &bs, p3, p4);
                // Encode status line containing protocol version and status code.
                encode_http_response_status_line(p0, p1, p2, p5, p6);
                // Encode http response line separator.
                encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
                    (void*) HTTP_RESPONSE_LINE_SEPARATOR, (void*) HTTP_RESPONSE_LINE_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
                    *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
                // Encode headers containing meta data, of which some have the form of variables.
                //
                // CAUTION! The body count is handed over as additional parameter.
                encode_http_response_headers(p0, p1, p2, p5, p6, (void*) &bc);
                // Encode http headers separator.
                encode(p0, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
                    (void*) HTTP_HEADERS_SEPARATOR, (void*) HTTP_HEADERS_SEPARATOR_COUNT, *NULL_POINTER, *NULL_POINTER,
                    *NULL_POINTER, *NULL_POINTER, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

                if ((*dc + bc) > *ds) {

                    // Increase destination http response size by the body count.
                    *ds = *dc + bc;

                    // Reallocate destination http response using the new size.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
                }

                // Copy temporary body to the end of the actual destination http response.
                set_array_elements(*d, p1, b, (void*) &bc, (void*) WIDE_CHARACTER_ARRAY);

                // Increase destination http response count by the body count.
                *dc = *dc + bc;

                // Deallocate temporary body.
                deallocate_array((void*) &b, (void*) &bs, (void*) WIDE_CHARACTER_ARRAY);

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode http response. The destination http response is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode http response. The destination http response count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode http response. The destination http response size is null.");
    }
}

/* HTTP_RESPONSE_CONVERTER_SOURCE */
#endif
