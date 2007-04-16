/*
 * $RCSfile: x_window_system_communicator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.8 $ $Date: 2007-04-16 15:50:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE
#define X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE

#include <X11/Xlib.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
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

        // Get x window system internals.
        get(p3, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Request input events (signals) to be put into event queue.
        XSelectInput(*d, **w, ExposureMask
            | KeyPressMask | KeyReleaseMask
            | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ButtonMotionMask
            | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask
            | EnterWindowMask | LeaveWindowMask);

        // Show the window (make it visible).
        XMapWindow(*d, **w);

        // Flush all pending requests to the X server.
        XFlush(*d);

    } else {

        log_message_debug("Could not write to x window system display. The destination display is null.");
    }
}

/* X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE */
#endif
