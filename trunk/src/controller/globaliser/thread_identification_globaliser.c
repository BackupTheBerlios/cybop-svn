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

#ifndef THREAD_IDENTIFICATION_GLOBALISER_SOURCE
#define THREAD_IDENTIFICATION_GLOBALISER_SOURCE

#include <pthread.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../variable/type_size/thread_type_size.c"
#include "../../variable/thread_identification.c"

/**
 * Allocates and initialises thread identification global variables.
 */
void globalise_thread_identification() {

    // Allocate cyboi service thread identification.
    CYBOI_SERVICE_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *CYBOI_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Allocate and initialise gnu/linux console thread identification.
    GNU_LINUX_CONSOLE_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *GNU_LINUX_CONSOLE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Allocate www service thread identification.
    WWW_SERVICE_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *WWW_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Allocate x window system thread identification.
    X_WINDOW_SYSTEM_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *X_WINDOW_SYSTEM_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
}

/* THREAD_IDENTIFICATION_GLOBALISER_SOURCE */
#endif
