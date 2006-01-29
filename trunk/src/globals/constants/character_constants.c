/*
 * $RCSfile: character_constants.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2006-01-29 01:47:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_CONSTANTS_SOURCE
#define CHARACTER_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//?? See KDE menu: | Applications | Debian | Text | Unicode character map
//?? Add below also the following constants:
//?? - UTF-8
//?? - Octal escaped UTF-8
//?? - Decimal entity reference

/** The character count. */
static int* CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// ASCII characters (0 - 127).
//

/**
 * The null control character. U+0000
 * It is used as string termination in the C programming language.
 */
static char NULL_CONTROL_CHARACTER_ARRAY[] = {'\0'};
static char* NULL_CONTROL_CHARACTER = NULL_CONTROL_CHARACTER_ARRAY;

/** The start of heading control character. U+0001 */
static char START_OF_HEADING_CONTROL_CHARACTER_ARRAY[] = {'?'};
static char* START_OF_HEADING_CONTROL_CHARACTER = START_OF_HEADING_CONTROL_CHARACTER_ARRAY;

/** The start of text control character. U+0002 */
static char START_OF_TEXT_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* START_OF_TEXT_CONTROL_CHARACTER = START_OF_TEXT_CONTROL_CHARACTER_ARRAY;

/** The end of text control character. U+0003 */
static char END_OF_TEXT_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* END_OF_TEXT_CONTROL_CHARACTER = END_OF_TEXT_CONTROL_CHARACTER_ARRAY;

/** The end of transmission control character. U+0004 */
static char END_OF_TRANSMISSION_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* END_OF_TRANSMISSION_CONTROL_CHARACTER = END_OF_TRANSMISSION_CONTROL_CHARACTER_ARRAY;

/** The enquiry control character. U+0005 */
static char ENQUIRY_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* ENQUIRY_CONTROL_CHARACTER = ENQUIRY_CONTROL_CHARACTER_ARRAY;

/** The acknowledge control character. U+0006 */
static char ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* ACKNOWLEDGE_CONTROL_CHARACTER = ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY;

/** The bell control character. U+0007 */
static char BELL_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* BELL_CONTROL_CHARACTER = BELL_CONTROL_CHARACTER_ARRAY;

/** The backspace control character. U+0008 */
static char BACKSPACE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* BACKSPACE_CONTROL_CHARACTER = BACKSPACE_CONTROL_CHARACTER_ARRAY;

/**
 * The character tabulation control character.
 *
 * U+0009
 *
 * Alias names:
 * HORIZONTAL TAB
 */
static char CHARACTER_TABULATION_CONTROL_CHARACTER_ARRAY[] = {'\t'};
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
static char LINE_FEED_CONTROL_CHARACTER_ARRAY[] = {'\n'};
static char* LINE_FEED_CONTROL_CHARACTER = LINE_FEED_CONTROL_CHARACTER_ARRAY;

/**
 * The line tabulation control character.
 *
 * U+000B
 *
 * Alias names:
 * VERTICAL TAB
 */
static char LINE_TABULATION_CONTROL_CHARACTER_ARRAY[] = {'\v'};
static char* LINE_TABULATION_CONTROL_CHARACTER = LINE_TABULATION_CONTROL_CHARACTER_ARRAY;

/** The form feed control character. U+000C */
static char FORM_FEED_CONTROL_CHARACTER_ARRAY[] = {'\f'};
static char* FORM_FEED_CONTROL_CHARACTER = FORM_FEED_CONTROL_CHARACTER_ARRAY;

/** The carriage return control character. U+000D */
static char CARRIAGE_RETURN_CONTROL_CHARACTER_ARRAY[] = {'\r'};
static char* CARRIAGE_RETURN_CONTROL_CHARACTER = CARRIAGE_RETURN_CONTROL_CHARACTER_ARRAY;

/** The shift out control character. U+000E */
static char SHIFT_OUT_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* SHIFT_OUT_CONTROL_CHARACTER = SHIFT_OUT_CONTROL_CHARACTER_ARRAY;

/** The shift in control character. U+000F */
static char SHIFT_IN_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* SHIFT_IN_CONTROL_CHARACTER = SHIFT_IN_CONTROL_CHARACTER_ARRAY;

/** The data link escape control character. U+0010 */
static char DATA_LINK_ESCAPE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* DATA_LINK_ESCAPE_CONTROL_CHARACTER = DATA_LINK_ESCAPE_CONTROL_CHARACTER_ARRAY;

/** The device control one control character. U+0011 */
static char DEVICE_CONTROL_ONE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* DEVICE_CONTROL_ONE_CONTROL_CHARACTER = DEVICE_CONTROL_ONE_CONTROL_CHARACTER_ARRAY;

/** The device control two control character. U+0012 */
static char DEVICE_CONTROL_TWO_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* DEVICE_CONTROL_TWO_CONTROL_CHARACTER = DEVICE_CONTROL_TWO_CONTROL_CHARACTER_ARRAY;

/** The device control three control character. U+0013 */
static char DEVICE_CONTROL_THREE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* DEVICE_CONTROL_THREE_CONTROL_CHARACTER = DEVICE_CONTROL_THREE_CONTROL_CHARACTER_ARRAY;

/** The device control four control character. U+0014 */
static char DEVICE_CONTROL_FOUR_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* DEVICE_CONTROL_FOUR_CONTROL_CHARACTER = DEVICE_CONTROL_FOUR_CONTROL_CHARACTER_ARRAY;

/** The negative acknowledge control character. U+0015 */
static char NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER = NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY;

/** The synchronous idle control character. U+0016 */
static char SYNCHRONOUS_IDLE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* SYNCHRONOUS_IDLE_CONTROL_CHARACTER = SYNCHRONOUS_IDLE_CONTROL_CHARACTER_ARRAY;

/** The end of transmission block control character. U+0017 */
static char END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER = END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER_ARRAY;

/** The cancel control character. U+0018 */
static char CANCEL_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* CANCEL_CONTROL_CHARACTER = CANCEL_CONTROL_CHARACTER_ARRAY;

/** The end of medium control character. U+0019 */
static char END_OF_MEDIUM_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* END_OF_MEDIUM_CONTROL_CHARACTER = END_OF_MEDIUM_CONTROL_CHARACTER_ARRAY;

/** The substitute control character. U+001A */
static char SUBSTITUTE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* SUBSTITUTE_CONTROL_CHARACTER = SUBSTITUTE_CONTROL_CHARACTER_ARRAY;

/** The escape control character. U+001B */
static char ESCAPE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* ESCAPE_CONTROL_CHARACTER = ESCAPE_CONTROL_CHARACTER_ARRAY;

/** The file separator control character. U+001C */
static char FILE_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* FILE_SEPARATOR_CONTROL_CHARACTER = FILE_SEPARATOR_CONTROL_CHARACTER_ARRAY;

/** The group separator control character. U+001D */
static char GROUP_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* GROUP_SEPARATOR_CONTROL_CHARACTER = GROUP_SEPARATOR_CONTROL_CHARACTER_ARRAY;

/** The record separator control character. U+001E */
static char RECORD_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* RECORD_SEPARATOR_CONTROL_CHARACTER = RECORD_SEPARATOR_CONTROL_CHARACTER_ARRAY;

/** The unit separator control character. U+001F */
static char UNIT_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* UNIT_SEPARATOR_CONTROL_CHARACTER = UNIT_SEPARATOR_CONTROL_CHARACTER_ARRAY;

/** The space character. U+0020 */
static char SPACE_CHARACTER_ARRAY[] = {' '};
static char* SPACE_CHARACTER = SPACE_CHARACTER_ARRAY;

/** The exclamation mark character. U+0021 */
static char EXCLAMATION_MARK_CHARACTER_ARRAY[] = {'!'};
static char* EXCLAMATION_MARK_CHARACTER = EXCLAMATION_MARK_CHARACTER_ARRAY;

/** The quotation mark character. U+0022 */
static char QUOTATION_MARK_CHARACTER_ARRAY[] = {'"'};
static char* QUOTATION_MARK_CHARACTER = QUOTATION_MARK_CHARACTER_ARRAY;

/** The number sign character. U+0023 */
static char NUMBER_SIGN_CHARACTER_ARRAY[] = {'#'};
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

/** The apostrophe character. U+0027 */
//?? TODO: How to write a ' here? ''' does not work!
static char APOSTROPHE_CHARACTER_ARRAY[] = {'\''};
static char* APOSTROPHE_CHARACTER = APOSTROPHE_CHARACTER_ARRAY;

/** The left parenthesis character. U+0028 */
static char LEFT_PARENTHESIS_CHARACTER_ARRAY[] = {'('};
static char* LEFT_PARENTHESIS_CHARACTER = LEFT_PARENTHESIS_CHARACTER_ARRAY;

/** The right parenthesis character. U+0029 */
static char RIGHT_PARENTHESIS_CHARACTER_ARRAY[] = {')'};
static char* RIGHT_PARENTHESIS_CHARACTER = RIGHT_PARENTHESIS_CHARACTER_ARRAY;

/** The asterisk character. U+002A */
static char ASTERISK_CHARACTER_ARRAY[] = {'*'};
static char* ASTERISK_CHARACTER = ASTERISK_CHARACTER_ARRAY;

/** The plus sign character. U+002B */
static char PLUS_SIGN_CHARACTER_ARRAY[] = {'+'};
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
static char HYPHEN_MINUS_CHARACTER_ARRAY[] = {'-'};
static char* HYPHEN_MINUS_CHARACTER = HYPHEN_MINUS_CHARACTER_ARRAY;

/** The full stop character. U+002E */
static char FULL_STOP_CHARACTER_ARRAY[] = {'.'};
static char* FULL_STOP_CHARACTER = FULL_STOP_CHARACTER_ARRAY;

/** The solidus character. U+002F */
static char SOLIDUS_CHARACTER_ARRAY[] = {'/'};
static char* SOLIDUS_CHARACTER = SOLIDUS_CHARACTER_ARRAY;

/** The digit zero character. U+0030 */
static char DIGIT_ZERO_CHARACTER_ARRAY[] = {'0'};
static char* DIGIT_ZERO_CHARACTER = DIGIT_ZERO_CHARACTER_ARRAY;

/** The digit one character. U+0031 */
static char DIGIT_ONE_CHARACTER_ARRAY[] = {'1'};
static char* DIGIT_ONE_CHARACTER = DIGIT_ONE_CHARACTER_ARRAY;

/** The digit two character. U+0032 */
static char DIGIT_TWO_CHARACTER_ARRAY[] = {'2'};
static char* DIGIT_TWO_CHARACTER = DIGIT_TWO_CHARACTER_ARRAY;

/** The digit three character. U+0033 */
static char DIGIT_THREE_CHARACTER_ARRAY[] = {'3'};
static char* DIGIT_THREE_CHARACTER = DIGIT_THREE_CHARACTER_ARRAY;

/** The digit four character. U+0034 */
static char DIGIT_FOUR_CHARACTER_ARRAY[] = {'4'};
static char* DIGIT_FOUR_CHARACTER = DIGIT_FOUR_CHARACTER_ARRAY;

/** The digit five character. U+0035 */
static char DIGIT_FIVE_CHARACTER_ARRAY[] = {'5'};
static char* DIGIT_FIVE_CHARACTER = DIGIT_FIVE_CHARACTER_ARRAY;

/** The digit six character. U+0036 */
static char DIGIT_SIX_CHARACTER_ARRAY[] = {'6'};
static char* DIGIT_SIX_CHARACTER = DIGIT_SIX_CHARACTER_ARRAY;

/** The digit seven character. U+0037 */
static char DIGIT_SEVEN_CHARACTER_ARRAY[] = {'7'};
static char* DIGIT_SEVEN_CHARACTER = DIGIT_SEVEN_CHARACTER_ARRAY;

/** The digit eight character. U+0038 */
static char DIGIT_EIGHT_CHARACTER_ARRAY[] = {'8'};
static char* DIGIT_EIGHT_CHARACTER = DIGIT_EIGHT_CHARACTER_ARRAY;

/** The digit nine character. U+0039 */
static char DIGIT_NINE_CHARACTER_ARRAY[] = {'9'};
static char* DIGIT_NINE_CHARACTER = DIGIT_NINE_CHARACTER_ARRAY;

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

/** The latin capital letter a character. U+0041 */
static char LATIN_CAPITAL_LETTER_A_CHARACTER_ARRAY[] = {'A'};
static char* LATIN_CAPITAL_LETTER_A_CHARACTER = LATIN_CAPITAL_LETTER_A_CHARACTER_ARRAY;

/** The latin capital letter b character. U+0042 */
static char LATIN_CAPITAL_LETTER_B_CHARACTER_ARRAY[] = {'B'};
static char* LATIN_CAPITAL_LETTER_B_CHARACTER = LATIN_CAPITAL_LETTER_B_CHARACTER_ARRAY;

/** The latin capital letter c character. U+0043 */
static char LATIN_CAPITAL_LETTER_C_CHARACTER_ARRAY[] = {'C'};
static char* LATIN_CAPITAL_LETTER_C_CHARACTER = LATIN_CAPITAL_LETTER_C_CHARACTER_ARRAY;

/** The latin capital letter d character. U+0044 */
static char LATIN_CAPITAL_LETTER_D_CHARACTER_ARRAY[] = {'D'};
static char* LATIN_CAPITAL_LETTER_D_CHARACTER = LATIN_CAPITAL_LETTER_D_CHARACTER_ARRAY;

/** The latin capital letter e character. U+0045 */
static char LATIN_CAPITAL_LETTER_E_CHARACTER_ARRAY[] = {'E'};
static char* LATIN_CAPITAL_LETTER_E_CHARACTER = LATIN_CAPITAL_LETTER_E_CHARACTER_ARRAY;

/** The latin capital letter f character. U+0046 */
static char LATIN_CAPITAL_LETTER_F_CHARACTER_ARRAY[] = {'F'};
static char* LATIN_CAPITAL_LETTER_F_CHARACTER = LATIN_CAPITAL_LETTER_F_CHARACTER_ARRAY;

/** The latin capital letter g character. U+0047 */
static char LATIN_CAPITAL_LETTER_G_CHARACTER_ARRAY[] = {'G'};
static char* LATIN_CAPITAL_LETTER_G_CHARACTER = LATIN_CAPITAL_LETTER_G_CHARACTER_ARRAY;

/** The latin capital letter h character. U+0048 */
static char LATIN_CAPITAL_LETTER_H_CHARACTER_ARRAY[] = {'H'};
static char* LATIN_CAPITAL_LETTER_H_CHARACTER = LATIN_CAPITAL_LETTER_H_CHARACTER_ARRAY;

/** The latin capital letter i character. U+0049 */
static char LATIN_CAPITAL_LETTER_I_CHARACTER_ARRAY[] = {'I'};
static char* LATIN_CAPITAL_LETTER_I_CHARACTER = LATIN_CAPITAL_LETTER_I_CHARACTER_ARRAY;

/** The latin capital letter j character. U+004A */
static char LATIN_CAPITAL_LETTER_J_CHARACTER_ARRAY[] = {'J'};
static char* LATIN_CAPITAL_LETTER_J_CHARACTER = LATIN_CAPITAL_LETTER_J_CHARACTER_ARRAY;

/** The latin capital letter k character. U+004B */
static char LATIN_CAPITAL_LETTER_K_CHARACTER_ARRAY[] = {'K'};
static char* LATIN_CAPITAL_LETTER_K_CHARACTER = LATIN_CAPITAL_LETTER_K_CHARACTER_ARRAY;

/** The latin capital letter l character. U+004C */
static char LATIN_CAPITAL_LETTER_L_CHARACTER_ARRAY[] = {'L'};
static char* LATIN_CAPITAL_LETTER_L_CHARACTER = LATIN_CAPITAL_LETTER_L_CHARACTER_ARRAY;

/** The latin capital letter m character. U+004D */
static char LATIN_CAPITAL_LETTER_M_CHARACTER_ARRAY[] = {'M'};
static char* LATIN_CAPITAL_LETTER_M_CHARACTER = LATIN_CAPITAL_LETTER_M_CHARACTER_ARRAY;

/** The latin capital letter n character. U+004E */
static char LATIN_CAPITAL_LETTER_N_CHARACTER_ARRAY[] = {'N'};
static char* LATIN_CAPITAL_LETTER_N_CHARACTER = LATIN_CAPITAL_LETTER_N_CHARACTER_ARRAY;

/** The latin capital letter o character. U+004F */
static char LATIN_CAPITAL_LETTER_O_CHARACTER_ARRAY[] = {'O'};
static char* LATIN_CAPITAL_LETTER_O_CHARACTER = LATIN_CAPITAL_LETTER_O_CHARACTER_ARRAY;

/** The latin capital letter p character. U+0050 */
static char LATIN_CAPITAL_LETTER_P_CHARACTER_ARRAY[] = {'P'};
static char* LATIN_CAPITAL_LETTER_P_CHARACTER = LATIN_CAPITAL_LETTER_P_CHARACTER_ARRAY;

/** The latin capital letter q character. U+0051 */
static char LATIN_CAPITAL_LETTER_Q_CHARACTER_ARRAY[] = {'Q'};
static char* LATIN_CAPITAL_LETTER_Q_CHARACTER = LATIN_CAPITAL_LETTER_Q_CHARACTER_ARRAY;

/** The latin capital letter r character. U+0052 */
static char LATIN_CAPITAL_LETTER_R_CHARACTER_ARRAY[] = {'R'};
static char* LATIN_CAPITAL_LETTER_R_CHARACTER = LATIN_CAPITAL_LETTER_R_CHARACTER_ARRAY;

/** The latin capital letter s character. U+0053 */
static char LATIN_CAPITAL_LETTER_S_CHARACTER_ARRAY[] = {'S'};
static char* LATIN_CAPITAL_LETTER_S_CHARACTER = LATIN_CAPITAL_LETTER_S_CHARACTER_ARRAY;

/** The latin capital letter t character. U+0054 */
static char LATIN_CAPITAL_LETTER_T_CHARACTER_ARRAY[] = {'T'};
static char* LATIN_CAPITAL_LETTER_T_CHARACTER = LATIN_CAPITAL_LETTER_T_CHARACTER_ARRAY;

/** The latin capital letter u character. U+0055 */
static char LATIN_CAPITAL_LETTER_U_CHARACTER_ARRAY[] = {'U'};
static char* LATIN_CAPITAL_LETTER_U_CHARACTER = LATIN_CAPITAL_LETTER_U_CHARACTER_ARRAY;

/** The latin capital letter v character. U+0056 */
static char LATIN_CAPITAL_LETTER_V_CHARACTER_ARRAY[] = {'V'};
static char* LATIN_CAPITAL_LETTER_V_CHARACTER = LATIN_CAPITAL_LETTER_V_CHARACTER_ARRAY;

/** The latin capital letter w character. U+0057 */
static char LATIN_CAPITAL_LETTER_W_CHARACTER_ARRAY[] = {'W'};
static char* LATIN_CAPITAL_LETTER_W_CHARACTER = LATIN_CAPITAL_LETTER_W_CHARACTER_ARRAY;

/** The latin capital letter x character. U+0058 */
static char LATIN_CAPITAL_LETTER_X_CHARACTER_ARRAY[] = {'X'};
static char* LATIN_CAPITAL_LETTER_X_CHARACTER = LATIN_CAPITAL_LETTER_X_CHARACTER_ARRAY;

/** The latin capital letter y character. U+0059 */
static char LATIN_CAPITAL_LETTER_Y_CHARACTER_ARRAY[] = {'Y'};
static char* LATIN_CAPITAL_LETTER_Y_CHARACTER = LATIN_CAPITAL_LETTER_Y_CHARACTER_ARRAY;

/** The latin capital letter z character. U+005A */
static char LATIN_CAPITAL_LETTER_Z_CHARACTER_ARRAY[] = {'Z'};
static char* LATIN_CAPITAL_LETTER_Z_CHARACTER = LATIN_CAPITAL_LETTER_Z_CHARACTER_ARRAY;

/** The left square bracket character. U+005B */
static char LEFT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {'['};
static char* LEFT_SQUARE_BRACKET_CHARACTER = LEFT_SQUARE_BRACKET_CHARACTER_ARRAY;

/** The reverse solidus character. U+005C */
static char REVERSE_SOLIDUS_CHARACTER_ARRAY[] = {'\\'};
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

/** The latin small letter a character. U+0061 */
static char LATIN_SMALL_LETTER_A_CHARACTER_ARRAY[] = {'a'};
static char* LATIN_SMALL_LETTER_A_CHARACTER = LATIN_SMALL_LETTER_A_CHARACTER_ARRAY;

/** The latin small letter b character. U+0062 */
static char LATIN_SMALL_LETTER_B_CHARACTER_ARRAY[] = {'b'};
static char* LATIN_SMALL_LETTER_B_CHARACTER = LATIN_SMALL_LETTER_B_CHARACTER_ARRAY;

/** The latin small letter c character. U+0063 */
static char LATIN_SMALL_LETTER_C_CHARACTER_ARRAY[] = {'c'};
static char* LATIN_SMALL_LETTER_C_CHARACTER = LATIN_SMALL_LETTER_C_CHARACTER_ARRAY;

/** The latin small letter d character. U+0064 */
static char LATIN_SMALL_LETTER_D_CHARACTER_ARRAY[] = {'d'};
static char* LATIN_SMALL_LETTER_D_CHARACTER = LATIN_SMALL_LETTER_D_CHARACTER_ARRAY;

/** The latin small letter e character. U+0065 */
static char LATIN_SMALL_LETTER_E_CHARACTER_ARRAY[] = {'e'};
static char* LATIN_SMALL_LETTER_E_CHARACTER = LATIN_SMALL_LETTER_E_CHARACTER_ARRAY;

/** The latin small letter f character. U+0066 */
static char LATIN_SMALL_LETTER_F_CHARACTER_ARRAY[] = {'f'};
static char* LATIN_SMALL_LETTER_F_CHARACTER = LATIN_SMALL_LETTER_F_CHARACTER_ARRAY;

/** The latin small letter g character. U+0067 */
static char LATIN_SMALL_LETTER_G_CHARACTER_ARRAY[] = {'g'};
static char* LATIN_SMALL_LETTER_G_CHARACTER = LATIN_SMALL_LETTER_G_CHARACTER_ARRAY;

/** The latin small letter h character. U+0068 */
static char LATIN_SMALL_LETTER_H_CHARACTER_ARRAY[] = {'h'};
static char* LATIN_SMALL_LETTER_H_CHARACTER = LATIN_SMALL_LETTER_H_CHARACTER_ARRAY;

/** The latin small letter i character. U+0069 */
static char LATIN_SMALL_LETTER_I_CHARACTER_ARRAY[] = {'i'};
static char* LATIN_SMALL_LETTER_I_CHARACTER = LATIN_SMALL_LETTER_I_CHARACTER_ARRAY;

/** The latin small letter j character. U+006A */
static char LATIN_SMALL_LETTER_J_CHARACTER_ARRAY[] = {'j'};
static char* LATIN_SMALL_LETTER_J_CHARACTER = LATIN_SMALL_LETTER_J_CHARACTER_ARRAY;

/** The latin small letter k character. U+006B */
static char LATIN_SMALL_LETTER_K_CHARACTER_ARRAY[] = {'k'};
static char* LATIN_SMALL_LETTER_K_CHARACTER = LATIN_SMALL_LETTER_K_CHARACTER_ARRAY;

/** The latin small letter l character. U+006C */
static char LATIN_SMALL_LETTER_L_CHARACTER_ARRAY[] = {'l'};
static char* LATIN_SMALL_LETTER_L_CHARACTER = LATIN_SMALL_LETTER_L_CHARACTER_ARRAY;

/** The latin small letter m character. U+006D */
static char LATIN_SMALL_LETTER_M_CHARACTER_ARRAY[] = {'m'};
static char* LATIN_SMALL_LETTER_M_CHARACTER = LATIN_SMALL_LETTER_M_CHARACTER_ARRAY;

/** The latin small letter n character. U+006E */
static char LATIN_SMALL_LETTER_N_CHARACTER_ARRAY[] = {'n'};
static char* LATIN_SMALL_LETTER_N_CHARACTER = LATIN_SMALL_LETTER_N_CHARACTER_ARRAY;

/** The latin small letter o character. U+006F */
static char LATIN_SMALL_LETTER_O_CHARACTER_ARRAY[] = {'o'};
static char* LATIN_SMALL_LETTER_O_CHARACTER = LATIN_SMALL_LETTER_O_CHARACTER_ARRAY;

/** The latin small letter p character. U+0070 */
static char LATIN_SMALL_LETTER_P_CHARACTER_ARRAY[] = {'p'};
static char* LATIN_SMALL_LETTER_P_CHARACTER = LATIN_SMALL_LETTER_P_CHARACTER_ARRAY;

/** The latin small letter q character. U+0071 */
static char LATIN_SMALL_LETTER_Q_CHARACTER_ARRAY[] = {'q'};
static char* LATIN_SMALL_LETTER_Q_CHARACTER = LATIN_SMALL_LETTER_Q_CHARACTER_ARRAY;

/** The latin small letter r character. U+0072 */
static char LATIN_SMALL_LETTER_R_CHARACTER_ARRAY[] = {'r'};
static char* LATIN_SMALL_LETTER_R_CHARACTER = LATIN_SMALL_LETTER_R_CHARACTER_ARRAY;

/** The latin small letter s character. U+0073 */
static char LATIN_SMALL_LETTER_S_CHARACTER_ARRAY[] = {'s'};
static char* LATIN_SMALL_LETTER_S_CHARACTER = LATIN_SMALL_LETTER_S_CHARACTER_ARRAY;

/** The latin small letter t character. U+0074 */
static char LATIN_SMALL_LETTER_T_CHARACTER_ARRAY[] = {'t'};
static char* LATIN_SMALL_LETTER_T_CHARACTER = LATIN_SMALL_LETTER_T_CHARACTER_ARRAY;

/** The latin small letter u character. U+0075 */
static char LATIN_SMALL_LETTER_U_CHARACTER_ARRAY[] = {'u'};
static char* LATIN_SMALL_LETTER_U_CHARACTER = LATIN_SMALL_LETTER_U_CHARACTER_ARRAY;

/** The latin small letter v character. U+0076 */
static char LATIN_SMALL_LETTER_V_CHARACTER_ARRAY[] = {'v'};
static char* LATIN_SMALL_LETTER_V_CHARACTER = LATIN_SMALL_LETTER_V_CHARACTER_ARRAY;

/** The latin small letter w character. U+0077 */
static char LATIN_SMALL_LETTER_W_CHARACTER_ARRAY[] = {'w'};
static char* LATIN_SMALL_LETTER_W_CHARACTER = LATIN_SMALL_LETTER_W_CHARACTER_ARRAY;

/** The latin small letter x character. U+0078 */
static char LATIN_SMALL_LETTER_X_CHARACTER_ARRAY[] = {'x'};
static char* LATIN_SMALL_LETTER_X_CHARACTER = LATIN_SMALL_LETTER_X_CHARACTER_ARRAY;

/** The latin small letter y character. U+0079 */
static char LATIN_SMALL_LETTER_Y_CHARACTER_ARRAY[] = {'y'};
static char* LATIN_SMALL_LETTER_Y_CHARACTER = LATIN_SMALL_LETTER_Y_CHARACTER_ARRAY;

/** The latin small letter z character. U+007A */
static char LATIN_SMALL_LETTER_Z_CHARACTER_ARRAY[] = {'z'};
static char* LATIN_SMALL_LETTER_Z_CHARACTER = LATIN_SMALL_LETTER_Z_CHARACTER_ARRAY;

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

/** The delete control character. U+007F */
static char DELETE_CONTROL_CHARACTER_ARRAY[] = {' '};
static char* DELETE_CONTROL_CHARACTER = DELETE_CONTROL_CHARACTER_ARRAY;

//
// ANSI characters (128 - 255).
//

//
// Unicode block: ?? (?? - ??).
//

/**
 * The latin letter dental click character.
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
static char LATIN_LETTER_DENTAL_CLICK_CHARACTER_ARRAY[] = {448};
static char* LATIN_LETTER_DENTAL_CLICK_CHARACTER = LATIN_LETTER_DENTAL_CLICK_CHARACTER_ARRAY;

/**
 * The latin letter lateral click character.
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
static char LATIN_LETTER_LATERAL_CLICK_CHARACTER_ARRAY[] = {449};
static char* LATIN_LETTER_LATERAL_CLICK_CHARACTER = LATIN_LETTER_LATERAL_CLICK_CHARACTER_ARRAY;

//
// Unicode block: Box Drawing (9472 - 9599).
//

/**
 * The box drawings light horizontal character.
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
static char BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER_ARRAY[] = {9472};
static char* BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER = BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER_ARRAY;

/**
 * The box drawings heavy horizontal character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2501
 * UTF-8: 0xE2 0x94 0x81
 * Octal escaped UTF-8: \342\224\201
 * Decimal entity reference: &#9473;
 */
static char BOX_DRAWINGS_HEAVY_HORIZONTAL_CHARACTER_ARRAY[] = {9473};
static char* BOX_DRAWINGS_HEAVY_HORIZONTAL_CHARACTER = BOX_DRAWINGS_HEAVY_HORIZONTAL_CHARACTER_ARRAY;

/**
 * The box drawings light vertical character.
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
static char BOX_DRAWINGS_LIGHT_VERTICAL_CHARACTER_ARRAY[] = {9474};
static char* BOX_DRAWINGS_LIGHT_VERTICAL_CHARACTER = BOX_DRAWINGS_LIGHT_VERTICAL_CHARACTER_ARRAY;

/**
 * The box drawings heavy vertical character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2503
 * UTF-8: 0xC7 0x83
 * Octal escaped UTF-8: \307\203
 * Decimal entity reference: &#9475;
 */
static char BOX_DRAWINGS_HEAVY_VERTICAL_CHARACTER_ARRAY[] = {9475};
static char* BOX_DRAWINGS_HEAVY_VERTICAL_CHARACTER = BOX_DRAWINGS_HEAVY_VERTICAL_CHARACTER_ARRAY;

/**
 * The box drawings light down and right character.
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
static char BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_CHARACTER_ARRAY[] = {9484};
static char* BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_CHARACTER = BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings heavy down and right character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+250F
 * UTF-8: 0xE2 0x94 0x8F
 * Octal escaped UTF-8: \342\224\217
 * Decimal entity reference: &#9487;
 */
static char BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT_CHARACTER_ARRAY[] = {9487};
static char* BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT_CHARACTER = BOX_DRAWINGS_HEAVY_DOWN_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings light down and left character.
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
static char BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_CHARACTER_ARRAY[] = {9488};
static char* BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_CHARACTER = BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings heavy down and left character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2513
 * UTF-8: 0xE2 0x94 0x93
 * Octal escaped UTF-8: \342\224\223
 * Decimal entity reference: &#9491;
 */
static char BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT_CHARACTER_ARRAY[] = {9491};
static char* BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT_CHARACTER = BOX_DRAWINGS_HEAVY_DOWN_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings light up and right character.
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
static char BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_CHARACTER_ARRAY[] = {9492};
static char* BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_CHARACTER = BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings heavy up and right character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2513
 * UTF-8: 0xE2 0x94 0x97
 * Octal escaped UTF-8: \342\224\227
 * Decimal entity reference: &#9495;
 */
static char BOX_DRAWINGS_HEAVY_UP_AND_RIGHT_CHARACTER_ARRAY[] = {9495};
static char* BOX_DRAWINGS_HEAVY_UP_AND_RIGHT_CHARACTER = BOX_DRAWINGS_HEAVY_UP_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings light up and left character.
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
static char BOX_DRAWINGS_LIGHT_UP_AND_LEFT_CHARACTER_ARRAY[] = {9496};
static char* BOX_DRAWINGS_LIGHT_UP_AND_LEFT_CHARACTER = BOX_DRAWINGS_LIGHT_UP_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings heavy up and left character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+251B
 * UTF-8: 0xE2 0x94 0x9B
 * Octal escaped UTF-8: \342\224\233
 * Decimal entity reference: &#9499;
 */
static char BOX_DRAWINGS_HEAVY_UP_AND_LEFT_CHARACTER_ARRAY[] = {9499};
static char* BOX_DRAWINGS_HEAVY_UP_AND_LEFT_CHARACTER = BOX_DRAWINGS_HEAVY_UP_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings double horizontal character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2550
 * UTF-8: 0xE2 0x95 0x90
 * Octal escaped UTF-8: \342\225\220
 * Decimal entity reference: &#9552;
 */
static char BOX_DRAWINGS_DOUBLE_HORIZONTAL_CHARACTER_ARRAY[] = {9552};
static char* BOX_DRAWINGS_DOUBLE_HORIZONTAL_CHARACTER = BOX_DRAWINGS_DOUBLE_HORIZONTAL_CHARACTER_ARRAY;

/**
 * The box drawings double vertical character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2551
 * UTF-8: 0xE2 0x95 0x91
 * Octal escaped UTF-8: \342\225\221
 * Decimal entity reference: &#9553;
 */
static char BOX_DRAWINGS_DOUBLE_VERTICAL_CHARACTER_ARRAY[] = {9553};
static char* BOX_DRAWINGS_DOUBLE_VERTICAL_CHARACTER = BOX_DRAWINGS_DOUBLE_VERTICAL_CHARACTER_ARRAY;

/**
 * The box drawings double down and right character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2554
 * UTF-8: 0xE2 0x95 0x94
 * Octal escaped UTF-8: \342\225\224
 * Decimal entity reference: &#9556;
 */
static char BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_CHARACTER_ARRAY[] = {9556};
static char* BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_CHARACTER = BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings double down and left character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2557
 * UTF-8: 0xE2 0x95 0x97
 * Octal escaped UTF-8: \342\225\227
 * Decimal entity reference: &#9559;
 */
static char BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_CHARACTER_ARRAY[] = {9559};
static char* BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_CHARACTER = BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings double up and right character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+255A
 * UTF-8: 0xE2 0x95 0x9A
 * Octal escaped UTF-8: \342\225\232
 * Decimal entity reference: &#9562;
 */
static char BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_CHARACTER_ARRAY[] = {9562};
static char* BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_CHARACTER = BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings double up and left character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+255D
 * UTF-8: 0xE2 0x95 0x9D
 * Octal escaped UTF-8: \342\225\235
 * Decimal entity reference: &#9565;
 */
static char BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_CHARACTER_ARRAY[] = {9565};
static char* BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_CHARACTER = BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings light arc down and right character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+256D
 * UTF-8: 0xE2 0x95 0xAD
 * Octal escaped UTF-8: \342\225\255
 * Decimal entity reference: &#9581;
 */
static char BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_CHARACTER_ARRAY[] = {9581};
static char* BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_CHARACTER = BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_RIGHT_CHARACTER_ARRAY;

/**
 * The box drawings light arc down and left character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+256E
 * UTF-8: 0xE2 0x95 0xAE
 * Octal escaped UTF-8: \342\225\256
 * Decimal entity reference: &#9582;
 */
static char BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_CHARACTER_ARRAY[] = {9582};
static char* BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_CHARACTER = BOX_DRAWINGS_LIGHT_ARC_DOWN_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings light arc up and left character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+256F
 * UTF-8: 0xE2 0x95 0xAF
 * Octal escaped UTF-8: \342\225\257
 * Decimal entity reference: &#9583;
 */
static char BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_CHARACTER_ARRAY[] = {9583};
static char* BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_CHARACTER = BOX_DRAWINGS_LIGHT_ARC_UP_AND_LEFT_CHARACTER_ARRAY;

/**
 * The box drawings light arc up and right character.
 *
 * Unicode category: Symbol, Other
 * Unicode: U+2570
 * UTF-8: 0xE2 0x95 0xB0
 * Octal escaped UTF-8: \342\225\260
 * Decimal entity reference: &#9584;
 */
static char BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_CHARACTER_ARRAY[] = {9584};
static char* BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_CHARACTER = BOX_DRAWINGS_LIGHT_ARC_UP_AND_RIGHT_CHARACTER_ARRAY;

/* CHARACTER_CONSTANTS_SOURCE */
#endif
