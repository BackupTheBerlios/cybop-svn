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
 * @version $RCSfile: request_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_REQUEST_HEADER_HTTP_NAME_SOURCE
#define CYBOI_REQUEST_HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

//
// The constants defined here are copies of the standard constants
// that may be found in files of this same directory.
//
// The difference is that these constants are of type "wchar_t"
// and are prefixed with "CYBOI_".
//
// This duplication of constants is necessary, because names or models
// of standard formats like HTTP or xDT are not always intuitive,
// so that CYBOI uses its own speaking names internally.
//
// Examples:
// - HTTP header names start with a capital letter, but CYBOI uses lower-case names only
// - xDT fields are represented by numbers, but CYBOI uses speaking names (text) only
//

/** The cyboi accept request header http name. */
static wchar_t CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't'};
static wchar_t* CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME = CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi accept-charset request header http name. */
static wchar_t CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'c', L'h', L'a', L'r', L's', L'e', L't'};
static wchar_t* CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME = CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi accept-encoding request header http name. */
static wchar_t CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME = CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi accept-language request header http name. */
static wchar_t CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME = CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi authorization request header http name. */
static wchar_t CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi expect request header http name. */
static wchar_t CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'e', L'x', L'p', L'e', L'c', L't'};
static wchar_t* CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME = CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi from request header http name. */
static wchar_t CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'f', L'r', L'o', L'm'};
static wchar_t* CYBOI_FROM_REQUEST_HEADER_HTTP_NAME = CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_FROM_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi host request header http name. */
static wchar_t CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'h', L'o', L's', L't'};
static wchar_t* CYBOI_HOST_REQUEST_HEADER_HTTP_NAME = CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_HOST_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi if-match request header http name. */
static wchar_t CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'm', L'a', L't', L'c', L'h'};
static wchar_t* CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME = CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi if-modified-since request header http name. */
static wchar_t CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd', L'-', L's', L'i', L'n', L'c', L'e'};
static wchar_t* CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi if-none-match request header http name. */
static wchar_t CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'n', L'o', L'n', L'e', L'-', L'm', L'a', L't', L'c', L'h'};
static wchar_t* CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME = CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi if-range request header http name. */
static wchar_t CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'r', L'a', L'n', L'g', L'e'};
static wchar_t* CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME = CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi if-unmodified-since request header http name. */
static wchar_t CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'i', L'f', L'-', L'u', L'n', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd', L'-', L's', L'i', L'n', L'c', L'e'};
static wchar_t* CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi max-forwards request header http name. */
static wchar_t CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'm', L'a', L'x', L'-', L'f', L'o', L'r', L'w', L'a', L'r', L'd', L's'};
static wchar_t* CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME = CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi proxy-authorization request header http name. */
static wchar_t CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'p', L'r', L'o', L'x', L'y', L'-', L'a', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi range request header http name. */
static wchar_t CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'r', L'a', L'n', L'g', L'e'};
static wchar_t* CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME = CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi referer request header http name. */
static wchar_t CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'e', L'r'};
static wchar_t* CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME = CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_REFERER_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi te request header http name. */
static wchar_t CYBOI_TE_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L't', L'e'};
static wchar_t* CYBOI_TE_REQUEST_HEADER_HTTP_NAME = CYBOI_TE_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_TE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi user-agent request header http name. */
static wchar_t CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'u', L's', L'e', L'r', L'-', L'a', L'g', L'e', L'n', L't'};
static wchar_t* CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME = CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi vary request header http name. */
static wchar_t CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_ARRAY[] = {L'v', L'a', L'r', L'y'};
static wchar_t* CYBOI_VARY_REQUEST_HEADER_HTTP_NAME = CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_VARY_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_REQUEST_HEADER_HTTP_NAME_SOURCE */
#endif
