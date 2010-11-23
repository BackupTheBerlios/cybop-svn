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
 * @version $RCSfile: request_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REQUEST_HEADER_HTTP_NAME_SOURCE
#define REQUEST_HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

//
// The following constants are taken from the HTTP 1.1 RFC 2616 specification:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14
// They are sorted alphabetically here.
//

/** The Accept request header http name. */
static wchar_t ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'c', L'c', L'e', L'p', L't'};
static wchar_t* ACCEPT_REQUEST_HEADER_HTTP_NAME = ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The Accept-Charset request header http name. */
static wchar_t ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'c', L'c', L'e', L'p', L't', L'-', L'C', L'h', L'a', L'r', L's', L'e', L't'};
static wchar_t* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME = ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The Accept-Encoding request header http name. */
static wchar_t ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'c', L'c', L'e', L'p', L't', L'-', L'E', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME = ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The Accept-Language request header http name. */
static wchar_t ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'c', L'c', L'e', L'p', L't', L'-', L'L', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME = ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The Authorization request header http name. */
static wchar_t AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'a', L't', L'i', L'o', L'n'};
static wchar_t* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The Expect request header http name. */
static wchar_t EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'E', L'x', L'p', L'e', L'c', L't'};
static wchar_t* EXPECT_REQUEST_HEADER_HTTP_NAME = EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The From request header http name. */
static wchar_t FROM_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'F', L'r', L'o', L'm'};
static wchar_t* FROM_REQUEST_HEADER_HTTP_NAME = FROM_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* FROM_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The Host request header http name. */
static wchar_t HOST_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'H', L'o', L's', L't'};
static wchar_t* HOST_REQUEST_HEADER_HTTP_NAME = HOST_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* HOST_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Match request header http name. */
static wchar_t IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'I', L'f', L'-', L'M', L'a', L't', L'c', L'h'};
static wchar_t* IF_MATCH_REQUEST_HEADER_HTTP_NAME = IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Modified-Since request header http name. */
static wchar_t IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'I', L'f', L'-', L'M', L'o', L'd', L'i', L'f', L'i', L'e', L'd', L'-', L'S', L'i', L'n', L'c', L'e'};
static wchar_t* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-None-Match request header http name. */
static wchar_t IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'I', L'f', L'-', L'N', L'o', L'n', L'e', L'-', L'M', L'a', L't', L'c', L'h'};
static wchar_t* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME = IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Range request header http name. */
static wchar_t IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'I', L'f', L'-', L'R', L'a', L'n', L'g', L'e'};
static wchar_t* IF_RANGE_REQUEST_HEADER_HTTP_NAME = IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Unmodified-since request header http name. */
static wchar_t IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'I', L'f', L'-', L'U', L'n', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd', L'-', L'S', L'i', L'n', L'c', L'e'};
static wchar_t* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The Max-Forwards request header http name. */
static wchar_t MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'M', L'a', L'x', L'-', L'F', L'o', L'r', L'w', L'a', L'r', L'd', L's'};
static wchar_t* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME = MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The Proxy-Authorization request header http name. */
static wchar_t PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'P', L'r', L'o', L'x', L'y', L'-', L'A', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'a', L't', L'i', L'o', L'n'};
static wchar_t* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The Range request header http name. */
static wchar_t RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'R', L'a', L'n', L'g', L'e'};
static wchar_t* RANGE_REQUEST_HEADER_HTTP_NAME = RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The Referer request header http name. */
static wchar_t REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'R', L'e', L'f', L'e', L'r', L'e', L'r'};
static wchar_t* REFERER_REQUEST_HEADER_HTTP_NAME = REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* REFERER_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The TE request header http name. */
static wchar_t TE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'T', L'E'};
static wchar_t* TE_REQUEST_HEADER_HTTP_NAME = TE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* TE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The User-Agent request header http name. */
static wchar_t USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'U', L's', L'e', L'r', L'-', L'A', L'g', L'e', L'n', L't'};
static wchar_t* USER_AGENT_REQUEST_HEADER_HTTP_NAME = USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The Vary request header http name. */
static wchar_t VARY_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'V', L'a', L'r', L'y'};
static wchar_t* VARY_REQUEST_HEADER_HTTP_NAME = VARY_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* VARY_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* REQUEST_HEADER_HTTP_NAME_SOURCE */
#endif
