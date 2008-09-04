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
 * @version $RCSfile: gnu_linux_console_shutting_maintainer.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_SHUTTER_SOURCE
#define GNU_LINUX_CONSOLE_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <termios.h>
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"
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

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Shutdown gnu/linux console.");

    // The gnu/linux console input- and output stream internal.
    FILE** ipi = (FILE**) NULL_POINTER_MEMORY_MODEL;
    FILE** opi = (FILE**) NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console internals.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ipi, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &opi, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Only deallocate gnu/linux console resources if at least one,
    // the input- OR output stream internal is null.
    if ((*ipi != *NULL_POINTER_MEMORY_MODEL) || (opi == *NULL_POINTER_MEMORY_MODEL)) {

        // Interrupt gnu/linux console service thread.
        interrupt_thread(p1, p2);

        // The gnu/linux console input- and output stream.
        FILE** ip = (FILE**) NULL_POINTER_MEMORY_MODEL;
        FILE** op = (FILE**) NULL_POINTER_MEMORY_MODEL;
        // The original termios interface.
        struct termios** to = (struct termios**) NULL_POINTER_MEMORY_MODEL;
        // The working termios interface.
        struct termios** tw = (struct termios**) NULL_POINTER_MEMORY_MODEL;
        // The character buffer that was used in the thread procedure.
        void** b = NULL_POINTER_MEMORY_MODEL;
        void** bc = NULL_POINTER_MEMORY_MODEL;
        void** bs = NULL_POINTER_MEMORY_MODEL;

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
        //?? deallocate((void*) t, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        free(*tw);
        free(*to);

        // Deallocate character buffer.
        deallocate((void*) b, *bs, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        // Deallocate character buffer count, size.
        deallocate((void*) bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not shutdown gnu/linux console. There is no gnu/linux console running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_SHUTTER_SOURCE */
#endif
