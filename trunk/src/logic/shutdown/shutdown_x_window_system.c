/*
 * $RCSfile: shutdown_x_window_system.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-03-21 01:26:59 $ $Author: christian $
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

#ifndef SHUTDOWN_X_WINDOW_SYSTEM_SOURCE
#define SHUTDOWN_X_WINDOW_SYSTEM_SOURCE

#include "../../global/structure_constants.c"
#include "../../global/variables.c"

/**
 * Shuts down the x window system.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void shutdown_x_window_system(void* p0, const void* p1, const void* p2, const void* p3) {

    // The x window system display.
    void** d = POINTER_NULL_POINTER;

    // Get x window system display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    if (d != POINTER_NULL_POINTER) {

        // Destroy foreground pixel values.
        void** fg = POINTER_NULL_POINTER;
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_ARRAY);
        destroy_integer((void*) fg);

        // Destroy background pixel values.
        void** bg = POINTER_NULL_POINTER;
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_ARRAY);
        destroy_integer((void*) bg);

        // Destroy screen.
        void** s = POINTER_NULL_POINTER;
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
        destroy_integer((void*) s);

        XCloseDisplay(*d);

    } else {

        log_message_debug("WARNING: Could not shutdown x window system. There is no x window system running.");
    }
}

/* SHUTDOWN_X_WINDOW_SYSTEM_SOURCE */
#endif
