/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: escape_control_sequence_gnu_linux_console_model.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_SOURCE
#define ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/**
 * The prefix escape control sequence linux console model.
 *
 * ESC[
 */
static wchar_t ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x001B, 0x005B};
static wchar_t* ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The erase display escape control sequence linux console model.
 *
 * ESC[2J
 *
 * Mnemonic:
 * ED (Erase Display)
 */
static wchar_t ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0032, 0x004A};
static wchar_t* ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The erase line escape control sequence linux console model.
 *
 * ESC[K
 *
 * Mnemonic:
 * EL (Erase Line)
 */
static wchar_t ERASE_LINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x004B};
static wchar_t* ERASE_LINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ERASE_LINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ERASE_LINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The cursor position escape control sequence linux console model.
 *
 * ESC[P;PH
 *
 * Mnemonic:
 * CUP (Cursor Position)
 * HVP (Horizontal and Vertical Position)
 */
static wchar_t CURSOR_POSITION_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0078, 0x0048};
static wchar_t* CURSOR_POSITION_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = CURSOR_POSITION_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* CURSOR_POSITION_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

//
// The set graphics rendition escape control sequence linux console models.
//
// ESC[P;...;Pm
//
// Mnemonic:
// SGR (Set Graphics Rendition)
//

/** The attribute suffix escape control sequence linux console model. */
static wchar_t ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x006D};
static wchar_t* ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The attribute off escape control sequence linux console model. */
static wchar_t ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0030, 0x006D};
static wchar_t* ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The bold escape control sequence linux console model. */
static wchar_t BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0031, 0x006D};
static wchar_t* BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* BOLD_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The underline escape control sequence linux console model. */
static wchar_t UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x006D};
static wchar_t* UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* UNDERLINE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The blink escape control sequence linux console model. */
static wchar_t BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0035, 0x006D};
static wchar_t* BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* BLINK_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The inverse escape control sequence linux console model. */
static wchar_t INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0037, 0x006D};
static wchar_t* INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* INVERSE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The hidden escape control sequence linux console model. */
static wchar_t HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0038, 0x006D};
static wchar_t* HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* HIDDEN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The black foreground escape control sequence linux console model. */
static wchar_t BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0030};
static wchar_t* BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* BLACK_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The red foreground escape control sequence linux console model. */
static wchar_t RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0031};
static wchar_t* RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* RED_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The green foreground escape control sequence linux console model. */
static wchar_t GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0032};
static wchar_t* GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* GREEN_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The yellow foreground escape control sequence linux console model. */
static wchar_t YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0033};
static wchar_t* YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* YELLOW_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The blue foreground escape control sequence linux console model. */
static wchar_t BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0034};
static wchar_t* BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* BLUE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The magenta (violet, purple, mauve) foreground escape control sequence linux console model. */
static wchar_t MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0035};
static wchar_t* MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* MAGENTA_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The cobalt blue (china blue) foreground escape control sequence linux console model. */
static wchar_t COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0036};
static wchar_t* COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* COBALT_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The white foreground escape control sequence linux console model. */
static wchar_t WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0033, 0x0037};
static wchar_t* WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* WHITE_FOREGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The black background escape control sequence linux console model. */
static wchar_t BLACK_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0030};
static wchar_t* BLACK_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = BLACK_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* BLACK_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The red background escape control sequence linux console model. */
static wchar_t RED_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0031};
static wchar_t* RED_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = RED_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* RED_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The green background escape control sequence linux console model. */
static wchar_t GREEN_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0032};
static wchar_t* GREEN_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = GREEN_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* GREEN_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The yellow background escape control sequence linux console model. */
static wchar_t YELLOW_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0033};
static wchar_t* YELLOW_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = YELLOW_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* YELLOW_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The blue background escape control sequence linux console model. */
static wchar_t BLUE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0034};
static wchar_t* BLUE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = BLUE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* BLUE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The magenta (violet, purple, mauve) background escape control sequence linux console model. */
static wchar_t MAGENTA_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0035};
static wchar_t* MAGENTA_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = MAGENTA_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* MAGENTA_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The cobalt blue (china blue) background escape control sequence linux console model. */
static wchar_t COBALT_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0036};
static wchar_t* COBALT_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = COBALT_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* COBALT_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The white background escape control sequence linux console model. */
static wchar_t WHITE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0034, 0x0037};
static wchar_t* WHITE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = WHITE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* WHITE_BACKGROUND_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

//
// Terminal input escape control sequence linux console models.
//
// Example: The "arrow up" key delivers: ESC[A
//

/** The arrow up escape control sequence linux console model. */
static wchar_t ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0041};
static wchar_t* ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ARROW_UP_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The arrow down escape control sequence linux console model. */
static wchar_t ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0042};
static wchar_t* ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ARROW_DOWN_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The arrow left escape control sequence linux console model. */
static wchar_t ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0044};
static wchar_t* ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ARROW_LEFT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The arrow right escape control sequence linux console model. */
static wchar_t ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY[] = {0x0043};
static wchar_t* ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL = ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_ARRAY;
static int* ARROW_RIGHT_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/* ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_SOURCE */
#endif
