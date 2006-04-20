/*
 * $RCSfile: shutdown_linux_console.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.13 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_LINUX_CONSOLE_SOURCE
#define SHUTDOWN_LINUX_CONSOLE_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <termios.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../globals/logger/logger.c"
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
    FILE** ti = (FILE**) &NULL_POINTER;

    // Get terminal internal.
    get(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &ti, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*ti != NULL_POINTER) {

        // Interrupt receive signal thread.
        interrupt_linux_console();

        // The terminal (device name).
        FILE** t = (FILE**) &NULL_POINTER;
        // The original termios interface.
        struct termios** to = (struct termios**) &NULL_POINTER;
        // The working termios interface.
        struct termios** tw = (struct termios**) &NULL_POINTER;

        // Get terminal internals.
        get(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) TERMINAL_ORIGINAL_ATTRIBUTES_INTERNAL, (void*) &to, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) TERMINAL_WORKING_ATTRIBUTES_INTERNAL, (void*) &tw, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get file descriptor for file stream.
        int d = fileno(*t);
        // Reset original terminal attributes.
        tcsetattr(d, TCSANOW, *to);

        // Destroy terminal internals.
        // CAUTION! Use descending order, as opposed to the creation!
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
//?? DO NOT deallocate t because it refers to stdout of the system for testing!
//??        deallocate((void*) t, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        free(*tw);
        free(*to);

    } else {

        log_message_debug("WARNING: Could not shutdown linux console. There is no linux console running.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* SHUTDOWN_LINUX_CONSOLE_SOURCE */
#endif
