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
 * @version $Revision: 1.4 $ $Date: 2005-03-30 14:15:42 $ $Author: christian $
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

#include <X11/Xlib.h>
#include "../../creator/integer_creator.c"
#include "../../creator/unsigned_long_creator.c"
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

    // The display.
    void** d = POINTER_NULL_POINTER;

    // Get display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    if (d != POINTER_NULL_POINTER) {

        // CAUTION!
        // The X window system types Window, Colormap, Font are simple integers!

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char** dn = (char**) POINTER_NULL_POINTER;
        // The screen number.
        int** sn = (int**) POINTER_NULL_POINTER;
        // The screen.
        Screen** s = (Screen**) POINTER_NULL_POINTER;
        // The background pixel values.
        unsigned long** bg = (unsigned long**) POINTER_NULL_POINTER;
        // The foreground pixel values.
        unsigned long** fg = (unsigned long**) POINTER_NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int** r = (int**) POINTER_NULL_POINTER;
        // The default colormap id for allocation on the specified screen.
        // Most routine allocations of color should be made out of this colormap.
        int** cm = (int**) POINTER_NULL_POINTER;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
        unsigned long** vm = (unsigned long**) POINTER_NULL_POINTER;
        // The values as specified by the value mask.
        XGCValues** v = (XGCValues**) POINTER_NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC** gc = (struct _XGC**) POINTER_NULL_POINTER;
        // The font name.
        char** fn = (char**) POINTER_NULL_POINTER;
        // The font id.
        int** f = (int**) POINTER_NULL_POINTER;

        // Get x window system internals.
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

        // Destroy x window system internals.
        // CAUTION! Use descending order, as opposed to the creation!
        // CAUTION! The graphic context has to be destroyed twice
        // (xlibs-internal- and CYBOI structure).
        XUnloadFont(*d, **f);
//??        destroy_integer((void*) *f);
//??        free(*fn);
        XFreeGC(*d, *gc);
        free(*gc);
        free(*v);
        destroy_unsigned_long((void*) *vm);
        destroy_integer((void*) *cm);
        destroy_integer((void*) *r);
        destroy_unsigned_long((void*) *fg);
        destroy_unsigned_long((void*) *bg);
        destroy_integer((void*) *sn);
        XCloseDisplay(*d);
//??        free(*dn);

    } else {

        log_message_debug("WARNING: Could not shutdown x window system. There is no x window system running.");
    }
}

/* SHUTDOWN_X_WINDOW_SYSTEM_SOURCE */
#endif
