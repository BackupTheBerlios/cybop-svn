/*
 * $RCSfile: array_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2007-07-23 23:52:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef ARRAY_CONSTANTS_SOURCE
#define ARRAY_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The character array constant. */
static int* CHARACTER_ARRAY = NUMBER_0_INTEGER_ARRAY;

/** The wide character array constant. */
static int* WIDE_CHARACTER_ARRAY = NUMBER_1_INTEGER_ARRAY;

/** The integer array constant. */
static int* INTEGER_ARRAY = NUMBER_2_INTEGER_ARRAY;

/** The pointer array constant. */
static int* POINTER_ARRAY = NUMBER_3_INTEGER_ARRAY;

/** The double array constant. */
static int* DOUBLE_ARRAY = NUMBER_4_INTEGER_ARRAY;

/** The unsigned long array constant. */
static int* UNSIGNED_LONG_ARRAY = NUMBER_5_INTEGER_ARRAY;

/* ARRAY_CONSTANTS_SOURCE */
#endif
