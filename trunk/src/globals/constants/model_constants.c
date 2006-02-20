/*
 * $RCSfile: model_constants.c,v $
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
 * @version $Revision: 1.12 $ $Date: 2006-02-20 16:17:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_CONSTANTS_SOURCE
#define MODEL_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Boolean models.
//

/** The false model. */
static char FALSE_MODEL_ARRAY[] = {'f', 'a', 'l', 's', 'e'};
static char* FALSE_MODEL = FALSE_MODEL_ARRAY;
static int* FALSE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The true model. */
static char TRUE_MODEL_ARRAY[] = {'t', 'r', 'u', 'e'};
static char* TRUE_MODEL = TRUE_MODEL_ARRAY;
static int* TRUE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Terminal colour models.
//

/** The black model. */
static char TERMINAL_COLOUR_BLACK_MODEL_ARRAY[] = {'b', 'l', 'a', 'c', 'k'};
static char* TERMINAL_COLOUR_BLACK_MODEL = TERMINAL_COLOUR_BLACK_MODEL_ARRAY;
static int* TERMINAL_COLOUR_BLACK_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The red model. */
static char TERMINAL_COLOUR_RED_MODEL_ARRAY[] = {'r', 'e', 'd'};
static char* TERMINAL_COLOUR_RED_MODEL = TERMINAL_COLOUR_RED_MODEL_ARRAY;
static int* TERMINAL_COLOUR_RED_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The green model. */
static char TERMINAL_COLOUR_GREEN_MODEL_ARRAY[] = {'g', 'r', 'e', 'e', 'n'};
static char* TERMINAL_COLOUR_GREEN_MODEL = TERMINAL_COLOUR_GREEN_MODEL_ARRAY;
static int* TERMINAL_COLOUR_GREEN_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The yellow model. */
static char TERMINAL_COLOUR_YELLOW_MODEL_ARRAY[] = {'y', 'e', 'l', 'l', 'o', 'w'};
static char* TERMINAL_COLOUR_YELLOW_MODEL = TERMINAL_COLOUR_YELLOW_MODEL_ARRAY;
static int* TERMINAL_COLOUR_YELLOW_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The blue model. */
static char TERMINAL_COLOUR_BLUE_MODEL_ARRAY[] = {'b', 'l', 'u', 'e'};
static char* TERMINAL_COLOUR_BLUE_MODEL = TERMINAL_COLOUR_BLUE_MODEL_ARRAY;
static int* TERMINAL_COLOUR_BLUE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) model. */
static char TERMINAL_COLOUR_MAGENTA_MODEL_ARRAY[] = {'m', 'a', 'g', 'e', 'n', 't', 'a'};
static char* TERMINAL_COLOUR_MAGENTA_MODEL = TERMINAL_COLOUR_MAGENTA_MODEL_ARRAY;
static int* TERMINAL_COLOUR_MAGENTA_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The cobalt blue (china blue) model. */
static char TERMINAL_COLOUR_COBALT_MODEL_ARRAY[] = {'c', 'o', 'b', 'a', 'l', 't'};
static char* TERMINAL_COLOUR_COBALT_MODEL = TERMINAL_COLOUR_COBALT_MODEL_ARRAY;
static int* TERMINAL_COLOUR_COBALT_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The white model. */
static char TERMINAL_COLOUR_WHITE_MODEL_ARRAY[] = {'w', 'h', 'i', 't', 'e'};
static char* TERMINAL_COLOUR_WHITE_MODEL = TERMINAL_COLOUR_WHITE_MODEL_ARRAY;
static int* TERMINAL_COLOUR_WHITE_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Program flow models.
//

/** The copy (set, assign) model. */
static char COPY_MODEL_ARRAY[] = {'c', 'o', 'p', 'y'};
static char* COPY_MODEL = COPY_MODEL_ARRAY;
static int* COPY_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The move model. */
static char MOVE_MODEL_ARRAY[] = {'m', 'o', 'v', 'e'};
static char* MOVE_MODEL = MOVE_MODEL_ARRAY;
static int* MOVE_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The copy property model. */
static char COPY_PROPERTY_MODEL_ARRAY[] = {'c', 'o', 'p', 'y', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static char* COPY_PROPERTY_MODEL = COPY_PROPERTY_MODEL_ARRAY;
static int* COPY_PROPERTY_MODEL_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The move property model. */
static char MOVE_PROPERTY_MODEL_ARRAY[] = {'m', 'o', 'v', 'e', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static char* MOVE_PROPERTY_MODEL = MOVE_PROPERTY_MODEL_ARRAY;
static int* MOVE_PROPERTY_MODEL_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The branch model. */
static char BRANCH_MODEL_ARRAY[] = {'b', 'r', 'a', 'n', 'c', 'h'};
static char* BRANCH_MODEL = BRANCH_MODEL_ARRAY;
static int* BRANCH_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The loop model. */
static char LOOP_MODEL_ARRAY[] = {'l', 'o', 'o', 'p'};
static char* LOOP_MODEL = LOOP_MODEL_ARRAY;
static int* LOOP_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The count parts model. */
static char COUNT_PARTS_MODEL_ARRAY[] = {'c', 'o', 'u', 'n', 't', '_', 'p', 'a', 'r', 't', 's'};
static char* COUNT_PARTS_MODEL = COUNT_PARTS_MODEL_ARRAY;
static int* COUNT_PARTS_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The build listname model. */
static char BUILD_LISTNAME_MODEL_ARRAY[] = {'b', 'u', 'i', 'l', 'd', '_', 'l', 'i', 's', 't', 'n', 'a', 'm', 'e'};
static char* BUILD_LISTNAME_MODEL = BUILD_LISTNAME_MODEL_ARRAY;
static int* BUILD_LISTNAME_MODEL_COUNT = NUMBER_14_INTEGER_ARRAY;

//
// Boolean logic models.
//

/** The and model. */
static char AND_MODEL_ARRAY[] = {'a', 'n', 'd'};
static char* AND_MODEL = AND_MODEL_ARRAY;
static int* AND_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The or model. */
static char OR_MODEL_ARRAY[] = {'o', 'r'};
static char* OR_MODEL = OR_MODEL_ARRAY;
static int* OR_MODEL_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Comparison models.
//

/** The compare model. */
static char COMPARE_MODEL_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 'r', 'e'};
static char* COMPARE_MODEL = COMPARE_MODEL_ARRAY;
static int* COMPARE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The equal model. */
static char EQUAL_MODEL_ARRAY[] = {'e', 'q', 'u', 'a', 'l'};
static char* EQUAL_MODEL = EQUAL_MODEL_ARRAY;
static int* EQUAL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The smaller model. */
static char SMALLER_MODEL_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r'};
static char* SMALLER_MODEL = SMALLER_MODEL_ARRAY;
static int* SMALLER_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The greater model. */
static char GREATER_MODEL_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r'};
static char* GREATER_MODEL = GREATER_MODEL_ARRAY;
static int* GREATER_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The smaller or equal model. */
static char SMALLER_OR_EQUAL_MODEL_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static char* SMALLER_OR_EQUAL_MODEL = SMALLER_OR_EQUAL_MODEL_ARRAY;
static int* SMALLER_OR_EQUAL_MODEL_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The greater or equal model. */
static char GREATER_OR_EQUAL_MODEL_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static char* GREATER_OR_EQUAL_MODEL = GREATER_OR_EQUAL_MODEL_ARRAY;
static int* GREATER_OR_EQUAL_MODEL_COUNT = NUMBER_16_INTEGER_ARRAY;

//
// Arithmetic models.
//

/** The add model. */
static char ADD_MODEL_ARRAY[] = {'a', 'd', 'd'};
static char* ADD_MODEL = ADD_MODEL_ARRAY;
static int* ADD_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The subtract model. */
static char SUBTRACT_MODEL_ARRAY[] = {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'};
static char* SUBTRACT_MODEL = SUBTRACT_MODEL_ARRAY;
static int* SUBTRACT_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The multiply model. */
static char MULTIPLY_MODEL_ARRAY[] = {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'};
static char* MULTIPLY_MODEL = MULTIPLY_MODEL_ARRAY;
static int* MULTIPLY_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The divide model. */
static char DIVIDE_MODEL_ARRAY[] = {'d', 'i', 'v', 'i', 'd', 'e'};
static char* DIVIDE_MODEL = DIVIDE_MODEL_ARRAY;
static int* DIVIDE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Memory management models.
//

/** The create part model. */
static char CREATE_PART_MODEL_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 'p', 'a', 'r', 't'};
static char* CREATE_PART_MODEL = CREATE_PART_MODEL_ARRAY;
static int* CREATE_PART_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The destroy part model. */
static char DESTROY_PART_MODEL_ARRAY[] = {'d', 'e', 's', 't', 'r', 'o', 'y', '_', 'p', 'a', 'r', 't'};
static char* DESTROY_PART_MODEL = DESTROY_PART_MODEL_ARRAY;
static int* DESTROY_PART_MODEL_COUNT = NUMBER_12_INTEGER_ARRAY;

//
// Lifecycle models.
//

/** The startup model. */
static char STARTUP_MODEL_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p'};
static char* STARTUP_MODEL = STARTUP_MODEL_ARRAY;
static int* STARTUP_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The shutdown model. */
static char SHUTDOWN_MODEL_ARRAY[] = {'s', 'h', 'u', 't', 'd', 'o', 'w', 'n'};
static char* SHUTDOWN_MODEL = SHUTDOWN_MODEL_ARRAY;
static int* SHUTDOWN_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The exit model. */
static char EXIT_MODEL_ARRAY[] = {'e', 'x', 'i', 't'};
static char* EXIT_MODEL = EXIT_MODEL_ARRAY;
static int* EXIT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// Communication models.
//

/** The send model. */
static char SEND_MODEL_ARRAY[] = {'s', 'e', 'n', 'd'};
static char* SEND_MODEL = SEND_MODEL_ARRAY;
static int* SEND_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The receive model. */
static char RECEIVE_MODEL_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e'};
static char* RECEIVE_MODEL = RECEIVE_MODEL_ARRAY;
static int* RECEIVE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The interrupt model. */
static char INTERRUPT_MODEL_ARRAY[] = {'i', 'n', 't', 'e', 'r', 'r', 'u', 'p', 't'};
static char* INTERRUPT_MODEL = INTERRUPT_MODEL_ARRAY;
static int* INTERRUPT_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The refresh url model. */
static char REFRESH_URL_MODEL_ARRAY[] = {'r', 'e', 'f', 'r', 'e', 's', 'h', '_', 'u', 'r', 'l'};
static char* REFRESH_URL_MODEL = REFRESH_URL_MODEL_ARRAY;
static int* REFRESH_URL_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// Language models.
//

/** The latex model. */
static char LATEX_MODEL_ARRAY[] = {'l', 'a', 't', 'e', 'x'};
static char* LATEX_MODEL = LATEX_MODEL_ARRAY;
static int* LATEX_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The linux console model. */
static char LINUX_CONSOLE_MODEL_ARRAY[] = {'l', 'i', 'n', 'u', 'x', '_', 'c', 'o', 'n', 's', 'o', 'l', 'e'};
static char* LINUX_CONSOLE_MODEL = LINUX_CONSOLE_MODEL_ARRAY;
static int* LINUX_CONSOLE_MODEL_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The signal model. */
static char SIGNAL_MODEL_ARRAY[] = {'s', 'i', 'g', 'n', 'a', 'l'};
static char* SIGNAL_MODEL = SIGNAL_MODEL_ARRAY;
static int* SIGNAL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The structured query language (sql). */
static char SQL_MODEL_ARRAY[] = {'s', 'q', 'l'};
static char* SQL_MODEL = SQL_MODEL_ARRAY;
static int* SQL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The tcp socket model. */
static char TCP_SOCKET_MODEL_ARRAY[] = {'t', 'c', 'p', '_', 's', 'o', 'c', 'k', 'e', 't'};
static char* TCP_SOCKET_MODEL = TCP_SOCKET_MODEL_ARRAY;
static int* TCP_SOCKET_MODEL_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The unix socket model. */
static char UNIX_SOCKET_MODEL_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'o', 'c', 'k', 'e', 't'};
static char* UNIX_SOCKET_MODEL = UNIX_SOCKET_MODEL_ARRAY;
static int* UNIX_SOCKET_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The x window system model. */
static char X_WINDOW_SYSTEM_MODEL_ARRAY[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', '_', 's', 'y', 's', 't', 'e', 'm'};
static char* X_WINDOW_SYSTEM_MODEL = X_WINDOW_SYSTEM_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_MODEL_COUNT = NUMBER_15_INTEGER_ARRAY;

//
// Shape models.
//

/** The rectangle shape model. */
static char UI_RECTANGLE_SHAPE_MODEL_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', 'g', 'l', 'e'};
static char* UI_RECTANGLE_SHAPE_MODEL = UI_RECTANGLE_SHAPE_MODEL_ARRAY;
static int* UI_RECTANGLE_SHAPE_MODEL_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The circle shape model. */
static char UI_CIRCLE_SHAPE_MODEL_ARRAY[] = {'c', 'i', 'r', 'c', 'l', 'e'};
static char* UI_CIRCLE_SHAPE_MODEL = UI_CIRCLE_SHAPE_MODEL_ARRAY;
static int* UI_CIRCLE_SHAPE_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The polygon shape model. */
static char UI_POLYGON_SHAPE_MODEL_ARRAY[] = {'p', 'o', 'l', 'y', 'g', 'o', 'n'};
static char* UI_POLYGON_SHAPE_MODEL = UI_POLYGON_SHAPE_MODEL_ARRAY;
static int* UI_POLYGON_SHAPE_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Layout models.
//

/** The root layout model. */
static char UI_ROOT_LAYOUT_MODEL_ARRAY[] = {'r', 'o', 'o', 't'};
static char* UI_ROOT_LAYOUT_MODEL = UI_ROOT_LAYOUT_MODEL_ARRAY;
static int* UI_ROOT_LAYOUT_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The coordinates layout model. */
static char UI_COORDINATES_LAYOUT_MODEL_ARRAY[] = {'c', 'o', 'o', 'r', 'd', 'i', 'n', 'a', 't', 'e', 's'};
static char* UI_COORDINATES_LAYOUT_MODEL = UI_COORDINATES_LAYOUT_MODEL_ARRAY;
static int* UI_COORDINATES_LAYOUT_MODEL_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The compass layout model. */
static char UI_COMPASS_LAYOUT_MODEL_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 's', 's'};
static char* UI_COMPASS_LAYOUT_MODEL = UI_COMPASS_LAYOUT_MODEL_ARRAY;
static int* UI_COMPASS_LAYOUT_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Compass layout cell models.
//

/** The compass layout north cell model. */
static char UI_NORTH_CELL_MODEL_ARRAY[] = {'n', 'o', 'r', 't', 'h'};
static char* UI_NORTH_CELL_MODEL = UI_NORTH_CELL_MODEL_ARRAY;
static int* UI_NORTH_CELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The compass layout south cell model. */
static char UI_SOUTH_CELL_MODEL_ARRAY[] = {'s', 'o', 'u', 't', 'h'};
static char* UI_SOUTH_CELL_MODEL = UI_SOUTH_CELL_MODEL_ARRAY;
static int* UI_SOUTH_CELL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The compass layout west cell model. */
static char UI_WEST_CELL_MODEL_ARRAY[] = {'w', 'e', 's', 't'};
static char* UI_WEST_CELL_MODEL = UI_WEST_CELL_MODEL_ARRAY;
static int* UI_WEST_CELL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The compass layout east cell model. */
static char UI_EAST_CELL_MODEL_ARRAY[] = {'e', 'a', 's', 't'};
static char* UI_EAST_CELL_MODEL = UI_EAST_CELL_MODEL_ARRAY;
static int* UI_EAST_CELL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The compass layout centre cell model. */
static char UI_CENTRE_CELL_MODEL_ARRAY[] = {'c', 'e', 'n', 't', 'r', 'e'};
static char* UI_CENTRE_CELL_MODEL = UI_CENTRE_CELL_MODEL_ARRAY;
static int* UI_CENTRE_CELL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Border models.
//

/** The line border model. */
static char TUI_LINE_BORDER_MODEL_ARRAY[] = {'l', 'i', 'n', 'e'};
static char* TUI_LINE_BORDER_MODEL = TUI_LINE_BORDER_MODEL_ARRAY;
static int* TUI_LINE_BORDER_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The round line border model. */
static char TUI_ROUND_LINE_BORDER_MODEL_ARRAY[] = {'r', 'o', 'u', 'n', 'd'};
static char* TUI_ROUND_LINE_BORDER_MODEL = TUI_ROUND_LINE_BORDER_MODEL_ARRAY;
static int* TUI_ROUND_LINE_BORDER_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The double line border model. */
static char TUI_DOUBLE_LINE_BORDER_MODEL_ARRAY[] = {'d', 'o', 'u', 'b', 'l', 'e'};
static char* TUI_DOUBLE_LINE_BORDER_MODEL = TUI_DOUBLE_LINE_BORDER_MODEL_ARRAY;
static int* TUI_DOUBLE_LINE_BORDER_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Run models.
//

/** The run model. */
static char RUN_MODEL_ARRAY[] = {'r', 'u', 'n'};
static char* RUN_MODEL = RUN_MODEL_ARRAY;
static int* RUN_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The list directory contents model. */
static char LIST_DIRECTORY_CONTENTS_MODEL_ARRAY[] = {'l', 'i', 's', 't', '_', 'd', 'i', 'r', 'e', 'c', 't', 'o', 'r', 'y', '_', 'c', 'o', 'n', 't', 'e', 'n', 't', 's'};
static char* LIST_DIRECTORY_CONTENTS_MODEL = LIST_DIRECTORY_CONTENTS_MODEL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_MODEL_COUNT = NUMBER_23_INTEGER_ARRAY;

/* MODEL_CONSTANTS_SOURCE */
#endif
