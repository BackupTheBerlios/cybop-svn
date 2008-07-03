/*
 * $RCSfile: cybol_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2008-07-03 09:24:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CONSTANTS_SOURCE
#define CYBOL_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Cybol tag attributes.
//

/** The name attribute. */
static wchar_t NAME_ATTRIBUTE_ARRAY[] = {L'n', L'a', L'm', L'e'};
static wchar_t* NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;
static int* NAME_ATTRIBUTE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The channel attribute. */
static wchar_t CHANNEL_ATTRIBUTE_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_ATTRIBUTE = CHANNEL_ATTRIBUTE_ARRAY;
static int* CHANNEL_ATTRIBUTE_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The abstraction attribute. */
static wchar_t ABSTRACTION_ATTRIBUTE_ARRAY[] = {L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* ABSTRACTION_ATTRIBUTE = ABSTRACTION_ATTRIBUTE_ARRAY;
static int* ABSTRACTION_ATTRIBUTE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The model attribute. */
static wchar_t MODEL_ATTRIBUTE_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* MODEL_ATTRIBUTE = MODEL_ATTRIBUTE_ARRAY;
static int* MODEL_ATTRIBUTE_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Cybol tag attributes as char.
// They are needed by the "compound_converter.c" module and
// may (possibly) be deleted later, if a self-written XML parser is used.
//

/** The name attribute as char. */
static char NAME_ATTRIBUTE_AS_CHAR_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* NAME_ATTRIBUTE_AS_CHAR = NAME_ATTRIBUTE_AS_CHAR_ARRAY;
static int* NAME_ATTRIBUTE_AS_CHAR_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The channel attribute as char. */
static char CHANNEL_ATTRIBUTE_AS_CHAR_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* CHANNEL_ATTRIBUTE_AS_CHAR = CHANNEL_ATTRIBUTE_AS_CHAR_ARRAY;
static int* CHANNEL_ATTRIBUTE_AS_CHAR_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The abstraction attribute as char. */
static char ABSTRACTION_ATTRIBUTE_AS_CHAR_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* ABSTRACTION_ATTRIBUTE_AS_CHAR = ABSTRACTION_ATTRIBUTE_AS_CHAR_ARRAY;
static int* ABSTRACTION_ATTRIBUTE_AS_CHAR_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The model attribute as char. */
static char MODEL_ATTRIBUTE_AS_CHAR_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* MODEL_ATTRIBUTE_AS_CHAR = MODEL_ATTRIBUTE_AS_CHAR_ARRAY;
static int* MODEL_ATTRIBUTE_AS_CHAR_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Knowledge model separators.
//

/** The compound part separator. */
static wchar_t COMPOUND_PART_SEPARATOR_ARRAY[] = {L'.'};
static wchar_t* COMPOUND_PART_SEPARATOR = COMPOUND_PART_SEPARATOR_ARRAY;
static int* COMPOUND_PART_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The compound meta separator. */
static wchar_t COMPOUND_META_SEPARATOR_ARRAY[] = {L'#'};
static wchar_t* COMPOUND_META_SEPARATOR = COMPOUND_META_SEPARATOR_ARRAY;
static int* COMPOUND_META_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The operation parameter separator. */
static wchar_t OPERATION_PARAMETER_SEPARATOR_ARRAY[] = {L','};
static wchar_t* OPERATION_PARAMETER_SEPARATOR = OPERATION_PARAMETER_SEPARATOR_ARRAY;
static int* OPERATION_PARAMETER_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The list separator between base name and index. */
static wchar_t LIST_SEPARATOR_ARRAY[] = {L'_', L'$'};
static wchar_t* LIST_SEPARATOR = LIST_SEPARATOR_ARRAY;
static int* LIST_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Xml markups.
//

/** The begin comment tag array, pointer, count. */
static wchar_t BEGIN_COMMENT_TAG_ARRAY[] = {L'<', L'!', L'-', L'-'};
static wchar_t* BEGIN_COMMENT_TAG = BEGIN_COMMENT_TAG_ARRAY;
static int* BEGIN_COMMENT_TAG_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The end comment tag array, pointer, count. */
static wchar_t END_COMMENT_TAG_ARRAY[] = {L'/', L'-', L'-', L'>'};
static wchar_t* END_COMMENT_TAG = END_COMMENT_TAG_ARRAY;
static int* END_COMMENT_TAG_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The short end comment tag array, pointer, count. */
static wchar_t SHORT_END_COMMENT_TAG_ARRAY[] = {L'-', L'-', L'>'};
static wchar_t* SHORT_END_COMMENT_TAG = SHORT_END_COMMENT_TAG_ARRAY;
static int* SHORT_END_COMMENT_TAG_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The begin tag begin array, pointer, count. */
static wchar_t BEGIN_TAG_BEGIN_ARRAY[] = {L'<'};
static wchar_t* BEGIN_TAG_BEGIN = BEGIN_TAG_BEGIN_ARRAY;
static int* BEGIN_TAG_BEGIN_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The end tag begin array, pointer, count. */
static wchar_t END_TAG_BEGIN_ARRAY[] = {L'<', L'/'};
static wchar_t* END_TAG_BEGIN = END_TAG_BEGIN_ARRAY;
static int* END_TAG_BEGIN_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The tag end array, pointer, count. */
static wchar_t TAG_END_ARRAY[] = {L'>'};
static wchar_t* TAG_END = TAG_END_ARRAY;
static int* TAG_END_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The empty tag end array, pointer, count. */
static wchar_t EMPTY_TAG_END_ARRAY[] = {L'/', L'>'};
static wchar_t* EMPTY_TAG_END = EMPTY_TAG_END_ARRAY;
static int* EMPTY_TAG_END_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The attribute begin array, pointer, count. */
static wchar_t ATTRIBUTE_BEGIN_ARRAY[] = {L' '};
static wchar_t* ATTRIBUTE_BEGIN = ATTRIBUTE_BEGIN_ARRAY;
static int* ATTRIBUTE_BEGIN_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The attribute value begin array, pointer, count. */
static wchar_t ATTRIBUTE_VALUE_BEGIN_ARRAY[] = {L'=', L'"'};
static wchar_t* ATTRIBUTE_VALUE_BEGIN = ATTRIBUTE_VALUE_BEGIN_ARRAY;
static int* ATTRIBUTE_VALUE_BEGIN_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The attribute value end array, pointer, count. */
static wchar_t ATTRIBUTE_VALUE_END_ARRAY[] = {L'"'};
static wchar_t* ATTRIBUTE_VALUE_END = ATTRIBUTE_VALUE_END_ARRAY;
static int* ATTRIBUTE_VALUE_END_COUNT = NUMBER_1_INTEGER_ARRAY;

/* CYBOL_CONSTANTS_SOURCE */
#endif
