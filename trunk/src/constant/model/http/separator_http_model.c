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
 * @version $RCSfile: separator_http_model.c,v $ $Revision: 1.3 $ $Date: 2008-09-11 23:02:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEPARATOR_HTTP_MODEL_SOURCE
#define SEPARATOR_HTTP_MODEL_SOURCE

#include "../../..//home/cybop/src/constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"

// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).

//
// Main parts.
//

/** The request line separator ("carriage return" and "line feed") http model. */
static wchar_t REQUEST_LINE_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x000D, 0x000A};
static wchar_t* REQUEST_LINE_SEPARATOR_HTTP_MODEL = REQUEST_LINE_SEPARATOR_HTTP_MODEL_HTTP_MODEL_ARRAY;
static int* REQUEST_LINE_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The response line separator ("carriage return" and "line feed") http model. */
static wchar_t RESPONSE_LINE_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x000D, 0x000A};
static wchar_t* RESPONSE_LINE_SEPARATOR_HTTP_MODEL = HTTP_RESPONSE_LINE_SEPARATOR_HTTP_MODEL_ARRAY;
static int* RESPONSE_LINE_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The headers separator (twice "carriage return" and "line feed", in other words: an empty line) http model. */
static wchar_t HEADERS_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x000D, 0x000A, 0x000D, 0x000A};
static wchar_t* HEADERS_SEPARATOR_HTTP_MODEL = HEADERS_SEPARATOR_HTTP_MODEL_HTTP_MODEL_ARRAY;
static int* HEADERS_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The body separator ("carriage return" and "line feed") http model. */
static wchar_t BODY_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x000D, 0x000A};
static wchar_t* BODY_SEPARATOR_HTTP_MODEL = BODY_SEPARATOR_HTTP_MODEL_HTTP_MODEL_ARRAY;
static int* BODY_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

//
// Request line parts.
//

/** The request method separator http model. */
static wchar_t* REQUEST_METHOD_SEPARATOR_HTTP_MODEL = SPACE_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* REQUEST_METHOD_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The uniform resource identifier separator http model. */
static wchar_t* UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR_HTTP_MODEL = SPACE_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Response line parts.
//

/** The protocol version separator http model. */
static wchar_t* PROTOCOL_VERSION_SEPARATOR_HTTP_MODEL = SPACE_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PROTOCOL_VERSION_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Header parts.
//

/** The header argument separator ("colon" and "space") http model. */
static wchar_t HEADER_ARGUMENT_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x003A, 0x0020};
static wchar_t* HEADER_ARGUMENT_SEPARATOR_HTTP_MODEL = HEADER_ARGUMENT_SEPARATOR_HTTP_MODEL_HTTP_MODEL_ARRAY;
static int* HEADER_ARGUMENT_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The header value separator ("semicolon" and "space") http model. */
static wchar_t HEADER_VALUE_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x003B, 0x0020};
static wchar_t* HEADER_VALUE_SEPARATOR_HTTP_MODEL = HTTP_HEADER_VALUE_SEPARATOR_HTTP_MODEL_ARRAY;
static int* HEADER_VALUE_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The header value assignment separator ("equals sign") http model. */
static wchar_t* HEADER_VALUE_ASSIGNMENT_SEPARATOR_HTTP_MODEL = EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* HEADER_VALUE_ASSIGNMENT_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The header separator ("carriage return" and "line feed") http model. */
static wchar_t HEADER_SEPARATOR_HTTP_MODEL_ARRAY[] = {0x000D, 0x000A};
static wchar_t* HEADER_SEPARATOR_HTTP_MODEL = HEADER_SEPARATOR_HTTP_MODEL_HTTP_MODEL_ARRAY;
static int* HEADER_SEPARATOR_HTTP_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* SEPARATOR_HTTP_MODEL_SOURCE */
#endif
