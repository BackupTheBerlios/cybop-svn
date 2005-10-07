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
 * @version $Revision: 1.10 $ $Date: 2005-10-07 12:20:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SEND_X_WINDOW_SYSTEM_SOURCE
#define SEND_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Sends an x window system message.
 *
 * @param p0 the internal memory
 * @param p1 the source gui compound model
 * @param p2 the source count
 */
void send_x_window_system(void* p0, void* p1, void* p2) {

    log_message_debug("Send x window system message.");

    // Encode compound model into x window system window.
    // The window gets allocated inside encode procedure.
    encode(p0, NULL_POINTER, NULL_POINTER, p1, p2, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST 2 send: %i\n", p0);

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    void** d = &NULL_POINTER;

    // Get display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    fprintf(stderr, "TEST 3 send: %i\n", p0);

    // Show window on display.
    write_data(d, NULL_POINTER, NULL_POINTER, p0, NULL_POINTER, (void*) X_WINDOW_SYSTEM_CHANNEL, (void*) X_WINDOW_SYSTEM_CHANNEL_COUNT);

    // The window internal.
    int** w = (int**) &NULL_POINTER;

    // Get window internal.
    get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST 7 send + sleep + window: %i\n", **w);
    sleep(3);

/*??
    XFreeGC(*d, *gc_menu_font);
    XFreeGC(*d, *gc_menu_border_bottom);
    XFreeGC(*d, *gc_menu_border_top);
    XFreeGC(*d, *gc_menu);
*/

    // Destroy window.
    XDestroyWindow(*d, **w);

    fprintf(stderr, "TEST 8 send destroy: %i\n", *w);

    // TODO?? Destroy here ALL other things that were created in encode_x_window_system!!

    // Destroy x window system internals.
    deallocate((void*) &w, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/* SEND_X_WINDOW_SYSTEM_SOURCE */
#endif
