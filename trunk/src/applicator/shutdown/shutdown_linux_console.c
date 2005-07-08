/*
 * $RCSfile: shutdown_linux_console.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-07-08 13:48:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_LINUX_CONSOLE_SOURCE
#define SHUTDOWN_LINUX_CONSOLE_SOURCE

#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memory/creator/integer_creator.c"
#include "../../memory/creator/unsigned_long_creator.c"

/**
 * Shuts down the linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void shutdown_linux_console(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Shutdown linux console.");

/*??
    // The display internal.
    struct _XDisplay** di = NULL_POINTER;

    // Get display internal.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_ARRAY);

    if (*di != NULL_POINTER) {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char** dn = NULL_POINTER;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** d = NULL_POINTER;
        // The screen number.
        int** sn = NULL_POINTER;
        // The screen.
//??        Screen** s = NULL_POINTER;
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
        // The font name.
//??        char** fn = NULL_POINTER;
        // The font id.
//??        int** f = NULL_POINTER;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
        unsigned long** vm = NULL_POINTER;
        // The values as specified by the value mask.
        XGCValues** v = NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC** gc = NULL_POINTER;

        // Get x window system internals.
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) POINTER_ARRAY);
//??        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_ARRAY);
//??        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) POINTER_ARRAY);
//??        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_ARRAY);
//??        XUnloadFont(*d, **f);
//??        XSetBackground(d, gc, *bg);
//??        XSetForeground(d, gc, *fg);

        // Free x window system internals.
        XFreeGC(*d, *gc);
        XCloseDisplay(*d);

        // Destroy x window system internals.
        // CAUTION! Use descending order, as opposed to the creation!
        // CAUTION! Do NOT use references &, because variables are **
        // and *&variable equals the variable alone.
        destroy_unsigned_long((void*) vm);
//??        destroy_integer((void*) f);
        destroy_integer((void*) r);
        destroy_unsigned_long((void*) fg);
        destroy_unsigned_long((void*) bg);
        destroy_integer((void*) cm);
        destroy_integer((void*) sn);

    } else {

        log_message_debug("WARNING: Could not shutdown linux console. There is no linux console running.");
    }
*/
}

/* SHUTDOWN_LINUX_CONSOLE_SOURCE */
#endif
