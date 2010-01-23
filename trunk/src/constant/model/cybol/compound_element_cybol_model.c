/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: compound_element_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ELEMENT_CYBOL_MODEL_SOURCE
#define COMPOUND_ELEMENT_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The meta compound element cybol model. */
static wchar_t META_COMPOUND_ELEMENT_CYBOL_MODEL_ARRAY[] = {L'm', L'e', L't', L'a'};
static wchar_t* META_COMPOUND_ELEMENT_CYBOL_MODEL = META_COMPOUND_ELEMENT_CYBOL_MODEL_ARRAY;
static int* META_COMPOUND_ELEMENT_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The part compound element cybol model. */
static wchar_t PART_COMPOUND_ELEMENT_CYBOL_MODEL_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* PART_COMPOUND_ELEMENT_CYBOL_MODEL = PART_COMPOUND_ELEMENT_CYBOL_MODEL_ARRAY;
static int* PART_COMPOUND_ELEMENT_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPOUND_ELEMENT_CYBOL_MODEL_SOURCE */
#endif
