/*
 * $RCSfile: shutdown_x_window_system.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2005-11-21 23:29:27 $ $Author: christian $
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

#ifndef SHUTDOWN_X_WINDOW_SYSTEM_SOURCE
#define SHUTDOWN_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Shuts down the x window system.
 *
 * This is done in the reverse order that the x window system was started up.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void shutdown_x_window_system(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Shutdown x window system.");

    // The display internal.
    struct _XDisplay** di = NULL_POINTER;

    // Get display internal.
    get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*di != NULL_POINTER) {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char** dn = (char**) &NULL_POINTER;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** d = (struct _XDisplay**) &NULL_POINTER;
        // The screen number.
        int** sn = (int**) &NULL_POINTER;
        // The screen.
//??        Screen** s = (Screen**) &NULL_POINTER;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int** cm = (int**) &NULL_POINTER;
        // The background pixel values.
        unsigned long** bg = (unsigned long**) &NULL_POINTER;
        // The foreground pixel values.
        unsigned long** fg = (unsigned long**) &NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int** r = (int**) &NULL_POINTER;
        // The font name.
//??        char** fn = (char**) &NULL_POINTER;
        // The font id.
//??        int** f = (char**) &NULL_POINTER;
        // The menu border bottom graphic context.
        struct _XGC** gc_menu_border_bottom = NULL_POINTER;
        // The window.
        int** w = NULL_POINTER;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
        unsigned long** vm = (unsigned long**) &NULL_POINTER;
        // The values as specified by the value mask.
        XGCValues** v = (XGCValues**) &NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC** gc = (struct _XGC**) &NULL_POINTER;

        // Get x window system internals.
        get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
//??        get(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
//??        get(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
//??        get(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL, (void*) &gc_menu_border_bottom, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Free x window system internals.
        XFreeGC(*d, *gc);
        XDestroyWindow(*d, **w);
        XCloseDisplay(*d);

        // Destroy x window system internals.
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
        deallocate((void*) sn, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) cm, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) bg, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) fg, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) r, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
//??        deallocate((void*) f, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) w, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) vm, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("WARNING: Could not shutdown x window system. There is no x window system running.");
    }
}

/* SHUTDOWN_X_WINDOW_SYSTEM_SOURCE */
#endif
