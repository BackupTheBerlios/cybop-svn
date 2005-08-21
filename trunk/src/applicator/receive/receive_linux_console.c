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
 * @version $Revision: 1.2 $ $Date: 2005-08-21 19:14:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_LINUX_CONSOLE_SOURCE
#define RECEIVE_LINUX_CONSOLE_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

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
 * @param p7 the commands
 * @param p8 the commands count
 */
void receive_linux_console(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8) {

    // The terminal (device name).
    void** t = &NULL_POINTER;

    // Get terminal.
    get_array_elements(p0, (void*) TERMINAL_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    // The character.
    char c = *NULL_CONTROL_CHARACTER;

    // Get character from terminal.
    c = fgetc(stdin);

    // The command abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The command model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The command details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // Get actual command belonging to the character.
    get_compound_element_by_encapsulated_name(p7, p8,
        (void*) &c, (void*) CHARACTER_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p1, p2);

    // The signal id.
    int* id = NULL_POINTER;
    allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *id = 0;
    get_new_signal_id(p4, p5, (void*) id);

    // Add signal to signal memory.
    set_signal(p4, p5, p6, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_PRIORITY, (void*) id);
}

/* RECEIVE_LINUX_CONSOLE_SOURCE */
#endif
