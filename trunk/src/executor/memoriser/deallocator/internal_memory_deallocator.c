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
 * @version $RCSfile: internal_memory_allocator.c,v $ $Revision: 1.20 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_DEALLOCATOR_SOURCE
#define INTERNAL_MEMORY_DEALLOCATOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

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
 * existent in internal memory (unequal *NULL_POINTER_MEMORY_MODEL).
 *
 * @param p0 the internal memory (Hand over as reference!)
 * @param p1 the internal memory size
 */
void deallocate_internal_memory(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Deallocate internal memory.");

    // CAUTION! Do NOT try to REMOVE the parameters!
    // Each configuration parameter has a fixed position within
    // the internal memory and CANNOT be removed.
    // Trying to do so, would result in a runtime error:
    // *** glibc detected *** double free or corruption (fasttop)
    // because the internal memory is already freed below.

    // Deallocate internal memory.
    deallocate_array(p0, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
}

/* INTERNAL_MEMORY_DEALLOCATOR_SOURCE */
#endif
