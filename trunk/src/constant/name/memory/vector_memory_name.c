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
 * @version $RCSfile: vector_memory_name.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VECTOR_MEMORY_NAME_SOURCE
#define VECTOR_MEMORY_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The dimension 0 vector memory name. In a (spatial) vector, this is the x coordinate. */
static int* DIMENSION_0_VECTOR_MEMORY_NAME = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The dimension 1 vector memory name. In a (spatial) vector, this is the y coordinate. */
static int* DIMENSION_1_VECTOR_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The dimension 2 vector memory name. In a (spatial) vector, this is the z coordinate. */
static int* DIMENSION_2_VECTOR_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/* VECTOR_MEMORY_NAME_SOURCE */
#endif
