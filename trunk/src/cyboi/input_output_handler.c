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
 * @version $Revision: 1.1 $ $Date: 2005-01-08 14:28:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INPUT_OUTPUT_HANDLER_SOURCE
#define INPUT_OUTPUT_HANDLER_SOURCE

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
    int* f = INTEGER_NULL_POINTER;
    create_integer((void*) &f);
    *f = 0;

    // UNIX socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        create_unix_socket(p0);

        *f = 0;
    }

    // TCP socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        create_tcp_socket(p0);

        *f = 0;
    }

    // X windows.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &X_WINDOWS_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        create_x_windows(p0);

        *f = 0;
    }

    // Destroy activation flag.
    destroy_integer((void*) &f);
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
    int* f = INTEGER_NULL_POINTER;
    create_integer((void*) &f);
    *f = 0;

    // X windows.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &X_WINDOWS_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        destroy_x_windows(p0);

        *f = 0;
    }

    // TCP socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        destroy_tcp_socket(p0);

        *f = 0;
    }

    // UNIX socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        destroy_unix_socket(p0);

        *f = 0;
    }

    // Destroy activation flag.
    destroy_integer((void*) &f);
}

/* INPUT_OUTPUT_HANDLER_SOURCE */
#endif
