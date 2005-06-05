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
 * @version $Revision: 1.3 $ $Date: 2005-06-05 11:12:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SHUTDOWN_TCP_SOCKET_SOURCE
#define SHUTDOWN_TCP_SOCKET_SOURCE

#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memory/array/array.c"

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

    // The tcp socket internal.
    int** s = NULL_POINTER;

    // Get tcp socket internal.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);

    if (*s != NULL_POINTER) {

        //?? TODO Rolf! Put all code for tcp socket shutdown here!
        close ( *((int*)*s) );

        //set the activation flag in the internal
        void** socket_flag = POINTER_NULL_POINTER;
        get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &socket_flag, (void*) POINTER_ARRAY);
        if ( (socket_flag!=NULL_POINTER) && (*socket_flag!=NULL_POINTER) ) {

            *((int*)*socket_flag) = 0;
        }


    } else {

        log_message_debug("WARNING: Could not shutdown tcp socket. There is no tcp socket service running.");
    }
}

/* SHUTDOWN_TCP_SOCKET_SOURCE */
#endif
