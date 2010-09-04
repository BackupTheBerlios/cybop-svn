/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: x_window_system_shutting_maintainer.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SHUTTING_MAINTAINER_SOURCE
#define X_WINDOW_SYSTEM_SHUTTING_MAINTAINER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator.c"

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
void maintain_shutting_x_window_system(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Shutdown x window system.");

    // The display internal.
    struct _XDisplay** di = (struct _XDisplay**) NULL_POINTER_MEMORY_MODEL;

    // Get display internal.
    get((void*) &di, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // Only destroy display if existent.
    if (*di != *NULL_POINTER_MEMORY_MODEL) {

        // Interrupt x window system service thread.
        maintain_interrupting_thread(p1, p2);

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char** dn = (char**) NULL_POINTER_MEMORY_MODEL;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** d = (struct _XDisplay**) NULL_POINTER_MEMORY_MODEL;
        // The screen number.
        int** sn = (int**) NULL_POINTER_MEMORY_MODEL;
        // The screen.
//??        Screen** s = (Screen**) NULL_POINTER_MEMORY_MODEL;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int** cm = (int**) NULL_POINTER_MEMORY_MODEL;
        // The background pixel values.
        unsigned long** bg = (unsigned long**) NULL_POINTER_MEMORY_MODEL;
        // The foreground pixel values.
        unsigned long** fg = (unsigned long**) NULL_POINTER_MEMORY_MODEL;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int** r = (int**) NULL_POINTER_MEMORY_MODEL;
        // The menu border bottom graphic context.
        struct _XGC** gc_menu_border_bottom = (struct _XGC**) NULL_POINTER_MEMORY_MODEL;
        // The window.
        int** w = (int**) NULL_POINTER_MEMORY_MODEL;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
        unsigned long** vm = (unsigned long**) NULL_POINTER_MEMORY_MODEL;
        // The values as specified by the value mask.
        XGCValues** v = (XGCValues**) NULL_POINTER_MEMORY_MODEL;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC** gc = (struct _XGC**) NULL_POINTER_MEMORY_MODEL;
        // The interrupt flag.
        int* ir = (int*) *NULL_POINTER_MEMORY_MODEL;

        // Get x window system internals.
        get((void*) &dn, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &d, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &sn, p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//??        get((void*) &s, p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &cm, p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &bg, p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &fg, p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &r, p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &gc_menu_border_bottom, p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &w, p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &vm, p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &v, p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        get((void*) &gc, p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//??        get((void*) &ir, p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_INTERNAL, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

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
        deallocate((void*) ir, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//??        free(*v);
        deallocate((void*) vm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) w, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//??        deallocate((void*) f, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) r, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) fg, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) bg, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) cm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) sn, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not shutdown x window system. There is no x window system running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* X_WINDOW_SYSTEM_SHUTTING_MAINTAINER_SOURCE */
#endif
