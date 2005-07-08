/*
 * $RCSfile: startup_linux_console.c,v $
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

#ifndef STARTUP_LINUX_CONSOLE_SOURCE
#define STARTUP_LINUX_CONSOLE_SOURCE

#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memory/creator/integer_creator.c"
#include "../../memory/creator/unsigned_long_creator.c"

/**
 * Starts up the linux console.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_linux_console(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Startup linux console.");

/*??
    // The device name of the controlling terminal.
    int t = -1;

    // Get terminal internal.
    get_array_elements(p0, (void*) LINUX_CONSOLE_TERMINAL_INTERNAL, (void*) &t, (void*) POINTER_ARRAY);

    if (*t == NULL_POINTER) {

/*??
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
*/

        // Create linux console internals.
/*??
        create_integer((void*) &sn);
        create_integer((void*) &cm);
        create_unsigned_long((void*) &bg);
        create_unsigned_long((void*) &fg);
        create_integer((void*) &r);
//??        create_integer((void*) &f);
        create_unsigned_long((void*) &vm);
*/

/*??
        // Initialise linux console internals.
        t = ttyname();
        fprintf((FILE*) *d, "TEST: The linux console terminal device name is: %i\n", n);
/*??
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
*/

/*??
        // Assign linux console internals.
        XSetBackground(d, gc, *bg);
        XSetForeground(d, gc, *fg);
//??        XSetFont(*d, gc, f);
*/

        // Set linux console internals.
/*??
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
//??        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
//??        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
//??        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
*/

/*??
    } else {

        log_message_debug("WARNING: Could not startup linux console. The linux console is already running.");
    }
*/
}

/* STARTUP_LINUX_CONSOLE_SOURCE */
#endif
