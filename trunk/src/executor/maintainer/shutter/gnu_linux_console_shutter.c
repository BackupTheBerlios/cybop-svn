/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: gnu_linux_console_shutting_maintainer.c,v $ $Revision: 1.11 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_SHUTTER_SOURCE
#define GNU_LINUX_CONSOLE_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <termios.h>

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/thread_identification.c"

/**
 * Shuts down the gnu/linux console.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory array
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_gnu_linux_console(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Shutdown gnu/linux console.");

    // The gnu/linux console input- and output stream.
    FILE* ip = (FILE*) *NULL_POINTER_MEMORY_MODEL;
    FILE* op = (FILE*) *NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console input- and output stream.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME);

    // Only deallocate gnu/linux console resources if at least one,
    // the input- OR output stream internal is null.
    if ((ip != *NULL_POINTER_MEMORY_MODEL) && (op != *NULL_POINTER_MEMORY_MODEL)) {

        // Interrupt gnu/linux console service thread.
        interrupt_thread(p1, p2);

        // The old termios settings.
        struct termios* to = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
        // The new termios settings.
        struct termios* tn = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
        // The character buffer used for input in the thread function.
        void* b = *NULL_POINTER_MEMORY_MODEL;
        void* bc = *NULL_POINTER_MEMORY_MODEL;
        void* bs = *NULL_POINTER_MEMORY_MODEL;

        // Get gnu/linux console internals.
        copy_array_forward((void*) &ip, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME);
        copy_array_forward((void*) &op, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME);
        copy_array_forward((void*) &to, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME);
        copy_array_forward((void*) &tn, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME);
        // Get character buffer.
        copy_array_forward((void*) &b, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL_MEMORY_MEMORY_NAME);
        copy_array_forward((void*) &bc, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_MEMORY_NAME);
        copy_array_forward((void*) &bs, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_MEMORY_NAME);

        // Get file descriptor for file stream.
        // CAUTION! The stream "stdin" must be used instead of "stdout" here!
        int d = fileno(ip);

        // Reset terminal to old settings.
        tcsetattr(d, TCSANOW, (void*) to);

/*??
        // Deallocate input- and output stream.
        //
        // CAUTION! DO NOT deallocate ip and op because they refer to stdin and stdout of the system!
        // This might be changed at a (much) later point in CYBOI development.
        deallocate((void*) &ip, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate((void*) &op, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
*/
        // Deallocate termios settings.
        free(to);
        free(tn);

        // Deallocate character buffer.
        deallocate_model((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        // Deallocate character buffer count, size.
        deallocate_model((void*) &bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
        deallocate_model((void*) &bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not shutdown gnu/linux console. There is no gnu/linux console running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_SHUTTER_SOURCE */
#endif
