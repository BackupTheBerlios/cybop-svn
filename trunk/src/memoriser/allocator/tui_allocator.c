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
 * @version $Revision: 1.7 $ $Date: 2005-07-28 12:52:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TUI_ALLOCATOR_SOURCE
#define TUI_ALLOCATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the textual user interface (tui).
 *
 * @param p0 the textual user interface (Hand over as reference!)
 * @param p1 the textual user interface size
 */
void allocate_tui(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        void** ts = (void**) p1;

        if (p0 != NULL_POINTER) {

            void** t = (void**) p0;

            log_message_debug("Allocate textual user interface.");

/*??
            // The z-, y-, x-dimension and properties.
            // The z dimension is the actual tui, represented by the p0 parameter.
            void* yd = NULL_POINTER;
            void* xd = NULL_POINTER;
            void* pd = NULL_POINTER;

            // Allocate z-, y-, x-dimension and properties.
            // CAUTION! The properties must be first, then x-, y-, z-dimension.
            allocate_array(p0, p1, (void*) POINTER_ARRAY);

            // The panels.
            void* p = NULL_POINTER;

            // Create panels.
            allocate_array((void*) &p, p1, (void*) POINTER_ARRAY);

            // Set panels.
            // The p0 parameter needs to be dereferenced since it is handed over
            // as reference, but this procedure expects a normal array.
            set_array_elements(*t, (void*) TUI_PANELS_INDEX, (void*) &p, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
*/

        } else {

            log_message_debug("Could not allocate textual user interface. The textual user interface parameter is null.");
        }

    } else {

        log_message_debug("Could not allocate textual user interface. The textual user interface size parameter is null.");
    }
}

/**
 * Deallocates the textual user interface (tui).
 *
 * @param p0 the textual user interface (Hand over as reference!)
 * @param p1 the textual user interface size
 */
void deallocate_tui(void* p0, void* p1) {

    if (p0 != NULL_POINTER) {

        void** t = (void**) p0;

        log_message_debug("Deallocate textual user interface.");

/*??
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
        deallocate_array(p0, p1, (void*) POINTER_ARRAY);
*/

    } else {

        log_message_debug("Could not deallocate textual user interface. The textual user interface parameter is null.");
    }
}

/* TUI_ALLOCATOR_SOURCE */
#endif
