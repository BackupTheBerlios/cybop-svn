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
 * @version $RCSfile: x_window_system_sending_communicator.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SENDING_COMMUNICATOR_SOURCE
#define X_WINDOW_SYSTEM_SENDING_COMMUNICATOR_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/communicator/sender/x_window_system_sender.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/encoder/x_window_system_encoder.c"
#include "../../../logger/logger.c"

/**
 * Sends an x window system message.
 *
 * @param p0 the internal memory
 * @param p1 the source gui compound model
 * @param p2 the source gui compound model count
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 */
void communicate_sending_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send x window system message.");

    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) NULL_POINTER_MEMORY_MODEL;

    // Get x window system mutex.
    get((void*) &xmt, p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    pthread_mutex_lock(*xmt);

//??    fwprintf(stdout, L"TEST send x 0: %i\n", p0);

    // Encode compound model into x window system window.
    encode_x_window_system(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p3, p4);

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    void** d = NULL_POINTER_MEMORY_MODEL;

    // Get display.
    get_array_elements((void*) &d, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

//??    fwprintf(stdout, L"TEST send x 1: %i\n", p0);

    // Show window on display.
    send_x_window_system(d, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p0, *NULL_POINTER_MEMORY_MODEL);

//??    fwprintf(stdout, L"TEST send x 2: %i\n", p0);

    pthread_mutex_unlock(*xmt);

    // TODO?? Destroy here ALL other things that were created in encode_x_window_system!!
}

/* X_WINDOW_SYSTEM_SENDING_COMMUNICATOR_SOURCE */
#endif
