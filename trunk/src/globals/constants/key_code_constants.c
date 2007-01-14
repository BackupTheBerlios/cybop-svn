/*
 * $RCSfile: key_code_constants.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2007-01-14 22:06:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef KEY_CODE_CONSTANTS_SOURCE
#define KEY_CODE_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//?? Check out http://www.comptechdoc.org/os/linux/howlinuxworks/linux_hlkeycodes.html
//?? or google: linux keyboard terminal keycodes mapping table
//?? Linux kernel source: http://www.topology.org/linux/charpath.html

/** The escape key code. */
static int ESCAPE_KEY_CODE_ARRAY[] = {1};
static int* ESCAPE_KEY_CODE = ESCAPE_KEY_CODE_ARRAY;
static int* ESCAPE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The one key code. */
static int ONE_KEY_CODE_ARRAY[] = {2};
static int* ONE_KEY_CODE = ONE_KEY_CODE_ARRAY;
static int* ONE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The two key code. */
static int TWO_KEY_CODE_ARRAY[] = {3};
static int* TWO_KEY_CODE = TWO_KEY_CODE_ARRAY;
static int* TWO_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The three key code. */
static int THREE_KEY_CODE_ARRAY[] = {4};
static int* THREE_KEY_CODE = THREE_KEY_CODE_ARRAY;
static int* THREE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The four key code. */
static int FOUR_KEY_CODE_ARRAY[] = {5};
static int* FOUR_KEY_CODE = FOUR_KEY_CODE_ARRAY;
static int* FOUR_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The five key code. */
static int FIVE_KEY_CODE_ARRAY[] = {6};
static int* FIVE_KEY_CODE = FIVE_KEY_CODE_ARRAY;
static int* FIVE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The six key code. */
static int SIX_KEY_CODE_ARRAY[] = {7};
static int* SIX_KEY_CODE = SIX_KEY_CODE_ARRAY;
static int* SIX_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The seven key code. */
static int SEVEN_KEY_CODE_ARRAY[] = {8};
static int* SEVEN_KEY_CODE = SEVEN_KEY_CODE_ARRAY;
static int* SEVEN_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The eight key code. */
static int EIGHT_KEY_CODE_ARRAY[] = {9};
static int* EIGHT_KEY_CODE = EIGHT_KEY_CODE_ARRAY;
static int* EIGHT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The nine key code. */
static int NINE_KEY_CODE_ARRAY[] = {10};
static int* NINE_KEY_CODE = NINE_KEY_CODE_ARRAY;
static int* NINE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The zero key code. */
static int ZERO_KEY_CODE_ARRAY[] = {11};
static int* ZERO_KEY_CODE = ZERO_KEY_CODE_ARRAY;
static int* ZERO_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The minus key code. */
static int MINUS_KEY_CODE_ARRAY[] = {12};
static int* MINUS_KEY_CODE = MINUS_KEY_CODE_ARRAY;
static int* MINUS_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The equals key code. */
static int EQUALS_KEY_CODE_ARRAY[] = {13};
static int* EQUALS_KEY_CODE = EQUALS_KEY_CODE_ARRAY;
static int* EQUALS_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The backspace key code. */
static int BACKSPACE_KEY_CODE_ARRAY[] = {14};
static int* BACKSPACE_KEY_CODE = BACKSPACE_KEY_CODE_ARRAY;
static int* BACKSPACE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The tabulator key code. */
static int TABULATOR_KEY_CODE_ARRAY[] = {15};
static int* TABULATOR_KEY_CODE = TABULATOR_KEY_CODE_ARRAY;
static int* TABULATOR_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The q key code. */
static int Q_KEY_CODE_ARRAY[] = {16};
static int* Q_KEY_CODE = Q_KEY_CODE_ARRAY;
static int* Q_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The w key code. */
static int W_KEY_CODE_ARRAY[] = {17};
static int* W_KEY_CODE = W_KEY_CODE_ARRAY;
static int* W_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The e key code. */
static int E_KEY_CODE_ARRAY[] = {18};
static int* E_KEY_CODE = E_KEY_CODE_ARRAY;
static int* E_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The r key code. */
static int R_KEY_CODE_ARRAY[] = {19};
static int* R_KEY_CODE = R_KEY_CODE_ARRAY;
static int* R_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The t key code. */
static int T_KEY_CODE_ARRAY[] = {20};
static int* T_KEY_CODE = T_KEY_CODE_ARRAY;
static int* T_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The y key code. */
static int Y_KEY_CODE_ARRAY[] = {21};
static int* Y_KEY_CODE = Y_KEY_CODE_ARRAY;
static int* Y_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The u key code. */
static int U_KEY_CODE_ARRAY[] = {22};
static int* U_KEY_CODE = U_KEY_CODE_ARRAY;
static int* U_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The i key code. */
static int I_KEY_CODE_ARRAY[] = {23};
static int* I_KEY_CODE = I_KEY_CODE_ARRAY;
static int* I_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The o key code. */
static int O_KEY_CODE_ARRAY[] = {24};
static int* O_KEY_CODE = O_KEY_CODE_ARRAY;
static int* O_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The p key code. */
static int P_KEY_CODE_ARRAY[] = {25};
static int* P_KEY_CODE = P_KEY_CODE_ARRAY;
static int* P_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left square bracket key code. */
static int LEFT_SQUARE_KEY_CODE_ARRAY[] = {26};
static int* LEFT_SQUARE_KEY_CODE = LEFT_SQUARE_KEY_CODE_ARRAY;
static int* LEFT_SQUARE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right square bracket key code. */
static int RIGHT_SQUARE_KEY_CODE_ARRAY[] = {27};
static int* RIGHT_SQUARE_KEY_CODE = RIGHT_SQUARE_KEY_CODE_ARRAY;
static int* RIGHT_SQUARE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The enter key code. */
static int ENTER_KEY_CODE_ARRAY[] = {28};
static int* ENTER_KEY_CODE = ENTER_KEY_CODE_ARRAY;
static int* ENTER_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left control key code. */
static int LEFT_CONTROL_KEY_CODE_ARRAY[] = {29};
static int* LEFT_CONTROL_KEY_CODE = LEFT_CONTROL_KEY_CODE_ARRAY;
static int* LEFT_CONTROL_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The a key code. */
static int A_KEY_CODE_ARRAY[] = {30};
static int* A_KEY_CODE = A_KEY_CODE_ARRAY;
static int* A_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The s key code. */
static int S_KEY_CODE_ARRAY[] = {31};
static int* S_KEY_CODE = S_KEY_CODE_ARRAY;
static int* S_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The d key code. */
static int D_KEY_CODE_ARRAY[] = {32};
static int* D_KEY_CODE = D_KEY_CODE_ARRAY;
static int* D_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f key code. */
static int F_KEY_CODE_ARRAY[] = {33};
static int* F_KEY_CODE = F_KEY_CODE_ARRAY;
static int* F_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The g key code. */
static int G_KEY_CODE_ARRAY[] = {34};
static int* G_KEY_CODE = G_KEY_CODE_ARRAY;
static int* G_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The h key code. */
static int H_KEY_CODE_ARRAY[] = {35};
static int* H_KEY_CODE = H_KEY_CODE_ARRAY;
static int* H_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The j key code. */
static int J_KEY_CODE_ARRAY[] = {36};
static int* J_KEY_CODE = J_KEY_CODE_ARRAY;
static int* J_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The k key code. */
static int K_KEY_CODE_ARRAY[] = {37};
static int* K_KEY_CODE = K_KEY_CODE_ARRAY;
static int* K_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The l key code. */
static int L_KEY_CODE_ARRAY[] = {38};
static int* L_KEY_CODE = L_KEY_CODE_ARRAY;
static int* L_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The semicolon key code. */
static int SEMICOLON_KEY_CODE_ARRAY[] = {39};
static int* SEMICOLON_KEY_CODE = SEMICOLON_KEY_CODE_ARRAY;
static int* SEMICOLON_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The apostrophe key code. */
static int APOSTROPHE_KEY_CODE_ARRAY[] = {40};
static int* APOSTROPHE_KEY_CODE = APOSTROPHE_KEY_CODE_ARRAY;
static int* APOSTROPHE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The accent grave key code. */
static int ACCENT_GRAVE_KEY_CODE_ARRAY[] = {41};
static int* ACCENT_GRAVE_KEY_CODE = ACCENT_GRAVE_KEY_CODE_ARRAY;
static int* ACCENT_GRAVE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left shift key code. */
static int LEFT_SHIFT_KEY_CODE_ARRAY[] = {42};
static int* LEFT_SHIFT_KEY_CODE = LEFT_SHIFT_KEY_CODE_ARRAY;
static int* LEFT_SHIFT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The backslash key code. */
static int BACKSLASH_KEY_CODE_ARRAY[] = {43};
static int* BACKSLASH_KEY_CODE = BACKSLASH_KEY_CODE_ARRAY;
static int* BACKSLASH_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The z key code. */
static int Z_KEY_CODE_ARRAY[] = {44};
static int* Z_KEY_CODE = Z_KEY_CODE_ARRAY;
static int* Z_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The x key code. */
static int X_KEY_CODE_ARRAY[] = {45};
static int* X_KEY_CODE = X_KEY_CODE_ARRAY;
static int* X_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The c key code. */
static int C_KEY_CODE_ARRAY[] = {46};
static int* C_KEY_CODE = C_KEY_CODE_ARRAY;
static int* C_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The v key code. */
static int V_KEY_CODE_ARRAY[] = {47};
static int* V_KEY_CODE = V_KEY_CODE_ARRAY;
static int* V_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The b key code. */
static int B_KEY_CODE_ARRAY[] = {48};
static int* B_KEY_CODE = B_KEY_CODE_ARRAY;
static int* B_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The n key code. */
static int N_KEY_CODE_ARRAY[] = {49};
static int* N_KEY_CODE = N_KEY_CODE_ARRAY;
static int* N_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The m key code. */
static int M_KEY_CODE_ARRAY[] = {50};
static int* M_KEY_CODE = M_KEY_CODE_ARRAY;
static int* M_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The comma key code. */
static int COMMA_KEY_CODE_ARRAY[] = {51};
static int* COMMA_KEY_CODE = COMMA_KEY_CODE_ARRAY;
static int* COMMA_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The dot key code. */
static int DOT_KEY_CODE_ARRAY[] = {52};
static int* DOT_KEY_CODE = DOT_KEY_CODE_ARRAY;
static int* DOT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The slash key code. */
static int SLASH_KEY_CODE_ARRAY[] = {53};
static int* SLASH_KEY_CODE = SLASH_KEY_CODE_ARRAY;
static int* SLASH_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right shift key code. */
static int RIGHT_SHIFT_KEY_CODE_ARRAY[] = {54};
static int* RIGHT_SHIFT_KEY_CODE = RIGHT_SHIFT_KEY_CODE_ARRAY;
static int* RIGHT_SHIFT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The asterisk key code. */
static int ASTERISK_KEY_CODE_ARRAY[] = {55};
static int* ASTERISK_KEY_CODE = ASTERISK_KEY_CODE_ARRAY;
static int* ASTERISK_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left alt key code. */
static int LEFT_ALT_KEY_CODE_ARRAY[] = {56};
static int* LEFT_ALT_KEY_CODE = LEFT_ALT_KEY_CODE_ARRAY;
static int* LEFT_ALT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The space key code. */
static int SPACE_KEY_CODE_ARRAY[] = {57};
static int* SPACE_KEY_CODE = SPACE_KEY_CODE_ARRAY;
static int* SPACE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The capitals lock key code. */
static int CAPITALS_LOCK_KEY_CODE_ARRAY[] = {58};
static int* CAPITALS_LOCK_KEY_CODE = CAPITALS_LOCK_KEY_CODE_ARRAY;
static int* CAPITALS_LOCK_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f1 key code. */
static int F1_KEY_CODE_ARRAY[] = {59};
static int* F1_KEY_CODE = F1_KEY_CODE_ARRAY;
static int* F1_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f2 key code. */
static int F2_KEY_CODE_ARRAY[] = {60};
static int* F2_KEY_CODE = F2_KEY_CODE_ARRAY;
static int* F2_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f3 key code. */
static int F3_KEY_CODE_ARRAY[] = {61};
static int* F3_KEY_CODE = F3_KEY_CODE_ARRAY;
static int* F3_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f4 key code. */
static int F4_KEY_CODE_ARRAY[] = {62};
static int* F4_KEY_CODE = F4_KEY_CODE_ARRAY;
static int* F4_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f5 key code. */
static int F5_KEY_CODE_ARRAY[] = {63};
static int* F5_KEY_CODE = F5_KEY_CODE_ARRAY;
static int* F5_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f6 key code. */
static int F6_KEY_CODE_ARRAY[] = {64};
static int* F6_KEY_CODE = F6_KEY_CODE_ARRAY;
static int* F6_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f7 key code. */
static int F7_KEY_CODE_ARRAY[] = {65};
static int* F7_KEY_CODE = F7_KEY_CODE_ARRAY;
static int* F7_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f8 key code. */
static int F8_KEY_CODE_ARRAY[] = {66};
static int* F8_KEY_CODE = F8_KEY_CODE_ARRAY;
static int* F8_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f9 key code. */
static int F9_KEY_CODE_ARRAY[] = {67};
static int* F9_KEY_CODE = F9_KEY_CODE_ARRAY;
static int* F9_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f10 key code. */
static int F10_KEY_CODE_ARRAY[] = {68};
static int* F10_KEY_CODE = F10_KEY_CODE_ARRAY;
static int* F10_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric lock key code. */
static int NUMERIC_LOCK_KEY_CODE_ARRAY[] = {69};
static int* NUMERIC_LOCK_KEY_CODE = NUMERIC_LOCK_KEY_CODE_ARRAY;
static int* NUMERIC_LOCK_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The scroll lock key code. */
static int SCROLL_LOCK_KEY_CODE_ARRAY[] = {70};
static int* SCROLL_LOCK_KEY_CODE = SCROLL_LOCK_KEY_CODE_ARRAY;
static int* SCROLL_LOCK_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric home (seven) key code. */
static int NUMERIC_HOME_KEY_CODE_ARRAY[] = {71};
static int* NUMERIC_HOME_KEY_CODE = NUMERIC_HOME_KEY_CODE_ARRAY;
static int* NUMERIC_HOME_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric up (eight) key code. */
static int NUMERIC_UP_KEY_CODE_ARRAY[] = {72};
static int* NUMERIC_UP_KEY_CODE = NUMERIC_UP_KEY_CODE_ARRAY;
static int* NUMERIC_UP_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric page up (nine) key code. */
static int NUMERIC_PAGE_UP_KEY_CODE_ARRAY[] = {73};
static int* NUMERIC_PAGE_UP_KEY_CODE = NUMERIC_PAGE_UP_KEY_CODE_ARRAY;
static int* NUMERIC_PAGE_UP_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric minus key code. */
static int NUMERIC_MINUS_KEY_CODE_ARRAY[] = {74};
static int* NUMERIC_MINUS_KEY_CODE = NUMERIC_MINUS_KEY_CODE_ARRAY;
static int* NUMERIC_MINUS_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric left (four) key code. */
static int NUMERIC_LEFT_KEY_CODE_ARRAY[] = {75};
static int* NUMERIC_LEFT_KEY_CODE = NUMERIC_LEFT_KEY_CODE_ARRAY;
static int* NUMERIC_LEFT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric centre (five) key code. */
static int NUMERIC_CENTRE_KEY_CODE_ARRAY[] = {76};
static int* NUMERIC_CENTRE_KEY_CODE = NUMERIC_CENTRE_KEY_CODE_ARRAY;
static int* NUMERIC_CENTRE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric right (six) key code. */
static int NUMERIC_RIGHT_KEY_CODE_ARRAY[] = {77};
static int* NUMERIC_RIGHT_KEY_CODE = NUMERIC_RIGHT_KEY_CODE_ARRAY;
static int* NUMERIC_RIGHT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric plus key code. */
static int NUMERIC_PLUS_KEY_CODE_ARRAY[] = {78};
static int* NUMERIC_PLUS_KEY_CODE = NUMERIC_PLUS_KEY_CODE_ARRAY;
static int* NUMERIC_PLUS_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric end (one) key code. */
static int NUMERIC_END_KEY_CODE_ARRAY[] = {79};
static int* NUMERIC_END_KEY_CODE = NUMERIC_END_KEY_CODE_ARRAY;
static int* NUMERIC_END_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric down (two) key code. */
static int NUMERIC_DOWN_KEY_CODE_ARRAY[] = {80};
static int* NUMERIC_DOWN_KEY_CODE = NUMERIC_DOWN_KEY_CODE_ARRAY;
static int* NUMERIC_DOWN_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric page down (three) key code. */
static int NUMERIC_PAGE_DOWN_KEY_CODE_ARRAY[] = {81};
static int* NUMERIC_PAGE_DOWN_KEY_CODE = NUMERIC_PAGE_DOWN_KEY_CODE_ARRAY;
static int* NUMERIC_PAGE_DOWN_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric insert (zero) key code. */
static int NUMERIC_INSERT_KEY_CODE_ARRAY[] = {82};
static int* NUMERIC_INSERT_KEY_CODE = NUMERIC_INSERT_KEY_CODE_ARRAY;
static int* NUMERIC_INSERT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric delete (comma) key code. */
static int NUMERIC_DELETE_KEY_CODE_ARRAY[] = {83};
static int* NUMERIC_DELETE_KEY_CODE = NUMERIC_DELETE_KEY_CODE_ARRAY;
static int* NUMERIC_DELETE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_1_KEY_CODE_ARRAY[] = {84};
static int* UNKNOWN_1_KEY_CODE = UNKNOWN_1_KEY_CODE_ARRAY;
static int* UNKNOWN_1_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_2_KEY_CODE_ARRAY[] = {85};
static int* UNKNOWN_2_KEY_CODE = UNKNOWN_2_KEY_CODE_ARRAY;
static int* UNKNOWN_2_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_3_KEY_CODE_ARRAY[] = {86};
static int* UNKNOWN_3_KEY_CODE = UNKNOWN_3_KEY_CODE_ARRAY;
static int* UNKNOWN_3_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f11 key code. */
static int F11_KEY_CODE_ARRAY[] = {87};
static int* F11_KEY_CODE = F11_KEY_CODE_ARRAY;
static int* F11_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The f12 key code. */
static int F12_KEY_CODE_ARRAY[] = {88};
static int* F12_KEY_CODE = F12_KEY_CODE_ARRAY;
static int* F12_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_4_KEY_CODE_ARRAY[] = {89};
static int* UNKNOWN_4_KEY_CODE = UNKNOWN_4_KEY_CODE_ARRAY;
static int* UNKNOWN_4_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_5_KEY_CODE_ARRAY[] = {90};
static int* UNKNOWN_5_KEY_CODE = UNKNOWN_5_KEY_CODE_ARRAY;
static int* UNKNOWN_5_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_6_KEY_CODE_ARRAY[] = {91};
static int* UNKNOWN_6_KEY_CODE = UNKNOWN_6_KEY_CODE_ARRAY;
static int* UNKNOWN_6_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_7_KEY_CODE_ARRAY[] = {92};
static int* UNKNOWN_7_KEY_CODE = UNKNOWN_7_KEY_CODE_ARRAY;
static int* UNKNOWN_7_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_8_KEY_CODE_ARRAY[] = {93};
static int* UNKNOWN_8_KEY_CODE = UNKNOWN_8_KEY_CODE_ARRAY;
static int* UNKNOWN_8_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_9_KEY_CODE_ARRAY[] = {94};
static int* UNKNOWN_9_KEY_CODE = UNKNOWN_9_KEY_CODE_ARRAY;
static int* UNKNOWN_9_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_10_KEY_CODE_ARRAY[] = {95};
static int* UNKNOWN_10_KEY_CODE = UNKNOWN_10_KEY_CODE_ARRAY;
static int* UNKNOWN_10_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric enter key code. */
static int NUMERIC_ENTER_KEY_CODE_ARRAY[] = {96};
static int* NUMERIC_ENTER_KEY_CODE = NUMERIC_ENTER_KEY_CODE_ARRAY;
static int* NUMERIC_ENTER_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right control key code. */
static int RIGHT_CONTROL_KEY_CODE_ARRAY[] = {97};
static int* RIGHT_CONTROL_KEY_CODE = RIGHT_CONTROL_KEY_CODE_ARRAY;
static int* RIGHT_CONTROL_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The numeric slash key code. */
static int NUMERIC_SLASH_KEY_CODE_ARRAY[] = {98};
static int* NUMERIC_SLASH_KEY_CODE = NUMERIC_SLASH_KEY_CODE_ARRAY;
static int* NUMERIC_SLASH_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The print key code. */
static int PRINT_KEY_CODE_ARRAY[] = {99};
static int* PRINT_KEY_CODE = PRINT_KEY_CODE_ARRAY;
static int* PRINT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right alt key code. */
static int RIGHT_ALT_KEY_CODE_ARRAY[] = {100};
static int* RIGHT_ALT_KEY_CODE = RIGHT_ALT_KEY_CODE_ARRAY;
static int* RIGHT_ALT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_11_KEY_CODE_ARRAY[] = {101};
static int* UNKNOWN_11_KEY_CODE = UNKNOWN_11_KEY_CODE_ARRAY;
static int* UNKNOWN_11_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The home key code. */
static int HOME_KEY_CODE_ARRAY[] = {102};
static int* HOME_KEY_CODE = HOME_KEY_CODE_ARRAY;
static int* HOME_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The up key code. */
static int UP_KEY_CODE_ARRAY[] = {103};
static int* UP_KEY_CODE = UP_KEY_CODE_ARRAY;
static int* UP_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The page up key code. */
static int PAGE_UP_KEY_CODE_ARRAY[] = {104};
static int* PAGE_UP_KEY_CODE = PAGE_UP_KEY_CODE_ARRAY;
static int* PAGE_UP_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The left key code. */
static int LEFT_KEY_CODE_ARRAY[] = {105};
static int* LEFT_KEY_CODE = LEFT_KEY_CODE_ARRAY;
static int* LEFT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The right key code. */
static int RIGHT_KEY_CODE_ARRAY[] = {106};
static int* RIGHT_KEY_CODE = RIGHT_KEY_CODE_ARRAY;
static int* RIGHT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end key code. */
static int END_KEY_CODE_ARRAY[] = {107};
static int* END_KEY_CODE = END_KEY_CODE_ARRAY;
static int* END_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The down key code. */
static int DOWN_KEY_CODE_ARRAY[] = {108};
static int* DOWN_KEY_CODE = DOWN_KEY_CODE_ARRAY;
static int* DOWN_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The page down key code. */
static int PAGE_DOWN_KEY_CODE_ARRAY[] = {109};
static int* PAGE_DOWN_KEY_CODE = PAGE_DOWN_KEY_CODE_ARRAY;
static int* PAGE_DOWN_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The insert key code. */
static int INSERT_KEY_CODE_ARRAY[] = {110};
static int* INSERT_KEY_CODE = INSERT_KEY_CODE_ARRAY;
static int* INSERT_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The delete key code. */
static int DELETE_KEY_CODE_ARRAY[] = {111};
static int* DELETE_KEY_CODE = DELETE_KEY_CODE_ARRAY;
static int* DELETE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_12_KEY_CODE_ARRAY[] = {112};
static int* UNKNOWN_12_KEY_CODE = UNKNOWN_12_KEY_CODE_ARRAY;
static int* UNKNOWN_12_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_13_KEY_CODE_ARRAY[] = {113};
static int* UNKNOWN_13_KEY_CODE = UNKNOWN_13_KEY_CODE_ARRAY;
static int* UNKNOWN_13_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_14_KEY_CODE_ARRAY[] = {114};
static int* UNKNOWN_14_KEY_CODE = UNKNOWN_14_KEY_CODE_ARRAY;
static int* UNKNOWN_14_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_15_KEY_CODE_ARRAY[] = {115};
static int* UNKNOWN_15_KEY_CODE = UNKNOWN_15_KEY_CODE_ARRAY;
static int* UNKNOWN_15_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_16_KEY_CODE_ARRAY[] = {116};
static int* UNKNOWN_16_KEY_CODE = UNKNOWN_16_KEY_CODE_ARRAY;
static int* UNKNOWN_16_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_17_KEY_CODE_ARRAY[] = {117};
static int* UNKNOWN_17_KEY_CODE = UNKNOWN_17_KEY_CODE_ARRAY;
static int* UNKNOWN_17_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The ?? key code. */
static int UNKNOWN_18_KEY_CODE_ARRAY[] = {118};
static int* UNKNOWN_18_KEY_CODE = UNKNOWN_18_KEY_CODE_ARRAY;
static int* UNKNOWN_18_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The pause key code. */
static int PAUSE_KEY_CODE_ARRAY[] = {119};
static int* PAUSE_KEY_CODE = PAUSE_KEY_CODE_ARRAY;
static int* PAUSE_KEY_CODE_COUNT = NUMBER_1_INTEGER_ARRAY;

/* KEY_CODE_CONSTANTS_SOURCE */
#endif
