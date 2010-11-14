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
 * @version $RCSfile: primitive_type_size.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PRIMITIVE_TYPE_SIZE_SOURCE
#define PRIMITIVE_TYPE_SIZE_SOURCE

//
// CAUTION! The glibc manual states that the data type of the result
// of the "sizeof" function may vary between compilers.
// It therefore recommends to use type "size_t" (instead of "int")
// as the preferred way to declare any arguments or variables
// that hold the size of an object.
//
// See:
// http://www.gnu.org/software/libtool/manual/libc/Important-Data-Types.html#Important-Data-Types
//
// However, cyboi assigns the sizes of all primitive types to special
// global integer variables at system startup, in module "globaliser.c".
// As long as these global integer variables are used, there is
// no need to work with type "sizt_t" in cyboi source code.
//

/** The char primitive type size. */
static int* CHARACTER_PRIMITIVE_TYPE_SIZE;

/* PRIMITIVE_TYPE_SIZE_SOURCE */
#endif
