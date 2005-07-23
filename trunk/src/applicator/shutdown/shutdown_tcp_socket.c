/*
 * $RCSfile: shutdown_tcp_socket.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-07-23 12:56:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_TCP_SOCKET_SOURCE
#define SHUTDOWN_TCP_SOCKET_SOURCE

#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator/integer_allocator.c"

/**
 * Shuts down the tcp socket service.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void shutdown_tcp_socket(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Shutdown tcp socket.");

    // Deactivate tcp socket service.
    interrupt_tcp_socket(p0, p1, p2, p3);

    // The tcp server socket.
    int** s = NULL_POINTER;
    // The tcp client sockets.
    void* cs = NULL_POINTER;
    void* csc = NULL_POINTER;
    void* css = NULL_POINTER;
    // The activation flag.
    void* af = NULL_POINTER;
    // The blocking flag.
    void* bf = NULL_POINTER;
    // The tcp signal ids.
    void* id = NULL_POINTER;
    void* idc = NULL_POINTER;
    void* ids = NULL_POINTER;

    // Get tcp server socket.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
    // Get tcp client sockets.
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_ARRAY);
    // Get activation flag.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &af, (void*) POINTER_ARRAY);
    // Get blocking flag.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_BLOCKING_INTERNAL, (void*) &bf, (void*) POINTER_ARRAY);
    // Get tcp signal ids.
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_ARRAY);

    if (*s != NULL_POINTER) {

        // Close tcp server socket.
        close(**s);

        // Destroy tcp server socket.
        deallocate_integer(s);
        // Destroy tcp client sockets.
        deallocate_array((void*) cs, (void*) css, (void*) INTEGER_ARRAY);
        deallocate_integer(csc);
        deallocate_integer(css);
        // Destroy activation flag.
        deallocate_integer(af);
        // Destroy blocking flag.
        deallocate_integer(bf);
        // Destroy tcp signal ids.
        deallocate_array((void*) id, (void*) ids, (void*) INTEGER_ARRAY);
        deallocate_integer(idc);
        deallocate_integer(ids);

    } else {

        log_message_debug("WARNING: Could not shutdown tcp socket. There is no tcp socket service running.");
    }
}

/* SHUTDOWN_TCP_SOCKET_SOURCE */
#endif
