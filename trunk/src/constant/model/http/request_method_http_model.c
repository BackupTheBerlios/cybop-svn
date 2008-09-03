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
 * @version $RCSfile: request_method_http_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REQUEST_METHOD_HTTP_MODEL_SOURCE
#define REQUEST_METHOD_HTTP_MODEL_SOURCE

#include "../../../constant/model/memory/integer_model.c"

/** The get request method http model. Transfers content from server as arguments in uri. */
static wchar_t GET_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'G', L'E', L'T'};
static wchar_t* GET_REQUEST_METHOD_HTTP_MODEL = HTTP_GET_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* GET_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The post request method http model. Transfers content from server in an additional data block consisting of name-value pairs. */
static wchar_t POST_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'P', L'O', L'S', L'T'};
static wchar_t* POST_REQUEST_METHOD_HTTP_MODEL = HTTP_POST_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* POST_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The head request method http model. Sends GET or POST request header, but not content. */
static wchar_t HEAD_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'H', L'E', L'A', L'D'};
static wchar_t* HEAD_REQUEST_METHOD_HTTP_MODEL = HTTP_HEAD_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The put request method http model. Uploads data to webserver via given uri. */
static wchar_t PUT_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'P', L'U', L'T'};
static wchar_t* PUT_REQUEST_METHOD_HTTP_MODEL = HTTP_PUT_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* PUT_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The delete request method http model. Deletes the specified file on the webserver. */
static wchar_t DELETE_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'D', L'E', L'L', L'E', L'T', L'E'};
static wchar_t* DELETE_REQUEST_METHOD_HTTP_MODEL = HTTP_DELETE_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The trace request method http model. Returns the request as the webserver received it. */
static wchar_t TRACE_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'T', L'R', L'A', L'C', L'E'};
static wchar_t* TRACE_REQUEST_METHOD_HTTP_MODEL = HTTP_TRACE_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The options request method http model. Returns a list of methods and features supported by the webserver. */
static wchar_t OPTIONS_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'O', L'P', L'T', L'I', L'O', L'N', L'S'};
static wchar_t* OPTIONS_REQUEST_METHOD_HTTP_MODEL = HTTP_OPTIONS_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The connect request method http model. Connects via ssl tunnel on proxy server. */
static wchar_t CONNECT_REQUEST_METHOD_HTTP_MODEL_ARRAY[] = {L'C', L'O', L'N', L'N', L'E', L'C', L'T'};
static wchar_t* CONNECT_REQUEST_METHOD_HTTP_MODEL = HTTP_CONNECT_REQUEST_METHOD_HTTP_MODEL_ARRAY;
static int* CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/* REQUEST_METHOD_HTTP_MODEL_SOURCE */
#endif
