/*
 * $RCSfile: startup_x_windows.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-03-20 01:43:34 $ $Author: christian $
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

#ifndef STARTUP_X_WINDOWS_SOURCE
#define STARTUP_X_WINDOWS_SOURCE

/**
 * Starts up the x windows.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_x_windows(void* p0, const void* p1, const void* p2, const void* p3) {

/*??
    // The unix server socket filename.
    void* f = POINTER_NULL_POINTER;

    // Get unix server socket filename.
    get_array_elements(p0, (void*) UNIX_SERVER_SOCKET_FILENAME_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != POINTER_NULL_POINTER) {
*/

    // The display name.
    // An example identifying the second screen of the first
    // display of host computer piggy.rz.tu-ilmenau.de would be:
    // char* dn = "earth.cybop.net:0.1"
    //?? TODO: This has to be built dynamically, later on!
    //?? For now, it is just an empty string.
    char* dn = "";
    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
//??    x->display = XOpenDisplay(dn);
}

/**
 * Shuts down the x windows.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void shutdown_x_windows(void* p0, const void* p1, const void* p2, const void* p3) {

//??    XCloseDisplay(x->display);
}

/* STARTUP_X_WINDOWS_SOURCE */
#endif
