/*
 * $RCSfile: signal_memory_manager.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.5 $ $Date: 2005-07-20 15:50:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_MANAGER_SOURCE
#define SIGNAL_MEMORY_MANAGER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/creator.c"

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

    // Initialise signal memory count, size.
    *sc = 0;
    *ss = 0;

    // Create signal memory.
    create((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT);

    // Set signal memory to internals.
    set_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
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
    void* sc = NULL_POINTER;
    void* ss = NULL_POINTER;

    // Get signal memory.
    get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_ARRAY);

    // Destroy signal memory.
    // CAUTION! Do NOT hand over as reference!
    // The variables are of type void**.
    // The expression (&*variable) is the same like (variable).
    destroy(s, ss, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT);
    destroy_integer(sc);
    destroy_integer(ss);
}

/* SIGNAL_MEMORY_MANAGER_SOURCE */
#endif
