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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_GLOBALISER_SOURCE
#define SIGNAL_GLOBALISER_SOURCE

#include <signal.h>
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/signal_type_size.c"

/**
 * Allocates and initialises signal global variables.
 */
void globalise_signal() {

    // Allocate and initialise sig_atomic_t signal type size.
    ATOMIC_SIGNAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *ATOMIC_SIGNAL_TYPE_SIZE = sizeof(sig_atomic_t);

    // Allocate and initialise volatile sig_atomic_t signal type size.
    VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE = sizeof(volatile sig_atomic_t);
}

/* SIGNAL_GLOBALISER_SOURCE */
#endif
