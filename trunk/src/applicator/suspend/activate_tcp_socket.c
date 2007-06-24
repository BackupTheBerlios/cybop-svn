/*
 * $RCSfile: activate_tcp_socket.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.13 $ $Date: 2007-06-24 15:02:21 $ $Author: christian $
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
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
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

    if (internals != *NULL_POINTER) {

        // The tcp socket interrupt flag.
        int** f = (int**) NULL_POINTER;

//??        get_element(internals, (void*) TCP_SOCKET_INTERRUPT_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if ((f != *NULL_POINTER) && (*f != *NULL_POINTER)) {

            // Deactivate interrupt flag, since tcp socket is to be started.
            **f = 0;
        }

    } else {

        log_message_debug("Could not activate tcp server socket. The internal is null.");
    }
}

/* ACTIVATE_TCP_SOCKET_SOURCE */
#endif
