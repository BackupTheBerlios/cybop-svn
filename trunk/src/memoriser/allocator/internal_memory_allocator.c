/*
 * $RCSfile: internal_memory_allocator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.12 $ $Date: 2007-05-16 19:29:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_ALLOCATOR_SOURCE
#define INTERNAL_MEMORY_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the internal memory.
 *
 * @param p0 the internal memory (Hand over as reference!)
 * @param p1 the internal memory size
 */
void allocate_internal_memory(void* p0, void* p1) {

    log_message_debug("Allocate internal memory.");

    // Allocate internal memory.
    allocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/**
 * Deallocates the internal memory.
 *
 * The configuration parameters existing in the internal memory have to be
 * deallocated (destroyed) where they were allocated (created)!
 *
 * If, for example, parameters were added by the x window system modules,
 * then these x window system modules are also responsible for destroying them.
 *
 * Configuration parameter allocation/ deallocation is thus clearly in the
 * responsibility of the module developer and no effort is undertaken here
 * to automatically deallocate those configuration parameters which are still
 * existent in internal memory (unequal *NULL_POINTER).
 *
 * @param p0 the internal memory (Hand over as reference!)
 * @param p1 the internal memory size
 */
void deallocate_internal_memory(void* p0, void* p1) {

    log_message_debug("Deallocate internal memory.");

    // CAUTION! Do NOT try to REMOVE the parameters!
    // Each configuration parameter has a fixed position within
    // the internal memory and CANNOT be removed.
    // Trying to do so, would result in a runtime error:
    // *** glibc detected *** double free or corruption (fasttop)
    // because the internal memory is already freed below.

    // Deallocate internal memory.
    deallocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/* INTERNAL_MEMORY_ALLOCATOR_SOURCE */
#endif
