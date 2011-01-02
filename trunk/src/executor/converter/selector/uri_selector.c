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

#ifndef URI_SELECTOR_SOURCE
#define URI_SELECTOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/uri/scheme_uri_model.c"
#include "../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../constant/name/xml_name.c"
#include "../../../executor/converter/decoder/uri/http_uri_decoder.c"
#include "../../../logger/logger.c"

/**
 * Selects uri.
 *
 * The request uri identifies the resource upon which to apply a request.
 * There are four options to specify a request uri:
 *
 * Request-URI = "*" | absoluteURI | abs_path | authority
 *
 * (1) No resource
 *
 * The asterisk "*" means that the request does not apply to a particular
 * resource, but to the server itself, and is only allowed when the method
 * used does not necessarily apply to a resource. Example:
 *
 * OPTIONS * HTTP/1.1
 *
 * (2) Absolute URI
 *
 * The absoluteURI form is REQUIRED when the request is being made to
 * a proxy. The proxy is requested to forward the request or service it
 * from a valid cache, and return the response. Note that the proxy MAY
 * forward the request on to another proxy or directly to the server
 * specified by the absoluteURI. Example:
 *
 * GET http://www.w3.org/pub/WWW/TheProject.html HTTP/1.1
 *
 * (3) Authority Form
 *
 * The authority form is only used by the CONNECT method. If a client
 * connects to a proxy using the CONNECT method, it has to specify
 * the hostname and, separated by a colon, the port number. Both of them
 * have to be specified. The host:port part is followed by a space and
 * a string specifying the HTTP version number. Example:
 *
 * CONNECT home.netscape.com:443 HTTP/1.0
 * User-agent: Mozilla/1.1N
 * Proxy-authorization: basic aGVsbG86d29ybGQ=
 *
 * (4) Absolute Path
 *
 * The most common form is that used to identify a resource on an
 * origin server or gateway. In this case, the absolute path of the
 * uri MUST be transmitted as the request uri, and the network location
 * of the uri (authority) MUST be transmitted in a Host header field.
 * For example, a client wishing to retrieve the resource above directly
 * from the origin server would create a TCP connection to port 80 of
 * the host "www.w3.org" and send the lines:
 *
 * GET /pub/WWW/TheProject.html HTTP/1.1
 * Host: www.w3.org
 *
 * followed by the remainder of the request.
 * Note that the absolute path cannot be empty; if none is present
 * in the original URI, it MUST be given as "/" (the server root).
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
void select_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select uri.");

        //
        // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) SCHEME_END_SEPARATOR_URI_NAME, (void*) SCHEME_END_SEPARATOR_URI_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select uri. The break flag is null.");
    }
}

/* URI_SELECTOR_SOURCE */
#endif
