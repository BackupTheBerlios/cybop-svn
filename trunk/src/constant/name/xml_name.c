/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: xml_name.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_NAME_SOURCE
#define XML_NAME_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"

/** The begin comment tag xml name. */
static wchar_t BEGIN_COMMENT_TAG_XML_NAME_ARRAY[] = {L'<', L'!', L'-', L'-'};
static wchar_t* BEGIN_COMMENT_TAG_XML_NAME = BEGIN_COMMENT_TAG_XML_NAME_ARRAY;
static int* BEGIN_COMMENT_TAG_XML_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The end comment tag xml name. */
static wchar_t END_COMMENT_TAG_XML_NAME_ARRAY[] = {L'/', L'-', L'-', L'>'};
static wchar_t* END_COMMENT_TAG_XML_NAME = END_COMMENT_TAG_XML_NAME_ARRAY;
static int* END_COMMENT_TAG_XML_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The short end comment tag xml name. */
static wchar_t SHORT_END_COMMENT_TAG_XML_NAME_ARRAY[] = {L'-', L'-', L'>'};
static wchar_t* SHORT_END_COMMENT_TAG_XML_NAME = SHORT_END_COMMENT_TAG_XML_NAME_ARRAY;
static int* SHORT_END_COMMENT_TAG_XML_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The begin tag begin xml name. */
static wchar_t BEGIN_TAG_BEGIN_XML_NAME_ARRAY[] = {L'<'};
static wchar_t* BEGIN_TAG_BEGIN_XML_NAME = BEGIN_TAG_BEGIN_XML_NAME_ARRAY;
static int* BEGIN_TAG_BEGIN_XML_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The end tag begin xml name. */
static wchar_t END_TAG_BEGIN_XML_NAME_ARRAY[] = {L'<', L'/'};
static wchar_t* END_TAG_BEGIN_XML_NAME = END_TAG_BEGIN_XML_NAME_ARRAY;
static int* END_TAG_BEGIN_XML_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The tag end xml name. */
static wchar_t TAG_END_XML_NAME_ARRAY[] = {L'>'};
static wchar_t* TAG_END_XML_NAME = TAG_END_XML_NAME_ARRAY;
static int* TAG_END_XML_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The empty tag end xml name. */
static wchar_t EMPTY_TAG_END_XML_NAME_ARRAY[] = {L'/', L'>'};
static wchar_t* EMPTY_TAG_END_XML_NAME = EMPTY_TAG_END_XML_NAME_ARRAY;
static int* EMPTY_TAG_END_XML_NAME_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The attribute begin xml name. */
static wchar_t ATTRIBUTE_BEGIN_XML_NAME_ARRAY[] = {L' '};
static wchar_t* ATTRIBUTE_BEGIN_XML_NAME = ATTRIBUTE_BEGIN_XML_NAME_ARRAY;
static int* ATTRIBUTE_BEGIN_XML_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The attribute value begin xml name. */
static wchar_t ATTRIBUTE_VALUE_BEGIN_XML_NAME_ARRAY[] = {L'=', L'"'};
static wchar_t* ATTRIBUTE_VALUE_BEGIN_XML_NAME = ATTRIBUTE_VALUE_BEGIN_XML_NAME_ARRAY;
static int* ATTRIBUTE_VALUE_BEGIN_XML_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The attribute value end xml name. */
static wchar_t ATTRIBUTE_VALUE_END_XML_NAME_ARRAY[] = {L'"'};
static wchar_t* ATTRIBUTE_VALUE_END_XML_NAME = ATTRIBUTE_VALUE_END_XML_NAME_ARRAY;
static int* ATTRIBUTE_VALUE_END_XML_NAME_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/* XML_NAME_SOURCE */
#endif
