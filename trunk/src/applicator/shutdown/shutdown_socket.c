/*
 * $RCSfile: shutdown_socket.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2006-12-30 13:42:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_SOCKET_SOURCE
#define SHUTDOWN_SOCKET_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Shuts down the socket service.
 *
 * @param p0 the internals memory
 * @param p1 the base internal
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void shutdown_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Shutdown socket.");

    // The server socket internal.
    int** si = (int**) &NULL_POINTER;

    // Get server socket internal.
    get(p0, (void*) SOCKET_INTERNAL, (void*) &si, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*si != NULL_POINTER) {

        // Interrupt server socket service thread.
        interrupt_socket();

        // The server socket.
        int** s = (int**) &NULL_POINTER;
/*??
        // The client sockets.
        void** cs = NULL_POINTER;
        void** csc = NULL_POINTER;
        void** css = NULL_POINTER;
        // The activation flag.
        void** af = NULL_POINTER;
        // The signal ids.
        void** id = NULL_POINTER;
        void** idc = NULL_POINTER;
        void** ids = NULL_POINTER;
*/

        // Get server socket.
        get(p0, (void*) SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
/*??
        // Get client sockets.
        get(p0, (void*) SERVER_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) SERVER_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) SERVER_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get interrupt flag.
        get(p0, (void*) SOCKET_INTERRUPT_INTERNAL, (void*) &af, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal ids.
        get(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/

        // Close server socket.
        close(**s);

        // Destroy server socket.
        deallocate(s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
/*??
        // Destroy client sockets.
        deallocate_array((void*) cs, (void*) css, (void*) INTEGER_ARRAY);
        deallocate(csc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate(css, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Destroy activation flag.
        deallocate(af, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Destroy signal ids.
        deallocate_array((void*) id, (void*) ids, (void*) INTEGER_ARRAY);
        deallocate(idc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate(ids, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
*/

    } else {

        log_message_debug("WARNING: Could not shutdown socket. There is no server socket running.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* SHUTDOWN_SOCKET_SOURCE */
#endif
