/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: thread_identification.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef THREAD_IDENTIFICATION_SOURCE
#define THREAD_IDENTIFICATION_SOURCE

#include <pthread.h>

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

/** The gnu linux console thread. */
static pthread_t* GNU_LINUX_CONSOLE_THREAD;
/** The x window system thread. */
static pthread_t* X_WINDOW_SYSTEM_THREAD;
/** The www service thread. */
static pthread_t* WWW_SERVICE_THREAD;
/** The cyboi service thread. */
static pthread_t* CYBOI_SERVICE_THREAD;

/* THREAD_IDENTIFICATION_SOURCE */
#endif
