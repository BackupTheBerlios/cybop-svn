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
// Primitive.
//

/** The character memory abstraction. */
static wchar_t CHARACTER_MEMORY_ABSTRACTION_ARRAY[] = {L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r'};
static wchar_t* CHARACTER_MEMORY_ABSTRACTION = CHARACTER_MEMORY_ABSTRACTION_ARRAY;
static int* CHARACTER_MEMORY_ABSTRACTION_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The double memory abstraction. */
static wchar_t DOUBLE_MEMORY_ABSTRACTION_ARRAY[] = {L'd', L'o', L'u', L'b', L'l', L'e'};
static wchar_t* DOUBLE_MEMORY_ABSTRACTION = DOUBLE_MEMORY_ABSTRACTION_ARRAY;
static int* DOUBLE_MEMORY_ABSTRACTION_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer memory abstraction. */
static wchar_t INTEGER_MEMORY_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'g', L'e', L'r'};
static wchar_t* INTEGER_MEMORY_ABSTRACTION = INTEGER_MEMORY_ABSTRACTION_ARRAY;
static int* INTEGER_MEMORY_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The pointer memory abstraction. */
static wchar_t POINTER_MEMORY_ABSTRACTION_ARRAY[] = {L'p', L'o', L'i', L'n', L't', L'e', L'r'};
static wchar_t* POINTER_MEMORY_ABSTRACTION = POINTER_MEMORY_ABSTRACTION_ARRAY;
static int* POINTER_MEMORY_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned_long memory abstraction. */
static wchar_t UNSIGNED_LONG_MEMORY_ABSTRACTION_ARRAY[] = {L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L'_', L'l', L'o', L'n', L'g'};
static wchar_t* UNSIGNED_LONG_MEMORY_ABSTRACTION = UNSIGNED_LONG_MEMORY_ABSTRACTION_ARRAY;
static int* UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide_character memory abstraction. */
static wchar_t WIDE_CHARACTER_MEMORY_ABSTRACTION_ARRAY[] = {L'w', L'i', L'd', L'e', L'_', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r'};
static wchar_t* WIDE_CHARACTER_MEMORY_ABSTRACTION = WIDE_CHARACTER_MEMORY_ABSTRACTION_ARRAY;
static int* WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

//
// Path.
//

/** The encapsulated_knowledge_path memory abstraction. */
static wchar_t ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_ARRAY[] = {L'e', L'n', L'c', L'a', L'p', L's', L'u', L'l', L'a', L't', L'e', L'd', L'_', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L'_', L'p', L'a', L't', L'h'};
static wchar_t* ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION = ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_ARRAY;
static int* ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The knowledge_path memory abstraction. */
static wchar_t KNOWLEDGE_PATH_MEMORY_ABSTRACTION_ARRAY[] = {L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L'_', L'p', L'a', L't', L'h'};
static wchar_t* KNOWLEDGE_PATH_MEMORY_ABSTRACTION = KNOWLEDGE_PATH_MEMORY_ABSTRACTION_ARRAY;
static int* KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

//
// Operation.
//

/** The operation memory abstraction. */
static wchar_t OPERATION_MEMORY_ABSTRACTION_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n'};
static wchar_t* OPERATION_MEMORY_ABSTRACTION = OPERATION_MEMORY_ABSTRACTION_ARRAY;
static int* OPERATION_MEMORY_ABSTRACTION_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

//
// Knowledge.
//

/**
 * The compound memory abstraction.
 *
 * Compound models consist of other compound or primitive models.
 * CAUTION! This is also used as knowledge memory abstraction!
 */
static wchar_t COMPOUND_MEMORY_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd'};
static wchar_t* COMPOUND_MEMORY_ABSTRACTION = COMPOUND_MEMORY_ABSTRACTION_ARRAY;
static int* COMPOUND_MEMORY_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The internal_memory memory abstraction. */
static wchar_t INTERNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'n', L'a', L'l', L'_', L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* INTERNAL_MEMORY_MEMORY_ABSTRACTION = INTERNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY;
static int* INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The model memory abstraction. */
//?? TODO: Delete this one later!
static wchar_t MODEL_MEMORY_ABSTRACTION_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* MODEL_MEMORY_ABSTRACTION = MODEL_MEMORY_ABSTRACTION_ARRAY;
static int* MODEL_MEMORY_ABSTRACTION_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The part memory abstraction. */
static wchar_t PART_MEMORY_ABSTRACTION_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* PART_MEMORY_ABSTRACTION = PART_MEMORY_ABSTRACTION_ARRAY;
static int* PART_MEMORY_ABSTRACTION_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The signal_memory memory abstraction. */
static wchar_t SIGNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY[] = {L's', L'i', L'g', L'n', L'a', L'l', L'_', L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* SIGNAL_MEMORY_MEMORY_ABSTRACTION = SIGNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY;
static int* SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

//
// Structure.
//

/** The complex memory abstraction. */
static wchar_t COMPLEX_MEMORY_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'l', L'e', L'x'};
static wchar_t* COMPLEX_MEMORY_ABSTRACTION = COMPLEX_MEMORY_ABSTRACTION_ARRAY;
static int* COMPLEX_MEMORY_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The datetime memory abstraction. */
static wchar_t DATETIME_MEMORY_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e'};
static wchar_t* DATETIME_MEMORY_ABSTRACTION = DATETIME_MEMORY_ABSTRACTION_ARRAY;
static int* DATETIME_MEMORY_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The fraction memory abstraction. */
static wchar_t FRACTION_MEMORY_ABSTRACTION_ARRAY[] = {L'f', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* FRACTION_MEMORY_ABSTRACTION = FRACTION_MEMORY_ABSTRACTION_ARRAY;
static int* FRACTION_MEMORY_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* MEMORY_ABSTRACTION_SOURCE */
#endif
