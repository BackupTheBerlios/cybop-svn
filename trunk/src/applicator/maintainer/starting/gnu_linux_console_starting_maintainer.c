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
 * @version $RCSfile: gnu_linux_console_starting_maintainer.c,v $ $Revision: 1.3 $ $Date: 2008-09-06 23:17:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_STARTER_SOURCE
#define GNU_LINUX_CONSOLE_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Starts up the gnu/linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void startup_gnu_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup gnu/linux console.");

    // The gnu/linux console input- and output stream internal.
    FILE** ipi = (FILE**) NULL_POINTER_MEMORY_MODEL;
    FILE** opi = (FILE**) NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console internals.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ipi, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &opi, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Only create new gnu/linux console resources if both,
    // input- AND output stream internal are null.
    if ((*ipi == *NULL_POINTER_MEMORY_MODEL) && (*opi == *NULL_POINTER_MEMORY_MODEL)) {

        // The gnu/linux console input- and output stream.
        FILE* ip = (FILE*) *NULL_POINTER_MEMORY_MODEL;
        FILE* op = (FILE*) *NULL_POINTER_MEMORY_MODEL;
        // The original termios interface.
        struct termios* to = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
        // The working termios interface.
        struct termios* tw = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
        // The character buffer used for input in the thread procedure.
        void* b = *NULL_POINTER_MEMORY_MODEL;
        int* bc = (int*) *NULL_POINTER_MEMORY_MODEL;
        int* bs = (int*) *NULL_POINTER_MEMORY_MODEL;

        // Create gnu/linux console internals.
//??        allocate((void*) &ip, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
//??        allocate((void*) &op, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        to = (struct termios*) malloc(sizeof(struct termios));
        tw = (struct termios*) malloc(sizeof(struct termios));

        // Allocate character buffer count, size.
        allocate((void*) &bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        // Initialise gnu/linux console internals.
        //
        // CAUTION! The standard input- and output streams are used for now.
        ip = stdin;
        op = stdout;

        // Get file descriptor for output file stream.
        int opd = fileno(op);

        // Copy termios attributes from file descriptor.
        tcgetattr(opd, to);
        tcgetattr(opd, tw);

        // Manipulate termios attributes.
        tw->c_lflag &= ~ICANON;
        tw->c_lflag &= ~ECHO;

        // Assign termios attributes.
        tcsetattr(opd, TCSANOW, tw);

        // Initialise character buffer count, size.
        //
        // CAUTION! Its size is initialised with three,
        // because longer escape sequences are not known.
        // Example: An up arrow delivers 'ESC' + '[' + 'A'
        *bc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        *bs = *NUMBER_3_INTEGER_MEMORY_MODEL;

        // Allocate character buffer.
        allocate((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        // Check for gnu/linux console.
        int l = strcmp("linux", getenv("TERM"));

        if (l == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"This is a gnu/linux console.");

        } else {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"This is a standard serial terminal.");
        }

        // Set gnu/linux console internals.
        set_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ip, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &op, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL, (void*) &to, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL, (void*) &tw, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL, (void*) &bc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL, (void*) &bs, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. The gnu/linux console input or output or both are already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_STARTER_SOURCE */
#endif
