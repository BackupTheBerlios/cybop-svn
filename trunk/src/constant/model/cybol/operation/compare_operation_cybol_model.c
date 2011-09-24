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
 * @version $RCSfile: comparison_operation_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_OPERATION_CYBOL_MODEL_SOURCE
#define COMPARE_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>

#include "../../../../constant/model/memory/integer_memory_model.c"

/** The equal compare operation cybol model. */
static wchar_t EQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'e', L'q', L'u', L'a', L'l'};
static wchar_t* EQUAL_COMPARE_OPERATION_CYBOL_MODEL = EQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* EQUAL_COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater compare operation cybol model. */
static wchar_t GREATER_COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r'};
static wchar_t* GREATER_COMPARE_OPERATION_CYBOL_MODEL = GREATER_COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* GREATER_COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater_or_equal compare operation cybol model. */
static wchar_t GREATER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* GREATER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL = GREATER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* GREATER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller compare operation cybol model. */
static wchar_t SMALLER_COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r'};
static wchar_t* SMALLER_COMPARE_OPERATION_CYBOL_MODEL = SMALLER_COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* SMALLER_COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller_or_equal compare operation cybol model. */
static wchar_t SMALLER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* SMALLER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL = SMALLER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* SMALLER_OR_EQUAL_COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The unequal compare operation cybol model. */
static wchar_t UNEQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'u', L'n', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* UNEQUAL_COMPARE_OPERATION_CYBOL_MODEL = UNEQUAL_COMPARE_OPERATION_CYBOL_MODEL_ARRAY;
static int* UNEQUAL_COMPARE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPARE_OPERATION_CYBOL_MODEL_SOURCE */
#endif
