/*
 * $RCSfile: internal_memory_manager.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2006-12-28 01:10:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_MANAGER_SOURCE
#define INTERNAL_MEMORY_MANAGER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Starts up the internal memory.
 *
 * CAUTION! The internal memory items have a fixed position,
 * determined by constants. The items HAVE TO be assigned an
 * initial value, since all source code relies on them.
 *
 * Most values are compared against the NULL_POINTER constant
 * to find out whether they are set or not. If now initial values
 * would be arbitrary pointers, the program would follow a wrong path,
 * because it would guess that an instance was properly allocated,
 * while in reality the value was just an arbitrary initial one.
 * Therefore, such values are initialised with the well-defined NULL_POINTER.
 *
 * CAUTION! ONLY ONE parameter can be handed over to threads!
 * For example, the tcp socket is running in an own thread.
 * Therefore, the knowledge memory and signal memory NEED TO BE ADDED
 * to the internal memory, in order to be forwardable to threads.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory (Hand over as reference!)
 * @param p2 the knowledge memory count (Hand over as reference!)
 * @param p3 the knowledge memory size (Hand over as reference!)
 * @param p4 the signal memory (Hand over as reference!)
 * @param p5 the signal memory count (Hand over as reference!)
 * @param p6 the signal memory size (Hand over as reference!)
 * @param p7 the signal memory mutex (Hand over as reference!)
 * @param p8 the signal memory interrupt request flag (Hand over as reference!)
 * @param p9 the linux console mutex (Hand over as reference!)
 * @param p10 the x window system mutex (Hand over as reference!)
 * @param p11 the www service mutex (Hand over as reference!)
 */
void startup_internal_memory(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("\n\n");
    log_message_debug("Information: Startup internal memory.");

    //
    // Initialise all values with null.
    //

    // The loop variable.
    int j = 0;

    while (1) {

        if (j >= *INTERNAL_MEMORY_ELEMENTS_COUNT) {

            break;
        }

        // Set null pointer at index.
        // CAUTION! The standard "set" procedure could have been used here as well.
        // However, to speed up the program, the "set_pointer_array_elements"
        // procedure was used directly, as it does not do so many comparisons
        // (like for example with "POINTER_VECTOR_ABSTRACTION", to find the right procedure).
        set_pointer_array_elements(p0, (void*) &j, (void*) &NULL_POINTER, (void*) NUMBER_1_INTEGER);

        j++;
    }

    //
    // Set special values.
    //

    // Set knowledge memory internals.
    set(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, p1, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Set signal memory internals.
    set(p0, (void*) SIGNAL_MEMORY_INTERNAL, p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, p5, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, p6, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Set signal memory mutex.
    set(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, p7, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set signal memory interrupt request flag.
    set(p0, (void*) INTERRUPT_REQUEST_INTERNAL, p8, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set linux console mutex.
    set(p0, (void*) LINUX_CONSOLE_MUTEX_INTERNAL, p9, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set x window system mutex.
    set(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, p10, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set www service mutex.
    set(p0, (void*) WWW_SERVICE_MUTEX_INTERNAL, p11, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
}

/* INTERNAL_MEMORY_MANAGER_SOURCE */
#endif
