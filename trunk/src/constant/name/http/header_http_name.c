/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: header_http_name.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HEADER_HTTP_NAME_SOURCE
#define HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The content type header http name. */
static wchar_t CONTENT_TYPE_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L't', L'y', L'p', L'e'};
static wchar_t* CONTENT_TYPE_HEADER_HTTP_NAME = CONTENT_TYPE_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_TYPE_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The content language header http name. */
static wchar_t CONTENT_LANGUAGE_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CONTENT_LANGUAGE_HEADER_HTTP_NAME = CONTENT_LANGUAGE_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_LANGUAGE_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The content encoding header http name. */
static wchar_t CONTENT_ENCODING_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* CONTENT_ENCODING_HEADER_HTTP_NAME = CONTENT_ENCODING_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_ENCODING_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The content length header http name. */
static wchar_t CONTENT_LENGTH_HEADER_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CONTENT_LENGTH_HEADER_HTTP_NAME = CONTENT_LENGTH_HEADER_HTTP_NAME_ARRAY;
static int* CONTENT_LENGTH_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The date header http name. */
static wchar_t DATE_HEADER_HTTP_NAME_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_HEADER_HTTP_NAME = DATE_HEADER_HTTP_NAME_ARRAY;
static int* DATE_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The last modified header http name. */
static wchar_t LAST_MODIFIED_HEADER_HTTP_NAME_ARRAY[] = {L'l', L'a', L's', L't', L'-', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* LAST_MODIFIED_HEADER_HTTP_NAME = LAST_MODIFIED_HEADER_HTTP_NAME_ARRAY;
static int* LAST_MODIFIED_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The set cookie header http name. */
static wchar_t SET_COOKIE_HEADER_HTTP_NAME_ARRAY[] = {L's', L'e', L't', L'-', L'c', L'o', L'o', L'k', L'i', L'e'};
static wchar_t* SET_COOKIE_HEADER_HTTP_NAME = SET_COOKIE_HEADER_HTTP_NAME_ARRAY;
static int* SET_COOKIE_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/* HEADER_HTTP_NAME_SOURCE */
#endif
