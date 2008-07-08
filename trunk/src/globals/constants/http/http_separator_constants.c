/*
 * $RCSfile: http_separator_constants.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2008-07-08 07:11:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_SEPARATOR_CONSTANTS_SOURCE
#define HTTP_SEPARATOR_CONSTANTS_SOURCE

#include "../../../globals/constants/character/code/character_code_constants.c"
#include "../../../globals/constants/integer/integer_constants.c"

// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).

//
// Main parts.
//

/** The http request line separator ("carriage return" and "line feed"). */
static wchar_t HTTP_REQUEST_LINE_SEPARATOR_ARRAY[] = {0x000D, 0x000A};
static wchar_t* HTTP_REQUEST_LINE_SEPARATOR = HTTP_REQUEST_LINE_SEPARATOR_ARRAY;
static int* HTTP_REQUEST_LINE_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http response line separator ("carriage return" and "line feed"). */
static wchar_t HTTP_RESPONSE_LINE_SEPARATOR_ARRAY[] = {0x000D, 0x000A};
static wchar_t* HTTP_RESPONSE_LINE_SEPARATOR = HTTP_RESPONSE_LINE_SEPARATOR_ARRAY;
static int* HTTP_RESPONSE_LINE_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http headers separator (twice "carriage return" and "line feed", in other words: an empty line). */
static wchar_t HTTP_HEADERS_SEPARATOR_ARRAY[] = {0x000D, 0x000A, 0x000D, 0x000A};
static wchar_t* HTTP_HEADERS_SEPARATOR = HTTP_HEADERS_SEPARATOR_ARRAY;
static int* HTTP_HEADERS_SEPARATOR_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The http body separator ("carriage return" and "line feed"). */
static wchar_t HTTP_BODY_SEPARATOR_ARRAY[] = {0x000D, 0x000A};
static wchar_t* HTTP_BODY_SEPARATOR = HTTP_BODY_SEPARATOR_ARRAY;
static int* HTTP_BODY_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Request line parts.
//

/** The http request method separator. */
static wchar_t* HTTP_REQUEST_METHOD_SEPARATOR = SPACE_WIDE_CHARACTER_ARRAY;
static int* HTTP_REQUEST_METHOD_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The http uniform resource identifier separator. */
static wchar_t* HTTP_UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR = SPACE_WIDE_CHARACTER_ARRAY;
static int* HTTP_UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Response line parts.
//

/** The http protocol version separator. */
static wchar_t* HTTP_PROTOCOL_VERSION_SEPARATOR = SPACE_WIDE_CHARACTER_ARRAY;
static int* HTTP_PROTOCOL_VERSION_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Header parts.
//

/** The http header argument separator ("colon" and "space"). */
static wchar_t HTTP_HEADER_ARGUMENT_SEPARATOR_ARRAY[] = {0x003A, 0x0020};
static wchar_t* HTTP_HEADER_ARGUMENT_SEPARATOR = HTTP_HEADER_ARGUMENT_SEPARATOR_ARRAY;
static int* HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http header value separator ("semicolon" and "space"). */
static wchar_t HTTP_HEADER_VALUE_SEPARATOR_ARRAY[] = {0x003B, 0x0020};
static wchar_t* HTTP_HEADER_VALUE_SEPARATOR = HTTP_HEADER_VALUE_SEPARATOR_ARRAY;
static int* HTTP_HEADER_VALUE_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The http header value assignment separator ("equals sign"). */
static wchar_t* HTTP_HEADER_VALUE_ASSIGNMENT_SEPARATOR = EQUALS_SIGN_WIDE_CHARACTER_ARRAY;
static int* HTTP_HEADER_VALUE_ASSIGNMENT_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The http header separator ("carriage return" and "line feed"). */
static wchar_t HTTP_HEADER_SEPARATOR_ARRAY[] = {0x000D, 0x000A};
static wchar_t* HTTP_HEADER_SEPARATOR = HTTP_HEADER_SEPARATOR_ARRAY;
static int* HTTP_HEADER_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/* HTTP_SEPARATOR_CONSTANTS_SOURCE */
#endif
