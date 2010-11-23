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
 * @version $RCSfile: response_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RESPONSE_HEADER_HTTP_NAME_SOURCE
#define RESPONSE_HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

//
// The following constants are taken from the HTTP 1.1 RFC 2616 specification:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14
// They are sorted alphabetically here.
//

/** The Accept-Ranges response header http name. */
static wchar_t ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'c', L'c', L'e', L'p', L't', L'-', L'R', L'a', L'n', L'g', L'e', L's'};
static wchar_t* ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME = ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The Age response header http name. */
static wchar_t AGE_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'g', L'e'};
static wchar_t* AGE_RESPONSE_HEADER_HTTP_NAME = AGE_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* AGE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The ETag response header http name. */
static wchar_t ETAG_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'E', L'T', L'a', L'g'};
static wchar_t* ETAG_RESPONSE_HEADER_HTTP_NAME = ETAG_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The Location response header http name. */
static wchar_t LOCATION_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'L', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* LOCATION_RESPONSE_HEADER_HTTP_NAME = LOCATION_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The Proxy-Authenticate response header http name. */
static wchar_t PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'P', L'r', L'o', L'x', L'y', L'-', L'A', L'u', L't', L'h', L'e', L'n', L't', L'i', L'c', L'a', L't', L'e'};
static wchar_t* PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME = PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The Retry-After response header http name. */
static wchar_t RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'R', L'e', L't', L'r', L'y', L'-', L'A', L'f', L't', L'e', L'r'};
static wchar_t* RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME = RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The Server response header http name. */
static wchar_t SERVER_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'S', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* SERVER_RESPONSE_HEADER_HTTP_NAME = SERVER_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The WWW-Authenticate response header http name. */
static wchar_t WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY[] = {L'W', L'W', L'W', L'-', L'A', L'u', L't', L'h', L'e', L'n', L't', L'i', L'c', L'a', L't', L'e'};
static wchar_t* WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME = WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_ARRAY;
static int* WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/* RESPONSE_HEADER_HTTP_NAME_SOURCE */
#endif
