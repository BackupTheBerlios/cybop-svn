/*
 * $RCSfile: structure_constants.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.30 $ $Date: 2006-12-28 16:04:26 $ $Author: christian $
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
// User interface (ui) position.
//

/** The ui position x index. */
static int* UI_POSITION_X_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The ui position y index. */
static int* UI_POSITION_Y_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The ui position z index. */
static int* UI_POSITION_Z_INDEX = NUMBER_2_INTEGER_ARRAY;

//
// User interface (ui) size.
//

/** The ui size x index. */
static int* UI_SIZE_X_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The ui size y index. */
static int* UI_SIZE_Y_INDEX = NUMBER_1_INTEGER_ARRAY;

/** The ui size z index. */
static int* UI_SIZE_Z_INDEX = NUMBER_2_INTEGER_ARRAY;

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
static int* INTERNAL_MEMORY_ELEMENTS_COUNT = NUMBER_10000_INTEGER_ARRAY;

/** The knowledge memory. */
static int* KNOWLEDGE_MEMORY_INTERNAL = NUMBER_0_INTEGER_ARRAY;
static int* KNOWLEDGE_MEMORY_COUNT_INTERNAL = NUMBER_1_INTEGER_ARRAY;
static int* KNOWLEDGE_MEMORY_SIZE_INTERNAL = NUMBER_2_INTEGER_ARRAY;

/** The signal memory. */
static int* SIGNAL_MEMORY_INTERNAL = NUMBER_3_INTEGER_ARRAY;
static int* SIGNAL_MEMORY_COUNT_INTERNAL = NUMBER_4_INTEGER_ARRAY;
static int* SIGNAL_MEMORY_SIZE_INTERNAL = NUMBER_5_INTEGER_ARRAY;
static int* SIGNAL_MEMORY_MUTEX_INTERNAL = NUMBER_6_INTEGER_ARRAY;

/** The interrupt request flag. */
static int* INTERRUPT_REQUEST_INTERNAL = NUMBER_10_INTEGER_ARRAY;

/** The linux console. */
static int* LINUX_CONSOLE_FILE_DESCRIPTOR_INTERNAL = NUMBER_100_INTEGER_ARRAY;
static int* LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL = NUMBER_101_INTEGER_ARRAY;
static int* LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL = NUMBER_102_INTEGER_ARRAY;
static int* LINUX_CONSOLE_MUTEX_INTERNAL = NUMBER_103_INTEGER_ARRAY;
static int* LINUX_CONSOLE_INTERNAL = NUMBER_110_INTEGER_ARRAY;
static int* LINUX_CONSOLE_COUNT_INTERNAL = NUMBER_111_INTEGER_ARRAY;
static int* LINUX_CONSOLE_SIZE_INTERNAL = NUMBER_112_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_ROOT_INTERNAL = NUMBER_190_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_ROOT_COUNT_INTERNAL = NUMBER_191_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_ROOT_SIZE_INTERNAL = NUMBER_192_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_COMMANDS_INTERNAL = NUMBER_193_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_COMMANDS_COUNT_INTERNAL = NUMBER_194_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_COMMANDS_SIZE_INTERNAL = NUMBER_195_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL = NUMBER_196_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL = NUMBER_197_INTEGER_ARRAY;
static int* LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL = NUMBER_198_INTEGER_ARRAY;

/** The x window system. */
static int* X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL = NUMBER_200_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_DISPLAY_INTERNAL = NUMBER_201_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_SCREEN_INTERNAL = NUMBER_202_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL = NUMBER_203_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_MUTEX_INTERNAL = NUMBER_204_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL = NUMBER_210_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_WINDOW_INTERNAL = NUMBER_211_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL = NUMBER_220_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_BACKGROUND_INTERNAL = NUMBER_221_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_FOREGROUND_INTERNAL = NUMBER_222_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL = NUMBER_230_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL = NUMBER_231_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL = NUMBER_232_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_INTERNAL = NUMBER_233_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_TOP_INTERNAL = NUMBER_234_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL = NUMBER_235_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_FONT_INTERNAL = NUMBER_236_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL = NUMBER_237_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL = NUMBER_290_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL = NUMBER_291_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL = NUMBER_292_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL = NUMBER_293_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL = NUMBER_294_INTEGER_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL = NUMBER_295_INTEGER_ARRAY;

/**
 * The server socket base numbers.
 * There is one for each service.
 * The difference between base numbers depends on the amount of index numbers.
 * See further below!
 */
static int* TCP_MUX_BASE_INTERNAL = NUMBER_500_INTEGER_ARRAY;
static int* FTP_DATA_BASE_INTERNAL = NUMBER_520_INTEGER_ARRAY;
static int* FTP_BASE_INTERNAL = NUMBER_540_INTEGER_ARRAY;
static int* FSP_BASE_INTERNAL = NUMBER_560_INTEGER_ARRAY;
static int* SSH_BASE_INTERNAL = NUMBER_580_INTEGER_ARRAY;
static int* TELNET_BASE_INTERNAL = NUMBER_600_INTEGER_ARRAY;
static int* SMTP_BASE_INTERNAL = NUMBER_620_INTEGER_ARRAY;
static int* WWW_BASE_INTERNAL = NUMBER_640_INTEGER_ARRAY;
static int* POP3_BASE_INTERNAL = NUMBER_660_INTEGER_ARRAY;
static int* HTTPS_BASE_INTERNAL = NUMBER_680_INTEGER_ARRAY;

/** The server socket index numbers, to be added on top of a base number. */
static int* SERVER_SOCKET_INTERNAL = NUMBER_1_INTEGER_ARRAY;
static int* SERVER_SOCKET_ADDRESS_INTERNAL = NUMBER_2_INTEGER_ARRAY;
static int* SERVER_SOCKET_ADDRESS_SIZE_INTERNAL = NUMBER_3_INTEGER_ARRAY;
static int* SERVER_SOCKET_BLOCKING_INTERNAL = NUMBER_4_INTEGER_ARRAY;
static int* SERVER_SOCKET_MUTEX_INTERNAL = NUMBER_5_INTEGER_ARRAY;
static int* SERVER_SOCKET_THREAD_COMMANDS_INTERNAL = NUMBER_6_INTEGER_ARRAY;
static int* SERVER_SOCKET_THREAD_COMMANDS_COUNT_INTERNAL = NUMBER_7_INTEGER_ARRAY;
static int* SERVER_SOCKET_THREAD_COMMANDS_SIZE_INTERNAL = NUMBER_8_INTEGER_ARRAY;
static int* SERVER_SOCKET_THREAD_CHARACTER_BUFFER_INTERNAL = NUMBER_9_INTEGER_ARRAY;
static int* SERVER_SOCKET_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL = NUMBER_10_INTEGER_ARRAY;
static int* SERVER_SOCKET_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL = NUMBER_11_INTEGER_ARRAY;

/** The tcp client sockets. */
static int* TCP_CLIENT_SOCKETS_INTERNAL = NUMBER_700_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKETS_COUNT_INTERNAL = NUMBER_701_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKETS_SIZE_INTERNAL = NUMBER_702_INTEGER_ARRAY;

/** The signal identifications. */
static int* TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL = NUMBER_710_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL = NUMBER_711_INTEGER_ARRAY;
static int* TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL = NUMBER_712_INTEGER_ARRAY;

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
