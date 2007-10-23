/*
 * $RCSfile: shutdown_x_window_system.c,v $
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
 * @version $Revision: 1.25 $ $Date: 2007-10-23 17:37:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTDOWN_X_WINDOW_SYSTEM_SOURCE
#define SHUTDOWN_X_WINDOW_SYSTEM_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

//
// CAUTION! The x window system uses a number of synonymous types:
// Display* == struct _XDisplay*
// GC == struct _XGC*
// Window == int
// Colormap == int
// Font (ID) == int
//

/**
 * Shuts down the x window system.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internals memory
 * @param p1 the socket service thread
 * @param p2 the socket service thread interrupt
 */
void shutdown_x_window_system(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Shutdown x window system.");

    // The display internal.
    struct _XDisplay** di = (struct _XDisplay**) NULL_POINTER;

    // Get display internal.
    get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Only destroy display if existent.
    if (*di != *NULL_POINTER) {

        // Interrupt x window system service thread.
        interrupt_x_window_system(p1, p2);

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char** dn = (char**) NULL_POINTER;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** d = (struct _XDisplay**) NULL_POINTER;
        // The screen number.
        int** sn = (int**) NULL_POINTER;
        // The screen.
//??        Screen** s = (Screen**) NULL_POINTER;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int** cm = (int**) NULL_POINTER;
        // The background pixel values.
        unsigned long** bg = (unsigned long**) NULL_POINTER;
        // The foreground pixel values.
        unsigned long** fg = (unsigned long**) NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int** r = (int**) NULL_POINTER;
        // The menu border bottom graphic context.
        struct _XGC** gc_menu_border_bottom = (struct _XGC**) NULL_POINTER;
        // The window.
        int** w = (int**) NULL_POINTER;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
        unsigned long** vm = (unsigned long**) NULL_POINTER;
        // The values as specified by the value mask.
        XGCValues** v = (XGCValues**) NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC** gc = (struct _XGC**) NULL_POINTER;
        // The interrupt flag.
        int* ir = (int*) *NULL_POINTER;

        // Get x window system internals.
        get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
//??        get_element(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL, (void*) &gc_menu_border_bottom, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
//??        get_element(p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_INTERNAL, (void*) &ir, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

/*??
    XFreeGC(*d, *gc_menu_font);
    XFreeGC(*d, *gc_menu_border_bottom);
    XFreeGC(*d, *gc_menu_border_top);
    XFreeGC(*d, *gc_menu);
*/

        // Free x window system internals.
//??        XFreeGC(*d, *gc);

//??        XDestroyWindow(*d, **w);

//??        XCloseDisplay(*d);

        // Destroy x window system internals.
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
        // CAUTION! Use descending order!
        // Example: The values (v) are destroyed BEFORE the value mask (vm)
        // attributes, since v might still reference vm internally.
        deallocate((void*) ir, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
//??        free(*v);
        deallocate((void*) vm, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) w, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
//??        deallocate((void*) f, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) r, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) fg, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) bg, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) cm, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) sn, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not shutdown x window system. There is no x window system running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SHUTDOWN_X_WINDOW_SYSTEM_SOURCE */
#endif
