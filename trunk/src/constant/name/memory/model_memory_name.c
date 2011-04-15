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

#ifndef MODEL_MEMORY_NAME_SOURCE
#define MODEL_MEMORY_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The names model memory name. */
static int* NAMES_MODEL_MEMORY_NAME = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The abstractions model memory name. */
static int* ABSTRACTIONS_MODEL_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The models model memory name. */
static int* MODELS_MODEL_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The details model memory name. */
static int* DETAILS_MODEL_MEMORY_NAME = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

//?? DELETE constants below later!

/** The data model memory name. */
static int* DATA_MODEL_MEMORY_NAME = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The count model memory name. */
static int* COUNT_MODEL_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The size model memory name. */
static int* SIZE_MODEL_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* MODEL_MEMORY_NAME_SOURCE */
#endif
