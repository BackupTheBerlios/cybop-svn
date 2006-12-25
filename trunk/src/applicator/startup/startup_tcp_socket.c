/*
 * $RCSfile: startup_tcp_socket.c,v $
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
 * @version $Revision: 1.18 $ $Date: 2006-12-25 12:41:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STARTUP_TCP_SOCKET_SOURCE
#define STARTUP_TCP_SOCKET_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

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
 * @param p0 the internals memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the socket port abstraction
 * @param p5 the socket port abstraction count
 * @param p6 the socket port model
 * @param p7 the socket port model count
 */
void startup_tcp_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_debug("Startup tcp socket.");

    // The tcp server socket internal.
    int** si = (int**) &NULL_POINTER;

    // Get tcp server socket internal.
    get(p0, (void*) TCP_SOCKET_INTERNAL, (void*) &si, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (*si == NULL_POINTER) {

    fprintf(stderr, "TEST: The tcp socket port abstraction is: %s \n", (char*) p4);
    fprintf(stderr, "TEST: The tcp socket port abstraction count is: %i \n", *((int*) p5));
    fprintf(stderr, "TEST: The tcp socket port model is: %i \n", **((int**) p6));
    fprintf(stderr, "TEST: The tcp socket port model count is: %i \n", *((int*) p7));

        // The tcp server socket.
        int* s = NULL_POINTER;
        // The tcp client sockets.
        void* cs = NULL_POINTER;
        int* csc = NULL_POINTER;
        int* css = NULL_POINTER;
        // The character buffer that will be used in the thread procedure.
        void* b = NULL_POINTER;
        int* bc = NULL_POINTER;
        int* bs = NULL_POINTER;
        // The blocking flag.
        int* bf = NULL_POINTER;
        // The tcp signal ids.
        void* id = NULL_POINTER;
        int* idc = NULL_POINTER;
        int* ids = NULL_POINTER;
        // The error code.
        int e = *NUMBER_0_INTEGER;

        //?? TODO: TCP interrupt flag.

        // Allocate tcp server socket.
        allocate((void*) &s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Allocate tcp client sockets.
        allocate((void*) &csc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &css, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate_array((void*) &cs, (void*) css, (void*) INTEGER_ARRAY);
        // Allocate character buffer count, size.
        allocate((void*) &bc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &bs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Allocate blocking flag.
        allocate((void*) &bf, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Allocate tcp signal ids.
        allocate((void*) &idc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &ids, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY);

        // Initialise tcp server socket.
        // param 0: namespace
        // param 1: style
        // param 2: protocol
        *s = socket(PF_INET, SOCK_STREAM, *NUMBER_0_INTEGER);
        // Initialise tcp client sockets.
        *csc = *NUMBER_0_INTEGER;
        *css = *NUMBER_0_INTEGER;
        // Initialise character buffer count, size.
        // Its size is initialised with 2048,
        // which should suffice for transferring standard data over tcp/ip.
        *bc = *NUMBER_0_INTEGER;
        *bs = 2048;
        // Initialise blocking flag.
        *bf = *NUMBER_0_INTEGER;
        // Initialise tcp signal ids.
        *idc = *NUMBER_0_INTEGER;
        *ids = *NUMBER_0_INTEGER;

        // Allocate character buffer.
        allocate((void*) &b, (void*) bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Set tcp server socket.
        set(p0, (void*) TCP_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Set tcp client sockets.
        set(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_SOCKET_THREAD_CHARACTER_BUFFER_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_SOCKET_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_SOCKET_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Set tcp blocking flag.
        set(p0, (void*) TCP_SOCKET_BLOCKING_INTERNAL, (void*) &bf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Set tcp signal ids.
        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if (*s >= *NUMBER_0_INTEGER) {

            fprintf(stderr, "DEBUG: The tcp server socket is: %d \n", *s);

            // The socket address.
            struct sockaddr_in a;

            // CAUTION! Since the address is a structure and not a pointer,
            // a check for null is NOT necessary here!

            // Set address format.
            //
            // CAUTION! Convert uint16_t integer hostshort from host byte order
            // to network byte order:
            // - "htons" and "ntohs" to convert values for the sin_port member
            // - "htonl" and "ntohl" to convert IPv4 addresses for the sin_addr member
            // (Remember, struct in_addr is equivalent to uint32_t.)
            //
            a.sin_family = AF_INET;
            a.sin_addr.s_addr = inet_addr("127.0.0.1"); //?? htonl(INADDR_ANY);
            a.sin_port = 3456; //?? htons(*((uint16_t*) p6));

            // Determine socket address size.
            socklen_t as = sizeof(struct sockaddr_in);

            // Bind socket number to socket address.
            e = bind(*s, (struct sockaddr*) &a, as);

            if (e >= *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST: pre listen: %d \n", *s);
                // Enable socket to accept connections, thus making it a server socket.
                // The second parameter determines the number of possible
                // pending client connection requests.
                listen(*s, *NUMBER_1_INTEGER);
    fprintf(stderr, "TEST: post listen: %d \n", *s);

            } else {

                log_message_debug("ERROR: Could not start up tcp socket. The tcp socket could not be bound to the address.");
            }

        } else {

            log_message_debug("ERROR: Could not start up tcp socket. The tcp socket could not be created.");
        }

    } else {

        log_message_debug("WARNING: Could not start up tcp socket. The tcp socket is already running.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* STARTUP_TCP_SOCKET_SOURCE */
#endif
