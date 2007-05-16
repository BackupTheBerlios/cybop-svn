/*
 * $RCSfile: send_x_window_system.c,v $
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
 * @version $Revision: 1.21 $ $Date: 2007-05-16 19:29:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SEND_X_WINDOW_SYSTEM_SOURCE
#define SEND_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
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
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 */
void send_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Send x window system message.");

    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) NULL_POINTER;

    // Get x window system mutex.
    get(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &xmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    pthread_mutex_lock(*xmt);

    // Serialise compound model into x window system window.
    serialise(p0, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        p1, p2, *NULL_POINTER, *NULL_POINTER, p3, p4, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT);

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    void** d = NULL_POINTER;

    // Get display.
    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

    // Show window on display.
    write_data(d, *NULL_POINTER, *NULL_POINTER, p0, *NULL_POINTER, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT);

    pthread_mutex_unlock(*xmt);

    // TODO?? Destroy here ALL other things that were created in encode_x_window_system!!
}

/* SEND_X_WINDOW_SYSTEM_SOURCE */
#endif
