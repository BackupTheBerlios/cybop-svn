/*
 * $RCSfile: constant.c,v $
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
 * @version $Revision: 1.29 $ $Date: 2005-01-09 01:30:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANT_SOURCE
#define CONSTANT_SOURCE

#include "../global/character_constants.c"

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

/** The command parameter index. */
static const int COMMAND_PARAMETER_INDEX_ARRAY[] = {0};
static const int* COMMAND_PARAMETER_INDEX = COMMAND_PARAMETER_INDEX_ARRAY;

/** The configuration file parameter index. */
static const int CONFIGURATION_FILE_PARAMETER_INDEX_ARRAY[] = {1};
static const int* CONFIGURATION_FILE_PARAMETER_INDEX = CONFIGURATION_FILE_PARAMETER_INDEX_ARRAY;

/* CONSTANT_SOURCE */
#endif
