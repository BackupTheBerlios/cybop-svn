/*
 * $RCSfile: console_control_sequence_constants.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2008-05-04 00:18:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSOLE_CONTROL_SEQUENCE_CONSTANTS_SOURCE
#define CONSOLE_CONTROL_SEQUENCE_CONSTANTS_SOURCE

#include <wchar.h>
#include "../../../globals/constants/integer/integer_constants.c"

/**
 * The escape control sequence prefix.
 *
 * ESC[
 */
static wchar_t ESCAPE_CONTROL_SEQUENCE_ARRAY[] = {0x001B, 0x005B};
static wchar_t* ESCAPE_CONTROL_SEQUENCE = ESCAPE_CONTROL_SEQUENCE_ARRAY;
//?? static char ESCAPE_CONTROL_SEQUENCE_ARRAY[] = {27, 91};
//?? static char* ESCAPE_CONTROL_SEQUENCE = ESCAPE_CONTROL_SEQUENCE_ARRAY;
static int* ESCAPE_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The erase display control sequence.
 *
 * ESC[2J
 *
 * Mnemonic:
 * ED (Erase Display)
 */
static wchar_t ERASE_DISPLAY_CONTROL_SEQUENCE_ARRAY[] = {0x0032, 0x004A};
static wchar_t* ERASE_DISPLAY_CONTROL_SEQUENCE = ERASE_DISPLAY_CONTROL_SEQUENCE_ARRAY;
static int* ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The erase line control sequence.
 *
 * ESC[K
 *
 * Mnemonic:
 * EL (Erase Line)
 */
static wchar_t ERASE_LINE_CONTROL_SEQUENCE_ARRAY[] = {0x004B};
static wchar_t* ERASE_LINE_CONTROL_SEQUENCE = ERASE_LINE_CONTROL_SEQUENCE_ARRAY;
static int* ERASE_LINE_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The cursor position control sequence.
 *
 * ESC[P;PH
 *
 * Mnemonic:
 * CUP (Cursor Position)
 * HVP (Horizontal and Vertical Position)
 */
static wchar_t CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY[] = {0x0078, 0x0048};
static wchar_t* CURSOR_POSITION_CONTROL_SEQUENCE = CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY;
static int* CURSOR_POSITION_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// The set graphics rendition control sequences.
//
// ESC[P;...;Pm
//
// Mnemonic:
// SGR (Set Graphics Rendition)
//

/** The attribute suffix control sequence. */
static wchar_t ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_ARRAY[] = {0x006D};
static wchar_t* ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE = ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_ARRAY;
static int* ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The attribute off control sequence. */
static wchar_t ATTRIBUTE_OFF_CONTROL_SEQUENCE_ARRAY[] = {0x0030, 0x006D};
static wchar_t* ATTRIBUTE_OFF_CONTROL_SEQUENCE = ATTRIBUTE_OFF_CONTROL_SEQUENCE_ARRAY;
static int* ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The bold control sequence. */
static wchar_t BOLD_CONTROL_SEQUENCE_ARRAY[] = {0x0031, 0x006D};
static wchar_t* BOLD_CONTROL_SEQUENCE = BOLD_CONTROL_SEQUENCE_ARRAY;
static int* BOLD_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The underline control sequence. */
static wchar_t UNDERLINE_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x006D};
static wchar_t* UNDERLINE_CONTROL_SEQUENCE = UNDERLINE_CONTROL_SEQUENCE_ARRAY;
static int* UNDERLINE_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The blink control sequence. */
static wchar_t BLINK_CONTROL_SEQUENCE_ARRAY[] = {0x0035, 0x006D};
static wchar_t* BLINK_CONTROL_SEQUENCE = BLINK_CONTROL_SEQUENCE_ARRAY;
static int* BLINK_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The inverse control sequence. */
static wchar_t INVERSE_CONTROL_SEQUENCE_ARRAY[] = {0x0037, 0x006D};
static wchar_t* INVERSE_CONTROL_SEQUENCE = INVERSE_CONTROL_SEQUENCE_ARRAY;
static int* INVERSE_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The hidden control sequence. */
static wchar_t HIDDEN_CONTROL_SEQUENCE_ARRAY[] = {0x0038, 0x006D};
static wchar_t* HIDDEN_CONTROL_SEQUENCE = HIDDEN_CONTROL_SEQUENCE_ARRAY;
static int* HIDDEN_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The black foreground control sequence. */
static wchar_t BLACK_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0030};
static wchar_t* BLACK_FOREGROUND_CONTROL_SEQUENCE = BLACK_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLACK_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The red foreground control sequence. */
static wchar_t RED_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0031};
static wchar_t* RED_FOREGROUND_CONTROL_SEQUENCE = RED_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* RED_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The green foreground control sequence. */
static wchar_t GREEN_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0032};
static wchar_t* GREEN_FOREGROUND_CONTROL_SEQUENCE = GREEN_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* GREEN_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The yellow foreground control sequence. */
static wchar_t YELLOW_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0033};
static wchar_t* YELLOW_FOREGROUND_CONTROL_SEQUENCE = YELLOW_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* YELLOW_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The blue foreground control sequence. */
static wchar_t BLUE_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0034};
static wchar_t* BLUE_FOREGROUND_CONTROL_SEQUENCE = BLUE_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLUE_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) foreground control sequence. */
static wchar_t MAGENTA_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0035};
static wchar_t* MAGENTA_FOREGROUND_CONTROL_SEQUENCE = MAGENTA_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* MAGENTA_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The cobalt blue (china blue) foreground control sequence. */
static wchar_t COBALT_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0036};
static wchar_t* COBALT_FOREGROUND_CONTROL_SEQUENCE = COBALT_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* COBALT_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The white foreground control sequence. */
static wchar_t WHITE_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0033, 0x0037};
static wchar_t* WHITE_FOREGROUND_CONTROL_SEQUENCE = WHITE_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* WHITE_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The black background control sequence. */
static wchar_t BLACK_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0030};
static wchar_t* BLACK_BACKGROUND_CONTROL_SEQUENCE = BLACK_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLACK_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The red background control sequence. */
static wchar_t RED_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0031};
static wchar_t* RED_BACKGROUND_CONTROL_SEQUENCE = RED_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* RED_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The green background control sequence. */
static wchar_t GREEN_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0032};
static wchar_t* GREEN_BACKGROUND_CONTROL_SEQUENCE = GREEN_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* GREEN_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The yellow background control sequence. */
static wchar_t YELLOW_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0033};
static wchar_t* YELLOW_BACKGROUND_CONTROL_SEQUENCE = YELLOW_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* YELLOW_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The blue background control sequence. */
static wchar_t BLUE_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0034};
static wchar_t* BLUE_BACKGROUND_CONTROL_SEQUENCE = BLUE_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLUE_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) background control sequence. */
static wchar_t MAGENTA_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0035};
static wchar_t* MAGENTA_BACKGROUND_CONTROL_SEQUENCE = MAGENTA_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* MAGENTA_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The cobalt blue (china blue) background control sequence. */
static wchar_t COBALT_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0036};
static wchar_t* COBALT_BACKGROUND_CONTROL_SEQUENCE = COBALT_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* COBALT_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The white background control sequence. */
static wchar_t WHITE_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {0x0034, 0x0037};
static wchar_t* WHITE_BACKGROUND_CONTROL_SEQUENCE = WHITE_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* WHITE_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Terminal input control sequences.
//
// Example: The "arrow up" key delivers: ESC[A
//

//?? TODO: These constants should be of type wchar_t in future!
//?? But that means that then also the gnu/linux console input needs to be changed.

/** The arrow up control sequence. */
//?? static char ARROW_UP_CONTROL_SEQUENCE_ARRAY[] = {65};
//?? static char* ARROW_UP_CONTROL_SEQUENCE = ARROW_UP_CONTROL_SEQUENCE_ARRAY;
static wchar_t ARROW_UP_CONTROL_SEQUENCE_ARRAY[] = {0x0041};
static wchar_t* ARROW_UP_CONTROL_SEQUENCE = ARROW_UP_CONTROL_SEQUENCE_ARRAY;
static int* ARROW_UP_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The arrow down control sequence. */
//?? static char ARROW_DOWN_CONTROL_SEQUENCE_ARRAY[] = {66};
//?? static char* ARROW_DOWN_CONTROL_SEQUENCE = ARROW_DOWN_CONTROL_SEQUENCE_ARRAY;
static wchar_t ARROW_DOWN_CONTROL_SEQUENCE_ARRAY[] = {0x0042};
static wchar_t* ARROW_DOWN_CONTROL_SEQUENCE = ARROW_DOWN_CONTROL_SEQUENCE_ARRAY;
static int* ARROW_DOWN_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The arrow left control sequence. */
//?? static char ARROW_LEFT_CONTROL_SEQUENCE_ARRAY[] = {68};
//?? static char* ARROW_LEFT_CONTROL_SEQUENCE = ARROW_LEFT_CONTROL_SEQUENCE_ARRAY;
static wchar_t ARROW_LEFT_CONTROL_SEQUENCE_ARRAY[] = {0x0044};
static wchar_t* ARROW_LEFT_CONTROL_SEQUENCE = ARROW_LEFT_CONTROL_SEQUENCE_ARRAY;
static int* ARROW_LEFT_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The arrow right control sequence. */
//?? static char ARROW_RIGHT_CONTROL_SEQUENCE_ARRAY[] = {67};
//?? static char* ARROW_RIGHT_CONTROL_SEQUENCE = ARROW_RIGHT_CONTROL_SEQUENCE_ARRAY;
static wchar_t ARROW_RIGHT_CONTROL_SEQUENCE_ARRAY[] = {0x0043};
static wchar_t* ARROW_RIGHT_CONTROL_SEQUENCE = ARROW_RIGHT_CONTROL_SEQUENCE_ARRAY;
static int* ARROW_RIGHT_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/* CONSOLE_CONTROL_SEQUENCE_CONSTANTS_SOURCE */
#endif
