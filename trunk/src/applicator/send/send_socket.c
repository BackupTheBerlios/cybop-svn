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
 * @version $Revision: 1.5 $ $Date: 2007-01-07 23:51:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SOCKET_SOURCE
#define SEND_SOCKET_SOURCE

#include <netinet/in.h>
#include <sys/socket.h>
#include "../../applicator/startup/startup_socket.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Sends a message via socket.
 *
 * @param p0 the internal memory
 * @param p1 the namespace model
 * @param p2 the namespace model count
 * @param p3 the style model
 * @param p4 the style model count
 * @param p5 the receiver socket file name or host address model, depending on the socket type (local, ipv4, ipv6)
 * @param p6 the receiver socket file name or host address model count
 * @param p7 the message abstraction
 * @param p8 the message abstraction count
 * @param p9 the message model
 * @param p10 the message model count
 * @param p11 the message details
 * @param p12 the message details count
 * @param p13 the base internal
 * @param p14 the knowledge memory
 * @param p15 the knowledge memory count
 */
void send_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p5 != NULL_POINTER) {

        int* base = (int*) p5;

        log_message_debug("Information: Send message via socket.");

        // The socket namespace.
        int sn = *INVALID_VALUE;
        // The address namespace.
        int an = *INVALID_VALUE;
        // The communication style.
        int st = *INVALID_VALUE;
        // The ipv4 host address.
        uint32_t ha4 = *INVALID_VALUE;
        // The ipv6 host address.
        struct in6_addr ha6 = in6addr_loopback; //?? IN6ADDR_LOOPBACK_INIT
        // The local socket address.
        // CAUTION! Do use a pointer here and not only the structure as type,
        // so that the different socket addresses can be processed uniformly below!
        struct sockaddr_un* la = NULL_POINTER;
        // The ipv4 internet socket address.
        // CAUTION! Do use a pointer here and not only the structure as type,
        // so that the different socket addresses can be processed uniformly below!
        struct sockaddr_in* ia4 = NULL_POINTER;
        // The ipv6 internet socket address.
        // CAUTION! Do use a pointer here and not only the structure as type,
        // so that the different socket addresses can be processed uniformly below!
        struct sockaddr_in6* ia6 = NULL_POINTER;
        // The socket address size.
        int as = *NUMBER_0_INTEGER;
        // The internal memory index.
        int i = *INVALID_VALUE;
        // The serialised string buffer array to be sent to the socket.
//??        void* b = NULL_POINTER;
        void* b = "close";
        int bc = 5; //?? *NUMBER_0_INTEGER;
        int bs = 5; //?? *NUMBER_0_INTEGER;
        // The socket mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) &NULL_POINTER;
        // The socket.
        //
        // CAUTION! Although this socket is used as client socket here,
        // it is also used as server socket for signal reception in the
        // "receive_socket" procedure.
        // However, this is not a problem, since a special socket mutex
        // is set whenever a message is sent or received via the socket.
        //
        // CAUTION! Do NOT create TWO sockets with identical parameters
        // (address, port etc.), one as "client-" and the other as "server" socket!
        // This is because identical sockets would conflict.
        void** s = &NULL_POINTER;
        // The result.
        int r = *INVALID_VALUE;

        // Get socket- and address namespace.
        startup_socket_get_namespace((void*) &sn, (void*) &an, p1, p2);
        // Get socket communication style.
        startup_socket_get_style((void*) &st, p3, p4);

        // Get host address constant.
        if (an == AF_INET) {

            startup_socket_get_ipv4_host_address((void*) &ha4, p5, p6);

        } else if (an == AF_INET6) {

            startup_socket_get_ipv6_host_address((void*) &ha6, p5, p6);
        }

        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get existing server socket of this system.
        //
        // In order to be able to send messages to a server socket,
        // this system needs a client socket to send from.
        // But since this system is a server owning a server socket itself,
        // that server socket is used as client socket here,
        // for sending a request to another (local or remote) server socket,
        // or even to itself, depending on the given receiver address.
        i = *base + *SOCKET_INTERNAL;
        get_array_elements(p0, (void*) &i, (void*) &s, (void*) POINTER_ARRAY);

        // Initialise socket address size.
        if (an == AF_LOCAL) {

            // CAUTION! The following line CANNOT be used:
            // *as = sizeof(struct sockaddr_un);
            // because the compiler brings the error
            // "invalid application of 'sizeof' to incomplete type 'struct sockaddr_un'".
            // The reason is the "sun_path" field of the "sockaddr_un" structure,
            // which is a character array whose size is unknown at compilation time.
            //
            // The size of the "sun_path" character array is therefore set
            // to the fixed size of 108.
            // The number "108" is the limit as set by the gnu c library!
            // Its documentation called it a "magic number" and does not
            // know why this limit exists.
            //
            // With the known type "short int" of the "sun_family" field and
            // a fixed size "108" of the "sun_path" field, the overall size of
            // the "sockaddr_un" structure can be calculated as sum.
            as = sizeof(short int) + 108;

        } else if (an == AF_INET) {

            as = sizeof(struct sockaddr_in);

        } else if (an == AF_INET6) {

            as = sizeof(struct sockaddr_in6);
        }

        // Allocate socket address.
        if (an == AF_LOCAL) {

            la = (struct sockaddr_un*) malloc(as);

        } else if (an == AF_INET) {

            ia4 = (struct sockaddr_in*) malloc(as);

        } else if (an == AF_INET6) {

            ia6 = (struct sockaddr_in6*) malloc(as);
        }

        // Initialise socket address.
        if (an == AF_LOCAL) {

            startup_socket_initialise_local_socket_address((void*) &la, p5, p6);

        } else if (an == AF_INET) {

            startup_socket_initialise_ipv4_socket_address((void*) &ia4, (void*) &ha4, p7);

        } else if (an == AF_INET6) {

            startup_socket_initialise_ipv6_socket_address((void*) &ia6, (void*) &ha6, p7);
        }

        // Allocate buffer array.
//??        allocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Serialise compound model into www service message buffer array.
//??        serialise(p0, NULL_POINTER, NULL_POINTER, p1, p2, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT);
//??        serialise_socket((void*) &b, (void*) &bc, (void*) &bs, p7, p8, p9, p10, p11, p12);
/*??
            encode_model((void*) &b, (void*) &bc, (void*) &bs,
                *ma, *mac, *mm, *mmc, *md, *mdc,
                (void*) HTML_ABSTRACTION, (void*) HTML_ABSTRACTION_COUNT, p3, p4);
*/

        // Check if sender- and receiver socket are identical.
        //
        // CAUTION! A deadlock may occur if this system sends a message to itself!
        // This is because the server socket of this system is locked when
        // a message is sent AND ALSO when a message is received.
        // Once the lock is set by the "send" procedure, the "receive" procedure
        // will wait endlessly for an unlock, since the "send" in turn waits for
        // the "receive" procedure to finish.
        //
        // Therefore, DO NOT allow a message to be sent to the system itself,
        // if the address, port etc. of sender and receiver system are IDENTICAL.
        // (If it is necessary to send a signal to the system itself,
        // then the "signal" channel for cyboi-internal signals should
        // be used instead of a socket.)
/*??
        check sender and receiver socket parameters here!

        if (identical == FALSE) {
*/

            // Lock socket mutex.
            pthread_mutex_lock(*mt);

            // Send message via socket.
            if (an == AF_LOCAL) {

//??                write_data(*s, NULL_POINTER, NULL_POINTER, b, (void*) &bc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT);
                write_socket((void*) la, NULL_POINTER, (void*) &as, b, (void*) &bc, *s, (void*) &st);

            } else if (an == AF_INET) {

//??                write_data(*s, NULL_POINTER, NULL_POINTER, b, (void*) &bc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT);
                write_socket((void*) ia4, NULL_POINTER, (void*) &as, b, (void*) &bc, *s, (void*) &st);

            } else if (an == AF_INET6) {

//??                write_data(*s, NULL_POINTER, NULL_POINTER, b, (void*) &bc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT);
                write_socket((void*) ia6, NULL_POINTER, (void*) &as, b, (void*) &bc, *s, (void*) &st);
            }

            // Unlock socket mutex.
            pthread_mutex_unlock(*mt);

/*??
        --
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

/*??
    } else {

        log_message_debug("Error: Could not send message via socket. The sender- and receiver socket are identical. The system MUST NOT send messages to itself since then, a socket deadlock would occur. Use the 'signal' channel instead of a socket to send cyboi-internal signals!");
    }
*/

        // Deallocate buffer array.
//??        deallocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Deallocate socket address.
        if (an == AF_LOCAL) {

            free(la);

        } else if (an == AF_INET) {

            free(ia4);

        } else if (an == AF_INET6) {

            free(ia6);
        }

    } else {

        log_message_debug("Error: Could not send message via socket. The base internal is null.");
    }
}

/* SEND_SOCKET_SOURCE */
#endif
