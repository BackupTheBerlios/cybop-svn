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
 * @version $RCSfile: arithmetic_operation_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARITHMETIC_OPERATION_CYBOL_MODEL_SOURCE
#define ARITHMETIC_OPERATION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The add arithmetic operation cybol model. */
static wchar_t ADD_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY[] = {L'a', L'd', L'd'};
static wchar_t* ADD_ARITHMETIC_OPERATION_CYBOL_MODEL = ADD_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY;
static int* ADD_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The subtract arithmetic operation cybol model. */
static wchar_t SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'u', L'b', L't', L'r', L'a', L'c', L't'};
static wchar_t* SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL = SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY;
static int* SUBTRACT_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The multiply arithmetic operation cybol model. */
static wchar_t MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'u', L'l', L't', L'i', L'p', L'l', L'y'};
static wchar_t* MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL = MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY;
static int* MULTIPLY_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The divide arithmetic operation cybol model. */
static wchar_t DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY[] = {L'd', L'i', L'v', L'i', L'd', L'e'};
static wchar_t* DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL = DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY;
static int* DIVIDE_ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* ARITHMETIC_OPERATION_CYBOL_MODEL_SOURCE */
#endif
