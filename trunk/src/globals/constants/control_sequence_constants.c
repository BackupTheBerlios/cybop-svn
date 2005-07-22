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
 * @version $Revision: 1.3 $ $Date: 2005-07-22 07:29:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTROL_SEQUENCE_CONSTANTS_SOURCE
#define CONTROL_SEQUENCE_CONSTANTS_SOURCE

/**
 * The erase display control sequence.
 *
 * ESC[2J
 *
 * Mnemonic:
 * ED (Erase Display)
 */
static const char ERASE_DISPLAY_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '2', 'J'};
static const char* ERASE_DISPLAY_CONTROL_SEQUENCE = ERASE_DISPLAY_CONTROL_SEQUENCE_ARRAY;
static const int ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT = ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT_ARRAY;

/**
 * The erase line control sequence.
 *
 * ESC[K
 *
 * Mnemonic:
 * EL (Erase Line)
 */
static const char ERASE_LINE_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', 'K'};
static const char* ERASE_LINE_CONTROL_SEQUENCE = ERASE_LINE_CONTROL_SEQUENCE_ARRAY;
static const int ERASE_LINE_CONTROL_SEQUENCE_COUNT_ARRAY[] = {3};
static const int* ERASE_LINE_CONTROL_SEQUENCE_COUNT = ERASE_LINE_CONTROL_SEQUENCE_COUNT_ARRAY;

/**
 * The cursor position control sequence.
 *
 * ESC[P;PH
 *
 * Mnemonic:
 * CUP (Cursor Position)
 * HVP (Horizontal and Vertical Position)
 */
static const char CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', 'x', 'H'};
static const char* CURSOR_POSITION_CONTROL_SEQUENCE = CURSOR_POSITION_CONTROL_SEQUENCE_ARRAY;
static const int CURSOR_POSITION_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* CURSOR_POSITION_CONTROL_SEQUENCE_COUNT = CURSOR_POSITION_CONTROL_SEQUENCE_COUNT_ARRAY;

//
// The set graphics rendition control sequences.
//
// ESC[P;...;Pm
//
// Mnemonic:
// SGR (Set Graphics Rendition)
//

/** The attribute off control sequence. */
static const char ATTRIBUTE_OFF_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '0', 'm'};
static const char* ATTRIBUTE_OFF_CONTROL_SEQUENCE = ATTRIBUTE_OFF_CONTROL_SEQUENCE_ARRAY;
static const int ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT = ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The bold control sequence. */
static const char BOLD_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '1', 'm'};
static const char* BOLD_CONTROL_SEQUENCE = BOLD_CONTROL_SEQUENCE_ARRAY;
static const int BOLD_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* BOLD_CONTROL_SEQUENCE_COUNT = BOLD_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The underline control sequence. */
static const char UNDERLINE_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '4', 'm'};
static const char* UNDERLINE_CONTROL_SEQUENCE = UNDERLINE_CONTROL_SEQUENCE_ARRAY;
static const int UNDERLINE_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* UNDERLINE_CONTROL_SEQUENCE_COUNT = UNDERLINE_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The blink control sequence. */
static const char BLINK_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '5', 'm'};
static const char* BLINK_CONTROL_SEQUENCE = BLINK_CONTROL_SEQUENCE_ARRAY;
static const int BLINK_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* BLINK_CONTROL_SEQUENCE_COUNT = BLINK_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The inverse control sequence. */
static const char INVERSE_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '7', 'm'};
static const char* INVERSE_CONTROL_SEQUENCE = INVERSE_CONTROL_SEQUENCE_ARRAY;
static const int INVERSE_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* INVERSE_CONTROL_SEQUENCE_COUNT = INVERSE_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The hidden control sequence. */
static const char HIDDEN_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '8', 'm'};
static const char* HIDDEN_CONTROL_SEQUENCE = HIDDEN_CONTROL_SEQUENCE_ARRAY;
static const int HIDDEN_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* HIDDEN_CONTROL_SEQUENCE_COUNT = HIDDEN_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The black foreground control sequence. */
static const char BLACK_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '30', 'm'};
static const char* BLACK_FOREGROUND_CONTROL_SEQUENCE = BLACK_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int BLACK_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* BLACK_FOREGROUND_CONTROL_SEQUENCE_COUNT = BLACK_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The red foreground control sequence. */
static const char RED_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '31', 'm'};
static const char* RED_FOREGROUND_CONTROL_SEQUENCE = RED_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int RED_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* RED_FOREGROUND_CONTROL_SEQUENCE_COUNT = RED_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The green foreground control sequence. */
static const char GREEN_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '32', 'm'};
static const char* GREEN_FOREGROUND_CONTROL_SEQUENCE = GREEN_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int GREEN_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* GREEN_FOREGROUND_CONTROL_SEQUENCE_COUNT = GREEN_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The yellow foreground control sequence. */
static const char YELLOW_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '33', 'm'};
static const char* YELLOW_FOREGROUND_CONTROL_SEQUENCE = YELLOW_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int YELLOW_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* YELLOW_FOREGROUND_CONTROL_SEQUENCE_COUNT = YELLOW_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The blue foreground control sequence. */
static const char BLUE_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '34', 'm'};
static const char* BLUE_FOREGROUND_CONTROL_SEQUENCE = BLUE_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int BLUE_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* BLUE_FOREGROUND_CONTROL_SEQUENCE_COUNT = BLUE_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The magenta (violet, purple, mauve) foreground control sequence. */
static const char MAGENTA_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '35', 'm'};
static const char* MAGENTA_FOREGROUND_CONTROL_SEQUENCE = MAGENTA_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int MAGENTA_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* MAGENTA_FOREGROUND_CONTROL_SEQUENCE_COUNT = MAGENTA_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The cobalt blue (china blue) foreground control sequence. */
static const char COBALT_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '36', 'm'};
static const char* COBALT_FOREGROUND_CONTROL_SEQUENCE = COBALT_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int COBALT_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* COBALT_FOREGROUND_CONTROL_SEQUENCE_COUNT = COBALT_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The white foreground control sequence. */
static const char WHITE_FOREGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '37', 'm'};
static const char* WHITE_FOREGROUND_CONTROL_SEQUENCE = WHITE_FOREGROUND_CONTROL_SEQUENCE_ARRAY;
static const int WHITE_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* WHITE_FOREGROUND_CONTROL_SEQUENCE_COUNT = WHITE_FOREGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The black background control sequence. */
static const char BLACK_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '40', 'm'};
static const char* BLACK_BACKGROUND_CONTROL_SEQUENCE = BLACK_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int BLACK_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* BLACK_BACKGROUND_CONTROL_SEQUENCE_COUNT = BLACK_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The red background control sequence. */
static const char RED_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '41', 'm'};
static const char* RED_BACKGROUND_CONTROL_SEQUENCE = RED_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int RED_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* RED_BACKGROUND_CONTROL_SEQUENCE_COUNT = RED_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The green background control sequence. */
static const char GREEN_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '42', 'm'};
static const char* GREEN_BACKGROUND_CONTROL_SEQUENCE = GREEN_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int GREEN_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* GREEN_BACKGROUND_CONTROL_SEQUENCE_COUNT = GREEN_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The yellow background control sequence. */
static const char YELLOW_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '43', 'm'};
static const char* YELLOW_BACKGROUND_CONTROL_SEQUENCE = YELLOW_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int YELLOW_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* YELLOW_BACKGROUND_CONTROL_SEQUENCE_COUNT = YELLOW_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The blue background control sequence. */
static const char BLUE_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '44', 'm'};
static const char* BLUE_BACKGROUND_CONTROL_SEQUENCE = BLUE_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int BLUE_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* BLUE_BACKGROUND_CONTROL_SEQUENCE_COUNT = BLUE_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The magenta (violet, purple, mauve) background control sequence. */
static const char MAGENTA_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '45', 'm'};
static const char* MAGENTA_BACKGROUND_CONTROL_SEQUENCE = MAGENTA_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int MAGENTA_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* MAGENTA_BACKGROUND_CONTROL_SEQUENCE_COUNT = MAGENTA_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The cobalt blue (china blue) background control sequence. */
static const char COBALT_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '46', 'm'};
static const char* COBALT_BACKGROUND_CONTROL_SEQUENCE = COBALT_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int COBALT_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* COBALT_BACKGROUND_CONTROL_SEQUENCE_COUNT = COBALT_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/** The white background control sequence. */
static const char WHITE_BACKGROUND_CONTROL_SEQUENCE_ARRAY[] = {'\033', '[', '47', 'm'};
static const char* WHITE_BACKGROUND_CONTROL_SEQUENCE = WHITE_BACKGROUND_CONTROL_SEQUENCE_ARRAY;
static const int WHITE_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY[] = {4};
static const int* WHITE_BACKGROUND_CONTROL_SEQUENCE_COUNT = WHITE_BACKGROUND_CONTROL_SEQUENCE_COUNT_ARRAY;

/* CONTROL_SEQUENCE_CONSTANTS_SOURCE */
#endif
