/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: character_entity_xml_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ENTITY_XML_MODEL_SOURCE
#define CHARACTER_ENTITY_XML_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The quotation mark character entity xml model. */
static wchar_t QUOTATION_MARK_CHARACTER_ENTITY_XML_MODEL_ARRAY[] = {L'q', L'u', L'o', L't'};
static wchar_t* QUOTATION_MARK_CHARACTER_ENTITY_XML_MODEL = QUOTATION_MARK_CHARACTER_ENTITY_XML_MODEL_ARRAY;
static int* QUOTATION_MARK_CHARACTER_ENTITY_XML_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The ampersand character entity xml model. */
static wchar_t AMPERSAND_CHARACTER_ENTITY_XML_MODEL_ARRAY[] = {L'a', L'm', L'p'};
static wchar_t* AMPERSAND_CHARACTER_ENTITY_XML_MODEL = AMPERSAND_CHARACTER_ENTITY_XML_MODEL_ARRAY;
static int* AMPERSAND_CHARACTER_ENTITY_XML_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The apostrophe character entity xml model. CAUTION! It is only used in XHTML. */
static wchar_t APOSTROPHE_CHARACTER_ENTITY_XML_MODEL_ARRAY[] = {L'a', L'p', L'o', L's'};
static wchar_t* APOSTROPHE_CHARACTER_ENTITY_XML_MODEL = APOSTROPHE_CHARACTER_ENTITY_XML_MODEL_ARRAY;
static int* APOSTROPHE_CHARACTER_ENTITY_XML_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The less than sign character entity xml model. */
static wchar_t LESS_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL_ARRAY[] = {L'l', L't'};
static wchar_t* LESS_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL = LESS_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL_ARRAY;
static int* LESS_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater than sign character entity xml model. */
static wchar_t GREATER_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL_ARRAY[] = {L'g', L't'};
static wchar_t* GREATER_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL = GREATER_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL_ARRAY;
static int* GREATER_THAN_SIGN_CHARACTER_ENTITY_XML_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* CHARACTER_ENTITY_XML_MODEL_SOURCE */
#endif
