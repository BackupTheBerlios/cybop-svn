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
 * @version $RCSfile: compound_http_name.c,v $ $Revision: 1.2 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_HTTP_NAME_SOURCE
#define COMPOUND_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The arguments compound http name. */
static char ARGUMENTS_COMPOUND_HTTP_NAME_ARRAY[] = {'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', 's'};
static char* ARGUMENTS_COMPOUND_HTTP_NAME = ARGUMENTS_COMPOUND_HTTP_NAME_ARRAY;
static int* ARGUMENTS_COMPOUND_HTTP_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The body compound http name. */
static char BODY_COMPOUND_HTTP_NAME_ARRAY[] = {'b', 'o', 'd', 'y'};
static char* BODY_COMPOUND_HTTP_NAME = BODY_COMPOUND_HTTP_NAME_ARRAY;
static int* BODY_COMPOUND_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The connection compound http name. */
static char CONNECTION_COMPOUND_HTTP_NAME_ARRAY[] = {'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n'};
static char* CONNECTION_COMPOUND_HTTP_NAME = CONNECTION_COMPOUND_HTTP_NAME_ARRAY;
static int* CONNECTION_COMPOUND_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The content_language compound http name. */
static char CONTENT_LANGUAGE_COMPOUND_HTTP_NAME_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '_', 'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static char* CONTENT_LANGUAGE_COMPOUND_HTTP_NAME = CONTENT_LANGUAGE_COMPOUND_HTTP_NAME_ARRAY;
static int* CONTENT_LANGUAGE_COMPOUND_HTTP_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The content_length compound http name. */
static char CONTENT_LENGTH_COMPOUND_HTTP_NAME_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '_', 'l', 'e', 'n', 'g', 't', 'h'};
static char* CONTENT_LENGTH_COMPOUND_HTTP_NAME = CONTENT_LENGTH_COMPOUND_HTTP_NAME_ARRAY;
static int* CONTENT_LENGTH_COMPOUND_HTTP_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The content_type compound http name. */
static char CONTENT_TYPE_COMPOUND_HTTP_NAME_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '_', 't', 'y', 'p', 'e'};
static char* CONTENT_TYPE_COMPOUND_HTTP_NAME = CONTENT_TYPE_COMPOUND_HTTP_NAME_ARRAY;
static int* CONTENT_TYPE_COMPOUND_HTTP_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The date compound http name. */
static char DATE_COMPOUND_HTTP_NAME_ARRAY[] = {'d', 'a', 't', 'e'};
static char* DATE_COMPOUND_HTTP_NAME = DATE_COMPOUND_HTTP_NAME_ARRAY;
static int* DATE_COMPOUND_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The host compound http name. */
static char HOST_COMPOUND_HTTP_NAME_ARRAY[] = {'h', 'o', 's', 't'};
static char* HOST_COMPOUND_HTTP_NAME = HOST_COMPOUND_HTTP_NAME_ARRAY;
static int* HOST_COMPOUND_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The last_modified compound http name. */
static char LAST_MODIFIED_COMPOUND_HTTP_NAME_ARRAY[] = {'l', 'a', 's', 't', '_', 'm', 'o', 'd', 'i', 'f', 'i', 'e', 'd'};
static char* LAST_MODIFIED_COMPOUND_HTTP_NAME = LAST_MODIFIED_COMPOUND_HTTP_NAME_ARRAY;
static int* LAST_MODIFIED_COMPOUND_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The location compound http name. */
static char LOCATION_COMPOUND_HTTP_NAME_ARRAY[] = {'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};
static char* LOCATION_COMPOUND_HTTP_NAME = LOCATION_COMPOUND_HTTP_NAME_ARRAY;
static int* LOCATION_COMPOUND_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The method compound http name. */
static char METHOD_COMPOUND_HTTP_NAME_ARRAY[] = {'m', 'e', 't', 'h', 'o', 'd'};
static char* METHOD_COMPOUND_HTTP_NAME = METHOD_COMPOUND_HTTP_NAME_ARRAY;
static int* METHOD_COMPOUND_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The protocol compound http name. */
static char PROTOCOL_COMPOUND_HTTP_NAME_ARRAY[] = {'p', 'r', 'o', 't', 'o', 'c', 'o', 'l'};
static char* PROTOCOL_COMPOUND_HTTP_NAME = PROTOCOL_COMPOUND_HTTP_NAME_ARRAY;
static int* PROTOCOL_COMPOUND_HTTP_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The server compound http name. */
static char SERVER_COMPOUND_HTTP_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'e', 'r'};
static char* SERVER_COMPOUND_HTTP_NAME = SERVER_COMPOUND_HTTP_NAME_ARRAY;
static int* SERVER_COMPOUND_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The status_code compound http name. */
static char STATUS_CODE_COMPOUND_HTTP_NAME_ARRAY[] = {'s', 't', 'a', 't', 'u', 's', '_', 'c', 'o', 'd', 'e'};
static char* STATUS_CODE_COMPOUND_HTTP_NAME = STATUS_CODE_COMPOUND_HTTP_NAME_ARRAY;
static int* STATUS_CODE_COMPOUND_HTTP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The uniform resource identifier (uri) compound http name. */
static char URI_COMPOUND_HTTP_NAME_ARRAY[] = {'u', 'r', 'i'};
static char* URI_COMPOUND_HTTP_NAME = URI_COMPOUND_HTTP_NAME_ARRAY;
static int* URI_COMPOUND_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPOUND_HTTP_NAME_SOURCE */
#endif
