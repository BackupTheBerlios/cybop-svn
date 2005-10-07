/*
 * $RCSfile: x_window_system_communicator.c,v $
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
 * - receive a file stream into a byte array
 * - send a file stream from a byte array
 *
 * @version $Revision: 1.2 $ $Date: 2005-10-07 12:20:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE
#define X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE

#include <X11/Xlib.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Reads the x window system display into a window.
 *
 * @param p0 the destination window (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source display
 * @param p4 the source count
 */
void read_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Writes the window onto the x window system display.
 *
 * @param p0 the destination display (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory
 * @param p4 the source count
 */
void write_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != NULL_POINTER) {

        struct _XDisplay** d = (struct _XDisplay**) p0;

        log_message_debug("Write to x window system display.");

        // The window.
        int** w = (int**) &NULL_POINTER;
        // The menu border bottom graphic context.
        struct _XGC** gc_menu_border_bottom = (struct _XGC**) &NULL_POINTER;

        // Get x window system internals.
        get(p3, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p3, (void*) X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL, (void*) &gc_menu_border_bottom, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST 4 comm: %i\n", **w);

        // Request input events (signals) to be put into event queue.
        XSelectInput(*d, **w, ButtonPressMask | KeyPressMask | ExposureMask);

    fprintf(stderr, "TEST 5 comm: %i\n", **w);

        // Map window.
        // This procedure changes the order of all sister windows,
        // so that the given window lies on top.
        // Afterwards, all windows are displayed on the screen.
        XMapRaised(*d, **w);

        // The window attributes.
//??        XWindowAttributes* wa = NULL_POINTER;
        XWindowAttributes wa;

        // Draw window.
        XGetWindowAttributes(*d, **w, &wa);
        //XDrawImageString(e.xexpose.display, e.xexpose.window, gc, 50, 50, "hello", strlen("hello"));
        //XRectangle(e.xexpose.display, e.xexpose.window, gc_menu, 2, 2, (wa.width-4), 30);

        // Draw menu bar.
        XDrawLine(*d, **w, *gc_menu_border_bottom, 0, 21, wa.width, 21);
        XDrawLine(*d, **w, *gc_menu_border_bottom, (wa.width-1), 1, (wa.width-1), 21);

    fprintf(stderr, "TEST 6 comm: %i\n", *d);

        //?? TODO: From xlib tutorial.
        //?? Remove as soon as event loop (MappingNotify) functions!
//??        XFlushGC(*d, *gc);

    } else {

        log_message_debug("Could not write to x window system display. The destination display is null.");
    }
}

/* X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE */
#endif
