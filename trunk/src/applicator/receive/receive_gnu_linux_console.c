/*
 * $RCSfile: receive_gnu_linux_console.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.17 $ $Date: 2008-05-04 00:18:10 $ $Author: christian $
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
 * @param p0 the command name (Hand over as reference!)
 * @param p1 the command name count (Hand over as reference!)
 * @param p2 the command name size (Hand over as reference!)
 * @param p3 the command abstraction (Hand over as reference!)
 * @param p4 the command abstraction count (Hand over as reference!)
 * @param p5 the command abstraction size (Hand over as reference!)
 * @param p6 the command model (Hand over as reference!)
 * @param p7 the command model count (Hand over as reference!)
 * @param p8 the command model size (Hand over as reference!)
 * @param p9 the command details (Hand over as reference!)
 * @param p10 the command details count (Hand over as reference!)
 * @param p11 the command details size (Hand over as reference!)
 * @param p12 the gnu/linux console input stream
 * @param p13 the commands
 * @param p14 the commands count
 * @param p15 the knowledge memory
 * @param p16 the knowledge memory count
 */
void receive_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Receive gnu/linux console message.");

    // The character array read from the gnu/linux console.
    void* a = *NULL_POINTER;
    int ac = *NUMBER_0_INTEGER;
    int as = *NUMBER_0_INTEGER;

    // Allocate character array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST receive pre read: %i\n", ac);

    // Read pressed keyboard keys as message from gnu/linux console.
    read_gnu_linux_console((void*) &a, (void*) &ac, (void*) &as, p12);

    fwprintf(stderr, L"TEST a: %s\n", (char*) a);
    fwprintf(stderr, L"TEST ac: %i\n", ac);
    fwprintf(stderr, L"TEST as: %i\n", as);

    // Decode character array into command.
    decode(p6, p7, p8, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, a, (void*) &ac, p15, p16, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT);

    fwprintf(stderr, L"TEST m: %s\n", *((char**) p6));
    fwprintf(stderr, L"TEST mc: %i\n", *((int*) p7));
    fwprintf(stderr, L"TEST ms: %i\n", *((int*) p8));

    // Deallocate character array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_GNU_LINUX_CONSOLE_SOURCE */
#endif
