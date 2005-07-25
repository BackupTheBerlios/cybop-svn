/*
 * $RCSfile: startup_x_window_system.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-07-25 20:27:58 $ $Author: christian $
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
 *
 * CAUTION! The x window system uses a number of synonymous types:
 * Display* == struct _XDisplay*
 * GC == struct _XGC*
 * Window == int
 * Colormap == int
 * Font == int
 */

#ifndef STARTUP_X_WINDOW_SYSTEM_SOURCE
#define STARTUP_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/allocator/integer_allocator.c"
#include "../../memoriser/allocator/unsigned_long_allocator.c"

/**
 * Starts up the x window system.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_x_window_system(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Startup x window system.");

    // The display internal.
    struct _XDisplay** di = NULL_POINTER;

    // Get display internal.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_ARRAY);

    if (*di == NULL_POINTER) {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char* dn = NULL_POINTER;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay* d = NULL_POINTER;
        // The screen number.
        int* sn = INTEGER_NULL_POINTER;
        // The screen.
//??        Screen* s = NULL_POINTER;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int* cm = NULL_POINTER;
        // The background pixel values.
        unsigned long* bg = NULL_POINTER;
        // The foreground pixel values.
        unsigned long* fg = NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int* r = NULL_POINTER;
        // The font name.
//??        char* fn = NULL_POINTER;
        // The font id.
//??        int* f = NULL_POINTER;
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

        // Create x window system internals.
        allocate_integer((void*) &sn);
        allocate_integer((void*) &cm);
        allocate_unsigned_long((void*) &bg);
        allocate_unsigned_long((void*) &fg);
        allocate_integer((void*) &r);
//??        allocate_integer((void*) &f);
        allocate_unsigned_long((void*) &vm);

        // Initialise x window system internals.
        dn = "";
        d = XOpenDisplay(dn);
        *sn = DefaultScreen(d);
//??        s = XScreenOfDisplay(*d, *sn);
        *cm = XDefaultColormap(d, *sn);
        *bg = XWhitePixel(d, *sn);
        *fg = XBlackPixel(d, *sn);
        *r = DefaultRootWindow(d);
//??        *r = XRootWindowOfScreen(s);
//??        fn = "Helvetica";
//??        *f = XLoadFont(*d, fn);
        *vm = 0;
        v = NULL_POINTER;
        gc = XCreateGC(d, *r, *vm, v);

        // Assign x window system internals.
        XSetBackground(d, gc, *bg);
        XSetForeground(d, gc, *fg);
//??        XSetFont(*d, gc, f);

        // Set x window system internals.
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
//??        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
//??        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
//??        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("WARNING: Could not startup x window system. The x window system is already running.");
    }
}

/* STARTUP_X_WINDOW_SYSTEM_SOURCE */
#endif
