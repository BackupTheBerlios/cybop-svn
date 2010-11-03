/*
 * Copyright (C) 1999-2010. Christian Heller.
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
// CAUTION! These memory abstraction constants HAVE TO BE of type "wchar_t*"!
//
// There is no problem with representing memory-internal abstractions by an integer number
// instead of a character array as long as just cybol abstractions are processed:
// - abstractions as given in cybol files are represented by characters, e.g. "boolean" or "xdt"
// - while parsing the cybol file, cyboi converts them into memory-internal structures
// - a "boolean" becomes and "int" and an "xdt" file becomes a "compound" memory model etc.
// - since the models have to be converted, the corresponding abstractions have to be converted as well
//
// It is true, integer numbers would be more efficient when processed in cyboi.
// This had been tried out and they had been applied.
//
// The problem, however, is, that runtime cyboi abstractions ARE ALSO USED
// in cybol applications, e.g. in cybol operation "add", "copy", "create".
//
// If having integers, then cybol application developers would have to
// learn which number references which memory abstraction (type).
// This is not good because cybol developers should not be forced
// to learn cyboi-internal stuff.
//
// Even worse, the assignment of integer numbers to abstraction constants
// may change, e.g. due to additional abstractions having to be added to cyboi.
//
// Therefore, using wide character sequences (strings) for cyboi-internal
// abstraction constants is necessary!
//

//
// Count.
//
// This count is valid for ALL memory abstractions below,
// as they are just integer numbers.
//

/** The memory abstraction count. */
static int* MEMORY_ABSTRACTION_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Primitive.
//
// Range: 0..999
//
// This big range is necessary, since different platforms
// (hardware as well as operating system) offer a plethora
// of primitive data types, that may have to be considered here.
//

/** The character memory abstraction. */
static int* CHARACTER_MEMORY_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The double memory abstraction. */
static int* DOUBLE_MEMORY_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer memory abstraction. */
static int* INTEGER_MEMORY_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The pointer memory abstraction. */
static int* POINTER_MEMORY_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned long memory abstraction. */
static int* UNSIGNED_LONG_MEMORY_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide character memory abstraction. */
static int* WIDE_CHARACTER_MEMORY_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

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

/** The model memory abstraction. */
static int* MODEL_MEMORY_ABSTRACTION = NUMBER_4002_INTEGER_MEMORY_MODEL_ARRAY;

/** The part memory abstraction. */
static int* PART_MEMORY_ABSTRACTION = NUMBER_4003_INTEGER_MEMORY_MODEL_ARRAY;

/** The signal memory memory abstraction. */
static int* SIGNAL_MEMORY_MEMORY_ABSTRACTION = NUMBER_4004_INTEGER_MEMORY_MODEL_ARRAY;

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
