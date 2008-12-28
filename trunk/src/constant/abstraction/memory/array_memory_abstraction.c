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
 * @version $RCSfile: array_memory_abstraction.c,v $ $Revision: 1.4 $ $Date: 2008-12-28 12:14:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_MEMORY_ABSTRACTION_SOURCE
#define ARRAY_MEMORY_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

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

/* ARRAY_MEMORY_ABSTRACTION_SOURCE */
#endif
