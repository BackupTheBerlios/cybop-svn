/*
 * $RCSfile: variables.c,v $
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
 * @version $Revision: 1.13 $ $Date: 2007-06-22 07:07:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VARIABLES_SOURCE
#define VARIABLES_SOURCE

#include <pthread.h>
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"

//
// Primitive type sizes.
//

// The character primitive size.
static int* CHARACTER_PRIMITIVE_SIZE = (int*) NULL_POINTER_ARRAY;

// The wide character primitive size.
static int* WIDE_CHARACTER_PRIMITIVE_SIZE = (int*) NULL_POINTER_ARRAY;

// The pointer primitive size.
static int* POINTER_PRIMITIVE_SIZE = (int*) NULL_POINTER_ARRAY;

// The integer primitive size.
static int* INTEGER_PRIMITIVE_SIZE = (int*) NULL_POINTER_ARRAY;

// The unsigned long primitive size.
static int* UNSIGNED_LONG_PRIMITIVE_SIZE = (int*) NULL_POINTER_ARRAY;

// The double primitive size.
static int* DOUBLE_PRIMITIVE_SIZE = (int*) NULL_POINTER_ARRAY;

//
// Thread identifications and service interrupt flags.
//

// The gnu linux console thread.
static pthread_t* GNU_LINUX_CONSOLE_THREAD = (pthread_t*) NULL_POINTER_ARRAY;
// The x window system thread.
static pthread_t* X_WINDOW_SYSTEM_THREAD = (pthread_t*) NULL_POINTER_ARRAY;
// The www service thread.
static pthread_t* WWW_SERVICE_THREAD = (pthread_t*) NULL_POINTER_ARRAY;
// The cyboi service thread.
static pthread_t* CYBOI_SERVICE_THREAD = (pthread_t*) NULL_POINTER_ARRAY;

// The gnu linux console interrupt flag.
static int* GNU_LINUX_CONSOLE_THREAD_INTERRUPT = (int*) NULL_POINTER_ARRAY;
// The x window system interrupt flag.
static int* X_WINDOW_SYSTEM_THREAD_INTERRUPT = (int*) NULL_POINTER_ARRAY;
// The www service interrupt flag.
static int* WWW_SERVICE_THREAD_INTERRUPT = (int*) NULL_POINTER_ARRAY;
// The cyboi service interrupt flag.
static int* CYBOI_SERVICE_THREAD_INTERRUPT = (int*) NULL_POINTER_ARRAY;

//
// Logging.
//

// The log level.
//
// CAUTION! Do NOT try to use *OFF_LOG_LEVEL or *NUMBER_0_INTEGER here instead of the value 0!
// Otherwise, the system would show the following error, as it expects a constant value:
// "error: initializer element is not constant"
static int LOG_LEVEL = 0;

// The log output.
//
// CAUTION! Do NOT try to use *NUMBER_MINUS_1_INTEGER here instead of the value -1!
// Otherwise, the system would show the following error, as it expects a constant value:
// "error: initializer element is not constant"
static int LOG_OUTPUT = -1;

/* VARIABLES_SOURCE */
#endif
