/*
 * $RCSfile: startup_linux_console.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.13 $ $Date: 2005-08-09 13:04:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_LINUX_CONSOLE_SOURCE
#define STARTUP_LINUX_CONSOLE_SOURCE

//?? #include <sys/ioctl.h>
//?? #include <sys/vt.h>
//?? #include <sys/stat.h>
//?? #include <sys/types.h>
//?? #include <sys/wait.h>
//?? #include <unistd.h>
//?? #include <stdlib.h>
//?? #include <signal.h>
//?? #include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/allocator.c"

/**
 * Starts up the linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void startup_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Startup linux console.");

    // The terminal (device name) internal.
    FILE** ti = NULL_POINTER;

    // Get terminal internal.
    get(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &ti, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*ti == NULL_POINTER) {

        // The terminal (device name).
        FILE* t = NULL_POINTER;
        // The original termios interface.
        struct termios* to = NULL_POINTER;
        // The working termios interface.
        struct termios* tw = NULL_POINTER;

        // Create linux console internals.
//??        allocate((void*) &t, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        to = (struct termios*) malloc(sizeof(struct termios));
        tw = (struct termios*) malloc(sizeof(struct termios));

        // Initialise linux console internals.
        // Set file stream.
        // CAUTION! Possibly, stdin must be used instead of stdout here!
        t = stdout;
        fprintf(stdout, "TEST: The terminal file stream is: %i\n", t);
        // Get file descriptor for file stream.
        int d = fileno(t);
        // Copy termios attributes from file descriptor.
        tcgetattr(d, (void*) to);
        tcgetattr(d, (void*) tw);
        // Manipulate termios attributes.
        tw->c_lflag &= ~ICANON;
        tw->c_lflag &= ~ECHO;
        // Set termios attributes.
        tcsetattr(d, TCSANOW, (void*) tw);

/*??
        // Check for linux console.
        int l = strcmp("linux", getenv("TERM"));

        if (l == 0) {

            log_message_debug("TEST: This is a linux console.");

        } else {

            log_message_debug("TEST: This is a standard serial terminal.");
        }
*/

        // Set linux console internals.
        set(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TERMINAL_ORIGINAL_ATTRIBUTES_INTERNAL, (void*) &to, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TERMINAL_WORKING_ATTRIBUTES_INTERNAL, (void*) &tw, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("WARNING: Could not startup linux console. The linux console is already running.");
    }
}

/* STARTUP_LINUX_CONSOLE_SOURCE */
#endif
