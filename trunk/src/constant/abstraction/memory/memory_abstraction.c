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
 * @version $RCSfile: memory_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_ABSTRACTION_SOURCE
#define MEMORY_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_model.c"

/** The character abstraction. */
static wchar_t CHARACTER_MEMORY_ABSTRACTION_ARRAY[] = {L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r'};
static wchar_t* CHARACTER_MEMORY_ABSTRACTION = CHARACTER_MEMORY_ABSTRACTION_ARRAY;
static int* CHARACTER_MEMORY_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The complex abstraction. */
static wchar_t COMPLEX_MEMORY_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'l', L'e', L'x'};
static wchar_t* COMPLEX_MEMORY_ABSTRACTION = COMPLEX_MEMORY_ABSTRACTION_ARRAY;
static int* COMPLEX_MEMORY_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The compound abstraction.
 *
 * Compound models consist of other compound or primitive models.
 * CAUTION! This is also used as knowledge memory abstraction!
 */
static wchar_t COMPOUND_MEMORY_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd'};
static wchar_t* COMPOUND_MEMORY_ABSTRACTION = COMPOUND_MEMORY_ABSTRACTION_ARRAY;
static int* COMPOUND_MEMORY_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The datetime abstraction. */
static wchar_t DATETIME_MEMORY_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e'};
static wchar_t* DATETIME_MEMORY_ABSTRACTION = DATETIME_MEMORY_ABSTRACTION_ARRAY;
static int* DATETIME_MEMORY_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The double abstraction. */
static wchar_t DOUBLE_MEMORY_ABSTRACTION_ARRAY[] = {L'd', L'o', L'u', L'b', L'l', L'e'};
static wchar_t* DOUBLE_MEMORY_ABSTRACTION = DOUBLE_MEMORY_ABSTRACTION_ARRAY;
static int* DOUBLE_MEMORY_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The double_vector abstraction. */
static wchar_t DOUBLE_VECTOR_MEMORY_ABSTRACTION_ARRAY[] = {L'd', L'o', L'u', L'b', L'l', L'e', L'_', L'v', L'e', L'c', L't', L'o', L'r'};
static wchar_t* DOUBLE_VECTOR_MEMORY_ABSTRACTION = DOUBLE_VECTOR_MEMORY_ABSTRACTION_ARRAY;
static int* DOUBLE_VECTOR_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The fraction abstraction. */
static wchar_t FRACTION_MEMORY_ABSTRACTION_ARRAY[] = {L'f', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* FRACTION_MEMORY_ABSTRACTION = FRACTION_MEMORY_ABSTRACTION_ARRAY;
static int* FRACTION_MEMORY_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The integer abstraction. */
static wchar_t INTEGER_MEMORY_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'g', L'e', L'r'};
static wchar_t* INTEGER_MEMORY_ABSTRACTION = INTEGER_MEMORY_ABSTRACTION_ARRAY;
static int* INTEGER_MEMORY_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The integer_vector abstraction. */
static wchar_t INTEGER_VECTOR_MEMORY_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'g', L'e', L'r', L'_', L'v', L'e', L'c', L't', L'o', L'r'};
static wchar_t* INTEGER_VECTOR_MEMORY_ABSTRACTION = INTEGER_VECTOR_MEMORY_ABSTRACTION_ARRAY;
static int* INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The internal_memory abstraction. */
static wchar_t INTERNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'n', L'a', L'l', L'_', L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* INTERNAL_MEMORY_MEMORY_ABSTRACTION = INTERNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY;
static int* INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The pointer_vector abstraction. */
static wchar_t POINTER_VECTOR_MEMORY_ABSTRACTION_ARRAY[] = {L'p', L'o', L'i', L'n', L't', L'e', L'r', L'_', L'v', L'e', L'c', L't', L'o', L'r'};
static wchar_t* POINTER_VECTOR_MEMORY_ABSTRACTION = POINTER_VECTOR_MEMORY_ABSTRACTION_ARRAY;
static int* POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The signal_memory abstraction. */
static wchar_t SIGNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY[] = {L's', L'i', L'g', L'n', L'a', L'l', L'_', L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* SIGNAL_MEMORY_MEMORY_ABSTRACTION = SIGNAL_MEMORY_MEMORY_ABSTRACTION_ARRAY;
static int* SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The unsigned_long_vector abstraction. */
static wchar_t UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION_ARRAY[] = {L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L'_', L'l', L'o', L'n', L'g'};
static wchar_t* UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION = UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION_ARRAY;
static int* UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The wide_character abstraction. */
static wchar_t WIDE_CHARACTER_MEMORY_ABSTRACTION_ARRAY[] = {L'w', L'i', L'd', L'e', L'_', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r'};
static wchar_t* WIDE_CHARACTER_MEMORY_ABSTRACTION = WIDE_CHARACTER_MEMORY_ABSTRACTION_ARRAY;
static int* WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The wide_character_vector abstraction. */
static wchar_t WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_ARRAY[] = {L'w', L'i', L'd', L'e', L'_', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L'_', L'v', L'e', L'c', L't', L'o', L'r'};
static wchar_t* WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION = WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_ARRAY;
static int* WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT = NUMBER_21_INTEGER_ARRAY;

/* MEMORY_ABSTRACTION_SOURCE */
#endif
