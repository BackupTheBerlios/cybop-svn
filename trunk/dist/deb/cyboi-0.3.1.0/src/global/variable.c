/*
 * $RCSfile: variable.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file defines global variables for:
 * - logging:
 *   - log settings
 * - array:
 *   - primitive type sizes
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * They have to be set on system startup.
 *
 * @version $Revision: 1.1 $ $Date: 2004-11-23 15:26:26 $ $Author: reichenbach $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VARIABLE_SOURCE
#define VARIABLE_SOURCE

#include <stdio.h>

//
// Log settings.
//

/** The log level. */
static int LOG_LEVEL;

/** The maximum log message count. */
static int MAXIMUM_LOG_MESSAGE_COUNT;

/** The log output. */
static FILE* LOG_OUTPUT;

//
// Primitive type sizes.
//

/** The pointer primitive size. */
static int POINTER_PRIMITIVE_SIZE;

/** The integer primitive size. */
static int INTEGER_PRIMITIVE_SIZE;

/** The character primitive size. */
static int CHARACTER_PRIMITIVE_SIZE;

/** The double primitive size. */
static int DOUBLE_PRIMITIVE_SIZE;

//
// Null pointers.
//
// CAUTION!
// These cannot be constant, because otherwise
// one could not alter their values later.
//

/** The null pointer. */
static void* NULL_POINTER;

/** The pointer null pointer. */
static void** POINTER_NULL_POINTER;

/** The integer null pointer. */
static int* INTEGER_NULL_POINTER;

/** The character null pointer. */
static char* CHARACTER_NULL_POINTER;

/** The double null pointer. */
static double* DOUBLE_NULL_POINTER;

/* VARIABLE_SOURCE */
#endif
