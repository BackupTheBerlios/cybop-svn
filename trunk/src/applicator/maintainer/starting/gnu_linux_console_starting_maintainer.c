/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: gnu_linux_console_starting_maintainer.c,v $ $Revision: 1.11 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_STARTING_MAINTAINER_SOURCE
#define GNU_LINUX_CONSOLE_STARTING_MAINTAINER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/thread_identification.c"

/**
 * Starts up the gnu/linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void maintain_starting_gnu_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup gnu/linux console.");

    // The gnu/linux console input- and output stream internal.
    FILE** ipi = (FILE**) NULL_POINTER_MEMORY_MODEL;
    FILE** opi = (FILE**) NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console internals.
    get((void*) &ipi, p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    get((void*) &opi, p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // Only create new gnu/linux console resources if both,
    // input- AND output stream internal are null.
    if ((*ipi == *NULL_POINTER_MEMORY_MODEL) && (*opi == *NULL_POINTER_MEMORY_MODEL)) {

        // The gnu/linux console input- and output stream.
        FILE* ip = (FILE*) *NULL_POINTER_MEMORY_MODEL;
        FILE* op = (FILE*) *NULL_POINTER_MEMORY_MODEL;
        // The old termios settings.
        struct termios* to = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
        // The new termios settings.
        struct termios* tn = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
        // The character buffer used for input in the thread function.
        void* b = *NULL_POINTER_MEMORY_MODEL;
        void* bc = *NULL_POINTER_MEMORY_MODEL;
        void* bs = *NULL_POINTER_MEMORY_MODEL;

/*??
        // Allocate input- and output stream.
        allocate((void*) &ip, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &op, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
*/
        // Allocate termios settings.
        to = (struct termios*) malloc(sizeof(struct termios));
        tn = (struct termios*) malloc(sizeof(struct termios));

        // Allocate character buffer.
        //
        // CAUTION! Its size is initialised with three,
        // because longer escape sequences are not known.
        // Example: An up arrow delivers 'ESC' + '[' + 'A'
        allocate_model((void*) &b, (void*) &bc, (void*) &bs, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

        // Initialise gnu/linux console internals.
        //
        // CAUTION! The standard input- and output streams are used for now.
        ip = stdin;
        op = stdout;

        // Get file descriptor for file stream.
        // CAUTION! The stream "stdin" must be used instead of "stdout" here!
        int d = fileno(ip);

        // Store old termios settings.
        int e = tcgetattr(d, (void*) to);

        if (e != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

            // Initialise new termios settings.
            *tn = *to;

            //
            // Manipulate termios attributes.
            //
            // A good documentation of possible flags may be found at:
            // http://www.unixguide.net/unix/programming/3.6.2.shtml
            //
            // c_iflag: always needed, only not if using software flow control (ick)
            // c_oflag: mostly hacks to make output to slow terminals work,
            //          newer systems have dropped almost all of them as obsolete
            // c_cflag: set character size, generate even parity, enabling hardware flow control
            // c_lflag: most applications will probably want to turn off ICANON
            //          (canonical, i.e. line-based, input processing), ECHO and ISIG
            // c_cc: an array of characters that have special meanings on input;
            //       these characters are given names like VINTR, VSTOP etc.
            //       the names are indexes into the array
            //       two of these "characters" are not really characters at all,
            //       but control the behaviour of read() when ICANON is disabled;
            //       these are VMIN and VTIME
            //
            // VTIME: the time to wait before read() will return;
            //        its value is (if not 0) always interpreted as a timer in tenths of seconds
            // VMIN: the number of bytes of input to be available, before read() will return
            //

            // Turn off.
            tn->c_lflag &= ~ICANON;
            // Turn off echo.
            tn->c_lflag &= ~ECHO;
            // Set number of input characters to be available, before read() will return.
            // CAUTION! This value HAS TO BE set to zero, so that one key press such as ESCAPE
            // gets processed right away (e.g. to exit an application), without waiting for
            // yet another character input.
            tn->c_cc[VMIN] = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Set time to wait before read() will return.
            tn->c_cc[VTIME] = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Set new termios attributes.
            tcsetattr(d, TCSANOW, (void*) tn);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. The termios settings could not be stored.\n");

            if (errno == EBADF) {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. The filedes argument is not a valid file descriptor.\n");

            } else if (errno == ENOTTY) {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. The filedes is not associated with a terminal.\n");

            } else {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. An unknown error occured.\n");
            }
        }

/*??
        // Check for gnu/linux console.
        int l = strcmp("linux", getenv("TERM"));

        if (l == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"This is a gnu/linux console.");

        } else {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"This is a standard serial terminal.");
        }
*/

        // Set gnu/linux console internals.
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &ip, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &op, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &to, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &tn, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        // Set character buffer.
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &b, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        set(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) &bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. The gnu/linux console input or output or both are already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_STARTING_MAINTAINER_SOURCE */
#endif
