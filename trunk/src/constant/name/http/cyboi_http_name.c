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
 * @version $RCSfile: compound_http_name.c,v $ $Revision: 1.2 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_HTTP_NAME_SOURCE
#define CYBOI_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

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

/** The cyboi arguments http name. */
/*??
static wchar_t CYBOI_ARGUMENTS_HTTP_NAME_ARRAY[] = {L'a', L'r', L'g', L'u', L'm', L'e', L'n', L't', L's'};
static wchar_t* CYBOI_ARGUMENTS_HTTP_NAME = CYBOI_ARGUMENTS_HTTP_NAME_ARRAY;
static int* CYBOI_ARGUMENTS_HTTP_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi body http name. */
/*??
static wchar_t CYBOI_BODY_HTTP_NAME_ARRAY[] = {L'b', L'o', L'd', L'y'};
static wchar_t* CYBOI_BODY_HTTP_NAME = CYBOI_BODY_HTTP_NAME_ARRAY;
static int* CYBOI_BODY_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi connection http name. */
/*??
static wchar_t CYBOI_CONNECTION_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L'n', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* CYBOI_CONNECTION_HTTP_NAME = CYBOI_CONNECTION_HTTP_NAME_ARRAY;
static int* CYBOI_CONNECTION_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content_language http name. */
/*??
static wchar_t CYBOI_CONTENT_LANGUAGE_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CYBOI_CONTENT_LANGUAGE_HTTP_NAME = CYBOI_CONTENT_LANGUAGE_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_LANGUAGE_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content_length http name. */
/*??
static wchar_t CYBOI_CONTENT_LENGTH_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CYBOI_CONTENT_LENGTH_HTTP_NAME = CYBOI_CONTENT_LENGTH_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_LENGTH_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi content_type http name. */
/*??
static wchar_t CYBOI_CONTENT_TYPE_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L't', L'y', L'p', L'e'};
static wchar_t* CYBOI_CONTENT_TYPE_HTTP_NAME = CYBOI_CONTENT_TYPE_HTTP_NAME_ARRAY;
static int* CYBOI_CONTENT_TYPE_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi date http name. */
/*??
static wchar_t CYBOI_DATE_HTTP_NAME_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* CYBOI_DATE_HTTP_NAME = CYBOI_DATE_HTTP_NAME_ARRAY;
static int* CYBOI_DATE_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi host http name. */
/*??
static wchar_t CYBOI_HOST_HTTP_NAME_ARRAY[] = {L'h', L'o', L's', L't'};
static wchar_t* CYBOI_HOST_HTTP_NAME = CYBOI_HOST_HTTP_NAME_ARRAY;
static int* CYBOI_HOST_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi last_modified http name. */
/*??
static wchar_t CYBOI_LAST_MODIFIED_HTTP_NAME_ARRAY[] = {L'l', L'a', L's', L't', L'_', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* CYBOI_LAST_MODIFIED_HTTP_NAME = CYBOI_LAST_MODIFIED_HTTP_NAME_ARRAY;
static int* CYBOI_LAST_MODIFIED_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi location http name. */
/*??
static wchar_t CYBOI_LOCATION_HTTP_NAME_ARRAY[] = {L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CYBOI_LOCATION_HTTP_NAME = CYBOI_LOCATION_HTTP_NAME_ARRAY;
static int* CYBOI_LOCATION_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi method http name. */
static wchar_t CYBOI_METHOD_HTTP_NAME_ARRAY[] = {L'm', L'e', L't', L'h', L'o', L'd'};
static wchar_t* CYBOI_METHOD_HTTP_NAME = CYBOI_METHOD_HTTP_NAME_ARRAY;
static int* CYBOI_METHOD_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi protocol http name. */
static wchar_t CYBOI_PROTOCOL_HTTP_NAME_ARRAY[] = {L'p', L'r', L'o', L't', L'o', L'c', L'o', L'l'};
static wchar_t* CYBOI_PROTOCOL_HTTP_NAME = CYBOI_PROTOCOL_HTTP_NAME_ARRAY;
static int* CYBOI_PROTOCOL_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi server http name. */
/*??
static wchar_t CYBOI_SERVER_HTTP_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* CYBOI_SERVER_HTTP_NAME = CYBOI_SERVER_HTTP_NAME_ARRAY;
static int* CYBOI_SERVER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi status_code http name. */
/*??
static wchar_t CYBOI_STATUS_CODE_HTTP_NAME_ARRAY[] = {L's', L't', L'a', L't', L'u', L's', L'_', L'c', L'o', L'd', L'e'};
static wchar_t* CYBOI_STATUS_CODE_HTTP_NAME = CYBOI_STATUS_CODE_HTTP_NAME_ARRAY;
static int* CYBOI_STATUS_CODE_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The uri http name.
 *
 * URI - Uniform Resource Identifier
 */
static wchar_t CYBOI_URI_HTTP_NAME_ARRAY[] = {L'u', L'r', L'i'};
static wchar_t* CYBOI_URI_HTTP_NAME = CYBOI_URI_HTTP_NAME_ARRAY;
static int* CYBOI_URI_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The uri-text http name.
 *
 * URI - Uniform Resource Identifier
 */
static wchar_t CYBOI_URI_TEXT_HTTP_NAME_ARRAY[] = {L'u', L'r', L'i', L'-', L't', L'e', L'x', L't'};
static wchar_t* CYBOI_URI_TEXT_HTTP_NAME = CYBOI_URI_TEXT_HTTP_NAME_ARRAY;
static int* CYBOI_URI_TEXT_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_HTTP_NAME_SOURCE */
#endif
