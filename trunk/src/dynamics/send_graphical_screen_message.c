/*
 * $RCSfile: send_graphical_screen_message.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

#ifndef SEND_GRAPHICAL_SCREEN_MESSAGE_SOURCE
#define SEND_GRAPHICAL_SCREEN_MESSAGE_SOURCE

//?? #include <stdio.h>
//?? #include <stdlib.h>
//?? #include <X11/Xlib.h>
//?? #include <X11/Xutil.h>

/**
 * This is the send operation.
 *
 * It sends a message, defined in a language, to an addressee.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-15 14:48:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * This is the send graphical screen message operation.
 *
 * @param p0 the addressee
 * @param p1 the message
 */
void send_graphical_screen_message(void* p0, void* p1) {

/*??
    // Get parameters from screen and set them on X.
    Display* display = XOpenDisplay("");
    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(
        display,
        DefaultRootWindow(display),
        hint.x,
        hint.y,
        hint.width,
        hint.height,
        5,
        foreground,
        background);

    XSetStandardProperties(display, window, "Application", "Icon", None, argv, argc, &hint);
    
    GC gc = XCreateGC(display, window, 0, 0);
    
    XSetBackground(display, gc, background);
    XSetForeground(display, gc, foreground);

    // Request input signals.
    XSelectInput(display, window, ButtonPressMask | KeyPressMask | ExposureMask);
    
    // Map windows.
    XMapRaised(display, window);
*/
}

/* SEND_GRAPHICAL_SCREEN_MESSAGE_SOURCE */
#endif

