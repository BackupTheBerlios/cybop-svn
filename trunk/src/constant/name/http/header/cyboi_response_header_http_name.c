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
 * @version $RCSfile: response_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_RESPONSE_HEADER_HTTP_NAME_SOURCE
#define CYBOI_RESPONSE_HEADER_HTTP_NAME_SOURCE

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

/** The cyboi accept-ranges response header http name. */
static wchar_t CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'c', L'c', L'e', L'p', L't', L'-', L'r', L'a', L'n', L'g', L'e', L's'};
static wchar_t* CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME = CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi age response header http name. */
static wchar_t CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'g', L'e'};
static wchar_t* CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME = CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_AGE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi etag response header http name. */
static wchar_t CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'e', L't', L'a', L'g'};
static wchar_t* CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME = CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi location response header http name. */
static wchar_t CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME = CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi proxy-authenticate response header http name. */
static wchar_t CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'p', L'r', L'o', L'x', L'y', L'-', L'a', L'u', L't', L'h', L'e', L'n', L't', L'i', L'c', L'a', L't', L'e'};
static wchar_t* CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME = CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi retry-after response header http name. */
static wchar_t CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'r', L'e', L't', L'r', L'y', L'-', L'a', L'f', L't', L'e', L'r'};
static wchar_t* CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME = CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi server response header http name. */
static wchar_t CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME = CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi www-authenticate response header http name. */
static wchar_t CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'w', L'w', L'w', L'-', L'a', L'u', L't', L'h', L'e', L'n', L't', L'i', L'c', L'a', L't', L'e'};
static wchar_t* CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME = CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_RESPONSE_HEADER_HTTP_NAME_SOURCE */
#endif
