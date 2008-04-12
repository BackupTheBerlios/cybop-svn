/*
 * $RCSfile: cybol_name_constants.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2008-04-12 17:03:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_NAME_CONSTANTS_SOURCE
#define CYBOL_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// General cybol names.
//

/** The super properties name. */
static char SUPER_PROPERTIES_NAME_ARRAY[] = {'s', 'u', 'p', 'e', 'r'};
static char* SUPER_PROPERTIES_NAME = SUPER_PROPERTIES_NAME_ARRAY;
static int* SUPER_PROPERTIES_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// User interface (ui) names.
//

/** The shape name. */
static char UI_SHAPE_NAME_ARRAY[] = {'s', 'h', 'a', 'p', 'e'};
static char* UI_SHAPE_NAME = UI_SHAPE_NAME_ARRAY;
static int* UI_SHAPE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The layout name. */
static char UI_LAYOUT_NAME_ARRAY[] = {'l', 'a', 'y', 'o', 'u', 't'};
static char* UI_LAYOUT_NAME = UI_LAYOUT_NAME_ARRAY;
static int* UI_LAYOUT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The cell name. */
static char UI_CELL_NAME_ARRAY[] = {'c', 'e', 'l', 'l'};
static char* UI_CELL_NAME = UI_CELL_NAME_ARRAY;
static int* UI_CELL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The position name. */
static char UI_POSITION_NAME_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n'};
static char* UI_POSITION_NAME = UI_POSITION_NAME_ARRAY;
static int* UI_POSITION_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The size name. */
static char UI_SIZE_NAME_ARRAY[] = {'s', 'i', 'z', 'e'};
static char* UI_SIZE_NAME = UI_SIZE_NAME_ARRAY;
static int* UI_SIZE_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The background colour name. */
static char UI_BACKGROUND_NAME_ARRAY[] = {'b', 'a', 'c', 'k', 'g', 'r', 'o', 'u', 'n', 'd'};
static char* UI_BACKGROUND_NAME = UI_BACKGROUND_NAME_ARRAY;
static int* UI_BACKGROUND_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The foreground colour name. */
static char UI_FOREGROUND_NAME_ARRAY[] = {'f', 'o', 'r', 'e', 'g', 'r', 'o', 'u', 'n', 'd'};
static char* UI_FOREGROUND_NAME = UI_FOREGROUND_NAME_ARRAY;
static int* UI_FOREGROUND_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

//
// User interface (ui) input names.
//

/** The enter name. */
static char UI_ENTER_NAME_ARRAY[] = {'e', 'n', 't', 'e', 'r'};
static char* UI_ENTER_NAME = UI_ENTER_NAME_ARRAY;
static int* UI_ENTER_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The escape name. */
static char UI_ESCAPE_NAME_ARRAY[] = {'e', 's', 'c', 'a', 'p', 'e'};
static char* UI_ESCAPE_NAME = UI_ESCAPE_NAME_ARRAY;
static int* UI_ESCAPE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The arrow up name. */
static char UI_ARROW_UP_NAME_ARRAY[] = {'a', 'r', 'r', 'o', 'w', '_', 'u', 'p'};
static char* UI_ARROW_UP_NAME = UI_ARROW_UP_NAME_ARRAY;
static int* UI_ARROW_UP_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The arrow down name. */
static char UI_ARROW_DOWN_NAME_ARRAY[] = {'a', 'r', 'r', 'o', 'w', '_', 'd', 'o', 'w', 'n'};
static char* UI_ARROW_DOWN_NAME = UI_ARROW_DOWN_NAME_ARRAY;
static int* UI_ARROW_DOWN_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The arrow left name. */
static char UI_ARROW_LEFT_NAME_ARRAY[] = {'a', 'r', 'r', 'o', 'w', '_', 'l', 'e', 'f', 't'};
static char* UI_ARROW_LEFT_NAME = UI_ARROW_LEFT_NAME_ARRAY;
static int* UI_ARROW_LEFT_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The arrow right name. */
static char UI_ARROW_RIGHT_NAME_ARRAY[] = {'a', 'r', 'r', 'o', 'w', '_', 'r', 'i', 'g', 'h', 't'};
static char* UI_ARROW_RIGHT_NAME = UI_ARROW_RIGHT_NAME_ARRAY;
static int* UI_ARROW_RIGHT_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Textual user interface (tui) names.
//

/** The border name. */
static char TUI_BORDER_NAME_ARRAY[] = {'b', 'o', 'r', 'd', 'e', 'r'};
static char* TUI_BORDER_NAME = TUI_BORDER_NAME_ARRAY;
static int* TUI_BORDER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The hidden property name. */
static char TUI_HIDDEN_NAME_ARRAY[] = {'h', 'i', 'd', 'd', 'e', 'n'};
static char* TUI_HIDDEN_NAME = TUI_HIDDEN_NAME_ARRAY;
static int* TUI_HIDDEN_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The inverse property name. */
static char TUI_INVERSE_NAME_ARRAY[] = {'i', 'n', 'v', 'e', 'r', 's', 'e'};
static char* TUI_INVERSE_NAME = TUI_INVERSE_NAME_ARRAY;
static int* TUI_INVERSE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The blink property name. */
static char TUI_BLINK_NAME_ARRAY[] = {'b', 'l', 'i', 'n', 'k'};
static char* TUI_BLINK_NAME = TUI_BLINK_NAME_ARRAY;
static int* TUI_BLINK_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The underline property name. */
static char TUI_UNDERLINE_NAME_ARRAY[] = {'u', 'n', 'd', 'e', 'r', 'l', 'i', 'n', 'e'};
static char* TUI_UNDERLINE_NAME = TUI_UNDERLINE_NAME_ARRAY;
static int* TUI_UNDERLINE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The bold property name. */
static char TUI_BOLD_NAME_ARRAY[] = {'b', 'o', 'l', 'd'};
static char* TUI_BOLD_NAME = TUI_BOLD_NAME_ARRAY;
static int* TUI_BOLD_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Graphical user interface (gui) names.
//

/** The title name. */
static char GUI_TITLE_NAME_ARRAY[] = {'t', 'i', 't', 'l', 'e'};
static char* GUI_TITLE_NAME = GUI_TITLE_NAME_ARRAY;
static int* GUI_TITLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The icon name. */
static char GUI_ICON_NAME_ARRAY[] = {'i', 'c', 'o', 'n'};
static char* GUI_ICON_NAME = GUI_ICON_NAME_ARRAY;
static int* GUI_ICON_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The expose command name. */
static char GUI_EXPOSE_COMMAND_NAME_ARRAY[] = {'e', 'x', 'p', 'o', 's', 'e'};
static char* GUI_EXPOSE_COMMAND_NAME = GUI_EXPOSE_COMMAND_NAME_ARRAY;
static int* GUI_EXPOSE_COMMAND_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The left mouse button press command name. */
static char GUI_LEFT_PRESS_COMMAND_NAME_ARRAY[] = {'l', 'e', 'f', 't', '_', 'p', 'r', 'e', 's', 's'};
static char* GUI_LEFT_PRESS_COMMAND_NAME = GUI_LEFT_PRESS_COMMAND_NAME_ARRAY;
static int* GUI_LEFT_PRESS_COMMAND_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The left mouse button release command name. */
static char GUI_LEFT_RELEASE_COMMAND_NAME_ARRAY[] = {'l', 'e', 'f', 't', '_', 'r', 'e', 'l', 'e', 'a', 's', 'e'};
static char* GUI_LEFT_RELEASE_COMMAND_NAME = GUI_LEFT_RELEASE_COMMAND_NAME_ARRAY;
static int* GUI_LEFT_RELEASE_COMMAND_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

//
// Web user interface (wui) tag names.
//

/** The tag name. */
static char WUI_TAG_NAME_ARRAY[] = {'t', 'a', 'g'};
static char* WUI_TAG_NAME = WUI_TAG_NAME_ARRAY;
static int* WUI_TAG_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The property name. */
static char WUI_PROPERTY_NAME_ARRAY[] = {'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static char* WUI_PROPERTY_NAME = WUI_PROPERTY_NAME_ARRAY;
static int* WUI_PROPERTY_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Web user interface (wui) attribute names.
//

/** The align attribute name. */
/*??
static char WUI_ALIGN_ATTRIBUTE_NAME_ARRAY[] = {'a', 'l', 'i', 'g', 'n'};
static char* WUI_ALIGN_ATTRIBUTE_NAME = WUI_ALIGN_ATTRIBUTE_NAME_ARRAY;
static int* WUI_ALIGN_ATTRIBUTE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;
*/

//
// Boolean names.
//

/** The input 1 name. */
static char INPUT_1_NAME_ARRAY[] = {'i', 'n', 'p', 'u', 't', '_', '1'};
static char* INPUT_1_NAME = INPUT_1_NAME_ARRAY;
static int* INPUT_1_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The input 2 name. */
static char INPUT_2_NAME_ARRAY[] = {'i', 'n', 'p', 'u', 't', '_', '2'};
static char* INPUT_2_NAME = INPUT_2_NAME_ARRAY;
static int* INPUT_2_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The output name. */
static char OUTPUT_NAME_ARRAY[] = {'o', 'u', 't', 'p', 'u', 't'};
static char* OUTPUT_NAME = OUTPUT_NAME_ARRAY;
static int* OUTPUT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Compare names.
//

/** The comparison name. */
static char COMPARISON_NAME_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n'};
static char* COMPARISON_NAME = COMPARISON_NAME_ARRAY;
static int* COMPARISON_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The left side name. */
static char LEFT_SIDE_NAME_ARRAY[] = {'l', 'e', 'f', 't'};
static char* LEFT_SIDE_NAME = LEFT_SIDE_NAME_ARRAY;
static int* LEFT_SIDE_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The right side name. */
static char RIGHT_SIDE_NAME_ARRAY[] = {'r', 'i', 'g', 'h', 't'};
static char* RIGHT_SIDE_NAME = RIGHT_SIDE_NAME_ARRAY;
static int* RIGHT_SIDE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The result name. */
static char RESULT_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static char* RESULT_NAME = RESULT_NAME_ARRAY;
static int* RESULT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Arithmetic names.
//

/** The operand 1 name. */
/*??
static char OPERAND_1_NAME_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '1'};
static char* OPERAND_1_NAME = OPERAND_1_NAME_ARRAY;
static int* OPERAND_1_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;
*/

/** The operand 2 name. */
/*??
static char OPERAND_2_NAME_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '2'};
static char* OPERAND_2_NAME = OPERAND_2_NAME_ARRAY;
static int* OPERAND_2_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;
*/

/** The result operand name. */
/*??
static char RESULT_OPERAND_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static char* RESULT_OPERAND_NAME = RESULT_OPERAND_NAME_ARRAY;
static int* RESULT_OPERAND_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;
*/

//
// Add names.
//

/** The add summand 1 name. */
static char ADD_SUMMAND_1_NAME_ARRAY[] = {'s', 'u', 'm', 'm', 'a', 'n', 'd', '_', '1'};
static char* ADD_SUMMAND_1_NAME = ADD_SUMMAND_1_NAME_ARRAY;
static int* ADD_SUMMAND_1_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The add summand 2 name. */
static char ADD_SUMMAND_2_NAME_ARRAY[] = {'s', 'u', 'm', 'm', 'a', 'n', 'd', '_', '2'};
static char* ADD_SUMMAND_2_NAME = ADD_SUMMAND_2_NAME_ARRAY;
static int* ADD_SUMMAND_2_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The add sum name. */
static char ADD_SUM_NAME_ARRAY[] = {'s', 'u', 'm'};
static char* ADD_SUM_NAME = ADD_SUM_NAME_ARRAY;
static int* ADD_SUM_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Copy and move names.
//

/** The copy source name. */
static char COPY_SOURCE_NAME_ARRAY[] = {'s', 'o', 'u', 'r', 'c', 'e'};
static char* COPY_SOURCE_NAME = COPY_SOURCE_NAME_ARRAY;
static int* COPY_SOURCE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copy destination name. */
static char COPY_DESTINATION_NAME_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
static char* COPY_DESTINATION_NAME = COPY_DESTINATION_NAME_ARRAY;
static int* COPY_DESTINATION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The copy abstraction name. */
static char COPY_ABSTRACTION_NAME_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* COPY_ABSTRACTION_NAME = COPY_ABSTRACTION_NAME_ARRAY;
static int* COPY_ABSTRACTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Branch names.
//

/** The criterion name. */
static char CRITERION_NAME_ARRAY[] = {'c', 'r', 'i', 't', 'e', 'r', 'i', 'o', 'n'};
static char* CRITERION_NAME = CRITERION_NAME_ARRAY;
static int* CRITERION_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The true model name. */
static char TRUE_MODEL_NAME_ARRAY[] = {'t', 'r', 'u', 'e'};
static char* TRUE_MODEL_NAME = TRUE_MODEL_NAME_ARRAY;
static int* TRUE_MODEL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The false model name. */
static char FALSE_MODEL_NAME_ARRAY[] = {'f', 'a', 'l', 's', 'e'};
static char* FALSE_MODEL_NAME = FALSE_MODEL_NAME_ARRAY;
static int* FALSE_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Loop names.
//

/** The break flag name. */
static char BREAK_FLAG_NAME_ARRAY[] = {'b', 'r', 'e', 'a', 'k'};
static char* BREAK_FLAG_NAME = BREAK_FLAG_NAME_ARRAY;
static int* BREAK_FLAG_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The loop model name. */
static char LOOP_MODEL_NAME_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* LOOP_MODEL_NAME = LOOP_MODEL_NAME_ARRAY;
static int* LOOP_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Build listname names.
//

/** The base name name. */
static char BASE_NAME_NAME_ARRAY[] = {'b', 'a', 's', 'e'};
static char* BASE_NAME_NAME = BASE_NAME_NAME_ARRAY;
static int* BASE_NAME_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The index name name. */
static char INDEX_NAME_NAME_ARRAY[] = {'i', 'n', 'd', 'e', 'x'};
static char* INDEX_NAME_NAME = INDEX_NAME_NAME_ARRAY;
static int* INDEX_NAME_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The composed name name. */
static char COMPOSED_NAME_NAME_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 's', 'e', 'd'};
static char* COMPOSED_NAME_NAME = COMPOSED_NAME_NAME_ARRAY;
static int* COMPOSED_NAME_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Count names.
//

/** The count compound name. */
static char COUNT_COMPOUND_NAME_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};
static char* COUNT_COMPOUND_NAME = COUNT_COMPOUND_NAME_ARRAY;
static int* COUNT_COMPOUND_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The count selection name. */
static char COUNT_SELECTION_NAME_ARRAY[] = {'s', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n'};
static char* COUNT_SELECTION_NAME = COUNT_SELECTION_NAME_ARRAY;
static int* COUNT_SELECTION_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The count filter name. */
static char COUNT_FILTER_NAME_ARRAY[] = {'f', 'i', 'l', 't', 'e', 'r'};
static char* COUNT_FILTER_NAME = COUNT_FILTER_NAME_ARRAY;
static int* COUNT_FILTER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The count result name. */
static char COUNT_RESULT_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static char* COUNT_RESULT_NAME = COUNT_RESULT_NAME_ARRAY;
static int* COUNT_RESULT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Get names.
//

/** The get compound name. */
static char GET_COMPOUND_NAME_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};
static char* GET_COMPOUND_NAME = GET_COMPOUND_NAME_ARRAY;
static int* GET_COMPOUND_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The get index name. */
static char GET_INDEX_NAME_ARRAY[] = {'i', 'n', 'd', 'e', 'x'};
static char* GET_INDEX_NAME = GET_INDEX_NAME_ARRAY;
static int* GET_INDEX_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The get description name. */
static char GET_DESCRIPTION_NAME_ARRAY[] = {'d', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n'};
static char* GET_DESCRIPTION_NAME = GET_DESCRIPTION_NAME_ARRAY;
static int* GET_DESCRIPTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The get result name. */
static char GET_RESULT_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static char* GET_RESULT_NAME = GET_RESULT_NAME_ARRAY;
static int* GET_RESULT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Create names.
//

/** The create name name. */
static char CREATE_NAME_NAME_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* CREATE_NAME_NAME = CREATE_NAME_NAME_ARRAY;
static int* CREATE_NAME_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The create abstraction name. */
static char CREATE_ABSTRACTION_NAME_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* CREATE_ABSTRACTION_NAME = CREATE_ABSTRACTION_NAME_ARRAY;
static int* CREATE_ABSTRACTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The create element name. */
static char CREATE_ELEMENT_NAME_ARRAY[] = {'e', 'l', 'e', 'm', 'e', 'n', 't'};
static char* CREATE_ELEMENT_NAME = CREATE_ELEMENT_NAME_ARRAY;
static int* CREATE_ELEMENT_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The create whole name. */
static char CREATE_WHOLE_NAME_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static char* CREATE_WHOLE_NAME = CREATE_WHOLE_NAME_ARRAY;
static int* CREATE_WHOLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Destroy names.
//

/** The destroy model. */
static char DESTROY_MODEL_NAME_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* DESTROY_MODEL_NAME = DESTROY_MODEL_NAME_ARRAY;
static int* DESTROY_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Startup and shutdown service names.
//

/** The service name. */
static char SERVICE_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e'};
static char* SERVICE_NAME = SERVICE_NAME_ARRAY;
static int* SERVICE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The service namespace name. */
static char SERVICE_NAMESPACE_NAME_ARRAY[] = {'n', 'a', 'm', 'e', 's', 'p', 'a', 'c', 'e'};
static char* SERVICE_NAMESPACE_NAME = SERVICE_NAMESPACE_NAME_ARRAY;
static int* SERVICE_NAMESPACE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The service style name. */
static char SERVICE_STYLE_NAME_ARRAY[] = {'s', 't', 'y', 'l', 'e'};
static char* SERVICE_STYLE_NAME = SERVICE_STYLE_NAME_ARRAY;
static int* SERVICE_STYLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The service address name. */
static char SERVICE_ADDRESS_NAME_ARRAY[] = {'a', 'd', 'd', 'r', 'e', 's', 's'};
static char* SERVICE_ADDRESS_NAME = SERVICE_ADDRESS_NAME_ARRAY;
static int* SERVICE_ADDRESS_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Send names.
//

/** The send channel name. */
static char SEND_CHANNEL_NAME_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* SEND_CHANNEL_NAME = SEND_CHANNEL_NAME_ARRAY;
static int* SEND_CHANNEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The send language name. */
static char SEND_LANGUAGE_NAME_ARRAY[] = {'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static char* SEND_LANGUAGE_NAME = SEND_LANGUAGE_NAME_ARRAY;
static int* SEND_LANGUAGE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The send communication mode name. */
static char SEND_COMMUNICATION_MODE_NAME_ARRAY[] = {'m', 'o', 'd', 'e'};
static char* SEND_COMMUNICATION_MODE_NAME = SEND_COMMUNICATION_MODE_NAME_ARRAY;
static int* SEND_COMMUNICATION_MODE_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The send socket namespace name. */
static char SEND_NAMESPACE_NAME_ARRAY[] = {'n', 'a', 'm', 'e', 's', 'p', 'a', 'c', 'e'};
static char* SEND_NAMESPACE_NAME = SEND_NAMESPACE_NAME_ARRAY;
static int* SEND_NAMESPACE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The send communication style name. */
static char SEND_STYLE_NAME_ARRAY[] = {'s', 't', 'y', 'l', 'e'};
static char* SEND_STYLE_NAME = SEND_STYLE_NAME_ARRAY;
static int* SEND_STYLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The send sender name. */
static char SEND_SENDER_NAME_ARRAY[] = {'s', 'e', 'n', 'd', 'e', 'r'};
static char* SEND_SENDER_NAME = SEND_SENDER_NAME_ARRAY;
static int* SEND_SENDER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The send receiver name. */
static char SEND_RECEIVER_NAME_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r'};
static char* SEND_RECEIVER_NAME = SEND_RECEIVER_NAME_ARRAY;
static int* SEND_RECEIVER_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The send message name. */
static char SEND_MESSAGE_NAME_ARRAY[] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
static char* SEND_MESSAGE_NAME = SEND_MESSAGE_NAME_ARRAY;
static int* SEND_MESSAGE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The send area name. */
static char SEND_AREA_NAME_ARRAY[] = {'a', 'r', 'e', 'a'};
static char* SEND_AREA_NAME = SEND_AREA_NAME_ARRAY;
static int* SEND_AREA_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The send clean name. */
static char SEND_CLEAN_NAME_ARRAY[] = {'c', 'l', 'e', 'a', 'n'};
static char* SEND_CLEAN_NAME = SEND_CLEAN_NAME_ARRAY;
static int* SEND_CLEAN_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The send new line name. */
static char SEND_NEW_LINE_NAME_ARRAY[] = {'n', 'e', 'w', '_', 'l', 'i', 'n', 'e'};
static char* SEND_NEW_LINE_NAME = SEND_NEW_LINE_NAME_ARRAY;
static int* SEND_NEW_LINE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The send url name. */
/*??
static char SEND_URL_NAME_ARRAY[] = {'u', 'r', 'l'};
static char* SEND_URL_NAME = SEND_URL_NAME_ARRAY;
static int* SEND_URL_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;
*/

//
// Receive names.
//

/** The receive channel name. */
static char RECEIVE_CHANNEL_NAME_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* RECEIVE_CHANNEL_NAME = RECEIVE_CHANNEL_NAME_ARRAY;
static int* RECEIVE_CHANNEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The receive handler name. */
static char RECEIVE_HANDLER_NAME_ARRAY[] = {'h', 'a', 'n', 'd', 'l', 'e', 'r'};
static char* RECEIVE_HANDLER_NAME = RECEIVE_HANDLER_NAME_ARRAY;
static int* RECEIVE_HANDLER_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The receive language name. */
static char RECEIVE_LANGUAGE_NAME_ARRAY[] = {'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static char* RECEIVE_LANGUAGE_NAME = RECEIVE_LANGUAGE_NAME_ARRAY;
static int* RECEIVE_LANGUAGE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The receive message name. */
static char RECEIVE_MESSAGE_NAME_ARRAY[] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
static char* RECEIVE_MESSAGE_NAME = RECEIVE_MESSAGE_NAME_ARRAY;
static int* RECEIVE_MESSAGE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The receive meta name. */
static char RECEIVE_META_NAME_ARRAY[] = {'m', 'e', 't', 'a'};
static char* RECEIVE_META_NAME = RECEIVE_META_NAME_ARRAY;
static int* RECEIVE_META_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The receive model name. */
static char RECEIVE_MODEL_NAME_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* RECEIVE_MODEL_NAME = RECEIVE_MODEL_NAME_ARRAY;
static int* RECEIVE_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The receive root name. */
static char RECEIVE_ROOT_NAME_ARRAY[] = {'r', 'o', 'o', 't'};
static char* RECEIVE_ROOT_NAME = RECEIVE_ROOT_NAME_ARRAY;
static int* RECEIVE_ROOT_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The receive style name. */
static char RECEIVE_STYLE_NAME_ARRAY[] = {'s', 't', 'y', 'l', 'e'};
static char* RECEIVE_STYLE_NAME = RECEIVE_STYLE_NAME_ARRAY;
static int* RECEIVE_STYLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The receive commands name. */
static char RECEIVE_COMMANDS_NAME_ARRAY[] = {'c', 'o', 'm', 'm', 'a', 'n', 'd', 's'};
static char* RECEIVE_COMMANDS_NAME = RECEIVE_COMMANDS_NAME_ARRAY;
static int* RECEIVE_COMMANDS_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The receive blocking name. */
static char RECEIVE_BLOCKING_NAME_ARRAY[] = {'b', 'l', 'o', 'c', 'k', 'i', 'n', 'g'};
static char* RECEIVE_BLOCKING_NAME = RECEIVE_BLOCKING_NAME_ARRAY;
static int* RECEIVE_BLOCKING_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Run names.
//

/** The command name. */
static char RUN_COMMAND_NAME_ARRAY[] = {'c', 'o', 'm', 'm', 'a', 'n', 'd'};
static char* RUN_COMMAND_NAME = RUN_COMMAND_NAME_ARRAY;
static int* RUN_COMMAND_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The archive create name. */
static char RUN_ARCHIVE_CREATE_NAME_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e'};
static char* RUN_ARCHIVE_CREATE_NAME = RUN_ARCHIVE_CREATE_NAME_ARRAY;
static int* RUN_ARCHIVE_CREATE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive update name. */
static char RUN_ARCHIVE_UPDATE_NAME_ARRAY[] = {'u', 'p', 'd', 'a', 't', 'e'};
static char* RUN_ARCHIVE_UPDATE_NAME = RUN_ARCHIVE_UPDATE_NAME_ARRAY;
static int* RUN_ARCHIVE_UPDATE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive bzip2 name. */
static char RUN_ARCHIVE_BZIP2_NAME_ARRAY[] = {'b', 'z', 'i', 'p', '2'};
static char* RUN_ARCHIVE_BZIP2_NAME = RUN_ARCHIVE_BZIP2_NAME_ARRAY;
static int* RUN_ARCHIVE_BZIP2_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The copy recursive name. */
static char RUN_COPY_RECURSIVE_NAME_ARRAY[] = {'r', 'e', 'c', 'u', 'r', 's', 'i', 'v', 'e'};
static char* RUN_COPY_RECURSIVE_NAME = RUN_COPY_RECURSIVE_NAME_ARRAY;
static int* RUN_COPY_RECURSIVE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The copy source name. */
static char RUN_COPY_SOURCE_NAME_ARRAY[] = {'s', 'o', 'u', 'r', 'c', 'e'};
static char* RUN_COPY_SOURCE_NAME = RUN_COPY_SOURCE_NAME_ARRAY;
static int* RUN_COPY_SOURCE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copy destination name. */
static char RUN_COPY_DESTINATION_NAME_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
static char* RUN_COPY_DESTINATION_NAME = RUN_COPY_DESTINATION_NAME_ARRAY;
static int* RUN_COPY_DESTINATION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The list directory contents all name. */
static char RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_ARRAY[] = {'a', 'l', 'l'};
static char* RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME = RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_ARRAY;
static int* RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The list directory contents long listing name. */
static char RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_ARRAY[] = {'l', 'o', 'n', 'g', '_', 'l', 'i', 's', 't', 'i', 'n', 'g'};
static char* RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME = RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_ARRAY;
static int* RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The program program name. */
static char RUN_PROGRAM_PROGRAM_NAME_ARRAY[] = {'p', 'r', 'o', 'g', 'r', 'a', 'm'};
static char* RUN_PROGRAM_PROGRAM_NAME = RUN_PROGRAM_PROGRAM_NAME_ARRAY;
static int* RUN_PROGRAM_PROGRAM_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Sense model names.
//

/** The sense model method name. */
static char SENSE_MODEL_METHOD_NAME_ARRAY[] = {'m', 'e', 't', 'h', 'o', 'd'};
static char* SENSE_MODEL_METHOD_NAME = SENSE_MODEL_METHOD_NAME_ARRAY;
static int* SENSE_MODEL_METHOD_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The sense model scheme name. */
static char SENSE_MODEL_SCHEME_NAME_ARRAY[] = {'s', 'c', 'h', 'e', 'm', 'e'};
static char* SENSE_MODEL_SCHEME_NAME = SENSE_MODEL_SCHEME_NAME_ARRAY;
static int* SENSE_MODEL_SCHEME_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The sense model authority name. */
static char SENSE_MODEL_AUTHORITY_NAME_ARRAY[] = {'a', 'u', 't', 'h', 'o', 'r', 'i', 't', 'y'};
static char* SENSE_MODEL_AUTHORITY_NAME = SENSE_MODEL_AUTHORITY_NAME_ARRAY;
static int* SENSE_MODEL_AUTHORITY_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The sense model path name. */
static char SENSE_MODEL_PATH_NAME_ARRAY[] = {'p', 'a', 't', 'h'};
static char* SENSE_MODEL_PATH_NAME = SENSE_MODEL_PATH_NAME_ARRAY;
static int* SENSE_MODEL_PATH_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The sense model fragment name. */
static char SENSE_MODEL_FRAGMENT_NAME_ARRAY[] = {'f', 'r', 'a', 'g', 'm', 'e', 'n', 't'};
static char* SENSE_MODEL_FRAGMENT_NAME = SENSE_MODEL_FRAGMENT_NAME_ARRAY;
static int* SENSE_MODEL_FRAGMENT_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The sense model action name. */
static char SENSE_MODEL_ACTION_NAME_ARRAY[] = {'a', 'c', 't', 'i', 'o', 'n'};
static char* SENSE_MODEL_ACTION_NAME = SENSE_MODEL_ACTION_NAME_ARRAY;
static int* SENSE_MODEL_ACTION_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/* CYBOL_NAME_CONSTANTS_SOURCE */
#endif
