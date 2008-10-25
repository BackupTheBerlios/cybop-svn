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
 * @version $RCSfile: webdav_request_method_http_model.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WEBDAV_REQUEST_METHOD_HTTP_MODEL_SOURCE
#define WEBDAV_REQUEST_METHOD_HTTP_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The propfind webdav request method http model. Reads properties as resources from an xml file. Retrieves the directory structure of a remote system. */
static wchar_t PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'P', L'R', L'O', L'P', L'F', L'I', L'N', L'D'};
static wchar_t* PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL = PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The proppatch webdav request method http model. Changes and deletes various properties of a resource in one single atomic act. */
static wchar_t PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'P', L'R', L'O', L'P', L'P', L'A', L'T', L'C', L'H'};
static wchar_t* PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL = PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The mkcol webdav request method http model. Creates a collection (also called directory). */
static wchar_t MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'M', L'K', L'C', L'O', L'L'};
static wchar_t* MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL = MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy webdav request method http model. Copies a resource from one uri to another. */
static wchar_t COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'C', L'O', L'P', L'Y'};
static wchar_t* COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL = COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The move webdav request method http model. Moves a resource from one uri to another. */
static wchar_t MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'M', L'O', L'V', L'E'};
static wchar_t* MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL = MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The lock webdav request method http model. Locks a resource. */
static wchar_t LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'L', L'O', L'C', L'K'};
static wchar_t* LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL = LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The unlock webdav request method http model. Unlocks a resource. */
static wchar_t UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'U', L'N', L'L', L'O', L'C', L'K'};
static wchar_t* UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL = UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* WEBDAV_REQUEST_METHOD_HTTP_MODEL_SOURCE */
#endif
