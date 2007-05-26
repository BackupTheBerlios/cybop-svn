/*
 * $RCSfile: initial_signal_manager.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIAL_SIGNAL_MANAGER_SOURCE
#define INITIAL_SIGNAL_MANAGER_SOURCE

#include "../../applicator/receive/receive_file_system.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/constants/cyboi_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Starts up the initial signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 */
void startup_initial_signal(void* p0, void* p1, void* p2) {

    log_message_debug("\n\n");
    log_message_debug("Information: Startup initial signal.");

    // The initial signal abstraction.
    void* a = *NULL_POINTER;
    int* ac = (int*) *NULL_POINTER;
    int* as = (int*) *NULL_POINTER;
    // The initial signal model.
    void* m = *NULL_POINTER;
    int* mc = (int*) *NULL_POINTER;
    int* ms = (int*) *NULL_POINTER;
    // The initial signal details.
    void* d = *NULL_POINTER;
    int* dc = (int*) *NULL_POINTER;
    int* ds = (int*) *NULL_POINTER;

    // Allocate initial signal abstraction, model.
    allocate((void*) &ac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // CAUTION! Do not allocate initial signal details!
    // It is not needed for the initial signal.

    // Initialise initial signal abstraction, model.
    *ac = *NUMBER_0_INTEGER;
    *as = *NUMBER_0_INTEGER;
    *mc = *NUMBER_0_INTEGER;
    *ms = *NUMBER_0_INTEGER;
    // CAUTION! Do not initialise initial signal details!
    // It is not needed for the initial signal.

    // Allocate and initialise initial signal abstraction.
    receive_file_system_model((void*) &a, (void*) ac, (void*) as,
        *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
        (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
        (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
    // Allocate and initialise initial signal model.
    receive_file_system_model((void*) &m, (void*) mc, (void*) ms,
        *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        p0, p1,
        COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT,
        FILE_CHANNEL, FILE_CHANNEL_COUNT);
    // CAUTION! Do not allocate and initialise initial signal details!
    // It is not needed for the initial signal.

    log_message_debug("\n\n");
    log_message_debug("Info: Add initial signal to signal memory.");

    // The signal id.
    int* id = (int*) *NULL_POINTER;
    allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *id = *NUMBER_0_INTEGER;
    get_new_signal_id(p0, p1, (void*) id);

    // Add initial signal to signal memory.
    set_signal(p0, p1, p2, a, (void*) ac, m, (void*) mc, d, (void*) dc, (void*) NORMAL_PRIORITY, (void*) id);
}

/* INITIAL_SIGNAL_MANAGER_SOURCE */
#endif
