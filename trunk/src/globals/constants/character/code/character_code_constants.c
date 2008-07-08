/*
 * $RCSfile: character_code_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2008-07-08 17:55:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_CODE_CONSTANTS_SOURCE
#define CHARACTER_CODE_CONSTANTS_SOURCE

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains character code constants.
//

//
// ASCII character codes (0 - 127).
//

/**
 * The null control character code. U+0000
 * It is used as string termination in the C programming language.
 */
static char NULL_CONTROL_CHARACTER_CODE_ARRAY[] = {0x00};
static char* NULL_CONTROL_CHARACTER_CODE = NULL_CONTROL_CHARACTER_CODE_ARRAY;

/**
 * The character tabulation control character code.
 *
 * U+0009
 *
 * Alias names:
 * horizontal tabulation (HT)
 * tab
 */
static char CHARACTER_TABULATION_CONTROL_CHARACTER_CODE_ARRAY[] = {0x09};
static char* CHARACTER_TABULATION_CONTROL_CHARACTER_CODE = CHARACTER_TABULATION_CONTROL_CHARACTER_CODE_ARRAY;

/**
 * The line feed control character code.
 *
 * U+000A
 *
 * Alias names:
 * LINE FEED (LF)
 * NEW LINE (NL)
 * END OF LINE (EOL)
 */
static char LINE_FEED_CONTROL_CHARACTER_CODE_ARRAY[] = {0x0A};
static char* LINE_FEED_CONTROL_CHARACTER_CODE = LINE_FEED_CONTROL_CHARACTER_CODE_ARRAY;

/**
 * The carriage return (enter) control character code.
 *
 * U+000D
 */
static char CARRIAGE_RETURN_CONTROL_CHARACTER_CODE_ARRAY[] = {0x0D};
static char* CARRIAGE_RETURN_CONTROL_CHARACTER_CODE = CARRIAGE_RETURN_CONTROL_CHARACTER_CODE_ARRAY;

/** The space character code  . U+0020 */
static char SPACE_CHARACTER_CODE_ARRAY[] = {0x20};
static char* SPACE_CHARACTER_CODE = SPACE_CHARACTER_CODE_ARRAY;

/** The exclamation mark character code !. U+0021 */
static char EXCLAMATION_MARK_CHARACTER_CODE_ARRAY[] = {0x20};
static char* EXCLAMATION_MARK_CHARACTER_CODE = EXCLAMATION_MARK_CHARACTER_CODE_ARRAY;

/** The quotation mark character code ?. U+0022 */
static char QUOTATION_MARK_CHARACTER_CODE_ARRAY[] = {0x22};
static char* QUOTATION_MARK_CHARACTER_CODE = QUOTATION_MARK_CHARACTER_CODE_ARRAY;

/** The number sign character code #. U+0023 */
static char NUMBER_SIGN_CHARACTER_CODE_ARRAY[] = {0x23};
static char* NUMBER_SIGN_CHARACTER_CODE = NUMBER_SIGN_CHARACTER_CODE_ARRAY;

/** The dollar sign character code $. U+0024 */
static char DOLLAR_SIGN_CHARACTER_CODE_ARRAY[] = {0x24};
static char* DOLLAR_SIGN_CHARACTER_CODE = DOLLAR_SIGN_CHARACTER_CODE_ARRAY;

/** The percent sign character code %. U+0025 */
static char PERCENT_SIGN_CHARACTER_CODE_ARRAY[] = {0x25};
static char* PERCENT_SIGN_CHARACTER_CODE = PERCENT_SIGN_CHARACTER_CODE_ARRAY;

/** The ampersand character code &. U+0026 */
static char AMPERSAND_CHARACTER_CODE_ARRAY[] = {0x26};
static char* AMPERSAND_CHARACTER_CODE = AMPERSAND_CHARACTER_CODE_ARRAY;

/** The plus sign character code +. U+002B */
static char PLUS_SIGN_CHARACTER_CODE_ARRAY[] = {0x2B};
static char* PLUS_SIGN_CHARACTER_CODE = PLUS_SIGN_CHARACTER_CODE_ARRAY;

/** The comma character code ,. U+002C */
static char COMMA_CHARACTER_CODE_ARRAY[] = {0x2C};
static char* COMMA_CHARACTER_CODE = COMMA_CHARACTER_CODE_ARRAY;

/**
 * The hyphen minus character code.
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
static char HYPHEN_MINUS_CHARACTER_CODE_ARRAY[] = {0x2D};
static char* HYPHEN_MINUS_CHARACTER_CODE = HYPHEN_MINUS_CHARACTER_CODE_ARRAY;

/** The full stop (period) character code .. U+002E */
static char FULL_STOP_CHARACTER_CODE_ARRAY[] = {0x2E};
static char* FULL_STOP_CHARACTER_CODE = FULL_STOP_CHARACTER_CODE_ARRAY;

/** The solidus (slash) character code /. U+002F */
static char SOLIDUS_CHARACTER_CODE_ARRAY[] = {0x2F};
static char* SOLIDUS_CHARACTER_CODE = SOLIDUS_CHARACTER_CODE_ARRAY;

/** The colon character code :. U+003A */
static char COLON_CHARACTER_CODE_ARRAY[] = {0x3A};
static char* COLON_CHARACTER_CODE = COLON_CHARACTER_CODE_ARRAY;

/** The semicolon character code ;. U+003B */
static char SEMICOLON_CHARACTER_CODE_ARRAY[] = {0x3B};
static char* SEMICOLON_CHARACTER_CODE = SEMICOLON_CHARACTER_CODE_ARRAY;

/** The less than sign character code <. U+003C */
static char LESS_THAN_SIGN_CHARACTER_CODE_ARRAY[] = {0x3C};
static char* LESS_THAN_SIGN_CHARACTER_CODE = LESS_THAN_SIGN_CHARACTER_CODE_ARRAY;

/**
 * The equals sign character code.
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
static char EQUALS_SIGN_CHARACTER_CODE_ARRAY[] = {0x3D};
static char* EQUALS_SIGN_CHARACTER_CODE = EQUALS_SIGN_CHARACTER_CODE_ARRAY;

/** The greater than sign character code >. U+003E */
static char GREATER_THAN_SIGN_CHARACTER_CODE_ARRAY[] = {0x3E};
static char* GREATER_THAN_SIGN_CHARACTER_CODE = GREATER_THAN_SIGN_CHARACTER_CODE_ARRAY;

/** The question mark character code ?. U+003F */
static char QUESTION_MARK_CHARACTER_CODE_ARRAY[] = {0x3F};
static char* QUESTION_MARK_CHARACTER_CODE = QUESTION_MARK_CHARACTER_CODE_ARRAY;

/** The commercial at character code @. U+0040 */
static char COMMERCIAL_AT_CHARACTER_CODE_ARRAY[] = {0x40};
static char* COMMERCIAL_AT_CHARACTER_CODE = COMMERCIAL_AT_CHARACTER_CODE_ARRAY;

/** The left square bracket character code [. U+005B */
static char LEFT_SQUARE_BRACKET_CHARACTER_CODE_ARRAY[] = {0x5B};
static char* LEFT_SQUARE_BRACKET_CHARACTER_CODE = LEFT_SQUARE_BRACKET_CHARACTER_CODE_ARRAY;

/** The reverse solidus character code \. U+005C */
static char REVERSE_SOLIDUS_CHARACTER_CODE_ARRAY[] = {0x5C};
static char* REVERSE_SOLIDUS_CHARACTER_CODE = REVERSE_SOLIDUS_CHARACTER_CODE_ARRAY;

/** The right square bracket character code ]. U+005D */
static char RIGHT_SQUARE_BRACKET_CHARACTER_CODE_ARRAY[] = {0x5D};
static char* RIGHT_SQUARE_BRACKET_CHARACTER_CODE = RIGHT_SQUARE_BRACKET_CHARACTER_CODE_ARRAY;

/** The circumflex accent character code ^. U+005E */
static char CIRCUMFLEX_ACCENT_CHARACTER_CODE_ARRAY[] = {0x5E};
static char* CIRCUMFLEX_ACCENT_CHARACTER_CODE = CIRCUMFLEX_ACCENT_CHARACTER_CODE_ARRAY;

/** The low line character code _. U+005F */
static char LOW_LINE_CHARACTER_CODE_ARRAY[] = {0x5F};
static char* LOW_LINE_CHARACTER_CODE = LOW_LINE_CHARACTER_CODE_ARRAY;

/** The grave accent character code `. U+0060 */
static char GRAVE_ACCENT_CHARACTER_CODE_ARRAY[] = {0x60};
static char* GRAVE_ACCENT_CHARACTER_CODE = GRAVE_ACCENT_CHARACTER_CODE_ARRAY;

/** The left curly bracket character code {. U+007B */
static char LEFT_CURLY_BRACKET_CHARACTER_CODE_ARRAY[] = {0x7B};
static char* LEFT_CURLY_BRACKET_CHARACTER_CODE = LEFT_CURLY_BRACKET_CHARACTER_CODE_ARRAY;

/**
 * The vertical line character code.
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
static char VERTICAL_LINE_CHARACTER_CODE_ARRAY[] = {0x7C};
static char* VERTICAL_LINE_CHARACTER_CODE = VERTICAL_LINE_CHARACTER_CODE_ARRAY;

/** The right curly bracket character code }. U+007D */
static char RIGHT_CURLY_BRACKET_CHARACTER_CODE_ARRAY[] = {0x7D};
static char* RIGHT_CURLY_BRACKET_CHARACTER_CODE = RIGHT_CURLY_BRACKET_CHARACTER_CODE_ARRAY;

/** The tilde character code ~. U+007E */
static char TILDE_CHARACTER_CODE_ARRAY[] = {0x7E};
static char* TILDE_CHARACTER_CODE = TILDE_CHARACTER_CODE_ARRAY;

/* CHARACTER_CODE_CONSTANTS_SOURCE */
#endif
