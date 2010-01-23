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
 * @version $RCSfile: service_interrupt.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_INTERRUPT_SOURCE
#define SERVICE_INTERRUPT_SOURCE

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

/** The gnu linux console exit flag. */
static int* GNU_LINUX_CONSOLE_EXIT;
/** The x window system exit flag. */
static int* X_WINDOW_SYSTEM_EXIT;
/** The www service exit flag. */
static int* WWW_SERVICE_EXIT;
/** The cyboi service exit flag. */
static int* CYBOI_SERVICE_EXIT;

/* SERVICE_INTERRUPT_SOURCE */
#endif
