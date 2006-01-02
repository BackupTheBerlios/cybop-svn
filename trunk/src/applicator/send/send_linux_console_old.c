/*
 * $RCSfile: send_linux_console_old.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
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
#include "../../memoriser/converter.c"
#include "../../memoriser/translator.c"

/**
 * Sends a textual user interface (tui) via linux console.
 *
 * @param p0 the internal memory
 * @param p1 the source tui compound model
 * @param p2 the source count
 */
/*??
void send_linux_console(void* p0, void* p1, void* p2) {

    log_message_debug("Send linux console message.");

    // The tui internal.
    void** tp = &NULL_POINTER;
    int** tcp = (int**) &NULL_POINTER;
    int** tsp = (int**) &NULL_POINTER;
    // The tui.
    void* t = NULL_POINTER;
    void* tc = NULL_POINTER;
    void* ts = NULL_POINTER;

    // Get tui internal.
    get(p0, (void*) TUI_INTERNAL, (void*) &tp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TUI_COUNT_INTERNAL, (void*) &tcp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TUI_SIZE_INTERNAL, (void*) &tsp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*tp != NULL_POINTER) {

        // Reinitialise tui with already existing tui internal.
        t = *tp;
        tc = *tcp;
        ts = *tsp;

    } else {

        // The tui internal tp is null, so that a new tui t needs to be created.

        // The count and size z, y, x coordinates.
        int* tcz = NULL_POINTER;
        int* tcy = NULL_POINTER;
        int* tcx = NULL_POINTER;
        int* tsz = NULL_POINTER;
        int* tsy = NULL_POINTER;
        int* tsx = NULL_POINTER;

        // Allocate count and size z, y, x coordinates.
        allocate((void*) &tcz, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tcy, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tcx, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tsz, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tsy, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tsx, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Initialise count and size z, y, x coordinates.
        set(tcz, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tcy, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tcx, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tsz, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tsy, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tsx, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Allocate tui count and size.
        allocate((void*) &tc, (void*) TUI_COUNT, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &ts, (void*) TUI_COUNT, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Initialise tui count and size.
        set(tc, (void*) TUI_Z_DIMENSION_INDEX, (void*) &tcz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(tc, (void*) TUI_Y_DIMENSION_INDEX, (void*) &tcy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(tc, (void*) TUI_X_DIMENSION_INDEX, (void*) &tcx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_Z_DIMENSION_INDEX, (void*) &tsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_Y_DIMENSION_INDEX, (void*) &tsy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_X_DIMENSION_INDEX, (void*) &tsx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Allocate tui.
        allocate((void*) &t, (void*) tsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Set tui internals.
        // The tui is stored in internal memory for faster access,
        // so that it does not have to be created every time again.
        set(p0, (void*) TUI_INTERNAL, (void*) &t, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TUI_COUNT_INTERNAL, (void*) &tc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TUI_SIZE_INTERNAL, (void*) &ts, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    }

    // Encode compound model into tui.
    encode((void*) &t, (void*) tc, (void*) ts, p1, p2, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT);

    // The serialised string array to be sent to the terminal.
    void* a = NULL_POINTER;
    int ac = 0;
    int as = 0;

    // Create array.
    allocate((void*) &a, (void*) &as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Serialise multi-dimensional tui into array.
    serialise((void*) &a, (void*) &ac, (void*) &as, t, (void*) tc, (void*) TERMINAL_ABSTRACTION, (void*) TERMINAL_ABSTRACTION_COUNT);

    // CAUTION! The textual user interface (tui) AND ALL ITS CONTENT
    // need to be deallocated at system shutdown!

    // The terminal (device name).
    void** term = &NULL_POINTER;

    // Get terminal.
    get_array_elements(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &term, (void*) POINTER_ARRAY);

    // Write serialised array as message to terminal.
    write_data(term, NULL_POINTER, NULL_POINTER, a, (void*) &ac, (void*) TERMINAL_CHANNEL, (void*) TERMINAL_CHANNEL_COUNT);

    // Destroy array.
    deallocate((void*) &a, (void*) &as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}
*/

/* SEND_LINUX_CONSOLE_SOURCE */
#endif
