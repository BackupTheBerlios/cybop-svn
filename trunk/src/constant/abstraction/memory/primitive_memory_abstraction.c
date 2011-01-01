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

#ifndef PRIMITIVE_MEMORY_ABSTRACTION_SOURCE
#define PRIMITIVE_MEMORY_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// CAUTION! These primitive memory abstraction constants HAVE TO BE of type "int*"!
//
// When memory gets allocated in form of an array with elements of the same
// primitive abstraction (type), then this is done in special array functions.
// These functions have to find out which type of array to allocate,
// by comparing the "abstraction" argument handed over with existing
// primitive abstraction constants as defined right here.
//
// It is not possible to use "wchar_t*" (string) as type for these constants,
// because the array functions would have to use their own array functions
// (circular reference) for comparing the abstraction that was handed over as argument.
//
// Therefore, the type "int*" is used for the constants defined here.
//

//
// Count.
//
// This count is valid for ALL primitive memory abstractions below,
// as they are just integer numbers.
//

/** The memory abstraction count. */
static int* PRIMITIVE_MEMORY_ABSTRACTION_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Primitive.
//

/** The character memory abstraction. */
static int* CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The double memory abstraction. */
static int* DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer memory abstraction. */
static int* INTEGER_PRIMITIVE_MEMORY_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The pointer memory abstraction. */
static int* POINTER_PRIMITIVE_MEMORY_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned long memory abstraction. */
static int* UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide character memory abstraction. */
static int* WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* PRIMITIVE_MEMORY_ABSTRACTION_SOURCE */
#endif
