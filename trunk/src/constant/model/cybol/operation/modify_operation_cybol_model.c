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
 * @version $RCSfile: run_operation_cybol_model.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODIFY_OPERATION_CYBOL_MODEL_SOURCE
#define MODIFY_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>

#include "../../../../constant/model/memory/integer_memory_model.c"

/** The append modify operation cybol model. */
static wchar_t APPEND_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'a', L'p', L'p', L'e', L'n', L'd'};
static wchar_t* APPEND_MODIFY_OPERATION_CYBOL_MODEL = APPEND_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* APPEND_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The build modify operation cybol model. */
static wchar_t BUILD_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'u', L'i', L'l', L'd'};
static wchar_t* BUILD_MODIFY_OPERATION_CYBOL_MODEL = BUILD_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* BUILD_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The count modify operation cybol model. */
static wchar_t COUNT_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_MODIFY_OPERATION_CYBOL_MODEL = COUNT_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* COUNT_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The get modify operation cybol model. */
static wchar_t GET_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'e', L't'};
static wchar_t* GET_MODIFY_OPERATION_CYBOL_MODEL = GET_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* GET_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The insert modify operation cybol model. */
static wchar_t INSERT_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'i', L'n', L's', L'e', L'r', L't'};
static wchar_t* INSERT_MODIFY_OPERATION_CYBOL_MODEL = INSERT_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* INSERT_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The overwrite modify operation cybol model. */
static wchar_t OVERWRITE_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'o', L'v', L'e', L'r', L'w', L'r', L'i', L't', L'e'};
static wchar_t* OVERWRITE_MODIFY_OPERATION_CYBOL_MODEL = OVERWRITE_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* OVERWRITE_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The remove modify operation cybol model. */
static wchar_t REMOVE_MODIFY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'e', L'm', L'o', L'v', L'e'};
static wchar_t* REMOVE_MODIFY_OPERATION_CYBOL_MODEL = REMOVE_MODIFY_OPERATION_CYBOL_MODEL_ARRAY;
static int* REMOVE_MODIFY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* MODIFY_OPERATION_CYBOL_MODEL_SOURCE */
#endif
