/*
 * $RCSfile: startup_tcp_socket.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-04-07 16:22:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_TCP_SOCKET_SOURCE
#define STARTUP_TCP_SOCKET_SOURCE

#include "../../global/structure_constants.c"
#include "../../global/variables.c"

/**
 * Starts up the tcp socket service.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_tcp_socket(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Startup tcp socket.");

    // The tcp socket internal.
    int** s = -1;

    // Get tcp socket internal.
    get_array_elements(p0, (void*) TCP_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);

    if (**s == -1) {

        //?? TODO Rolf! Put all code for tcp socket startup here!
        
        set_array_elements(p0, (void*) TCP_SOCKET_INTERNAL, (void*) &s, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("WARNING: Could not startup tcp socket. The tcp socket service is already running.");
    }
}

/* STARTUP_TCP_SOCKET_SOURCE */
#endif
