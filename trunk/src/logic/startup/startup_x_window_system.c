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
 * @version $Revision: 1.4 $ $Date: 2005-03-22 01:13:06 $ $Author: christian $
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

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../creator/integer_creator.c"
#include "../../creator/unsigned_long_creator.c"
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

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = NULL_POINTER;

    // Get display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    if (*d == NULL_POINTER) {

        // CAUTION!
        // The X window system types Window, Colormap, Font are simple integers!

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char* dn = NULL_POINTER;
        // The screen number.
        int* sn = INTEGER_NULL_POINTER;
        // The screen.
        Screen* s = NULL_POINTER;
        // The background pixel values.
        unsigned long* bg = NULL_POINTER;
        // The foreground pixel values.
        unsigned long* fg = NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int* r = NULL_POINTER;
        // The default colormap id for allocation on the specified screen.
        // Most routine allocations of color should be made out of this colormap.
        int* cm = NULL_POINTER;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
        unsigned long* vm = NULL_POINTER;
        // The values as specified by the value mask.
        XGCValues* v = NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC* gc = NULL_POINTER;
        // The font name.
        char* fn = NULL_POINTER;
        // The font id.
        int* f = NULL_POINTER;

        // Create x window system internals.
        create_integer((void*) &sn);
        create_unsigned_long((void*) &bg);
        create_unsigned_long((void*) &fg);
        create_integer((void*) &r);
        create_integer((void*) &cm);
        create_unsigned_long((void*) &vm);
        create_integer((void*) &f);

        // Initialise x window system internals.
        dn = "";
        *d = XOpenDisplay(dn);
        *sn = 0;
        s = XScreenOfDisplay(*d, *sn);
        *bg = XWhitePixel(*d, *sn);
        *fg = XBlackPixel(*d, *sn);
        *r = XRootWindowOfScreen(s);
        *cm = XDefaultColormap(*d, *sn);
        *vm = 0;
        v = NULL_POINTER;
        gc = XCreateGC(*d, *r, *vm, v);
        XSetBackground(*d, gc, *bg);
        XSetForeground(*d, gc, *fg);
//??        fn = "Helvetica";
//??        *f = XLoadFont(*d, fn);
//??        XSetFont(*d, gc, f);

        // Set x window system internals.
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        // CAUTION! Do NOT use reference for d, because it is of type (struct _XDisplay**)!
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) d, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

/*??
        XColor gray;
        gray.red = 49125;
        gray.green = 49125;
        gray.blue = 49125;
        XAllocColor(d, *cm, &gray);

        XColor light_gray;
        light_gray.red = 56000;
        light_gray.green = 58000;
        light_gray.blue = 60000;
        XAllocColor(d, *cm, &light_gray);

        XColor vlight_gray;
        vlight_gray.red = 60000;
        vlight_gray.green = 61000;
        vlight_gray.blue = 62000;
        XAllocColor(d, *cm, &vlight_gray);

        XColor dark_gray;
        dark_gray.red = 32768;
        dark_gray.green = 32768;
        dark_gray.blue = 32768;
        XAllocColor(d, *cm, &dark_gray);
*/

/*??
        // Create menu graphic context.
        gc_menu = XCreateGC(display, window, 0, 0);
        XSetBackground(display, gc_menu, background);
        XSetForeground(display, gc_menu, light_gray.pixel);

        // Create menu border graphic context.
        gc_menu_border_top = XCreateGC(display, window, 0, 0);
        XSetBackground(display, gc_menu_border_top, background);
        XSetForeground(display, gc_menu_border_top, vlight_gray.pixel);

        // Create menu border bottom graphic context.
        gc_menu_border_bottom = XCreateGC(display, window, 0, 0);
        XSetBackground(display, gc_menu_border_bottom, background);
        XSetForeground(display, gc_menu_border_bottom, dark_gray.pixel);

        // Create menu font graphic context.
        gc_menu_font = XCreateGC(display, window, 0, 0);
        XSetBackground(display, gc_menu_font, light_gray.pixel);
        XSetForeground(display, gc_menu_font, foreground);
*/

        /** The event. */
        XEvent event;
        /** The key. */
        KeySym key;
        /** The text. */
        char text[10];
        /** The test. */
        char str_test[1000];
        /** The zugriff. */
        char str_zugriff[1000];
        /** The menu bar. */
        char str_menubar[100];
        /** The menu foreground. */
        /*??unsigned long*/ //??double menu_foreground;
        /** The temporary variables. */
        int k;
        int menu_eintrage_ende;
        /** The window attributes. */
        XWindowAttributes window_attributes;

        // The size hint.
        XSizeHints sh;
        sh.x = 100;
        sh.y = 100;
        sh.width = 400;
        sh.height = 300;
        sh.flags = PPosition | PSize;

        // Create window.
        int w = XCreateSimpleWindow(*d, *r, sh.x, sh.y, sh.width, sh.height, 5, *fg, *bg);

        XSetStandardProperties(*d, w, "Application", "Icon", None, NULL, 0, (void*) &sh);

/*??
        char* test = "test string";
        int test_length = strlen(test);
        XDrawString(display, window, cybol_gc,
            position_x, position_y, test, test_length);
*/

        // Request input events (signals) to be put into event queue.
//??        XSelectInput(display, window, ButtonPressMask | KeyPressMask | ExposureMask);

        // Map the window.
        // This procedure changes the order of all sister windows,
        // so that the given window lies on top.
        // Afterwards, all windows are displayed on the screen.
        XMapRaised(*d, w);

        //?? TODO: From xlib tutorial.
        //?? Remove as soon as event loop (MappingNotify) functions!
        XFlushGC(*d, gc);

        sleep(5);

        // Free memory.
        XDestroyWindow(*d, w);

    } else {

        log_message_debug("WARNING: Could not startup x window system. The x window system is already running.");
    }
}

/* STARTUP_X_WINDOW_SYSTEM_SOURCE */
#endif
