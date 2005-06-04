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
 * @version $Revision: 1.1 $ $Date: 2005-06-04 23:57:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ESCAPE_CODE_CONSTANTS_SOURCE
#define ESCAPE_CODE_CONSTANTS_SOURCE

/** the count for all escape code */
static const int ESCAPE_CODE_CHARACTER_COUNT_ARRAY[] = {3};
static const int* ESCAPE_CODE_CHARACTER_COUNT = ESCAPE_CODE_CHARACTER_COUNT_ARRAY;


/** The space character. U+0020 */
static const char ESCAPE_CODE_SPACE_CHARACTER_ARRAY[] = {'%', '2', '0'};
static const char* ESCAPE_CODE_SPACE_CHARACTER = ESCAPE_CODE_SPACE_CHARACTER_ARRAY;

/** The less than sign character. U+003C */
static const char ESCAPE_CODE_LESS_THAN_SIGN_CHARACTER_ARRAY[] = {'%', '3', 'C'};
static const char* ESCAPE_CODE_LESS_THAN_SIGN_CHARACTER = ESCAPE_CODE_LESS_THAN_SIGN_CHARACTER_ARRAY;

/** The greater than sign character. U+003E */
static const char ESCAPE_CODE_GREATER_THAN_SIGN_CHARACTER_ARRAY[] = {'%', '3', 'E'};
static const char* ESCAPE_CODE_GREATER_THAN_SIGN_CHARACTER = ESCAPE_CODE_GREATER_THAN_SIGN_CHARACTER_ARRAY;

/** The number sign character. U+0023 */
static const char ESCAPE_CODE_NUMBER_SIGN_CHARACTER_ARRAY[] = {'%', '2', '3'};
static const char* ESCAPE_CODE_NUMBER_SIGN_CHARACTER = ESCAPE_CODE_NUMBER_SIGN_CHARACTER_ARRAY;

/** The percent sign character. U+0025 */
static const char ESCAPE_CODE_PERCENT_SIGN_CHARACTER_ARRAY[] = {'%', '2', '5'};
static const char* ESCAPE_CODE_PERCENT_SIGN_CHARACTER = ESCAPE_CODE_PERCENT_SIGN_CHARACTER_ARRAY;

/** The left curly bracket character. U+007B */
static const char ESCAPE_CODE_LEFT_CURLY_BRACKET_CHARACTER_ARRAY[] = {'%', '7', 'B'};
static const char* ESCAPE_CODE_LEFT_CURLY_BRACKET_CHARACTER = ESCAPE_CODE_LEFT_CURLY_BRACKET_CHARACTER_ARRAY;

/** The right curly bracket character. U+007D */
static const char ESCAPE_CODE_RIGHT_CURLY_BRACKET_CHARACTER_ARRAY[] = {'%', '7', 'D'};
static const char* ESCAPE_CODE_RIGHT_CURLY_BRACKET_CHARACTER = ESCAPE_CODE_RIGHT_CURLY_BRACKET_CHARACTER_ARRAY;

/** The vertical line character. U+007C */
static const char ESCAPE_CODE_VERTICAL_LINE_CHARACTER_ARRAY[] = {'%', '7', 'C'};
static const char* ESCAPE_CODE_VERTICAL_LINE_CHARACTER = ESCAPE_CODE_VERTICAL_LINE_CHARACTER_ARRAY;

/** The reverse solidus character. U+005C */
static const char ESCAPE_CODE_REVERSE_SOLIDUS_CHARACTER_ARRAY[] = {'%', '5', 'C'};
static const char* ESCAPE_CODE_REVERSE_SOLIDUS_CHARACTER = ESCAPE_CODE_REVERSE_SOLIDUS_CHARACTER_ARRAY;

/** The circumflex accent character. U+005E */
static const char ESCAPE_CODE_CIRCUMFLEX_ACCENT_CHARACTER_ARRAY[] = {'%', '5', 'E'};
static const char* ESCAPE_CODE_CIRCUMFLEX_ACCENT_CHARACTER = ESCAPE_CODE_CIRCUMFLEX_ACCENT_CHARACTER_ARRAY;

/** The tilde character. U+007E */
static const char ESCAPE_CODE_TILDE_CHARACTER_ARRAY[] = {'%', '7', 'E'};
static const char* ESCAPE_CODE_TILDE_CHARACTER = ESCAPE_CODE_TILDE_CHARACTER_ARRAY;

/** The left square bracket character. U+005B */
static const char ESCAPE_CODE_LEFT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {'%', '5', 'B'};
static const char* ESCAPE_CODE_LEFT_SQUARE_BRACKET_CHARACTER = ESCAPE_CODE_LEFT_SQUARE_BRACKET_CHARACTER_ARRAY;

/** The right square bracket character. U+005D */
static const char ESCAPE_CODE_RIGHT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {'%', '5', 'D'};
static const char* ESCAPE_CODE_RIGHT_SQUARE_BRACKET_CHARACTER = ESCAPE_CODE_RIGHT_SQUARE_BRACKET_CHARACTER_ARRAY;

/** The grave accent character. U+0060 */
static const char ESCAPE_CODE_GRAVE_ACCENT_CHARACTER_ARRAY[] = {'%', '6', '0'};
static const char* ESCAPE_CODE_GRAVE_ACCENT_CHARACTER = ESCAPE_CODE_GRAVE_ACCENT_CHARACTER_ARRAY;

/** The semicolon character. U+003B */
static const char ESCAPE_CODE_SEMICOLON_CHARACTER_ARRAY[] = {'%', '3', 'B'};
static const char* ESCAPE_CODE_SEMICOLON_CHARACTER = ESCAPE_CODE_SEMICOLON_CHARACTER_ARRAY;

/** The solidus character. U+002F */
static const char ESCAPE_CODE_SOLIDUS_CHARACTER_ARRAY[] = {'%', '2', 'F'};
static const char* ESCAPE_CODE_SOLIDUS_CHARACTER = ESCAPE_CODE_SOLIDUS_CHARACTER_ARRAY;

/** The question mark character. U+003F */
static const char ESCAPE_CODE_QUESTION_MARK_CHARACTER_ARRAY[] = {'%', '3', 'F'};
static const char* ESCAPE_CODE_QUESTION_MARK_CHARACTER = ESCAPE_CODE_QUESTION_MARK_CHARACTER_ARRAY;

/** The colon character. U+003A */
static const char ESCAPE_CODE_COLON_CHARACTER_ARRAY[] = {'%', '3', 'A'};
static const char* ESCAPE_CODE_COLON_CHARACTER = ESCAPE_CODE_COLON_CHARACTER_ARRAY;

/** The commercial at character. U+0040 */
static const char ESCAPE_CODE_COMMERCIAL_AT_CHARACTER_ARRAY[] = {'%', '4', '0'};
static const char* ESCAPE_CODE_COMMERCIAL_AT_CHARACTER = ESCAPE_CODE_COMMERCIAL_AT_CHARACTER_ARRAY;

/** The equals sign character. U+003D */
static const char ESCAPE_CODE_EQUALS_SIGN_CHARACTER_ARRAY[] = {'%', '3', 'D'};
static const char* ESCAPE_CODE_EQUALS_SIGN_CHARACTER = ESCAPE_CODE_EQUALS_SIGN_CHARACTER_ARRAY;

/** The ampersand character. U+0026 */
static const char ESCAPE_CODE_AMPERSAND_CHARACTER_ARRAY[] = {'%', '2', '6'};
static const char* ESCAPE_CODE_AMPERSAND_CHARACTER = ESCAPE_CODE_AMPERSAND_CHARACTER_ARRAY;

/** The dollar sign character. U+0024 */
static const char ESCAPE_CODE_DOLLAR_SIGN_CHARACTER_ARRAY[] = {'%', '2', '4'};
static const char* ESCAPE_CODE_DOLLAR_SIGN_CHARACTER = ESCAPE_CODE_DOLLAR_SIGN_CHARACTER_ARRAY;


/* ESCAPE_CODE_CONSTANTS_SOURCE */
#endif
