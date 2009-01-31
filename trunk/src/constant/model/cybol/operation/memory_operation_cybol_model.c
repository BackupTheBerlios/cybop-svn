/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: memory_operation_cybol_model.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_OPERATION_CYBOL_MODEL_SOURCE
#define MEMORY_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The build listname flow operation cybol model. */
static wchar_t BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'u', L'i', L'l', L'd', L'_', L'l', L'i', L's', L't', L'n', L'a', L'm', L'e'};
static wchar_t* BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL = BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* BUILD_LISTNAME_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy (set, assign) transfer operation cybol model. */
static wchar_t COPY_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_MEMORY_OPERATION_CYBOL_MODEL = COPY_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* COPY_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The count flow operation cybol model. */
static wchar_t COUNT_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_MEMORY_OPERATION_CYBOL_MODEL = COUNT_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* COUNT_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The create memory operation cybol model. */
static wchar_t CREATE_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* CREATE_MEMORY_OPERATION_CYBOL_MODEL = CREATE_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* CREATE_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The destroy memory operation cybol model. */
static wchar_t DESTROY_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'd', L'e', L's', L't', L'r', L'o', L'y'};
static wchar_t* DESTROY_MEMORY_OPERATION_CYBOL_MODEL = DESTROY_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* DESTROY_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The get flow operation cybol model. */
static wchar_t GET_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'e', L't'};
static wchar_t* GET_MEMORY_OPERATION_CYBOL_MODEL = GET_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* GET_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The move transfer operation cybol model. */
static wchar_t MOVE_MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_MEMORY_OPERATION_CYBOL_MODEL = MOVE_MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* MOVE_MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* MEMORY_OPERATION_CYBOL_MODEL_SOURCE */
#endif
