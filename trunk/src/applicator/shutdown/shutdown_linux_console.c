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
 * @version $Revision: 1.3 $ $Date: 2005-07-14 17:41:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_LINUX_CONSOLE_SOURCE
#define SHUTDOWN_LINUX_CONSOLE_SOURCE

#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/creator/integer_creator.c"
#include "../../memoriser/creator/unsigned_long_creator.c"

/**
 * Shuts down the linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void shutdown_linux_console(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Shutdown linux console.");

    // The terminal (device name) internal.
    int** t = NULL_POINTER;

    // Get terminal internal.
    get_array_elements(p0, (void*) LINUX_CONSOLE_TERMINAL_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    if (*t != NULL_POINTER) {

        // Destroy linux console internals.
        // CAUTION! Use descending order, as opposed to the creation!
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
        destroy_integer((void*) t);

    } else {

        log_message_debug("WARNING: Could not shutdown linux console. There is no linux console running.");
    }
}

/* SHUTDOWN_LINUX_CONSOLE_SOURCE */
#endif
