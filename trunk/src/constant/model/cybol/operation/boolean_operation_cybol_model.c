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
 * @version $RCSfile: boolean_operation_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_OPERATION_CYBOL_MODEL_SOURCE
#define BOOLEAN_OPERATION_CYBOL_MODEL_SOURCE

#include "../../../../constant/model/memory/integer_model.c"

/** The not boolean operation cybol model. This is the ones complement (all bits negated). */
static wchar_t NOT_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'n', L'o', L't'};
static wchar_t* NOT_BOOLEAN_OPERATION_CYBOL_MODEL = NOT_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY;
static int* NOT_BOOLEAN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The neg boolean operation cybol model. This is the two's complement (all bits negated and added one). */
static wchar_t NEG_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'n', L'e', L'g'};
static wchar_t* NEG_BOOLEAN_OPERATION_CYBOL_MODEL = NEG_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY;
static int* NEG_BOOLEAN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The and boolean operation cybol model. */
static wchar_t AND_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'a', L'n', L'd'};
static wchar_t* AND_BOOLEAN_OPERATION_CYBOL_MODEL = AND_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY;
static int* AND_BOOLEAN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The or boolean operation cybol model. */
static wchar_t OR_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'o', L'r'};
static wchar_t* OR_BOOLEAN_OPERATION_CYBOL_MODEL = OR_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY;
static int* OR_BOOLEAN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The xor boolean operation cybol model. */
static wchar_t XOR_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY[] = {L'x', L'o', L'r'};
static wchar_t* XOR_BOOLEAN_OPERATION_CYBOL_MODEL = XOR_BOOLEAN_OPERATION_CYBOL_MODEL_ARRAY;
static int* XOR_BOOLEAN_OPERATION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/* BOOLEAN_OPERATION_CYBOL_MODEL_SOURCE */
#endif
