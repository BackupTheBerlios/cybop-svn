/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: gnu_linux_console_receiving_communicator.c,v $ $Revision: 1.5 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_RECEIVER_SOURCE
#define GNU_LINUX_CONSOLE_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../../constant/model/log/level_log_model.c"
#include "../../../logger/logger.c"

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

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive gnu/linux console message.");

    // The character array read from the gnu/linux console.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int ac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int as = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate character array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST receive pre read: %i\n", ac);

    // Read pressed keyboard keys as message from gnu/linux console.
    read_gnu_linux_console((void*) &a, (void*) &ac, (void*) &as, p12);

    fwprintf(stderr, L"TEST a: %s\n", (wchar_t*) a);
    fwprintf(stderr, L"TEST ac: %i\n", ac);
    fwprintf(stderr, L"TEST as: %i\n", as);

    // Decode character array into command.
    decode(p6, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, a, (void*) &ac, p15, p16, (void*) GNU_LINUX_CONSOLE_INTERFACE_CYBOL_ABSTRACTION, (void*) GNU_LINUX_CONSOLE_INTERFACE_CYBOL_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST m: %s\n", *((wchar_t**) p6));
    fwprintf(stderr, L"TEST mc: %i\n", *((int*) p7));
    fwprintf(stderr, L"TEST ms: %i\n", *((int*) p8));

    // Deallocate character array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_RECEIVER_SOURCE */
#endif