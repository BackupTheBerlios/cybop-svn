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
 * @version $Revision: 1.4 $ $Date: 2005-07-15 12:14:40 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_LINUX_CONSOLE_SOURCE
#define STARTUP_LINUX_CONSOLE_SOURCE

#include <sys/ioctl.h>
#include <sys/vt.h>
//?? #include <sys/stat.h>
//?? #include <sys/types.h>
//?? #include <sys/wait.h>
//?? #include <stdio.h>
//?? #include <unistd.h>
//?? #include <stdlib.h>
//?? #include <signal.h>
#include <fcntl.h>
#include "../../memoriser/creator/integer_creator.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"

/**
 * Starts up the linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void startup_linux_console(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Startup linux console.");

    // The terminal (device name) internal.
    int** ti = NULL_POINTER;

    // Get terminal internal.
    get_array_elements(p0, (void*) LINUX_CONSOLE_TERMINAL_INTERNAL, (void*) &ti, (void*) POINTER_ARRAY);

    if (*ti == NULL_POINTER) {

        // The terminal (device name).
        int* t = NULL_POINTER;

        // Create linux console internals.
        create_integer((void*) &t);

        // Check for linux console.
        int l = strcmp("linux", getenv("TERM"));

        if (l == 0) {

            log_message_debug("TEST: This is a linux console.");

        } else {

            log_message_debug("TEST: This is a standard serial terminal.");
        }

        // Open virtual console.
//??        *t = ttyname();
        *t = open("/dev/tty", O_RDWR, 0);

        if (*t >= 0) {

            // Check for virtual console.
            struct vt_stat vtstat;
            int v = ioctl(*t, VT_GETSTATE, &vtstat);

            if (v >= 0) {

                // Check for free virtual console.
                int vtnum;
                int f = ioctl(*t, VT_OPENQRY, &vtnum);

                if (f >= 0) {

/*??
                    // The device name.
                    char* d = create_array...
                    sprintf(d, ());
*/

                } else {

                    log_message_debug("ERROR: Could not startup linux console. There are no free virtual consoles.");
                }

            } else {

                log_message_debug("ERROR: Could not startup linux console. The tty device is not a virtual console.");
            }

        } else {

            log_message_debug("ERROR: Could not startup linux console. The virtual terminal could not be opened.");
        }

        fprintf(stdout, "TEST: The terminal device name is: %i\n", *t);

        // Set linux console internals.
        set_array_elements(p0, (void*) LINUX_CONSOLE_TERMINAL_INTERNAL, (void*) &t, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("WARNING: Could not startup linux console. The linux console is already running.");
    }
}

/* STARTUP_LINUX_CONSOLE_SOURCE */
#endif
