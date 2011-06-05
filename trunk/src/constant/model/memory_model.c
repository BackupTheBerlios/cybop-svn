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
 * @version $RCSfile: memory_model.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_MODEL_SOURCE
#define MEMORY_MODEL_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"

/** The complex memory model count. */
static int* COMPLEX_MEMORY_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The compound memory model count. */
static int* COMPOUND_MEMORY_MODEL_COUNT_NEW = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;
static int* COMPOUND_MEMORY_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The datetime memory model count. */
static int* DATETIME_MEMORY_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The fraction memory model count. */
static int* FRACTION_MEMORY_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The internal memory memory model count. */
static int* INTERNAL_MEMORY_MEMORY_MODEL_COUNT = NUMBER_1000_INTEGER_MEMORY_MODEL_ARRAY;

/** The item memory model count. */
static int* ITEM_MEMORY_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The model memory model count. */
//?? TODO: Delete this one (below) later!
static int* MODEL_MEMORY_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The part memory model count. */
static int* PART_MEMORY_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The primitive memory model count. */
static int* PRIMITIVE_MEMORY_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The signal memory memory model count. */
static int* SIGNAL_MEMORY_MEMORY_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* MEMORY_MODEL_SOURCE */
#endif
