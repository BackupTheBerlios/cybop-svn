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
 * @version $RCSfile: operation_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2008-09-07 23:01:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_CYBOL_MODEL_SOURCE
#define OPERATION_CYBOL_MODEL_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The arithmetic operation cybol model. */
static wchar_t ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY[] = {L'a', L'r', L'i', L't', L'h', L'm', L'e', L't', L'i', L'c'};
static wchar_t* ARITHMETIC_OPERATION_CYBOL_MODEL = ARITHMETIC_OPERATION_CYBOL_MODEL_ARRAY;
static int* ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The bit operation cybol model. */
static wchar_t BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'i', L't'};
static wchar_t* BIT_OPERATION_CYBOL_MODEL = BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The boolean operation cybol model. */
static wchar_t BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'b', L'o', L'o', L'l', L'e', L'a', L'n'};
static wchar_t* BOOLEAN_OPERATION_CYBOL_MODEL = BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY;
static int* BOOLEAN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The communication operation cybol model. */
static wchar_t COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'm', L'm', L'u', L'n', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* COMMUNICATION_OPERATION_CYBOL_MODEL = COMMUNICATION_OPERATION_CYBOL_MODEL_ARRAY;
static int* COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The comparison operation cybol model. */
static wchar_t COMPARISON_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n'};
static wchar_t* COMPARISON_OPERATION_CYBOL_MODEL = COMPARISON_OPERATION_CYBOL_MODEL_ARRAY;
static int* COMPARISON_OPERATION_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The flow operation cybol model. */
static wchar_t FLOW_OPERATION_CYBOL_MODEL_ARRAY[] = {L'f', L'l', L'o', L'w'};
static wchar_t* FLOW_OPERATION_CYBOL_MODEL = FLOW_OPERATION_CYBOL_MODEL_ARRAY;
static int* FLOW_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The lifecycle operation cybol model. */
static wchar_t LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY[] = {L'l', L'i', L'f', L'e', L'c', L'y', L'c', L'l', L'e'};
static wchar_t* LIFECYCLE_OPERATION_CYBOL_MODEL = LIFECYCLE_OPERATION_CYBOL_MODEL_ARRAY;
static int* LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The memory operation cybol model. */
static wchar_t MEMORY_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* MEMORY_OPERATION_CYBOL_MODEL = MEMORY_OPERATION_CYBOL_MODEL_ARRAY;
static int* MEMORY_OPERATION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The run operation cybol model. */
static wchar_t RUN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'u', L'n'};
static wchar_t* RUN_OPERATION_CYBOL_MODEL = RUN_OPERATION_CYBOL_MODEL_ARRAY;
static int* RUN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* OPERATION_CYBOL_MODEL_SOURCE */
#endif
