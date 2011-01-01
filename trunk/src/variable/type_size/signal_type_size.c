/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef SIGNAL_TYPE_SIZE_SOURCE
#define SIGNAL_TYPE_SIZE_SOURCE

//
// CAUTION! Do NOT try to assign any values here!
// Otherwise, the compiler shows the following error:
// "error: initializer element is not constant"
// Therefore, the variables are only initialised in module "globaliser.c".
//

/** The sig_atomic_t signal type size. */
static signed char* ATOMIC_SIGNAL_TYPE_SIZE;

/** The volatile sig_atomic_t signal type size. */
static signed char* VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE;

/* SIGNAL_TYPE_SIZE_SOURCE */
#endif
