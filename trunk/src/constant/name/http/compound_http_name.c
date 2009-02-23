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
 * @version $RCSfile: compound_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-02-23 22:53:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_HTTP_NAME_SOURCE
#define COMPOUND_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The method compound http name. */
static wchar_t METHOD_COMPOUND_HTTP_NAME_ARRAY[] = {L'm', L'e', L't', L'h', L'o', L'd'};
static wchar_t* METHOD_COMPOUND_HTTP_NAME = METHOD_COMPOUND_HTTP_NAME_ARRAY;
static int* METHOD_COMPOUND_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The uniform resource identifier (uri) compound http name. */
static wchar_t URI_COMPOUND_HTTP_NAME_ARRAY[] = {L'u', L'r', L'i'};
static wchar_t* URI_COMPOUND_HTTP_NAME = URI_COMPOUND_HTTP_NAME_ARRAY;
static int* URI_COMPOUND_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The protocol compound http name. */
static wchar_t PROTOCOL_COMPOUND_HTTP_NAME_ARRAY[] = {L'p', L'r', L'o', L't', L'o', L'c', L'o', L'l'};
static wchar_t* PROTOCOL_COMPOUND_HTTP_NAME = PROTOCOL_COMPOUND_HTTP_NAME_ARRAY;
static int* PROTOCOL_COMPOUND_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The status_code compound http name. */
static wchar_t STATUS_CODE_COMPOUND_HTTP_NAME_ARRAY[] = {L's', L't', L'a', L't', L'u', L's', L'_', L'c', L'o', L'd', L'e'};
static wchar_t* STATUS_CODE_COMPOUND_HTTP_NAME = STATUS_CODE_COMPOUND_HTTP_NAME_ARRAY;
static int* STATUS_CODE_COMPOUND_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The host compound http name. */
static wchar_t HOST_COMPOUND_HTTP_NAME_ARRAY[] = {L'h', L'o', L's', L't'};
static wchar_t* HOST_COMPOUND_HTTP_NAME = HOST_COMPOUND_HTTP_NAME_ARRAY;
static int* HOST_COMPOUND_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The server compound http name. */
static wchar_t SERVER_COMPOUND_HTTP_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* SERVER_COMPOUND_HTTP_NAME = SERVER_COMPOUND_HTTP_NAME_ARRAY;
static int* SERVER_COMPOUND_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The date compound http name. */
static wchar_t DATE_COMPOUND_HTTP_NAME_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_COMPOUND_HTTP_NAME = DATE_COMPOUND_HTTP_NAME_ARRAY;
static int* DATE_COMPOUND_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The location compound http name. */
static wchar_t LOCATION_COMPOUND_HTTP_NAME_ARRAY[] = {L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* LOCATION_COMPOUND_HTTP_NAME = LOCATION_COMPOUND_HTTP_NAME_ARRAY;
static int* LOCATION_COMPOUND_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The last_modified compound http name. */
static wchar_t LAST_MODIFIED_COMPOUND_HTTP_NAME_ARRAY[] = {L'l', L'a', L's', L't', L'_', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* LAST_MODIFIED_COMPOUND_HTTP_NAME = LAST_MODIFIED_COMPOUND_HTTP_NAME_ARRAY;
static int* LAST_MODIFIED_COMPOUND_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The content_language compound http name. */
static wchar_t CONTENT_LANGUAGE_COMPOUND_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CONTENT_LANGUAGE_COMPOUND_HTTP_NAME = CONTENT_LANGUAGE_COMPOUND_HTTP_NAME_ARRAY;
static int* CONTENT_LANGUAGE_COMPOUND_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The content_type compound http name. */
static wchar_t CONTENT_TYPE_COMPOUND_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L't', L'y', L'p', L'e'};
static wchar_t* CONTENT_TYPE_COMPOUND_HTTP_NAME = CONTENT_TYPE_COMPOUND_HTTP_NAME_ARRAY;
static int* CONTENT_TYPE_COMPOUND_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The content_length compound http name. */
static wchar_t CONTENT_LENGTH_COMPOUND_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CONTENT_LENGTH_COMPOUND_HTTP_NAME = CONTENT_LENGTH_COMPOUND_HTTP_NAME_ARRAY;
static int* CONTENT_LENGTH_COMPOUND_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The connection compound http name. */
static wchar_t CONNECTION_COMPOUND_HTTP_NAME_ARRAY[] = {L'c', L'o', L'n', L'n', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* CONNECTION_COMPOUND_HTTP_NAME = CONNECTION_COMPOUND_HTTP_NAME_ARRAY;
static int* CONNECTION_COMPOUND_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The body compound http name. */
static wchar_t BODY_COMPOUND_HTTP_NAME_ARRAY[] = {L'b', L'o', L'd', L'y'};
static wchar_t* BODY_COMPOUND_HTTP_NAME = BODY_COMPOUND_HTTP_NAME_ARRAY;
static int* BODY_COMPOUND_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The arguments compound http name. */
static wchar_t ARGUMENTS_COMPOUND_HTTP_NAME_ARRAY[] = {L'a', L'r', L'g', L'u', L'm', L'e', L'n', L't', L's'};
static wchar_t* ARGUMENTS_COMPOUND_HTTP_NAME = ARGUMENTS_COMPOUND_HTTP_NAME_ARRAY;
static int* ARGUMENTS_COMPOUND_HTTP_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPOUND_HTTP_NAME_SOURCE */
#endif
