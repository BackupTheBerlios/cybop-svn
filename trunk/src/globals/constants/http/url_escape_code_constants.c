/*
 * $RCSfile: url_escape_code_constants.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URL_ESCAPE_CODE_CONSTANTS_SOURCE
#define URL_ESCAPE_CODE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The space   url escape code. */
static wchar_t SPACE_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'0'};
static wchar_t* SPACE_URL_ESCAPE_CODE = SPACE_URL_ESCAPE_CODE_ARRAY;
static int* SPACE_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The number sign # url escape code. */
static wchar_t NUMBER_SIGN_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'3'};
static wchar_t* NUMBER_SIGN_URL_ESCAPE_CODE = NUMBER_SIGN_URL_ESCAPE_CODE_ARRAY;
static int* NUMBER_SIGN_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The dollar sign $ url escape code. */
static wchar_t DOLLAR_SIGN_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'4'};
static wchar_t* DOLLAR_SIGN_URL_ESCAPE_CODE = DOLLAR_SIGN_URL_ESCAPE_CODE_ARRAY;
static int* DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The percent sign % url escape code. */
static wchar_t PERCENT_SIGN_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'5'};
static wchar_t* PERCENT_SIGN_URL_ESCAPE_CODE = PERCENT_SIGN_URL_ESCAPE_CODE_ARRAY;
static int* PERCENT_SIGN_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The ampersand & url escape code. */
static wchar_t AMPERSAND_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'6'};
static wchar_t* AMPERSAND_URL_ESCAPE_CODE = AMPERSAND_URL_ESCAPE_CODE_ARRAY;
static int* AMPERSAND_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The solidus (slash) / url escape code. */
static wchar_t SOLIDUS_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'F'};
static wchar_t* SOLIDUS_URL_ESCAPE_CODE = SOLIDUS_URL_ESCAPE_CODE_ARRAY;
static int* SOLIDUS_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The colon : url escape code. */
static wchar_t COLON_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'A'};
static wchar_t* COLON_URL_ESCAPE_CODE = COLON_URL_ESCAPE_CODE_ARRAY;
static int* COLON_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The semicolon ; url escape code. */
static wchar_t SEMICOLON_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'B'};
static wchar_t* SEMICOLON_URL_ESCAPE_CODE = SEMICOLON_URL_ESCAPE_CODE_ARRAY;
static int* SEMICOLON_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The less than sign < url escape code. */
static wchar_t LESS_THAN_SIGN_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'C'};
static wchar_t* LESS_THAN_SIGN_URL_ESCAPE_CODE = LESS_THAN_SIGN_URL_ESCAPE_CODE_ARRAY;
static int* LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The equals sign = url escape code. */
static wchar_t EQUALS_SIGN_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'D'};
static wchar_t* EQUALS_SIGN_URL_ESCAPE_CODE = EQUALS_SIGN_URL_ESCAPE_CODE_ARRAY;
static int* EQUALS_SIGN_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The greater than sign > url escape code. */
static wchar_t GREATER_THAN_SIGN_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'E'};
static wchar_t* GREATER_THAN_SIGN_URL_ESCAPE_CODE = GREATER_THAN_SIGN_URL_ESCAPE_CODE_ARRAY;
static int* GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The question mark ? url escape code. */
static wchar_t QUESTION_MARK_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'F'};
static wchar_t* QUESTION_MARK_URL_ESCAPE_CODE = QUESTION_MARK_URL_ESCAPE_CODE_ARRAY;
static int* QUESTION_MARK_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The commercial at @ url escape code. */
static wchar_t COMMERCIAL_AT_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'4', L'0'};
static wchar_t* COMMERCIAL_AT_URL_ESCAPE_CODE = COMMERCIAL_AT_URL_ESCAPE_CODE_ARRAY;
static int* COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The left square bracket [ url escape code. */
static wchar_t LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'B'};
static wchar_t* LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE = LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_ARRAY;
static int* LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The reverse solidus (backslash) \ url escape code. */
static wchar_t REVERSE_SOLIDUS_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'C'};
static wchar_t* REVERSE_SOLIDUS_URL_ESCAPE_CODE = REVERSE_SOLIDUS_URL_ESCAPE_CODE_ARRAY;
static int* REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The right square bracket ] url escape code. */
static wchar_t RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'D'};
static wchar_t* RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE = RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_ARRAY;
static int* RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The caret ^ url escape code. */
static wchar_t CARET_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'E'};
static wchar_t* CARET_URL_ESCAPE_CODE = CARET_URL_ESCAPE_CODE_ARRAY;
static int* CARET_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The grave accent ` url escape code. */
static wchar_t GRAVE_ACCENT_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'6', L'0'};
static wchar_t* GRAVE_ACCENT_URL_ESCAPE_CODE = GRAVE_ACCENT_URL_ESCAPE_CODE_ARRAY;
static int* GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The left curly brace { url escape code. */
static wchar_t LEFT_CURLY_BRACE_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'B'};
static wchar_t* LEFT_CURLY_BRACE_URL_ESCAPE_CODE = LEFT_CURLY_BRACE_URL_ESCAPE_CODE_ARRAY;
static int* LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The vertical bar | url escape code. */
static wchar_t VERTICAL_BAR_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'C'};
static wchar_t* VERTICAL_BAR_URL_ESCAPE_CODE = VERTICAL_BAR_URL_ESCAPE_CODE_ARRAY;
static int* VERTICAL_BAR_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The right curly brace } url escape code. */
static wchar_t RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'D'};
static wchar_t* RIGHT_CURLY_BRACE_URL_ESCAPE_CODE = RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_ARRAY;
static int* RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The tilde ~ url escape code. */
static wchar_t TILDE_URL_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'E'};
static wchar_t* TILDE_URL_ESCAPE_CODE = TILDE_URL_ESCAPE_CODE_ARRAY;
static int* TILDE_URL_ESCAPE_CODE_COUNT = NUMBER_3_INTEGER_ARRAY;

/* URL_ESCAPE_CODE_CONSTANTS_SOURCE */
#endif
