/*
 * $RCSfile: send_socket.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2006-12-30 21:55:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SOCKET_SOURCE
#define SEND_SOCKET_SOURCE

#include <netinet/in.h>
#include <sys/socket.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Sends a message via socket.
 *
 * @param p0 the internal memory
 * @param p1 the source gui compound model ??
 * @param p2 the source count ??
 * @param p1 the receiver abstraction
 * @param p2 the receiver abstraction count
 * @param p3 the receiver model
 * @param p4 the receiver model count
 * @param p5 the receiver details
 * @param p6 the receiver details count
 * @param p7 the source wui abstraction
 * @param p8 the source wui abstraction count
 * @param p9 the source wui model (root compound model)
 * @param p10 the source wui model count
 * @param p11 the source wui details (meta properties of root compound model)
 * @param p12 the source wui details count
 * @param p13 the base internal
 * @param p14 the knowledge memory
 * @param p15 the knowledge memory count
 */
void send_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p5 != NULL_POINTER) {

        int* base = (int*) p5;

        // The internal memory index.
        int i = *INVALID_VALUE;
        // The serialised string buffer array to be sent to the socket.
//??        void* b = NULL_POINTER;
        void* b = "close";
        int bc = *NUMBER_0_INTEGER;
        int bs = *NUMBER_0_INTEGER;
        // The socket mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) &NULL_POINTER;

        log_message_debug("Information: Send message via socket.");

        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Allocate buffer array.
        allocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Serialise compound model into www service message buffer array.
//??        serialise(p0, NULL_POINTER, NULL_POINTER, p1, p2, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, p3, p4);
//??        serialise_socket((void*) &b, (void*) &bc, (void*) &bs, p1, p2, p3, p4, p5, p6, NULL_POINTER, NULL_POINTER, p7, p8, p11, p12);
/*??
            encode_model((void*) &b, (void*) &bc, (void*) &bs,
                *ma, *mac, *mm, *mmc, *md, *mdc,
                (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT, p3, p4);
*/

        // The socket.
        //
        // CAUTION! Although this socket is used as client socket here, it is also
        // used as server socket for signal reception in the "receive_socket" procedure.
        // However, this is not a problem, since a special socket mutex is set
        // whenever a message is sent or received via the socket.
        void** s = &NULL_POINTER;

        // Get socket.
        i = *base + *SOCKET_INTERNAL;
        get_array_elements(p0, (void*) &i, (void*) &s, (void*) POINTER_ARRAY);

    fprintf(stderr, "TEST: send socket s: %i \n", *((int*) *s));

        // Lock socket mutex.
        pthread_mutex_lock(*mt);

/*??
        // Send message via socket.
        write_data(s, NULL_POINTER, NULL_POINTER, b, bc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT);

        // Send message to client.
        // If the flags argument (fourth one) is zero, then one can
        // just as well use the "write" instead of the "send" procedure.
        // If the socket is nonblocking, then "send" (like "write")
        // can return after sending just PART OF the data.
        // Note, however, that a successful return value merely indicates that the
        // message has been sent without error, not necessarily that it has been
        // received without error.
        bc = send(cs, b, bs, *NUMBER_0_INTEGER);
*/

        // Unlock socket mutex.
        pthread_mutex_unlock(*mt);

        // Deallocate buffer array.
        deallocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

/*??
    --
        // The remote socket address.
        struct sockaddr_in a = NULL_POINTER;
        int as = NULL_POINTER;

        // Initialise client socket address size.
        as = sizeof(struct sockaddr_in);

        // Initialise socket address.
        //
        // CAUTION! Convert uint16_t integer hostshort from host byte order
        // to network byte order:
        // - "htons" and "ntohs" to convert values for the sin_port member
        // - "htonl" and "ntohl" to convert IPv4 addresses for the sin_addr member

        // CAUTION! Use "AF_INET" here and NOT "PF_INET"!
        // The latter is to be used for socket creation.
        // See further above!
        a.sin_family = AF_INET;
        // The "a.sin_addr" field is of type "struct in_addr".
        // This data type is used in certain contexts to contain an IPv4 internet host address.
        // It has just one field, named "s_addr", which records the host address number as an "uint32_t".
//??        inet_aton(htonl(INADDR_ANY), (struct in_addr*) &(a->sin_addr));
        inet_aton("127.0.0.1", (struct in_addr*) &(a.sin_addr));
//??        a->sin_port = htons(*((uint16_t*) p6));
        a.sin_port = 3456;

        // Connect client socket "cs" to the server socket whose address is
        // specified by the "a" and "as" arguments.
        int r = connect(cs, (struct sockaddr*) &a, *((socklen_t*) &as));

        if (r >= *NUMBER_0_INTEGER) {

            // The socket number for the signal id.
            // The index for the signal id in the array is the same index
            // in the client socket number array.
            int i = -1;

            get_index_for_signal_id(p2, p9, (void*) &i);

            if (i >= 0) {

                // The client socket.
                int* cs = NULL_POINTER;

                get_client_socket_number_for_index(p2, (void*) &i, (void*) &cs);

                if (*cs >= 0) {

        } else {

            log_message_debug("Could not send message via socket. The send operation failed.");
        }

                // Remove client socket number and main signal id from internal memory.
                remove_relation_clientsocketnumber_mainsignalid(p2, (void*) &i);

                // Close client socket.
                close(*cs);

            } else {

                log_message_debug("Could not send message via socket. The client socket number was not found.");
            }

        } else {

            log_message_debug("Could not send message via socket. The signal id index is invalid.");
        }
    */

    } else {

        log_message_debug("Error: Could not send message via socket. The base internal is null.");
    }
}

/* SEND_SOCKET_SOURCE */
#endif
