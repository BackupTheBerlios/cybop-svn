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
 * @version $RCSfile: x_window_system_communicator.c,v $ $Revision: 1.29 $ $Date: 2009-01-31 16:31:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SENDER_SOURCE
#define X_WINDOW_SYSTEM_SENDER_SOURCE

#include <X11/Xlib.h>
#include <pthread.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../executor/accessor/getter.c"
#include "../../../logger/logger.c"

/**
 * Sends the window onto the x window system display.
 *
 * @param p0 the destination display (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory
 * @param p4 the source count
 */
void send_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        struct _XDisplay** d = (struct _XDisplay**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send to x window system display.");

        // The window.
        int** w = (int**) NULL_POINTER_MEMORY_MODEL;

        // Get x window system internals.
        get((void*) &w, p3, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (*d != *NULL_POINTER_MEMORY_MODEL) {

            // CAUTION! This test is necessary to avoid a "Segmentation fault"!
            if (*w != *NULL_POINTER_MEMORY_MODEL) {

                // Request input events (signals) to be put into event queue.
                XSelectInput(*d, **w, ExposureMask
                    | KeyPressMask | KeyReleaseMask
                    | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ButtonMotionMask
                    | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask
                    | EnterWindowMask | LeaveWindowMask);

                // Show the window (make it visible).
                XMapWindow(*d, **w);

                // Flush all pending requests to the X server.
                XFlush(*d);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send to x window system display. The destination display is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send to x window system display. The destination display is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send to x window system display. The destination display argument is null.");
    }
}

/* X_WINDOW_SYSTEM_SENDER_SOURCE */
#endif
