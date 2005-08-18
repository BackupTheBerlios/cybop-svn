/*
 * $RCSfile: receive_linux_console.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-08-18 22:30:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_LINUX_CONSOLE_SOURCE
#define RECEIVE_LINUX_CONSOLE_SOURCE

//?? #include <stdio.h>
//?? #include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
//?? #include "../../globals/constants/boolean_constants.c"
//?? #include "../../globals/constants/channel_constants.c"
//?? #include "../../globals/constants/character_constants.c"
//?? #include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
//?? #include "../../memoriser/accessor.c"
//?? #include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
//?? #include "../../memoriser/converter.c"
//?? #include "../../memoriser/translator.c"

//?? TEST
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/constant.c"

/**
 * Receives a textual user interface (tui) via linux console.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 */
void receive_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The terminal (device name).
    void** t = &NULL_POINTER;

    // Get terminal.
    get_array_elements(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    // The character.
    char c = *NULL_CONTROL_CHARACTER;

    // Get character from stream.
    c = fgetc(stdin);

    //?? Identify currently active (top-most) tui window,
    //?? which is set as pointer in the internal memory.

    //?? Determine the command (signal) corresponding to the typed key.
    //?? The key-command mapping has to be given by the CYBOL application,
    //?? as mapping knowledge model.

    if (c == 'b') {

        // The signal id.
        int* id = NULL_POINTER;
        allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *id = 0;
        get_new_signal_id(p4, p5, (void*) id);

        // Add signal to signal memory.
        set_signal(p4, p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) "resmedicinae/logic/shutdown.cybol", (void*) NUMBER_33_INTEGER, NULL_POINTER, NULL_POINTER, (void*) NORMAL_PRIORITY, (void*) id);
//??        set_signal(p4, p5, p6, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) "exit", (void*) NUMBER_4_INTEGER, NULL_POINTER, NULL_POINTER, (void*) NORMAL_PRIORITY, (void*) id);

    fprintf(stderr, "TEST in: %i\n", *t);
    }

    fprintf(stderr, "TEST out: %i\n", *t);
}

/* RECEIVE_LINUX_CONSOLE_SOURCE */
#endif
