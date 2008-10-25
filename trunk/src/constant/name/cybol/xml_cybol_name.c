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
 * @version $RCSfile: xml_cybol_name.c,v $ $Revision: 1.2 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_CYBOL_NAME_SOURCE
#define XML_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The part xml cybol name. */
static wchar_t PART_XML_CYBOL_NAME_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* PART_XML_CYBOL_NAME = PART_XML_CYBOL_NAME_ARRAY;
static int* PART_XML_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The tag xml cybol name. */
static wchar_t TAG_XML_CYBOL_NAME_ARRAY[] = {L't', L'a', L'g'};
static wchar_t* TAG_XML_CYBOL_NAME = TAG_XML_CYBOL_NAME_ARRAY;
static int* TAG_XML_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* XML_CYBOL_NAME_SOURCE */
#endif
