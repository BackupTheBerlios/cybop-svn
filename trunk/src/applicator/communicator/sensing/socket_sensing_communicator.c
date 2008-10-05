/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: socket_sensing_communicator.c,v $ $Revision: 1.10 $ $Date: 2008-10-05 23:15:02 $ $Author: christian $
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
#include "../../../logger/logger.c"
#include "../../../memoriser/accessor/compound_accessor.c"
#include "../../../memoriser/accessor/internal_memory_accessor.c"
#include "../../../memoriser/accessor/signal_memory_accessor.c"
#include "../../../memoriser/allocator.c"
#include "../../../memoriser/array.c"

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

                unsigned int* st = (unsigned int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* irq = (int*) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense socket message.");

    fwprintf(stderr, L"TEST: sense (stream) socket server socket: %i \n", *os);

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
                        *ps = accept(*os, (struct sockaddr*) p4, (socklen_t*) p5);

    fwprintf(stderr, L"TEST: sense (stream) socket client partner socket ps: %i \n", *ps);

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

                        while (*irq == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                            // Sleep as long as the socket interrupt is not handled and reset yet.
                            // This is to give the central processing unit (cpu) some
                            // time to breathe, that is to be idle or to process other signals.
                            sleep(*st);
                        }

                        // CAUTION! The "select" procedure was NOT used to make this socket
                        // non-blocking, because it has some overhead in that other sockets
                        // need to be considered and their file descriptors handed over as
                        // parameter.
                        //
                        // CAUTION! An alternative approach to speed up communication would be
                        // to keep all accepted client sockets open, for example by storing them
                        // in a "socket memory" container. This container would have to be
                        // allocated at server socket startup and deallocated at shutdown.
                        // It would have to be accessed using a special mutex. Further, it would
                        // be stored in the internal memory, just like the knowledge- and signal memory.
                        //
                        // There would have to be two threads: one for "accept" and another for "recv".
                        // The reason is that "recv" might still be busy receiving data while new
                        // connection requests are to be accepted. The second thread would contain
                        // a loop trying to sense data from all client sockets stored in the socket memory.
                        //
                        // However, this approach was NOT realised due to various difficulties:
                        // - http is a stateless protocol, so each request has to be considered independently anyway
                        // - after a request has been accepted and a reply sent to the client, a new request
                        //   of the same client would be accepted and sensed independently;
                        //   it would be complicated to find out (via comparison of the socket addresses)
                        //   if the client socket already exists in the socket memory
                        // - it would be unclear when to close the client socket, since it was
                        //   actually stored in the socket memory to be ready for multiple
                        //   data exchanges and to avoid steady accept/close cycles

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense (stream) socket message. The interrupt is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense (stream) socket message. The mutex is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense (stream) socket message. The sleep time is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense (stream) socket message. The communication partner-connected socket is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense (stream) socket message. The original socket of this system is null.");
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

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense socket.");

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
        get_element(p0, (void*) &i, (void*) &irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Get mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Get sleep time.
        i = *base + *SOCKET_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p0, (void*) &i, (void*) &st, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Get communication partner socket address.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        // Get original socket of this system.
        i = *base + *SOCKET_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p0, (void*) &i, (void*) &os, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            // A break condition does not exist here because the loop
            // is running neverendingly while sensing messages.
            //
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service function
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

            communicate_sensing_socket_message(*irq, *mt, *st, *ps, *pa, *pas, *os);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense socket. The base internal is null.");
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

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense www socket.");

    communicate_sensing_socket(p0, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
}

/**
 * Senses cyboi socket messages.
 *
 * @param p0 the internal memory
 */
void communicate_sensing_cyboi_socket(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense cyboi socket.");

    communicate_sensing_socket(p0, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SOCKET_SENSING_COMMUNICATOR_SOURCE */
#endif
