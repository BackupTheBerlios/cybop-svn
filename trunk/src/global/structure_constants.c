/*
 * $RCSfile: structure_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.22 $ $Date: 2005-03-22 00:24:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef STRUCTURE_CONSTANTS_SOURCE
#define STRUCTURE_CONSTANTS_SOURCE

//
// Arrays.
//

/** The character array constant. */
static const int CHARACTER_ARRAY_ARRAY[] = {2};
static const int* CHARACTER_ARRAY = CHARACTER_ARRAY_ARRAY;

/** The pointer array constant. */
static const int POINTER_ARRAY_ARRAY[] = {0};
static const int* POINTER_ARRAY = POINTER_ARRAY_ARRAY;

/** The integer array constant. */
static const int INTEGER_ARRAY_ARRAY[] = {1};
static const int* INTEGER_ARRAY = INTEGER_ARRAY_ARRAY;

/** The unsigned long array constant. */
static const int UNSIGNED_LONG_ARRAY_ARRAY[] = {1};
static const int* UNSIGNED_LONG_ARRAY = UNSIGNED_LONG_ARRAY_ARRAY;

/** The double array constant. */
static const int DOUBLE_ARRAY_ARRAY[] = {3};
static const int* DOUBLE_ARRAY = DOUBLE_ARRAY_ARRAY;

//
// Character.
//

/** The character count. */
static const int CHARACTER_COUNT_ARRAY[] = {1};
static const int* CHARACTER_COUNT = CHARACTER_COUNT_ARRAY;

/** The character value index. */
static const int CHARACTER_VALUE_INDEX_ARRAY[] = {0};
static const int* CHARACTER_VALUE_INDEX = CHARACTER_VALUE_INDEX_ARRAY;

//
// String.
//

/** The string resize factor. */
static const int STRING_RESIZE_FACTOR_ARRAY[] = {2};
static const int* STRING_RESIZE_FACTOR = STRING_RESIZE_FACTOR_ARRAY;

//
// Pointer.
//

/** The pointer count. */
static const int POINTER_COUNT_ARRAY[] = {1};
static const int* POINTER_COUNT = POINTER_COUNT_ARRAY;

/** The pointer value index. */
static const int POINTER_VALUE_INDEX_ARRAY[] = {0};
static const int* POINTER_VALUE_INDEX = POINTER_VALUE_INDEX_ARRAY;

//
// Integer.
//

/** The integer count. */
static const int INTEGER_COUNT_ARRAY[] = {1};
static const int* INTEGER_COUNT = INTEGER_COUNT_ARRAY;

/** The integer value index. */
static const int INTEGER_VALUE_INDEX_ARRAY[] = {0};
static const int* INTEGER_VALUE_INDEX = INTEGER_VALUE_INDEX_ARRAY;

//
// Unsigned long.
//

/** The unsigned long count. */
static const int UNSIGNED_LONG_COUNT_ARRAY[] = {1};
static const int* UNSIGNED_LONG_COUNT = UNSIGNED_LONG_COUNT_ARRAY;

/** The unsigned long value index. */
static const int UNSIGNED_LONG_VALUE_INDEX_ARRAY[] = {0};
static const int* UNSIGNED_LONG_VALUE_INDEX = UNSIGNED_LONG_VALUE_INDEX_ARRAY;

//
// Double.
//

/** The double count. */
static const int DOUBLE_COUNT_ARRAY[] = {1};
static const int* DOUBLE_COUNT = DOUBLE_COUNT_ARRAY;

/** The double value index. */
static const int DOUBLE_VALUE_INDEX_ARRAY[] = {0};
static const int* DOUBLE_VALUE_INDEX = DOUBLE_VALUE_INDEX_ARRAY;

//
// Fraction.
//

/** The fraction count. */
static const int FRACTION_COUNT_ARRAY[] = {2};
static const int* FRACTION_COUNT = FRACTION_COUNT_ARRAY;

/** The numerator index. */
static const int NUMERATOR_INDEX_ARRAY[] = {0};
static const int* NUMERATOR_INDEX = NUMERATOR_INDEX_ARRAY;

/** The denominator index. */
static const int DENOMINATOR_INDEX_ARRAY[] = {1};
static const int* DENOMINATOR_INDEX = DENOMINATOR_INDEX_ARRAY;

//
// Vector.
//

/** The vector count. */
static const int VECTOR_COUNT_ARRAY[] = {3};
static const int* VECTOR_COUNT = VECTOR_COUNT_ARRAY;

/** The x index. */
static const int X_INDEX_ARRAY[] = {0};
static const int* X_INDEX = X_INDEX_ARRAY;

/** The y index. */
static const int Y_INDEX_ARRAY[] = {1};
static const int* Y_INDEX = Y_INDEX_ARRAY;

/** The z index. */
static const int Z_INDEX_ARRAY[] = {2};
static const int* Z_INDEX = Z_INDEX_ARRAY;

//
// Time.
//

/** The time count. */
static const int TIME_COUNT_ARRAY[] = {6};
static const int* TIME_COUNT = TIME_COUNT_ARRAY;

/** The year index. */
static const int YEAR_INDEX_ARRAY[] = {0};
static const int* YEAR_INDEX = YEAR_INDEX_ARRAY;

/** The month index. */
static const int MONTH_INDEX_ARRAY[] = {1};
static const int* MONTH_INDEX = MONTH_INDEX_ARRAY;

/** The day index. */
static const int DAY_INDEX_ARRAY[] = {2};
static const int* DAY_INDEX = DAY_INDEX_ARRAY;

/** The hour index. */
static const int HOUR_INDEX_ARRAY[] = {3};
static const int* HOUR_INDEX = HOUR_INDEX_ARRAY;

/** The minute index. */
static const int MINUTE_INDEX_ARRAY[] = {4};
static const int* MINUTE_INDEX = MINUTE_INDEX_ARRAY;

/** The second index. */
static const int SECOND_INDEX_ARRAY[] = {5};
static const int* SECOND_INDEX = SECOND_INDEX_ARRAY;

//
// Complex.
//

/** The complex count. */
static const int COMPLEX_COUNT_ARRAY[] = {2};
static const int* COMPLEX_COUNT = COMPLEX_COUNT_ARRAY;

/** The real index. */
static const int REAL_INDEX_ARRAY[] = {0};
static const int* REAL_INDEX = REAL_INDEX_ARRAY;

/** The imaginary index. */
static const int IMAGINARY_INDEX_ARRAY[] = {1};
static const int* IMAGINARY_INDEX = IMAGINARY_INDEX_ARRAY;

//
// Compound.
//

/** The compound resize factor. */
static const int COMPOUND_RESIZE_FACTOR_ARRAY[] = {2};
static const int* COMPOUND_RESIZE_FACTOR = COMPOUND_RESIZE_FACTOR_ARRAY;

/** The compound count. */
static const int COMPOUND_COUNT_ARRAY[] = {12};
static const int* COMPOUND_COUNT = COMPOUND_COUNT_ARRAY;

/** The names index. */
static const int NAMES_INDEX_ARRAY[] = {0};
static const int* NAMES_INDEX = NAMES_INDEX_ARRAY;

/** The names counts index. */
static const int NAMES_COUNTS_INDEX_ARRAY[] = {1};
static const int* NAMES_COUNTS_INDEX = NAMES_COUNTS_INDEX_ARRAY;

/** The names sizes index. */
static const int NAMES_SIZES_INDEX_ARRAY[] = {2};
static const int* NAMES_SIZES_INDEX = NAMES_SIZES_INDEX_ARRAY;

/** The abstractions index. */
static const int ABSTRACTIONS_INDEX_ARRAY[] = {3};
static const int* ABSTRACTIONS_INDEX = ABSTRACTIONS_INDEX_ARRAY;

/** The abstractions counts index. */
static const int ABSTRACTIONS_COUNTS_INDEX_ARRAY[] = {4};
static const int* ABSTRACTIONS_COUNTS_INDEX = ABSTRACTIONS_COUNTS_INDEX_ARRAY;

/** The abstractions sizes index. */
static const int ABSTRACTIONS_SIZES_INDEX_ARRAY[] = {5};
static const int* ABSTRACTIONS_SIZES_INDEX = ABSTRACTIONS_SIZES_INDEX_ARRAY;

/** The models index. */
static const int MODELS_INDEX_ARRAY[] = {6};
static const int* MODELS_INDEX = MODELS_INDEX_ARRAY;

/** The models counts index. */
static const int MODELS_COUNTS_INDEX_ARRAY[] = {7};
static const int* MODELS_COUNTS_INDEX = MODELS_COUNTS_INDEX_ARRAY;

/** The models sizes index. */
static const int MODELS_SIZES_INDEX_ARRAY[] = {8};
static const int* MODELS_SIZES_INDEX = MODELS_SIZES_INDEX_ARRAY;

/** The details index. */
static const int DETAILS_INDEX_ARRAY[] = {9};
static const int* DETAILS_INDEX = DETAILS_INDEX_ARRAY;

/** The details counts index. */
static const int DETAILS_COUNTS_INDEX_ARRAY[] = {10};
static const int* DETAILS_COUNTS_INDEX = DETAILS_COUNTS_INDEX_ARRAY;

/** The details sizes index. */
static const int DETAILS_SIZES_INDEX_ARRAY[] = {11};
static const int* DETAILS_SIZES_INDEX = DETAILS_SIZES_INDEX_ARRAY;

//
// Internals memory elements.
//

/** The internals memory elements count. */
static const int INTERNALS_MEMORY_ELEMENTS_COUNT_ARRAY[] = {40};
static const int* INTERNALS_MEMORY_ELEMENTS_COUNT = INTERNALS_MEMORY_ELEMENTS_COUNT_ARRAY;

/** The startup parameters. */
static const int STARTUP_CHANNEL_INTERNAL_ARRAY[] = {0};
static const int* STARTUP_CHANNEL_INTERNAL = STARTUP_CHANNEL_INTERNAL_ARRAY;

static const int STARTUP_CHANNEL_COUNT_INTERNAL_ARRAY[] = {1};
static const int* STARTUP_CHANNEL_COUNT_INTERNAL = STARTUP_CHANNEL_COUNT_INTERNAL_ARRAY;

static const int STARTUP_CHANNEL_SIZE_INTERNAL_ARRAY[] = {2};
static const int* STARTUP_CHANNEL_SIZE_INTERNAL = STARTUP_CHANNEL_SIZE_INTERNAL_ARRAY;

static const int STARTUP_ABSTRACTION_INTERNAL_ARRAY[] = {3};
static const int* STARTUP_ABSTRACTION_INTERNAL = STARTUP_ABSTRACTION_INTERNAL_ARRAY;

static const int STARTUP_ABSTRACTION_COUNT_INTERNAL_ARRAY[] = {4};
static const int* STARTUP_ABSTRACTION_COUNT_INTERNAL = STARTUP_ABSTRACTION_COUNT_INTERNAL_ARRAY;

static const int STARTUP_ABSTRACTION_SIZE_INTERNAL_ARRAY[] = {5};
static const int* STARTUP_ABSTRACTION_SIZE_INTERNAL = STARTUP_ABSTRACTION_SIZE_INTERNAL_ARRAY;

static const int STARTUP_MODEL_INTERNAL_ARRAY[] = {6};
static const int* STARTUP_MODEL_INTERNAL = STARTUP_MODEL_INTERNAL_ARRAY;

static const int STARTUP_MODEL_COUNT_INTERNAL_ARRAY[] = {7};
static const int* STARTUP_MODEL_COUNT_INTERNAL = STARTUP_MODEL_COUNT_INTERNAL_ARRAY;

static const int STARTUP_MODEL_SIZE_INTERNAL_ARRAY[] = {8};
static const int* STARTUP_MODEL_SIZE_INTERNAL = STARTUP_MODEL_SIZE_INTERNAL_ARRAY;

/** The knowledge memory. */
static const int KNOWLEDGE_MEMORY_INTERNAL_ARRAY[] = {9};
static const int* KNOWLEDGE_MEMORY_INTERNAL = KNOWLEDGE_MEMORY_INTERNAL_ARRAY;

static const int KNOWLEDGE_MEMORY_COUNT_INTERNAL_ARRAY[] = {10};
static const int* KNOWLEDGE_MEMORY_COUNT_INTERNAL = KNOWLEDGE_MEMORY_COUNT_INTERNAL_ARRAY;

static const int KNOWLEDGE_MEMORY_SIZE_INTERNAL_ARRAY[] = {11};
static const int* KNOWLEDGE_MEMORY_SIZE_INTERNAL = KNOWLEDGE_MEMORY_SIZE_INTERNAL_ARRAY;

/** The signal memory. */
static const int SIGNAL_MEMORY_INTERNAL_ARRAY[] = {12};
static const int* SIGNAL_MEMORY_INTERNAL = SIGNAL_MEMORY_INTERNAL_ARRAY;

static const int SIGNAL_MEMORY_COUNT_INTERNAL_ARRAY[] = {13};
static const int* SIGNAL_MEMORY_COUNT_INTERNAL = SIGNAL_MEMORY_COUNT_INTERNAL_ARRAY;

static const int SIGNAL_MEMORY_SIZE_INTERNAL_ARRAY[] = {14};
static const int* SIGNAL_MEMORY_SIZE_INTERNAL = SIGNAL_MEMORY_SIZE_INTERNAL_ARRAY;

/** The unix server socket. */
static const int UNIX_SERVER_SOCKET_ACTIVE_INTERNAL_ARRAY[] = {15};
static const int* UNIX_SERVER_SOCKET_ACTIVE_INTERNAL = UNIX_SERVER_SOCKET_ACTIVE_INTERNAL_ARRAY;

static const int UNIX_SERVER_SOCKET_INTERNAL_ARRAY[] = {16};
static const int* UNIX_SERVER_SOCKET_INTERNAL = UNIX_SERVER_SOCKET_INTERNAL_ARRAY;

static const int UNIX_SERVER_SOCKET_FILENAME_INTERNAL_ARRAY[] = {17};
static const int* UNIX_SERVER_SOCKET_FILENAME_INTERNAL = UNIX_SERVER_SOCKET_FILENAME_INTERNAL_ARRAY;

/** The tcp server socket. */
static const int TCP_SERVER_SOCKET_ACTIVE_INTERNAL_ARRAY[] = {18};
static const int* TCP_SERVER_SOCKET_ACTIVE_INTERNAL = TCP_SERVER_SOCKET_ACTIVE_INTERNAL_ARRAY;

static const int TCP_SERVER_SOCKET_INTERNAL_ARRAY[] = {19};
static const int* TCP_SERVER_SOCKET_INTERNAL = TCP_SERVER_SOCKET_INTERNAL_ARRAY;

static const int TCP_SERVER_SOCKET_PORT_INTERNAL_ARRAY[] = {20};
static const int* TCP_SERVER_SOCKET_PORT_INTERNAL = TCP_SERVER_SOCKET_PORT_INTERNAL_ARRAY;

/** The tcp client sockets. */
static const int TCP_CLIENT_SOCKETS_INTERNAL_ARRAY[] = {21};
static const int* TCP_CLIENT_SOCKETS_INTERNAL = TCP_CLIENT_SOCKETS_INTERNAL_ARRAY;

static const int TCP_CLIENT_SOCKETS_COUNT_INTERNAL_ARRAY[] = {22};
static const int* TCP_CLIENT_SOCKETS_COUNT_INTERNAL = TCP_CLIENT_SOCKETS_COUNT_INTERNAL_ARRAY;

static const int TCP_CLIENT_SOCKETS_SIZE_INTERNAL_ARRAY[] = {23};
static const int* TCP_CLIENT_SOCKETS_SIZE_INTERNAL = TCP_CLIENT_SOCKETS_SIZE_INTERNAL_ARRAY;

/** The signal identifications. */
static const int TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL_ARRAY[] = {24};
static const int* TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL = TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL_ARRAY;

static const int TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL_ARRAY[] = {25};
static const int* TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL = TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL_ARRAY;

static const int TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL_ARRAY[] = {26};
static const int* TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL = TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL_ARRAY;

/** The x window system. */
static const int X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL_ARRAY[] = {27};
static const int* X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL = X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_DISPLAY_INTERNAL_ARRAY[] = {28};
static const int* X_WINDOW_SYSTEM_DISPLAY_INTERNAL = X_WINDOW_SYSTEM_DISPLAY_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_SCREEN_INTERNAL_ARRAY[] = {29};
static const int* X_WINDOW_SYSTEM_SCREEN_INTERNAL = X_WINDOW_SYSTEM_SCREEN_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL_ARRAY[] = {30};
static const int* X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL = X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_BACKGROUND_INTERNAL_ARRAY[] = {31};
static const int* X_WINDOW_SYSTEM_BACKGROUND_INTERNAL = X_WINDOW_SYSTEM_BACKGROUND_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_FOREGROUND_INTERNAL_ARRAY[] = {32};
static const int* X_WINDOW_SYSTEM_FOREGROUND_INTERNAL = X_WINDOW_SYSTEM_FOREGROUND_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL_ARRAY[] = {33};
static const int* X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL = X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL_ARRAY[] = {34};
static const int* X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL = X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL_ARRAY[] = {35};
static const int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL = X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL_ARRAY[] = {36};
static const int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL = X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_ARRAY[] = {37};
static const int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL = X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_FONT_NAME_INTERNAL_ARRAY[] = {38};
static const int* X_WINDOW_SYSTEM_FONT_NAME_INTERNAL = X_WINDOW_SYSTEM_FONT_NAME_INTERNAL_ARRAY;

static const int X_WINDOW_SYSTEM_FONT_INTERNAL_ARRAY[] = {39};
static const int* X_WINDOW_SYSTEM_FONT_INTERNAL = X_WINDOW_SYSTEM_FONT_INTERNAL_ARRAY;

//
// Signal memory.
//

/** The signal memory resize factor. */
static const int SIGNAL_MEMORY_RESIZE_FACTOR_ARRAY[] = {2};
static const int* SIGNAL_MEMORY_RESIZE_FACTOR = SIGNAL_MEMORY_RESIZE_FACTOR_ARRAY;

/** The signal memory count. */
static const int SIGNAL_MEMORY_COUNT_ARRAY[] = {8};
static const int* SIGNAL_MEMORY_COUNT = SIGNAL_MEMORY_COUNT_ARRAY;

/** The signals abstractions index. */
static const int SIGNALS_ABSTRACTIONS_INDEX_ARRAY[] = {0};
static const int* SIGNALS_ABSTRACTIONS_INDEX = SIGNALS_ABSTRACTIONS_INDEX_ARRAY;

/** The signals abstractions counts index. */
static const int SIGNALS_ABSTRACTIONS_COUNTS_INDEX_ARRAY[] = {1};
static const int* SIGNALS_ABSTRACTIONS_COUNTS_INDEX = SIGNALS_ABSTRACTIONS_COUNTS_INDEX_ARRAY;

/** The signals models index. */
static const int SIGNALS_MODELS_INDEX_ARRAY[] = {2};
static const int* SIGNALS_MODELS_INDEX = SIGNALS_MODELS_INDEX_ARRAY;

/** The signals models counts index. */
static const int SIGNALS_MODELS_COUNTS_INDEX_ARRAY[] = {3};
static const int* SIGNALS_MODELS_COUNTS_INDEX = SIGNALS_MODELS_COUNTS_INDEX_ARRAY;

/** The signals details index. */
static const int SIGNALS_DETAILS_INDEX_ARRAY[] = {4};
static const int* SIGNALS_DETAILS_INDEX = SIGNALS_DETAILS_INDEX_ARRAY;

/** The signals details counts index. */
static const int SIGNALS_DETAILS_COUNTS_INDEX_ARRAY[] = {5};
static const int* SIGNALS_DETAILS_COUNTS_INDEX = SIGNALS_DETAILS_COUNTS_INDEX_ARRAY;

/** The signals priorities index. */
static const int SIGNALS_PRIORITIES_INDEX_ARRAY[] = {6};
static const int* SIGNALS_PRIORITIES_INDEX = SIGNALS_PRIORITIES_INDEX_ARRAY;

/** The signals identifications index. */
static const int SIGNALS_IDENTIFICATIONS_INDEX_ARRAY[] = {7};
static const int* SIGNALS_IDENTIFICATIONS_INDEX = SIGNALS_IDENTIFICATIONS_INDEX_ARRAY;

//
// Xml tag.
//

/** The xml tag count. */
static const int XML_TAG_COUNT_ARRAY[] = {2};
static const int* XML_TAG_COUNT = XML_TAG_COUNT_ARRAY;

/** The xml tag name, attribute, value index. */
static const int XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX_ARRAY[] = {0};
static const int* XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX = XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX_ARRAY;

/** The xml tag counts index. */
static const int XML_TAG_COUNTS_INDEX_ARRAY[] = {1};
static const int* XML_TAG_COUNTS_INDEX = XML_TAG_COUNTS_INDEX_ARRAY;

//
// Xml attribute.
//

/** The xml attribute count. */
static const int XML_ATTRIBUTE_COUNT_ARRAY[] = {2};
static const int* XML_ATTRIBUTE_COUNT = XML_ATTRIBUTE_COUNT_ARRAY;

/** The xml attribute name, value index. */
static const int XML_ATTRIBUTE_NAME_VALUE_INDEX_ARRAY[] = {0};
static const int* XML_ATTRIBUTE_NAME_VALUE_INDEX = XML_ATTRIBUTE_NAME_VALUE_INDEX_ARRAY;

/** The xml attribute counts index. */
static const int XML_ATTRIBUTE_COUNTS_INDEX_ARRAY[] = {1};
static const int* XML_ATTRIBUTE_COUNTS_INDEX = XML_ATTRIBUTE_COUNTS_INDEX_ARRAY;

/* STRUCTURE_CONSTANTS_SOURCE */
#endif
