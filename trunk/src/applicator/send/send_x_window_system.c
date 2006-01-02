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
 * @version $Revision: 1.12 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SEND_X_WINDOW_SYSTEM_SOURCE
#define SEND_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/model_constants.c"
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

    fprintf(stderr, "TEST send 0: %i\n", p0);

    // Encode compound model into x window system window.
    encode(p0, NULL_POINTER, NULL_POINTER, p1, p2, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT);

    fprintf(stderr, "TEST send 1: %i\n", p0);

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    void** d = &NULL_POINTER;

    // Get display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    // Show window on display.
    write_data(d, NULL_POINTER, NULL_POINTER, p0, NULL_POINTER, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT);

    // TODO?? Destroy here ALL other things that were created in encode_x_window_system!!
}

/* SEND_X_WINDOW_SYSTEM_SOURCE */
#endif
