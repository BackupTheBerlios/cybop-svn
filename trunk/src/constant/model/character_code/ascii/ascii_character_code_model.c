/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: ascii_character_code_model.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ASCII_CHARACTER_CODE_MODEL_SOURCE
#define ASCII_CHARACTER_CODE_MODEL_SOURCE

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains character code constants.
//
// ASCII character codes (0 - 127).
//

/**
 * The null control ascii character code model. U+0000
 * It is used as string termination in the C programming language.
 */
static char NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x00};
static char* NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL = NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The character tabulation control ascii character code model.
 *
 * U+0009
 *
 * Alias names:
 * horizontal tabulation (HT)
 * tab
 */
static char CHARACTER_TABULATION_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x09};
static char* CHARACTER_TABULATION_CONTROL_ASCII_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The line feed control ascii character code model.
 *
 * U+000A
 *
 * Alias names:
 * LINE FEED (LF)
 * NEW LINE (NL)
 * END OF LINE (EOL)
 */
static char LINE_FEED_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x0A};
static char* LINE_FEED_CONTROL_ASCII_CHARACTER_CODE_MODEL = LINE_FEED_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The carriage return (enter) control ascii character code model.
 *
 * U+000D
 */
static char CARRIAGE_RETURN_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x0D};
static char* CARRIAGE_RETURN_CONTROL_ASCII_CHARACTER_CODE_MODEL = CARRIAGE_RETURN_CONTROL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The space ascii character code model  . U+0020 */
static char SPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x20};
static char* SPACE_ASCII_CHARACTER_CODE_MODEL = SPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The exclamation mark ascii character code model !. U+0021 */
static char EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x20};
static char* EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL = EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The quotation mark ascii character code model ?. U+0022 */
static char QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x22};
static char* QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL = QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The number sign ascii character code model #. U+0023 */
static char NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x23};
static char* NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL = NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The dollar sign ascii character code model $. U+0024 */
static char DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x24};
static char* DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL = DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The percent sign ascii character code model %. U+0025 */
static char PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x25};
static char* PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL = PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The ampersand ascii character code model &. U+0026 */
static char AMPERSAND_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x26};
static char* AMPERSAND_ASCII_CHARACTER_CODE_MODEL = AMPERSAND_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The plus sign ascii character code model +. U+002B */
static char PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x2B};
static char* PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL = PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The comma ascii character code model ,. U+002C */
static char COMMA_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x2C};
static char* COMMA_ASCII_CHARACTER_CODE_MODEL = COMMA_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The hyphen minus ascii character code model.
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
static char HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x2D};
static char* HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL = HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The full stop (period) ascii character code model .. U+002E */
static char FULL_STOP_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x2E};
static char* FULL_STOP_ASCII_CHARACTER_CODE_MODEL = FULL_STOP_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The solidus (slash) ascii character code model /. U+002F */
static char SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x2F};
static char* SOLIDUS_ASCII_CHARACTER_CODE_MODEL = SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The colon ascii character code model :. U+003A */
static char COLON_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x3A};
static char* COLON_ASCII_CHARACTER_CODE_MODEL = COLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The semicolon ascii character code model ;. U+003B */
static char SEMICOLON_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x3B};
static char* SEMICOLON_ASCII_CHARACTER_CODE_MODEL = SEMICOLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The less than sign ascii character code model <. U+003C */
static char LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x3C};
static char* LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL = LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The equals sign ascii character code model.
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
static char EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x3D};
static char* EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL = EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The greater than sign ascii character code model >. U+003E */
static char GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x3E};
static char* GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL = GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The question mark ascii character code model ?. U+003F */
static char QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x3F};
static char* QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL = QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The commercial at ascii character code model @. U+0040 */
static char COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x40};
static char* COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL = COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left square bracket ascii character code model [. U+005B */
static char LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x5B};
static char* LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL = LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse solidus ascii character code model \. U+005C */
static char REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x5C};
static char* REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL = REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right square bracket ascii character code model ]. U+005D */
static char RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x5D};
static char* RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL = RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The circumflex accent ascii character code model ^. U+005E */
static char CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x5E};
static char* CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL = CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The low line ascii character code model _. U+005F */
static char LOW_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x5F};
static char* LOW_LINE_ASCII_CHARACTER_CODE_MODEL = LOW_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The grave accent ascii character code model `. U+0060 */
static char GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x60};
static char* GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL = GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left curly bracket ascii character code model {. U+007B */
static char LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x7B};
static char* LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL = LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The vertical line ascii character code model.
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
static char VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x7C};
static char* VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL = VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right curly bracket ascii character code model }. U+007D */
static char RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x7D};
static char* RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL = RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The tilde ascii character code model ~. U+007E */
static char TILDE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = {0x7E};
static char* TILDE_ASCII_CHARACTER_CODE_MODEL = TILDE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/* ASCII_CHARACTER_CODE_MODEL_SOURCE */
#endif
