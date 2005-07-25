/*
 * $RCSfile: send_x_window_system.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2005-07-25 21:01:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SEND_X_WINDOW_SYSTEM_SOURCE
#define SEND_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

/**
 * Sends an x window system message.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void send_x_window_system(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Send x window system message.");

//??            knowledge model is given as param
//??            create encode model em
//??            encode-translate(em, km)

//??            create serialise model sm
//??            serialise(sm, em)
//??            destroy em

//??            create vga model vm
//??            send_vga(vm, sm)
//??            destroy sm
//??            ?? destroy or not vm??

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = NULL_POINTER;
    // The default colourmap id for allocation on the specified screen.
    // Most routine allocations of colour should be made out of this colormap.
    int** cm = NULL_POINTER;
    // The background pixel values.
    unsigned long** bg = NULL_POINTER;
    // The foreground pixel values.
    unsigned long** fg = NULL_POINTER;
    // The top-level root window for the given display and screen.
    // This is sometimes called the root window of the window manager.
    // Remember, CYBOI itself IS the window manager.
    int** r = NULL_POINTER;

    // Get x window system internals.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_ARRAY);

    // The size hint.
    XSizeHints sh;
    sh.x = 100;
    sh.y = 100;
    sh.width = 400;
    sh.height = 300;
    sh.flags = PPosition | PSize;

    // The window.
    int w = XCreateSimpleWindow(*d, **r, sh.x, sh.y, sh.width, sh.height, 5, **fg, **bg);
    XSetStandardProperties(*d, w, "Application", "Icon", None, NULL_POINTER, 0, (void*) &sh);

    // The colours.
    XColor gray;
    XColor light_gray;
    XColor vlight_gray;
    XColor dark_gray;
    // The menu graphic context.
    struct _XGC* gc_menu = NULL_POINTER;
    // The menu border top graphic context.
    struct _XGC* gc_menu_border_top = NULL_POINTER;
    // The menu border bottom graphic context.
    struct _XGC* gc_menu_border_bottom = NULL_POINTER;
    // The menu font graphic context.
    struct _XGC* gc_menu_font = NULL_POINTER;

    // Initialise x window system internals.
    gray.red = 49125;
    gray.green = 49125;
    gray.blue = 49125;
    light_gray.red = 56000;
    light_gray.green = 58000;
    light_gray.blue = 60000;
    vlight_gray.red = 60000;
    vlight_gray.green = 61000;
    vlight_gray.blue = 62000;
    dark_gray.red = 32768;
    dark_gray.green = 32768;
    dark_gray.blue = 32768;
    gc_menu = XCreateGC(*d, w, 0, 0);
    gc_menu_border_top = XCreateGC(*d, w, 0, 0);
    gc_menu_border_bottom = XCreateGC(*d, w, 0, 0);
    gc_menu_font = XCreateGC(*d, w, 0, 0);

    // Assign x window system internals.
    XAllocColor(*d, **cm, &gray);
    XAllocColor(*d, **cm, &light_gray);
    XAllocColor(*d, **cm, &vlight_gray);
    XAllocColor(*d, **cm, &dark_gray);
    XSetBackground(*d, gc_menu, **bg);
    XSetForeground(*d, gc_menu, light_gray.pixel);
    XSetBackground(*d, gc_menu_border_top, **bg);
    XSetForeground(*d, gc_menu_border_top, vlight_gray.pixel);
    XSetBackground(*d, gc_menu_border_bottom, **bg);
    XSetForeground(*d, gc_menu_border_bottom, dark_gray.pixel);
    XSetBackground(*d, gc_menu_font, light_gray.pixel);
    XSetForeground(*d, gc_menu_font, **fg);

    // Request input events (signals) to be put into event queue.
    XSelectInput(*d, w, ButtonPressMask | KeyPressMask | ExposureMask);

    // Map window.
    // This procedure changes the order of all sister windows,
    // so that the given window lies on top.
    // Afterwards, all windows are displayed on the screen.
    XMapRaised(*d, w);

    // The window attributes.
//??    XWindowAttributes* wa = NULL_POINTER;
    XWindowAttributes wa;

    // Draw window.
    XGetWindowAttributes(*d, w, &wa);
    //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, "hello", strlen("hello"));
    //XRectangle (e.xexpose.display, e.xexpose.window, gc_menu, 2, 2, (wa.width-4), 30);

    // Draw menu bar.
    XDrawLine(*d, w, gc_menu_border_bottom, 0, 21, wa.width, 21);
    XDrawLine(*d, w, gc_menu_border_bottom, (wa.width-1), 1, (wa.width-1), 21);

    //?? TODO: From xlib tutorial.
    //?? Remove as soon as event loop (MappingNotify) functions!
//??    XFlushGC(*d, gc);

    sleep(5);

/*??
        XFreeGC(*d, *gc_menu_font);
        XFreeGC(*d, *gc_menu_border_bottom);
        XFreeGC(*d, *gc_menu_border_top);
        XFreeGC(*d, *gc_menu);
*/
    XDestroyWindow(*d, w);
}

/* SEND_X_WINDOW_SYSTEM_SOURCE */
#endif
