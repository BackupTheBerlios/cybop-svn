/*
 * $RCSfile: shutdown_gnu_linux_console.c,v $
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
 * @version $Revision: 1.9 $ $Date: 2008-05-28 22:39:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_GNU_LINUX_CONSOLE_SOURCE
#define SHUTDOWN_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <termios.h>
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/thread_identification_variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Shuts down the gnu/linux console.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internals memory
 * @param p1 the socket service thread
 * @param p2 the socket service thread interrupt
 */
void shutdown_gnu_linux_console(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Shutdown gnu/linux console.");

    // The gnu/linux console input- and output stream internal.
    FILE** ipi = (FILE**) NULL_POINTER;
    FILE** opi = (FILE**) NULL_POINTER;

    // Get gnu/linux console internals.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ipi, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &opi, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Only deallocate gnu/linux console resources if at least one,
    // the input- OR output stream internal is null.
    if ((*ipi != *NULL_POINTER) || (opi == *NULL_POINTER)) {

        // Interrupt gnu/linux console service thread.
        interrupt_thread(p1, p2);

        // The gnu/linux console input- and output stream.
        FILE** ip = (FILE**) NULL_POINTER;
        FILE** op = (FILE**) NULL_POINTER;
        // The original termios interface.
        struct termios** to = (struct termios**) NULL_POINTER;
        // The working termios interface.
        struct termios** tw = (struct termios**) NULL_POINTER;
        // The character buffer that was used in the thread procedure.
        void** b = NULL_POINTER;
        void** bc = NULL_POINTER;
        void** bs = NULL_POINTER;

        // Get gnu/linux console internals.
        get_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ip, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &op, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL, (void*) &to, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL, (void*) &tw, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get character buffer.
        get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get file descriptor for output file stream.
        int opd = fileno(*op);
        // Reset original gnu/linux console attributes.
        tcsetattr(opd, TCSANOW, *to);

        // Destroy gnu/linux console internals.
        //
        // CAUTION! Use descending order, as opposed to the creation!
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
        //?? DO NOT deallocate t because it refers to stdout of the system for testing!
        //?? deallocate((void*) t, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        free(*tw);
        free(*to);

        // Deallocate character buffer.
        deallocate((void*) b, *bs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        // Deallocate character buffer count, size.
        deallocate((void*) bc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) bs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) L"Could not shutdown gnu/linux console. There is no gnu/linux console running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SHUTDOWN_GNU_LINUX_CONSOLE_SOURCE */
#endif
