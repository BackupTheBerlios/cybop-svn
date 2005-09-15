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
 * @version $Revision: 1.7 $ $Date: 2005-09-15 20:49:24 $ $Author: christian $
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
 * @param p1 the source gui compound model
 * @param p2 the source count
 */
void send_x_window_system(void* p0, void* p1, void* p2) {

    log_message_debug("Send x window system message.");

    // The window internal.
    void** wp = &NULL_POINTER;
    int** wcp = (int**) &NULL_POINTER;
    int** wsp = (int**) &NULL_POINTER;
    // The window.
    void* w = NULL_POINTER;
    void* wc = NULL_POINTER;
    void* ws = NULL_POINTER;

    // Get window internal.
    get(p0, (void*) WINDOW_INTERNAL, (void*) &wp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) WINDOW_COUNT_INTERNAL, (void*) &wcp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) WINDOW_SIZE_INTERNAL, (void*) &wsp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*wp != NULL_POINTER) {

        // Reinitialise tui with already existing tui internal.
        w = *wp;
        wc = *wcp;
        ws = *wsp;

    } else {

        // The window internal wp is null, so that a new window w needs to be created.

/*??
        // The count and size z, y, x coordinates.
        int* tcz = NULL_POINTER;
        int* tcy = NULL_POINTER;
        int* tcx = NULL_POINTER;
        int* tsz = NULL_POINTER;
        int* tsy = NULL_POINTER;
        int* tsx = NULL_POINTER;

        // Allocate count and size z, y, x coordinates.
        allocate((void*) &tcz, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tcy, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tcx, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tsz, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tsy, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &tsx, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Initialise count and size z, y, x coordinates.
        set(tcz, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tcy, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tcx, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tsz, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tsy, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        set(tsx, (void*) PRIMITIVE_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Allocate tui count and size.
        allocate((void*) &tc, (void*) TUI_COUNT, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &ts, (void*) TUI_COUNT, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Initialise tui count and size.
        set(tc, (void*) TUI_Z_DIMENSION_INDEX, (void*) &tcz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(tc, (void*) TUI_Y_DIMENSION_INDEX, (void*) &tcy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(tc, (void*) TUI_X_DIMENSION_INDEX, (void*) &tcx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_Z_DIMENSION_INDEX, (void*) &tsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_Y_DIMENSION_INDEX, (void*) &tsy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(ts, (void*) TUI_X_DIMENSION_INDEX, (void*) &tsx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/

        // Allocate window.
        allocate((void*) &w, (void*) wsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Set window internals.
        // The window is stored in internal memory for faster access,
        // so that it does not have to be created every time again.
        set(p0, (void*) WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) WINDOW_COUNT_INTERNAL, (void*) &wc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) WINDOW_SIZE_INTERNAL, (void*) &ws, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    }

    // Encode compound model into x window system window.
    encode((void*) &w, (void*) wc, (void*) ws, p1, p2, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT);

    // CAUTION! The window AND ALL ITS CONTENT
    // need to be deallocated at system shutdown!

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    void** d = &NULL_POINTER;

    // Get display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    // Show window on display.
    write_data(d, NULL_POINTER, NULL_POINTER, w, (void*) &wc, (void*) X_WINDOW_SYSTEM_CHANNEL, (void*) X_WINDOW_SYSTEM_CHANNEL_COUNT);
}

/* SEND_X_WINDOW_SYSTEM_SOURCE */
#endif
