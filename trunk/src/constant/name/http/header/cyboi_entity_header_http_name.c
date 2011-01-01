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
 * @version $RCSfile: entity_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_ENTITY_HEADER_HTTP_NAME_SOURCE
#define CYBOI_ENTITY_HEADER_HTTP_NAME_SOURCE

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

/** The cyboi allow entity header http name. */
static wchar_t CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'a', L'l', L'l', L'o', L'w'};
static wchar_t* CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME = CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-encoding entity header http name. */
static wchar_t CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-language entity header http name. */
static wchar_t CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-length entity header http name. */
static wchar_t CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-location entity header http name. */
static wchar_t CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-md5 entity header http name. */
static wchar_t CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'm', L'd', L'5'};
static wchar_t* CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-range entity header http name. */
static wchar_t CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'r', L'a', L'n', L'g', L'e'};
static wchar_t* CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content-type entity header http name. */
static wchar_t CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L't', L'y', L'p', L'e'};
static wchar_t* CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME = CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi expires entity header http name. */
static wchar_t CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'e', L'x', L'p', L'i', L'r', L'e', L's'};
static wchar_t* CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME = CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi last-modified entity header http name. */
static wchar_t CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_ARRAY[] = {L'l', L'a', L's', L't', L'-', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME = CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_ARRAY;
static int* CYBOI_LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_ENTITY_HEADER_HTTP_NAME_SOURCE */
#endif
