/*
 * $RCSfile: cybol_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.6 $ $Date: 2007-01-14 22:06:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CONSTANTS_SOURCE
#define CYBOL_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Cybol tag attributes.
//

/** The name attribute. */
static char NAME_ATTRIBUTE_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;
static int* NAME_ATTRIBUTE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The channel attribute. */
static char CHANNEL_ATTRIBUTE_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* CHANNEL_ATTRIBUTE = CHANNEL_ATTRIBUTE_ARRAY;
static int* CHANNEL_ATTRIBUTE_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The abstraction attribute. */
static char ABSTRACTION_ATTRIBUTE_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* ABSTRACTION_ATTRIBUTE = ABSTRACTION_ATTRIBUTE_ARRAY;
static int* ABSTRACTION_ATTRIBUTE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The model attribute. */
static char MODEL_ATTRIBUTE_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* MODEL_ATTRIBUTE = MODEL_ATTRIBUTE_ARRAY;
static int* MODEL_ATTRIBUTE_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Knowledge model separators.
//

/** The compound part separator. */
static char COMPOUND_PART_SEPARATOR_ARRAY[] = {'.'};
static char* COMPOUND_PART_SEPARATOR = COMPOUND_PART_SEPARATOR_ARRAY;
static int* COMPOUND_PART_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The compound meta separator. */
static char COMPOUND_META_SEPARATOR_ARRAY[] = {'#'};
static char* COMPOUND_META_SEPARATOR = COMPOUND_META_SEPARATOR_ARRAY;
static int* COMPOUND_META_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The operation parameter separator. */
static char OPERATION_PARAMETER_SEPARATOR_ARRAY[] = {','};
static char* OPERATION_PARAMETER_SEPARATOR = OPERATION_PARAMETER_SEPARATOR_ARRAY;
static int* OPERATION_PARAMETER_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The list separator between base name and index. */
static char LIST_SEPARATOR_ARRAY[] = {'_', '$'};
static char* LIST_SEPARATOR = LIST_SEPARATOR_ARRAY;
static int* LIST_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

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

/* CYBOL_CONSTANTS_SOURCE */
#endif
