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
 * @version $RCSfile: reallocation_factor.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REALLOCATION_FACTOR_SOURCE
#define REALLOCATION_FACTOR_SOURCE

//
// CAUTION! Do NOT try to assign any values here!
// Otherwise, the compiler shows the following error:
// "error: initializer element is not constant"
// Therefore, the variables are only initialised in module "globaliser.c".
//

/** The cybol file reallocation factor. */
static int* CYBOL_FILE_REALLOCATION_FACTOR;
/** The character vector reallocation factor. */
static int* CHARACTER_VECTOR_REALLOCATION_FACTOR;
/** The wide character vector reallocation factor. */
static int* WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR;
/** The integer vector reallocation factor. */
static int* INTEGER_VECTOR_REALLOCATION_FACTOR;
/** The unsigned long vector reallocation factor. */
static int* UNSIGNED_LONG_VECTOR_REALLOCATION_FACTOR;
/** The double vector reallocation factor. */
static int* DOUBLE_VECTOR_REALLOCATION_FACTOR;
/** The pointer vector reallocation factor. */
static int* POINTER_VECTOR_REALLOCATION_FACTOR;
/** The compound reallocation factor. */
static int* COMPOUND_REALLOCATION_FACTOR;
/** The signal memory reallocation factor. */
static int* SIGNAL_MEMORY_REALLOCATION_FACTOR;

/* REALLOCATION_FACTOR_SOURCE */
#endif
