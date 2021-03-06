/*
 * $RCSfile: input_output_activator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.10 $ $Date: 2005-02-25 01:35:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef INPUT_OUTPUT_ACTIVATOR_SOURCE
#define INPUT_OUTPUT_ACTIVATOR_SOURCE

#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../web/tcp_socket_server.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Activates the input output mechanisms.
 *
 * The signal waiting loop only catches cyboi internal signals.
 * In order to also catch signals of various devices,
 * special mechanisms for signal reception have to be started.
 * To the mechanisms belong:
 * - unix socket
 * - tcp socket
 * - x windows
 *
 * These have their own internal signal/ action/ event/ interrupt
 * waiting loops which get activated here.
 * Whenever such a signal/ action/ event/ interrupt occurs, it gets transformed
 * into a cyboi signal and is finally placed in cyboi's signal memory.
 *
 * TODO: Since many internal waiting loops run in parallel,
 * the adding of signals to the signal memory must be synchronized!
 * How to do this properly in C?
 *
 * @param p0 the internals memory
 */
void activate_input_output(void* p0) {

    log_message_debug("Activate internals.");

    // The activation flag.
    void** f = POINTER_NULL_POINTER;
    // The comparison result.
    int r = 0;

    // UNIX socket server.
    get_array_elements(p0, (void*) UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

            receive_unix_socket(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

    // TCP socket server.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

//??            receive_tcp_socket(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

    // X windows server.
    get_array_elements(p0, (void*) X_WINDOWS_SERVER_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

            receive_x_windows(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

//?? TEST only!
//??    send_x_windows_output(NULL, NULL, p5);
//??    sleep(4);
//??    init_x();
}

/* INPUT_OUTPUT_ACTIVATOR_SOURCE */
#endif
