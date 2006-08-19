/*
 * $RCSfile: send_linux_console.c,v $
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
 * @version $Revision: 1.46 $ $Date: 2006-08-19 02:04:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_LINUX_CONSOLE_SOURCE
#define SEND_LINUX_CONSOLE_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/channel_constants.c"
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
 * @param p1 the source root abstraction
 * @param p2 the source root abstraction count
 * @param p3 the source root model (root window compound model)
 * @param p4 the source root model count
 * @param p5 the source root details (meta properties of root window compound model)
 * @param p6 the source root details count
 * @param p7 the source part name (area to be repainted)
 * @param p8 the source part name count
 * @param p9 the source clean flag
 * @param p10 the source clean flag count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void send_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_debug("Send linux console message.");

    // The serialised string array to be sent to the linux console (terminal).
    void* a = NULL_POINTER;
    int ac = 0;
    int as = 0;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    if (p9 != NULL_POINTER) {

        int* f = (int*) p9;

        if (*f != *NUMBER_0_INTEGER) {

            // Resize destination character array for erase display control sequence.
            if ((ac + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT) >= as) {

                // Set destination character array size.
                // CAUTION! Add constant in case ac is zero!
                as = ac * *WIDE_CHARACTER_VECTOR_REALLOCATE_FACTOR
                    + *ESCAPE_CONTROL_SEQUENCE_COUNT
                    + *ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT;

                // Reallocate destination character array.
                reallocate_array((void*) &a, (void*) &ac, (void*) &as, (void*) WIDE_CHARACTER_ARRAY);
            }

            // Set erase display control sequence.
            set_array_elements(a, (void*) &ac, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            ac = ac + *ESCAPE_CONTROL_SEQUENCE_COUNT;
            set_array_elements(a, (void*) &ac, (void*) ERASE_DISPLAY_CONTROL_SEQUENCE, (void*) ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            ac = ac + *ERASE_DISPLAY_CONTROL_SEQUENCE_COUNT;
        }
    }

    // Serialise textual user interface (tui) into array.
    serialise_linux_console((void*) &a, (void*) &ac, (void*) &as, p1, p2, p3, p4, p5, p6, NULL_POINTER, NULL_POINTER, p7, p8, p11, p12);

    // The linux console (terminal).
    void** t = &NULL_POINTER;

    // Get linux console.
    get_array_elements(p0, (void*) LINUX_CONSOLE_FILE_DESCRIPTOR_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    // Write serialised array as message to linux console.
    write_data(t, NULL_POINTER, NULL_POINTER, a, (void*) &ac, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/* SEND_LINUX_CONSOLE_SOURCE */
#endif
