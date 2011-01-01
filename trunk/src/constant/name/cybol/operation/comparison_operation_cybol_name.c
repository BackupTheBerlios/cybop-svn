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
 * @version $RCSfile: comparison_operation_cybol_name.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARISON_OPERATION_CYBOL_NAME_SOURCE
#define COMPARISON_OPERATION_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The left side comparison operation cybol name. */
static wchar_t LEFT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't'};
static wchar_t* LEFT_SIDE_COMPARISON_OPERATION_CYBOL_NAME = LEFT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_ARRAY;
static int* LEFT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The right side comparison operation cybol name. */
static wchar_t RIGHT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_ARRAY[] = {L'r', L'i', L'g', L'h', L't'};
static wchar_t* RIGHT_SIDE_COMPARISON_OPERATION_CYBOL_NAME = RIGHT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_ARRAY;
static int* RIGHT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The result comparison operation cybol name. */
static wchar_t RESULT_COMPARISON_OPERATION_CYBOL_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* RESULT_COMPARISON_OPERATION_CYBOL_NAME = RESULT_COMPARISON_OPERATION_CYBOL_NAME_ARRAY;
static int* RESULT_COMPARISON_OPERATION_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The selection comparison operation cybol name. */
static wchar_t SELECTION_COMPARISON_OPERATION_CYBOL_NAME_ARRAY[] = {L's', L'e', L'l', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* SELECTION_COMPARISON_OPERATION_CYBOL_NAME = SELECTION_COMPARISON_OPERATION_CYBOL_NAME_ARRAY;
static int* SELECTION_COMPARISON_OPERATION_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPARISON_OPERATION_CYBOL_NAME_SOURCE */
#endif
