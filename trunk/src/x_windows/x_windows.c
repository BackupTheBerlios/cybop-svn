/*
 * $RCSfile: x_windows.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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

#ifndef X_WINDOWS_SOURCE
#define X_WINDOWS_SOURCE

//??#include <X11/Xlib.h>
//??#include <X11/Xutil.h>

/**
 * This is the x windows.
 *
 * It keeps data which are necessary to control an x windows.
 *
 * @version $Revision: 1.6 $ $Date: 2004-06-11 19:34:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct x_windows {

    /** The display. */
/*??
    Display* display;

    /** The screen. */
/*??
    int screen;

    /** The window. */
/*??
    Window window;

    /** The graphics context. */
/*??
    GC gc;

    /** The menu graphics context. */
/*??
    GC gc_menu;

    /** The menu border top graphics context. */
/*??
    GC gc_menu_border_top;

    /** The menu border bottom graphics context. */
/*??
    GC gc_menu_border_bottom;

    /** The menu font graphics context. */
/*??
    GC gc_menu_font;

    /** The event. */
/*??
    XEvent event;

    /** The key. */
/*??
    KeySym key;

    /** The size hint. */
/*??
    XSizeHints hint;

    /** The text. */
/*??
    char text[10];

    /** The test. */
/*??
    char str_test[1000];

    /** The zugriff. */
/*??
    char str_zugriff[1000];

    /** The menu bar. */
/*??
    char str_menubar[100];

    /** The foreground. */
    /*??unsigned long*/ //??double foreground;

    /** The background. */
    /*??unsigned long*/ //??double background;

    /** The menu foreground. */
    /*??unsigned long*/ //??double menu_foreground;

    /** The temporary variables. */
/*??
    int k;
    int menu_eintrage_ende;

    /** The color map. */
/*??
    Colormap cmap;

    /** The colors. */
/*??
    XColor gray, light_gray, vlight_gray, dark_gray;

    /** The window attributes. */
/*??
    XWindowAttributes window_attributes;
*/
};

/* X_WINDOWS_SOURCE */
#endif
