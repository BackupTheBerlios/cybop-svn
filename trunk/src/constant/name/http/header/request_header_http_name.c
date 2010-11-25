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
static char ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'A', 'c', 'c', 'e', 'p', 't'};
static char* ACCEPT_REQUEST_HEADER_HTTP_NAME = ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The Accept-Charset request header http name. */
static char ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'A', 'c', 'c', 'e', 'p', 't', '-', 'C', 'h', 'a', 'r', 's', 'e', 't'};
static char* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME = ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The Accept-Encoding request header http name. */
static char ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'A', 'c', 'c', 'e', 'p', 't', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'};
static char* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME = ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The Accept-Language request header http name. */
static char ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'A', 'c', 'c', 'e', 'p', 't', '-', 'L', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static char* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME = ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The Authorization request header http name. */
static char AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'A', 'u', 't', 'h', 'o', 'r', 'i', 'z', 'a', 't', 'i', 'o', 'n'};
static char* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The Expect request header http name. */
static char EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'E', 'x', 'p', 'e', 'c', 't'};
static char* EXPECT_REQUEST_HEADER_HTTP_NAME = EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The From request header http name. */
static char FROM_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'F', 'r', 'o', 'm'};
static char* FROM_REQUEST_HEADER_HTTP_NAME = FROM_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* FROM_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The Host request header http name. */
static char HOST_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'H', 'o', 's', 't'};
static char* HOST_REQUEST_HEADER_HTTP_NAME = HOST_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* HOST_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Match request header http name. */
static char IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'I', 'f', '-', 'M', 'a', 't', 'c', 'h'};
static char* IF_MATCH_REQUEST_HEADER_HTTP_NAME = IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Modified-Since request header http name. */
static char IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'I', 'f', '-', 'M', 'o', 'd', 'i', 'f', 'i', 'e', 'd', '-', 'S', 'i', 'n', 'c', 'e'};
static char* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-None-Match request header http name. */
static char IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'I', 'f', '-', 'N', 'o', 'n', 'e', '-', 'M', 'a', 't', 'c', 'h'};
static char* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME = IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Range request header http name. */
static char IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'I', 'f', '-', 'R', 'a', 'n', 'g', 'e'};
static char* IF_RANGE_REQUEST_HEADER_HTTP_NAME = IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The If-Unmodified-since request header http name. */
static char IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'I', 'f', '-', 'U', 'n', 'm', 'o', 'd', 'i', 'f', 'i', 'e', 'd', '-', 'S', 'i', 'n', 'c', 'e'};
static char* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The Max-Forwards request header http name. */
static char MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'M', 'a', 'x', '-', 'F', 'o', 'r', 'w', 'a', 'r', 'd', 's'};
static char* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME = MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The Proxy-Authorization request header http name. */
static char PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'P', 'r', 'o', 'x', 'y', '-', 'A', 'u', 't', 'h', 'o', 'r', 'i', 'z', 'a', 't', 'i', 'o', 'n'};
static char* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The Range request header http name. */
static char RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'R', 'a', 'n', 'g', 'e'};
static char* RANGE_REQUEST_HEADER_HTTP_NAME = RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The Referer request header http name. */
static char REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'R', 'e', 'f', 'e', 'r', 'e', 'r'};
static char* REFERER_REQUEST_HEADER_HTTP_NAME = REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* REFERER_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The TE request header http name. */
static char TE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'T', 'E'};
static char* TE_REQUEST_HEADER_HTTP_NAME = TE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* TE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The User-Agent request header http name. */
static char USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'U', 's', 'e', 'r', '-', 'A', 'g', 'e', 'n', 't'};
static char* USER_AGENT_REQUEST_HEADER_HTTP_NAME = USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The Vary request header http name. */
static char VARY_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {'V', 'a', 'r', 'y'};
static char* VARY_REQUEST_HEADER_HTTP_NAME = VARY_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* VARY_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* REQUEST_HEADER_HTTP_NAME_SOURCE */
#endif
