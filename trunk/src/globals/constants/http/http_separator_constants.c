/*
 * $RCSfile: http_separator_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-27 07:07:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_SEPARATOR_CONSTANTS_SOURCE
#define HTTP_SEPARATOR_CONSTANTS_SOURCE

#include "../../../globals/constants/character/character_constants.c"
#include "../../../globals/constants/integer/integer_constants.c"

//
// Main parts.
//

/** The http request line separator ("carriage return" and "line feed"). */
static char HTTP_REQUEST_LINE_SEPARATOR_ARRAY[] = {0x0D, 0x0A};
static char* HTTP_REQUEST_LINE_SEPARATOR = HTTP_REQUEST_LINE_SEPARATOR_ARRAY;
static int* HTTP_REQUEST_LINE_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http response line separator ("carriage return" and "line feed"). */
static char HTTP_RESPONSE_LINE_SEPARATOR_ARRAY[] = {0x0D, 0x0A};
static char* HTTP_RESPONSE_LINE_SEPARATOR = HTTP_RESPONSE_LINE_SEPARATOR_ARRAY;
static int* HTTP_RESPONSE_LINE_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http headers separator (twice "carriage return" and "line feed", in other words: an empty line). */
static char HTTP_HEADERS_SEPARATOR_ARRAY[] = {0x0D, 0x0A, 0x0D, 0x0A};
static char* HTTP_HEADERS_SEPARATOR = HTTP_HEADERS_SEPARATOR_ARRAY;
static int* HTTP_HEADERS_SEPARATOR_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Request line parts.
//

/** The http request method separator. */
static char* HTTP_REQUEST_METHOD_SEPARATOR = SPACE_CHARACTER_ARRAY;
static int* HTTP_REQUEST_METHOD_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The http file path separator. */
static char* HTTP_FILE_PATH_SEPARATOR = SPACE_CHARACTER_ARRAY;
static int* HTTP_FILE_PATH_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Response line parts.
//

/** The http protocol version separator. */
static char* HTTP_PROTOCOL_VERSION_SEPARATOR = SPACE_CHARACTER_ARRAY;
static int* HTTP_PROTOCOL_VERSION_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Header parts.
//

/** The http header argument separator ("colon" and "space"). */
static char HTTP_HEADER_ARGUMENT_SEPARATOR_ARRAY[] = {0x3A, 0x20};
static char* HTTP_HEADER_ARGUMENT_SEPARATOR = HTTP_HEADER_ARGUMENT_SEPARATOR_ARRAY;
static int* HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http header value separator ("semicolon" and "space"). */
static char HTTP_HEADER_VALUE_SEPARATOR_ARRAY[] = {0x3B, 0x20};
static char* HTTP_HEADER_VALUE_SEPARATOR = HTTP_HEADER_VALUE_SEPARATOR_ARRAY;
static int* HTTP_HEADER_VALUE_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http header value assignment separator ("equals sign"). */
static char* HTTP_HEADER_VALUE_ASSIGNMENT_SEPARATOR = EQUALS_SIGN_CHARACTER_ARRAY;
static int* HTTP_HEADER_VALUE_ASSIGNMENT_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The http header separator ("carriage return" and "line feed"). */
static char HTTP_HEADER_SEPARATOR_ARRAY[] = {0x0D, 0x0A};
static char* HTTP_HEADER_SEPARATOR = HTTP_HEADER_SEPARATOR_ARRAY;
static int* HTTP_HEADER_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/* HTTP_SEPARATOR_CONSTANTS_SOURCE */
#endif
