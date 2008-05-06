/*
 * $RCSfile: console_escape_code_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2008-05-06 22:36:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSOLE_ESCAPE_CODE_CONSTANTS_SOURCE
#define CONSOLE_ESCAPE_CODE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The escape code count. */
static int* ESCAPE_CODE_CHARACTER_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The space character escape code. U+0020 */
static wchar_t SPACE_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'0'};
static wchar_t* SPACE_CHARACTER_ESCAPE_CODE = SPACE_CHARACTER_ESCAPE_CODE_ARRAY;

/** The less than sign character escape code. U+003C */
static wchar_t LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'C'};
static wchar_t* LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE = LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The greater than sign character escape code. U+003E */
static wchar_t GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'E'};
static wchar_t* GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE = GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The number sign character escape code. U+0023 */
static wchar_t NUMBER_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'3'};
static wchar_t* NUMBER_SIGN_CHARACTER_ESCAPE_CODE = NUMBER_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The percent sign character escape code. U+0025 */
static wchar_t PERCENT_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'5'};
static wchar_t* PERCENT_SIGN_CHARACTER_ESCAPE_CODE = PERCENT_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The left curly bracket character escape code. U+007B */
static wchar_t LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'B'};
static wchar_t* LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE = LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The right curly bracket character escape code. U+007D */
static wchar_t RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'D'};
static wchar_t* RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE = RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The vertical line character escape code. U+007C */
static wchar_t VERTICAL_LINE_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'C'};
static wchar_t* VERTICAL_LINE_CHARACTER_ESCAPE_CODE = VERTICAL_LINE_CHARACTER_ESCAPE_CODE_ARRAY;

/** The reverse solidus character escape code. U+005C */
static wchar_t REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'C'};
static wchar_t* REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE = REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY;

/** The circumflex accent character escape code. U+005E */
static wchar_t CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'E'};
static wchar_t* CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE = CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY;

/** The tilde character escape code. U+007E */
static wchar_t TILDE_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'7', L'E'};
static wchar_t* TILDE_CHARACTER_ESCAPE_CODE = TILDE_CHARACTER_ESCAPE_CODE_ARRAY;

/** The left square bracket character escape code. U+005B */
static wchar_t LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'B'};
static wchar_t* LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE = LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The right square bracket character escape code. U+005D */
static wchar_t RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'5', L'D'};
static wchar_t* RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE = RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The grave accent character escape code. U+0060 */
static wchar_t GRAVE_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'6', L'0'};
static wchar_t* GRAVE_ACCENT_CHARACTER_ESCAPE_CODE = GRAVE_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY;

/** The semicolon character escape code. U+003B */
static wchar_t SEMICOLON_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'B'};
static wchar_t* SEMICOLON_CHARACTER_ESCAPE_CODE = SEMICOLON_CHARACTER_ESCAPE_CODE_ARRAY;

/** The solidus character escape code. U+002F */
static wchar_t SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'F'};
static wchar_t* SOLIDUS_CHARACTER_ESCAPE_CODE = SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY;

/** The question mark character escape code. U+003F */
static wchar_t QUESTION_MARK_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'F'};
static wchar_t* QUESTION_MARK_CHARACTER_ESCAPE_CODE = QUESTION_MARK_CHARACTER_ESCAPE_CODE_ARRAY;

/** The colon character escape code. U+003A */
static wchar_t COLON_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'A'};
static wchar_t* COLON_CHARACTER_ESCAPE_CODE = COLON_CHARACTER_ESCAPE_CODE_ARRAY;

/** The commercial at character escape code. U+0040 */
static wchar_t COMMERCIAL_AT_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'4', L'0'};
static wchar_t* COMMERCIAL_AT_CHARACTER_ESCAPE_CODE = COMMERCIAL_AT_CHARACTER_ESCAPE_CODE_ARRAY;

/** The equals sign character escape code. U+003D */
static wchar_t EQUALS_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'3', L'D'};
static wchar_t* EQUALS_SIGN_CHARACTER_ESCAPE_CODE = EQUALS_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The ampersand character escape code. U+0026 */
static wchar_t AMPERSAND_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'6'};
static wchar_t* AMPERSAND_CHARACTER_ESCAPE_CODE = AMPERSAND_CHARACTER_ESCAPE_CODE_ARRAY;

/** The dollar sign character escape code. U+0024 */
static wchar_t DOLLAR_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {L'%', L'2', L'4'};
static wchar_t* DOLLAR_SIGN_CHARACTER_ESCAPE_CODE = DOLLAR_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/* CONSOLE_ESCAPE_CODE_CONSTANTS_SOURCE */
#endif
