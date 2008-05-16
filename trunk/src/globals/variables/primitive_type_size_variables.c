/*
 * $RCSfile: primitive_type_size_variables.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.5 $ $Date: 2008-05-16 23:15:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PRIMITIVE_TYPE_SIZE_VARIABLES_SOURCE
#define PRIMITIVE_TYPE_SIZE_VARIABLES_SOURCE

#include "../../globals/constants/integer/integer_constants.c"

//
// CAUTION! Do NOT try to assign any values here!
//
// Ideally, of course, *NULL_POINTER would be assigned as initial value.
// But then, the compiler shows the following error:
// "error: initializer element is not constant"
//
// Therefore, the variable is only initialised in function "globalise"
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

/* PRIMITIVE_TYPE_SIZE_VARIABLES_SOURCE */
#endif
