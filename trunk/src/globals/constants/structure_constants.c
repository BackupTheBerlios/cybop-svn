/*
 * $RCSfile: structure_constants.c,v $
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
 * @version $Revision: 1.20 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef STRUCTURE_CONSTANTS_SOURCE
#define STRUCTURE_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Primitive.
//

/** The primitive count. */
static int* PRIMITIVE_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The primitive value index. */
static int* PRIMITIVE_VALUE_INDEX = NUMBER_0_INTEGER_ARRAY;

//
// Vectors.
//

/** The character vector reallocate factor. */
static int* CHARACTER_VECTOR_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The wide character vector reallocate factor. */
static int* WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The integer vector reallocate factor. */
static int* INTEGER_VECTOR_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The unsigned long vector reallocate factor. */
static int* UNSIGNED_LONG_VECTOR_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The double vector reallocate factor. */
static int* DOUBLE_VECTOR_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The pointer vector reallocate factor. */
static int* POINTER_VECTOR_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

//
// Fraction.
//

/** The fraction count. */
static int* FRACTION_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The fraction numerator index. */
static int* FRACTION_NUMERATOR_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The fraction denominator index. */
static int* FRACTION_DENOMINATOR_INDEX = NUMBER_1_INTEGER_ARRAY;

//
// Time.
//

/** The time count. */
static int* TIME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The time year index. */
static int* TIME_YEAR_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The time month index. */
static int* TIME_MONTH_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The time day index. */
static int* TIME_DAY_INDEX = NUMBER_2_INTEGER_ARRAY;

/** The time hour index. */
static int* TIME_HOUR_INDEX = NUMBER_3_INTEGER_ARRAY;

/** The time minute index. */
static int* TIME_MINUTE_INDEX = NUMBER_4_INTEGER_ARRAY;

/** The time second index. */
static int* TIME_SECOND_INDEX = NUMBER_5_INTEGER_ARRAY;

//
// Complex.
//

/** The complex count. */
static int* COMPLEX_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The complex real index. */
static int* COMPLEX_REAL_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The complex imaginary index. */
static int* COMPLEX_IMAGINARY_INDEX = NUMBER_1_INTEGER_ARRAY;

//
// Textual user interface (tui).
//

/** The tui reallocate factor. */
static int* TUI_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The tui count. */
static int* TUI_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The tui z dimension index. */
static int* TUI_Z_DIMENSION_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The tui y dimension index. */
static int* TUI_Y_DIMENSION_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The tui x dimension index. */
static int* TUI_X_DIMENSION_INDEX = NUMBER_2_INTEGER_ARRAY;

/** The tui properties index. */
static int* TUI_PROPERTIES_INDEX = NUMBER_3_INTEGER_ARRAY;

//
// Textual user interface (tui) properties.
//

/** The tui properties count. */
static int* TUI_PROPERTIES_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The tui properties character index. */
static int* TUI_PROPERTIES_CHARACTER_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The tui properties bold index. */
static int* TUI_PROPERTIES_BOLD_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The tui properties underline index. */
static int* TUI_PROPERTIES_UNDERLINE_INDEX = NUMBER_2_INTEGER_ARRAY;

/** The tui properties blink index. */
static int* TUI_PROPERTIES_BLINK_INDEX = NUMBER_3_INTEGER_ARRAY;

/** The tui properties inverse index. */
static int* TUI_PROPERTIES_INVERSE_INDEX = NUMBER_4_INTEGER_ARRAY;

/** The tui properties hidden index. */
static int* TUI_PROPERTIES_HIDDEN_INDEX = NUMBER_5_INTEGER_ARRAY;

/** The tui properties foreground index. */
static int* TUI_PROPERTIES_FOREGROUND_INDEX = NUMBER_6_INTEGER_ARRAY;

/** The tui properties background index. */
static int* TUI_PROPERTIES_BACKGROUND_INDEX = NUMBER_7_INTEGER_ARRAY;

//
// Textual user interface (tui) position.
//

/** The tui position x index. */
static int* TUI_POSITION_X_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The tui position y index. */
static int* TUI_POSITION_Y_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The tui position z index. */
static int* TUI_POSITION_Z_INDEX = NUMBER_2_INTEGER_ARRAY;

//
// Textual user interface (tui) size.
//

/** The tui size x index. */
static int* TUI_SIZE_X_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The tui size y index. */
static int* TUI_SIZE_Y_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The tui size z index. */
static int* TUI_SIZE_Z_INDEX = NUMBER_2_INTEGER_ARRAY;

//
// Compound.
//

/** The compound reallocate factor. */
static int* COMPOUND_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The compound count. */
static int* COMPOUND_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The compound names index. */
static int* NAMES_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The compound names counts index. */
static int* NAMES_COUNTS_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The compound names sizes index. */
static int* NAMES_SIZES_INDEX = NUMBER_2_INTEGER_ARRAY;

/** The compound abstractions index. */
static int* ABSTRACTIONS_INDEX = NUMBER_3_INTEGER_ARRAY;

/** The compound abstractions counts index. */
static int* ABSTRACTIONS_COUNTS_INDEX = NUMBER_4_INTEGER_ARRAY;

/** The compound abstractions sizes index. */
static int* ABSTRACTIONS_SIZES_INDEX = NUMBER_5_INTEGER_ARRAY;

/** The compound models index. */
static int* MODELS_INDEX = NUMBER_6_INTEGER_ARRAY;

/** The compound models counts index. */
static int* MODELS_COUNTS_INDEX = NUMBER_7_INTEGER_ARRAY;

/** The compound models sizes index. */
static int* MODELS_SIZES_INDEX = NUMBER_8_INTEGER_ARRAY;

/** The compound details index. */
static int* DETAILS_INDEX = NUMBER_9_INTEGER_ARRAY;

/** The compound details counts index. */
static int* DETAILS_COUNTS_INDEX = NUMBER_10_INTEGER_ARRAY;

/** The compound details sizes index. */
static int* DETAILS_SIZES_INDEX = NUMBER_11_INTEGER_ARRAY;

//
// Signal memory.
//

/** The signal memory reallocate factor. */
static int* SIGNAL_MEMORY_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The signal memory count. */
static int* SIGNAL_MEMORY_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The signals abstractions index. */
static int* SIGNALS_ABSTRACTIONS_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The signals abstractions counts index. */
static int* SIGNALS_ABSTRACTIONS_COUNTS_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The signals models index. */
static int* SIGNALS_MODELS_INDEX = NUMBER_2_INTEGER_ARRAY;

/** The signals models counts index. */
static int* SIGNALS_MODELS_COUNTS_INDEX = NUMBER_3_INTEGER_ARRAY;

/** The signals details index. */
static int* SIGNALS_DETAILS_INDEX = NUMBER_4_INTEGER_ARRAY;

/** The signals details counts index. */
static int* SIGNALS_DETAILS_COUNTS_INDEX = NUMBER_5_INTEGER_ARRAY;

/** The signals priorities index. */
static int* SIGNALS_PRIORITIES_INDEX = NUMBER_6_INTEGER_ARRAY;

/** The signals identifications index. */
static int* SIGNALS_IDENTIFICATIONS_INDEX = NUMBER_7_INTEGER_ARRAY;

//
// Internal memory elements.
//

/** The internal memory elements count. */
static int* INTERNAL_MEMORY_ELEMENTS_COUNT = NUMBER_400_INTEGER_ARRAY;

/** The knowledge memory. */
static int* KNOWLEDGE_MEMORY_INTERNAL = NUMBER_0_INTEGER_ARRAY;
static int* KNOWLEDGE_MEMORY_COUNT_INTERNAL = NUMBER_1_INTEGER_ARRAY;
static int* KNOWLEDGE_MEMORY_SIZE_INTERNAL = NUMBER_2_INTEGER_ARRAY;

/** The signal memory. */
static int* SIGNAL_MEMORY_INTERNAL = NUMBER_3_INTEGER_ARRAY;
static int* SIGNAL_MEMORY_COUNT_INTERNAL = NUMBER_4_INTEGER_ARRAY;
static int* SIGNAL_MEMORY_SIZE_INTERNAL = NUMBER_5_INTEGER_ARRAY;

/** The unix socket. */
static int* UNIX_SOCKET_INTERRUPT_INTERNAL = NUMBER_100_INTEGER_ARRAY;
static int* UNIX_SOCKET_INTERNAL = NUMBER_101_INTEGER_ARRAY;
static int* UNIX_SOCKET_FILENAME_INTERNAL = NUMBER_102_INTEGER_ARRAY;

/** The tcp socket. */
static int* TCP_SOCKET_INTERRUPT_INTERNAL = NUMBER_103_INTEGER_ARRAY;
static int* TCP_SOCKET_INTERNAL = NUMBER_104_INTEGER_ARRAY;
static int* TCP_SOCKET_BLOCKING_INTERNAL = NUMBER_105_INTEGER_ARRAY;

/** The tcp client sockets. */
static int* TCP_CLIENT_SOCKETS_INTERNAL = NUMBER_106_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKETS_COUNT_INTERNAL = NUMBER_107_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKETS_SIZE_INTERNAL = NUMBER_108_INTEGER_ARRAY;

/** The signal identifications. */
static int* TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL = NUMBER_109_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL = NUMBER_110_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL = NUMBER_111_INTEGER_ARRAY;

/** The linux console. */
static int* LINUX_CONSOLE_INTERRUPT_INTERNAL = NUMBER_200_INTEGER_ARRAY;
static int* TERMINAL_FILE_DESCRIPTOR_INTERNAL = NUMBER_201_INTEGER_ARRAY;
static int* TERMINAL_ORIGINAL_ATTRIBUTES_INTERNAL = NUMBER_202_INTEGER_ARRAY;
static int* TERMINAL_WORKING_ATTRIBUTES_INTERNAL = NUMBER_203_INTEGER_ARRAY;
static int* TUI_INTERNAL = NUMBER_204_INTEGER_ARRAY;
static int* TUI_COUNT_INTERNAL = NUMBER_205_INTEGER_ARRAY;
static int* TUI_SIZE_INTERNAL = NUMBER_206_INTEGER_ARRAY;

/** The x window system. */
static int* X_WINDOW_SYSTEM_INTERRUPT_INTERNAL = NUMBER_300_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL = NUMBER_301_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_DISPLAY_INTERNAL = NUMBER_302_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_SCREEN_INTERNAL = NUMBER_303_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL = NUMBER_304_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL = NUMBER_310_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_WINDOW_INTERNAL = NUMBER_311_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL = NUMBER_320_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_BACKGROUND_INTERNAL = NUMBER_321_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_FOREGROUND_INTERNAL = NUMBER_322_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL = NUMBER_330_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL = NUMBER_331_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL = NUMBER_332_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_INTERNAL = NUMBER_333_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_TOP_INTERNAL = NUMBER_334_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL = NUMBER_335_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_FONT_INTERNAL = NUMBER_336_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL = NUMBER_337_INTEGER_ARRAY;

/** The temporary data (for easy handing over to threads within one parameter). */
static int* TEMPORARY_USER_INTERFACE_ROOT_INTERNAL = NUMBER_390_INTEGER_ARRAY;
static int* TEMPORARY_USER_INTERFACE_ROOT_COUNT_INTERNAL = NUMBER_391_INTEGER_ARRAY;
static int* TEMPORARY_USER_INTERFACE_ROOT_SIZE_INTERNAL = NUMBER_392_INTEGER_ARRAY;
static int* TEMPORARY_USER_INTERFACE_COMMANDS_INTERNAL = NUMBER_393_INTEGER_ARRAY;
static int* TEMPORARY_USER_INTERFACE_COMMANDS_COUNT_INTERNAL = NUMBER_394_INTEGER_ARRAY;
static int* TEMPORARY_USER_INTERFACE_COMMANDS_SIZE_INTERNAL = NUMBER_395_INTEGER_ARRAY;

//
// Xml tag.
//

/** The xml tag count. */
static int* XML_TAG_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The xml tag name, attribute, value index. */
static int* XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The xml tag counts index. */
static int* XML_TAG_COUNTS_INDEX = NUMBER_1_INTEGER_ARRAY;

//
// Xml attribute.
//

/** The xml attribute count. */
static int* XML_ATTRIBUTE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The xml attribute name, value index. */
static int* XML_ATTRIBUTE_NAME_VALUE_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The xml attribute counts index. */
static int* XML_ATTRIBUTE_COUNTS_INDEX = NUMBER_1_INTEGER_ARRAY;

/* STRUCTURE_CONSTANTS_SOURCE */
#endif
