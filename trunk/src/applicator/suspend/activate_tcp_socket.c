/*
 * $RCSfile: activate_tcp_socket.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2005-08-11 22:33:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ACTIVATE_TCP_SOCKET_SOURCE
#define ACTIVATE_TCP_SOCKET_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"

/**
 * Starts up the tcp socket service.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void activate_tcp_socket( void* internals, void* know, void* know_count, void* know_size,
    void* socket_port_abstr, void* socket_port_abstr_count,
    void* socket_port_model, void* socket_port_model_count) {

    log_message_debug("Startup tcp socket.");

    // Check of null pointer.
    if (internals != NULL_POINTER) {

        //set the activation flahg in the internal
        int** socket_flag = &NULL_POINTER;

        get(internals, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &socket_flag, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if ((socket_flag != NULL_POINTER) && (*socket_flag != NULL_POINTER)) {

            **socket_flag = 1;
        }

    } else {

        log_message_debug("Could not activate tcp server socket. The internal is null.");
    }
}

/* ACTIVATE_TCP_SOCKET_SOURCE */
#endif
