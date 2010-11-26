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

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/http/separator_http_name.c"
#include "../../../executor/converter/detector.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

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

/* HTTP_REQUEST_SELECTOR_SOURCE */
#endif
