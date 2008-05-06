/*
 * $RCSfile: http_request_method_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.7 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_METHOD_CONSTANTS_SOURCE
#define HTTP_REQUEST_METHOD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The get request method. Transfers content from server as arguments in uri. */
static wchar_t HTTP_GET_REQUEST_METHOD_ARRAY[] = {L'G', L'E', L'T'};
static wchar_t* HTTP_GET_REQUEST_METHOD = HTTP_GET_REQUEST_METHOD_ARRAY;
static int* HTTP_GET_REQUEST_METHOD_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The post request method. Transfers content from server in an additional data block consisting of name-value pairs. */
static wchar_t HTTP_POST_REQUEST_METHOD_ARRAY[] = {L'P', L'O', L'S', L'T'};
static wchar_t* HTTP_POST_REQUEST_METHOD = HTTP_POST_REQUEST_METHOD_ARRAY;
static int* HTTP_POST_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The head request method. Sends GET or POST request header, but not content. */
static wchar_t HTTP_HEAD_REQUEST_METHOD_ARRAY[] = {L'H', L'E', L'A', L'D'};
static wchar_t* HTTP_HEAD_REQUEST_METHOD = HTTP_HEAD_REQUEST_METHOD_ARRAY;
static int* HTTP_HEAD_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The put request method. Uploads data to webserver via given uri. */
static wchar_t HTTP_PUT_REQUEST_METHOD_ARRAY[] = {L'P', L'U', L'T'};
static wchar_t* HTTP_PUT_REQUEST_METHOD = HTTP_PUT_REQUEST_METHOD_ARRAY;
static int* HTTP_PUT_REQUEST_METHOD_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The delete request method. Deletes the specified file on the webserver. */
static wchar_t HTTP_DELETE_REQUEST_METHOD_ARRAY[] = {L'D', L'E', L'L', L'E', L'T', L'E'};
static wchar_t* HTTP_DELETE_REQUEST_METHOD = HTTP_DELETE_REQUEST_METHOD_ARRAY;
static int* HTTP_DELETE_REQUEST_METHOD_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The trace request method. Returns the request as the webserver received it. */
static wchar_t HTTP_TRACE_REQUEST_METHOD_ARRAY[] = {L'T', L'R', L'A', L'C', L'E'};
static wchar_t* HTTP_TRACE_REQUEST_METHOD = HTTP_TRACE_REQUEST_METHOD_ARRAY;
static int* HTTP_TRACE_REQUEST_METHOD_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The options request method. Returns a list of methods and features supported by the webserver. */
static wchar_t HTTP_OPTIONS_REQUEST_METHOD_ARRAY[] = {L'O', L'P', L'T', L'I', L'O', L'N', L'S'};
static wchar_t* HTTP_OPTIONS_REQUEST_METHOD = HTTP_OPTIONS_REQUEST_METHOD_ARRAY;
static int* HTTP_OPTIONS_REQUEST_METHOD_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The connect request method. Connects via ssl tunnel on proxy server. */
static wchar_t HTTP_CONNECT_REQUEST_METHOD_ARRAY[] = {L'C', L'O', L'N', L'N', L'E', L'C', L'T'};
static wchar_t* HTTP_CONNECT_REQUEST_METHOD = HTTP_CONNECT_REQUEST_METHOD_ARRAY;
static int* HTTP_CONNECT_REQUEST_METHOD_COUNT = NUMBER_7_INTEGER_ARRAY;

/* HTTP_REQUEST_METHOD_CONSTANTS_SOURCE */
#endif
