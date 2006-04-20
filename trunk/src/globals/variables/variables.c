/*
 * $RCSfile: variables.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.7 $ $Date: 2006-04-20 22:36:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VARIABLES_SOURCE
#define VARIABLES_SOURCE

#include <pthread.h>

//
// Null pointer.
//
// CAUTION! It must not be constant, because otherwise
// one could not alter the values it points to.
//

// The null pointer.
static void* NULL_POINTER;

//
// Primitive type sizes.
//

// The character primitive size.
static int* CHARACTER_PRIMITIVE_SIZE;

// The wide character primitive size.
static int* WIDE_CHARACTER_PRIMITIVE_SIZE;

// The pointer primitive size.
static int* POINTER_PRIMITIVE_SIZE;

// The integer primitive size.
static int* INTEGER_PRIMITIVE_SIZE;

// The unsigned long primitive size.
static int* UNSIGNED_LONG_PRIMITIVE_SIZE;

// The double primitive size.
static int* DOUBLE_PRIMITIVE_SIZE;

//
// Thread identifications and service interrupt flags.
//

// The linux console thread.
static pthread_t* LINUX_CONSOLE_THREAD;
// The unix socket thread.
static pthread_t* UNIX_SOCKET_THREAD;
// The tcp socket thread.
static pthread_t* TCP_SOCKET_THREAD;
// The x window system thread.
static pthread_t* X_WINDOW_SYSTEM_THREAD;

// The linux console interrupt flag.
static int* LINUX_CONSOLE_THREAD_INTERRUPT;
// The unix socket interrupt flag.
static int* UNIX_SOCKET_THREAD_INTERRUPT;
// The tcp socket interrupt flag.
static int* TCP_SOCKET_THREAD_INTERRUPT;
// The x window system interrupt flag.
static int* X_WINDOW_SYSTEM_THREAD_INTERRUPT;

//
// Logging.
//

// The log level.
static int* LOG_LEVEL;

// The log output.
static int LOG_OUTPUT;

/* VARIABLES_SOURCE */
#endif
