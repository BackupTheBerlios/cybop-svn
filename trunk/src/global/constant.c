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
 * This file defines global constants for:
 * - null pointers
 * - arrays
 * - internals
 * - unix socket
 * - x windows
 * - xml tag
 * - xml attribute
 * - signal priorities
 * - xml markups
 * - xml parse modes
 * - cybol file
 * - cybol tags
 * - cybol attributes
 * - location separators
 * - cybol model values:
 *   - model separators
 *   - boolean
 * - cyboi
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * Systems would then be written solely in cybol. Dreaming ...
 *
 * @version $Revision: 1.13 $ $Date: 2004-09-08 19:44:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANT_SOURCE
#define CONSTANT_SOURCE

//
// Character internals.
//

/** The character internals count. */
static const int CHARACTER_INTERNALS_COUNT = 1;

/** The unix server socket flag index. */
static const int UNIX_SERVER_SOCKET_FLAG_INDEX = 0;

//
// Integer internals.
//

/** The integer internals count. */
static const int INTEGER_INTERNALS_COUNT = 1;

/** The unix server socket index. */
static const int UNIX_SERVER_SOCKET_INDEX = 0;

//
// Pointer internals.
//

/** The pointer internals count. */
static const int POINTER_INTERNALS_COUNT = 1;

/** The unix server socket filename index. */
static const int UNIX_SERVER_SOCKET_FILENAME_INDEX = 0;

//
// Double internals.
//

/** The double internals count. */
static const int DOUBLE_INTERNALS_COUNT = 0;

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
static const int STARTUP_PARAMETERS_COUNT = 4;

/** The command startup parameter index. */
static const int COMMAND_STARTUP_PARAMETER_INDEX = 0;

/** The abstraction startup parameter index. */
static const int ABSTRACTION_STARTUP_PARAMETER_INDEX = 1;

/** The location startup parameter index. */
static const int LOCATION_STARTUP_PARAMETER_INDEX = 2;

/** The model startup parameter index. */
static const int MODEL_STARTUP_PARAMETER_INDEX = 3;

/* CONSTANT_SOURCE */
#endif
