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
 * @version $RCSfile: memory_operation_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_OPERATION_CYBOL_MODEL_SOURCE
#define MEMORY_OPERATION_CYBOL_MODEL_SOURCE

#include "../../../../constant/model/memory/integer_model.c"

/** The create memory operation cybol model. */
static wchar_t CREATE_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* CREATE_MEMORY_OPERATION_CYBOL_MODEL = CREATE_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* CREATE_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The create part element memory operation cybol model. */
static wchar_t CREATE_PART_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* CREATE_PART_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL = CREATE_PART_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* CREATE_PART_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The create meta element memory operation cybol model. */
static wchar_t CREATE_META_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'e', L't', L'a'};
static wchar_t* CREATE_META_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL = CREATE_META_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* CREATE_META_ELEMENT_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The destroy memory operation cybol model. */
static wchar_t DESTROY_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'd', L'e', L's', L't', L'r', L'o', L'y'};
static wchar_t* DESTROY_MEMORY_OPERATION_CYBOL_MODEL = DESTROY_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* DESTROY_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_ARRAY;

/* MEMORY_OPERATION_CYBOL_MODEL_SOURCE */
#endif
