/*
 * $RCSfile: constant.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.25 $ $Date: 2004-12-18 16:42:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANT_SOURCE
#define CONSTANT_SOURCE

//
// Internals.
//

static const int INTERNAL_COLUMN_COUNT_ARRAY[] = {2};
static const int* INTERNAL_COLUMN_COUNT = INTERNAL_COLUMN_COUNT_ARRAY;

static const int INTERNAL_COLUMN_VALUE_INDEX_ARRAY[] = {0};
static const int* INTERNAL_COLUMN_VALUE_INDEX = INTERNAL_COLUMN_VALUE_INDEX_ARRAY;

static const int INTERNAL_COLUMN_VALUETYPE_INDEX_ARRAY[] = {1};
static const int* INTERNAL_COLUMN_VALUETYPE_INDEX = INTERNAL_COLUMN_VALUETYPE_INDEX_ARRAY;

//
// internal value type
//

static const int INTERNAL_TYPE_CHARACTER_ARRAY[] = {1};
static const int* INTERNAL_TYPE_CHARACTER = INTERNAL_TYPE_CHARACTER_ARRAY;

static const int INTERNAL_TYPE_INTEGER_ARRAY[] = {2};
static const int* INTERNAL_TYPE_INTEGER = INTERNAL_TYPE_INTEGER_ARRAY;

static const int INTERNAL_TYPE_DOUBLE_ARRAY[] = {3};
static const int* INTERNAL_TYPE_DOUBLE = INTERNAL_TYPE_DOUBLE_ARRAY;

static const int INTERNAL_TYPE_POINTER_ARRAY[] = {4};
static const int* INTERNAL_TYPE_POINTER = INTERNAL_TYPE_POINTER_ARRAY;

//
// Internal array index.
//

static const int INTERNAL_ARRAY_COUNT_ARRAY[] = {24};
static const int* INTERNAL_ARRAY_COUNT = INTERNAL_ARRAY_COUNT_ARRAY;

/** The tcp socket index. */

static const int INTERNAL_TCPSOCKET_PORT_INDEX_ARRAY[] = {0};
static const int* INTERNAL_TCPSOCKET_PORT_INDEX = INTERNAL_TCPSOCKET_PORT_INDEX_ARRAY;

static const int INTERNAL_TCPSOCKET_ACTIVE_INDEX_ARRAY[] = {1};
static const int* INTERNAL_TCPSOCKET_ACTIVE_INDEX = INTERNAL_TCPSOCKET_ACTIVE_INDEX_ARRAY;

static const int INTERNAL_TCPSOCKET_SERVERSOCKETNUMBER_INDEX_ARRAY[] = {2};
static const int* INTERNAL_TCPSOCKET_SERVERSOCKETNUMBER_INDEX = INTERNAL_TCPSOCKET_SERVERSOCKETNUMBER_INDEX_ARRAY;

/** The start parameter index. */

static const int INTERNAL_START_ABSTRACTION_INDEX_ARRAY[] = {3};
static const int* INTERNAL_START_ABSTRACTION_INDEX = INTERNAL_START_ABSTRACTION_INDEX_ARRAY;

static const int INTERNAL_START_ABSTRACTION_COUNT_INDEX_ARRAY[] = {4};
static const int* INTERNAL_START_ABSTRACTION_COUNT_INDEX = INTERNAL_START_ABSTRACTION_COUNT_INDEX_ARRAY;

static const int INTERNAL_START_ABSTRACTION_SIZE_INDEX_ARRAY[] = {5};
static const int* INTERNAL_START_ABSTRACTION_SIZE_INDEX = INTERNAL_START_ABSTRACTION_SIZE_INDEX_ARRAY;

static const int INTERNAL_START_CHANNEL_INDEX_ARRAY[] = {6};
static const int* INTERNAL_START_CHANNEL_INDEX = INTERNAL_START_CHANNEL_INDEX_ARRAY;

static const int INTERNAL_START_CHANNEL_COUNT_INDEX_ARRAY[] = {7};
static const int* INTERNAL_START_CHANNEL_COUNT_INDEX = INTERNAL_START_CHANNEL_COUNT_INDEX_ARRAY;

static const int INTERNAL_START_CHANNEL_SIZE_INDEX_ARRAY[] = {8};
static const int* INTERNAL_START_CHANNEL_SIZE_INDEX = INTERNAL_START_CHANNEL_SIZE_INDEX_ARRAY;

static const int INTERNAL_START_MODEL_INDEX_ARRAY[] = {9};
static const int* INTERNAL_START_MODEL_INDEX = INTERNAL_START_MODEL_INDEX_ARRAY;

static const int INTERNAL_START_MODEL_COUNT_INDEX_ARRAY[] = {10};
static const int* INTERNAL_START_MODEL_COUNT_INDEX = INTERNAL_START_MODEL_COUNT_INDEX_ARRAY;

static const int INTERNAL_START_MODEL_SIZE_INDEX_ARRAY[] = {11};
static const int* INTERNAL_START_MODEL_SIZE_INDEX = INTERNAL_START_MODEL_SIZE_INDEX_ARRAY;

/** The signal memory index. */

static const int INTERNAL_SIGNAL_MEMORY_INDEX_ARRAY[] = {12};
static const int* INTERNAL_SIGNAL_MEMORY_INDEX = INTERNAL_SIGNAL_MEMORY_INDEX_ARRAY;

static const int INTERNAL_SIGNAL_MEMORY_COUNT_INDEX_ARRAY[] = {13};
static const int* INTERNAL_SIGNAL_MEMORY_COUNT_INDEX = INTERNAL_SIGNAL_MEMORY_COUNT_INDEX_ARRAY;

static const int INTERNAL_SIGNAL_MEMORY_SIZE_INDEX_ARRAY[] = {14};
static const int* INTERNAL_SIGNAL_MEMORY_SIZE_INDEX = INTERNAL_SIGNAL_MEMORY_SIZE_INDEX_ARRAY;

/** The knowledge model index. */

static const int INTERNAL_KNOWLEDGE_MODEL_INDEX_ARRAY[] = {15};
static const int* INTERNAL_KNOWLEDGE_MODEL_INDEX = INTERNAL_KNOWLEDGE_MODEL_INDEX_ARRAY;

static const int INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX_ARRAY[] = {16};
static const int* INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX = INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX_ARRAY;

static const int INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX_ARRAY[] = {17};
static const int* INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX = INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX_ARRAY;

/** The client socket number  */

static const int INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_INDEX_ARRAY[] = {18};
static const int* INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_INDEX = INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_INDEX_ARRAY;

static const int INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT_INDEX_ARRAY[] = {19};
static const int* INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT_INDEX = INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT_INDEX_ARRAY;

static const int INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE_INDEX_ARRAY[] = {20};
static const int* INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE_INDEX = INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE_INDEX_ARRAY;

/** The main signal id  */

static const int INTERNAL_TCPSOCKET_MAINSIGNALID_INDEX_ARRAY[] = {21};
static const int* INTERNAL_TCPSOCKET_MAINSIGNALID_INDEX = INTERNAL_TCPSOCKET_MAINSIGNALID_INDEX_ARRAY;

static const int INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT_INDEX_ARRAY[] = {22};
static const int* INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT_INDEX = INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT_INDEX_ARRAY;

static const int INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE_INDEX_ARRAY[] = {23};
static const int* INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE_INDEX = INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE_INDEX_ARRAY;

//
// Unix socket.
//

/** The unix server socket filename array, pointer, count. */

static const char UNIX_SERVER_SOCKET_FILENAME_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'f', 'i', 'l', 'e', 'n', 'a', 'm', 'e'};
static const char* UNIX_SERVER_SOCKET_FILENAME = UNIX_SERVER_SOCKET_FILENAME_ARRAY;
static const int UNIX_SERVER_SOCKET_FILENAME_COUNT_ARRAY[] = {27};
static const int* UNIX_SERVER_SOCKET_FILENAME_COUNT = UNIX_SERVER_SOCKET_FILENAME_COUNT_ARRAY;

/** The unix socket filename name array, pointer, count. */

static const char UNIX_SOCKET_FILENAME_NAME_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'f', 'i', 'l', 'e', 'n', 'a', 'm', 'e', '_', 'n', 'a', 'm', 'e'};
static const char* UNIX_SOCKET_FILENAME_NAME = UNIX_SOCKET_FILENAME_NAME_ARRAY;
static const int UNIX_SOCKET_FILENAME_NAME_COUNT_ARRAY[] = {25};
static const int* UNIX_SOCKET_FILENAME_NAME_COUNT = UNIX_SOCKET_FILENAME_NAME_COUNT_ARRAY;

//
// X windows.
//

//
// Signal priorities.
//

/** The normal priority. */
static const int NORMAL_PRIORITY_ARRAY[] = {0};
static const int* NORMAL_PRIORITY = NORMAL_PRIORITY_ARRAY;

//
// Xml markups.
//

/** The begin comment tag array, pointer, count. */
static const char BEGIN_COMMENT_TAG_ARRAY[] = {'<', '!', '-', '-'};
static const char* BEGIN_COMMENT_TAG = BEGIN_COMMENT_TAG_ARRAY;
static const int BEGIN_COMMENT_TAG_COUNT_ARRAY[] = {4};
static const int* BEGIN_COMMENT_TAG_COUNT = BEGIN_COMMENT_TAG_COUNT_ARRAY;

/** The end comment tag array, pointer, count. */
static const char END_COMMENT_TAG_ARRAY[] = {'/', '-', '-', '>'};
static const char* END_COMMENT_TAG = END_COMMENT_TAG_ARRAY;
static const int END_COMMENT_TAG_COUNT_ARRAY[] = {4};
static const int* END_COMMENT_TAG_COUNT = END_COMMENT_TAG_COUNT_ARRAY;

/** The short end comment tag array, pointer, count. */
static const char SHORT_END_COMMENT_TAG_ARRAY[] = {'-', '-', '>'};
static const char* SHORT_END_COMMENT_TAG = SHORT_END_COMMENT_TAG_ARRAY;
static const int SHORT_END_COMMENT_TAG_COUNT_ARRAY[] = {3};
static const int* SHORT_END_COMMENT_TAG_COUNT = SHORT_END_COMMENT_TAG_COUNT_ARRAY;

/** The begin tag begin array, pointer, count. */
static const char BEGIN_TAG_BEGIN_ARRAY[] = {'<'};
static const char* BEGIN_TAG_BEGIN = BEGIN_TAG_BEGIN_ARRAY;
static const int BEGIN_TAG_BEGIN_COUNT_ARRAY[] = {1};
static const int* BEGIN_TAG_BEGIN_COUNT = BEGIN_TAG_BEGIN_COUNT_ARRAY;

/** The end tag begin array, pointer, count. */
static const char END_TAG_BEGIN_ARRAY[] = {'<', '/'};
static const char* END_TAG_BEGIN = END_TAG_BEGIN_ARRAY;
static const int END_TAG_BEGIN_COUNT_ARRAY[] = {2};
static const int* END_TAG_BEGIN_COUNT = END_TAG_BEGIN_COUNT_ARRAY;

/** The tag end array, pointer, count. */
static const char TAG_END_ARRAY[] = {'>'};
static const char* TAG_END = TAG_END_ARRAY;
static const int TAG_END_COUNT_ARRAY[] = {1};
static const int* TAG_END_COUNT = TAG_END_COUNT_ARRAY;

/** The empty tag end array, pointer, count. */
static const char EMPTY_TAG_END_ARRAY[] = {'/', '>'};
static const char* EMPTY_TAG_END = EMPTY_TAG_END_ARRAY;
static const int EMPTY_TAG_END_COUNT_ARRAY[] = {2};
static const int* EMPTY_TAG_END_COUNT = EMPTY_TAG_END_COUNT_ARRAY;

/** The attribute begin array, pointer, count. */
static const char ATTRIBUTE_BEGIN_ARRAY[] = {' '};
static const char* ATTRIBUTE_BEGIN = ATTRIBUTE_BEGIN_ARRAY;
static const int ATTRIBUTE_BEGIN_COUNT_ARRAY[] = {1};
static const int* ATTRIBUTE_BEGIN_COUNT = ATTRIBUTE_BEGIN_COUNT_ARRAY;

/** The attribute value begin array, pointer, count. */
static const char ATTRIBUTE_VALUE_BEGIN_ARRAY[] = {'=', '"'};
static const char* ATTRIBUTE_VALUE_BEGIN = ATTRIBUTE_VALUE_BEGIN_ARRAY;
static const int ATTRIBUTE_VALUE_BEGIN_COUNT_ARRAY[] = {1};
static const int* ATTRIBUTE_VALUE_BEGIN_COUNT = ATTRIBUTE_VALUE_BEGIN_COUNT_ARRAY;

/** The attribute value end array, pointer, count. */
static const char ATTRIBUTE_VALUE_END_ARRAY[] = {'"'};
static const char* ATTRIBUTE_VALUE_END = ATTRIBUTE_VALUE_END_ARRAY;
static const int ATTRIBUTE_VALUE_END_COUNT_ARRAY[] = {1};
static const int* ATTRIBUTE_VALUE_END_COUNT = ATTRIBUTE_VALUE_END_COUNT_ARRAY;

//
// Xml parse modes.
//

/** The zero parse mode. */
static const int ZERO_PARSE_MODE_ARRAY[] = {0};
static const int* ZERO_PARSE_MODE = ZERO_PARSE_MODE_ARRAY;

/** The comment tag parse mode. */
static const int COMMENT_TAG_PARSE_MODE_ARRAY[] = {1};
static const int* COMMENT_TAG_PARSE_MODE = COMMENT_TAG_PARSE_MODE_ARRAY;

/** The begin tag parse mode. */
static const int BEGIN_TAG_PARSE_MODE_ARRAY[] = {2};
static const int* BEGIN_TAG_PARSE_MODE = BEGIN_TAG_PARSE_MODE_ARRAY;

/** The end tag parse mode. */
static const int END_TAG_PARSE_MODE_ARRAY[] = {3};
static const int* END_TAG_PARSE_MODE = END_TAG_PARSE_MODE_ARRAY;

/** The tag value parse mode. */
static const int TAG_VALUE_PARSE_MODE_ARRAY[] = {4};
static const int* TAG_VALUE_PARSE_MODE = TAG_VALUE_PARSE_MODE_ARRAY;

/** The attribute name parse mode. */
static const int ATTRIBUTE_NAME_PARSE_MODE_ARRAY[] = {5};
static const int* ATTRIBUTE_NAME_PARSE_MODE = ATTRIBUTE_NAME_PARSE_MODE_ARRAY;

/** The attribute value parse mode. */
static const int ATTRIBUTE_VALUE_PARSE_MODE_ARRAY[] = {6};
static const int* ATTRIBUTE_VALUE_PARSE_MODE = ATTRIBUTE_VALUE_PARSE_MODE_ARRAY;

//
// Cybol file.
//

/** The file resize factor. */
static const int FILE_RESIZE_FACTOR_ARRAY[] = {2};
static const int* FILE_RESIZE_FACTOR = FILE_RESIZE_FACTOR_ARRAY;

/** The cybol path. */
//?? static const char CYBOL_PATH[] = {'/home/cybop/lib/cybop/'};

/** The cybol file suffix. */
//?? static const char FILE_SUFFIX[] = {'.cybol'};

/** The null model. */
//?? static const char NULL_MODEL[] = {'null'};

//
// Location separator.
//

/** The model location separator array, pointer, count. */
static const char MODEL_LOCATION_SEPARATOR_ARRAY[] = {':'};
static const char* MODEL_LOCATION_SEPARATOR = MODEL_LOCATION_SEPARATOR_ARRAY;
static const int MODEL_LOCATION_SEPARATOR_COUNT_ARRAY[] = {1};
static const int* MODEL_LOCATION_SEPARATOR_COUNT = MODEL_LOCATION_SEPARATOR_COUNT_ARRAY;

//
// Cybol model values:
// - compound
// - operation
// - boolean
//

//
// Compound.
//

/** The compound element separator. */
static const char* COMPOUND_ELEMENT_SEPARATOR = FULL_STOP_CHARACTER_ARRAY;
static const int* COMPOUND_ELEMENT_SEPARATOR_COUNT = FULL_STOP_CHARACTER_COUNT_ARRAY;

//
// Operation.
//

/** The operation parameter separator. */
static const char* OPERATION_PARAMETER_SEPARATOR = COMMA_CHARACTER_ARRAY;
static const int* OPERATION_PARAMETER_SEPARATOR_COUNT = COMMA_CHARACTER_COUNT_ARRAY;

//
// Boolean.
//

/** The true boolean array, pointer, count. */
static const char TRUE_BOOLEAN_ARRAY[] = {'t', 'r', 'u', 'e'};
static const char* TRUE_BOOLEAN = TRUE_BOOLEAN_ARRAY;
static const int TRUE_BOOLEAN_COUNT_ARRAY[] = {4};
static const int* TRUE_BOOLEAN_COUNT = TRUE_BOOLEAN_COUNT_ARRAY;

/** The false boolean array, pointer, count. */
static const char FALSE_BOOLEAN_ARRAY[] = {'f', 'a', 'l', 's', 'e'};
static const char* FALSE_BOOLEAN = FALSE_BOOLEAN_ARRAY;
static const int FALSE_BOOLEAN_COUNT_ARRAY[] = {5};
static const int* FALSE_BOOLEAN_COUNT = FALSE_BOOLEAN_COUNT_ARRAY;

//
// Cyboi.
//

/** The startup parameters count. */
static const int STARTUP_PARAMETERS_COUNT_ARRAY[] = {2};
static const int* STARTUP_PARAMETERS_COUNT = STARTUP_PARAMETERS_COUNT_ARRAY;

/** The config file startup parameter index. */
static const int CONFIG_STARTUP_PARAMETER_INDEX_ARRAY[] = {1};
static const int* CONFIG_STARTUP_PARAMETER_INDEX = CONFIG_STARTUP_PARAMETER_INDEX_ARRAY;

/* CONSTANT_SOURCE */
#endif
