/*
 * $RCSfile: http_request_method_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2007-01-18 22:51:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_METHOD_CONSTANTS_SOURCE
#define HTTP_REQUEST_METHOD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer_constants.c"

/** The get request method. */
static char HTTP_GET_REQUEST_METHOD_ARRAY[] = {'G', 'E', 'T'};
static char* HTTP_GET_REQUEST_METHOD = HTTP_GET_REQUEST_METHOD_ARRAY;
static int* HTTP_GET_REQUEST_METHOD_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The post request method. */
static char HTTP_POST_REQUEST_METHOD_ARRAY[] = {'P', 'O', 'S', 'T'};
static char* HTTP_POST_REQUEST_METHOD = HTTP_POST_REQUEST_METHOD_ARRAY;
static int* HTTP_POST_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The head request method. */
static char HTTP_HEAD_REQUEST_METHOD_ARRAY[] = {'H', 'E', 'A', 'D'};
static char* HTTP_POSHTTP_HEAD_REQUEST_METHOD = HTTP_HEAD_REQUEST_METHOD_ARRAY;
static int* HTTP_HEAD_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The put request method. */
static char HTTP_PUT_REQUEST_METHOD_ARRAY[] = {'P', 'U', 'T'};
static char* HTTP_PUT_REQUEST_METHOD = HTTP_PUT_REQUEST_METHOD_ARRAY;
static int* HTTP_PUT_REQUEST_METHOD_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The delete request method. */
static char HTTP_DELETE_REQUEST_METHOD_ARRAY[] = {'D', 'E', 'L', 'E', 'T', 'E'};
static char* HTTP_DELETE_REQUEST_METHOD = HTTP_DELETE_REQUEST_METHOD_ARRAY;
static int* HTTP_DELETE_REQUEST_METHOD_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The trace request method. */
static char HTTP_TRACE_REQUEST_METHOD_ARRAY[] = {'T', 'R', 'A', 'C', 'E'};
static char* HTTP_TRACE_REQUEST_METHOD = HTTP_TRACE_REQUEST_METHOD_ARRAY;
static int* HTTP_TRACE_REQUEST_METHOD_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The options request method. */
static char HTTP_OPTIONS_REQUEST_METHOD_ARRAY[] = {'O', 'P', 'T', 'I', 'O', 'N', 'S'};
static char* HTTP_OPTIONS_REQUEST_METHOD = HTTP_OPTIONS_REQUEST_METHOD_ARRAY;
static int* HTTP_OPTIONS_REQUEST_METHOD_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The connect request method. */
static char HTTP_CONNECT_REQUEST_METHOD_ARRAY[] = {'C', 'O', 'N', 'N', 'E', 'C', 'T'};
static char* HTTP_CONNECT_REQUEST_METHOD = HTTP_CONNECT_REQUEST_METHOD_ARRAY;
static int* HTTP_CONNECT_REQUEST_METHOD_COUNT = NUMBER_7_INTEGER_ARRAY;

/* HTTP_REQUEST_METHOD_CONSTANTS_SOURCE */
#endif
