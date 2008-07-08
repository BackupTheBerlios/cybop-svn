/*
 * $RCSfile: sense_socket.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.5 $ $Date: 2008-07-08 17:55:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSE_SOCKET_SOURCE
#define SENSE_SOCKET_SOURCE

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
#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../globals/constants/console/console_escape_code_constants.c"
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/internal_memory_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

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
void sense_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER) {

        int* os = (int*) p6;

        if (p3 != *NULL_POINTER) {

            int* ps = (int*) p3;

            if (p2 != *NULL_POINTER) {

                unsigned int* st = (unsigned int*) p2;

                if (p1 != *NULL_POINTER) {

                    pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                    if (p0 != *NULL_POINTER) {

                        int* irq = (int*) p0;

                        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Sense socket message.");

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
                        *irq = *NUMBER_1_INTEGER;

                        // Unlock socket mutex.
                        pthread_mutex_unlock(mt);

                        while (*irq == *NUMBER_1_INTEGER) {

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

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense (stream) socket message. The interrupt is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense (stream) socket message. The mutex is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense (stream) socket message. The sleep time is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense (stream) socket message. The communication partner-connected socket is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense (stream) socket message. The original socket of this system is null.");
    }
}

/**
 * Senses socket messages.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 */
void sense_socket(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* base = (int*) p1;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Sense socket.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER;
        // The interrupt.
        void** irq = NULL_POINTER;
        // The mutex.
        void** mt = NULL_POINTER;
        // The sleep time.
        void** st = NULL_POINTER;
        // The display.
        void** d = NULL_POINTER;
        // The communication partner-connected socket of this system.
        void** ps = NULL_POINTER;
        // The communication partner-connected socket address of this system.
        void** pa = NULL_POINTER;
        void** pas = NULL_POINTER;
        // The original socket of this system.
        void** os = NULL_POINTER;

        // Get interrupt.
        i = *base + *SOCKET_INTERRUPT_REQUEST_INTERNAL;
        get_element(p0, (void*) &i, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get_element(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get sleep time.
        i = *base + *SOCKET_SLEEP_TIME_INTERNAL;
        get_element(p0, (void*) &i, (void*) &st, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket address.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get original socket of this system.
        i = *base + *SOCKET_INTERNAL;
        get_element(p0, (void*) &i, (void*) &os, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        while (*NUMBER_1_INTEGER) {

            // A break condition does not exist here because the loop
            // is running neverendingly while sensing messages.
            //
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service function
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

            sense_socket_message(*irq, *mt, *st, *ps, *pa, *pas, *os);
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not sense socket. The base internal is null.");
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
void sense_www_socket(void* p0) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Sense www socket.");

    sense_socket(p0, (void*) WWW_BASE_INTERNAL);
}

/**
 * Senses cyboi socket messages.
 *
 * @param p0 the internal memory
 */
void sense_cyboi_socket(void* p0) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Sense cyboi socket.");

    sense_socket(p0, (void*) CYBOI_BASE_INTERNAL);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SENSE_SOCKET_SOURCE */
#endif
