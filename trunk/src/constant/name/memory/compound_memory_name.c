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
 * @version $RCSfile: compound_memory_name.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_MEMORY_NAME_SOURCE
#define COMPOUND_MEMORY_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//?? Delete this file later!
//?? The compound is a dynamic memory structure consisting of parts.
//?? A part consists of: name, abstraction, model, details.
//?? Each of these four is a model consisting of: pointer, count, size.

/** The names compound memory name. */
static int* NAMES_COMPOUND_MEMORY_NAME = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The names counts compound memory name. */
static int* NAMES_COUNTS_COMPOUND_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The names sizes compound memory name. */
static int* NAMES_SIZES_COMPOUND_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The abstractions compound memory name. */
static int* ABSTRACTIONS_COMPOUND_MEMORY_NAME = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The abstractions counts compound memory name. */
static int* ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The abstractions sizes compound memory name. */
static int* ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The models compound memory name. */
static int* MODELS_COMPOUND_MEMORY_NAME = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The models counts compound memory name. */
static int* MODELS_COUNTS_COMPOUND_MEMORY_NAME = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The models sizes compound memory name. */
static int* MODELS_SIZES_COMPOUND_MEMORY_NAME = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The details compound memory name. */
static int* DETAILS_COMPOUND_MEMORY_NAME = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The details counts compound memory name. */
static int* DETAILS_COUNTS_COMPOUND_MEMORY_NAME = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The details sizes compound memory name. */
static int* DETAILS_SIZES_COMPOUND_MEMORY_NAME = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPOUND_MEMORY_NAME_SOURCE */
#endif
