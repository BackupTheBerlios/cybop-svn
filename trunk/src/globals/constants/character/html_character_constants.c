/*
 * $RCSfile: html_character_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-12 23:31:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_CHARACTER_CONSTANTS_SOURCE
#define HTML_CHARACTER_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// The references &#00; to &#08; are unused.
//

/** The horizontal tab html character. */
static char HORIZONTAL_TAB_HTML_CHARACTER_ARRAY[] = {'&', '#', '0', '9', ';'};
static char* HORIZONTAL_TAB_HTML_CHARACTER = HORIZONTAL_TAB_HTML_CHARACTER_ARRAY;
static int* HORIZONTAL_TAB_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The line feed html character. */
static char LINE_FEED_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', ';'};
static char* LINE_FEED_HTML_CHARACTER = LINE_FEED_HTML_CHARACTER_ARRAY;
static int* LINE_FEED_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// The references &#11; to &#12; are unused.
//

/** The carriage return html character. */
static char CARRIAGE_RETURN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '3', ';'};
static char* CARRIAGE_RETURN_HTML_CHARACTER = CARRIAGE_RETURN_HTML_CHARACTER_ARRAY;
static int* CARRIAGE_RETURN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// The references &#14; to &#31; are unused.
//

/** The space   html character. */
static char SPACE_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '2', ';'};
static char* SPACE_HTML_CHARACTER = SPACE_HTML_CHARACTER_ARRAY;
static int* SPACE_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The exclamation mark ! html character. */
static char EXCLAMATION_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '3', ';'};
static char* EXCLAMATION_MARK_HTML_CHARACTER = EXCLAMATION_MARK_HTML_CHARACTER_ARRAY;
static int* EXCLAMATION_MARK_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The quotation mark " html character. */
static char QUOTATION_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '4', ';'};
static char* QUOTATION_MARK_HTML_CHARACTER = QUOTATION_MARK_HTML_CHARACTER_ARRAY;
static int* QUOTATION_MARK_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The number sign # html character. */
static char NUMBER_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '5', ';'};
static char* NUMBER_SIGN_HTML_CHARACTER = NUMBER_SIGN_HTML_CHARACTER_ARRAY;
static int* NUMBER_SIGN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The dollar sign $ html character. */
static char DOLLAR_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '6', ';'};
static char* DOLLAR_SIGN_HTML_CHARACTER = DOLLAR_SIGN_HTML_CHARACTER_ARRAY;
static int* DOLLAR_SIGN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The percent sign % html character. */
static char PERCENT_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '7', ';'};
static char* PERCENT_SIGN_HTML_CHARACTER = PERCENT_SIGN_HTML_CHARACTER_ARRAY;
static int* PERCENT_SIGN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The ampersand & html character. */
static char AMPERSAND_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '8', ';'};
static char* AMPERSAND_HTML_CHARACTER = AMPERSAND_HTML_CHARACTER_ARRAY;
static int* AMPERSAND_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The apostrophe ' html character. */
static char APOSTROPHE_HTML_CHARACTER_ARRAY[] = {'&', '#', '3', '9', ';'};
static char* APOSTROPHE_HTML_CHARACTER = APOSTROPHE_HTML_CHARACTER_ARRAY;
static int* APOSTROPHE_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The left parenthesis ( html character. */
static char LEFT_PARENTHESIS_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '0', ';'};
static char* LEFT_PARENTHESIS_HTML_CHARACTER = LEFT_PARENTHESIS_HTML_CHARACTER_ARRAY;
static int* LEFT_PARENTHESIS_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The right parenthesis ) html character. */
static char RIGHT_PARENTHESIS_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '1', ';'};
static char* RIGHT_PARENTHESIS_HTML_CHARACTER = RIGHT_PARENTHESIS_HTML_CHARACTER_ARRAY;
static int* RIGHT_PARENTHESIS_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The asterisk * html character. */
static char ASTERISK_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '2', ';'};
static char* ASTERISK_HTML_CHARACTER = ASTERISK_HTML_CHARACTER_ARRAY;
static int* ASTERISK_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The plus sign + html character. */
static char PLUS_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '3', ';'};
static char* PLUS_SIGN_HTML_CHARACTER = PLUS_SIGN_HTML_CHARACTER_ARRAY;
static int* PLUS_SIGN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The comma , html character. */
static char COMMA_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '4', ';'};
static char* COMMA_HTML_CHARACTER = COMMA_HTML_CHARACTER_ARRAY;
static int* COMMA_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The hyphen - html character. */
static char HYPHEN_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '5', ';'};
static char* HYPHEN_HTML_CHARACTER = HYPHEN_HTML_CHARACTER_ARRAY;
static int* HYPHEN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The period (fullstop, dot) . html character. */
static char PERIOD_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '6', ';'};
static char* PERIOD_HTML_CHARACTER = PERIOD_HTML_CHARACTER_ARRAY;
static int* PERIOD_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The solidus (slash) / html character. */
static char SOLIDUS_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '7', ';'};
static char* SOLIDUS_HTML_CHARACTER = SOLIDUS_HTML_CHARACTER_ARRAY;
static int* SOLIDUS_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 0 html character. */
static char DIGIT_0_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '8', ';'};
static char* DIGIT_0_HTML_CHARACTER = DIGIT_0_HTML_CHARACTER_ARRAY;
static int* DIGIT_0_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 1 html character. */
static char DIGIT_1_HTML_CHARACTER_ARRAY[] = {'&', '#', '4', '9', ';'};
static char* DIGIT_1_HTML_CHARACTER = DIGIT_1_HTML_CHARACTER_ARRAY;
static int* DIGIT_1_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 2 html character. */
static char DIGIT_2_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '0', ';'};
static char* DIGIT_2_HTML_CHARACTER = DIGIT_2_HTML_CHARACTER_ARRAY;
static int* DIGIT_2_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 3 html character. */
static char DIGIT_3_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '1', ';'};
static char* DIGIT_3_HTML_CHARACTER = DIGIT_3_HTML_CHARACTER_ARRAY;
static int* DIGIT_3_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 4 html character. */
static char DIGIT_4_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '2', ';'};
static char* DIGIT_4_HTML_CHARACTER = DIGIT_4_HTML_CHARACTER_ARRAY;
static int* DIGIT_4_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 5 html character. */
static char DIGIT_5_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '3', ';'};
static char* DIGIT_5_HTML_CHARACTER = DIGIT_5_HTML_CHARACTER_ARRAY;
static int* DIGIT_5_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 6 html character. */
static char DIGIT_6_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '4', ';'};
static char* DIGIT_6_HTML_CHARACTER = DIGIT_6_HTML_CHARACTER_ARRAY;
static int* DIGIT_6_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 7 html character. */
static char DIGIT_7_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '5', ';'};
static char* DIGIT_7_HTML_CHARACTER = DIGIT_7_HTML_CHARACTER_ARRAY;
static int* DIGIT_7_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 8 html character. */
static char DIGIT_8_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '6', ';'};
static char* DIGIT_8_HTML_CHARACTER = DIGIT_8_HTML_CHARACTER_ARRAY;
static int* DIGIT_8_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The digit 9 html character. */
static char DIGIT_9_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '7', ';'};
static char* DIGIT_9_HTML_CHARACTER = DIGIT_9_HTML_CHARACTER_ARRAY;
static int* DIGIT_9_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The colon : html character. */
static char COLON_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '8', ';'};
static char* COLON_HTML_CHARACTER = COLON_HTML_CHARACTER_ARRAY;
static int* COLON_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The semi-colon ; html character. */
static char SEMICOLON_HTML_CHARACTER_ARRAY[] = {'&', '#', '5', '9', ';'};
static char* SEMICOLON_HTML_CHARACTER = SEMICOLON_HTML_CHARACTER_ARRAY;
static int* SEMICOLON_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The less than < html character. */
static char LESS_THAN_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '0', ';'};
static char* LESS_THAN_HTML_CHARACTER = LESS_THAN_HTML_CHARACTER_ARRAY;
static int* LESS_THAN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The equals sign = html character. */
static char EQUALS_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '1', ';'};
static char* EQUALS_SIGN_HTML_CHARACTER = EQUALS_SIGN_HTML_CHARACTER_ARRAY;
static int* EQUALS_SIGN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The greater than > html character. */
static char GREATER_THAN_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '2', ';'};
static char* GREATER_THAN_HTML_CHARACTER = GREATER_THAN_HTML_CHARACTER_ARRAY;
static int* GREATER_THAN_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The question mark ? html character. */
static char QUESTION_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '3', ';'};
static char* QUESTION_MARK_HTML_CHARACTER = QUESTION_MARK_HTML_CHARACTER_ARRAY;
static int* QUESTION_MARK_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The commercial at @ html character. */
static char COMMERCIAL_AT_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '4', ';'};
static char* COMMERCIAL_AT_HTML_CHARACTER = COMMERCIAL_AT_HTML_CHARACTER_ARRAY;
static int* COMMERCIAL_AT_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter a html character. */
static char CAPITAL_LETTER_A_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '5', ';'};
static char* CAPITAL_LETTER_A_HTML_CHARACTER = CAPITAL_LETTER_A_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_A_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter b html character. */
static char CAPITAL_LETTER_B_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '6', ';'};
static char* CAPITAL_LETTER_B_HTML_CHARACTER = CAPITAL_LETTER_B_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_B_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter c html character. */
static char CAPITAL_LETTER_C_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '7', ';'};
static char* CAPITAL_LETTER_C_HTML_CHARACTER = CAPITAL_LETTER_C_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_C_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter d html character. */
static char CAPITAL_LETTER_D_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '8', ';'};
static char* CAPITAL_LETTER_D_HTML_CHARACTER = CAPITAL_LETTER_D_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_D_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter e html character. */
static char CAPITAL_LETTER_E_HTML_CHARACTER_ARRAY[] = {'&', '#', '6', '9', ';'};
static char* CAPITAL_LETTER_E_HTML_CHARACTER = CAPITAL_LETTER_E_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_E_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter f html character. */
static char CAPITAL_LETTER_F_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '0', ';'};
static char* CAPITAL_LETTER_F_HTML_CHARACTER = CAPITAL_LETTER_F_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_F_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter g html character. */
static char CAPITAL_LETTER_G_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '1', ';'};
static char* CAPITAL_LETTER_G_HTML_CHARACTER = CAPITAL_LETTER_G_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_G_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter h html character. */
static char CAPITAL_LETTER_H_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '2', ';'};
static char* CAPITAL_LETTER_H_HTML_CHARACTER = CAPITAL_LETTER_H_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_H_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter i html character. */
static char CAPITAL_LETTER_I_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '3', ';'};
static char* CAPITAL_LETTER_I_HTML_CHARACTER = CAPITAL_LETTER_I_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_I_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter j html character. */
static char CAPITAL_LETTER_J_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '4', ';'};
static char* CAPITAL_LETTER_J_HTML_CHARACTER = CAPITAL_LETTER_J_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_J_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter k html character. */
static char CAPITAL_LETTER_K_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '5', ';'};
static char* CAPITAL_LETTER_K_HTML_CHARACTER = CAPITAL_LETTER_K_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_K_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter l html character. */
static char CAPITAL_LETTER_L_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '6', ';'};
static char* CAPITAL_LETTER_L_HTML_CHARACTER = CAPITAL_LETTER_L_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_L_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter m html character. */
static char CAPITAL_LETTER_M_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '7', ';'};
static char* CAPITAL_LETTER_M_HTML_CHARACTER = CAPITAL_LETTER_M_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_M_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter n html character. */
static char CAPITAL_LETTER_N_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '8', ';'};
static char* CAPITAL_LETTER_N_HTML_CHARACTER = CAPITAL_LETTER_N_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_N_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter o html character. */
static char CAPITAL_LETTER_O_HTML_CHARACTER_ARRAY[] = {'&', '#', '7', '9', ';'};
static char* CAPITAL_LETTER_O_HTML_CHARACTER = CAPITAL_LETTER_O_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_O_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter p html character. */
static char CAPITAL_LETTER_P_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '0', ';'};
static char* CAPITAL_LETTER_P_HTML_CHARACTER = CAPITAL_LETTER_P_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_P_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter q html character. */
static char CAPITAL_LETTER_Q_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '1', ';'};
static char* CAPITAL_LETTER_Q_HTML_CHARACTER = CAPITAL_LETTER_Q_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_Q_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter r html character. */
static char CAPITAL_LETTER_R_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '2', ';'};
static char* CAPITAL_LETTER_R_HTML_CHARACTER = CAPITAL_LETTER_R_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_R_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter s html character. */
static char CAPITAL_LETTER_S_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '3', ';'};
static char* CAPITAL_LETTER_S_HTML_CHARACTER = CAPITAL_LETTER_S_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_S_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter t html character. */
static char CAPITAL_LETTER_T_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '4', ';'};
static char* CAPITAL_LETTER_T_HTML_CHARACTER = CAPITAL_LETTER_T_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_T_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter u html character. */
static char CAPITAL_LETTER_U_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '5', ';'};
static char* CAPITAL_LETTER_U_HTML_CHARACTER = CAPITAL_LETTER_U_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_U_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter v html character. */
static char CAPITAL_LETTER_V_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '6', ';'};
static char* CAPITAL_LETTER_V_HTML_CHARACTER = CAPITAL_LETTER_V_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_V_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter w html character. */
static char CAPITAL_LETTER_W_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '7', ';'};
static char* CAPITAL_LETTER_W_HTML_CHARACTER = CAPITAL_LETTER_W_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_W_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter x html character. */
static char CAPITAL_LETTER_X_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '8', ';'};
static char* CAPITAL_LETTER_X_HTML_CHARACTER = CAPITAL_LETTER_X_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_X_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter y html character. */
static char CAPITAL_LETTER_Y_HTML_CHARACTER_ARRAY[] = {'&', '#', '8', '9', ';'};
static char* CAPITAL_LETTER_Y_HTML_CHARACTER = CAPITAL_LETTER_Y_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_Y_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The capital letter z html character. */
static char CAPITAL_LETTER_Z_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '0', ';'};
static char* CAPITAL_LETTER_Z_HTML_CHARACTER = CAPITAL_LETTER_Z_HTML_CHARACTER_ARRAY;
static int* CAPITAL_LETTER_Z_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The left square bracket [ html character. */
static char LEFT_SQUARE_BRACKET_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '1', ';'};
static char* LEFT_SQUARE_BRACKET_HTML_CHARACTER = LEFT_SQUARE_BRACKET_HTML_CHARACTER_ARRAY;
static int* LEFT_SQUARE_BRACKET_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The reverse solidus (backslash) \ html character. */
static char REVERSE_SOLIDUS_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '2', ';'};
static char* REVERSE_SOLIDUS_HTML_CHARACTER = REVERSE_SOLIDUS_HTML_CHARACTER_ARRAY;
static int* REVERSE_SOLIDUS_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The right square bracket ] html character. */
static char RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '3', ';'};
static char* RIGHT_SQUARE_BRACKET_HTML_CHARACTER = RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ARRAY;
static int* RIGHT_SQUARE_BRACKET_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The caret ^ html character. */
static char CARET_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '4', ';'};
static char* CARET_HTML_CHARACTER = CARET_HTML_CHARACTER_ARRAY;
static int* CARET_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The horizontal bar (underscore) _ html character. */
static char HORIZONTAL_BAR_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '5', ';'};
static char* HORIZONTAL_BAR_HTML_CHARACTER = HORIZONTAL_BAR_HTML_CHARACTER_ARRAY;
static int* HORIZONTAL_BAR_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The grave accent ` html character. */
static char GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '6', ';'};
static char* GRAVE_ACCENT_HTML_CHARACTER = GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The small letter a html character. */
static char SMALL_LETTER_A_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '7', ';'};
static char* SMALL_LETTER_A_HTML_CHARACTER = SMALL_LETTER_A_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_A_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The small letter b html character. */
static char SMALL_LETTER_B_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '8', ';'};
static char* SMALL_LETTER_B_HTML_CHARACTER = SMALL_LETTER_B_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_B_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The small letter c html character. */
static char SMALL_LETTER_C_HTML_CHARACTER_ARRAY[] = {'&', '#', '9', '9', ';'};
static char* SMALL_LETTER_C_HTML_CHARACTER = SMALL_LETTER_C_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_C_HTML_CHARACTER_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The small letter d html character. */
static char SMALL_LETTER_D_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '0', ';'};
static char* SMALL_LETTER_D_HTML_CHARACTER = SMALL_LETTER_D_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_D_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter e html character. */
static char SMALL_LETTER_E_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '1', ';'};
static char* SMALL_LETTER_E_HTML_CHARACTER = SMALL_LETTER_E_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_E_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter f html character. */
static char SMALL_LETTER_F_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '2', ';'};
static char* SMALL_LETTER_F_HTML_CHARACTER = SMALL_LETTER_F_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_F_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter g html character. */
static char SMALL_LETTER_G_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '3', ';'};
static char* SMALL_LETTER_G_HTML_CHARACTER = SMALL_LETTER_G_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_G_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter h html character. */
static char SMALL_LETTER_H_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '4', ';'};
static char* SMALL_LETTER_H_HTML_CHARACTER = SMALL_LETTER_H_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_H_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter i html character. */
static char SMALL_LETTER_I_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '5', ';'};
static char* SMALL_LETTER_I_HTML_CHARACTER = SMALL_LETTER_I_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_I_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter j html character. */
static char SMALL_LETTER_J_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '6', ';'};
static char* SMALL_LETTER_J_HTML_CHARACTER = SMALL_LETTER_J_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_J_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter k html character. */
static char SMALL_LETTER_K_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '7', ';'};
static char* SMALL_LETTER_K_HTML_CHARACTER = SMALL_LETTER_K_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_K_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter l html character. */
static char SMALL_LETTER_L_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '8', ';'};
static char* SMALL_LETTER_L_HTML_CHARACTER = SMALL_LETTER_L_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_L_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter m html character. */
static char SMALL_LETTER_M_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '0', '9', ';'};
static char* SMALL_LETTER_M_HTML_CHARACTER = SMALL_LETTER_M_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_M_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter n html character. */
static char SMALL_LETTER_N_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '0', ';'};
static char* SMALL_LETTER_N_HTML_CHARACTER = SMALL_LETTER_N_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_N_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter o html character. */
static char SMALL_LETTER_O_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '1', ';'};
static char* SMALL_LETTER_O_HTML_CHARACTER = SMALL_LETTER_O_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_O_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter p html character. */
static char SMALL_LETTER_P_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '2', ';'};
static char* SMALL_LETTER_P_HTML_CHARACTER = SMALL_LETTER_P_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_P_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter q html character. */
static char SMALL_LETTER_Q_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '3', ';'};
static char* SMALL_LETTER_Q_HTML_CHARACTER = SMALL_LETTER_Q_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_Q_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter r html character. */
static char SMALL_LETTER_R_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '4', ';'};
static char* SMALL_LETTER_R_HTML_CHARACTER = SMALL_LETTER_R_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_R_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter s html character. */
static char SMALL_LETTER_S_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '5', ';'};
static char* SMALL_LETTER_S_HTML_CHARACTER = SMALL_LETTER_S_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_S_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter t html character. */
static char SMALL_LETTER_T_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '6', ';'};
static char* SMALL_LETTER_T_HTML_CHARACTER = SMALL_LETTER_T_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_T_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter u html character. */
static char SMALL_LETTER_U_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '7', ';'};
static char* SMALL_LETTER_U_HTML_CHARACTER = SMALL_LETTER_U_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_U_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter v html character. */
static char SMALL_LETTER_V_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '8', ';'};
static char* SMALL_LETTER_V_HTML_CHARACTER = SMALL_LETTER_V_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_V_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter w html character. */
static char SMALL_LETTER_W_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '1', '9', ';'};
static char* SMALL_LETTER_W_HTML_CHARACTER = SMALL_LETTER_W_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_W_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter x html character. */
static char SMALL_LETTER_X_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '0', ';'};
static char* SMALL_LETTER_X_HTML_CHARACTER = SMALL_LETTER_X_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_X_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter y html character. */
static char SMALL_LETTER_Y_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '1', ';'};
static char* SMALL_LETTER_Y_HTML_CHARACTER = SMALL_LETTER_Y_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_Y_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small letter z html character. */
static char SMALL_LETTER_Z_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '2', ';'};
static char* SMALL_LETTER_Z_HTML_CHARACTER = SMALL_LETTER_Z_HTML_CHARACTER_ARRAY;
static int* SMALL_LETTER_Z_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The left curly brace { html character. */
static char LEFT_CURLY_BRACE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '3', ';'};
static char* LEFT_CURLY_BRACE_HTML_CHARACTER = LEFT_CURLY_BRACE_HTML_CHARACTER_ARRAY;
static int* LEFT_CURLY_BRACE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The vertical bar | html character. */
static char VERTICAL_BAR_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '4', ';'};
static char* VERTICAL_BAR_HTML_CHARACTER = VERTICAL_BAR_HTML_CHARACTER_ARRAY;
static int* VERTICAL_BAR_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The right curly brace } html character. */
static char RIGHT_CURLY_BRACE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '5', ';'};
static char* RIGHT_CURLY_BRACE_HTML_CHARACTER = RIGHT_CURLY_BRACE_HTML_CHARACTER_ARRAY;
static int* RIGHT_CURLY_BRACE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The tilde ~ html character. */
static char TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '2', '6', ';'};
static char* TILDE_HTML_CHARACTER = TILDE_HTML_CHARACTER_ARRAY;
static int* TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// The references &#127; to &#159; are unused.
//

/** The non-breaking space   html character. */
static char NON_BREAKING_SPACE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '0', ';'};
static char* NON_BREAKING_SPACE_HTML_CHARACTER = NON_BREAKING_SPACE_HTML_CHARACTER_ARRAY;
static int* NON_BREAKING_SPACE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The inverted exclamation html character. */
static char INVERTED_EXCLAMATION_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '1', ';'};
static char* INVERTED_EXCLAMATION_HTML_CHARACTER = INVERTED_EXCLAMATION_HTML_CHARACTER_ARRAY;
static int* INVERTED_EXCLAMATION_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The cent sign html character. */
static char CENT_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '2', ';'};
static char* CENT_SIGN_HTML_CHARACTER = CENT_SIGN_HTML_CHARACTER_ARRAY;
static int* CENT_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The pound sterling html character. */
static char POUND_STERLING_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '3', ';'};
static char* POUND_STERLING_HTML_CHARACTER = POUND_STERLING_HTML_CHARACTER_ARRAY;
static int* POUND_STERLING_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The general currency sign html character. */
static char GENERAL_CURRENCY_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '4', ';'};
static char* GENERAL_CURRENCY_HTML_CHARACTER = GENERAL_CURRENCY_HTML_CHARACTER_ARRAY;
static int* GENERAL_CURRENCY_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The yen sign html character. */
static char YEN_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '5', ';'};
static char* YEN_SIGN_HTML_CHARACTER = YEN_SIGN_HTML_CHARACTER_ARRAY;
static int* YEN_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The broken vertical bar html character. */
static char BROKEN_VERTICAL_BAR_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '6', ';'};
static char* BROKEN_VERTICAL_BAR_HTML_CHARACTER = BROKEN_VERTICAL_BAR_HTML_CHARACTER_ARRAY;
static int* BROKEN_VERTICAL_BAR_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The section sign html character. */
static char SECTION_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '7', ';'};
static char* SECTION_SIGN_HTML_CHARACTER = SECTION_SIGN_HTML_CHARACTER_ARRAY;
static int* SECTION_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The umlaut (dieresis) html character. */
static char UMLAUT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '8', ';'};
static char* UMLAUT_HTML_CHARACTER = UMLAUT_HTML_CHARACTER_ARRAY;
static int* UMLAUT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copyright html character. */
static char COPYRIGHT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '6', '9', ';'};
static char* COPYRIGHT_HTML_CHARACTER = COPYRIGHT_HTML_CHARACTER_ARRAY;
static int* COPYRIGHT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The feminine ordinal html character. */
static char FEMININE_ORDINAL_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '0', ';'};
static char* FEMININE_ORDINAL_HTML_CHARACTER = FEMININE_ORDINAL_HTML_CHARACTER_ARRAY;
static int* FEMININE_ORDINAL_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The left angle quote, guillemotleft html character. */
static char LEFT_ANGLE_QUOTE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '1', ';'};
static char* LEFT_ANGLE_QUOTE_HTML_CHARACTER = LEFT_ANGLE_QUOTE_HTML_CHARACTER_ARRAY;
static int* LEFT_ANGLE_QUOTE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The not sign html character. */
static char NOT_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '2', ';'};
static char* NOT_SIGN_HTML_CHARACTER = NOT_SIGN_HTML_CHARACTER_ARRAY;
static int* NOT_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The soft hyphen html character. */
static char SOFT_HYPHEN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '3', ';'};
static char* SOFT_HYPHEN_HTML_CHARACTER = SOFT_HYPHEN_HTML_CHARACTER_ARRAY;
static int* SOFT_HYPHEN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The registered trademark html character. */
static char REGISTERED_TRADEMARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '4', ';'};
static char* REGISTERED_TRADEMARK_HTML_CHARACTER = REGISTERED_TRADEMARK_HTML_CHARACTER_ARRAY;
static int* REGISTERED_TRADEMARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The macron accent html character. */
static char MACRON_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '5', ';'};
static char* MACRON_ACCENT_HTML_CHARACTER = MACRON_ACCENT_HTML_CHARACTER_ARRAY;
static int* MACRON_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The degree sign html character. */
static char DEGREE_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '6', ';'};
static char* DEGREE_SIGN_HTML_CHARACTER = DEGREE_SIGN_HTML_CHARACTER_ARRAY;
static int* DEGREE_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The plus or minus html character. */
static char PLUS_OR_MINUS_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '7', ';'};
static char* PLUS_OR_MINUS_HTML_CHARACTER = PLUS_OR_MINUS_HTML_CHARACTER_ARRAY;
static int* PLUS_OR_MINUS_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The superscript two ² html character. */
static char SUPERSCRIPT_TWO_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '8', ';'};
static char* SUPERSCRIPT_TWO_HTML_CHARACTER = SUPERSCRIPT_TWO_HTML_CHARACTER_ARRAY;
static int* SUPERSCRIPT_TWO_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The superscript three ³ html character. */
static char SUPERSCRIPT_THREE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '7', '9', ';'};
static char* SUPERSCRIPT_THREE_HTML_CHARACTER = SUPERSCRIPT_THREE_HTML_CHARACTER_ARRAY;
static int* SUPERSCRIPT_THREE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The acute accent html character. */
static char ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '0', ';'};
static char* ACUTE_ACCENT_HTML_CHARACTER = ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The micro sign html character. */
static char MICRO_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '1', ';'};
static char* MICRO_SIGN_HTML_CHARACTER = MICRO_SIGN_HTML_CHARACTER_ARRAY;
static int* MICRO_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The paragraph sign § html character. */
static char PARAGRAPH_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '2', ';'};
static char* PARAGRAPH_SIGN_HTML_CHARACTER = PARAGRAPH_SIGN_HTML_CHARACTER_ARRAY;
static int* PARAGRAPH_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The middle dot html character. */
static char MIDDLE_DOT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '3', ';'};
static char* MIDDLE_DOT_HTML_CHARACTER = MIDDLE_DOT_HTML_CHARACTER_ARRAY;
static int* MIDDLE_DOT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The cedilla html character. */
static char CEDILLA_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '4', ';'};
static char* CEDILLA_HTML_CHARACTER = CEDILLA_HTML_CHARACTER_ARRAY;
static int* CEDILLA_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The superscript one ¹ html character. */
static char SUPERSCRIPT_ONE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '5', ';'};
static char* SUPERSCRIPT_ONE_HTML_CHARACTER = SUPERSCRIPT_ONE_HTML_CHARACTER_ARRAY;
static int* SUPERSCRIPT_ONE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The masculine ordinal html character. */
static char MASCULINE_ORDINAL_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '6', ';'};
static char* MASCULINE_ORDINAL_HTML_CHARACTER = MASCULINE_ORDINAL_HTML_CHARACTER_ARRAY;
static int* MASCULINE_ORDINAL_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The right angle quote guillemotright html character. */
static char RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '7', ';'};
static char* RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_HTML_CHARACTER = RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_HTML_CHARACTER_ARRAY;
static int* RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The fraction one-fourth html character. */
static char FRACTION_ONE_FOURTH_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '8', ';'};
static char* FRACTION_ONE_FOURTH_HTML_CHARACTER = FRACTION_ONE_FOURTH_HTML_CHARACTER_ARRAY;
static int* FRACTION_ONE_FOURTH_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The fraction one-half ½ html character. */
static char FRACTION_ONE_HALF_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '8', '9', ';'};
static char* FRACTION_ONE_HALF_HTML_CHARACTER = FRACTION_ONE_HALF_HTML_CHARACTER_ARRAY;
static int* FRACTION_ONE_HALF_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The fraction three-fourths ¼ html character. */
static char FRACTION_THREE_FOURTHS_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '0', ';'};
static char* FRACTION_THREE_FOURTHS_HTML_CHARACTER = FRACTION_THREE_FOURTHS_HTML_CHARACTER_ARRAY;
static int* FRACTION_THREE_FOURTHS_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The inverted question mark html character. */
static char INVERTED_QUESTION_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '1', ';'};
static char* INVERTED_QUESTION_MARK_HTML_CHARACTER = INVERTED_QUESTION_MARK_HTML_CHARACTER_ARRAY;
static int* INVERTED_QUESTION_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital a grave accent html character. */
static char CAPITAL_A_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '2', ';'};
static char* CAPITAL_A_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_A_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_A_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital a acute accent html character. */
static char CAPITAL_A_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '3', ';'};
static char* CAPITAL_A_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_A_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_A_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital a circumflex accent html character. */
static char CAPITAL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '4', ';'};
static char* CAPITAL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital a tilde html character. */
static char CAPITAL_A_TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '5', ';'};
static char* CAPITAL_A_TILDE_HTML_CHARACTER = CAPITAL_A_TILDE_HTML_CHARACTER_ARRAY;
static int* CAPITAL_A_TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital a umlaut mark (dieresis) html character. */
static char CAPITAL_A_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '6', ';'};
static char* CAPITAL_A_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_A_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* CAPITAL_A_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital a ring html character. */
static char CAPITAL_A_RING_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '7', ';'};
static char* CAPITAL_A_RING_HTML_CHARACTER = CAPITAL_A_RING_HTML_CHARACTER_ARRAY;
static int* CAPITAL_A_RING_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital ae dipthong (ligature) html character. */
static char CAPITAL_AE_DIPTHONG_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '8', ';'};
static char* CAPITAL_AE_DIPTHONG_HTML_CHARACTER = CAPITAL_AE_DIPTHONG_HTML_CHARACTER_ARRAY;
static int* CAPITAL_AE_DIPTHONG_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital c cedilla html character. */
static char CAPITAL_C_CEDILLA_HTML_CHARACTER_ARRAY[] = {'&', '#', '1', '9', '9', ';'};
static char* CAPITAL_C_CEDILLA_HTML_CHARACTER = CAPITAL_C_CEDILLA_HTML_CHARACTER_ARRAY;
static int* CAPITAL_C_CEDILLA_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital e grave accent html character. */
static char CAPITAL_E_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '0', ';'};
static char* CAPITAL_E_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_E_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_E_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital e acute accent html character. */
static char CAPITAL_E_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '1', ';'};
static char* CAPITAL_E_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_E_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_E_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital e circumflex accent html character. */
static char CAPITAL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '2', ';'};
static char* CAPITAL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital e umlaut mark (dieresis) html character. */
static char CAPITAL_E_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '3', ';'};
static char* CAPITAL_E_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_E_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* CAPITAL_E_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital i grave accent html character. */
static char CAPITAL_I_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '4', ';'};
static char* CAPITAL_I_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_I_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_I_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital i acute accent html character. */
static char CAPITAL_I_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '5', ';'};
static char* CAPITAL_I_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_I_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_I_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital i circumflex accent html character. */
static char CAPITAL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '6', ';'};
static char* CAPITAL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital i umlaut mark (dieresis) html character. */
static char CAPITAL_I_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '7', ';'};
static char* CAPITAL_I_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_I_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* CAPITAL_I_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital eth icelandic html character. */
static char CAPITAL_ETH_ICELANDIC_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '8', ';'};
static char* CAPITAL_ETH_ICELANDIC_HTML_CHARACTER = CAPITAL_ETH_ICELANDIC_HTML_CHARACTER_ARRAY;
static int* CAPITAL_ETH_ICELANDIC_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital n tilde html character. */
static char CAPITAL_N_TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '0', '9', ';'};
static char* CAPITAL_N_TILDE_HTML_CHARACTER = CAPITAL_N_TILDE_HTML_CHARACTER_ARRAY;
static int* CAPITAL_N_TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital o grave accent html character. */
static char CAPITAL_O_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '0', ';'};
static char* CAPITAL_O_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_O_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_O_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital o acute accent html character. */
static char CAPITAL_O_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '1', ';'};
static char* CAPITAL_O_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_O_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_O_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital o circumflex accent html character. */
static char CAPITAL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '2', ';'};
static char* CAPITAL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital o tilde html character. */
static char CAPITAL_O_TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '3', ';'};
static char* CAPITAL_O_TILDE_HTML_CHARACTER = CAPITAL_O_TILDE_HTML_CHARACTER_ARRAY;
static int* CAPITAL_O_TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital o umlaut mark (dieresis) html character. */
static char CAPITAL_O_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '4', ';'};
static char* CAPITAL_O_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_O_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* CAPITAL_O_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The multiply sign html character. */
static char MULTIPLY_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '5', ';'};
static char* MULTIPLY_SIGN_HTML_CHARACTER = MULTIPLY_SIGN_HTML_CHARACTER_ARRAY;
static int* MULTIPLY_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital o slash html character. */
static char CAPITAL_O_SLASH_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '6', ';'};
static char* CAPITAL_O_SLASH_HTML_CHARACTER = CAPITAL_O_SLASH_HTML_CHARACTER_ARRAY;
static int* CAPITAL_O_SLASH_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital u grave accent html character. */
static char CAPITAL_U_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '7', ';'};
static char* CAPITAL_U_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_U_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_U_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital u acute accent html character. */
static char CAPITAL_U_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '8', ';'};
static char* CAPITAL_U_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_U_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_U_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital u circumflex accent html character. */
static char CAPITAL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '1', '9', ';'};
static char* CAPITAL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital u umlaut mark (dieresis) html character. */
static char CAPITAL_U_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '0', ';'};
static char* CAPITAL_U_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_U_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* CAPITAL_U_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital y acute accent html character. */
static char CAPITAL_Y_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '1', ';'};
static char* CAPITAL_Y_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_Y_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* CAPITAL_Y_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The capital thorn icelandic html character. */
static char CAPITAL_THORN_ICELANDIC_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '2', ';'};
static char* CAPITAL_THORN_ICELANDIC_HTML_CHARACTER = CAPITAL_THORN_ICELANDIC_HTML_CHARACTER_ARRAY;
static int* CAPITAL_THORN_ICELANDIC_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small sharp s german (sz ligature) html character. */
static char SMALL_SHARP_S_GERMAN_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '3', ';'};
static char* SMALL_SHARP_S_GERMAN_HTML_CHARACTER = SMALL_SHARP_S_GERMAN_HTML_CHARACTER_ARRAY;
static int* SMALL_SHARP_S_GERMAN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small a grave accent html character. */
static char SMALL_A_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '4', ';'};
static char* SMALL_A_GRAVE_ACCENT_HTML_CHARACTER = SMALL_A_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_A_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small a acute accent html character. */
static char SMALL_A_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '5', ';'};
static char* SMALL_A_ACUTE_ACCENT_HTML_CHARACTER = SMALL_A_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_A_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small a circumflex accent html character. */
static char SMALL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '6', ';'};
static char* SMALL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small a tilde html character. */
static char SMALL_A_TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '7', ';'};
static char* SMALL_A_TILDE_HTML_CHARACTER = SMALL_A_TILDE_HTML_CHARACTER_ARRAY;
static int* SMALL_A_TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small a umlaut mark (dieresis) html character. */
static char SMALL_A_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '8', ';'};
static char* SMALL_A_UMLAUT_MARK_HTML_CHARACTER = SMALL_A_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* SMALL_A_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small a ring html character. */
static char SMALL_A_RING_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '2', '9', ';'};
static char* SMALL_A_RING_HTML_CHARACTER = SMALL_A_RING_HTML_CHARACTER_ARRAY;
static int* SMALL_A_RING_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small ae dipthong (ligature) html character. */
static char SMALL_AE_DIPTHONG_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '0', ';'};
static char* SMALL_AE_DIPTHONG_HTML_CHARACTER = SMALL_AE_DIPTHONG_HTML_CHARACTER_ARRAY;
static int* SMALL_AE_DIPTHONG_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small c cedilla html character. */
static char SMALL_C_CEDILLA_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '1', ';'};
static char* SMALL_C_CEDILLA_HTML_CHARACTER = SMALL_C_CEDILLA_HTML_CHARACTER_ARRAY;
static int* SMALL_C_CEDILLA_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small e grave accent html character. */
static char SMALL_E_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '2', ';'};
static char* SMALL_E_GRAVE_ACCENT_HTML_CHARACTER = SMALL_E_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_E_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small e acute accent html character. */
static char SMALL_E_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '3', ';'};
static char* SMALL_E_ACUTE_ACCENT_HTML_CHARACTER = SMALL_E_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_E_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small e circumflex accent html character. */
static char SMALL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '4', ';'};
static char* SMALL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small e umlaut mark (dieresis) html character. */
static char SMALL_E_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '5', ';'};
static char* SMALL_E_UMLAUT_MARK_HTML_CHARACTER = SMALL_E_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* SMALL_E_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small i grave accent html character. */
static char SMALL_I_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '6', ';'};
static char* SMALL_I_GRAVE_ACCENT_HTML_CHARACTER = SMALL_I_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_I_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small i acute accent html character. */
static char SMALL_I_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '7', ';'};
static char* SMALL_I_ACUTE_ACCENT_HTML_CHARACTER = SMALL_I_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_I_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small i circumflex accent html character. */
static char SMALL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '8', ';'};
static char* SMALL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small i umlaut mark (dieresis) html character. */
static char SMALL_I_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '3', '9', ';'};
static char* SMALL_I_UMLAUT_MARK_HTML_CHARACTER = SMALL_I_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* SMALL_I_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small eth icelandic html character. */
static char SMALL_ETH_ICELANDIC_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '0', ';'};
static char* SMALL_ETH_ICELANDIC_HTML_CHARACTER = SMALL_ETH_ICELANDIC_HTML_CHARACTER_ARRAY;
static int* SMALL_ETH_ICELANDIC_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small n tilde html character. */
static char SMALL_N_TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '1', ';'};
static char* SMALL_N_TILDE_HTML_CHARACTER = SMALL_N_TILDE_HTML_CHARACTER_ARRAY;
static int* SMALL_N_TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small o grave accent html character. */
static char SMALL_O_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '2', ';'};
static char* SMALL_O_GRAVE_ACCENT_HTML_CHARACTER = SMALL_O_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_O_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small o acute accent html character. */
static char SMALL_O_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '3', ';'};
static char* SMALL_O_ACUTE_ACCENT_HTML_CHARACTER = SMALL_O_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_O_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small o circumflex accent html character. */
static char SMALL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '4', ';'};
static char* SMALL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small o tilde html character. */
static char SMALL_O_TILDE_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '5', ';'};
static char* SMALL_O_TILDE_HTML_CHARACTER = SMALL_O_TILDE_HTML_CHARACTER_ARRAY;
static int* SMALL_O_TILDE_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small o umlaut mark (dieresis) html character. */
static char SMALL_O_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '6', ';'};
static char* SMALL_O_UMLAUT_MARK_HTML_CHARACTER = SMALL_O_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* SMALL_O_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The division sign html character. */
static char DIVISION_SIGN_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '7', ';'};
static char* DIVISION_SIGN_HTML_CHARACTER = DIVISION_SIGN_HTML_CHARACTER_ARRAY;
static int* DIVISION_SIGN_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small o slash html character. */
static char SMALL_O_SLASH_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '8', ';'};
static char* SMALL_O_SLASH_HTML_CHARACTER = SMALL_O_SLASH_HTML_CHARACTER_ARRAY;
static int* SMALL_O_SLASH_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small u grave accent html character. */
static char SMALL_U_GRAVE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '4', '9', ';'};
static char* SMALL_U_GRAVE_ACCENT_HTML_CHARACTER = SMALL_U_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_U_GRAVE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small u acute accent html character. */
static char SMALL_U_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '5', '0', ';'};
static char* SMALL_U_ACUTE_ACCENT_HTML_CHARACTER = SMALL_U_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_U_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small u circumflex accent html character. */
static char SMALL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '5', '1', ';'};
static char* SMALL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small u umlaut mark (dieresis) html character. */
static char SMALL_U_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '5', '2', ';'};
static char* SMALL_U_UMLAUT_MARK_HTML_CHARACTER = SMALL_U_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* SMALL_U_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small y acute accent html character. */
static char SMALL_Y_ACUTE_ACCENT_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '5', '3', ';'};
static char* SMALL_Y_ACUTE_ACCENT_HTML_CHARACTER = SMALL_Y_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
static int* SMALL_Y_ACUTE_ACCENT_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small thorn icelandic html character. */
static char SMALL_THORN_ICELANDIC_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '5', '4', ';'};
static char* SMALL_THORN_ICELANDIC_HTML_CHARACTER = SMALL_THORN_ICELANDIC_HTML_CHARACTER_ARRAY;
static int* SMALL_THORN_ICELANDIC_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The small y umlaut mark (dieresis) html character. */
static char SMALL_Y_UMLAUT_MARK_HTML_CHARACTER_ARRAY[] = {'&', '#', '2', '5', '5', ';'};
static char* SMALL_Y_UMLAUT_MARK_HTML_CHARACTER = SMALL_Y_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
static int* SMALL_Y_UMLAUT_MARK_HTML_CHARACTER_COUNT = NUMBER_6_INTEGER_ARRAY;

/* HTML_CHARACTER_CONSTANTS_SOURCE */
#endif
