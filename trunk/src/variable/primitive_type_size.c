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
 * @version $RCSfile: primitive_type_size.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PRIMITIVE_TYPE_SIZE_SOURCE
#define PRIMITIVE_TYPE_SIZE_SOURCE

//
// CAUTION! Do NOT try to assign any values here!
//
// Ideally, of course, *NULL_POINTER_MEMORY_MODEL would be assigned as initial value.
// But then, the compiler shows the following error:
// "error: initializer element is not constant"
//
// Therefore, the variables are only initialised in function "globalise"
// of module "globaliser.c".
//

/** The character primitive size. */
static int* CHARACTER_PRIMITIVE_SIZE;
/** The wide character primitive size. */
static int* WIDE_CHARACTER_PRIMITIVE_SIZE;
/** The pointer primitive size. */
static int* POINTER_PRIMITIVE_SIZE;
/** The integer primitive size. */
static int* INTEGER_PRIMITIVE_SIZE;
/** The unsigned long primitive size. */
static int* UNSIGNED_LONG_PRIMITIVE_SIZE;
/** The double primitive size. */
static int* DOUBLE_PRIMITIVE_SIZE;

/* PRIMITIVE_TYPE_SIZE_SOURCE */
#endif
