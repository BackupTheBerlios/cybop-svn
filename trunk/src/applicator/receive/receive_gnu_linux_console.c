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
 * @version $Revision: 1.11 $ $Date: 2008-03-30 10:49:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_GNU_LINUX_CONSOLE_SOURCE
#define RECEIVE_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/logger/logger.c"

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

    // The character array read from the gnu/linux console.
    void* a = *NULL_POINTER;
    int ac = *NUMBER_0_INTEGER;
    int as = *NUMBER_0_INTEGER;

    // Allocate character array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Read pressed keyboard keys as message from gnu/linux console.
    read_gnu_linux_console((void*) &a, (void*) &ac, (void*) &as, p12);

    fprintf(stderr, "TEST a: %s\n", (char*) a);
    fprintf(stderr, "TEST ac: %i\n", ac);
    fprintf(stderr, "TEST as: %i\n", as);

    // The command.
    void* c = *NULL_POINTER;
    int cc = *NUMBER_0_INTEGER;
    int cs = *NUMBER_0_INTEGER;

    // Allocate command.
    allocate((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Decode character array into command.
    decode_gnu_linux_console((void*) &c, (void*) &cc, (void*) &cs, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, a, (void*) &ac, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT);

    // Deallocate character array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

/*??
    // The user interface commands.
    void** c = NULL_POINTER;
    void** cc = NULL_POINTER;
    void** cs = NULL_POINTER;

    // Get user interface commands internal.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Get actual command belonging to the command name.
    // If the name is not known, the command parameter is left untouched.
    get_universal_compound_element_by_name(*c, *cc,
        p13, p14,
        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11,
        *k, *kc);
*/

    // Deallocate command.
    deallocate((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_GNU_LINUX_CONSOLE_SOURCE */
#endif
