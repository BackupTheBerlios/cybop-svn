/*
 * $RCSfile: knowledge_memory_manager.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-07-12 10:38:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef KNOWLEDGE_MEMORY_HANDLER_SOURCE
#define KNOWLEDGE_MEMORY_HANDLER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/creator/creator.c"

/**
 * Starts up the knowledge memory.
 *
 * @param p0 the internals memory
 */
void startup_knowledge_memory(void* p0) {

    log_message_debug("Startup knowledge memory.");

    // The knowledge memory.
    void* k = NULL_POINTER;
    int* kc = INTEGER_NULL_POINTER;
    int* ks = INTEGER_NULL_POINTER;

    // Create knowledge memory count, size.
    create_integer((void*) &kc);
    create_integer((void*) &ks);

    // Initialize knowledge memory count, size.
    *kc = 0;
    *ks = 0;

    // Create knowledge memory.
    create((void*) &k, (void*) ks, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Set knowledge memory to internals.
    set_array_elements(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
}

/**
 * Shuts down the knowledge memory.
 *
 * @param p0 the internals memory
 */
void shutdown_knowledge_memory(void* p0) {

    log_message_debug("Shutdown knowledge memory.");

    // The knowledge memory.
    void* k = NULL_POINTER;
    void* kc = NULL_POINTER;
    void* ks = NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_ARRAY);

    // Destroy knowledge memory.
    // CAUTION! Do NOT hand over as reference!
    // The variables are of type void**.
    // The expression (&*variable) is the same like (variable).
    destroy(k, ks, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    destroy_integer(kc);
    destroy_integer(ks);
}

/* KNOWLEDGE_MEMORY_HANDLER_SOURCE */
#endif
