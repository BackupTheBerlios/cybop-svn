/*
 * $RCSfile: cybol_name_constants.c,v $
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
 * @version $Revision: 1.13 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_NAME_CONSTANTS_SOURCE
#define CYBOL_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// General cybol names.
//

/** The super properties name. */
static wchar_t SUPER_PROPERTIES_NAME_ARRAY[] = {L's', L'u', L'p', L'e', L'r'};
static wchar_t* SUPER_PROPERTIES_NAME = SUPER_PROPERTIES_NAME_ARRAY;
static int* SUPER_PROPERTIES_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// User interface (ui) names.
//

/** The shape name. */
static wchar_t UI_SHAPE_NAME_ARRAY[] = {L's', L'h', L'a', L'p', L'e'};
static wchar_t* UI_SHAPE_NAME = UI_SHAPE_NAME_ARRAY;
static int* UI_SHAPE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The layout name. */
static wchar_t UI_LAYOUT_NAME_ARRAY[] = {L'l', L'a', L'y', L'o', L'u', L't'};
static wchar_t* UI_LAYOUT_NAME = UI_LAYOUT_NAME_ARRAY;
static int* UI_LAYOUT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The cell name. */
static wchar_t UI_CELL_NAME_ARRAY[] = {L'c', L'e', L'l', L'l'};
static wchar_t* UI_CELL_NAME = UI_CELL_NAME_ARRAY;
static int* UI_CELL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The position name. */
static wchar_t UI_POSITION_NAME_ARRAY[] = {L'p', L'o', L's', L'i', L't', L'i', L'o', L'n'};
static wchar_t* UI_POSITION_NAME = UI_POSITION_NAME_ARRAY;
static int* UI_POSITION_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The size name. */
static wchar_t UI_SIZE_NAME_ARRAY[] = {L's', L'i', L'z', L'e'};
static wchar_t* UI_SIZE_NAME = UI_SIZE_NAME_ARRAY;
static int* UI_SIZE_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The background colour name. */
static wchar_t UI_BACKGROUND_NAME_ARRAY[] = {L'b', L'a', L'c', L'k', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* UI_BACKGROUND_NAME = UI_BACKGROUND_NAME_ARRAY;
static int* UI_BACKGROUND_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The foreground colour name. */
static wchar_t UI_FOREGROUND_NAME_ARRAY[] = {L'f', L'o', L'r', L'e', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* UI_FOREGROUND_NAME = UI_FOREGROUND_NAME_ARRAY;
static int* UI_FOREGROUND_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

//
// User interface (ui) input names.
//

/** The enter name. */
static wchar_t UI_ENTER_NAME_ARRAY[] = {L'e', L'n', L't', L'e', L'r'};
static wchar_t* UI_ENTER_NAME = UI_ENTER_NAME_ARRAY;
static int* UI_ENTER_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The escape name. */
static wchar_t UI_ESCAPE_NAME_ARRAY[] = {L'e', L's', L'c', L'a', L'p', L'e'};
static wchar_t* UI_ESCAPE_NAME = UI_ESCAPE_NAME_ARRAY;
static int* UI_ESCAPE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The arrow up name. */
static wchar_t UI_ARROW_UP_NAME_ARRAY[] = {L'a', L'r', L'r', L'o', L'w', L'_', L'u', L'p'};
static wchar_t* UI_ARROW_UP_NAME = UI_ARROW_UP_NAME_ARRAY;
static int* UI_ARROW_UP_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The arrow down name. */
static wchar_t UI_ARROW_DOWN_NAME_ARRAY[] = {L'a', L'r', L'r', L'o', L'w', L'_', L'd', L'o', L'w', L'n'};
static wchar_t* UI_ARROW_DOWN_NAME = UI_ARROW_DOWN_NAME_ARRAY;
static int* UI_ARROW_DOWN_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The arrow left name. */
static wchar_t UI_ARROW_LEFT_NAME_ARRAY[] = {L'a', L'r', L'r', L'o', L'w', L'_', L'l', L'e', L'f', L't'};
static wchar_t* UI_ARROW_LEFT_NAME = UI_ARROW_LEFT_NAME_ARRAY;
static int* UI_ARROW_LEFT_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The arrow right name. */
static wchar_t UI_ARROW_RIGHT_NAME_ARRAY[] = {L'a', L'r', L'r', L'o', L'w', L'_', L'r', L'i', L'g', L'h', L't'};
static wchar_t* UI_ARROW_RIGHT_NAME = UI_ARROW_RIGHT_NAME_ARRAY;
static int* UI_ARROW_RIGHT_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Textual user interface (tui) names.
//

/** The border name. */
static wchar_t TUI_BORDER_NAME_ARRAY[] = {L'b', L'o', L'r', L'd', L'e', L'r'};
static wchar_t* TUI_BORDER_NAME = TUI_BORDER_NAME_ARRAY;
static int* TUI_BORDER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The hidden property name. */
static wchar_t TUI_HIDDEN_NAME_ARRAY[] = {L'h', L'i', L'd', L'd', L'e', L'n'};
static wchar_t* TUI_HIDDEN_NAME = TUI_HIDDEN_NAME_ARRAY;
static int* TUI_HIDDEN_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The inverse property name. */
static wchar_t TUI_INVERSE_NAME_ARRAY[] = {L'i', L'n', L'v', L'e', L'r', L's', L'e'};
static wchar_t* TUI_INVERSE_NAME = TUI_INVERSE_NAME_ARRAY;
static int* TUI_INVERSE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The blink property name. */
static wchar_t TUI_BLINK_NAME_ARRAY[] = {L'b', L'l', L'i', L'n', L'k'};
static wchar_t* TUI_BLINK_NAME = TUI_BLINK_NAME_ARRAY;
static int* TUI_BLINK_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The underline property name. */
static wchar_t TUI_UNDERLINE_NAME_ARRAY[] = {L'u', L'n', L'd', L'e', L'r', L'l', L'i', L'n', L'e'};
static wchar_t* TUI_UNDERLINE_NAME = TUI_UNDERLINE_NAME_ARRAY;
static int* TUI_UNDERLINE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The bold property name. */
static wchar_t TUI_BOLD_NAME_ARRAY[] = {L'b', L'o', L'l', L'd'};
static wchar_t* TUI_BOLD_NAME = TUI_BOLD_NAME_ARRAY;
static int* TUI_BOLD_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Graphical user interface (gui) names.
//

/** The title name. */
static wchar_t GUI_TITLE_NAME_ARRAY[] = {L't', L'i', L't', L'l', L'e'};
static wchar_t* GUI_TITLE_NAME = GUI_TITLE_NAME_ARRAY;
static int* GUI_TITLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The icon name. */
static wchar_t GUI_ICON_NAME_ARRAY[] = {L'i', L'c', L'o', L'n'};
static wchar_t* GUI_ICON_NAME = GUI_ICON_NAME_ARRAY;
static int* GUI_ICON_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The expose command name. */
static wchar_t GUI_EXPOSE_COMMAND_NAME_ARRAY[] = {L'e', L'x', L'p', L'o', L's', L'e'};
static wchar_t* GUI_EXPOSE_COMMAND_NAME = GUI_EXPOSE_COMMAND_NAME_ARRAY;
static int* GUI_EXPOSE_COMMAND_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The left mouse button press command name. */
static wchar_t GUI_LEFT_PRESS_COMMAND_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'_', L'p', L'r', L'e', L's', L's'};
static wchar_t* GUI_LEFT_PRESS_COMMAND_NAME = GUI_LEFT_PRESS_COMMAND_NAME_ARRAY;
static int* GUI_LEFT_PRESS_COMMAND_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The left mouse button release command name. */
static wchar_t GUI_LEFT_RELEASE_COMMAND_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'_', L'r', L'e', L'l', L'e', L'a', L's', L'e'};
static wchar_t* GUI_LEFT_RELEASE_COMMAND_NAME = GUI_LEFT_RELEASE_COMMAND_NAME_ARRAY;
static int* GUI_LEFT_RELEASE_COMMAND_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

//
// Web user interface (wui) tag names.
//

/** The tag name. */
static wchar_t WUI_TAG_NAME_ARRAY[] = {L't', L'a', L'g'};
static wchar_t* WUI_TAG_NAME = WUI_TAG_NAME_ARRAY;
static int* WUI_TAG_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The property name. */
static wchar_t WUI_PROPERTY_NAME_ARRAY[] = {L'p', L'r', L'o', L'p', L'e', L'r', L't', L'y'};
static wchar_t* WUI_PROPERTY_NAME = WUI_PROPERTY_NAME_ARRAY;
static int* WUI_PROPERTY_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Web user interface (wui) attribute names.
//

/** The align attribute name. */
/*??
static wchar_t WUI_ALIGN_ATTRIBUTE_NAME_ARRAY[] = {L'a', L'l', L'i', L'g', L'n'};
static wchar_t* WUI_ALIGN_ATTRIBUTE_NAME = WUI_ALIGN_ATTRIBUTE_NAME_ARRAY;
static int* WUI_ALIGN_ATTRIBUTE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;
*/

//
// Boolean names.
//

/** The input 1 name. */
static wchar_t INPUT_1_NAME_ARRAY[] = {L'i', L'n', L'p', L'u', L't', L'_', L'1'};
static wchar_t* INPUT_1_NAME = INPUT_1_NAME_ARRAY;
static int* INPUT_1_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The input 2 name. */
static wchar_t INPUT_2_NAME_ARRAY[] = {L'i', L'n', L'p', L'u', L't', L'_', L'2'};
static wchar_t* INPUT_2_NAME = INPUT_2_NAME_ARRAY;
static int* INPUT_2_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The output name. */
static wchar_t OUTPUT_NAME_ARRAY[] = {L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* OUTPUT_NAME = OUTPUT_NAME_ARRAY;
static int* OUTPUT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Compare names.
//

/** The comparison name. */
static wchar_t COMPARISON_NAME_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n'};
static wchar_t* COMPARISON_NAME = COMPARISON_NAME_ARRAY;
static int* COMPARISON_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The left side name. */
static wchar_t LEFT_SIDE_NAME_ARRAY[] = {L'l', L'e', L'f', L't'};
static wchar_t* LEFT_SIDE_NAME = LEFT_SIDE_NAME_ARRAY;
static int* LEFT_SIDE_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The right side name. */
static wchar_t RIGHT_SIDE_NAME_ARRAY[] = {L'r', L'i', L'g', L'h', L't'};
static wchar_t* RIGHT_SIDE_NAME = RIGHT_SIDE_NAME_ARRAY;
static int* RIGHT_SIDE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The result name. */
static wchar_t RESULT_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* RESULT_NAME = RESULT_NAME_ARRAY;
static int* RESULT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Arithmetic names.
//

/** The operand 1 name. */
/*??
static wchar_t OPERAND_1_NAME_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L'n', L'd', L'_', L'1'};
static wchar_t* OPERAND_1_NAME = OPERAND_1_NAME_ARRAY;
static int* OPERAND_1_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;
*/

/** The operand 2 name. */
/*??
static wchar_t OPERAND_2_NAME_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L'n', L'd', L'_', L'2'};
static wchar_t* OPERAND_2_NAME = OPERAND_2_NAME_ARRAY;
static int* OPERAND_2_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;
*/

/** The result operand name. */
/*??
static wchar_t RESULT_OPERAND_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* RESULT_OPERAND_NAME = RESULT_OPERAND_NAME_ARRAY;
static int* RESULT_OPERAND_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;
*/

//
// Add names.
//

/** The add summand 1 name. */
static wchar_t ADD_SUMMAND_1_NAME_ARRAY[] = {L's', L'u', L'm', L'm', L'a', L'n', L'd', L'_', L'1'};
static wchar_t* ADD_SUMMAND_1_NAME = ADD_SUMMAND_1_NAME_ARRAY;
static int* ADD_SUMMAND_1_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The add summand 2 name. */
static wchar_t ADD_SUMMAND_2_NAME_ARRAY[] = {L's', L'u', L'm', L'm', L'a', L'n', L'd', L'_', L'2'};
static wchar_t* ADD_SUMMAND_2_NAME = ADD_SUMMAND_2_NAME_ARRAY;
static int* ADD_SUMMAND_2_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The add sum name. */
static wchar_t ADD_SUM_NAME_ARRAY[] = {L's', L'u', L'm'};
static wchar_t* ADD_SUM_NAME = ADD_SUM_NAME_ARRAY;
static int* ADD_SUM_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Copy and move names.
//

/** The copy source name. */
static wchar_t COPY_SOURCE_NAME_ARRAY[] = {L's', L'o', L'u', L'r', L'c', L'e'};
static wchar_t* COPY_SOURCE_NAME = COPY_SOURCE_NAME_ARRAY;
static int* COPY_SOURCE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copy destination name. */
static wchar_t COPY_DESTINATION_NAME_ARRAY[] = {L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n'};
static wchar_t* COPY_DESTINATION_NAME = COPY_DESTINATION_NAME_ARRAY;
static int* COPY_DESTINATION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The copy abstraction name. */
static wchar_t COPY_ABSTRACTION_NAME_ARRAY[] = {L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* COPY_ABSTRACTION_NAME = COPY_ABSTRACTION_NAME_ARRAY;
static int* COPY_ABSTRACTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Branch names.
//

/** The criterion name. */
static wchar_t CRITERION_NAME_ARRAY[] = {L'c', L'r', L'i', L't', L'e', L'r', L'i', L'o', L'n'};
static wchar_t* CRITERION_NAME = CRITERION_NAME_ARRAY;
static int* CRITERION_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The true model name. */
static wchar_t TRUE_MODEL_NAME_ARRAY[] = {L't', L'r', L'u', L'e'};
static wchar_t* TRUE_MODEL_NAME = TRUE_MODEL_NAME_ARRAY;
static int* TRUE_MODEL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The false model name. */
static wchar_t FALSE_MODEL_NAME_ARRAY[] = {L'f', L'a', L'l', L's', L'e'};
static wchar_t* FALSE_MODEL_NAME = FALSE_MODEL_NAME_ARRAY;
static int* FALSE_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Loop names.
//

/** The break flag name. */
static wchar_t BREAK_FLAG_NAME_ARRAY[] = {L'b', L'r', L'e', L'a', L'k'};
static wchar_t* BREAK_FLAG_NAME = BREAK_FLAG_NAME_ARRAY;
static int* BREAK_FLAG_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The loop model name. */
static wchar_t LOOP_MODEL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* LOOP_MODEL_NAME = LOOP_MODEL_NAME_ARRAY;
static int* LOOP_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Build listname names.
//

/** The base name name. */
static wchar_t BASE_NAME_NAME_ARRAY[] = {L'b', L'a', L's', L'e'};
static wchar_t* BASE_NAME_NAME = BASE_NAME_NAME_ARRAY;
static int* BASE_NAME_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The index name name. */
static wchar_t INDEX_NAME_NAME_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
static wchar_t* INDEX_NAME_NAME = INDEX_NAME_NAME_ARRAY;
static int* INDEX_NAME_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The composed name name. */
static wchar_t COMPOSED_NAME_NAME_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L's', L'e', L'd'};
static wchar_t* COMPOSED_NAME_NAME = COMPOSED_NAME_NAME_ARRAY;
static int* COMPOSED_NAME_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Count names.
//

/** The count compound name. */
static wchar_t COUNT_COMPOUND_NAME_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd'};
static wchar_t* COUNT_COMPOUND_NAME = COUNT_COMPOUND_NAME_ARRAY;
static int* COUNT_COMPOUND_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The count selection name. */
static wchar_t COUNT_SELECTION_NAME_ARRAY[] = {L's', L'e', L'l', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* COUNT_SELECTION_NAME = COUNT_SELECTION_NAME_ARRAY;
static int* COUNT_SELECTION_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The count filter name. */
static wchar_t COUNT_FILTER_NAME_ARRAY[] = {L'f', L'i', L'l', L't', L'e', L'r'};
static wchar_t* COUNT_FILTER_NAME = COUNT_FILTER_NAME_ARRAY;
static int* COUNT_FILTER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The count result name. */
static wchar_t COUNT_RESULT_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* COUNT_RESULT_NAME = COUNT_RESULT_NAME_ARRAY;
static int* COUNT_RESULT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Get names.
//

/** The get compound name. */
static wchar_t GET_COMPOUND_NAME_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd'};
static wchar_t* GET_COMPOUND_NAME = GET_COMPOUND_NAME_ARRAY;
static int* GET_COMPOUND_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The get index name. */
static wchar_t GET_INDEX_NAME_ARRAY[] = {L'i', L'n', L'd', L'e', L'x'};
static wchar_t* GET_INDEX_NAME = GET_INDEX_NAME_ARRAY;
static int* GET_INDEX_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The get description name. */
static wchar_t GET_DESCRIPTION_NAME_ARRAY[] = {L'd', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* GET_DESCRIPTION_NAME = GET_DESCRIPTION_NAME_ARRAY;
static int* GET_DESCRIPTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The get result name. */
static wchar_t GET_RESULT_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* GET_RESULT_NAME = GET_RESULT_NAME_ARRAY;
static int* GET_RESULT_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Create names.
//

/** The create name name. */
static wchar_t CREATE_NAME_NAME_ARRAY[] = {L'n', L'a', L'm', L'e'};
static wchar_t* CREATE_NAME_NAME = CREATE_NAME_NAME_ARRAY;
static int* CREATE_NAME_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The create abstraction name. */
static wchar_t CREATE_ABSTRACTION_NAME_ARRAY[] = {L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* CREATE_ABSTRACTION_NAME = CREATE_ABSTRACTION_NAME_ARRAY;
static int* CREATE_ABSTRACTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The create element name. */
static wchar_t CREATE_ELEMENT_NAME_ARRAY[] = {L'e', L'l', L'e', L'm', L'e', L'n', L't'};
static wchar_t* CREATE_ELEMENT_NAME = CREATE_ELEMENT_NAME_ARRAY;
static int* CREATE_ELEMENT_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The create whole name. */
static wchar_t CREATE_WHOLE_NAME_ARRAY[] = {L'w', L'h', L'o', L'l', L'e'};
static wchar_t* CREATE_WHOLE_NAME = CREATE_WHOLE_NAME_ARRAY;
static int* CREATE_WHOLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Destroy names.
//

/** The destroy model. */
static wchar_t DESTROY_MODEL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* DESTROY_MODEL_NAME = DESTROY_MODEL_NAME_ARRAY;
static int* DESTROY_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Startup and shutdown service names.
//

/** The service name. */
static wchar_t SERVICE_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e'};
static wchar_t* SERVICE_NAME = SERVICE_NAME_ARRAY;
static int* SERVICE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The service namespace name. */
static wchar_t SERVICE_NAMESPACE_NAME_ARRAY[] = {L'n', L'a', L'm', L'e', L's', L'p', L'a', L'c', L'e'};
static wchar_t* SERVICE_NAMESPACE_NAME = SERVICE_NAMESPACE_NAME_ARRAY;
static int* SERVICE_NAMESPACE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The service style name. */
static wchar_t SERVICE_STYLE_NAME_ARRAY[] = {L's', L't', L'y', L'l', L'e'};
static wchar_t* SERVICE_STYLE_NAME = SERVICE_STYLE_NAME_ARRAY;
static int* SERVICE_STYLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The service address name. */
static wchar_t SERVICE_ADDRESS_NAME_ARRAY[] = {L'a', L'd', L'd', L'r', L'e', L's', L's'};
static wchar_t* SERVICE_ADDRESS_NAME = SERVICE_ADDRESS_NAME_ARRAY;
static int* SERVICE_ADDRESS_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Send names.
//

/** The send channel name. */
static wchar_t SEND_CHANNEL_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* SEND_CHANNEL_NAME = SEND_CHANNEL_NAME_ARRAY;
static int* SEND_CHANNEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The send language name. */
static wchar_t SEND_LANGUAGE_NAME_ARRAY[] = {L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* SEND_LANGUAGE_NAME = SEND_LANGUAGE_NAME_ARRAY;
static int* SEND_LANGUAGE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The send communication mode name. */
static wchar_t SEND_COMMUNICATION_MODE_NAME_ARRAY[] = {L'm', L'o', L'd', L'e'};
static wchar_t* SEND_COMMUNICATION_MODE_NAME = SEND_COMMUNICATION_MODE_NAME_ARRAY;
static int* SEND_COMMUNICATION_MODE_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The send socket namespace name. */
static wchar_t SEND_NAMESPACE_NAME_ARRAY[] = {L'n', L'a', L'm', L'e', L's', L'p', L'a', L'c', L'e'};
static wchar_t* SEND_NAMESPACE_NAME = SEND_NAMESPACE_NAME_ARRAY;
static int* SEND_NAMESPACE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The send communication style name. */
static wchar_t SEND_STYLE_NAME_ARRAY[] = {L's', L't', L'y', L'l', L'e'};
static wchar_t* SEND_STYLE_NAME = SEND_STYLE_NAME_ARRAY;
static int* SEND_STYLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The send sender name. */
static wchar_t SEND_SENDER_NAME_ARRAY[] = {L's', L'e', L'n', L'd', L'e', L'r'};
static wchar_t* SEND_SENDER_NAME = SEND_SENDER_NAME_ARRAY;
static int* SEND_SENDER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The send receiver name. */
static wchar_t SEND_RECEIVER_NAME_ARRAY[] = {L'r', L'e', L'c', L'e', L'i', L'v', L'e', L'r'};
static wchar_t* SEND_RECEIVER_NAME = SEND_RECEIVER_NAME_ARRAY;
static int* SEND_RECEIVER_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The send message name. */
static wchar_t SEND_MESSAGE_NAME_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e'};
static wchar_t* SEND_MESSAGE_NAME = SEND_MESSAGE_NAME_ARRAY;
static int* SEND_MESSAGE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The send area name. */
static wchar_t SEND_AREA_NAME_ARRAY[] = {L'a', L'r', L'e', L'a'};
static wchar_t* SEND_AREA_NAME = SEND_AREA_NAME_ARRAY;
static int* SEND_AREA_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The send clean name. */
static wchar_t SEND_CLEAN_NAME_ARRAY[] = {L'c', L'l', L'e', L'a', L'n'};
static wchar_t* SEND_CLEAN_NAME = SEND_CLEAN_NAME_ARRAY;
static int* SEND_CLEAN_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The send new line name. */
static wchar_t SEND_NEW_LINE_NAME_ARRAY[] = {L'n', L'e', L'w', L'_', L'l', L'i', L'n', L'e'};
static wchar_t* SEND_NEW_LINE_NAME = SEND_NEW_LINE_NAME_ARRAY;
static int* SEND_NEW_LINE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The send url name. */
/*??
static wchar_t SEND_URL_NAME_ARRAY[] = {L'u', L'r', L'l'};
static wchar_t* SEND_URL_NAME = SEND_URL_NAME_ARRAY;
static int* SEND_URL_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;
*/

//
// Receive names.
//

/** The receive channel name. */
static wchar_t RECEIVE_CHANNEL_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* RECEIVE_CHANNEL_NAME = RECEIVE_CHANNEL_NAME_ARRAY;
static int* RECEIVE_CHANNEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The receive handler name. */
static wchar_t RECEIVE_HANDLER_NAME_ARRAY[] = {L'h', L'a', L'n', L'd', L'l', L'e', L'r'};
static wchar_t* RECEIVE_HANDLER_NAME = RECEIVE_HANDLER_NAME_ARRAY;
static int* RECEIVE_HANDLER_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The receive language name. */
static wchar_t RECEIVE_LANGUAGE_NAME_ARRAY[] = {L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* RECEIVE_LANGUAGE_NAME = RECEIVE_LANGUAGE_NAME_ARRAY;
static int* RECEIVE_LANGUAGE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The receive message name. */
static wchar_t RECEIVE_MESSAGE_NAME_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e'};
static wchar_t* RECEIVE_MESSAGE_NAME = RECEIVE_MESSAGE_NAME_ARRAY;
static int* RECEIVE_MESSAGE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The receive meta name. */
static wchar_t RECEIVE_META_NAME_ARRAY[] = {L'm', L'e', L't', L'a'};
static wchar_t* RECEIVE_META_NAME = RECEIVE_META_NAME_ARRAY;
static int* RECEIVE_META_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The receive model name. */
static wchar_t RECEIVE_MODEL_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* RECEIVE_MODEL_NAME = RECEIVE_MODEL_NAME_ARRAY;
static int* RECEIVE_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The receive root name. */
static wchar_t RECEIVE_ROOT_NAME_ARRAY[] = {L'r', L'o', L'o', L't'};
static wchar_t* RECEIVE_ROOT_NAME = RECEIVE_ROOT_NAME_ARRAY;
static int* RECEIVE_ROOT_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The receive style name. */
static wchar_t RECEIVE_STYLE_NAME_ARRAY[] = {L's', L't', L'y', L'l', L'e'};
static wchar_t* RECEIVE_STYLE_NAME = RECEIVE_STYLE_NAME_ARRAY;
static int* RECEIVE_STYLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The receive commands name. */
static wchar_t RECEIVE_COMMANDS_NAME_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L's'};
static wchar_t* RECEIVE_COMMANDS_NAME = RECEIVE_COMMANDS_NAME_ARRAY;
static int* RECEIVE_COMMANDS_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The receive blocking name. */
static wchar_t RECEIVE_BLOCKING_NAME_ARRAY[] = {L'b', L'l', L'o', L'c', L'k', L'i', L'n', L'g'};
static wchar_t* RECEIVE_BLOCKING_NAME = RECEIVE_BLOCKING_NAME_ARRAY;
static int* RECEIVE_BLOCKING_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Run names.
//

/** The command name. */
static wchar_t RUN_COMMAND_NAME_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd'};
static wchar_t* RUN_COMMAND_NAME = RUN_COMMAND_NAME_ARRAY;
static int* RUN_COMMAND_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The archive create name. */
static wchar_t RUN_ARCHIVE_CREATE_NAME_ARRAY[] = {L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* RUN_ARCHIVE_CREATE_NAME = RUN_ARCHIVE_CREATE_NAME_ARRAY;
static int* RUN_ARCHIVE_CREATE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive update name. */
static wchar_t RUN_ARCHIVE_UPDATE_NAME_ARRAY[] = {L'u', L'p', L'd', L'a', L't', L'e'};
static wchar_t* RUN_ARCHIVE_UPDATE_NAME = RUN_ARCHIVE_UPDATE_NAME_ARRAY;
static int* RUN_ARCHIVE_UPDATE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive bzip2 name. */
static wchar_t RUN_ARCHIVE_BZIP2_NAME_ARRAY[] = {L'b', L'z', L'i', L'p', L'2'};
static wchar_t* RUN_ARCHIVE_BZIP2_NAME = RUN_ARCHIVE_BZIP2_NAME_ARRAY;
static int* RUN_ARCHIVE_BZIP2_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The copy recursive name. */
static wchar_t RUN_COPY_RECURSIVE_NAME_ARRAY[] = {L'r', L'e', L'c', L'u', L'r', L's', L'i', L'v', L'e'};
static wchar_t* RUN_COPY_RECURSIVE_NAME = RUN_COPY_RECURSIVE_NAME_ARRAY;
static int* RUN_COPY_RECURSIVE_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The copy source name. */
static wchar_t RUN_COPY_SOURCE_NAME_ARRAY[] = {L's', L'o', L'u', L'r', L'c', L'e'};
static wchar_t* RUN_COPY_SOURCE_NAME = RUN_COPY_SOURCE_NAME_ARRAY;
static int* RUN_COPY_SOURCE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copy destination name. */
static wchar_t RUN_COPY_DESTINATION_NAME_ARRAY[] = {L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n'};
static wchar_t* RUN_COPY_DESTINATION_NAME = RUN_COPY_DESTINATION_NAME_ARRAY;
static int* RUN_COPY_DESTINATION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The list directory contents all name. */
static wchar_t RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME = RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_ARRAY;
static int* RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The list directory contents long listing name. */
static wchar_t RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_ARRAY[] = {L'l', L'o', L'n', L'g', L'_', L'l', L'i', L's', L't', L'i', L'n', L'g'};
static wchar_t* RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME = RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_ARRAY;
static int* RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The program program name. */
static wchar_t RUN_PROGRAM_PROGRAM_NAME_ARRAY[] = {L'p', L'r', L'o', L'g', L'r', L'a', L'm'};
static wchar_t* RUN_PROGRAM_PROGRAM_NAME = RUN_PROGRAM_PROGRAM_NAME_ARRAY;
static int* RUN_PROGRAM_PROGRAM_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Sense model names.
//

/** The sense model method name. */
static wchar_t SENSE_MODEL_METHOD_NAME_ARRAY[] = {L'm', L'e', L't', L'h', L'o', L'd'};
static wchar_t* SENSE_MODEL_METHOD_NAME = SENSE_MODEL_METHOD_NAME_ARRAY;
static int* SENSE_MODEL_METHOD_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The sense model scheme name. */
static wchar_t SENSE_MODEL_SCHEME_NAME_ARRAY[] = {L's', L'c', L'h', L'e', L'm', L'e'};
static wchar_t* SENSE_MODEL_SCHEME_NAME = SENSE_MODEL_SCHEME_NAME_ARRAY;
static int* SENSE_MODEL_SCHEME_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The sense model authority name. */
static wchar_t SENSE_MODEL_AUTHORITY_NAME_ARRAY[] = {L'a', L'u', L't', L'h', L'o', L'r', L'i', L't', L'y'};
static wchar_t* SENSE_MODEL_AUTHORITY_NAME = SENSE_MODEL_AUTHORITY_NAME_ARRAY;
static int* SENSE_MODEL_AUTHORITY_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The sense model path name. */
static wchar_t SENSE_MODEL_PATH_NAME_ARRAY[] = {L'p', L'a', L't', L'h'};
static wchar_t* SENSE_MODEL_PATH_NAME = SENSE_MODEL_PATH_NAME_ARRAY;
static int* SENSE_MODEL_PATH_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The sense model fragment name. */
static wchar_t SENSE_MODEL_FRAGMENT_NAME_ARRAY[] = {L'f', L'r', L'a', L'g', L'm', L'e', L'n', L't'};
static wchar_t* SENSE_MODEL_FRAGMENT_NAME = SENSE_MODEL_FRAGMENT_NAME_ARRAY;
static int* SENSE_MODEL_FRAGMENT_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The sense model action name. */
static wchar_t SENSE_MODEL_ACTION_NAME_ARRAY[] = {L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* SENSE_MODEL_ACTION_NAME = SENSE_MODEL_ACTION_NAME_ARRAY;
static int* SENSE_MODEL_ACTION_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/* CYBOL_NAME_CONSTANTS_SOURCE */
#endif
