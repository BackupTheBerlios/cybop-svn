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
 * @version $Revision: 1.2 $ $Date: 2005-07-25 20:27:58 $ $Author: christian $
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

//
// ASCII characters (0 - 127).
//

/**
 * The null control character. U+0000
 * It is used as string termination in the C programming language.
 */
static const char NULL_CONTROL_CHARACTER_ARRAY[] = {'\0'};
static const char* NULL_CONTROL_CHARACTER = NULL_CONTROL_CHARACTER_ARRAY;
static const int* NULL_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The start of heading control character. U+0001 */
static const char START_OF_HEADING_CONTROL_CHARACTER_ARRAY[] = {'?'};
static const char* START_OF_HEADING_CONTROL_CHARACTER = START_OF_HEADING_CONTROL_CHARACTER_ARRAY;
static const int* START_OF_HEADING_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The start of text control character. U+0002 */
static const char START_OF_TEXT_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* START_OF_TEXT_CONTROL_CHARACTER = START_OF_TEXT_CONTROL_CHARACTER_ARRAY;
static const int* START_OF_TEXT_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end of text control character. U+0003 */
static const char END_OF_TEXT_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* END_OF_TEXT_CONTROL_CHARACTER = END_OF_TEXT_CONTROL_CHARACTER_ARRAY;
static const int* END_OF_TEXT_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end of transmission control character. U+0004 */
static const char END_OF_TRANSMISSION_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* END_OF_TRANSMISSION_CONTROL_CHARACTER = END_OF_TRANSMISSION_CONTROL_CHARACTER_ARRAY;
static const int* END_OF_TRANSMISSION_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The enquiry control character. U+0005 */
static const char ENQUIRY_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* ENQUIRY_CONTROL_CHARACTER = ENQUIRY_CONTROL_CHARACTER_ARRAY;
static const int* ENQUIRY_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The acknowledge control character. U+0006 */
static const char ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* ACKNOWLEDGE_CONTROL_CHARACTER = ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY;
static const int* ACKNOWLEDGE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The bell control character. U+0007 */
static const char BELL_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* BELL_CONTROL_CHARACTER = BELL_CONTROL_CHARACTER_ARRAY;
static const int* BELL_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The backspace control character. U+0008 */
static const char BACKSPACE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* BACKSPACE_CONTROL_CHARACTER = BACKSPACE_CONTROL_CHARACTER_ARRAY;
static const int* BACKSPACE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The character tabulation control character.
 *
 * U+0009
 *
 * Alias names:
 * HORIZONTAL TAB
 */
static const char CHARACTER_TABULATION_CONTROL_CHARACTER_ARRAY[] = {'\t'};
static const char* CHARACTER_TABULATION_CONTROL_CHARACTER = CHARACTER_TABULATION_CONTROL_CHARACTER_ARRAY;
static const int* CHARACTER_TABULATION_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

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
static const char LINE_FEED_CONTROL_CHARACTER_ARRAY[] = {'\n'};
static const char* LINE_FEED_CONTROL_CHARACTER = LINE_FEED_CONTROL_CHARACTER_ARRAY;
static const int* LINE_FEED_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The line tabulation control character.
 *
 * U+000B
 *
 * Alias names:
 * VERTICAL TAB
 */
static const char LINE_TABULATION_CONTROL_CHARACTER_ARRAY[] = {'\v'};
static const char* LINE_TABULATION_CONTROL_CHARACTER = LINE_TABULATION_CONTROL_CHARACTER_ARRAY;
static const int* LINE_TABULATION_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The form feed control character. U+000C */
static const char FORM_FEED_CONTROL_CHARACTER_ARRAY[] = {'\f'};
static const char* FORM_FEED_CONTROL_CHARACTER = FORM_FEED_CONTROL_CHARACTER_ARRAY;
static const int* FORM_FEED_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The carriage return control character. U+000D */
static const char CARRIAGE_RETURN_CONTROL_CHARACTER_ARRAY[] = {'\r'};
static const char* CARRIAGE_RETURN_CONTROL_CHARACTER = CARRIAGE_RETURN_CONTROL_CHARACTER_ARRAY;
static const int* CARRIAGE_RETURN_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The shift out control character. U+000E */
static const char SHIFT_OUT_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* SHIFT_OUT_CONTROL_CHARACTER = SHIFT_OUT_CONTROL_CHARACTER_ARRAY;
static const int* SHIFT_OUT_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The shift in control character. U+000F */
static const char SHIFT_IN_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* SHIFT_IN_CONTROL_CHARACTER = SHIFT_IN_CONTROL_CHARACTER_ARRAY;
static const int* SHIFT_IN_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The data link escape control character. U+0010 */
static const char DATA_LINK_ESCAPE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* DATA_LINK_ESCAPE_CONTROL_CHARACTER = DATA_LINK_ESCAPE_CONTROL_CHARACTER_ARRAY;
static const int* DATA_LINK_ESCAPE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The device control one control character. U+0011 */
static const char DEVICE_CONTROL_ONE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* DEVICE_CONTROL_ONE_CONTROL_CHARACTER = DEVICE_CONTROL_ONE_CONTROL_CHARACTER_ARRAY;
static const int* DEVICE_CONTROL_ONE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The device control two control character. U+0012 */
static const char DEVICE_CONTROL_TWO_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* DEVICE_CONTROL_TWO_CONTROL_CHARACTER = DEVICE_CONTROL_TWO_CONTROL_CHARACTER_ARRAY;
static const int* DEVICE_CONTROL_TWO_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The device control three control character. U+0013 */
static const char DEVICE_CONTROL_THREE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* DEVICE_CONTROL_THREE_CONTROL_CHARACTER = DEVICE_CONTROL_THREE_CONTROL_CHARACTER_ARRAY;
static const int* DEVICE_CONTROL_THREE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The device control four control character. U+0014 */
static const char DEVICE_CONTROL_FOUR_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* DEVICE_CONTROL_FOUR_CONTROL_CHARACTER = DEVICE_CONTROL_FOUR_CONTROL_CHARACTER_ARRAY;
static const int* DEVICE_CONTROL_FOUR_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The negative acknowledge control character. U+0015 */
static const char NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER = NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER_ARRAY;
static const int* NEGATIVE_ACKNOWLEDGE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The synchronous idle control character. U+0016 */
static const char SYNCHRONOUS_IDLE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* SYNCHRONOUS_IDLE_CONTROL_CHARACTER = SYNCHRONOUS_IDLE_CONTROL_CHARACTER_ARRAY;
static const int* SYNCHRONOUS_IDLE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end of transmission block control character. U+0017 */
static const char END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER = END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER_ARRAY;
static const int* END_OF_TRANSMISSION_BLOCK_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The cancel control character. U+0018 */
static const char CANCEL_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* CANCEL_CONTROL_CHARACTER = CANCEL_CONTROL_CHARACTER_ARRAY;
static const int* CANCEL_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end of medium control character. U+0019 */
static const char END_OF_MEDIUM_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* END_OF_MEDIUM_CONTROL_CHARACTER = END_OF_MEDIUM_CONTROL_CHARACTER_ARRAY;
static const int* END_OF_MEDIUM_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The substitute control character. U+001A */
static const char SUBSTITUTE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* SUBSTITUTE_CONTROL_CHARACTER = SUBSTITUTE_CONTROL_CHARACTER_ARRAY;
static const int* SUBSTITUTE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The escape control character. U+001B */
static const char ESCAPE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* ESCAPE_CONTROL_CHARACTER = ESCAPE_CONTROL_CHARACTER_ARRAY;
static const int* ESCAPE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The file separator control character. U+001C */
static const char FILE_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* FILE_SEPARATOR_CONTROL_CHARACTER = FILE_SEPARATOR_CONTROL_CHARACTER_ARRAY;
static const int* FILE_SEPARATOR_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The group separator control character. U+001D */
static const char GROUP_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* GROUP_SEPARATOR_CONTROL_CHARACTER = GROUP_SEPARATOR_CONTROL_CHARACTER_ARRAY;
static const int* GROUP_SEPARATOR_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The record separator control character. U+001E */
static const char RECORD_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* RECORD_SEPARATOR_CONTROL_CHARACTER = RECORD_SEPARATOR_CONTROL_CHARACTER_ARRAY;
static const int* RECORD_SEPARATOR_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The unit separator control character. U+001F */
static const char UNIT_SEPARATOR_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* UNIT_SEPARATOR_CONTROL_CHARACTER = UNIT_SEPARATOR_CONTROL_CHARACTER_ARRAY;
static const int* UNIT_SEPARATOR_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The space character. U+0020 */
static const char SPACE_CHARACTER_ARRAY[] = {' '};
static const char* SPACE_CHARACTER = SPACE_CHARACTER_ARRAY;
static const int* SPACE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The exclamation mark character. U+0021 */
static const char EXCLAMATION_MARK_CHARACTER_ARRAY[] = {'!'};
static const char* EXCLAMATION_MARK_CHARACTER = EXCLAMATION_MARK_CHARACTER_ARRAY;
static const int* EXCLAMATION_MARK_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The quotation mark character. U+0022 */
static const char QUOTATION_MARK_CHARACTER_ARRAY[] = {'"'};
static const char* QUOTATION_MARK_CHARACTER = QUOTATION_MARK_CHARACTER_ARRAY;
static const int* QUOTATION_MARK_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The number sign character. U+0023 */
static const char NUMBER_SIGN_CHARACTER_ARRAY[] = {'#'};
static const char* NUMBER_SIGN_CHARACTER = NUMBER_SIGN_CHARACTER_ARRAY;
static const int* NUMBER_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The dollar sign character. U+0024 */
static const char DOLLAR_SIGN_CHARACTER_ARRAY[] = {'$'};
static const char* DOLLAR_SIGN_CHARACTER = DOLLAR_SIGN_CHARACTER_ARRAY;
static const int* DOLLAR_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The percent sign character. U+0025 */
static const char PERCENT_SIGN_CHARACTER_ARRAY[] = {'%'};
static const char* PERCENT_SIGN_CHARACTER = PERCENT_SIGN_CHARACTER_ARRAY;
static const int* PERCENT_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ampersand character. U+0026 */
static const char AMPERSAND_CHARACTER_ARRAY[] = {'&'};
static const char* AMPERSAND_CHARACTER = AMPERSAND_CHARACTER_ARRAY;
static const int* AMPERSAND_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The apostrophe character. U+0027 */
//?? TODO: How to write a ' here? ''' does not work!
static const char APOSTROPHE_CHARACTER_ARRAY[] = {'\''};
static const char* APOSTROPHE_CHARACTER = APOSTROPHE_CHARACTER_ARRAY;
static const int* APOSTROPHE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left parenthesis character. U+0028 */
static const char LEFT_PARENTHESIS_CHARACTER_ARRAY[] = {'('};
static const char* LEFT_PARENTHESIS_CHARACTER = LEFT_PARENTHESIS_CHARACTER_ARRAY;
static const int* LEFT_PARENTHESIS_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right parenthesis character. U+0029 */
static const char RIGHT_PARENTHESIS_CHARACTER_ARRAY[] = {')'};
static const char* RIGHT_PARENTHESIS_CHARACTER = RIGHT_PARENTHESIS_CHARACTER_ARRAY;
static const int* RIGHT_PARENTHESIS_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The asterisk character. U+002A */
static const char ASTERISK_CHARACTER_ARRAY[] = {'*'};
static const char* ASTERISK_CHARACTER = ASTERISK_CHARACTER_ARRAY;
static const int* ASTERISK_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The plus sign character. U+002B */
static const char PLUS_SIGN_CHARACTER_ARRAY[] = {'+'};
static const char* PLUS_SIGN_CHARACTER = PLUS_SIGN_CHARACTER_ARRAY;
static const int* PLUS_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The comma character. U+002C */
static const char COMMA_CHARACTER_ARRAY[] = {','};
static const char* COMMA_CHARACTER = COMMA_CHARACTER_ARRAY;
static const int* COMMA_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The hyphen minus character. U+002D */
static const char HYPHEN_MINUS_CHARACTER_ARRAY[] = {'-'};
static const char* HYPHEN_MINUS_CHARACTER = HYPHEN_MINUS_CHARACTER_ARRAY;
static const int* HYPHEN_MINUS_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The full stop character. U+002E */
static const char FULL_STOP_CHARACTER_ARRAY[] = {'.'};
static const char* FULL_STOP_CHARACTER = FULL_STOP_CHARACTER_ARRAY;
static const int* FULL_STOP_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The solidus character. U+002F */
static const char SOLIDUS_CHARACTER_ARRAY[] = {'/'};
static const char* SOLIDUS_CHARACTER = SOLIDUS_CHARACTER_ARRAY;
static const int* SOLIDUS_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit zero character. U+0030 */
static const char DIGIT_ZERO_CHARACTER_ARRAY[] = {'0'};
static const char* DIGIT_ZERO_CHARACTER = DIGIT_ZERO_CHARACTER_ARRAY;
static const int* DIGIT_ZERO_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit one character. U+0031 */
static const char DIGIT_ONE_CHARACTER_ARRAY[] = {'1'};
static const char* DIGIT_ONE_CHARACTER = DIGIT_ONE_CHARACTER_ARRAY;
static const int* DIGIT_ONE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit two character. U+0032 */
static const char DIGIT_TWO_CHARACTER_ARRAY[] = {'2'};
static const char* DIGIT_TWO_CHARACTER = DIGIT_TWO_CHARACTER_ARRAY;
static const int* DIGIT_TWO_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit three character. U+0033 */
static const char DIGIT_THREE_CHARACTER_ARRAY[] = {'3'};
static const char* DIGIT_THREE_CHARACTER = DIGIT_THREE_CHARACTER_ARRAY;
static const int* DIGIT_THREE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit four character. U+0034 */
static const char DIGIT_FOUR_CHARACTER_ARRAY[] = {'4'};
static const char* DIGIT_FOUR_CHARACTER = DIGIT_FOUR_CHARACTER_ARRAY;
static const int* DIGIT_FOUR_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit five character. U+0035 */
static const char DIGIT_FIVE_CHARACTER_ARRAY[] = {'5'};
static const char* DIGIT_FIVE_CHARACTER = DIGIT_FIVE_CHARACTER_ARRAY;
static const int* DIGIT_FIVE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit six character. U+0036 */
static const char DIGIT_SIX_CHARACTER_ARRAY[] = {'6'};
static const char* DIGIT_SIX_CHARACTER = DIGIT_SIX_CHARACTER_ARRAY;
static const int* DIGIT_SIX_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit seven character. U+0037 */
static const char DIGIT_SEVEN_CHARACTER_ARRAY[] = {'7'};
static const char* DIGIT_SEVEN_CHARACTER = DIGIT_SEVEN_CHARACTER_ARRAY;
static const int* DIGIT_SEVEN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit eight character. U+0038 */
static const char DIGIT_EIGHT_CHARACTER_ARRAY[] = {'8'};
static const char* DIGIT_EIGHT_CHARACTER = DIGIT_EIGHT_CHARACTER_ARRAY;
static const int* DIGIT_EIGHT_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The digit nine character. U+0039 */
static const char DIGIT_NINE_CHARACTER_ARRAY[] = {'9'};
static const char* DIGIT_NINE_CHARACTER = DIGIT_NINE_CHARACTER_ARRAY;
static const int* DIGIT_NINE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The colon character. U+003A */
static const char COLON_CHARACTER_ARRAY[] = {':'};
static const char* COLON_CHARACTER = COLON_CHARACTER_ARRAY;
static const int* COLON_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The semicolon character. U+003B */
static const char SEMICOLON_CHARACTER_ARRAY[] = {';'};
static const char* SEMICOLON_CHARACTER = SEMICOLON_CHARACTER_ARRAY;
static const int* SEMICOLON_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The less than sign character. U+003C */
static const char LESS_THAN_SIGN_CHARACTER_ARRAY[] = {'<'};
static const char* LESS_THAN_SIGN_CHARACTER = LESS_THAN_SIGN_CHARACTER_ARRAY;
static const int* LESS_THAN_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The equals sign character. U+003D */
static const char EQUALS_SIGN_CHARACTER_ARRAY[] = {'='};
static const char* EQUALS_SIGN_CHARACTER = EQUALS_SIGN_CHARACTER_ARRAY;
static const int* EQUALS_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The greater than sign character. U+003E */
static const char GREATER_THAN_SIGN_CHARACTER_ARRAY[] = {'>'};
static const char* GREATER_THAN_SIGN_CHARACTER = GREATER_THAN_SIGN_CHARACTER_ARRAY;
static const int* GREATER_THAN_SIGN_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The question mark character. U+003F */
static const char QUESTION_MARK_CHARACTER_ARRAY[] = {'?'};
static const char* QUESTION_MARK_CHARACTER = QUESTION_MARK_CHARACTER_ARRAY;
static const int* QUESTION_MARK_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The commercial at character. U+0040 */
static const char COMMERCIAL_AT_CHARACTER_ARRAY[] = {'@'};
static const char* COMMERCIAL_AT_CHARACTER = COMMERCIAL_AT_CHARACTER_ARRAY;
static const int* COMMERCIAL_AT_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter a character. U+0041 */
static const char LATIN_CAPITAL_LETTER_A_CHARACTER_ARRAY[] = {'A'};
static const char* LATIN_CAPITAL_LETTER_A_CHARACTER = LATIN_CAPITAL_LETTER_A_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_A_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter b character. U+0042 */
static const char LATIN_CAPITAL_LETTER_B_CHARACTER_ARRAY[] = {'B'};
static const char* LATIN_CAPITAL_LETTER_B_CHARACTER = LATIN_CAPITAL_LETTER_B_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_B_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter c character. U+0043 */
static const char LATIN_CAPITAL_LETTER_C_CHARACTER_ARRAY[] = {'C'};
static const char* LATIN_CAPITAL_LETTER_C_CHARACTER = LATIN_CAPITAL_LETTER_C_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_C_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter d character. U+0044 */
static const char LATIN_CAPITAL_LETTER_D_CHARACTER_ARRAY[] = {'D'};
static const char* LATIN_CAPITAL_LETTER_D_CHARACTER = LATIN_CAPITAL_LETTER_D_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_D_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter e character. U+0045 */
static const char LATIN_CAPITAL_LETTER_E_CHARACTER_ARRAY[] = {'E'};
static const char* LATIN_CAPITAL_LETTER_E_CHARACTER = LATIN_CAPITAL_LETTER_E_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_E_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter f character. U+0046 */
static const char LATIN_CAPITAL_LETTER_F_CHARACTER_ARRAY[] = {'F'};
static const char* LATIN_CAPITAL_LETTER_F_CHARACTER = LATIN_CAPITAL_LETTER_F_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_F_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter g character. U+0047 */
static const char LATIN_CAPITAL_LETTER_G_CHARACTER_ARRAY[] = {'G'};
static const char* LATIN_CAPITAL_LETTER_G_CHARACTER = LATIN_CAPITAL_LETTER_G_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_G_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter h character. U+0048 */
static const char LATIN_CAPITAL_LETTER_H_CHARACTER_ARRAY[] = {'H'};
static const char* LATIN_CAPITAL_LETTER_H_CHARACTER = LATIN_CAPITAL_LETTER_H_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_H_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter i character. U+0049 */
static const char LATIN_CAPITAL_LETTER_I_CHARACTER_ARRAY[] = {'I'};
static const char* LATIN_CAPITAL_LETTER_I_CHARACTER = LATIN_CAPITAL_LETTER_I_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_I_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter j character. U+004A */
static const char LATIN_CAPITAL_LETTER_J_CHARACTER_ARRAY[] = {'J'};
static const char* LATIN_CAPITAL_LETTER_J_CHARACTER = LATIN_CAPITAL_LETTER_J_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_J_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter k character. U+004B */
static const char LATIN_CAPITAL_LETTER_K_CHARACTER_ARRAY[] = {'K'};
static const char* LATIN_CAPITAL_LETTER_K_CHARACTER = LATIN_CAPITAL_LETTER_K_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_K_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter l character. U+004C */
static const char LATIN_CAPITAL_LETTER_L_CHARACTER_ARRAY[] = {'L'};
static const char* LATIN_CAPITAL_LETTER_L_CHARACTER = LATIN_CAPITAL_LETTER_L_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_L_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter m character. U+004D */
static const char LATIN_CAPITAL_LETTER_M_CHARACTER_ARRAY[] = {'M'};
static const char* LATIN_CAPITAL_LETTER_M_CHARACTER = LATIN_CAPITAL_LETTER_M_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_M_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter n character. U+004E */
static const char LATIN_CAPITAL_LETTER_N_CHARACTER_ARRAY[] = {'N'};
static const char* LATIN_CAPITAL_LETTER_N_CHARACTER = LATIN_CAPITAL_LETTER_N_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_N_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter o character. U+004F */
static const char LATIN_CAPITAL_LETTER_O_CHARACTER_ARRAY[] = {'O'};
static const char* LATIN_CAPITAL_LETTER_O_CHARACTER = LATIN_CAPITAL_LETTER_O_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_O_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter p character. U+0050 */
static const char LATIN_CAPITAL_LETTER_P_CHARACTER_ARRAY[] = {'P'};
static const char* LATIN_CAPITAL_LETTER_P_CHARACTER = LATIN_CAPITAL_LETTER_P_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_P_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter q character. U+0051 */
static const char LATIN_CAPITAL_LETTER_Q_CHARACTER_ARRAY[] = {'Q'};
static const char* LATIN_CAPITAL_LETTER_Q_CHARACTER = LATIN_CAPITAL_LETTER_Q_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_Q_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter r character. U+0052 */
static const char LATIN_CAPITAL_LETTER_R_CHARACTER_ARRAY[] = {'R'};
static const char* LATIN_CAPITAL_LETTER_R_CHARACTER = LATIN_CAPITAL_LETTER_R_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_R_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter s character. U+0053 */
static const char LATIN_CAPITAL_LETTER_S_CHARACTER_ARRAY[] = {'S'};
static const char* LATIN_CAPITAL_LETTER_S_CHARACTER = LATIN_CAPITAL_LETTER_S_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_S_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter t character. U+0054 */
static const char LATIN_CAPITAL_LETTER_T_CHARACTER_ARRAY[] = {'T'};
static const char* LATIN_CAPITAL_LETTER_T_CHARACTER = LATIN_CAPITAL_LETTER_T_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_T_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter u character. U+0055 */
static const char LATIN_CAPITAL_LETTER_U_CHARACTER_ARRAY[] = {'U'};
static const char* LATIN_CAPITAL_LETTER_U_CHARACTER = LATIN_CAPITAL_LETTER_U_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_U_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter v character. U+0056 */
static const char LATIN_CAPITAL_LETTER_V_CHARACTER_ARRAY[] = {'V'};
static const char* LATIN_CAPITAL_LETTER_V_CHARACTER = LATIN_CAPITAL_LETTER_V_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_V_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter w character. U+0057 */
static const char LATIN_CAPITAL_LETTER_W_CHARACTER_ARRAY[] = {'W'};
static const char* LATIN_CAPITAL_LETTER_W_CHARACTER = LATIN_CAPITAL_LETTER_W_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_W_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter x character. U+0058 */
static const char LATIN_CAPITAL_LETTER_X_CHARACTER_ARRAY[] = {'X'};
static const char* LATIN_CAPITAL_LETTER_X_CHARACTER = LATIN_CAPITAL_LETTER_X_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_X_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter y character. U+0059 */
static const char LATIN_CAPITAL_LETTER_Y_CHARACTER_ARRAY[] = {'Y'};
static const char* LATIN_CAPITAL_LETTER_Y_CHARACTER = LATIN_CAPITAL_LETTER_Y_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_Y_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin capital letter z character. U+005A */
static const char LATIN_CAPITAL_LETTER_Z_CHARACTER_ARRAY[] = {'Z'};
static const char* LATIN_CAPITAL_LETTER_Z_CHARACTER = LATIN_CAPITAL_LETTER_Z_CHARACTER_ARRAY;
static const int* LATIN_CAPITAL_LETTER_Z_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left square bracket character. U+005B */
static const char LEFT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {'['};
static const char* LEFT_SQUARE_BRACKET_CHARACTER = LEFT_SQUARE_BRACKET_CHARACTER_ARRAY;
static const int* LEFT_SQUARE_BRACKET_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The reverse solidus character. U+005C */
static const char REVERSE_SOLIDUS_CHARACTER_ARRAY[] = {'\\'};
static const char* REVERSE_SOLIDUS_CHARACTER = REVERSE_SOLIDUS_CHARACTER_ARRAY;
static const int* REVERSE_SOLIDUS_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right square bracket character. U+005D */
static const char RIGHT_SQUARE_BRACKET_CHARACTER_ARRAY[] = {']'};
static const char* RIGHT_SQUARE_BRACKET_CHARACTER = RIGHT_SQUARE_BRACKET_CHARACTER_ARRAY;
static const int* RIGHT_SQUARE_BRACKET_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The circumflex accent character. U+005E */
static const char CIRCUMFLEX_ACCENT_CHARACTER_ARRAY[] = {'^'};
static const char* CIRCUMFLEX_ACCENT_CHARACTER = CIRCUMFLEX_ACCENT_CHARACTER_ARRAY;
static const int* CIRCUMFLEX_ACCENT_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The low line character. U+005F */
static const char LOW_LINE_CHARACTER_ARRAY[] = {'_'};
static const char* LOW_LINE_CHARACTER = LOW_LINE_CHARACTER_ARRAY;
static const int* LOW_LINE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The grave accent character. U+0060 */
static const char GRAVE_ACCENT_CHARACTER_ARRAY[] = {'`'};
static const char* GRAVE_ACCENT_CHARACTER = GRAVE_ACCENT_CHARACTER_ARRAY;
static const int* GRAVE_ACCENT_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter a character. U+0061 */
static const char LATIN_SMALL_LETTER_A_CHARACTER_ARRAY[] = {'a'};
static const char* LATIN_SMALL_LETTER_A_CHARACTER = LATIN_SMALL_LETTER_A_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_A_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter b character. U+0062 */
static const char LATIN_SMALL_LETTER_B_CHARACTER_ARRAY[] = {'b'};
static const char* LATIN_SMALL_LETTER_B_CHARACTER = LATIN_SMALL_LETTER_B_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_B_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter c character. U+0063 */
static const char LATIN_SMALL_LETTER_C_CHARACTER_ARRAY[] = {'c'};
static const char* LATIN_SMALL_LETTER_C_CHARACTER = LATIN_SMALL_LETTER_C_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_C_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter d character. U+0064 */
static const char LATIN_SMALL_LETTER_D_CHARACTER_ARRAY[] = {'d'};
static const char* LATIN_SMALL_LETTER_D_CHARACTER = LATIN_SMALL_LETTER_D_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_D_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter e character. U+0065 */
static const char LATIN_SMALL_LETTER_E_CHARACTER_ARRAY[] = {'e'};
static const char* LATIN_SMALL_LETTER_E_CHARACTER = LATIN_SMALL_LETTER_E_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_E_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter f character. U+0066 */
static const char LATIN_SMALL_LETTER_F_CHARACTER_ARRAY[] = {'f'};
static const char* LATIN_SMALL_LETTER_F_CHARACTER = LATIN_SMALL_LETTER_F_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_F_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter g character. U+0067 */
static const char LATIN_SMALL_LETTER_G_CHARACTER_ARRAY[] = {'g'};
static const char* LATIN_SMALL_LETTER_G_CHARACTER = LATIN_SMALL_LETTER_G_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_G_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter h character. U+0068 */
static const char LATIN_SMALL_LETTER_H_CHARACTER_ARRAY[] = {'h'};
static const char* LATIN_SMALL_LETTER_H_CHARACTER = LATIN_SMALL_LETTER_H_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_H_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter i character. U+0069 */
static const char LATIN_SMALL_LETTER_I_CHARACTER_ARRAY[] = {'i'};
static const char* LATIN_SMALL_LETTER_I_CHARACTER = LATIN_SMALL_LETTER_I_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_I_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter j character. U+006A */
static const char LATIN_SMALL_LETTER_J_CHARACTER_ARRAY[] = {'j'};
static const char* LATIN_SMALL_LETTER_J_CHARACTER = LATIN_SMALL_LETTER_J_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_J_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter k character. U+006B */
static const char LATIN_SMALL_LETTER_K_CHARACTER_ARRAY[] = {'k'};
static const char* LATIN_SMALL_LETTER_K_CHARACTER = LATIN_SMALL_LETTER_K_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_K_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter l character. U+006C */
static const char LATIN_SMALL_LETTER_L_CHARACTER_ARRAY[] = {'l'};
static const char* LATIN_SMALL_LETTER_L_CHARACTER = LATIN_SMALL_LETTER_L_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_L_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter m character. U+006D */
static const char LATIN_SMALL_LETTER_M_CHARACTER_ARRAY[] = {'m'};
static const char* LATIN_SMALL_LETTER_M_CHARACTER = LATIN_SMALL_LETTER_M_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_M_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter n character. U+006E */
static const char LATIN_SMALL_LETTER_N_CHARACTER_ARRAY[] = {'n'};
static const char* LATIN_SMALL_LETTER_N_CHARACTER = LATIN_SMALL_LETTER_N_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_N_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter o character. U+006F */
static const char LATIN_SMALL_LETTER_O_CHARACTER_ARRAY[] = {'o'};
static const char* LATIN_SMALL_LETTER_O_CHARACTER = LATIN_SMALL_LETTER_O_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_O_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter p character. U+0070 */
static const char LATIN_SMALL_LETTER_P_CHARACTER_ARRAY[] = {'p'};
static const char* LATIN_SMALL_LETTER_P_CHARACTER = LATIN_SMALL_LETTER_P_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_P_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter q character. U+0071 */
static const char LATIN_SMALL_LETTER_Q_CHARACTER_ARRAY[] = {'q'};
static const char* LATIN_SMALL_LETTER_Q_CHARACTER = LATIN_SMALL_LETTER_Q_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_Q_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter r character. U+0072 */
static const char LATIN_SMALL_LETTER_R_CHARACTER_ARRAY[] = {'r'};
static const char* LATIN_SMALL_LETTER_R_CHARACTER = LATIN_SMALL_LETTER_R_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_R_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter s character. U+0073 */
static const char LATIN_SMALL_LETTER_S_CHARACTER_ARRAY[] = {'s'};
static const char* LATIN_SMALL_LETTER_S_CHARACTER = LATIN_SMALL_LETTER_S_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_S_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter t character. U+0074 */
static const char LATIN_SMALL_LETTER_T_CHARACTER_ARRAY[] = {'t'};
static const char* LATIN_SMALL_LETTER_T_CHARACTER = LATIN_SMALL_LETTER_T_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_T_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter u character. U+0075 */
static const char LATIN_SMALL_LETTER_U_CHARACTER_ARRAY[] = {'u'};
static const char* LATIN_SMALL_LETTER_U_CHARACTER = LATIN_SMALL_LETTER_U_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_U_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter v character. U+0076 */
static const char LATIN_SMALL_LETTER_V_CHARACTER_ARRAY[] = {'v'};
static const char* LATIN_SMALL_LETTER_V_CHARACTER = LATIN_SMALL_LETTER_V_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_V_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter w character. U+0077 */
static const char LATIN_SMALL_LETTER_W_CHARACTER_ARRAY[] = {'w'};
static const char* LATIN_SMALL_LETTER_W_CHARACTER = LATIN_SMALL_LETTER_W_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_W_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter x character. U+0078 */
static const char LATIN_SMALL_LETTER_X_CHARACTER_ARRAY[] = {'x'};
static const char* LATIN_SMALL_LETTER_X_CHARACTER = LATIN_SMALL_LETTER_X_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_X_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter y character. U+0079 */
static const char LATIN_SMALL_LETTER_Y_CHARACTER_ARRAY[] = {'y'};
static const char* LATIN_SMALL_LETTER_Y_CHARACTER = LATIN_SMALL_LETTER_Y_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_Y_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The latin small letter z character. U+007A */
static const char LATIN_SMALL_LETTER_Z_CHARACTER_ARRAY[] = {'z'};
static const char* LATIN_SMALL_LETTER_Z_CHARACTER = LATIN_SMALL_LETTER_Z_CHARACTER_ARRAY;
static const int* LATIN_SMALL_LETTER_Z_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left curly bracket character. U+007B */
static const char LEFT_CURLY_BRACKET_CHARACTER_ARRAY[] = {'{'};
static const char* LEFT_CURLY_BRACKET_CHARACTER = LEFT_CURLY_BRACKET_CHARACTER_ARRAY;
static const int* LEFT_CURLY_BRACKET_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The vertical line character. U+007C */
static const char VERTICAL_LINE_CHARACTER_ARRAY[] = {'|'};
static const char* VERTICAL_LINE_CHARACTER = VERTICAL_LINE_CHARACTER_ARRAY;
static const int* VERTICAL_LINE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right curly bracket character. U+007D */
static const char RIGHT_CURLY_BRACKET_CHARACTER_ARRAY[] = {'}'};
static const char* RIGHT_CURLY_BRACKET_CHARACTER = RIGHT_CURLY_BRACKET_CHARACTER_ARRAY;
static const int* RIGHT_CURLY_BRACKET_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The tilde character. U+007E */
static const char TILDE_CHARACTER_ARRAY[] = {'~'};
static const char* TILDE_CHARACTER = TILDE_CHARACTER_ARRAY;
static const int* TILDE_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The delete control character. U+007F */
static const char DELETE_CONTROL_CHARACTER_ARRAY[] = {' '};
static const char* DELETE_CONTROL_CHARACTER = DELETE_CONTROL_CHARACTER_ARRAY;
static const int* DELETE_CONTROL_CHARACTER_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// ANSI characters (128 - 255).
//

//
// UNICODE characters (256 - ??).
//

/* CHARACTER_CONSTANTS_SOURCE */
#endif
