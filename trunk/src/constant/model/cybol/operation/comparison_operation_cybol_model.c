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
 * @version $RCSfile: comparison_operation_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARISON_OPERATION_CYBOL_MODEL_SOURCE
#define COMPARISON_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The equal comparison operation cybol model. */
static wchar_t EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY[] = {L'e', L'q', L'u', L'a', L'l'};
static wchar_t* EQUAL_COMPARISON_OPERATION_CYBOL_MODEL = EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY;
static int* EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller comparison operation cybol model. */
static wchar_t SMALLER_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r'};
static wchar_t* SMALLER_COMPARISON_OPERATION_CYBOL_MODEL = SMALLER_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY;
static int* SMALLER_COMPARISON_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater comparison operation cybol model. */
static wchar_t GREATER_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r'};
static wchar_t* GREATER_COMPARISON_OPERATION_CYBOL_MODEL = GREATER_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY;
static int* GREATER_COMPARISON_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller or equal comparison operation cybol model. */
static wchar_t SMALLER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* SMALLER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL = SMALLER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY;
static int* SMALLER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater or equal comparison operation cybol model. */
static wchar_t GREATER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* GREATER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL = GREATER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_ARRAY;
static int* GREATER_OR_EQUAL_COMPARISON_OPERATION_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPARISON_OPERATION_CYBOL_MODEL_SOURCE */
#endif
