/*
 * $RCSfile: send_linux_console.c,v $
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
 * @version $Revision: 1.37 $ $Date: 2006-01-28 00:40:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_LINUX_CONSOLE_SOURCE
#define SEND_LINUX_CONSOLE_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"

/**
 * Sends a textual user interface (tui) via linux console.
 *
 * @param p0 the internal memory
 * @param p1 the source tui compound model
 * @param p2 the source count
 */
void send_linux_console(void* p0, void* p1, void* p2) {

    log_message_debug("Send linux console message.");

    // The serialised string array to be sent to the terminal.
    void* a = NULL_POINTER;
    int ac = 0;
    int as = 0;

    fprintf(stderr, "TEST send linux console 0: %i\n", p0);

    // Create array.
    allocate((void*) &a, (void*) &as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Serialise textual user interface (tui) into array.
    serialise((void*) &a, (void*) &ac, (void*) &as, p1, p2, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT);

    // The linux console terminal.
    void** t = &NULL_POINTER;

    // Get linux console terminal.
    get_array_elements(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    // Write serialised array as message to linux console terminal.
    write_data(t, NULL_POINTER, NULL_POINTER, a, (void*) &ac, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT);

    // Destroy array.
    deallocate((void*) &a, (void*) &as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* SEND_LINUX_CONSOLE_SOURCE */
#endif
