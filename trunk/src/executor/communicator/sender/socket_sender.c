/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: socket_sending_communicator.c,v $ $Revision: 1.14 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SENDER_SOURCE
#define SOCKET_SENDER_SOURCE

//?? TEST for test file; DELETE later!
#include <sys/stat.h>
#include <fcntl.h>
//?? TEST END

#include <netinet/in.h>
#include <sys/socket.h>

#include "../../../applicator/maintainer/starting/socket_starting_maintainer.c"
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/cybol/communication_mode_cybol_model.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/communicator/sender/datagram_socket_sender.c"
#include "../../../executor/communicator/sender/raw_socket_sender.c"
#include "../../../executor/communicator/sender/stream_socket_sender.c"
#include "../../../executor/converter/encoder.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/socket_type_size.c"

/**
 * Gets the socket for server mode.
 *
 * Server mode means that this system was asked by a client system,
 * that it now needs to reply to.
 *
 * @param p0 the communication partner socket (Hand over as reference!)
 * @param p1 the internal memory
 * @param p2 the base internal
 */
void apply_send_socket_get_socket_server_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* base = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get socket for server mode.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_MEMORY_NAME;
        get(p0, p1, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

/*??
        ONLY necessary when writing or deleting a socket from internal memory.
        This may become necessary if many sockets are held in a queue.

        // The socket mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER_MEMORY_MODEL;

        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &mt, p1, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
*/

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket get socket for server mode. The base internal is null.");
    }
}

/**
 * Gets the socket for client mode.
 *
 * Client mode means that this system acts as client asking a server system,
 * which is its (local or remote) communication partner.
 *
 * @param p0 the socket of this system (Hand over as reference OF reference!!)
 * @param p1 the socket namespace
 * @param p2 the communication style
 */
void apply_send_socket_get_socket_client_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* st = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* sn = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int*** s = (int***) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get socket for client mode.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the function
                // that might cause an error.
                errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Initialise server socket.
                //
                // param 0: namespace
                // param 1: style
                // param 2: protocol
                //
                // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                // The latter is to be used for address family assignment.
                // See further below!
                ***s = socket(*sn, *st, *NUMBER_0_INTEGER_MEMORY_MODEL);

                if (***s < *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (errno == EPROTONOSUPPORT) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket get socket client mode. The protocol or style is not supported by the namespace specified.");

                    } else if (errno == EMFILE) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket get socket client mode. The process already has too many file descriptors open.");

                    } else if (errno == ENFILE) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket get socket client mode. The system already has too many file descriptors open.");

                    } else if (errno == EACCES) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket get socket client mode. The process does not have the privilege to create a socket of the specified style or protocol.");

                    } else if (errno == ENOBUFS) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket get socket client mode. The system ran out of internal buffer space.");

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket get socket client mode. An unknown error occured while initialising the socket.");
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket get socket for server mode. The base internal is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket get socket for server mode. The base internal is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket get socket for server mode. The base internal is null.");
    }
}

/**
 * Gets the socket.
 *
 * In server mode, an existing socket of this system is read from the internal memory.
 * In client mode, a completely new socket is created.
 *
 * @param p0 the communication partner socket (Hand over as reference!)
 * @param p1 the internal memory
 * @param p2 the base internal
 * @param p3 the socket namespace
 * @param p4 the communication style
 * @param p5 the communication mode
 * @param p6 the communication mode count
 */
void apply_send_socket_get_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get socket.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) SERVER_COMMUNICATION_MODE_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) SERVER_COMMUNICATION_MODE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            apply_send_socket_get_socket_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) CLIENT_COMMUNICATION_MODE_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) CLIENT_COMMUNICATION_MODE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            apply_send_socket_get_socket_client_mode(p0, p3, p4);
        }
    }
}

/**
 * Sets non-blocking mode for the given socket.
 *
 * @param p0 the socket
 */
void apply_send_socket_set_nonblocking_mode(void* p0) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Send socket set non-blocking mode.");

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
        // clean solution here. See file "controller/checker/wait_checker.c"!

        // Get file status flags.
        int fl = fcntl(*s, F_GETFL, NUMBER_0_INTEGER_MEMORY_MODEL);

        if (fl != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

            // Set non-blocking flag (bit).
            fl |= O_NONBLOCK;

            // Store modified flag word in the file descriptor.
            fcntl(*s, F_SETFL, fl);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket / set non-blocking mode. The socket file descriptor flags could not be read.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send socket / set non-blocking mode. The base internal is null.");
    }
}

/**
 * Allocates the host address.
 *
 * @param p0 the host address (Hand over as reference!)
 * @param p1 the address namespace
 */
void apply_send_socket_allocate_host_address(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* n = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** a = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Send socket allocate host address.");

            // Get host address constant.
            if (*n == AF_INET) {

                // Allocate ipv4 socket address.
                *a = malloc(*INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE);

            } else if (*n == AF_INET6) {

                // Allocate ipv6 socket address.
                *a = malloc(*INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket allocate host address. The host address is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket allocate host address. The address namespace is null.");
    }
}

/**
 * Allocates the socket address.
 *
 * @param p0 the socket address (Hand over as reference!)
 * @param p1 the socket address size (Hand over as reference!)
 * @param p2 the address namespace
 */
void apply_send_socket_allocate_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* n = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* as = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** a = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Send socket allocate socket address.");

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
                    *as = *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE + *NUMBER_108_INTEGER_MEMORY_MODEL;

                    // Allocate socket address.
                    *a = malloc(*as);

                } else if (*n == AF_INET) {

                    // Initialise ipv4 socket address size.
                    *as = *INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE;

                    // Allocate ipv4 socket address.
                    *a = malloc(*as);

                } else if (*n == AF_INET6) {

                    // Initialise ipv6 socket address size.
                    *as = *INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE;

                    // Allocate ipv6 socket address.
                    *a = malloc(*as);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket allocate socket address. The socket address is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket allocate socket address. The socket address size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket allocate socket address. The address namespace is null.");
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
void apply_send_socket_initialise_socket_address(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* n = (int*) p5;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Send socket initialise socket address.");

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
            maintain_starting_socket_initialise_local_socket_address(p0, p1, p2);

        } else if (*n == AF_INET) {

            // Initialise ipv4 socket address.
            maintain_starting_socket_initialise_ipv4_socket_address(p0, p3, p4);

        } else if (*n == AF_INET6) {

            // Initialise ipv6 socket address.
            maintain_starting_socket_initialise_ipv6_socket_address(p0, p3, p4);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not send message via socket initialise socket address. The address namespace is null.");
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
void apply_send_socket(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    //?? --- START TEST ---
    // The log file name.
    char* n = "http_response";
    // The log file status flags.
    int status = O_TRUNC | O_CREAT | O_WRONLY;
    // The log file.
    int f = open(n, status);

    if (f >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The file owner.
        int o = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // The file group.
        int g = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Set file owner.
        chown(n, o, g);

        // The file access rights.
        //?? TODO: When trying to cross-compile cyboi for windows,
        //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
        int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

        // Set file access rights.
        chmod(n, r);

        // Log html to output.
        write(f, p13, *((int*) p14));

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        log_write_terminated_message(stdout, L"Error: Could not open socket sending http_response file. A file error occured.\n");
    }
    //?? --- END TEST ---

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send message via socket.");

    // The communication style.
    int st = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The socket namespace.
    int sn = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The address namespace.
    int an = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The communication partner socket.
    int** s = (int**) NULL_POINTER_MEMORY_MODEL;
    // The host address of the communication partner.
    void* ha = *NULL_POINTER_MEMORY_MODEL;
    // The socket address of the communication partner.
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    int sas = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get socket- and address namespace.
    maintain_starting_socket_memorise_getting_namespace((void*) &sn, (void*) &an, p5, p6);
    fwprintf(stdout, L"TEST: send socket sn: %i \n", sn);
    fwprintf(stdout, L"TEST: send socket an: %i \n", an);
    // Get socket communication style.
    maintain_starting_socket_get_style((void*) &st, p7, p8);
    fwprintf(stdout, L"TEST: send socket st: %i \n", st);
    // Get communication partner socket.
    apply_send_socket_get_socket((void*) &s, p0, p1, (void*) &sn, (void*) &st, p9, p10);
    fwprintf(stdout, L"TEST: send socket s: %i \n", **s);

    // Set non-blocking mode for socket.
    apply_send_socket_set_nonblocking_mode((void*) *s);
    fwprintf(stdout, L"TEST: send socket s non-blocking: %i \n", **s);

    // Allocate host address.
    apply_send_socket_allocate_host_address((void*) &ha, (void*) &an);
    fwprintf(stdout, L"TEST: send socket ha: %i \n", ha);
    // Allocate socket address.
    apply_send_socket_allocate_socket_address((void*) &sa, (void*) &sas, (void*) &an);
    fwprintf(stdout, L"TEST: send socket sa: %i \n", sa);

    // Initialise host address.
    maintain_starting_socket_get_host_address(ha, p2, p3, (void*) &an);
    fwprintf(stdout, L"TEST: send socket ha init: %i \n", ha);
    // Initialise socket address.
    apply_send_socket_initialise_socket_address((void*) &sa, p2, p3, ha, p4, (void*) &an);
    fwprintf(stdout, L"TEST: send socket sa init: %i \n", sa);

    // One might think that a deadlock may occur if this system
    // sends a message to itself. However, this could only occur if
    // the socket of this system got locked when a message is sent
    // AND ALSO when a message is received. Once the lock got set by
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

    // Send message via socket in server mode.
    send_stream_socket((void*) *s, p13, p14, (void*) &sa, (void*) &sas, p9, p10);

    // Close socket.
    //
    // CAUTION! The socket is always closed, no matter whether it was created in:
    // - this "send_socket" operation right here (client mode)
    // - the "receive_socket" operation (server mode) and retrieved from internal memory right here
    close(**s);

    // Deallocate socket address.
    free(sa);
    // Deallocate host address.
    free(ha);
}

/* SOCKET_SENDER_SOURCE */
#endif
