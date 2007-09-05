/*
 * $RCSfile: xdt_package_name_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-09-05 21:19:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_PACKAGE_NAME_CONSTANTS_SOURCE
#define XDT_PACKAGE_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The standard package name. */
static char STANDARD_XDT_PACKAGE_NAME_ARRAY[] = {'s', 't', 'a', 'n', 'd', 'a', 'r', 'd'};
static char* STANDARD_XDT_PACKAGE_NAME = STANDARD_XDT_PACKAGE_NAME_ARRAY;
static int* STANDARD_XDT_PACKAGE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/* XDT_PACKAGE_NAME_CONSTANTS_SOURCE */
#endif
