/*
 * $RCSfile: startup_x_window_system.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.1 $ $Date: 2005-03-20 17:53:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 *
 * A session (display) manager shows a graphical user login,
 * in which it offers a list of window managers to chose from.
 *
 * A window manager cares about all windows displayed on a screen.
 * This includes the resizing, moving, stacking or tiling of windows.
 *
 * CYBOI aims to become both at the same time,
 * a session- (display-) as well as a window manager.
 */

#ifndef STARTUP_X_WINDOW_SYSTEM_SOURCE
#define STARTUP_X_WINDOW_SYSTEM_SOURCE

#include "../../global/integer_constants.c"
#include "../../global/structure_constants.c"
#include "../../global/variables.c"

/**
 * Starts up the x window system.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_x_window_system(void* p0, const void* p1, const void* p2, const void* p3) {

    // The x window system display.
    void* d = POINTER_NULL_POINTER;

    // Get x window system display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    if (d != NULL_POINTER) {

        log_message_debug("WARNING: Could not startup x window system. The x window system is already running.");

    } else {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char* n = "";

        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        d = (void*) XOpenDisplay(n);

        // Set x window system display.
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
    }
}

/* STARTUP_X_WINDOW_SYSTEM_SOURCE */
#endif
