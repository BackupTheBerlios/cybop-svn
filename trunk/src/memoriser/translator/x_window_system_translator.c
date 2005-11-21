/*
 * $RCSfile: x_window_system_translator.c,v $
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
 */

#ifndef X_WINDOW_SYSTEM_TRANSLATOR_SOURCE
#define X_WINDOW_SYSTEM_TRANSLATOR_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Decodes the x window system model into a compound model.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory containing all x window system windows
 * @param p4 the source count
 */
void decode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the compound model into an x window system model.
 *
 * @param p0 the internal memory containing all x window system windows
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void encode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Encode compound into x window system window.");

/*??
        // The source part abstraction, model, details.
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        void** m = &NULL_POINTER;
        // CAUTION! This must be int** because its value is used below.
        int** mc = (int**) &NULL_POINTER;
        void** ms = &NULL_POINTER;
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;
*/

/*??
        //
        // A number of useful x functions.
        //

        // Configure functions.
        XConfigureWindow(display, w, value_mask, values);
        XResizeWindow(display, w, width, height);
        XChangeWindowAttributes(display, w, valuemask, attributes);

        // GC functions.
        XSetLineAttributes(display, gc, line_width, line_style, cap_style, join_style);
        XSetFillStyle(display, gc, fill_style);
        XSetFont(display, gc, font);

        // Graphics functions.
*/

    } else {

        log_message_debug("Could not encode x window system. The source count is null.");
    }
}

/* X_WINDOW_SYSTEM_TRANSLATOR_SOURCE */
#endif
