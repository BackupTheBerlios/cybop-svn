/*
 * $RCSfile: signal_memory_handler.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.2 $ $Date: 2005-01-08 17:19:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_HANDLER_SOURCE
#define SIGNAL_MEMORY_HANDLER_SOURCE

#include "../global/abstraction_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"

/**
 * Starts up the signal memory.
 *
 * @param p0 the internals memory
 */
void startup_signal_memory(void* p0) {

    log_message_debug("Startup signal memory.");

    // The signal memory.
    void* s = NULL_POINTER;
    int* sc = INTEGER_NULL_POINTER;
    int* ss = INTEGER_NULL_POINTER;

    // Create signal memory count, size.
    create_integer((void*) &sc);
    create_integer((void*) &ss);

    // Initialize signal memory count, size.
    *sc = 0;
    *ss = 0;

    // Create signal memory.
    create((void*) &s, (void*) &ss, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);

    // Set signal memory to internals.
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) &ONE_ELEMENT_COUNT);
}

/**
 * Shuts down the signal memory.
 *
 * @param p0 the internals memory
 */
void shutdown_signal_memory(void* p0) {

    log_message_debug("Shutdown signal memory.");

    // The signal memory.
    void* s = NULL_POINTER;
    int* sc = INTEGER_NULL_POINTER;
    int* ss = INTEGER_NULL_POINTER;

    // Get signal memory.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) &ONE_ELEMENT_COUNT);

    // Destroy signal memory.
    destroy((void*) &s, (void*) &ss, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);
    destroy_integer((void*) &ss);
    destroy_integer((void*) &sc);
}

/* SIGNAL_MEMORY_HANDLER_SOURCE */
#endif
