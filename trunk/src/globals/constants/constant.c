/*
 * $RCSfile: constant.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2005-08-04 15:20:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANT_SOURCE
#define CONSTANT_SOURCE

#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/integer_constants.c"

//
// Signal priorities.
//

/** The normal priority. */
static int* NORMAL_PRIORITY = NUMBER_0_INTEGER_ARRAY;

//
// Xml markups.
//

/** The begin comment tag array, pointer, count. */
static char BEGIN_COMMENT_TAG_ARRAY[] = {'<', '!', '-', '-'};
static char* BEGIN_COMMENT_TAG = BEGIN_COMMENT_TAG_ARRAY;
static int* BEGIN_COMMENT_TAG_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The end comment tag array, pointer, count. */
static char END_COMMENT_TAG_ARRAY[] = {'/', '-', '-', '>'};
static char* END_COMMENT_TAG = END_COMMENT_TAG_ARRAY;
static int* END_COMMENT_TAG_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The short end comment tag array, pointer, count. */
static char SHORT_END_COMMENT_TAG_ARRAY[] = {'-', '-', '>'};
static char* SHORT_END_COMMENT_TAG = SHORT_END_COMMENT_TAG_ARRAY;
static int* SHORT_END_COMMENT_TAG_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The begin tag begin array, pointer, count. */
static char BEGIN_TAG_BEGIN_ARRAY[] = {'<'};
static char* BEGIN_TAG_BEGIN = BEGIN_TAG_BEGIN_ARRAY;
static int* BEGIN_TAG_BEGIN_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end tag begin array, pointer, count. */
static char END_TAG_BEGIN_ARRAY[] = {'<', '/'};
static char* END_TAG_BEGIN = END_TAG_BEGIN_ARRAY;
static int* END_TAG_BEGIN_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The tag end array, pointer, count. */
static char TAG_END_ARRAY[] = {'>'};
static char* TAG_END = TAG_END_ARRAY;
static int* TAG_END_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The empty tag end array, pointer, count. */
static char EMPTY_TAG_END_ARRAY[] = {'/', '>'};
static char* EMPTY_TAG_END = EMPTY_TAG_END_ARRAY;
static int* EMPTY_TAG_END_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The attribute begin array, pointer, count. */
static char ATTRIBUTE_BEGIN_ARRAY[] = {' '};
static char* ATTRIBUTE_BEGIN = ATTRIBUTE_BEGIN_ARRAY;
static int* ATTRIBUTE_BEGIN_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The attribute value begin array, pointer, count. */
static char ATTRIBUTE_VALUE_BEGIN_ARRAY[] = {'=', '"'};
static char* ATTRIBUTE_VALUE_BEGIN = ATTRIBUTE_VALUE_BEGIN_ARRAY;
static int* ATTRIBUTE_VALUE_BEGIN_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The attribute value end array, pointer, count. */
static char ATTRIBUTE_VALUE_END_ARRAY[] = {'"'};
static char* ATTRIBUTE_VALUE_END = ATTRIBUTE_VALUE_END_ARRAY;
static int* ATTRIBUTE_VALUE_END_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Xml parse modes.
//

/** The zero parse mode. */
static int* ZERO_PARSE_MODE = NUMBER_0_INTEGER_ARRAY;

/** The comment tag parse mode. */
static int* COMMENT_TAG_PARSE_MODE = NUMBER_1_INTEGER_ARRAY;

/** The begin tag parse mode. */
static int* BEGIN_TAG_PARSE_MODE = NUMBER_2_INTEGER_ARRAY;

/** The end tag parse mode. */
static int* END_TAG_PARSE_MODE = NUMBER_3_INTEGER_ARRAY;

/** The tag value parse mode. */
static int* TAG_VALUE_PARSE_MODE = NUMBER_4_INTEGER_ARRAY;

/** The attribute name parse mode. */
static int* ATTRIBUTE_NAME_PARSE_MODE = NUMBER_5_INTEGER_ARRAY;

/** The attribute value parse mode. */
static int* ATTRIBUTE_VALUE_PARSE_MODE = NUMBER_6_INTEGER_ARRAY;

//
// Cybol file.
//

/** The file reallocate factor. */
static int* FILE_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

/** The cybol path. */
//?? static char CYBOL_PATH[] = {'/home/cybop/lib/cybop/'};

/** The cybol file suffix. */
//?? static char FILE_SUFFIX[] = {'.cybol'};

/** The null model. */
//?? static char NULL_MODEL[] = {'null'};

//
// Location separator.
//

/** The model location separator array, pointer, count. */
static char MODEL_LOCATION_SEPARATOR_ARRAY[] = {':'};
static char* MODEL_LOCATION_SEPARATOR = MODEL_LOCATION_SEPARATOR_ARRAY;
static int* MODEL_LOCATION_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// List separator.
// this ist the separator from the basisname and the index
//

/** The model location separator array, pointer, count. */
static char LIST_SEPARATOR_ARRAY[] = {'_', '$'};
static char* LIST_SEPARATOR = LIST_SEPARATOR_ARRAY;
static int* LIST_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Request method
//

/** The model request method get array, pointer, count. */
static char REQEUST_METHOD_GET_ARRAY[] = {'G', 'E', 'T'};
static char* REQEUST_METHOD_GET = REQEUST_METHOD_GET_ARRAY;
static int* REQEUST_METHOD_GET_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The model request method post array, pointer, count. */
static char REQEUST_METHOD_POST_ARRAY[] = {'P', 'O', 'S', 'T'};
static char* REQEUST_METHOD_POST = REQEUST_METHOD_POST_ARRAY;
static int* REQEUST_METHOD_POST_COUNT = NUMBER_4_INTEGER_ARRAY;

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
static char* COMPOUND_ELEMENT_SEPARATOR = FULL_STOP_CHARACTER_ARRAY;
static int* COMPOUND_ELEMENT_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Operation.
//

/** The operation parameter separator. */
static char* OPERATION_PARAMETER_SEPARATOR = COMMA_CHARACTER_ARRAY;
static int* OPERATION_PARAMETER_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Cyboi.
//

/** The startup parameters count. */
static int* STARTUP_PARAMETERS_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The command parameter index. */
static int* COMMAND_PARAMETER_INDEX = NUMBER_0_INTEGER_ARRAY;

/** The run file parameter index. */
static int* RUN_FILE_PARAMETER_INDEX = NUMBER_1_INTEGER_ARRAY;

/* CONSTANT_SOURCE */
#endif
