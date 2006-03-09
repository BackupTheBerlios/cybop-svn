/*
 * $RCSfile: name_constants.c,v $
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
 * @version $Revision: 1.16 $ $Date: 2006-03-09 22:45:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef NAME_CONSTANTS_SOURCE
#define NAME_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

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
// Web user interface (wui) names.
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
static char OPERAND_1_NAME_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '1'};
static char* OPERAND_1_NAME = OPERAND_1_NAME_ARRAY;
static int* OPERAND_1_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The operand 2 name. */
static char OPERAND_2_NAME_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 'n', 'd', '_', '2'};
static char* OPERAND_2_NAME = OPERAND_2_NAME_ARRAY;
static int* OPERAND_2_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The result operand name. */
static char RESULT_OPERAND_NAME_ARRAY[] = {'r', 'e', 's', 'u', 'l', 't'};
static char* RESULT_OPERAND_NAME = RESULT_OPERAND_NAME_ARRAY;
static int* RESULT_OPERAND_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Copy and move names.
//

/** The source name. */
static char SOURCE_NAME_ARRAY[] = {'s', 'o', 'u', 'r', 'c', 'e'};
static char* SOURCE_NAME = SOURCE_NAME_ARRAY;
static int* SOURCE_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The destination name. */
static char DESTINATION_NAME_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
static char* DESTINATION_NAME = DESTINATION_NAME_ARRAY;
static int* DESTINATION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The destination property name. */
static char DESTINATION_PROPERTY_NAME_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static char* DESTINATION_PROPERTY_NAME = DESTINATION_PROPERTY_NAME_ARRAY;
static int* DESTINATION_PROPERTY_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

//
// Branch names.
//

/** The criterion name. */
static char CRITERION_NAME_ARRAY[] = {'c', 'r', 'i', 't', 'e', 'r', 'i', 'o', 'n'};
static char* CRITERION_NAME = CRITERION_NAME_ARRAY;
static int* CRITERION_NAME_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The true model name. */
static char TRUE_MODEL_NAME_ARRAY[] = {'t', 'r', 'u', 'e', '_', 'm', 'o', 'd', 'e', 'l'};
static char* TRUE_MODEL_NAME = TRUE_MODEL_NAME_ARRAY;
static int* TRUE_MODEL_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The false model name. */
static char FALSE_MODEL_NAME_ARRAY[] = {'f', 'a', 'l', 's', 'e', '_', 'm', 'o', 'd', 'e', 'l'};
static char* FALSE_MODEL_NAME = FALSE_MODEL_NAME_ARRAY;
static int* FALSE_MODEL_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

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
// Count parts names.
//

/** The whole model name. */
static char WHOLE_MODEL_NAME_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static char* WHOLE_MODEL_NAME = WHOLE_MODEL_NAME_ARRAY;
static int* WHOLE_MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The part name name. */
static char PART_NAME_NAME_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* PART_NAME_NAME = PART_NAME_NAME_ARRAY;
static int* PART_NAME_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The counter name. */
static char COUNTER_NAME_ARRAY[] = {'c', 'o', 'u', 'n', 't', 'e', 'r'};
static char* COUNTER_NAME = COUNTER_NAME_ARRAY;
static int* COUNTER_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Create and destroy names.
//

/** The name name. */
static char NAME_NAME_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* NAME_NAME = NAME_NAME_ARRAY;
static int* NAME_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The channel name. */
static char CHANNEL_NAME_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* CHANNEL_NAME = CHANNEL_NAME_ARRAY;
static int* CHANNEL_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The abstraction name. */
static char ABSTRACTION_NAME_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* ABSTRACTION_NAME = ABSTRACTION_NAME_ARRAY;
static int* ABSTRACTION_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The model name. */
static char MODEL_NAME_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* MODEL_NAME = MODEL_NAME_ARRAY;
static int* MODEL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The whole name. */
static char WHOLE_NAME_ARRAY[] = {'w', 'h', 'o', 'l', 'e'};
static char* WHOLE_NAME = WHOLE_NAME_ARRAY;
static int* WHOLE_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Startup and shutdown names.
//

/** The service name. */
static char SERVICE_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e'};
static char* SERVICE_NAME = SERVICE_NAME_ARRAY;
static int* SERVICE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The platform name. */
static char PLATFORM_NAME_ARRAY[] = {'p', 'l', 'a', 't', 'f', 'o', 'r', 'm'};
static char* PLATFORM_NAME = PLATFORM_NAME_ARRAY;
static int* PLATFORM_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The port name. */
static char PORT_NAME_ARRAY[] = {'p', 'o', 'r', 't'};
static char* PORT_NAME = PORT_NAME_ARRAY;
static int* PORT_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Send and receive names.
//

/** The channel name. */
// Already defined for create and destroy.

/** The sender name. */
static char SENDER_NAME_ARRAY[] = {'s', 'e', 'n', 'd', 'e', 'r'};
static char* SENDER_NAME = SENDER_NAME_ARRAY;
static int* SENDER_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The receiver name. */
static char RECEIVER_NAME_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r'};
static char* RECEIVER_NAME = RECEIVER_NAME_ARRAY;
static int* RECEIVER_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The message name. */
static char MESSAGE_NAME_ARRAY[] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
static char* MESSAGE_NAME = MESSAGE_NAME_ARRAY;
static int* MESSAGE_NAME_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The url name. */
static char URL_NAME_ARRAY[] = {'u', 'r', 'l'};
static char* URL_NAME = URL_NAME_ARRAY;
static int* URL_NAME_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The root name. */
static char ROOT_NAME_ARRAY[] = {'r', 'o', 'o', 't'};
static char* ROOT_NAME = ROOT_NAME_ARRAY;
static int* ROOT_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The commands name. */
static char COMMANDS_NAME_ARRAY[] = {'c', 'o', 'm', 'm', 'a', 'n', 'd', 's'};
static char* COMMANDS_NAME = COMMANDS_NAME_ARRAY;
static int* COMMANDS_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The blocking name. */
static char BLOCKING_NAME_ARRAY[] = {'b', 'l', 'o', 'c', 'k', 'i', 'n', 'g'};
static char* BLOCKING_NAME = BLOCKING_NAME_ARRAY;
static int* BLOCKING_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

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

/* NAME_CONSTANTS_SOURCE */
#endif
