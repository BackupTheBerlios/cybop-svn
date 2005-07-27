/*
 * $RCSfile: control_sequence_constants.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2005-07-27 23:10:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTROL_SEQUENCE_CONSTANTS_SOURCE
#define CONTROL_SEQUENCE_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

/**
 * The erase display control sequence.
 *
 * ESC[2J
 *
 * Mnemonic:
 * ED (Erase Display)
 */
static char ERASE_DISPLAY_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '2', 'J'};
static char* ERASE_DISPLAY_CONTROL_SEQUENCE = ERASE_DISPLAY_CONTROL_SEQUENCE_ARRAY;
static int* ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The erase line control sequence.
 *
 * ESC[K
 *
 * Mnemonic:
 * EL (Erase Line)
 */
static char ERASE_LINE_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', 'K'};
static char* ERASE_LINE_CONTROL_SEQUENCE = ERASE_LINE_CONTROL_SEQUENCE_ARRAY;
static int* ERASE_LINE_CONTROL_SEQUENCE_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The cursor position control sequence.
 *
 * ESC[P;PH
 *
 * Mnemonic:
 * CUP (Cursor Position)
 * HVP (Horizontal and Vertical Position)
 */
static char CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', 'x', 'H'};
static char* CURSOR_POSITION_CONTROL_SEQUENCE = CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY;
static int* CURSOR_POSITION_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

//
// The set graphics rendition control sequences.
//
// ESC[P;...;Pm
//
// Mnemonic:
// SGR (Set Graphics Rendition)
//

/** The attribute off control sequence. */
static char ATTRIBUTE_OFF_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '0', 'm'};
static char* ATTRIBUTE_OFF_CONTROL_SEQUENCE = ATTRIBUTE_OFF_CONTROL_SEQUENCE_ARRAY;
static int* ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The bold control sequence. */
static char BOLD_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '1', 'm'};
static char* BOLD_CONTROL_SEQUENCE = BOLD_CONTROL_SEQUENCE_ARRAY;
static int* BOLD_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The underline control sequence. */
static char UNDERLINE_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '4', 'm'};
static char* UNDERLINE_CONTROL_SEQUENCE = UNDERLINE_CONTROL_SEQUENCE_ARRAY;
static int* UNDERLINE_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The blink control sequence. */
static char BLINK_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '5', 'm'};
static char* BLINK_CONTROL_SEQUENCE = BLINK_CONTROL_SEQUENCE_ARRAY;
static int* BLINK_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The inverse control sequence. */
static char INVERSE_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '7', 'm'};
static char* INVERSE_CONTROL_SEQUENCE = INVERSE_CONTROL_SEQUENCE_ARRAY;
static int* INVERSE_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The hidden control sequence. */
static char HIDDEN_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '8', 'm'};
static char* HIDDEN_CONTROL_SEQUENCE = HIDDEN_CONTROL_SEQUENCE_ARRAY;
static int* HIDDEN_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The black foreground control sequence. */
static int BLACK_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {30};
static int* BLACK_FOREGROUND_CONTROL_SEQUENCE = BLACK_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLACK_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The red foreground control sequence. */
static int RED_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {31};
static int* RED_FOREGROUND_CONTROL_SEQUENCE = RED_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* RED_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The green foreground control sequence. */
static int GREEN_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {32};
static int* GREEN_FOREGROUND_CONTROL_SEQUENCE = GREEN_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* GREEN_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The yellow foreground control sequence. */
static int YELLOW_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {33};
static int* YELLOW_FOREGROUND_CONTROL_SEQUENCE = YELLOW_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* YELLOW_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The blue foreground control sequence. */
static int BLUE_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {34};
static int* BLUE_FOREGROUND_CONTROL_SEQUENCE = BLUE_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLUE_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) foreground control sequence. */
static int MAGENTA_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {35};
static int* MAGENTA_FOREGROUND_CONTROL_SEQUENCE = MAGENTA_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* MAGENTA_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The cobalt blue (china blue) foreground control sequence. */
static int COBALT_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {36};
static int* COBALT_FOREGROUND_CONTROL_SEQUENCE = COBALT_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* COBALT_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The white foreground control sequence. */
static int WHITE_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {37};
static int* WHITE_FOREGROUND_CONTROL_SEQUENCE = WHITE_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static int* WHITE_FOREGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The black background control sequence. */
static int BLACK_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {40};
static int* BLACK_BACKGROUND_CONTROL_SEQUENCE = BLACK_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLACK_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The red background control sequence. */
static int RED_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {41};
static int* RED_BACKGROUND_CONTROL_SEQUENCE = RED_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* RED_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The green background control sequence. */
static int GREEN_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {42};
static int* GREEN_BACKGROUND_CONTROL_SEQUENCE = GREEN_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* GREEN_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The yellow background control sequence. */
static int YELLOW_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {43};
static int* YELLOW_BACKGROUND_CONTROL_SEQUENCE = YELLOW_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* YELLOW_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The blue background control sequence. */
static int BLUE_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {44};
static int* BLUE_BACKGROUND_CONTROL_SEQUENCE = BLUE_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* BLUE_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The magenta (violet, purple, mauve) background control sequence. */
static int MAGENTA_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {45};
static int* MAGENTA_BACKGROUND_CONTROL_SEQUENCE = MAGENTA_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* MAGENTA_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The cobalt blue (china blue) background control sequence. */
static int COBALT_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {46};
static int* COBALT_BACKGROUND_CONTROL_SEQUENCE = COBALT_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* COBALT_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The white background control sequence. */
static int WHITE_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {47};
static int* WHITE_BACKGROUND_CONTROL_SEQUENCE = WHITE_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static int* WHITE_BACKGROUND_CONTROL_SEQUENCE_COUNT = NUMBER_1_INTEGER_ARRAY;

/* CONTROL_SEQUENCE_CONSTANTS_SOURCE */
#endif
