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
 * @version $RCSfile: entity_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ENTITY_HEADER_HTTP_NAME_SOURCE
#define ENTITY_HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

//
// The following constants are taken from the HTTP 1.1 RFC 2616 specification:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14
// They are sorted alphabetically here.
//

/** The Allow entity header http name. */
static wchar_t ALLOW_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'A', L'l', L'l', L'o', L'w'};
static wchar_t* ALLOW_ENTITY_HEADER_HTTP_NAME = ALLOW_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-Encoding entity header http name. */
static wchar_t CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'E', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME = CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-Language entity header http name. */
static wchar_t CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'L', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME = CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-Length entity header http name. */
static wchar_t CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'L', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME = CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-Location entity header http name. */
static wchar_t CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'L', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME = CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-MD5 entity header http name. */
static wchar_t CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'M', L'D', L'5'};
static wchar_t* CONTENT_MD5_ENTITY_HEADER_HTTP_NAME = CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-Range entity header http name. */
static wchar_t CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'R', L'a', L'n', L'g', L'e'};
static wchar_t* CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME = CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The Content-Type entity header http name. */
static wchar_t CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L't', L'e', L'n', L't', L'-', L'T', L'y', L'p', L'e'};
static wchar_t* CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME = CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The Expires entity header http name. */
static wchar_t EXPIRES_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'E', L'x', L'p', L'i', L'r', L'e', L's'};
static wchar_t* EXPIRES_ENTITY_HEADER_HTTP_NAME = EXPIRES_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The Last-Modified entity header http name. */
static wchar_t LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'L', L'a', L's', L't', L'-', L'M', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME = LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/* ENTITY_HEADER_HTTP_NAME_SOURCE */
#endif
