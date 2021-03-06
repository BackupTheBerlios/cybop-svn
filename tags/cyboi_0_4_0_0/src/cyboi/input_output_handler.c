/*
 * $RCSfile: input_output_handler.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2005-02-25 01:35:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INPUT_OUTPUT_HANDLER_SOURCE
#define INPUT_OUTPUT_HANDLER_SOURCE

#include "../creator/integer_creator.c"
#include "../global/integer_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../socket/unix_socket.c"
#include "../web/tcp_socket_server.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Starts up the input output.
 *
 * To the mechanisms belong:
 * - unix socket
 * - tcp socket
 * - x windows
 *
 * @param p0 the internals memory
 */
void startup_input_output(void* p0) {

    log_message_debug("Startup input output.");

    // The activation flag.
    void** f = POINTER_NULL_POINTER;
    // The comparison result.
    int r = 0;

    // UNIX socket server.
    get_array_elements(p0, (void*) UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

            create_unix_server_socket(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

    // TCP socket server.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

            create_tcp_server_socket(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

    // X windows server.
    get_array_elements(p0, (void*) X_WINDOWS_SERVER_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

//??            create_x_windows_server(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }
}

/**
 * Shuts down the input output mechanisms.
 *
 * To the mechanisms belong:
 * - x windows
 * - tcp socket
 * - unix socket
 *
 * @param p0 the internals memory
 */
void shutdown_input_output(void* p0) {

    log_message_debug("Shutdown input output.");

    // The activation flag.
    void** f = POINTER_NULL_POINTER;
    // The comparison result.
    int r = 0;

    // UNIX socket server.
    get_array_elements(p0, (void*) UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

            destroy_unix_server_socket(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

    // TCP socket server.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

            destroy_tcp_server_socket(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }

    // X windows server.
    get_array_elements(p0, (void*) X_WINDOWS_SERVER_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        compare_arrays(*f, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) &r, (void*) INTEGER_ARRAY);

        if (r == 1) {

//??            destroy_x_windows_server(p0);
            r = 0;
        }

        f = POINTER_NULL_POINTER;
    }
}

/* INPUT_OUTPUT_HANDLER_SOURCE */
#endif
