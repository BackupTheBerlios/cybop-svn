/*
 * $RCSfile: receive_gnu_linux_console.c,v $
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
 * @version $Revision: 1.9 $ $Date: 2008-02-15 15:47:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_GNU_LINUX_CONSOLE_SOURCE
#define RECEIVE_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/logger/logger.c"
/*??
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/wide_character_constants.c"
#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
*/

/**
 * Receives textual user interface (tui) message via gnu/linux console.
 *
 * @param p0 the signal name (Hand over as reference!)
 * @param p1 the signal name count (Hand over as reference!)
 * @param p2 the signal name size (Hand over as reference!)
 * @param p3 the signal abstraction (Hand over as reference!)
 * @param p4 the signal abstraction count (Hand over as reference!)
 * @param p5 the signal abstraction size (Hand over as reference!)
 * @param p6 the signal model (Hand over as reference!)
 * @param p7 the signal model count (Hand over as reference!)
 * @param p8 the signal model size (Hand over as reference!)
 * @param p9 the signal details (Hand over as reference!)
 * @param p10 the signal details count (Hand over as reference!)
 * @param p11 the signal details size (Hand over as reference!)
 * @param p12 the gnu/linux console input stream
 */
void receive_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Receive gnu/linux console message.");

    // The character array read from the gnu/linux console (terminal).
    void* a = *NULL_POINTER;
    int ac = *NUMBER_0_INTEGER;
    int as = *NUMBER_0_INTEGER;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Read pressed keyboard keys as message from gnu/linux console.
    read_gnu_linux_console((void*) &a, (void*) &ac, (void*) &as, p12);

/*??
    // Decode character array into signal.
    decode_gnu_linux_console(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, (void*) &a, (void*) &ac);
*/

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_GNU_LINUX_CONSOLE_SOURCE */
#endif
