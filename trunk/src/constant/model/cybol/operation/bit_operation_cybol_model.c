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
 * @version $RCSfile: bit_operation_cybol_model.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BIT_OPERATION_CYBOL_MODEL_SOURCE
#define BIT_OPERATION_CYBOL_MODEL_SOURCE

#include "../../../../constant/model/memory/integer_memory_model.c"

/** The shift left bit operation cybol model. It corresponds to "SHL" assembler command. */
static wchar_t SHIFT_LEFT_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'h', L'i', L'f', L't', L'_', L'l', L'e', L'f', L't'};
static wchar_t* SHIFT_LEFT_BIT_OPERATION_CYBOL_MODEL = SHIFT_LEFT_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* SHIFT_LEFT_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The shift right bit operation cybol model. It corresponds to "SHR" assembler command. */
static wchar_t SHIFT_RIGHT_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'h', L'i', L'f', L't', L'_', L'r', L'i', L'g', L'h', L't'};
static wchar_t* SHIFT_RIGHT_BIT_OPERATION_CYBOL_MODEL = SHIFT_RIGHT_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* SHIFT_RIGHT_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The rotate left bit operation cybol model. It corresponds to "ROL" assembler command. */
static wchar_t ROTATE_LEFT_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'o', L't', L'a', L't', L'e', L'_', L'l', L'e', L'f', L't'};
static wchar_t* ROTATE_LEFT_BIT_OPERATION_CYBOL_MODEL = ROTATE_LEFT_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* ROTATE_LEFT_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The rotate right bit operation cybol model. It corresponds to "ROR" assembler command. */
static wchar_t ROTATE_RIGHT_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'o', L't', L'a', L't', L'e', L'_', L'r', L'i', L'g', L'h', L't'};
static wchar_t* ROTATE_RIGHT_BIT_OPERATION_CYBOL_MODEL = ROTATE_RIGHT_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* ROTATE_RIGHT_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The set bit operation cybol model. It corresponds to "BTS" assembler command. */
static wchar_t SET_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L's', L'e', L't', L'_', L'b', L'i', L't'};
static wchar_t* SET_BIT_OPERATION_CYBOL_MODEL = SET_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* SET_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The reset bit operation cybol model. It corresponds to "BTR" assembler command. */
static wchar_t RESET_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L'r', L'e', L's', L'e', L't', L'_', L'b', L'i', L't'};
static wchar_t* RESET_BIT_OPERATION_CYBOL_MODEL = RESET_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* RESET_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The get bit operation cybol model. It corresponds to "BT" assembler command. */
static wchar_t GET_BIT_OPERATION_CYBOL_MODEL_ARRAY[] = {L'g', L'e', L't', L'_', L'b', L'i', L't'};
static wchar_t* GET_BIT_OPERATION_CYBOL_MODEL = GET_BIT_OPERATION_CYBOL_MODEL_ARRAY;
static int* GET_BIT_OPERATION_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* BIT_OPERATION_CYBOL_MODEL_SOURCE */
#endif
