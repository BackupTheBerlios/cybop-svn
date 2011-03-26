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
 * @version $RCSfile: memory_abstraction.c,v $ $Revision: 1.12 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PRIMITIVE_OPERATION_ABSTRACTION_SOURCE
#define PRIMITIVE_OPERATION_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// CAUTION! These primitive operation abstraction constants HAVE TO BE of type "int*"!
//
// When arrays are compared, then this is done in special comparison functions.
// These functions have to find out which kind of comparison to apply.
// This is done by comparing the "comparison" argument handed over with existing
// primitive operation abstraction constants as defined right here.
//
// It is not possible to use "wchar_t*" (string) as type for these constants,
// because the comparison functions would have to use their own comparison functions
// (circular reference) for comparing the operation abstraction that was handed over as argument.
//
// Therefore, the type "int*" is used for the constants defined here.
//

//
// Count.
//
// This count is valid for ALL primitive operation abstractions below,
// as they are just integer numbers.
//

/** The primitive operation abstraction count. */
static int* PRIMITIVE_OPERATION_ABSTRACTION_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Primitive operation.
//

/** The equal primitive operation abstraction. */
static int* EQUAL_PRIMITIVE_OPERATION_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller primitive operation abstraction. */
static int* SMALLER_PRIMITIVE_OPERATION_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater primitive operation abstraction. */
static int* GREATER_PRIMITIVE_OPERATION_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller or equal primitive operation abstraction. */
static int* SMALLER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater or equal primitive operation abstraction. */
static int* GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* PRIMITIVE_OPERATION_ABSTRACTION_SOURCE */
#endif
