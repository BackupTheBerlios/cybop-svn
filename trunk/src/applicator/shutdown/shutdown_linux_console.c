/*
 * $RCSfile: shutdown_linux_console.c,v $
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
 * @version $Revision: 1.10 $ $Date: 2005-11-21 23:29:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_LINUX_CONSOLE_SOURCE
#define SHUTDOWN_LINUX_CONSOLE_SOURCE

#include <termios.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Shuts down the linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void shutdown_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Shutdown linux console.");

    // The terminal (device name) internal.
    int** t = NULL_POINTER;

    // Get terminal internal.
    get(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*t != NULL_POINTER) {

        // The terminal (device name).
        int** t = NULL_POINTER;
        // The original termios interface.
        struct termios** to = NULL_POINTER;
        // The working termios interface.
        struct termios** tw = NULL_POINTER;

        // Get terminal internals.
        get(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) TERMINAL_ORIGINAL_ATTRIBUTES_INTERNAL, (void*) &to, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) TERMINAL_WORKING_ATTRIBUTES_INTERNAL, (void*) &tw, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Finalise terminal internals.
        // Reset original terminal attributes.
        tcsetattr(**t, TCSANOW, (void*) *to);

        // Destroy terminal internals.
        // CAUTION! Use descending order, as opposed to the creation!
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
        deallocate((void*) t, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        free(*tw);
        free(*to);

    } else {

        log_message_debug("WARNING: Could not shutdown linux console. There is no linux console running.");
    }
}

/* SHUTDOWN_LINUX_CONSOLE_SOURCE */
#endif
