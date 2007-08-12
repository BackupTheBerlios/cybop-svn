/*
 * $RCSfile: send_socket.c,v $
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
 * @version $Revision: 1.20 $ $Date: 2007-08-12 23:31:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_SOCKET_SOURCE
#define SEND_SOCKET_SOURCE

//?? TEST for test file
#include <fcntl.h>
#include <sys/stat.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include "../../applicator/startup/startup_socket.c"
#include "../../globals/constants/character/character_set_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/http/http_header_constants.c"
#include "../../globals/constants/http/http_header_variable_constants.c"
#include "../../globals/constants/http/http_protocol_version_constants.c"
#include "../../globals/constants/http/http_status_code_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/mime_type/text_mime_type_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Gets the socket for server mode.
 *
 * Server mode means that this system was asked by a client system,
 * that it now needs to reply to.
 *
 * @param p0 the socket of this system (Hand over as reference!)
 * @param p1 the internal memory
 * @param p2 the base internal
 */
void send_socket_get_socket_server_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* base = (int*) p2;

        log_message_debug("Information: Get socket for server mode.");

        // The internal memory index.
        int i = *INVALID_VALUE;
        // The socket mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;

/*??
        ONLY necessary when writing or deleting a socket from internal memory.
        This may become necessary if many sockets are hold in a queue, soon to be implemented.

        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get_element(p1, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/
        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
        get_element(p1, (void*) &i, p0, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("Error: Could not send message via socket get socket for server mode. The base internal is null.");
    }
}

/**
 * Gets the socket for client mode.
 *
 * Client mode means that this system acts as client asking a server system,
 * which is its (local or remote) communication partner.
 *
 * @param p0 the socket of this system (Hand over as reference!)
 * @param p1 the socket namespace
 * @param p2 the communication style
 */
void send_socket_get_socket_client_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* st = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* sn = (int*) p1;

            if (p0 != *NULL_POINTER) {

                int*** s = (int***) p0;

                log_message_debug("Information: Get socket for client mode.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER;

                // Initialise server socket.
                //
                // param 0: namespace
                // param 1: style
                // param 2: protocol
                //
                // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                // The latter is to be used for address family assignment.
                // See further below!
                ***s = socket(*sn, *st, *NUMBER_0_INTEGER);

                if (***s < *NUMBER_0_INTEGER) {

                    if (errno == EPROTONOSUPPORT) {

                        log_message_debug("Error: Could not send socket get socket client mode. The protocol or style is not supported by the namespace specified.");

                    } else if (errno == EMFILE) {

                        log_message_debug("Error: Could not send socket get socket client mode. The process already has too many file descriptors open.");

                    } else if (errno == ENFILE) {

                        log_message_debug("Error: Could not send socket get socket client mode. The system already has too many file descriptors open.");

                    } else if (errno == EACCES) {

                        log_message_debug("Error: Could not send socket get socket client mode. The process does not have the privilege to create a socket of the specified style or protocol.");

                    } else if (errno == ENOBUFS) {

                        log_message_debug("Error: Could not send socket get socket client mode. The system ran out of internal buffer space.");

                    } else {

                        log_message_debug("Error: Could not send socket get socket client mode. An unknown error occured while initialising the socket.");
                    }
                }

            } else {

                log_message_debug("Error: Could not send message via socket get socket for server mode. The base internal is null.");
            }

        } else {

            log_message_debug("Error: Could not send message via socket get socket for server mode. The base internal is null.");
        }

    } else {

        log_message_debug("Error: Could not send message via socket get socket for server mode. The base internal is null.");
    }
}

/**
 * Gets the socket.
 *
 * In server mode, an existing socket of this system is read from the internal memory.
 * In client mode, a completely new socket is created.
 *
 * @param p0 the socket of this system (Hand over as reference!)
 * @param p1 the internal memory
 * @param p2 the base internal
 * @param p3 the socket namespace
 * @param p4 the communication style
 * @param p5 the communication mode
 * @param p6 the communication mode count
 */
void send_socket_get_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_debug("Information: Get socket.");

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) SERVER_COMMUNICATION_MODE_MODEL, (void*) SERVER_COMMUNICATION_MODE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_socket_get_socket_server_mode(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) CLIENT_COMMUNICATION_MODE_MODEL, (void*) CLIENT_COMMUNICATION_MODE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            send_socket_get_socket_client_mode(p0, p3, p4);
        }
    }
}

/**
 * Sets non-blocking mode for the given socket.
 *
 * @param p0 the socket
 */
void send_socket_set_nonblocking_mode(void* p0) {

    if (p0 != *NULL_POINTER) {

        int* s = (int*) p0;

        log_message_debug("Information: Send socket set non-blocking mode.");

        // Set non-blocking mode for the socket file descriptor.
        //
        // If the O_NONBLOCK flag (a bit) is set, read requests on the socket
        // (file) can return immediately with a failure status if there is no
        // input immediately available, instead of blocking. Likewise, write
        // requests can also return immediately with a failure status if the
        // output can't be written immediately.
        //
        // CAUTION! The "select" procedure was NOT used to make this socket
        // non-blocking, because it has some overhead in that other sockets
        // need to be considered and their file descriptors handed over as
        // parameter.
        // A simple "sleep" procedure is considered to be a more simple and
        // clean solution here.

        // Get file status flags.
        int fl = fcntl(*s, F_GETFL, NUMBER_0_INTEGER);

        if (fl != *INVALID_VALUE) {

            // Set non-blocking flag (bit).
            fl |= O_NONBLOCK;

            // Store modified flag word in the file descriptor.
            fcntl(*s, F_SETFL, fl);

        } else {

            log_message_debug("Error: Could not send socket / set non-blocking mode. The socket file descriptor flags could not be read.");
        }

    } else {

        log_message_debug("Error: Could not send message via socket. The base internal is null.");
    }
}

/**
 * Allocates the host address.
 *
 * @param p0 the host address (Hand over as reference!)
 * @param p1 the address namespace
 */
void send_socket_allocate_host_address(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* n = (int*) p1;

        if (p0 != *NULL_POINTER) {

            void** a = (void**) p0;

            log_message_debug("Information: Send socket allocate host address.");

            // Get host address constant.
            if (*n == AF_INET) {

                // Allocate ipv4 socket address.
                *a = malloc(sizeof(struct in_addr));

            } else if (*n == AF_INET6) {

                // Allocate ipv6 socket address.
                *a = malloc(sizeof(struct in6_addr));
            }

        } else {

            log_message_debug("Error: Could not send message via socket allocate host address. The host address is null.");
        }

    } else {

        log_message_debug("Error: Could not send message via socket allocate host address. The address namespace is null.");
    }
}

/**
 * Allocates the socket address.
 *
 * @param p0 the socket address (Hand over as reference!)
 * @param p1 the socket address size (Hand over as reference!)
 * @param p2 the address namespace
 */
void send_socket_allocate_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* n = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* as = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** a = (void**) p0;

                log_message_debug("Information: Send socket allocate socket address.");

                if (*n == AF_LOCAL) {

                    // Initialise socket address size.
                    //
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
                    *as = sizeof(short int) + 108;

                    // Allocate socket address.
                    *a = malloc(*as);

                } else if (*n == AF_INET) {

                    // Initialise ipv4 socket address size.
                    *as = sizeof(struct sockaddr_in);

                    // Allocate ipv4 socket address.
                    *a = malloc(*as);

                } else if (*n == AF_INET6) {

                    // Initialise ipv6 socket address size.
                    *as = sizeof(struct sockaddr_in6);

                    // Allocate ipv6 socket address.
                    *a = malloc(*as);
                }

            } else {

                log_message_debug("Error: Could not send message via socket allocate socket address. The socket address is null.");
            }

        } else {

            log_message_debug("Error: Could not send message via socket allocate socket address. The socket address size is null.");
        }

    } else {

        log_message_debug("Error: Could not send message via socket allocate socket address. The address namespace is null.");
    }
}

/**
 * Initialises the socket address.
 *
 * @param p0 the socket address (Hand over as reference!)
 * @param p1 the file name or host address model, depending on the socket type (local, ipv4, ipv6)
 * @param p2 the file name or host address model count
 * @param p3 the host address
 * @param p4 the port model
 * @param p5 the address namespace
 */
void send_socket_initialise_socket_address(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER) {

        int* n = (int*) p5;

        log_message_debug("Information: Send socket initialise socket address.");

        if (*n == AF_LOCAL) {

            // Initialise local socket address.
            //
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
            startup_socket_initialise_local_socket_address(p0, p1, p2);

        } else if (*n == AF_INET) {

            // Initialise ipv4 socket address.
            startup_socket_initialise_ipv4_socket_address(p0, p3, p4);

        } else if (*n == AF_INET6) {

            // Initialise ipv6 socket address.
            startup_socket_initialise_ipv6_socket_address(p0, p3, p4);
        }

    } else {

        log_message_debug("Error: Could not send message via socket initialise socket address. The address namespace is null.");
    }
}

/**
 * Sends a message via socket.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 * @param p2 the file name or host address model, depending on the socket type (local, ipv4, ipv6)
 * @param p3 the file name or host address model count
 * @param p4 the port model
 * @param p5 the namespace model
 * @param p6 the namespace model count
 * @param p7 the style model
 * @param p8 the style model count
 * @param p9 the communication mode
 * @param p10 the communication mode count
 * @param p11 the message abstraction
 * @param p12 the message abstraction count
 * @param p13 the message model
 * @param p14 the message model count
 * @param p15 the message details
 * @param p16 the message details count
 * @param p17 the knowledge memory
 * @param p18 the knowledge memory count
 * @param p19 the language
 * @param p20 the language count
 */
void send_socket(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    log_message_debug("Information: Send message via socket.");

    // The communication style.
    int st = *INVALID_VALUE;
    // The socket namespace.
    int sn = *INVALID_VALUE;
    // The address namespace.
    int an = *INVALID_VALUE;
    // The socket of this system.
    int** s = (int**) NULL_POINTER;
    // The host address of the communication partner.
    void* ha = *NULL_POINTER;
    // The socket address of the communication partner.
    void* sa = *NULL_POINTER;
    // The socket address size of the communication partner.
    int sas = *NUMBER_0_INTEGER;
    // The http body character vector as serialised model.
    void* b = *NULL_POINTER;
    int bc = *NUMBER_0_INTEGER;
    int bs = *NUMBER_0_INTEGER;
    // The http message character vector to be sent to the socket.
    void* m = *NULL_POINTER;
    int mc = *NUMBER_0_INTEGER;
    int ms = *NUMBER_0_INTEGER;

/*??
    // Get socket- and address namespace.
    startup_socket_get_namespace((void*) &sn, (void*) &an, p5, p6);
    // Get socket communication style.
    startup_socket_get_style((void*) &st, p7, p8);
    // Get socket.
    send_socket_get_socket((void*) &s, p0, p1, (void*) &sn, (void*) &st, p9, p10);

    fprintf(stderr, "TEST: send socket: %i \n", **s);
*/

    // Set non-blocking mode for socket.
//??    send_socket_set_nonblocking_mode((void*) *s);

/*??
    // Allocate host address.
    send_socket_allocate_host_address((void*) &ha, (void*) &an);
    // Allocate socket address.
    send_socket_allocate_socket_address((void*) &sa, (void*) &sas, (void*) &an);
*/
    // Allocate http body character vector.
    allocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Allocate http message character vector.
    allocate((void*) &m, (void*) &ms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

/*??
    // Initialise host address.
    startup_socket_get_host_address(ha, p2, p3, (void*) &an);
    // Initialise socket address.
    send_socket_initialise_socket_address((void*) &sa, p2, p3, ha, p4, (void*) &an);
*/

    //
    // Serialise http message.
    //
    // An http server response delivers message data in text format (like MIME 1.0),
    // and consists of the following three parts:
    // 1 protocol version and status code
    // 2 headers containing meta data, of which some have the form of variables
    // 3 body containing the actual user data (such as a serialised xhtml page)
    // The end of the header data is demarcated by an empty line.
    //
    // Header variables are NOT case-sensitive and have the following syntax:
    // variable: statement[=value] [,statement2][=value2] [...]
    //
    // The following example shows the headers "Content-type", "Content-length" and "Set-cookie":
    //
    // Content-type: text/html
    // Content-length: 114
    // Set-cookie: usr=id541296, domain=bolege.de secure
    //
    // The following lines show an example http answer with protocol, header and body,
    // sent from a server back to the client:
    //
    // HTTP/1.0 200 OK
    // Date: Fri, 13 Jan 2006 15:12:48 GMT
    // Last-Modified: Tue, 10 Jan 2006 11:18:20 GMT
    // Content-Language: de
    // Content-Encoding: gzip
    // Content-Type: text/html; charset=utf-8
    //
    // <xhtml xmlns="http://www.w3.org/1999/xhtml">
    // <head>
    //     <meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
    //     </meta>
    //     <meta name="author" content="Generated by CYBOI">
    // ...
    //

    // Serialise http body.
    //
    // The compound model is serialised depending on the given language, e.g. into xhtml format.
    //
    // CAUTION! This has to be done AT FIRST, yet before adding the model to the buffer array,
    // because the serialised model's count is added as content length to the http header below.
    // Therefore, the model is stored in a temporary variable here, before adding that to the buffer further below.
    serialise((void*) &b, (void*) &bc, (void*) &bs, *NULL_POINTER, *NULL_POINTER, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);

    // CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
    // This is defined so by the Hypertext Transfer Protocol (HTTP).

    // Serialise http protocol version.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_1_1_PROTOCOL_VERSION, (void*) HTTP_1_1_PROTOCOL_VERSION_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise space character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise http status code.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTTP_200_OK_STATUS_CODE, (void*) HTTP_200_OK_STATUS_CODE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise carriage return character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CARRIAGE_RETURN_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise line feed character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise content type http header.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CONTENT_TYPE_HTTP_HEADER, (void*) CONTENT_TYPE_HTTP_HEADER_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise colon character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) COLON_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise space character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise content type as mime type.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) HTML_TEXT_MIME_TYPE, (void*) HTML_TEXT_MIME_TYPE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise semicolon character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) SEMICOLON_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise space character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise charset http header variable.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CHARSET_HTTP_HEADER_VARIABLE, (void*) CHARSET_HTTP_HEADER_VARIABLE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise equals sign character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) EQUALS_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise http charset value.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) ISO_8859_1_CHARACTER_SET, (void*) ISO_8859_1_CHARACTER_SET_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise carriage return character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CARRIAGE_RETURN_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise line feed character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise content length http header.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CONTENT_LENGTH_HTTP_HEADER, (void*) CONTENT_LENGTH_HTTP_HEADER_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise colon character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) COLON_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise space character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise content length as http body's length.
    // CAUTION! The source is an integer value!.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) &bc, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Serialise carriage return character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CARRIAGE_RETURN_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise line feed character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise carriage return character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) CARRIAGE_RETURN_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise line feed character.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Serialise http body which was already serialised from a cyboi model further above.
    serialise((void*) &m, (void*) &mc, (void*) &ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        b, (void*) &bc, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    fputs("SUCCESS! Generated http message with xhtml file as body.\n", stdout);

//?? -- START TEST
    // The log file name.
    char* n = "send.xhtml";
    // The log file status flags.
    int status = O_TRUNC | O_CREAT | O_WRONLY;
    // The log file.
    int f = open(n, status);

    if (f >= 0) {

        // The file owner.
        int o = *INVALID_VALUE;

        // The file group.
        int g = *INVALID_VALUE;

        // Set file owner.
        chown(n, o, g);

        // The file access rights.
        //?? TODO: When trying to cross-compile cyboi for windows,
        //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
        int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

        // Set file access rights.
        chmod(n, r);

        // Log xhtml to output.
        write(f, m, mc);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        fputs("Error: Could open xhtml log file. A file error occured.\n", stdout);
    }
//?? -- END TEST

    // One might think that a deadlock may occur if this system
    // sends a message to itself. However, this could only occur if
    // the socket of this system got locked when a message is sent
    // AND ALSO when a message is received. Once the lock is set by
    // the "send" procedure, the "receive" procedure would wait
    // endlessly for an unlock, since the "send" in turn would wait
    // for the "receive" procedure to finish.
    //
    // But all this is not a problem and cannot happen, since the
    // "receive" operation creates a new socket with the address
    // data of the communication partner, whenever data are received.
    // Therefore, sender- and receiver socket cannot happen to be
    // identical. As a consequence, socket locking using a mutex is
    // not necessary here!

    // Send message via socket.
//??    write_socket((void*) *s, m, (void*) &mc, (void*) &sa, (void*) &sas, p9, p10, (void*) &st);

    /*??
        // The socket number for the signal id.
        // The index for the signal id in the array is the same index
        // in the client socket number array.
        int i = -1;

        get_index_for_signal_id(p2, p9, (void*) &i);

        if (i >= 0) {

            // The client socket.
            int* cs = (int*) *NULL_POINTER;

            get_client_socket_number_for_index(p2, (void*) &i, (void*) &cs);

            if (*cs >= 0) {
    --
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

    // Close socket.
    //
    // CAUTION! The socket is always closed, no matter whether it was created in:
    // - this "send_socket" operation (client mode)
    // - the "receive_socket" operation (server mode) and retrieved from internal memory here
//??    close(**s);

    // Deallocate http body character vector.
    deallocate((void*) &b, (void*) &bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Deallocate http message character vector.
    deallocate((void*) &m, (void*) &ms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
/*??
    // Deallocate socket address.
    free(sa);
    // Deallocate host address.
    free(ha);
*/
}

/* SEND_SOCKET_SOURCE */
#endif
