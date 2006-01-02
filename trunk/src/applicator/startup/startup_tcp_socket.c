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
 * @version $Revision: 1.14 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_TCP_SOCKET_SOURCE
#define STARTUP_TCP_SOCKET_SOURCE

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
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

/**
 * Starts up the tcp socket.
 *
 * @param internals the internal memory
 * @param know the knowledge memory
 * @param know_count the knowledge memory count
 * @param know_size the knowledge memory size
 * @param socket_port_abstr the socket port abstraction
 * @param socket_port_abstr_count the socket port abstraction count
 * @param socket_port_model the socket port model
 * @param socket_port_model_count the socket port model count
 */
void startup_tcp_socket(void* internals, void* know, void* know_count, void* know_size,
    void* socket_port_abstr, void* socket_port_abstr_count, void* socket_port_model, void* socket_port_model_count) {

    log_message_debug("Startup tcp socket.");

    //check of null pointer
    if ((internals != NULL_POINTER)
         && (know != NULL_POINTER)
         && (know_count != NULL_POINTER)
         && (know_size != NULL_POINTER)
         && (socket_port_abstr != NULL_POINTER)
         && (socket_port_abstr_count != NULL_POINTER)
         && (socket_port_model != NULL_POINTER)
         && (socket_port_model_count != NULL_POINTER)) {

        int res = 0;

        //check the socket port of integer
        compare_arrays( (void*) socket_port_abstr,
                        (void*) socket_port_abstr_count,
                        (void*) INTEGER_VECTOR_ABSTRACTION,
                        (void*) INTEGER_VECTOR_ABSTRACTION_COUNT,
                        (void*) &res, (void*) CHARACTER_ARRAY);

        if ( res == 1 ) {

            log_message_debug("Allocate tcp server socket.");

            fprintf(stderr, "DEBUG: The port is: %d \n", *(int*) socket_port_model);

            // The tcp server socket.
            int* s = NULL_POINTER;
            // The tcp client sockets.
            void* cs = NULL_POINTER;
            int* csc = NULL_POINTER;
            int* css = NULL_POINTER;
            // The activation flag.
            int* af = NULL_POINTER;
            // The blocking flag.
            int* bf = NULL_POINTER;
            // The tcp signal ids.
            void* id = NULL_POINTER;
            int* idc = NULL_POINTER;
            int* ids = NULL_POINTER;

            // Create tcp server socket.
            allocate((void*) &s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *s = socket(PF_INET, SOCK_STREAM, 0);
            // Create tcp client sockets.
            allocate((void*) &csc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *csc = 0;
            allocate((void*) &css, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *css = 0;
            allocate_array((void*) &cs, (void*) css, (void*) INTEGER_ARRAY);
            // Create activation flag.
            allocate(&af, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *af = 0;
            // Create blocking flag.
            allocate(&bf, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *bf = 0;
            // Create tcp signal ids.
            allocate((void*) &idc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *idc = 0;
            allocate((void*) &ids, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *ids = 0;
            allocate_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY);

            // Set server socket.
            set(internals, (void*) TCP_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Set client sockets.
            set(internals, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set(internals, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set(internals, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Set interrupt flag.
            set(internals, (void*) TCP_SOCKET_INTERRUPT_INTERNAL, (void*) &af, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Set blocking flag.
            set(internals, (void*) TCP_SOCKET_BLOCKING_INTERNAL, (void*) &bf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Set tcp signal ids.
            set(internals, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set(internals, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            set(internals, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            if (*s >= 0) {

                fprintf(stderr, "DEBUG: The tcp server socket is: %d \n", *s);

                // The socket address.
                struct sockaddr_in a;

                // Set address format.
                a.sin_family = AF_INET;
                a.sin_addr.s_addr = INADDR_ANY;
                a.sin_port = htons(*((int*)socket_port_model) );

                // Determine socket address size.
                int as = sizeof(struct sockaddr_in);

                // Bind number to address.
                if (bind(*s, (struct sockaddr*) &a, as) >= 0) {

                    // Set the number of possible pending client connection requests.
                    listen(*s, 1);

                } else {

                    log_message_debug("ERROR: Could not start up tcp socket. The socket could not be bound to the address.");
                }

            } else {

                log_message_debug("ERROR: Could not start up tcp socket. The socket is smaller than zero.");
            }
        }

    } else {

        log_message_debug("ERROR: Could not start up tcp socket. The socket port is null.");
    }
}

/* STARTUP_TCP_SOCKET_SOURCE */
#endif
