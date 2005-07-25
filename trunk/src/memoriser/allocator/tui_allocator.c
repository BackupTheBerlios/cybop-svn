/*
 * $RCSfile: tui_allocator.c,v $
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
 * This file contains the functionality to:
 * - create a signal memory in memory
 *
 * @version $Revision: 1.3 $ $Date: 2005-07-25 20:27:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TUI_CREATOR_SOURCE
#define TUI_CREATOR_SOURCE

//?? #include "../../globals/constants/integer_constants.c"
//?? #include "../../globals/constants/log_constants.c"
//?? #include "../../globals/constants/structure_constants.c"
//?? #include "../../globals/logger/logger.c"
//?? #include "../../memoriser/array.c"

/**
 * Creates the textual user interface dimension.
 *
 * @param p0 the textual user interface (Hand over as reference!)
 * @param p1 the textual user interface size
 */
void allocate_tui(void* p0, const void* p1) {

/*??
    if (p0 != NULL_POINTER) {

        void** t = (void**) p0;

        log_message_debug("Create textual user interface.");

        // Create textual user interface.
        allocate_array(p0, (void*) TUI_COUNT, (void*) POINTER_ARRAY);

        // The panels.
        void* p = NULL_POINTER;

        // Create panels.
        allocate_array((void*) &p, p1, (void*) POINTER_ARRAY);

        // Set panels.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        set_array_elements(*t, (void*) TUI_PANELS_INDEX, (void*) &p, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("Could not create textual user interface. The textual user interface parameter is null.");
    }
*/
}

/**
 * Destroys the textual user interface.
 *
 * @param p0 the textual user interface (Hand over as reference!)
 * @param p1 the textual user interface size
 */
void deallocate_tui(void* p0, const void* p1) {

/*??
    if (p0 != NULL_POINTER) {

        void** t = (void**) p0;

        log_message_debug("Destroy textual user interface.");

        // The panels.
        void* p = NULL_POINTER;

        // Get panels.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        get_array_elements(*t, (void*) TUI_PANELS_INDEX, (void*) &p, (void*) POINTER_ARRAY);

        // Remove panels.
        // CAUTION! Use descending order as compared to creation, for faster removal.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        remove_array_elements(*t, (void*) TUI_COUNT, (void*) TUI_PANELS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

        // Destroy panels.
        // CAUTION! Do NOT hand over as reference!
        // The variables are of type void**.
        // The expression (&*variable) is the same like (variable).
        deallocate_array((void*) p, p1, (void*) POINTER_ARRAY);

        // Destroy signal memory.
        deallocate_array(p0, (void*) TUI_COUNT, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("Could not destroy textual user interface. The textual user interface parameter is null.");
    }
*/
}

/* TUI_CREATOR_SOURCE */
#endif
