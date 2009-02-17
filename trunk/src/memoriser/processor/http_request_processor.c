/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.2 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_PROCESSOR_SOURCE
#define HTTP_REQUEST_PROCESSOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/selector/http_request_selector.c"

//
// Taken from:
// https://bugzilla.mozilla.org/show_bug.cgi?id=18643
//
// We cannot add a charset parameter to the Content-Type header for HTTP GET,
// because there is no Content-Type header in the case of GET (since there is no
// body following the headers). A *lot* of forms use GET.
//
// Since the charset of GET requests is always straight 7bit ASCII encoding
// standard ISO-Latin-1 text, I would have thought that that was pretty irrelevant.
//
// According to RFC1630:
// #     Where the local naming scheme uses ASCII characters which are not
// #     allowed in the URI, these may be represented in the URL by a
// #     percent sign "%" immediately followed by two hexadecimal digits
// #     (0-9, A-F) giving the ISO Latin 1 code for that character.
//                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Does this not mean that URIs can only contain a single character encoding?
//
// Similarly in HTML4, section 17.13.1:
// #   Note. The "get" method restricts form data set values to ASCII
// #   characters. Only the "post" method (with
// #   enctype="multipart/form-data") is specified to cover the entire
// #   [ISO10646] character set.
//
// RFC1630 does attempt to restrict URIs to iso-8859-1, but it is a well
// known fact that HTML forms have been violating that rule for years. Similar
// comment for HTML4's 17.13.1.
//

void process_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4) {

    select_http_request_method(p0, p1, p2);
}

void process_http_request_uri(void* p0, void* p1, void* p2) {

    select_http_request_uri(p0, p1, p2);
}

void process_http_request_protocol(void* p0, void* p1, void* p2) {

    select_http_request_protocol(p0, p1, p2);
}

void process_http_request_header_argument(void* p0, void* p1, void* p2) {

    select_http_request_header_argument(p0, p1, p2);
}

void process_http_request_header_value(void* p0, void* p1, void* p2) {

    select_http_request_header_value(p0, p1, p2);
}

void process_http_request_body(void* p0, void* p1, void* p2) {

    select_http_request_body(p0, p1, p2);
}

/* HTTP_REQUEST_PROCESSOR_SOURCE */
#endif
