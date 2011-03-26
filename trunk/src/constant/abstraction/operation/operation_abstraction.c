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

#ifndef OPERATION_ABSTRACTION_SOURCE
#define OPERATION_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// CAUTION! These operation abstraction constants HAVE TO BE of type "wchar_t*"!
//
// There is no problem with representing memory-internal abstractions by an integer number
// instead of a character array as long as just cybol abstractions are processed:
// - abstractions as given in cybol files are represented by characters, e.g. "boolean" or "xdt"
//   or for operations, e.g. "compare/equal" or "calculate/add"
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

//??
//?? CAUTION! These constants are possibly NOT needed.
//?? Similar ones are specified in directory "constant/abstraction/cybol/"
//?? Until this is sure, however, the constants are commented out.
//?? They may be deleted later.
//??

//
// Compare.
//

/** The equal operation abstraction. */
/*??
static wchar_t EQUAL_OPERATION_ABSTRACTION_ARRAY[] = {L'e', L'q', L'u', L'a', L'l'};
static wchar_t* EQUAL_OPERATION_ABSTRACTION = EQUAL_OPERATION_ABSTRACTION_ARRAY;
static int* EQUAL_OPERATION_ABSTRACTION_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater operation abstraction. */
/*??
static wchar_t GREATER_OPERATION_ABSTRACTION_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r'};
static wchar_t* GREATER_OPERATION_ABSTRACTION = GREATER_OPERATION_ABSTRACTION_ARRAY;
static int* GREATER_OPERATION_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater_or_equal operation abstraction. */
/*??
static wchar_t GREATER_OR_EQUAL_OPERATION_ABSTRACTION_ARRAY[] = {L'g', L'r', L'e', L'a', L't', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* GREATER_OR_EQUAL_OPERATION_ABSTRACTION = GREATER_OR_EQUAL_OPERATION_ABSTRACTION_ARRAY;
static int* GREATER_OR_EQUAL_OPERATION_ABSTRACTION_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller operation abstraction. */
/*??
static wchar_t SMALLER_OPERATION_ABSTRACTION_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r'};
static wchar_t* SMALLER_OPERATION_ABSTRACTION = SMALLER_OPERATION_ABSTRACTION_ARRAY;
static int* SMALLER_OPERATION_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller_or_equal operation abstraction. */
/*??
static wchar_t SMALLER_OR_EQUAL_OPERATION_ABSTRACTION_ARRAY[] = {L's', L'm', L'a', L'l', L'l', L'e', L'r', L'_', L'o', L'r', L'_', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* SMALLER_OR_EQUAL_OPERATION_ABSTRACTION = SMALLER_OR_EQUAL_OPERATION_ABSTRACTION_ARRAY;
static int* SMALLER_OR_EQUAL_OPERATION_ABSTRACTION_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

//
// Calculate.
//

/** The add operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L'a', L'd', L'd'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The divide operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L'd', L'i', L'v', L'i', L'd', L'e'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The multiply operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L'm', L'u', L'l', L't', L'i', L'p', L'l', L'y'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The subtract operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L's', L'u', L'b', L't', L'r', L'a', L'c', L't'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

//
// Route.
//

/** The branch operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L'b', L'r', L'a', L'n', L'c', L'h'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The loop operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L'l', L'o', L'o', L'p'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The sequence operation abstraction. */
/*??
static wchar_t ADD_OPERATION_ABSTRACTION_ARRAY[] = {L's', L'e', L'q', L'u', L'e', L'n', L'c', L'e'};
static wchar_t* ADD_OPERATION_ABSTRACTION = ADD_OPERATION_ABSTRACTION_ARRAY;
static int* ADD_OPERATION_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* OPERATION_ABSTRACTION_SOURCE */
#endif
