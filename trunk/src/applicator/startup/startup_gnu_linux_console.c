/*
 * $RCSfile: startup_gnu_linux_console.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-06-24 15:02:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_GNU_LINUX_CONSOLE_SOURCE
#define STARTUP_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/variables.c"
#include "../../globals/logger/logger.c"
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

    log_message_debug("Startup gnu/linux console.");

    // The gnu/linux console input- and output stream internal.
    FILE** ipi = (FILE**) NULL_POINTER;
    FILE** opi = (FILE**) NULL_POINTER;

    // Get gnu/linux console internals.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ipi, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &opi, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Only create new gnu/linux console resources if both,
    // input- AND output stream internal are null.
    if ((*ipi == *NULL_POINTER) && (*opi == *NULL_POINTER)) {

        // The gnu/linux console input- and output stream.
        FILE* ip = (FILE*) *NULL_POINTER;
        FILE* op = (FILE*) *NULL_POINTER;
        // The original termios interface.
        struct termios* to = (struct termios*) *NULL_POINTER;
        // The working termios interface.
        struct termios* tw = (struct termios*) *NULL_POINTER;
        // The character buffer used for input in the thread procedure.
        void* b = *NULL_POINTER;
        int* bc = (int*) *NULL_POINTER;
        int* bs = (int*) *NULL_POINTER;

        // Create gnu/linux console internals.
//??        allocate((void*) &ip, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
//??        allocate((void*) &op, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        to = (struct termios*) malloc(sizeof(struct termios));
        tw = (struct termios*) malloc(sizeof(struct termios));

        // Allocate character buffer count, size.
        allocate((void*) &bc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &bs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

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
        *bc = *NUMBER_0_INTEGER;
        *bs = *NUMBER_3_INTEGER;

        // Allocate character buffer.
        allocate((void*) &b, (void*) bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Check for gnu/linux console.
        int l = strcmp("linux", getenv("TERM"));

        if (l == *NUMBER_0_INTEGER) {

            log_message_debug("Debug: This is a gnu/linux console.");

        } else {

            log_message_debug("Debug: This is a standard serial terminal.");
        }

        // Set gnu/linux console internals.
        set_element(p0, (void*) GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &ip, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL, (void*) &op, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL, (void*) &to, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL, (void*) &tw, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set_element(p0, (void*) GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("WARNING: Could not startup gnu/linux console. The gnu/linux console input or output or both are already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* STARTUP_GNU_LINUX_CONSOLE_SOURCE */
#endif