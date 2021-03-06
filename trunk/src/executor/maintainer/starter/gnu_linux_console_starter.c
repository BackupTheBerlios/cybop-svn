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
 * @version $RCSfile: gnu_linux_console_starting_maintainer.c,v $ $Revision: 1.11 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_STARTER_SOURCE
#define GNU_LINUX_CONSOLE_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/terminal_type_size.c"

/**
 * Starts up the gnu/linux console.
 *
 * @param p0 the internal memory array
 */
void startup_gnu_linux_console(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup gnu/linux console.");

    // The gnu/linux console input- and output stream.
    FILE* ip = (FILE*) *NULL_POINTER_MEMORY_MODEL;
    FILE* op = (FILE*) *NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console input- and output stream.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME);

    // Only create new gnu/linux console resources if both,
    // input- AND output stream internal are null.
    if ((ip == *NULL_POINTER_MEMORY_MODEL) && (op == *NULL_POINTER_MEMORY_MODEL)) {

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
        //
        // CAUTION! An allocation is NOT necessary, as long as
        // the standard input- and output streams are used below.
        allocate((void*) &ip, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
        allocate((void*) &op, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
*/
        // Allocate termios settings.
        to = (struct termios*) malloc(*INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);
        tn = (struct termios*) malloc(*INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);
        // Allocate character buffer count, size.
        allocate_model((void*) &bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
        allocate_model((void*) &bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        // Initialise character buffer count, size.
        //
        // CAUTION! Its size is initialised with three,
        // because longer escape sequences are not known.
        // Example: An up arrow delivers 'ESC' + '[' + 'A'
        copy_integer(bc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        copy_integer(bs, (void*) NUMBER_3_INTEGER_MEMORY_MODEL);

        // Allocate character buffer.
        allocate_model((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

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
        copy_array_forward(p0, (void*) &ip, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(p0, (void*) &op, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(p0, (void*) &to, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(p0, (void*) &tn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        // Set character buffer.
        copy_array_forward(p0, (void*) &b, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(p0, (void*) &bc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(p0, (void*) &bs, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup gnu/linux console. The gnu/linux console input or output or both are already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GNU_LINUX_CONSOLE_STARTER_SOURCE */
#endif
