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
 * @version $Revision: 1.21 $ $Date: 2004-12-16 09:52:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANT_SOURCE
#define CONSTANT_SOURCE

//
// internal
//
static const int INTERNAL_COLUMN_COUNT = 2;
static const int INTERNAL_COLUMN_VALUE_INDEX = 0;
static const int INTERNAL_COLUMN_VALUETYPE_INDEX = 1;

//
// internal value type
//
static const int INTERNAL_TYPE_CHARACTER = 1;
static const int INTERNAL_TYPE_INTEGER = 2;
static const int INTERNAL_TYPE_DOUBLE = 3;
static const int INTERNAL_TYPE_POINTER = 4;

//
// internal array index
//
static const int INTERNAL_ARRAY_COUNT = 24;

/** The tcp socket index. */
static const int INTERNAL_TCPSOCKET_PORT_INDEX = 0;
static const int INTERNAL_TCPSOCKET_ACTIVE_INDEX = 1;
static const int INTERNAL_TCPSOCKET_SERVERSOCKETNUMBER_INDEX = 2;

/** The start parameter index. */
static const int INTERNAL_START_ABSTRACTION_INDEX = 3;
static const int INTERNAL_START_ABSTRACTION_COUNT_INDEX = 4;
static const int INTERNAL_START_ABSTRACTION_SIZE_INDEX = 5;
static const int INTERNAL_START_CHANNEL_INDEX = 6;
static const int INTERNAL_START_CHANNEL_COUNT_INDEX = 7;
static const int INTERNAL_START_CHANNEL_SIZE_INDEX = 8;
static const int INTERNAL_START_MODEL_INDEX = 9;
static const int INTERNAL_START_MODEL_COUNT_INDEX = 10;
static const int INTERNAL_START_MODEL_SIZE_INDEX = 11;

/** The signal memory index. */
static const int INTERNAL_SIGNAL_MEMORY_INDEX = 12;
static const int INTERNAL_SIGNAL_MEMORY_COUNT_INDEX = 13;
static const int INTERNAL_SIGNAL_MEMORY_SIZE_INDEX = 14;

/** The knowledge model index. */
static const int INTERNAL_KNOWLEDGE_MODEL_INDEX = 15;
static const int INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX = 16;
static const int INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX = 17;

/** The client socket number  */
static const int INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_INDEX = 18;
static const int INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT_INDEX = 19;
static const int INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE_INDEX = 20;

/** The main signal id  */
static const int INTERNAL_TCPSOCKET_MAINSIGNALID_INDEX = 21;
static const int INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT_INDEX = 22;
static const int INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE_INDEX = 23;

//
// Unix socket.
//

/** The unix server socket filename array, pointer, count. */
static const char UNIX_SERVER_SOCKET_FILENAME_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'e', 'r', 'v', 'e', 'r', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'f', 'i', 'l', 'e', 'n', 'a', 'm', 'e'};
static const char* UNIX_SERVER_SOCKET_FILENAME = UNIX_SERVER_SOCKET_FILENAME_ARRAY;
static const int UNIX_SERVER_SOCKET_FILENAME_COUNT = 27;

/** The unix socket filename name array, pointer, count. */
static const char UNIX_SOCKET_FILENAME_NAME_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'o', 'c', 'k', 'e', 't', '_', 'f', 'i', 'l', 'e', 'n', 'a', 'm', 'e', '_', 'n', 'a', 'm', 'e'};
static const char* UNIX_SOCKET_FILENAME_NAME = UNIX_SOCKET_FILENAME_NAME_ARRAY;
static const int UNIX_SOCKET_FILENAME_NAME_COUNT = 25;

//
// X windows.
//

//
// Signal priorities.
//

/** The normal priority. */
static const int NORMAL_PRIORITY = 0;

//
// Xml markups.
//

/** The begin comment tag array, pointer, count. */
static const char BEGIN_COMMENT_TAG_ARRAY[] = {'<', '!', '-', '-'};
static const char* BEGIN_COMMENT_TAG = BEGIN_COMMENT_TAG_ARRAY;
static const int BEGIN_COMMENT_TAG_COUNT = 4;

/** The end comment tag array, pointer, count. */
static const char END_COMMENT_TAG_ARRAY[] = {'/', '-', '-', '>'};
static const char* END_COMMENT_TAG = END_COMMENT_TAG_ARRAY;
static const int END_COMMENT_TAG_COUNT = 4;

/** The short end comment tag array, pointer, count. */
static const char SHORT_END_COMMENT_TAG_ARRAY[] = {'-', '-', '>'};
static const char* SHORT_END_COMMENT_TAG = SHORT_END_COMMENT_TAG_ARRAY;
static const int SHORT_END_COMMENT_TAG_COUNT = 3;

/** The begin tag begin array, pointer, count. */
static const char BEGIN_TAG_BEGIN_ARRAY[] = {'<'};
static const char* BEGIN_TAG_BEGIN = BEGIN_TAG_BEGIN_ARRAY;
static const int BEGIN_TAG_BEGIN_COUNT = 1;

/** The end tag begin array, pointer, count. */
static const char END_TAG_BEGIN_ARRAY[] = {'<', '/'};
static const char* END_TAG_BEGIN = END_TAG_BEGIN_ARRAY;
static const int END_TAG_BEGIN_COUNT = 2;

/** The tag end array, pointer, count. */
static const char TAG_END_ARRAY[] = {'>'};
static const char* TAG_END = TAG_END_ARRAY;
static const int TAG_END_COUNT = 1;

/** The empty tag end array, pointer, count. */
static const char EMPTY_TAG_END_ARRAY[] = {'/', '>'};
static const char* EMPTY_TAG_END = EMPTY_TAG_END_ARRAY;
static const int EMPTY_TAG_END_COUNT = 2;

/** The attribute begin array, pointer, count. */
static const char ATTRIBUTE_BEGIN_ARRAY[] = {' '};
static const char* ATTRIBUTE_BEGIN = ATTRIBUTE_BEGIN_ARRAY;
static const int ATTRIBUTE_BEGIN_COUNT = 1;

/** The attribute value begin array, pointer, count. */
static const char ATTRIBUTE_VALUE_BEGIN_ARRAY[] = {'=', '"'};
static const char* ATTRIBUTE_VALUE_BEGIN = ATTRIBUTE_VALUE_BEGIN_ARRAY;
static const int ATTRIBUTE_VALUE_BEGIN_COUNT = 1;

/** The attribute value end array, pointer, count. */
static const char ATTRIBUTE_VALUE_END_ARRAY[] = {'"'};
static const char* ATTRIBUTE_VALUE_END = ATTRIBUTE_VALUE_END_ARRAY;
static const int ATTRIBUTE_VALUE_END_COUNT = 1;

//
// Xml parse modes.
//

/** The zero parse mode. */
static const int ZERO_PARSE_MODE = 0;

/** The comment tag parse mode. */
static const int COMMENT_TAG_PARSE_MODE = 1;

/** The begin tag parse mode. */
static const int BEGIN_TAG_PARSE_MODE = 2;

/** The end tag parse mode. */
static const int END_TAG_PARSE_MODE = 3;

/** The tag value parse mode. */
static const int TAG_VALUE_PARSE_MODE = 4;

/** The attribute name parse mode. */
static const int ATTRIBUTE_NAME_PARSE_MODE = 5;

/** The attribute value parse mode. */
static const int ATTRIBUTE_VALUE_PARSE_MODE = 6;

//
// Cybol file.
//

/** The file resize factor. */
static const int FILE_RESIZE_FACTOR = 2;

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
static const int MODEL_LOCATION_SEPARATOR_COUNT = 1;

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
static const char COMPOUND_ELEMENT_SEPARATOR = '.';

//
// Operation.
//

/** The operation parameter separator. */
static const char OPERATION_PARAMETER_SEPARATOR = ',';

//
// Boolean.
//

/** The true boolean array, pointer, count. */
static const char TRUE_BOOLEAN_ARRAY[] = {'t', 'r', 'u', 'e'};
static const char* TRUE_BOOLEAN = TRUE_BOOLEAN_ARRAY;
static const int TRUE_BOOLEAN_COUNT = 4;

/** The false boolean array, pointer, count. */
static const char FALSE_BOOLEAN_ARRAY[] = {'f', 'a', 'l', 's', 'e'};
static const char* FALSE_BOOLEAN = FALSE_BOOLEAN_ARRAY;
static const int FALSE_BOOLEAN_COUNT = 5;

//
// Cyboi.
//

/** The startup parameters count. */
static const int STARTUP_PARAMETERS_COUNT = 2;

/** The config file startup parameter index. */
static const int CONFIG_STARTUP_PARAMETER_INDEX = 1;

/* CONSTANT_SOURCE */
#endif
