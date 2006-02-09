/*
 * $RCSfile: ascii_character_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2006-02-09 23:13:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ASCII_CHARACTER_CONSTANTS_SOURCE
#define ASCII_CHARACTER_CONSTANTS_SOURCE

//
// ASCII characters (0 - 127).
//

/**
 * The null control character. U+0000
 * It is used as string termination in the C programming language.
 */
static char NULL_CONTROL_ASCII_CHARACTER_ARRAY[] = {'\0'};
static char* NULL_CONTROL_ASCII_CHARACTER = NULL_CONTROL_ASCII_CHARACTER_ARRAY;

/**
 * The line feed control character.
 *
 * U+000A
 *
 * Alias names:
 * LINE FEED (LF)
 * NEW LINE (NL)
 * END OF LINE (EOL)
 */
static char LINE_FEED_CONTROL_ASCII_CHARACTER_ARRAY[] = {0x0A};
static char* LINE_FEED_CONTROL_ASCII_CHARACTER = LINE_FEED_CONTROL_ASCII_CHARACTER_ARRAY;

/** The space character. U+0020 */
static char SPACE_ASCII_CHARACTER_ARRAY[] = {' '};
static char* SPACE_ASCII_CHARACTER = SPACE_ASCII_CHARACTER_ARRAY;

/** The exclamation mark character. U+0021 */
static char EXCLAMATION_MARK_ASCII_CHARACTER_ARRAY[] = {'!'};
static char* EXCLAMATION_MARK_ASCII_CHARACTER = EXCLAMATION_MARK_ASCII_CHARACTER_ARRAY;

/** The quotation mark character. U+0022 */
static char QUOTATION_MARK_ASCII_CHARACTER_ARRAY[] = {' '};
static char* QUOTATION_MARK_ASCII_CHARACTER = QUOTATION_MARK_ASCII_CHARACTER_ARRAY;

/** The number sign character. U+0023 */
static char NUMBER_SIGN_ASCII_CHARACTER_ARRAY[] = {'#'};
static char* NUMBER_SIGN_ASCII_CHARACTER = NUMBER_SIGN_ASCII_CHARACTER_ARRAY;

/** The dollar sign character. U+0024 */
static char DOLLAR_SIGN_ASCII_CHARACTER_ARRAY[] = {'$'};
static char* DOLLAR_SIGN_ASCII_CHARACTER = DOLLAR_SIGN_ASCII_CHARACTER_ARRAY;

/** The percent sign character. U+0025 */
static char PERCENT_SIGN_ASCII_CHARACTER_ARRAY[] = {'%'};
static char* PERCENT_SIGN_ASCII_CHARACTER = PERCENT_SIGN_ASCII_CHARACTER_ARRAY;

/** The ampersand character. U+0026 */
static char AMPERSAND_ASCII_CHARACTER_ARRAY[] = {'&'};
static char* AMPERSAND_ASCII_CHARACTER = AMPERSAND_ASCII_CHARACTER_ARRAY;

/** The comma character. U+002C */
static char COMMA_ASCII_CHARACTER_ARRAY[] = {','};
static char* COMMA_ASCII_CHARACTER = COMMA_ASCII_CHARACTER_ARRAY;

/** The full stop character. U+002E */
static char FULL_STOP_ASCII_CHARACTER_ARRAY[] = {'.'};
static char* FULL_STOP_ASCII_CHARACTER = FULL_STOP_ASCII_CHARACTER_ARRAY;

/** The solidus character. U+002F */
static char SOLIDUS_ASCII_CHARACTER_ARRAY[] = {'*'};
static char* SOLIDUS_ASCII_CHARACTER = SOLIDUS_ASCII_CHARACTER_ARRAY;

/** The colon character. U+003A */
static char COLON_ASCII_CHARACTER_ARRAY[] = {':'};
static char* COLON_ASCII_CHARACTER = COLON_ASCII_CHARACTER_ARRAY;

/** The semicolon character. U+003B */
static char SEMICOLON_ASCII_CHARACTER_ARRAY[] = {';'};
static char* SEMICOLON_ASCII_CHARACTER = SEMICOLON_ASCII_CHARACTER_ARRAY;

/** The less than sign character. U+003C */
static char LESS_THAN_SIGN_ASCII_CHARACTER_ARRAY[] = {'<'};
static char* LESS_THAN_SIGN_ASCII_CHARACTER = LESS_THAN_SIGN_ASCII_CHARACTER_ARRAY;

/**
 * The equals sign character.
 *
 * Unicode category: Symbol, Math
 * Unicode: U+003D
 * UTF-8: 0x3D
 * Octal escaped UTF-8: \075
 * Decimal entity reference: &#61;
 *
 * Notes:
 * other related characters: U+2241 NOT TILDE-U+2263 STRICTLY EQUIVALENT TO
 *
 * See also:
 * U+2260 NOT EQUAL TO
 * U+2261 IDENTICAL TO
 */
static char EQUALS_SIGN_ASCII_CHARACTER_ARRAY[] = {'='};
static char* EQUALS_SIGN_ASCII_CHARACTER = EQUALS_SIGN_ASCII_CHARACTER_ARRAY;

/** The greater than sign character. U+003E */
static char GREATER_THAN_SIGN_ASCII_CHARACTER_ARRAY[] = {'>'};
static char* GREATER_THAN_SIGN_ASCII_CHARACTER = GREATER_THAN_SIGN_ASCII_CHARACTER_ARRAY;

/** The question mark character. U+003F */
static char QUESTION_MARK_ASCII_CHARACTER_ARRAY[] = {'?'};
static char* QUESTION_MARK_ASCII_CHARACTER = QUESTION_MARK_ASCII_CHARACTER_ARRAY;

/** The commercial at character. U+0040 */
static char COMMERCIAL_AT_ASCII_CHARACTER_ARRAY[] = {'@'};
static char* COMMERCIAL_AT_ASCII_CHARACTER = COMMERCIAL_AT_ASCII_CHARACTER_ARRAY;

/** The left square bracket character. U+005B */
static char LEFT_SQUARE_BRACKET_ASCII_CHARACTER_ARRAY[] = {'['};
static char* LEFT_SQUARE_BRACKET_ASCII_CHARACTER = LEFT_SQUARE_BRACKET_ASCII_CHARACTER_ARRAY;

/** The reverse solidus character. U+005C */
static char REVERSE_SOLIDUS_ASCII_CHARACTER_ARRAY[] = {'*'};
static char* REVERSE_SOLIDUS_ASCII_CHARACTER = REVERSE_SOLIDUS_ASCII_CHARACTER_ARRAY;

/** The right square bracket character. U+005D */
static char RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_ARRAY[] = {']'};
static char* RIGHT_SQUARE_BRACKET_ASCII_CHARACTER = RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_ARRAY;

/** The circumflex accent character. U+005E */
static char CIRCUMFLEX_ACCENT_ASCII_CHARACTER_ARRAY[] = {' '};
static char* CIRCUMFLEX_ACCENT_ASCII_CHARACTER = CIRCUMFLEX_ACCENT_ASCII_CHARACTER_ARRAY;

/** The low line character. U+005F */
static char LOW_LINE_ASCII_CHARACTER_ARRAY[] = {'_'};
static char* LOW_LINE_ASCII_CHARACTER = LOW_LINE_ASCII_CHARACTER_ARRAY;

/** The grave accent character. U+0060 */
static char GRAVE_ACCENT_ASCII_CHARACTER_ARRAY[] = {' '};
static char* GRAVE_ACCENT_ASCII_CHARACTER = GRAVE_ACCENT_ASCII_CHARACTER_ARRAY;

/** The left curly bracket character. U+007B */
static char LEFT_CURLY_BRACKET_ASCII_CHARACTER_ARRAY[] = {'{'};
static char* LEFT_CURLY_BRACKET_ASCII_CHARACTER = LEFT_CURLY_BRACKET_ASCII_CHARACTER_ARRAY;

/**
 * The vertical line character.
 *
 * Unicode category: Symbol, Math
 * Unicode: U+007C
 * UTF-8: 0x7C
 * Octal escaped UTF-8: \174
 * Decimal entity reference: &#124;
 *
 * Alias names:
 * VERTICAL BAR
 *
 * Notes:
 * used in pairs to indicate absolute value
 *
 * See also:
 * U+01C0 LATIN LETTER DENTAL CLICK
 * U+05C0 HEBREW PUNCTUATION PASEQ
 * U+2223 DIVIDES
 * U+2758 LIGHT VERTICAL BAR
 */
static char VERTICAL_LINE_ASCII_CHARACTER_ARRAY[] = {'|'};
static char* VERTICAL_LINE_ASCII_CHARACTER = VERTICAL_LINE_ASCII_CHARACTER_ARRAY;

/** The right curly bracket character. U+007D */
static char RIGHT_CURLY_BRACKET_ASCII_CHARACTER_ARRAY[] = {'}'};
static char* RIGHT_CURLY_BRACKET_ASCII_CHARACTER = RIGHT_CURLY_BRACKET_ASCII_CHARACTER_ARRAY;

/** The tilde character. U+007E */
static char TILDE_ASCII_CHARACTER_ARRAY[] = {'~'};
static char* TILDE_ASCII_CHARACTER = TILDE_ASCII_CHARACTER_ARRAY;

/* ASCII_CHARACTER_CONSTANTS_SOURCE */
#endif
