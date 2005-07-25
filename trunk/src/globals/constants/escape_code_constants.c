/*
 * $RCSfile: escape_code_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2005-07-25 20:27:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ESCAPE_CODE_CONSTANTS_SOURCE
#define ESCAPE_CODE_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

/** The escape code count. */
static const int* ESCAPE_CODE_CHARACTER_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The space character escape code. U+0020 */
static const char SPACE_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '2', '0'};
static const char* SPACE_CHARACTER_ESCAPE_CODE = SPACE_CHARACTER_ESCAPE_CODE_ARRAY;

/** The less than sign character escape code. U+003C */
static const char LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '3', 'C'};
static const char* LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE = LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The greater than sign character escape code. U+003E */
static const char GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '3', 'E'};
static const char* GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE = GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The number sign character escape code. U+0023 */
static const char NUMBER_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '2', '3'};
static const char* NUMBER_SIGN_CHARACTER_ESCAPE_CODE = NUMBER_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The percent sign character escape code. U+0025 */
static const char PERCENT_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '2', '5'};
static const char* PERCENT_SIGN_CHARACTER_ESCAPE_CODE = PERCENT_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The left curly bracket character escape code. U+007B */
static const char LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '7', 'B'};
static const char* LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE = LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The right curly bracket character escape code. U+007D */
static const char RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '7', 'D'};
static const char* RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE = RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The vertical line character escape code. U+007C */
static const char VERTICAL_LINE_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '7', 'C'};
static const char* VERTICAL_LINE_CHARACTER_ESCAPE_CODE = VERTICAL_LINE_CHARACTER_ESCAPE_CODE_ARRAY;

/** The reverse solidus character escape code. U+005C */
static const char REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '5', 'C'};
static const char* REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE = REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY;

/** The circumflex accent character escape code. U+005E */
static const char CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '5', 'E'};
static const char* CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE = CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY;

/** The tilde character escape code. U+007E */
static const char TILDE_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '7', 'E'};
static const char* TILDE_CHARACTER_ESCAPE_CODE = TILDE_CHARACTER_ESCAPE_CODE_ARRAY;

/** The left square bracket character escape code. U+005B */
static const char LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '5', 'B'};
static const char* LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE = LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The right square bracket character escape code. U+005D */
static const char RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '5', 'D'};
static const char* RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE = RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE_ARRAY;

/** The grave accent character escape code. U+0060 */
static const char GRAVE_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '6', '0'};
static const char* GRAVE_ACCENT_CHARACTER_ESCAPE_CODE = GRAVE_ACCENT_CHARACTER_ESCAPE_CODE_ARRAY;

/** The semicolon character escape code. U+003B */
static const char SEMICOLON_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '3', 'B'};
static const char* SEMICOLON_CHARACTER_ESCAPE_CODE = SEMICOLON_CHARACTER_ESCAPE_CODE_ARRAY;

/** The solidus character escape code. U+002F */
static const char SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '2', 'F'};
static const char* SOLIDUS_CHARACTER_ESCAPE_CODE = SOLIDUS_CHARACTER_ESCAPE_CODE_ARRAY;

/** The question mark character escape code. U+003F */
static const char QUESTION_MARK_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '3', 'F'};
static const char* QUESTION_MARK_CHARACTER_ESCAPE_CODE = QUESTION_MARK_CHARACTER_ESCAPE_CODE_ARRAY;

/** The colon character escape code. U+003A */
static const char COLON_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '3', 'A'};
static const char* COLON_CHARACTER_ESCAPE_CODE = COLON_CHARACTER_ESCAPE_CODE_ARRAY;

/** The commercial at character escape code. U+0040 */
static const char COMMERCIAL_AT_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '4', '0'};
static const char* COMMERCIAL_AT_CHARACTER_ESCAPE_CODE = COMMERCIAL_AT_CHARACTER_ESCAPE_CODE_ARRAY;

/** The equals sign character escape code. U+003D */
static const char EQUALS_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '3', 'D'};
static const char* EQUALS_SIGN_CHARACTER_ESCAPE_CODE = EQUALS_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/** The ampersand character escape code. U+0026 */
static const char AMPERSAND_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '2', '6'};
static const char* AMPERSAND_CHARACTER_ESCAPE_CODE = AMPERSAND_CHARACTER_ESCAPE_CODE_ARRAY;

/** The dollar sign character escape code. U+0024 */
static const char DOLLAR_SIGN_CHARACTER_ESCAPE_CODE_ARRAY[] = {'%', '2', '4'};
static const char* DOLLAR_SIGN_CHARACTER_ESCAPE_CODE = DOLLAR_SIGN_CHARACTER_ESCAPE_CODE_ARRAY;

/* ESCAPE_CODE_CONSTANTS_SOURCE */
#endif
