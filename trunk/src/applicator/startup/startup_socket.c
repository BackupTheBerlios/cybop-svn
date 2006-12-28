/*
 * $RCSfile: startup_socket.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2006-12-28 16:04:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STARTUP_SOCKET_SOURCE
#define STARTUP_SOCKET_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

/**
 * Gets the socket- and address namespace.
 *
 * @param p0 the socket namespace (Hand over as reference!)
 * @param p1 the address namespace (Hand over as reference!)
 * @param p2 the namespace model
 * @param p3 the namespace model count
 */
void startup_socket_get_namespace(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != NULL_POINTER) {

        int* an = (int*) p1;

        if (p0 != NULL_POINTER) {

            int* sn = (int*) p0;

            log_message_debug("Startup socket get namespace.");

            // The comparison result.
            int r = 0;

            if (r == 0) {

                compare_arrays(p2, p3, (void*) LOCAL_NAMESPACE_MODEL, (void*) LOCAL_NAMESPACE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *sn = PF_LOCAL;
                    *an = AF_LOCAL;
                }
            }

            if (r == 0) {

                compare_arrays(p2, p3, (void*) INET_NAMESPACE_MODEL, (void*) INET_NAMESPACE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *sn = PF_INET;
                    *an = AF_INET;
                }
            }

            if (r == 0) {

                compare_arrays(p2, p3, (void*) INET6_NAMESPACE_MODEL, (void*) INET6_NAMESPACE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *sn = PF_INET6;
                    *an = AF_INET6;
                }
            }

        } else {

            log_message_debug("Could not get namespace. The socket namespace is null.");
        }

    } else {

        log_message_debug("Could not get namespace. The address namespace is null.");
    }
}

/**
 * Gets the communication style.
 *
 * @param p0 the communication style (Hand over as reference!)
 * @param p1 the communication style model
 * @param p2 the communication style model count
 */
void startup_socket_get_style(void* p0, void* p1, void* p2) {

    if (p0 != NULL_POINTER) {

        int* s = (int*) p0;

        log_message_debug("Startup socket get style.");

        // The comparison result.
        int r = 0;

        if (r == 0) {

            compare_arrays(p1, p2, (void*) STREAM_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *s = SOCK_STREAM;
            }
        }

        if (r == 0) {

            compare_arrays(p1, p2, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *s = SOCK_DGRAM;
            }
        }

        if (r == 0) {

            compare_arrays(p1, p2, (void*) RAW_COMMUNICATION_STYLE_MODEL, (void*) RAW_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *s = SOCK_RAW;
            }
        }

    } else {

        log_message_debug("Could not get style. The communication style is null.");
    }
}

/**
 * Gets the ipv4 host address.
 *
 * @param p0 the ipv4 host address (Hand over as reference!)
 * @param p1 the address model
 * @param p2 the address model count
 */
void startup_socket_get_ipv4_host_address(void* p0, void* p1, void* p2) {

    if (p0 != NULL_POINTER) {

        int* a = (int*) p0;

        log_message_debug("Startup socket get ipv4 host address.");

        // The comparison result.
        int r = 0;

        if (r == 0) {

            compare_arrays(p1, p2, (void*) LOOPBACK_ADDRESS_MODEL, (void*) LOOPBACK_ADDRESS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *a = INADDR_LOOPBACK;
            }
        }

        if (r == 0) {

            compare_arrays(p1, p2, (void*) ANY_ADDRESS_MODEL, (void*) ANY_ADDRESS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *a = INADDR_ANY;
            }
        }

    } else {

        log_message_debug("Could not get ipv4 host address. The ipv4 host address is null.");
    }
}

/**
 * Gets the ipv6 host address.
 *
 * @param p0 the ipv6 host address (Hand over as reference!)
 * @param p1 the address model
 * @param p2 the address model count
 */
void startup_socket_get_ipv6_host_address(void* p0, void* p1, void* p2) {

    if (p0 != NULL_POINTER) {

        struct in6_addr* a = (struct in6_addr*) p0;

        log_message_debug("Startup socket get ipv6 host address.");

        // The comparison result.
        int r = 0;

        if (r == 0) {

            compare_arrays(p1, p2, (void*) LOOPBACK_ADDRESS_MODEL, (void*) LOOPBACK_ADDRESS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *a = in6addr_loopback; //?? IN6ADDR_LOOPBACK_INIT
            }
        }

        if (r == 0) {

            compare_arrays(p1, p2, (void*) ANY_ADDRESS_MODEL, (void*) ANY_ADDRESS_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                *a = in6addr_any; //?? IN6ADDR_ANY_INIT
            }
        }

    } else {

        log_message_debug("Could not get ipv6 host address. The ipv6 host address is null.");
    }
}

/**
 * Initialises the local socket address.
 *
 * @param p0 the local socket address (Hand over as reference!)
 * @param p1 the file name
 * @param p2 the file name count
 */
void startup_socket_initialise_local_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* fc = (int*) p2;

        if (p1 != NULL_POINTER) {

            char* f = (char*) p1;

            if (p0 != NULL_POINTER) {

                struct sockaddr_un** a = (struct sockaddr_un**) p0;

                log_message_debug("Startup socket initialise local socket address.");

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                (*a)->sun_family = AF_LOCAL;

                // The terminated file name.
                char* t = NULL_POINTER;
                int ts = *fc + NUMBER_1_INTEGER;

                if

                // Set file name.
                //
                // CAUTION! For some strange reason, the file name's length is
                // limited to 108 ascii characters in the GNU C library!
                (*a)->sun_path = f;

            } else {

                log_message_debug("Error: Could not initialise local socket address. The socket address is null.");
            }

        } else {

            log_message_debug("Error: Could not initialise local socket address. The file name is null.");
        }

    } else {

        log_message_debug("Error: Could not initialise local socket address. The file name count is null.");
    }
}

/**
 * Initialises the ipv4 socket address.
 *
 * @param p0 the ipv4 socket address (Hand over as reference!)
 * @param p1 the host address
 * @param p2 the socket port
 */
void startup_socket_initialise_ipv4_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* p = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* h = (int*) p1;

            if (p0 != NULL_POINTER) {

                struct sockaddr_in** a = (struct sockaddr_in**) p0;

                log_message_debug("Startup socket initialise ipv4 socket address.");

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                (*a)->sin_family = AF_INET;

                // Set host address.
                //
                // CAUTION! The address MUST BE represented in a canonical
                // format called "network byte order".
                //
                // The "a.sin_addr" field is of type "struct in_addr".
                // This data type is used in certain contexts to contain an IPv4 internet host address.
                // It has just one field, named "s_addr", which records the host address number as an "uint32_t".
                //
                // CAUTION! Convert uint16_t integer hostshort from host byte order
                // to network byte order:
                // - "htons" and "ntohs" to convert values for the sin_port member
                // - "htonl" and "ntohl" to convert IPv4 addresses for the sin_addr member
//??                inet_aton(ipv4, (struct in_addr*) &((*a)->sin_addr));
                (*a)->sin_addr.s_addr = *h;

                // Set socket port.
                //
                // CAUTION! The port number MUST BE represented in a canonical
                // format called "network byte order".
//??                a->sin_port = htons(*((uint16_t*) p6));
                (*a)->sin_port = *p;

            } else {

                log_message_debug("Error: Could not initialise ipv4 socket address. The socket address is null.");
            }

        } else {

            log_message_debug("Error: Could not initialise ipv4 socket address. The host address is null.");
        }

    } else {

        log_message_debug("Error: Could not initialise ipv4 socket address. The socket port is null.");
    }
}

/**
 * Initialises the ipv6 socket address.
 *
 * @param p0 the ipv6 socket address (Hand over as reference!)
 * @param p1 the host address
 * @param p2 the socket port
 */
void startup_socket_initialise_ipv6_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* p = (int*) p2;

        if (p1 != NULL_POINTER) {

            struct in6_addr* h = (struct in6_addr*) p1;

            if (p0 != NULL_POINTER) {

                struct sockaddr_in6** a = (struct sockaddr_in6**) p0;

                log_message_debug("Startup socket initialise ipv6 socket address.");

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                (*a)->sin_family = AF_INET6;

                // Set host address.
                //
                // CAUTION! The address MUST BE represented in a canonical
                // format called "network byte order".
                //
                // The "a.sin_addr" field is of type "struct in_addr".
                // This data type is used in certain contexts to contain an IPv4 internet host address.
                // It has just one field, named "s_addr", which records the host address number as an "uint32_t".
                //
                // CAUTION! Convert uint16_t integer hostshort from host byte order
                // to network byte order:
                // - "htons" and "ntohs" to convert values for the sin_port member
                // - "htonl" and "ntohl" to convert IPv4 addresses for the sin_addr member
//??                inet_aton(htonl(INADDR_ANY), (struct in_addr*) &(a->sin_addr));
//??                inet_aton(ipv6, (struct in_addr*) &((*a)->sin_addr));
                (*a)->sin_addr = *h;

                // Set socket port.
                //
                // CAUTION! The port number MUST BE represented in a canonical
                // format called "network byte order".
//??                a->sin_port = htons(*((uint16_t*) p6));
                (*a)->sin_port = *p;

            } else {

                log_message_debug("Error: Could not initialise ipv6 socket address. The socket address is null.");
            }

        } else {

            log_message_debug("Error: Could not initialise ipv6 socket address. The host address is null.");
        }

    } else {

        log_message_debug("Error: Could not initialise ipv6 socket address. The socket port is null.");
    }
}

/**
 * Starts up socket.
 *
 * @param p0 the internals memory
 * @param p1 the namespace model
 * @param p2 the namespace model count
 * @param p3 the style model
 * @param p4 the style model count
 * @param p5 the host address model
 * @param p6 the host address model count
 * @param p7 the port model
 * @param p8 the base internal
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the knowledge memory size
 */
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    if (p8 != NULL_POINTER) {

        int* base = (int*) p8;

        log_message_debug("Startup socket.");

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
        // The server socket.
        int* s = NULL_POINTER;
        // The local socket address.
        struct sockaddr_un* la = NULL_POINTER;
        // The ipv4 internet socket address.
        struct sockaddr_in* ia4 = NULL_POINTER;
        // The ipv6 internet socket address.
        struct sockaddr_in6* ia6 = NULL_POINTER;
        // The socket address size.
        int* as = NULL_POINTER;
/*??
        // The client sockets.
        void* cs = NULL_POINTER;
        int* csc = NULL_POINTER;
        int* css = NULL_POINTER;
*/
        // The character buffer that will be used in the thread procedure.
        void* b = NULL_POINTER;
        int* bc = NULL_POINTER;
        int* bs = NULL_POINTER;
        // The blocking flag.
        int* bf = NULL_POINTER;
/*??
        // The signal ids.
        void* id = NULL_POINTER;
        int* idc = NULL_POINTER;
        int* ids = NULL_POINTER;
*/
        // The internal memory index.
        int i = *INVALID_VALUE;

        // Get socket- and address namespace.
        startup_socket_get_namespace((void*) &sn, (void*) &an, p1, p2);
        // Get socket communication style.
        startup_socket_get_style((void*) &st, p3, p4);

        // Get host address constant.
        if (*an == AF_INET) {

            startup_socket_get_ipv4_host_address((void*) &ha4, p5, p6);

        } else if (*an == AF_INET6) {

            startup_socket_get_ipv6_host_address((void*) &ha6, p5, p6);
        }

        // Allocate server socket.
        allocate((void*) &s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Allocate socket address size.
        allocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
/*??
        // Allocate client sockets.
        allocate((void*) &csc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &css, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate_array((void*) &cs, (void*) css, (void*) INTEGER_ARRAY);
*/
        // Allocate character buffer count, size.
        allocate((void*) &bc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &bs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        // Allocate blocking flag.
        allocate((void*) &bf, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
/*??
        // Allocate signal ids.
        allocate((void*) &idc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &ids, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY);
*/

        // Initialise server socket.
        //
        // param 0: namespace
        // param 1: style
        // param 2: protocol
        //
        // CAUTION! Use "PF_INET" here and NOT "AF_INET"!
        // The latter is to be used for address family assignment.
        // See further below!
        *s = socket(sn, st, *NUMBER_0_INTEGER);

        // Initialise socket address size.
        if (*an == AF_LOCAL) {

            *as = sizeof(struct sockaddr_un);

        } else if (*an == AF_INET4) {

            *as = sizeof(struct sockaddr_in);

        } else if (*an == AF_INET6) {

            *as = sizeof(struct sockaddr_in6);
        }

/*??
        // Initialise client sockets.
        *csc = *NUMBER_0_INTEGER;
        *css = *NUMBER_0_INTEGER;
*/
        // Initialise character buffer count, size.
        // Its size is initialised with 2048,
        // which should suffice for transferring standard data over tcp/ip.
        *bc = *NUMBER_0_INTEGER;
        *bs = 2048;
        // Initialise blocking flag.
        *bf = *NUMBER_0_INTEGER;
/*??
        // Initialise signal ids.
        *idc = *NUMBER_0_INTEGER;
        *ids = *NUMBER_0_INTEGER;
*/

        // Allocate socket address.
        if (*an == AF_LOCAL) {

            la = (struct sockaddr_un*) malloc(*as);

        } else if (*an == AF_INET4) {

            ia4 = (struct sockaddr_in*) malloc(*as);

        } else if (*an == AF_INET6) {

            ia6 = (struct sockaddr_in6*) malloc(*as);
        }

        // Allocate character buffer.
        allocate((void*) &b, (void*) bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Initialise socket address.
        if (*an == AF_LOCAL) {

            startup_socket_initialise_local_socket_address((void*) &la, (void*) &ha4, p7);

        } else if (*an == AF_INET4) {

            startup_socket_initialise_ipv4_socket_address((void*) &ia4, (void*) &ha4, p7);

        } else if (*an == AF_INET6) {

            startup_socket_initialise_ipv6_socket_address((void*) &ia6, (void*) &ha6, p7);
        }

        // Set server socket.
        i = *base + *SERVER_SOCKET_INTERNAL;
        set(p0, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Set socket address.
        i = *base + *SERVER_SOCKET_ADDRESS_INTERNAL;
        set(p0, (void*) &i, (void*) &a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SERVER_SOCKET_ADDRESS_SIZE_INTERNAL;
        set(p0, (void*) &i, (void*) &as, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
/*??
        // Set client sockets.
        set(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/
        i = *base + *SERVER_SOCKET_THREAD_CHARACTER_BUFFER_INTERNAL;
        set(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SERVER_SOCKET_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL;
        set(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SERVER_SOCKET_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL;
        set(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Set blocking flag.
//??        set(p0, (void*) SERVER_SOCKET_BLOCKING_INTERNAL, (void*) &bf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
/*??
        // Set signal ids.
        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/

        if (*s >= *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST: The server socket is: %d \n", *s);

            // Bind socket number to socket address.
            int r = bind(*s, (struct sockaddr*) a, *((socklen_t*) as));

            if (r >= *NUMBER_0_INTEGER) {

                if (st == SOCK_STREAM) {

                    // CAUTION! Datagram sockets do NOT have connections,
                    // which is why the "listen" procedure is only called
                    // for stream sockets here.

    fprintf(stderr, "TEST: pre listen: %d \n", *s);
                    // Enable socket to accept connections, thus making it a server socket.
                    // The second parameter determines the number of possible
                    // pending client connection requests.
                    listen(*s, *NUMBER_1_INTEGER);
    fprintf(stderr, "TEST: post listen: %d \n", *s);
                }

            } else {

                log_message_debug("Error: Could not start up socket. The socket could not be bound to the address.");
            }

        } else {

            log_message_debug("Error: Could not start up socket. The socket could not be created.");
        }

    } else {

        log_message_debug("Error: Could not start up socket. The base internal is null.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* STARTUP_SOCKET_SOURCE */
#endif
