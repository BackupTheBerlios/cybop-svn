/*
 * $RCSfile: wide_character_code_constants.c,v $
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

#ifndef WIDE_CHARACTER_CODE_CONSTANTS_SOURCE
#define WIDE_CHARACTER_CODE_CONSTANTS_SOURCE

#include <stddef.h>

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains wide character code constants.
//

//
// ASCII character codes (0 - 127).
//

/**
 * The null control character code. U+0000
 * It is used as string termination in the C programming language.
 */
static wchar_t NULL_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0000};
static wchar_t* NULL_CONTROL_WIDE_CHARACTER_CODE = NULL_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The start of heading control character code. U+0001 */
static wchar_t START_OF_HEADING_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0001};
static wchar_t* START_OF_HEADING_CONTROL_WIDE_CHARACTER_CODE = START_OF_HEADING_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The start of text control character code. U+0002 */
static wchar_t START_OF_TEXT_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0002};
static wchar_t* START_OF_TEXT_CONTROL_WIDE_CHARACTER_CODE = START_OF_TEXT_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The end of text control character code. U+0003 */
static wchar_t END_OF_TEXT_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0003};
static wchar_t* END_OF_TEXT_CONTROL_WIDE_CHARACTER_CODE = END_OF_TEXT_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The end of transmission control character code. U+0004 */
static wchar_t END_OF_TRANSMISSION_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0004};
static wchar_t* END_OF_TRANSMISSION_CONTROL_WIDE_CHARACTER_CODE = END_OF_TRANSMISSION_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The enquiry control character code. U+0005 */
static wchar_t ENQUIRY_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0005};
static wchar_t* ENQUIRY_CONTROL_WIDE_CHARACTER_CODE = ENQUIRY_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The acknowledge control character code. U+0006 */
static wchar_t ACKNOWLEDGE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0006};
static wchar_t* ACKNOWLEDGE_CONTROL_WIDE_CHARACTER_CODE = ACKNOWLEDGE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The bell control character code. U+0007 */
static wchar_t BELL_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0007};
static wchar_t* BELL_CONTROL_WIDE_CHARACTER_CODE = BELL_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The backspace control character code. U+0008 */
static wchar_t BACKSPACE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0008};
static wchar_t* BACKSPACE_CONTROL_WIDE_CHARACTER_CODE = BACKSPACE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The character tabulation control character code.
 *
 * U+0009
 *
 * Alias names:
 * HORIZONTAL TAB
 */
static wchar_t CHARACTER_TABULATION_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0009};
static wchar_t* CHARACTER_TABULATION_CONTROL_WIDE_CHARACTER_CODE = CHARACTER_TABULATION_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

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
static wchar_t LINE_FEED_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x000A};
static wchar_t* LINE_FEED_CONTROL_WIDE_CHARACTER_CODE = LINE_FEED_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The line tabulation control character code.
 *
 * U+000B
 *
 * Alias names:
 * VERTICAL TAB
 */
static wchar_t LINE_TABULATION_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x000B};
static wchar_t* LINE_TABULATION_CONTROL_WIDE_CHARACTER_CODE = LINE_TABULATION_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The form feed control character code. U+000C */
static wchar_t FORM_FEED_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x000C};
static wchar_t* FORM_FEED_CONTROL_WIDE_CHARACTER_CODE = FORM_FEED_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The carriage return (enter) control character code. U+000D */
static wchar_t CARRIAGE_RETURN_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x000D};
static wchar_t* CARRIAGE_RETURN_CONTROL_WIDE_CHARACTER_CODE = CARRIAGE_RETURN_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The shift out control character code. U+000E */
static wchar_t SHIFT_OUT_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x000E};
static wchar_t* SHIFT_OUT_CONTROL_WIDE_CHARACTER_CODE = SHIFT_OUT_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The shift in control character code. U+000F */
static wchar_t SHIFT_IN_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x000F};
static wchar_t* SHIFT_IN_CONTROL_WIDE_CHARACTER_CODE = SHIFT_IN_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The data link escape control character code. U+0010 */
static wchar_t DATA_LINK_ESCAPE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0010};
static wchar_t* DATA_LINK_ESCAPE_CONTROL_WIDE_CHARACTER_CODE = DATA_LINK_ESCAPE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The device control one control character code. U+0011 */
static wchar_t DEVICE_CONTROL_ONE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0011};
static wchar_t* DEVICE_CONTROL_ONE_CONTROL_WIDE_CHARACTER_CODE = DEVICE_CONTROL_ONE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The device control two control character code. U+0012 */
static wchar_t DEVICE_CONTROL_TWO_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0012};
static wchar_t* DEVICE_CONTROL_TWO_CONTROL_WIDE_CHARACTER_CODE = DEVICE_CONTROL_TWO_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The device control three control character code. U+0013 */
static wchar_t DEVICE_CONTROL_THREE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0013};
static wchar_t* DEVICE_CONTROL_THREE_CONTROL_WIDE_CHARACTER_CODE = DEVICE_CONTROL_THREE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The device control four control character code. U+0014 */
static wchar_t DEVICE_CONTROL_FOUR_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0014};
static wchar_t* DEVICE_CONTROL_FOUR_CONTROL_WIDE_CHARACTER_CODE = DEVICE_CONTROL_FOUR_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The negative acknowledge control character code. U+0015 */
static wchar_t NEGATIVE_ACKNOWLEDGE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0015};
static wchar_t* NEGATIVE_ACKNOWLEDGE_CONTROL_WIDE_CHARACTER_CODE = NEGATIVE_ACKNOWLEDGE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The synchronous idle control character code. U+0016 */
static wchar_t SYNCHRONOUS_IDLE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0016};
static wchar_t* SYNCHRONOUS_IDLE_CONTROL_WIDE_CHARACTER_CODE = SYNCHRONOUS_IDLE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The end of transmission block control character code. U+0017 */
static wchar_t END_OF_TRANSMISSION_BLOCK_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0017};
static wchar_t* END_OF_TRANSMISSION_BLOCK_CONTROL_WIDE_CHARACTER_CODE = END_OF_TRANSMISSION_BLOCK_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The cancel control character code. U+0018 */
static wchar_t CANCEL_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0018};
static wchar_t* CANCEL_CONTROL_WIDE_CHARACTER_CODE = CANCEL_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The end of medium control character code. U+0019 */
static wchar_t END_OF_MEDIUM_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x0019};
static wchar_t* END_OF_MEDIUM_CONTROL_WIDE_CHARACTER_CODE = END_OF_MEDIUM_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The substitute control character code. U+001A */
static wchar_t SUBSTITUTE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x001A};
static wchar_t* SUBSTITUTE_CONTROL_WIDE_CHARACTER_CODE = SUBSTITUTE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The escape control character code. U+001B */
static wchar_t ESCAPE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x001B};
static wchar_t* ESCAPE_CONTROL_WIDE_CHARACTER_CODE = ESCAPE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The file separator control character code. U+001C */
static wchar_t FILE_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x001C};
static wchar_t* FILE_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE = FILE_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The group separator control character code. U+001D */
static wchar_t GROUP_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x001D};
static wchar_t* GROUP_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE = GROUP_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The record separator control character code. U+001E */
static wchar_t RECORD_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x001E};
static wchar_t* RECORD_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE = RECORD_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The unit separator control character code. U+001F */
static wchar_t UNIT_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x001F};
static wchar_t* UNIT_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE = UNIT_SEPARATOR_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

/** The space character code. U+0020 */
static wchar_t SPACE_WIDE_CHARACTER_CODE_ARRAY[] = {0x0020};
static wchar_t* SPACE_WIDE_CHARACTER_CODE = SPACE_WIDE_CHARACTER_CODE_ARRAY;

/** The exclamation mark character code. U+0021 */
static wchar_t EXCLAMATION_MARK_WIDE_CHARACTER_CODE_ARRAY[] = {0x0021};
static wchar_t* EXCLAMATION_MARK_WIDE_CHARACTER_CODE = EXCLAMATION_MARK_WIDE_CHARACTER_CODE_ARRAY;

/** The quotation mark character code. U+0022 */
static wchar_t QUOTATION_MARK_WIDE_CHARACTER_CODE_ARRAY[] = {0x0022};
static wchar_t* QUOTATION_MARK_WIDE_CHARACTER_CODE = QUOTATION_MARK_WIDE_CHARACTER_CODE_ARRAY;

/** The number sign character code. U+0023 */
static wchar_t NUMBER_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x0023};
static wchar_t* NUMBER_SIGN_WIDE_CHARACTER_CODE = NUMBER_SIGN_WIDE_CHARACTER_CODE_ARRAY;

/** The dollar sign character code. U+0024 */
static wchar_t DOLLAR_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x0024};
static wchar_t* DOLLAR_SIGN_WIDE_CHARACTER_CODE = DOLLAR_SIGN_WIDE_CHARACTER_CODE_ARRAY;

/** The percent sign character code. U+0025 */
static wchar_t PERCENT_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x0025};
static wchar_t* PERCENT_SIGN_WIDE_CHARACTER_CODE = PERCENT_SIGN_WIDE_CHARACTER_CODE_ARRAY;

/** The ampersand character code. U+0026 */
static wchar_t AMPERSAND_WIDE_CHARACTER_CODE_ARRAY[] = {0x0026};
static wchar_t* AMPERSAND_WIDE_CHARACTER_CODE = AMPERSAND_WIDE_CHARACTER_CODE_ARRAY;

/** The apostrophe character code. U+0027 */
static wchar_t APOSTROPHE_WIDE_CHARACTER_CODE_ARRAY[] = {0x0027};
static wchar_t* APOSTROPHE_WIDE_CHARACTER_CODE = APOSTROPHE_WIDE_CHARACTER_CODE_ARRAY;

/** The left parenthesis character code. U+0028 */
static wchar_t LEFT_PARENTHESIS_WIDE_CHARACTER_CODE_ARRAY[] = {0x0028};
static wchar_t* LEFT_PARENTHESIS_WIDE_CHARACTER_CODE = LEFT_PARENTHESIS_WIDE_CHARACTER_CODE_ARRAY;

/** The right parenthesis character code. U+0029 */
static wchar_t RIGHT_PARENTHESIS_WIDE_CHARACTER_CODE_ARRAY[] = {0x0029};
static wchar_t* RIGHT_PARENTHESIS_WIDE_CHARACTER_CODE = RIGHT_PARENTHESIS_WIDE_CHARACTER_CODE_ARRAY;

/** The asterisk character code. U+002A */
static wchar_t ASTERISK_WIDE_CHARACTER_CODE_ARRAY[] = {0x002A};
static wchar_t* ASTERISK_WIDE_CHARACTER_CODE = ASTERISK_WIDE_CHARACTER_CODE_ARRAY;

/** The plus sign character code. U+002B */
static wchar_t PLUS_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x002B};
static wchar_t* PLUS_SIGN_WIDE_CHARACTER_CODE = PLUS_SIGN_WIDE_CHARACTER_CODE_ARRAY;

/** The comma character code. U+002C */
static wchar_t COMMA_WIDE_CHARACTER_CODE_ARRAY[] = {0x002C};
static wchar_t* COMMA_WIDE_CHARACTER_CODE = COMMA_WIDE_CHARACTER_CODE_ARRAY;

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
static wchar_t HYPHEN_MINUS_WIDE_CHARACTER_CODE_ARRAY[] = {0x002D};
static wchar_t* HYPHEN_MINUS_WIDE_CHARACTER_CODE = HYPHEN_MINUS_WIDE_CHARACTER_CODE_ARRAY;

/** The full stop character code. U+002E */
static wchar_t FULL_STOP_WIDE_CHARACTER_CODE_ARRAY[] = {0x002E};
static wchar_t* FULL_STOP_WIDE_CHARACTER_CODE = FULL_STOP_WIDE_CHARACTER_CODE_ARRAY;

/** The solidus character code. U+002F */
static wchar_t SOLIDUS_WIDE_CHARACTER_CODE_ARRAY[] = {0x002F};
static wchar_t* SOLIDUS_WIDE_CHARACTER_CODE = SOLIDUS_WIDE_CHARACTER_CODE_ARRAY;

/** The digit zero character code. U+0030 */
static wchar_t DIGIT_ZERO_WIDE_CHARACTER_CODE_ARRAY[] = {0x0030};
static wchar_t* DIGIT_ZERO_WIDE_CHARACTER_CODE = DIGIT_ZERO_WIDE_CHARACTER_CODE_ARRAY;

/** The digit one character code. U+0031 */
static wchar_t DIGIT_ONE_WIDE_CHARACTER_CODE_ARRAY[] = {0x0031};
static wchar_t* DIGIT_ONE_WIDE_CHARACTER_CODE = DIGIT_ONE_WIDE_CHARACTER_CODE_ARRAY;

/** The digit two character code. U+0032 */
static wchar_t DIGIT_TWO_WIDE_CHARACTER_CODE_ARRAY[] = {0x0032};
static wchar_t* DIGIT_TWO_WIDE_CHARACTER_CODE = DIGIT_TWO_WIDE_CHARACTER_CODE_ARRAY;

/** The digit three character code. U+0033 */
static wchar_t DIGIT_THREE_WIDE_CHARACTER_CODE_ARRAY[] = {0x0033};
static wchar_t* DIGIT_THREE_WIDE_CHARACTER_CODE = DIGIT_THREE_WIDE_CHARACTER_CODE_ARRAY;

/** The digit four character code. U+0034 */
static wchar_t DIGIT_FOUR_WIDE_CHARACTER_CODE_ARRAY[] = {0x0034};
static wchar_t* DIGIT_FOUR_WIDE_CHARACTER_CODE = DIGIT_FOUR_WIDE_CHARACTER_CODE_ARRAY;

/** The digit five character code. U+0035 */
static wchar_t DIGIT_FIVE_WIDE_CHARACTER_CODE_ARRAY[] = {0x0035};
static wchar_t* DIGIT_FIVE_WIDE_CHARACTER_CODE = DIGIT_FIVE_WIDE_CHARACTER_CODE_ARRAY;

/** The digit six character code. U+0036 */
static wchar_t DIGIT_SIX_WIDE_CHARACTER_CODE_ARRAY[] = {0x0036};
static wchar_t* DIGIT_SIX_WIDE_CHARACTER_CODE = DIGIT_SIX_WIDE_CHARACTER_CODE_ARRAY;

/** The digit seven character code. U+0037 */
static wchar_t DIGIT_SEVEN_WIDE_CHARACTER_CODE_ARRAY[] = {0x0037};
static wchar_t* DIGIT_SEVEN_WIDE_CHARACTER_CODE = DIGIT_SEVEN_WIDE_CHARACTER_CODE_ARRAY;

/** The digit eight character code. U+0038 */
static wchar_t DIGIT_EIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x0038};
static wchar_t* DIGIT_EIGHT_WIDE_CHARACTER_CODE = DIGIT_EIGHT_WIDE_CHARACTER_CODE_ARRAY;

/** The digit nine character code. U+0039 */
static wchar_t DIGIT_NINE_WIDE_CHARACTER_CODE_ARRAY[] = {0x0039};
static wchar_t* DIGIT_NINE_WIDE_CHARACTER_CODE = DIGIT_NINE_WIDE_CHARACTER_CODE_ARRAY;

/** The colon character code. U+003A */
static wchar_t COLON_WIDE_CHARACTER_CODE_ARRAY[] = {0x003A};
static wchar_t* COLON_WIDE_CHARACTER_CODE = COLON_WIDE_CHARACTER_CODE_ARRAY;

/** The semicolon character code. U+003B */
static wchar_t SEMICOLON_WIDE_CHARACTER_CODE_ARRAY[] = {0x003B};
static wchar_t* SEMICOLON_WIDE_CHARACTER_CODE = SEMICOLON_WIDE_CHARACTER_CODE_ARRAY;

/** The less than sign character code. U+003C */
static wchar_t LESS_THAN_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x003C};
static wchar_t* LESS_THAN_SIGN_WIDE_CHARACTER_CODE = LESS_THAN_SIGN_WIDE_CHARACTER_CODE_ARRAY;

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
static wchar_t EQUALS_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x003D};
static wchar_t* EQUALS_SIGN_WIDE_CHARACTER_CODE = EQUALS_SIGN_WIDE_CHARACTER_CODE_ARRAY;

/** The greater than sign character code. U+003E */
static wchar_t GREATER_THAN_SIGN_WIDE_CHARACTER_CODE_ARRAY[] = {0x003E};
static wchar_t* GREATER_THAN_SIGN_WIDE_CHARACTER_CODE = GREATER_THAN_SIGN_WIDE_CHARACTER_CODE_ARRAY;

/** The question mark character code. U+003F */
static wchar_t QUESTION_MARK_WIDE_CHARACTER_CODE_ARRAY[] = {0x003F};
static wchar_t* QUESTION_MARK_WIDE_CHARACTER_CODE = QUESTION_MARK_WIDE_CHARACTER_CODE_ARRAY;

/** The commercial at character code. U+0040 */
static wchar_t COMMERCIAL_AT_WIDE_CHARACTER_CODE_ARRAY[] = {0x0040};
static wchar_t* COMMERCIAL_AT_WIDE_CHARACTER_CODE = COMMERCIAL_AT_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter a character code. U+0041 */
static wchar_t LATIN_CAPITAL_LETTER_A_WIDE_CHARACTER_CODE_ARRAY[] = {0x0041};
static wchar_t* LATIN_CAPITAL_LETTER_A_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_A_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter b character code. U+0042 */
static wchar_t LATIN_CAPITAL_LETTER_B_WIDE_CHARACTER_CODE_ARRAY[] = {0x0042};
static wchar_t* LATIN_CAPITAL_LETTER_B_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_B_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter c character code. U+0043 */
static wchar_t LATIN_CAPITAL_LETTER_C_WIDE_CHARACTER_CODE_ARRAY[] = {0x0043};
static wchar_t* LATIN_CAPITAL_LETTER_C_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_C_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter d character code. U+0044 */
static wchar_t LATIN_CAPITAL_LETTER_D_WIDE_CHARACTER_CODE_ARRAY[] = {0x0044};
static wchar_t* LATIN_CAPITAL_LETTER_D_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_D_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter e character code. U+0045 */
static wchar_t LATIN_CAPITAL_LETTER_E_WIDE_CHARACTER_CODE_ARRAY[] = {0x0045};
static wchar_t* LATIN_CAPITAL_LETTER_E_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_E_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter f character code. U+0046 */
static wchar_t LATIN_CAPITAL_LETTER_F_WIDE_CHARACTER_CODE_ARRAY[] = {0x0046};
static wchar_t* LATIN_CAPITAL_LETTER_F_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_F_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter g character code. U+0047 */
static wchar_t LATIN_CAPITAL_LETTER_G_WIDE_CHARACTER_CODE_ARRAY[] = {0x0047};
static wchar_t* LATIN_CAPITAL_LETTER_G_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_G_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter h character code. U+0048 */
static wchar_t LATIN_CAPITAL_LETTER_H_WIDE_CHARACTER_CODE_ARRAY[] = {0x0048};
static wchar_t* LATIN_CAPITAL_LETTER_H_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_H_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter i character code. U+0049 */
static wchar_t LATIN_CAPITAL_LETTER_I_WIDE_CHARACTER_CODE_ARRAY[] = {0x0049};
static wchar_t* LATIN_CAPITAL_LETTER_I_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_I_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter j character code. U+004A */
static wchar_t LATIN_CAPITAL_LETTER_J_WIDE_CHARACTER_CODE_ARRAY[] = {0x004A};
static wchar_t* LATIN_CAPITAL_LETTER_J_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_J_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter k character code. U+004B */
static wchar_t LATIN_CAPITAL_LETTER_K_WIDE_CHARACTER_CODE_ARRAY[] = {0x004B};
static wchar_t* LATIN_CAPITAL_LETTER_K_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_K_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter l character code. U+004C */
static wchar_t LATIN_CAPITAL_LETTER_L_WIDE_CHARACTER_CODE_ARRAY[] = {0x004C};
static wchar_t* LATIN_CAPITAL_LETTER_L_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_L_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter m character code. U+004D */
static wchar_t LATIN_CAPITAL_LETTER_M_WIDE_CHARACTER_CODE_ARRAY[] = {0x004D};
static wchar_t* LATIN_CAPITAL_LETTER_M_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_M_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter n character code. U+004E */
static wchar_t LATIN_CAPITAL_LETTER_N_WIDE_CHARACTER_CODE_ARRAY[] = {0x004E};
static wchar_t* LATIN_CAPITAL_LETTER_N_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_N_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter o character code. U+004F */
static wchar_t LATIN_CAPITAL_LETTER_O_WIDE_CHARACTER_CODE_ARRAY[] = {0x004F};
static wchar_t* LATIN_CAPITAL_LETTER_O_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_O_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter p character code. U+0050 */
static wchar_t LATIN_CAPITAL_LETTER_P_WIDE_CHARACTER_CODE_ARRAY[] = {0x0050};
static wchar_t* LATIN_CAPITAL_LETTER_P_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_P_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter q character code. U+0051 */
static wchar_t LATIN_CAPITAL_LETTER_Q_WIDE_CHARACTER_CODE_ARRAY[] = {0x0051};
static wchar_t* LATIN_CAPITAL_LETTER_Q_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_Q_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter r character code. U+0052 */
static wchar_t LATIN_CAPITAL_LETTER_R_WIDE_CHARACTER_CODE_ARRAY[] = {0x0052};
static wchar_t* LATIN_CAPITAL_LETTER_R_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_R_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter s character code. U+0053 */
static wchar_t LATIN_CAPITAL_LETTER_S_WIDE_CHARACTER_CODE_ARRAY[] = {0x0053};
static wchar_t* LATIN_CAPITAL_LETTER_S_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_S_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter t character code. U+0054 */
static wchar_t LATIN_CAPITAL_LETTER_T_WIDE_CHARACTER_CODE_ARRAY[] = {0x0054};
static wchar_t* LATIN_CAPITAL_LETTER_T_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_T_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter u character code. U+0055 */
static wchar_t LATIN_CAPITAL_LETTER_U_WIDE_CHARACTER_CODE_ARRAY[] = {0x0055};
static wchar_t* LATIN_CAPITAL_LETTER_U_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_U_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter v character code. U+0056 */
static wchar_t LATIN_CAPITAL_LETTER_V_WIDE_CHARACTER_CODE_ARRAY[] = {0x0056};
static wchar_t* LATIN_CAPITAL_LETTER_V_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_V_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter w character code. U+0057 */
static wchar_t LATIN_CAPITAL_LETTER_W_WIDE_CHARACTER_CODE_ARRAY[] = {0x0057};
static wchar_t* LATIN_CAPITAL_LETTER_W_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_W_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter x character code. U+0058 */
static wchar_t LATIN_CAPITAL_LETTER_X_WIDE_CHARACTER_CODE_ARRAY[] = {0x0058};
static wchar_t* LATIN_CAPITAL_LETTER_X_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_X_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter y character code. U+0059 */
static wchar_t LATIN_CAPITAL_LETTER_Y_WIDE_CHARACTER_CODE_ARRAY[] = {0x0059};
static wchar_t* LATIN_CAPITAL_LETTER_Y_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_Y_WIDE_CHARACTER_CODE_ARRAY;

/** The latin capital letter z character code. U+005A */
static wchar_t LATIN_CAPITAL_LETTER_Z_WIDE_CHARACTER_CODE_ARRAY[] = {0x005A};
static wchar_t* LATIN_CAPITAL_LETTER_Z_WIDE_CHARACTER_CODE = LATIN_CAPITAL_LETTER_Z_WIDE_CHARACTER_CODE_ARRAY;

/** The left square bracket character code. U+005B */
static wchar_t LEFT_SQUARE_BRACKET_WIDE_CHARACTER_CODE_ARRAY[] = {0x005B};
static wchar_t* LEFT_SQUARE_BRACKET_WIDE_CHARACTER_CODE = LEFT_SQUARE_BRACKET_WIDE_CHARACTER_CODE_ARRAY;

/** The reverse solidus character code. U+005C */
static wchar_t REVERSE_SOLIDUS_WIDE_CHARACTER_CODE_ARRAY[] = {0x005C};
static wchar_t* REVERSE_SOLIDUS_WIDE_CHARACTER_CODE = REVERSE_SOLIDUS_WIDE_CHARACTER_CODE_ARRAY;

/** The right square bracket character code. U+005D */
static wchar_t RIGHT_SQUARE_BRACKET_WIDE_CHARACTER_CODE_ARRAY[] = {0x005D};
static wchar_t* RIGHT_SQUARE_BRACKET_WIDE_CHARACTER_CODE = RIGHT_SQUARE_BRACKET_WIDE_CHARACTER_CODE_ARRAY;

/** The circumflex accent character code. U+005E */
static wchar_t CIRCUMFLEX_ACCENT_WIDE_CHARACTER_CODE_ARRAY[] = {0x005E};
static wchar_t* CIRCUMFLEX_ACCENT_WIDE_CHARACTER_CODE = CIRCUMFLEX_ACCENT_WIDE_CHARACTER_CODE_ARRAY;

/** The low line character code. U+005F */
static wchar_t LOW_LINE_WIDE_CHARACTER_CODE_ARRAY[] = {0x005F};
static wchar_t* LOW_LINE_WIDE_CHARACTER_CODE = LOW_LINE_WIDE_CHARACTER_CODE_ARRAY;

/** The grave accent character code. U+0060 */
static wchar_t GRAVE_ACCENT_WIDE_CHARACTER_CODE_ARRAY[] = {0x0060};
static wchar_t* GRAVE_ACCENT_WIDE_CHARACTER_CODE = GRAVE_ACCENT_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter a character code. U+0061 */
static wchar_t LATIN_SMALL_LETTER_A_WIDE_CHARACTER_CODE_ARRAY[] = {0x0061};
static wchar_t* LATIN_SMALL_LETTER_A_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_A_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter b character code. U+0062 */
static wchar_t LATIN_SMALL_LETTER_B_WIDE_CHARACTER_CODE_ARRAY[] = {0x0062};
static wchar_t* LATIN_SMALL_LETTER_B_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_B_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter c character code. U+0063 */
static wchar_t LATIN_SMALL_LETTER_C_WIDE_CHARACTER_CODE_ARRAY[] = {0x0063};
static wchar_t* LATIN_SMALL_LETTER_C_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_C_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter d character code. U+0064 */
static wchar_t LATIN_SMALL_LETTER_D_WIDE_CHARACTER_CODE_ARRAY[] = {0x0064};
static wchar_t* LATIN_SMALL_LETTER_D_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_D_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter e character code. U+0065 */
static wchar_t LATIN_SMALL_LETTER_E_WIDE_CHARACTER_CODE_ARRAY[] = {0x0065};
static wchar_t* LATIN_SMALL_LETTER_E_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_E_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter f character code. U+0066 */
static wchar_t LATIN_SMALL_LETTER_F_WIDE_CHARACTER_CODE_ARRAY[] = {0x0066};
static wchar_t* LATIN_SMALL_LETTER_F_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_F_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter g character code. U+0067 */
static wchar_t LATIN_SMALL_LETTER_G_WIDE_CHARACTER_CODE_ARRAY[] = {0x0067};
static wchar_t* LATIN_SMALL_LETTER_G_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_G_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter h character code. U+0068 */
static wchar_t LATIN_SMALL_LETTER_H_WIDE_CHARACTER_CODE_ARRAY[] = {0x0068};
static wchar_t* LATIN_SMALL_LETTER_H_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_H_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter i character code. U+0069 */
static wchar_t LATIN_SMALL_LETTER_I_WIDE_CHARACTER_CODE_ARRAY[] = {0x0069};
static wchar_t* LATIN_SMALL_LETTER_I_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_I_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter j character code. U+006A */
static wchar_t LATIN_SMALL_LETTER_J_WIDE_CHARACTER_CODE_ARRAY[] = {0x006A};
static wchar_t* LATIN_SMALL_LETTER_J_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_J_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter k character code. U+006B */
static wchar_t LATIN_SMALL_LETTER_K_WIDE_CHARACTER_CODE_ARRAY[] = {0x006B};
static wchar_t* LATIN_SMALL_LETTER_K_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_K_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter l character code. U+006C */
static wchar_t LATIN_SMALL_LETTER_L_WIDE_CHARACTER_CODE_ARRAY[] = {0x006C};
static wchar_t* LATIN_SMALL_LETTER_L_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_L_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter m character code. U+006D */
static wchar_t LATIN_SMALL_LETTER_M_WIDE_CHARACTER_CODE_ARRAY[] = {0x006D};
static wchar_t* LATIN_SMALL_LETTER_M_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_M_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter n character code. U+006E */
static wchar_t LATIN_SMALL_LETTER_N_WIDE_CHARACTER_CODE_ARRAY[] = {0x006E};
static wchar_t* LATIN_SMALL_LETTER_N_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_N_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter o character code. U+006F */
static wchar_t LATIN_SMALL_LETTER_O_WIDE_CHARACTER_CODE_ARRAY[] = {0x006F};
static wchar_t* LATIN_SMALL_LETTER_O_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_O_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter p character code. U+0070 */
static wchar_t LATIN_SMALL_LETTER_P_WIDE_CHARACTER_CODE_ARRAY[] = {0x0070};
static wchar_t* LATIN_SMALL_LETTER_P_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_P_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter q character code. U+0071 */
static wchar_t LATIN_SMALL_LETTER_Q_WIDE_CHARACTER_CODE_ARRAY[] = {0x0071};
static wchar_t* LATIN_SMALL_LETTER_Q_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_Q_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter r character code. U+0072 */
static wchar_t LATIN_SMALL_LETTER_R_WIDE_CHARACTER_CODE_ARRAY[] = {0x0072};
static wchar_t* LATIN_SMALL_LETTER_R_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_R_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter s character code. U+0073 */
static wchar_t LATIN_SMALL_LETTER_S_WIDE_CHARACTER_CODE_ARRAY[] = {0x0073};
static wchar_t* LATIN_SMALL_LETTER_S_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_S_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter t character code. U+0074 */
static wchar_t LATIN_SMALL_LETTER_T_WIDE_CHARACTER_CODE_ARRAY[] = {0x0074};
static wchar_t* LATIN_SMALL_LETTER_T_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_T_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter u character code. U+0075 */
static wchar_t LATIN_SMALL_LETTER_U_WIDE_CHARACTER_CODE_ARRAY[] = {0x0075};
static wchar_t* LATIN_SMALL_LETTER_U_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_U_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter v character code. U+0076 */
static wchar_t LATIN_SMALL_LETTER_V_WIDE_CHARACTER_CODE_ARRAY[] = {0x0076};
static wchar_t* LATIN_SMALL_LETTER_V_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_V_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter w character code. U+0077 */
static wchar_t LATIN_SMALL_LETTER_W_WIDE_CHARACTER_CODE_ARRAY[] = {0x0077};
static wchar_t* LATIN_SMALL_LETTER_W_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_W_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter x character code. U+0078 */
static wchar_t LATIN_SMALL_LETTER_X_WIDE_CHARACTER_CODE_ARRAY[] = {0x0078};
static wchar_t* LATIN_SMALL_LETTER_X_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_X_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter y character code. U+0079 */
static wchar_t LATIN_SMALL_LETTER_Y_WIDE_CHARACTER_CODE_ARRAY[] = {0x0079};
static wchar_t* LATIN_SMALL_LETTER_Y_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_Y_WIDE_CHARACTER_CODE_ARRAY;

/** The latin small letter z character code. U+007A */
static wchar_t LATIN_SMALL_LETTER_Z_WIDE_CHARACTER_CODE_ARRAY[] = {0x007A};
static wchar_t* LATIN_SMALL_LETTER_Z_WIDE_CHARACTER_CODE = LATIN_SMALL_LETTER_Z_WIDE_CHARACTER_CODE_ARRAY;

/** The left curly bracket character code. U+007B */
static wchar_t LEFT_CURLY_BRACKET_WIDE_CHARACTER_CODE_ARRAY[] = {0x007B};
static wchar_t* LEFT_CURLY_BRACKET_WIDE_CHARACTER_CODE = LEFT_CURLY_BRACKET_WIDE_CHARACTER_CODE_ARRAY;

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
static wchar_t VERTICAL_LINE_WIDE_CHARACTER_CODE_ARRAY[] = {0x007C};
static wchar_t* VERTICAL_LINE_WIDE_CHARACTER_CODE = VERTICAL_LINE_WIDE_CHARACTER_CODE_ARRAY;

/** The right curly bracket character code. U+007D */
static wchar_t RIGHT_CURLY_BRACKET_WIDE_CHARACTER_CODE_ARRAY[] = {0x007D};
static wchar_t* RIGHT_CURLY_BRACKET_WIDE_CHARACTER_CODE = RIGHT_CURLY_BRACKET_WIDE_CHARACTER_CODE_ARRAY;

/** The tilde character code. U+007E */
static wchar_t TILDE_WIDE_CHARACTER_CODE_ARRAY[] = {0x007E};
static wchar_t* TILDE_WIDE_CHARACTER_CODE = TILDE_WIDE_CHARACTER_CODE_ARRAY;

/** The delete control character code. U+007F */
static wchar_t DELETE_CONTROL_WIDE_CHARACTER_CODE_ARRAY[] = {0x007F};
static wchar_t* DELETE_CONTROL_WIDE_CHARACTER_CODE = DELETE_CONTROL_WIDE_CHARACTER_CODE_ARRAY;

//
// Extended character codes (128 - 255).
//

//
// Unicode block: ?? (?? - ??).
//

/**
 * The latin letter dental click character code.
 *
 * Unicode category: Letter, Other
 * Unicode: U+01C0
 * UTF-8: 0xC7 0x80
 * Octal escaped UTF-8: \307\200
 * Decimal entity reference: &#448;
 *
 * Alias names:
 * pipe
 *
 * Notes:
 * Khoisan tradition
 * "c" in Zulu orthography
 *
 * See also:
 * U+002F SOLIDUS
 * U+007C VERTICAL LINE
 * U+0287 LATIN SMALL LETTER TURNED T
 * U+2223 DIVIDES
 */
static wchar_t LATIN_LETTER_DENTAL_CLICK_WIDE_CHARACTER_CODE_ARRAY[] = {0x01c0};
static wchar_t* LATIN_LETTER_DENTAL_CLICK_WIDE_CHARACTER_CODE = LATIN_LETTER_DENTAL_CLICK_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The latin letter lateral click character code.
 *
 * Unicode category: Letter, Other
 * Unicode: U+01C1
 * UTF-8: 0xC7 0x81
 * Octal escaped UTF-8: \307\201
 * Decimal entity reference: &#449;
 *
 * Alias names:
 * double pipe
 *
 * Notes:
 * Khoisan tradition
 * "x" in Zulu orthography
 *
 * See also:
 * U+0296 LATIN LETTER INVERTED GLOTTAL STOP
 * U+2225 PARALLEL TO
 */
static wchar_t LATIN_LETTER_LATERAL_CLICK_WIDE_CHARACTER_CODE_ARRAY[] = {0x01c1};
static wchar_t* LATIN_LETTER_LATERAL_CLICK_WIDE_CHARACTER_CODE = LATIN_LETTER_LATERAL_CLICK_WIDE_CHARACTER_CODE_ARRAY;

//
// Unicode block: Box Drawing (9472 - 9599).
//

/**
 * The box drawings light horizontal character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2500
 * UTF-8: 0xE2 0x94 0x80
 * Octal escaped UTF-8: \342\224\200
 * Decimal entity reference: &#9472;
 *
 * Alias names:
 * Videotex Mosaic DG 15
 */
static wchar_t BOX_DRAWINGS_LIGHT_HORIZONTAL_WIDE_CHARACTER_CODE_ARRAY[] = {0x2500};
static wchar_t* BOX_DRAWINGS_LIGHT_HORIZONTAL_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_HORIZONTAL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings heavy horizontal character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2501
 * UTF-8: 0xE2 0x94 0x81
 * Octal escaped UTF-8: \342\224\201
 * Decimal entity reference: &#9473;
 */
static wchar_t BOX_DRAWINGS_HEAVY_HORIZONTAL_WIDE_CHARACTER_CODE_ARRAY[] = {0x2501};
static wchar_t* BOX_DRAWINGS_HEAVY_HORIZONTAL_WIDE_CHARACTER_CODE = BOX_DRAWINGS_HEAVY_HORIZONTAL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light vertical character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2502
 * UTF-8: 0xC7 0x82
 * Octal escaped UTF-8: \307\202
 * Decimal entity reference: &#9474;
 *
 * Alias names:
 * Videotex Mosaic DG 14
 */
static wchar_t BOX_DRAWINGS_LIGHT_VERTICAL_WIDE_CHARACTER_CODE_ARRAY[] = {0x2502};
static wchar_t* BOX_DRAWINGS_LIGHT_VERTICAL_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_VERTICAL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings heavy vertical character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2503
 * UTF-8: 0xC7 0x83
 * Octal escaped UTF-8: \307\203
 * Decimal entity reference: &#9475;
 */
static wchar_t BOX_DRAWINGS_HEAVY_VERTICAL_WIDE_CHARACTER_CODE_ARRAY[] = {0x2503};
static wchar_t* BOX_DRAWINGS_HEAVY_VERTICAL_WIDE_CHARACTER_CODE = BOX_DRAWINGS_HEAVY_VERTICAL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light down and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+250C
 * UTF-8: 0xE2 0x94 0x8C
 * Octal escaped UTF-8: \342\224\214
 * Decimal entity reference: &#9484;
 *
 * Alias names:
 * Videotex Mosaic DG 16
 */
static wchar_t BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x250c};
static wchar_t* BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings heavy down and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+250F
 * UTF-8: 0xE2 0x94 0x8F
 * Octal escaped UTF-8: \342\224\217
 * Decimal entity reference: &#9487;
 */
static wchar_t BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x250f};
static wchar_t* BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light down and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2510
 * UTF-8: 0xE2 0x94 0x90
 * Octal escaped UTF-8: \342\224\220
 * Decimal entity reference: &#9488;
 *
 * Alias names:
 * Videotex Mosaic DG 17
 */
static wchar_t BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2510};
static wchar_t* BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings heavy down and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2513
 * UTF-8: 0xE2 0x94 0x93
 * Octal escaped UTF-8: \342\224\223
 * Decimal entity reference: &#9491;
 */
static wchar_t BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2513};
static wchar_t* BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light up and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2514
 * UTF-8: 0xE2 0x94 0x94
 * Octal escaped UTF-8: \342\224\224
 * Decimal entity reference: &#9492;
 *
 * Alias names:
 * Videotex Mosaic DG 18
 */
static wchar_t BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2514};
static wchar_t* BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings heavy up and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2517
 * UTF-8: 0xE2 0x94 0x97
 * Octal escaped UTF-8: \342\224\227
 * Decimal entity reference: &#9495;
 */
static wchar_t BOX_DRAWINGS_HEAVY_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2517};
static wchar_t* BOX_DRAWINGS_HEAVY_UP_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_HEAVY_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light up and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2518
 * UTF-8: 0xE2 0x94 0x98
 * Octal escaped UTF-8: \342\224\230
 * Decimal entity reference: &#9496;
 *
 * Alias names:
 * Videotex Mosaic DG 19
 */
static wchar_t BOX_DRAWINGS_LIGHT_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2518};
static wchar_t* BOX_DRAWINGS_LIGHT_UP_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings heavy up and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+251B
 * UTF-8: 0xE2 0x94 0x9B
 * Octal escaped UTF-8: \342\224\233
 * Decimal entity reference: &#9499;
 */
static wchar_t BOX_DRAWINGS_HEAVY_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x251b};
static wchar_t* BOX_DRAWINGS_HEAVY_UP_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_HEAVY_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings double horizontal character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2550
 * UTF-8: 0xE2 0x95 0x90
 * Octal escaped UTF-8: \342\225\220
 * Decimal entity reference: &#9552;
 */
static wchar_t BOX_DRAWINGS_DOUBLE_HORIZONTAL_WIDE_CHARACTER_CODE_ARRAY[] = {0x2550};
static wchar_t* BOX_DRAWINGS_DOUBLE_HORIZONTAL_WIDE_CHARACTER_CODE = BOX_DRAWINGS_DOUBLE_HORIZONTAL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings double vertical character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2551
 * UTF-8: 0xE2 0x95 0x91
 * Octal escaped UTF-8: \342\225\221
 * Decimal entity reference: &#9553;
 */
static wchar_t BOX_DRAWINGS_DOUBLE_VERTICAL_WIDE_CHARACTER_CODE_ARRAY[] = {0x2551};
static wchar_t* BOX_DRAWINGS_DOUBLE_VERTICAL_WIDE_CHARACTER_CODE = BOX_DRAWINGS_DOUBLE_VERTICAL_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings double down and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2554
 * UTF-8: 0xE2 0x95 0x94
 * Octal escaped UTF-8: \342\225\224
 * Decimal entity reference: &#9556;
 */
static wchar_t BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2554};
static wchar_t* BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings double down and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2557
 * UTF-8: 0xE2 0x95 0x97
 * Octal escaped UTF-8: \342\225\227
 * Decimal entity reference: &#9559;
 */
static wchar_t BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2557};
static wchar_t* BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings double up and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+255A
 * UTF-8: 0xE2 0x95 0x9A
 * Octal escaped UTF-8: \342\225\232
 * Decimal entity reference: &#9562;
 */
static wchar_t BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x255a};
static wchar_t* BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings double up and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+255D
 * UTF-8: 0xE2 0x95 0x9D
 * Octal escaped UTF-8: \342\225\235
 * Decimal entity reference: &#9565;
 */
static wchar_t BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x255d};
static wchar_t* BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light arc down and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+256D
 * UTF-8: 0xE2 0x95 0xAD
 * Octal escaped UTF-8: \342\225\255
 * Decimal entity reference: &#9581;
 */
static wchar_t BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x256d};
static wchar_t* BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light arc down and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+256E
 * UTF-8: 0xE2 0x95 0xAE
 * Octal escaped UTF-8: \342\225\256
 * Decimal entity reference: &#9582;
 */
static wchar_t BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x256e};
static wchar_t* BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light arc up and left character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+256F
 * UTF-8: 0xE2 0x95 0xAF
 * Octal escaped UTF-8: \342\225\257
 * Decimal entity reference: &#9583;
 */
static wchar_t BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY[] = {0x256f};
static wchar_t* BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_WIDE_CHARACTER_CODE_ARRAY;

/**
 * The box drawings light arc up and right character code.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2570
 * UTF-8: 0xE2 0x95 0xB0
 * Octal escaped UTF-8: \342\225\260
 * Decimal entity reference: &#9584;
 */
static wchar_t BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY[] = {0x2570};
static wchar_t* BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_WIDE_CHARACTER_CODE = BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_WIDE_CHARACTER_CODE_ARRAY;

/* WIDE_CHARACTER_CODE_CONSTANTS_SOURCE */
#endif
