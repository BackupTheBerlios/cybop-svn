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
 * @version $RCSfile: socket_sensing_communicator.c,v $ $Revision: 1.14 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SENSING_COMMUNICATOR_SOURCE
#define SOCKET_SENSING_COMMUNICATOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/log/level_log_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../executor/accessor/getter/array_getter.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/accessor/getter/signal_memory_getter.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"

//
// An alternative approach to speed up communication would be to keep
// all accepted client sockets open, for example by storing them
// in a "socket memory" container. This container would have to be
// allocated at server socket startup and deallocated at shutdown.
// It would have to be accessed using a special mutex. Further, it would
// be stored in the internal memory, just like the knowledge- and signal memory.
// However, there will be no need to handle many sockets,
// if each connection is treated like a new request.
//
// There would have to be two threads: one for "accept" and another for "recv".
// The reason is that "recv" might still be busy receiving data while new
// connection requests are to be accepted. The second thread would contain
// a loop trying to sense data from all client sockets stored in the socket memory.
//
// However, this approach was NOT realised due to various difficulties:
// - http is a stateless protocol, so each request is considered independently anyway
// - after a request has been accepted and a reply sent to the client, a new request
//   of the same client would be accepted and sensed independently;
//   it would be complicated to find out (via comparison of the socket addresses)
//   if the client socket already exists in the socket memory
// - it would be unclear when to close the client socket, since it was
//   actually stored in the socket memory to be ready for multiple
//   data exchanges and to avoid steady accept/close cycles
// - many modern applications written in other programming languages
//   open and close each socket after just one request-response cycle
//   and do NOT keep the connexion open
//
// Not useful is the idea to hand over the socket as cybol property,
// in order to store it in the knowledge tree. Low-level sockets
// should not be known to higher-level cybol applications.
//

/**
 * Senses socket message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the communication partner-connected socket
 * @param p4 the communication partner-connected socket address
 * @param p5 the communication partner-connected socket address size
 * @param p6 the original socket of this system
 */
void communicate_sensing_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* os = (int*) p6;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* ps = (int*) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                double* st = (double*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* irq = (int*) p0;

                        // CAUTION! DO NOT log this function call!
                        // This function is executed within a thread, but the
                        // logging is not guaranteed to be thread-safe and might
                        // cause unpredictable programme behaviour.
                        // Also, this function runs in an endless loop and would produce huge log files.
                        // log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense socket message.");

    fwprintf(stdout, L"TEST: sense (stream) socket server socket: %i \n", *os);

                        // Initialise error number.
                        // It is a global variable/ function and other operations
                        // may have set some value that is not wanted here.
                        //
                        // CAUTION! Initialise the error number BEFORE calling the procedure
                        // that might cause an error.
                        //
                        // CAUTION! Do NOT reset the GLOBAL "errno" variable here!
                        // All what is said above is true, but is this a THREAD
                        // and other threads might access the "errno" variable
                        // at the same time, which would lead to false programme behaviour.
                        // errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Accept client socket request and store client socket.
                        //
                        // Accepting a connection does NOT make the original socket
                        // part of the connection. Instead, it creates a new socket
                        // which becomes connected. The normal return value of
                        // "accept" is the file descriptor for the new socket.
                        //
                        // After "accept", the original socket remains open and
                        // unconnected, and continues listening until it gets closed.
                        // One can accept further connections with the original
                        // socket by calling "accept" again -- best done in a loop!
                        //
                        // The address "pa" returns information about the name of the
                        // communication partner socket that initiated the connection.
                        //
                        // CAUTION! The "select" procedure was NOT used to make this socket non-blocking,
                        // because it has some overhead in that other sockets need to be considered
                        // and their file descriptors handed over as parameter.
                        //
                        *ps = accept(*os, (struct sockaddr*) p4, (socklen_t*) p5);

                        if (*ps >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST: sense (stream) socket client partner socket ps: %i \n", *ps);

                            // CAUTION! Do NOT close client socket here!
                            // It is stored in the internal memory and only closed
                            // in the "send_socket" operation, when replying to the client.
                            // close(*ps);

                            // Lock socket mutex.
                            pthread_mutex_lock(mt);

                            // Set socket interrupt request to indicate
                            // that a message has been received via socket,
                            // which may now be processed in the main thread of this system.
                            *irq = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Unlock socket mutex.
                            pthread_mutex_unlock(mt);

    fwprintf(stdout, L"TEST: sense wait st: %g \n", *st);

                            while (*irq != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // Sleep as long as the socket interrupt is not handled and reset yet.
                                // This is to give the central processing unit (cpu) some
                                // time to breathe, that is to be idle or to process other signals.
                                sleep(*st);
                            }

                        } else {

                            if (errno == EBADF) {

                                // CAUTION! DO NOT log this function call!
                                // This function is executed within a thread, but the
                                // logging is not guaranteed to be thread-safe and might
                                // cause unpredictable programme behaviour.
                                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The socket argument is not a valid file descriptor.");

                            } else if (errno == ENOTSOCK) {

                                // CAUTION! DO NOT log this function call!
                                // This function is executed within a thread, but the
                                // logging is not guaranteed to be thread-safe and might
                                // cause unpredictable programme behaviour.
                                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The descriptor socket argument is not a socket.");

                            } else if (errno == EOPNOTSUPP) {

                                // CAUTION! DO NOT log this function call!
                                // This function is executed within a thread, but the
                                // logging is not guaranteed to be thread-safe and might
                                // cause unpredictable programme behaviour.
                                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The descriptor socket does not support this operation.");

                            } else if (errno == EWOULDBLOCK) {

                                // CAUTION! DO NOT log this function call!
                                // This function is executed within a thread, but the
                                // logging is not guaranteed to be thread-safe and might
                                // cause unpredictable programme behaviour.
                                //
                                // CAUTION! Do NOT log the following error!
                                // The reason is that the socket is non-blocking,
                                // so that the "accept" procedure returns always,
                                // even if no connection was established,
                                // which would unnecessarily fill up the log file.
                                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The socket has nonblocking mode set, and there are no pending connections immediately available.");

                            } else {

                                // CAUTION! DO NOT log this function call!
                                // This function is executed within a thread, but the
                                // logging is not guaranteed to be thread-safe and might
                                // cause unpredictable programme behaviour.
                                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. An unknown error occured while accepting a socket connection.");
                            }
                        }

                    } else {

                        // CAUTION! DO NOT log this function call!
                        // This function is executed within a thread, but the
                        // logging is not guaranteed to be thread-safe and might
                        // cause unpredictable programme behaviour.
                        // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The interrupt is null.");
                    }

                } else {

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The mutex is null.");
                }

            } else {

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The sleep time is null.");
            }

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The communication partner-connected socket is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket message. The original socket of this system is null.");
    }
}

/**
 * Senses socket messages.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 */
void communicate_sensing_socket(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* base = (int*) p1;

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense socket.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The interrupt.
        void** irq = NULL_POINTER_MEMORY_MODEL;
        // The mutex.
        void** mt = NULL_POINTER_MEMORY_MODEL;
        // The sleep time.
        void** st = NULL_POINTER_MEMORY_MODEL;
        // The display.
        void** d = NULL_POINTER_MEMORY_MODEL;
        // The communication partner-connected socket of this system.
        void** ps = NULL_POINTER_MEMORY_MODEL;
        // The communication partner-connected socket address of this system.
        void** pa = NULL_POINTER_MEMORY_MODEL;
        void** pas = NULL_POINTER_MEMORY_MODEL;
        // The original socket of this system.
        void** os = NULL_POINTER_MEMORY_MODEL;

        // Get interrupt.
        i = *base + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &irq, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        // Get mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &mt, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        // Get sleep time.
        i = *base + *SOCKET_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &st, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        // Get communication partner-connected socket of this system.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &ps, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        // Get communication partner socket address.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &pa, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &pas, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        // Get original socket of this system.
        i = *base + *SOCKET_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &os, p0, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            // A break condition does not exist here because the loop
            // is running neverendingly while sensing messages.
            //
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service function
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

    fwprintf(stdout, L"TEST: sensing socket pre os: %i \n", *((int*) *os));
    fwprintf(stdout, L"TEST: sensing socket pre ps: %i \n", *((int*) *ps));
            communicate_sensing_socket_message(*irq, *mt, *st, *ps, *pa, *pas, *os);
    fwprintf(stdout, L"TEST: sensing socket post os: %i \n", *((int*) *os));
    fwprintf(stdout, L"TEST: sensing socket post ps: %i \n", *((int*) *ps));
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket. The base internal is null.");
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the function that was used to create it (this function).
    // The pthread_exit() function does therefore not have to be called here.
    // However, since this function runs an endless loop waiting for input, it may
    // only be left using an external signal (see comment at "break" condition above).
}

/**
 * Senses www socket messages.
 *
 * @param p0 the internal memory
 */
void communicate_sensing_www_socket(void* p0) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.
    // log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense www socket.");

    communicate_sensing_socket(p0, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
}

/**
 * Senses cyboi socket messages.
 *
 * @param p0 the internal memory
 */
void communicate_sensing_cyboi_socket(void* p0) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.
    // log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense cyboi socket.");

    communicate_sensing_socket(p0, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SOCKET_SENSING_COMMUNICATOR_SOURCE */
#endif
