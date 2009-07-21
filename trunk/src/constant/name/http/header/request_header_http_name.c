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

/** The accept request header http name. */
static wchar_t ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't'};
static wchar_t* ACCEPT_REQUEST_HEADER_HTTP_NAME = ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The accept-charset request header http name. */
static wchar_t ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'c', L'h', L'a', L'r', L's', L'e', L't'};
static wchar_t* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME = ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The accept-encoding request header http name. */
static wchar_t ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME = ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The accept-language request header http name. */
static wchar_t ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME = ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The authorization request header http name. */
static wchar_t AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'a', L't', L'i', L'o', L'n'};
static wchar_t* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The expect request header http name. */
static wchar_t EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'e', L'x', L'p', L'e', L'c', L't'};
static wchar_t* EXPECT_REQUEST_HEADER_HTTP_NAME = EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The from request header http name. */
static wchar_t FROM_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'f', L'r', L'o', L'm'};
static wchar_t* FROM_REQUEST_HEADER_HTTP_NAME = FROM_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* FROM_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The host request header http name. */
static wchar_t HOST_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'h', L'o', L's', L't'};
static wchar_t* HOST_REQUEST_HEADER_HTTP_NAME = HOST_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* HOST_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The if-match request header http name. */
static wchar_t IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'm', L'a', L't', L'c', L'h'};
static wchar_t* IF_MATCH_REQUEST_HEADER_HTTP_NAME = IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The if-modified-since request header http name. */
static wchar_t IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd', L'-', L's', L'i', L'n', L'c', L'e'};
static wchar_t* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The if-none-match request header http name. */
static wchar_t IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'n', L'o', L'n', L'e', L'-', L'm', L'a', L't', L'c', L'h'};
static wchar_t* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME = IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The if-range request header http name. */
static wchar_t IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'r', L'a', L'n', L'g', L'e'};
static wchar_t* IF_RANGE_REQUEST_HEADER_HTTP_NAME = IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The if-unmodified-since request header http name. */
static wchar_t IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'u', L'n', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd', L'-', L's', L'i', L'n', L'c', L'e'};
static wchar_t* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The max-forwards request header http name. */
static wchar_t MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'm', L'a', L'x', L'-', L'f', L'o', L'r', L'w', L'a', L'r', L'd', L's'};
static wchar_t* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME = MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The proxy-authorization request header http name. */
static wchar_t PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'p', L'r', L'o', L'x', L'y', L'-', L'a', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'a', L't', L'i', L'o', L'n'};
static wchar_t* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The range request header http name. */
static wchar_t RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'r', L'a', L'n', L'g', L'e'};
static wchar_t* RANGE_REQUEST_HEADER_HTTP_NAME = RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The referer request header http name. */
static wchar_t REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'e', L'r'};
static wchar_t* REFERER_REQUEST_HEADER_HTTP_NAME = REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* REFERER_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The te request header http name. */
static wchar_t TE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L't', L'e'};
static wchar_t* TE_REQUEST_HEADER_HTTP_NAME = TE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* TE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The user-agent request header http name. */
static wchar_t USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'u', L's', L'e', L'r', L'-', L'a', L'g', L'e', L'n', L't'};
static wchar_t* USER_AGENT_REQUEST_HEADER_HTTP_NAME = USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The vary request header http name. */
static wchar_t VARY_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'v', L'a', L'r', L'y'};
static wchar_t* VARY_REQUEST_HEADER_HTTP_NAME = VARY_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* VARY_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* REQUEST_HEADER_HTTP_NAME_SOURCE */
#endif
