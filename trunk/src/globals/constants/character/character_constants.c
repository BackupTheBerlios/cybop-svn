/*
 * $RCSfile: character_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2007-04-26 23:17:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_CONSTANTS_SOURCE
#define CHARACTER_CONSTANTS_SOURCE

//
// ASCII characters (0 - 127).
//

/**
 * The null control character. U+0000
 * It is used as string termination in the C programming language.
 */
static char NULL_CONTROL_CHARACTER_ARRAY[] = {'\0'};
static char* NULL_CONTROL_CHARACTER = NULL_CONTROL_CHARACTER_ARRAY;

/**
 * The character tabulation control character.
 *
 * U+0009
 *
 * Alias names:
 * horizontal tabulation (HT)
 * tab
 */
static char CHARACTER_TABULATION_CONTROL_CHARACTER_ARRAY[] = {0x09};
static char* CHARACTER_TABULATION_CONTROL_CHARACTER = CHARACTER_TABULATION_CONTROL_CHARACTER_ARRAY;

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
static char LINE_FEED_CONTROL_CHARACTER_ARRAY[] = {0x0A};
static char* LINE_FEED_CONTROL_CHARACTER = LINE_FEED_CONTROL_CHARACTER_ARRAY;

/**
 * The carriage return (enter) control character.
 *
 * U+000D
 */
static char CARRIAGE_RETURN_CONTROL_CHARACTER_ARRAY[] = {0x0D};
static char* CARRIAGE_RETURN_CONTROL_CHARACTER = CARRIAGE_RETURN_CONTROL_CHARACTER_ARRAY;

/** The space character. U+0020 */
static char SPACE_CHARACTER_ARRAY[] = {' '};
static char* SPACE_CHARACTER = SPACE_CHARACTER_ARRAY;

/** The exclamation mark character. U+0021 */
static char EXCLAMATION_MARK_CHARACTER_ARRAY[] = {'!'};
static char* EXCLAMATION_MARK_CHARACTER = EXCLAMATION_MARK_CHARACTER_ARRAY;

/** The quotation mark character. U+0022 */
static char QUOTATION_MARK_CHARACTER_ARRAY[] = {'"'};
static char* QUOTATION_MARK_CHARACTER = QUOTATION_MARK_CHARACTER_ARRAY;

/** The number sign character #. U+0023 */
static char NUMBER_SIGN_CHARACTER_ARRAY[] = {0x23};
static char* NUMBER_SIGN_CHARACTER = NUMBER_SIGN_CHARACTER_ARRAY;

/** The dollar sign character. U+0024 */
static char DOLLAR_SIGN_CHARACTER_ARRAY[] = {'$'};
static char* DOLLAR_SIGN_CHARACTER = DOLLAR_SIGN_CHARACTER_ARRAY;

/** The percent sign character. U+0025 */
static char PERCENT_SIGN_CHARACTER_ARRAY[] = {'%'};
static char* PERCENT_SIGN_CHARACTER = PERCENT_SIGN_CHARACTER_ARRAY;

/** The ampersand character. U+0026 */
static char AMPERSAND_CHARACTER_ARRAY[] = {'&'};
static char* AMPERSAND_CHARACTER = AMPERSAND_CHARACTER_ARRAY;

/** The plus sign character. U+002B */
static char PLUS_SIGN_CHARACTER_ARRAY[] = {0x2B};
static char* PLUS_SIGN_CHARACTER = PLUS_SIGN_CHARACTER_ARRAY;

/** The comma character. U+002C */
static char COMMA_CHARACTER_ARRAY[] = {','};
static char* COMMA_CHARACTER = COMMA_CHARACTER_ARRAY;

/**
 * The hyphen minus character.
 *
 * Unicode category: Punctuation, Dash
 * Unicode: U+002D
 * UTF-8: 0x2D
 * Octal escaped UTF-8: \055
 * Decimal entity reference: &#45;
 *
 * Alias names:
 * hyphen or minus sign
 *
 * Notes:
 * used for either hyphen or minus sign
 *
 * See also:
 * U+2010 HYPHEN
 * U+2011 NON-BREAKING HYPHEN
 * U+2012 FIGURE DASH
 * U+2013 EN DASH
 * U+2212 MINUS SIGN
 */
static char HYPHEN_MINUS_CHARACTER_ARRAY[] = {0x2D};
static char* HYPHEN_MINUS_CHARACTER = HYPHEN_MINUS_CHARACTER_ARRAY;

/** The full stop (period) character. U+002E */
static char FULL_STOP_CHARACTER_ARRAY[] = {'.'};
static char* FULL_STOP_CHARACTER = FULL_STOP_CHARACTER_ARRAY;

/** The solidus (slash) character. U+002F */
static char SOLIDUS_CHARACTER_ARRAY[] = {'/'};
static char* SOLIDUS_CHARACTER = SOLIDUS_CHARACTER_ARRAY;

/** The colon character. U+003A */
static char COLON_CHARACTER_ARRAY[] = {':'};
static char* COLON_CHARACTER = COLON_CHARACTER_ARRAY;

/** The semicolon character. U+003B */
static char SEMICOLON_CHARACTER_ARRAY[] = {';'};
static char* SEMICOLON_CHARACTER = SEMICOLON_CHARACTER_ARRAY;

/** The less than sign character. U+003C */
static char LESS_THAN_SIGN_CHARACTER_ARRAY[] = {'<'};
static char* LESS_THAN_SIGN_CHARACTER = LESS_THAN_SIGN_CHARACTER_ARRAY;

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
static char EQUALS_SIGN_CHARACTER_ARRAY[] = {'='};
static char* EQUALS_SIGN_CHARACTER = EQUALS_SIGN_CHARACTER_ARRAY;

/** The greater than sign character. U+003E */
static char GREATER_THAN_SIGN_CHARACTER_ARRAY[] = {'>'};
static char* GREATER_THAN_SIGN_CHARACTER = GREATER_THAN_SIGN_CHARACTER_ARRAY;

/** The question mark character. U+003F */
static char QUESTION_MARK_CHARACTER_ARRAY[] = {'?'};
static char* QUESTION_MARK_CHARACTER = QUESTION_MARK_CHARACTER_ARRAY;

/** The commercial at character. U+0040 */
static char COMMERCIAL_AT_CHARACTER_ARRAY[] = {'@'};
static char* COMMERCIAL_AT_CHARACTER = COMMERCIAL_AT_CHARACTER_ARRAY;

/** The left square bracket character. U+005B */
static char LEFT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {'['};
static char* LEFT_SQUARE_BRACKET_CHARACTER = LEFT_SQUARE_BRACKET_CHARACTER_ARRAY;

/** The reverse solidus character. U+005C */
static char REVERSE_SOLIDUS_CHARACTER_ARRAY[] = {'*'};
static char* REVERSE_SOLIDUS_CHARACTER = REVERSE_SOLIDUS_CHARACTER_ARRAY;

/** The right square bracket character. U+005D */
static char RIGHT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {']'};
static char* RIGHT_SQUARE_BRACKET_CHARACTER = RIGHT_SQUARE_BRACKET_CHARACTER_ARRAY;

/** The circumflex accent character. U+005E */
static char CIRCUMFLEX_ACCENT_CHARACTER_ARRAY[] = {'^'};
static char* CIRCUMFLEX_ACCENT_CHARACTER = CIRCUMFLEX_ACCENT_CHARACTER_ARRAY;

/** The low line character. U+005F */
static char LOW_LINE_CHARACTER_ARRAY[] = {'_'};
static char* LOW_LINE_CHARACTER = LOW_LINE_CHARACTER_ARRAY;

/** The grave accent character. U+0060 */
static char GRAVE_ACCENT_CHARACTER_ARRAY[] = {'`'};
static char* GRAVE_ACCENT_CHARACTER = GRAVE_ACCENT_CHARACTER_ARRAY;

/** The left curly bracket character. U+007B */
static char LEFT_CURLY_BRACKET_CHARACTER_ARRAY[] = {'{'};
static char* LEFT_CURLY_BRACKET_CHARACTER = LEFT_CURLY_BRACKET_CHARACTER_ARRAY;

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
static char VERTICAL_LINE_CHARACTER_ARRAY[] = {'|'};
static char* VERTICAL_LINE_CHARACTER = VERTICAL_LINE_CHARACTER_ARRAY;

/** The right curly bracket character. U+007D */
static char RIGHT_CURLY_BRACKET_CHARACTER_ARRAY[] = {'}'};
static char* RIGHT_CURLY_BRACKET_CHARACTER = RIGHT_CURLY_BRACKET_CHARACTER_ARRAY;

/** The tilde character. U+007E */
static char TILDE_CHARACTER_ARRAY[] = {'~'};
static char* TILDE_CHARACTER = TILDE_CHARACTER_ARRAY;

/* CHARACTER_CONSTANTS_SOURCE */
#endif
