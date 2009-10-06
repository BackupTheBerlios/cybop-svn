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
 * @version $RCSfile: memory_abstraction.c,v $ $Revision: 1.12 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_ABSTRACTION_SOURCE
#define MEMORY_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// Primitive.
//
// Range: 0..999
//
// This big range is necessary, since different platforms
// (hardware as well as operating system) offer a plethora
// of primitive data types, that may have to be considered here.
//

/** The character array memory abstraction. */
static int* CHARACTER_ARRAY_MEMORY_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The double array memory abstraction. */
static int* DOUBLE_ARRAY_MEMORY_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer array memory abstraction. */
static int* INTEGER_ARRAY_MEMORY_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The pointer array memory abstraction. */
static int* POINTER_ARRAY_MEMORY_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned long array memory abstraction. */
static int* UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide character array memory abstraction. */
static int* WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

//
// Vector.
//
// Range: 1000..1999
//

/** The character vector memory abstraction. */
static int* CHARACTER_VECTOR_MEMORY_ABSTRACTION = NUMBER_1000_INTEGER_MEMORY_MODEL_ARRAY;

/** The double vector memory abstraction. */
static int* DOUBLE_VECTOR_MEMORY_ABSTRACTION = NUMBER_1001_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer vector memory abstraction. */
static int* INTEGER_VECTOR_MEMORY_ABSTRACTION = NUMBER_1002_INTEGER_MEMORY_MODEL_ARRAY;

/** The pointer vector memory abstraction. */
static int* POINTER_VECTOR_MEMORY_ABSTRACTION = NUMBER_1003_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned long vector memory abstraction. */
static int* UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION = NUMBER_1004_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide character vector memory abstraction. */
static int* WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION = NUMBER_1005_INTEGER_MEMORY_MODEL_ARRAY;

//
// Path.
//
// Range: 2000..2999
//

/** The encapsulated knowledge path memory abstraction. */
static int* ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION = NUMBER_2000_INTEGER_MEMORY_MODEL_ARRAY;

/** The knowledge path memory abstraction. */
static int* KNOWLEDGE_PATH_MEMORY_ABSTRACTION = NUMBER_2001_INTEGER_MEMORY_MODEL_ARRAY;

//
// Operation.
//
// Range: 3000..3999
//

/** The operation memory abstraction. */
static int* OPERATION_MEMORY_ABSTRACTION = NUMBER_3000_INTEGER_MEMORY_MODEL_ARRAY;

//
// Knowledge.
//
// Range: 4000..4999
//

/**
 * The compound memory abstraction.
 *
 * Compound models consist of other compound or primitive models.
 * CAUTION! This is also used as knowledge memory abstraction!
 */
static int* COMPOUND_MEMORY_ABSTRACTION = NUMBER_4000_INTEGER_MEMORY_MODEL_ARRAY;

/** The internal memory memory abstraction. */
static int* INTERNAL_MEMORY_MEMORY_ABSTRACTION = NUMBER_4001_INTEGER_MEMORY_MODEL_ARRAY;

/** The part memory abstraction. */
static int* PART_MEMORY_ABSTRACTION = NUMBER_4002_INTEGER_MEMORY_MODEL_ARRAY;

/** The signal memory memory abstraction. */
static int* SIGNAL_MEMORY_MEMORY_ABSTRACTION = NUMBER_4003_INTEGER_MEMORY_MODEL_ARRAY;

//
// Structure.
//
// Range: 5000..9999
//
// This big range is necessary to provide structures required by
// graphical user interface frameworks or other external libraries.
//

/** The complex memory abstraction. */
static int* COMPLEX_MEMORY_ABSTRACTION = NUMBER_5000_INTEGER_MEMORY_MODEL_ARRAY;

/** The datetime memory abstraction. */
static int* DATETIME_MEMORY_ABSTRACTION = NUMBER_5001_INTEGER_MEMORY_MODEL_ARRAY;

/** The fraction memory abstraction. */
static int* FRACTION_MEMORY_ABSTRACTION = NUMBER_5002_INTEGER_MEMORY_MODEL_ARRAY;

/* MEMORY_ABSTRACTION_SOURCE */
#endif
