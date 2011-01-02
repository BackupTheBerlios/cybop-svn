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
 * @version $RCSfile: separator_http_name.c,v $ $Revision: 1.2 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_URI_NAME_SOURCE
#define HTTP_REQUEST_URI_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The no resource (asterisk) http request uri name. */
static wchar_t* NO_RESOURCE_HTTP_REQUEST_URI_NAME = ASTERISK_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* NO_RESOURCE_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The absolute uri (colon) http request uri name. */
static wchar_t* ABSOLUTE_URI_HTTP_REQUEST_URI_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ABSOLUTE_URI_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The authority form (solidus, solidus) http request uri name. */
static wchar_t AUTHORITY_FORM_HTTP_REQUEST_URI_NAME_ARRAY[] = {0x002F, 0x002F};
static wchar_t* AUTHORITY_FORM_HTTP_REQUEST_URI_NAME = AUTHORITY_FORM_HTTP_REQUEST_URI_NAME_ARRAY;
static int* AUTHORITY_FORM_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The absolute path (solidus) http request uri name. */
static wchar_t* ABSOLUTE_PATH_HTTP_REQUEST_URI_NAME = SOLIDUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ABSOLUTE_PATH_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/* HTTP_REQUEST_URI_NAME_SOURCE */
#endif
