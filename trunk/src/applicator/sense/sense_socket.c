/*
 * $RCSfile: sense_socket.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
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
#include "../../globals/constants/character/character_constants.c"
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
 * Senses via stream socket.
 *
 * @param p0 the buffer (Hand over as reference!)
 * @param p1 the buffer count
 * @param p2 the buffer size
 * @param p3 the communication partner-connected socket of this system
 *           (the client socket to accept, receive data from and attach as parameter to the
 *           cyboi signal generated later, so that this server may reply to the correct client)
 * @param p4 the communication partner-connected socket address
 * @param p5 the communication partner-connected socket address size
 * @param p6 the original socket of this system
 * @param p7 the socket mutex
 */
void sense_socket_stream(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p6 != *NULL_POINTER) {

        int* os = (int*) p6;

        if (p3 != *NULL_POINTER) {

            int* ps = (int*) p3;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Sense via stream socket.");

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling the procedure
            // that might cause an error.
            errno = *NUMBER_0_INTEGER;

            // Lock socket mutex.
            pthread_mutex_lock((pthread_mutex_t*) p7);

    fprintf(stderr, "TEST: sense socket stream server socket: %i \n", *os);

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

    fprintf(stderr, "TEST: sense socket stream client partner socket ps: %i \n", *ps);

            if (*ps >= *NUMBER_0_INTEGER) {

                // Each client request is accepted, its data received and a corresponding
                // signal generated, so that cyboi may send a response back to the client
                // and close the client socket.
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

                read_stream_socket(p0, p1, p2, p3);

                // CAUTION! Do NOT close client socket here!
                // It is stored as parameter belonging to the signal and only closed
                // in the "send_socket" operation, when replying to the client.
                // close(*ps);

            } else {

                if (errno == EBADF) {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. The socket argument is not a valid file descriptor.");

                } else if (errno == ENOTSOCK) {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. The descriptor socket argument is not a socket.");

                } else if (errno == EOPNOTSUPP) {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. The descriptor socket does not support this operation.");

                } else if (errno == EWOULDBLOCK) {

                    // CAUTION! Do NOT log the following error:
                    // log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. The socket has nonblocking mode set, and there are no pending connections immediately available.");
                    //
                    // The reason is that the socket is non-blocking,
                    // so that the "accept" procedure returns always,
                    // even if no connection was established,
                    // which would unnecessarily fill up the log file.

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. An unknown error occured while accepting a socket connection.");
                }
            }

            // Unlock socket mutex.
            pthread_mutex_unlock((pthread_mutex_t*) p7);

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. The communication partner-connected socket of this system is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense via stream socket. The original socket of this system is null.");
    }
}

/**
 * Senses a socket message.
 *
 * @param p0 the knowledge memory
 * @param p1 the knowledge memory count
 * @param p2 the knowledge memory size
 * @param p3 the signal memory
 * @param p4 the signal memory count
 * @param p5 the signal memory size
 * @param p6 the signal memory interrupt request internal
 * @param p7 the signal memory mutex
 * @param p8 the model (Hand over as reference!)
 * @param p9 the model count
 * @param p10 the model size
 * @param p11 the details (Hand over as reference!)
 * @param p12 the details count
 * @param p13 the details size
 * @param p14 the commands
 * @param p15 the commands count
 * @param p16 the language
 * @param p17 the language count
 * @param p18 the communication style
 * @param p19 the communication style count
 * @param p20 the original socket of this system
 * @param p21 the original socket address of this system
 * @param p22 the original socket address of this system size
 * @param p23 the communication partner-connected socket of this system
 * @param p24 the communication partner-connected socket address
 * @param p25 the communication partner-connected socket address size
 * @param p26 the socket interrupt request
 * @param p27 the socket mutex
 * @param p28 the buffer (Hand over as reference!)
 * @param p29 the buffer count
 * @param p30 the buffer size
 */
void sense_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19,
    void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26, void* p27, void* p28, void* p29, void* p30) {

    if (p30 != *NULL_POINTER) {

        int* bs = (int*) p30;

        if (p29 != *NULL_POINTER) {

            int* bc = (int*) p29;

            if (p28 != *NULL_POINTER) {

                void** b = (void**) p28;

                if (p27 != *NULL_POINTER) {

                    pthread_mutex_t* mt = (pthread_mutex_t*) p27;

                    if (p26 != *NULL_POINTER) {

                        int* irq = (int*) p26;

                        if (p8 != *NULL_POINTER) {

                            void** m = (void**) p8;

                            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Sense socket message.");

        fprintf(stderr, "TEST 0 language: %s \n", (char*) p16);
        fprintf(stderr, "TEST 0 language count: %i \n", *((int*) p17));

        fprintf(stderr, "TEST 0 bc: %i \n", *((int*) p29));
        fprintf(stderr, "TEST 0 bs: %i \n", *((int*) p30));

                            // Sense socket message depending on communication style.
                            sense_socket_style(p28, p29, p30, p23, p24, p25, p20, p21, p22, p27, p18, p19);

                            // Lock socket mutex.
                            pthread_mutex_lock(mt);

                            // Set socket interrupt request to indicate
                            // that a message has been received via socket, which
                            // may now be processed in the main thread of this system.
                            *irq = *NUMBER_1_INTEGER;

                            // Unlock socket mutex.
                            pthread_mutex_unlock(mt);

                            while (*sirq == *NUMBER_1_INTEGER) {

                                // Sleep as long as the socket interrupt
                                // is not handled and reset yet.
                                sleep(*CHECKER_SLEEP_TIME);
                            }

        fprintf(stderr, "TEST: sense socket message client socket sock: %i \n", *((int*) p23));

                            // Reset character buffer.
                            //
                            // CAUTION! The buffer and its count do ALWAYS have to be reset,
                            // NOT ONLY if the message data reception (above) was successful!
                            // The reason is that on failure, the buffer count is set to some
                            // negative value and therefore needs to be reset in any case.
                            //
                            // CAUTION! Do NOT deallocate the character buffer!
                            // It was allocated at socket startup and must remain unchanged,
                            // since threads are not allowed to allocate any memory area.
                            // Therefore, its elements are just set to null pointers here.
                            //
                            // CAUTION! Do NOT reset the maximum buffer size!
                            // It was allocated and initialised at socket startup
                            // and must remain unchanged.
                            memset(*b, *NUMBER_0_INTEGER, *bs);
                            *bc = *NUMBER_0_INTEGER;

            fprintf(stderr, "TEST 5 bc: %i \n", *((int*) p28));
            fprintf(stderr, "TEST 5 bs: %i \n", *((int*) p29));

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket message. The model is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket message. The socket interrupt request is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket message. The socket mutex is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket message. The buffer is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket message. The buffer count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket message. The buffer size is null.");
    }
}

/**
 * Senses socket messages in an own thread.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 */
void sense_socket_thread(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* base = (int*) p1;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Sense socket messages in an own thread.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER;
        // The knowledge memory.
        void** k = NULL_POINTER;
        void** kc = NULL_POINTER;
        void** ks = NULL_POINTER;
        // The signal memory.
        void** s = NULL_POINTER;
        void** sc = NULL_POINTER;
        void** ss = NULL_POINTER;
        // The signal memory interrupt request.
        sig_atomic_t** smirq = (sig_atomic_t**) NULL_POINTER;
        // The signal memory mutex.
        pthread_mutex_t** smmt = (pthread_mutex_t**) NULL_POINTER;
        // The socket interrupt request.
        sig_atomic_t** sirq = (sig_atomic_t**) NULL_POINTER;
        // The socket mutex.
        pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER;

        // The model.
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        // The details.
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;
        // The commands.
        void** c = NULL_POINTER;
        void** cc = NULL_POINTER;
        // The language.
        void** l = NULL_POINTER;
        void** lc = NULL_POINTER;
        // The communication style.
        void** st = NULL_POINTER;
        void** stc = NULL_POINTER;
        // The original socket of this system.
        void** os = NULL_POINTER;
        // The original socket address of this system.
        void** oa = NULL_POINTER;
        void** oas = NULL_POINTER;
        // The communication partner-connected socket of this system.
        void** ps = NULL_POINTER;
        // The communication partner-connected socket address of this system.
        void** pa = NULL_POINTER;
        void** pas = NULL_POINTER;
        // The character buffer.
        void** b = NULL_POINTER;
        void** bc = NULL_POINTER;
        // The maximum buffer size.
        // CAUTION! A message MUST NOT be longer!
        void** bs = NULL_POINTER;

        // Get knowledge memory internal.
        get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory internal.
        get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory interrupt request internal.
        get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL, (void*) &smirq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory mutex internal.
        get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get socket interrupt request.
        i = *base + *SOCKET_INTERRUPT_REQUEST_INTERNAL;
        get_element(p0, (void*) &i, (void*) &sirq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get_element(p0, (void*) &i, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Lock socket mutex.
        //
        // CAUTION! A mutex is needed here to ensure that the commands- and other internals
        // and their associated count and size are retrieved at once and belong together.
        // Otherwise, e.g. a commands internal might be gotten in this "sense" thread,
        // then the "main" thread of cyboi might set a new commands internal, count
        // and size, and finally this "sense" thread would get a wrong count or size
        // (of the new commands internal), not belonging to the commands internal got before.
        pthread_mutex_lock(*smt);

        // Get model.
        i = *base + *SOCKET_MODEL_INTERNAL;
        get_element(p0, (void*) &i, (void*) &m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_MODEL_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_MODEL_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ms, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get details.
        i = *base + *SOCKET_DETAILS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_DETAILS_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_DETAILS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ds, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get commands.
        i = *base + *SOCKET_COMMANDS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMANDS_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get language.
        i = *base + *SOCKET_LANGUAGE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &l, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_LANGUAGE_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &lc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication style.
        i = *base + *SOCKET_STYLE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &st, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_STYLE_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &stc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get original socket of this system.
        i = *base + *SOCKET_INTERNAL;
        get_element(p0, (void*) &i, (void*) &os, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get original socket address of this system.
        i = *base + *SOCKET_ADDRESS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &oa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_ADDRESS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &oas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket address.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get character buffer, which was set at socket startup.
        i = *base + *SOCKET_CHARACTER_BUFFER_INTERNAL;
        get_element(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Unlock socket mutex.
        pthread_mutex_unlock(*smt);

        while (*NUMBER_1_INTEGER) {

            // A break condition does not exist here because the loop
            // is blocking neverendingly while waiting for signals.
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service procedure
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

            // CAUTION! Hand over model, details and buffer as reference!
            sense_socket_message(*k, *kc, *ks, *s, *sc, *ss, *smirq, *smmt,
                m, *mc, *ms, d, *dc, *ds, *c, *cc, *l, *lc, *st, *stc,
                *os, *oa, *oas, *ps, *pa, *pas, *sirq, *smt, b, *bc, *bs);

            // Sleep for some time to give the central processing unit (cpu)
            // time to breathe, that is to be idle or to process other signals.
            //
            // CAUTION! The "select" procedure was NOT used to make this socket
            // non-blocking, because it has some overhead in that other sockets
            // need to be considered and their file descriptors handed over as
            // parameter.
            // A simple "sleep" procedure is considered to be a more simple and
            // clean solution here.
            //
            // CAUTION! This is ONLY necessary if using a non-blocking socket!
            // sleep(1.0);

            //?? TESTING only; delete BREAK command and this log message later!
            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "TEST: Break loop now ...");
            break;
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket thread. The base internal is null.");
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
    //
    // However, since this procedure runs an endless loop waiting for input,
    // and is NEVER left (does not have a "break" condition),
    // the loop and this thread can only be exited by an external signal
    // which is sent in the corresponding interrupt service procedure,
    // situated in the applicator/interrupt/ directory,
    // and processed in the interrupt_service_system_signal_handler procedure:
    // controller/manager/system_signal_handler_manager.c
}

/**
 * Senses www messages via socket.
 *
 * @param p0 the internal memory
 */
void sense_socket_www(void* p0) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Sense www messages via socket.");

    sense_socket_thread(p0, (void*) WWW_BASE_INTERNAL);
}

/**
 * Senses cyboi messages via socket.
 *
 * @param p0 the internal memory
 */
void sense_socket_cyboi(void* p0) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Sense cyboi messages via socket.");

    sense_socket_thread(p0, (void*) CYBOI_BASE_INTERNAL);
}

/**
 * Senses messages via socket.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 * @param p2 the service thread
 * @param p3 the sense socket thread procedure
 * @param p4 the model (Hand over as reference!)
 * @param p5 the model count
 * @param p6 the model size
 * @param p7 the details (Hand over as reference!)
 * @param p8 the details count
 * @param p9 the details size
 * @param p10 the commands model (Hand over as reference!)
 * @param p11 the commands model count
 * @param p12 the language model (Hand over as reference!)
 * @param p13 the language model count
 * @param p14 the communication style model (Hand over as reference!)
 * @param p15 the communication style model count
 */
void sense_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p2 != *NULL_POINTER) {

        int* t = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* b = (int*) p1;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Sense socket.");

            // The internal memory index.
            int i = *NUMBER_MINUS_1_INTEGER;
            // The socket mutex.
            pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;

            // Get socket mutex.
            i = *b + *SOCKET_MUTEX_INTERNAL;
            get_element(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Lock socket mutex.
            pthread_mutex_lock(*mt);

            // Adding the following parameters to the internal memory is necessary,
            // because only one parameter (the internal memory p0) can be forwarded
            // to the thread procedure further below. Thus, p0 MUST contain any others.

            // Set internals.
            //
            // CAUTION! A mutex is ACTUALLY not necessary, since the thread
            // procedures only read, but NOT write internal memory values.
            //
            // However, a mutex IS NECESSARY anyway, since the internal values
            // and their count and size should be set together, at once.
            // Otherwise, the thread procedures might read a new internal value
            // with the count or size of an old internal value, which would
            // lead to a segmentation fault and possibly system crash.

            // Set model internal.
            i = *b + *SOCKET_MODEL_INTERNAL;
            set_element(p0, (void*) &i, p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_MODEL_COUNT_INTERNAL;
            set_element(p0, (void*) &i, p5, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_MODEL_SIZE_INTERNAL;
            set_element(p0, (void*) &i, p6, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set details internal.
            i = *b + *SOCKET_DETAILS_INTERNAL;
            set_element(p0, (void*) &i, p7, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_DETAILS_COUNT_INTERNAL;
            set_element(p0, (void*) &i, p8, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_DETAILS_SIZE_INTERNAL;
            set_element(p0, (void*) &i, p9, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set commands internal.
            i = *b + *SOCKET_COMMANDS_INTERNAL;
            set_element(p0, (void*) &i, p10, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_COMMANDS_COUNT_INTERNAL;
            set_element(p0, (void*) &i, p11, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set language internal.
            i = *b + *SOCKET_LANGUAGE_INTERNAL;
            set_element(p0, (void*) &i, p12, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_LANGUAGE_COUNT_INTERNAL;
            set_element(p0, (void*) &i, p13, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set communication style internal.
            i = *b + *SOCKET_STYLE_INTERNAL;
            set_element(p0, (void*) &i, p14, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_STYLE_COUNT_INTERNAL;
            set_element(p0, (void*) &i, p15, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Unlock socket mutex.
            pthread_mutex_unlock(*mt);

            // Only create thread, if not existent.
            // The "pthread_t" type is an integer, so both can be compared.
            if (*t == *NUMBER_MINUS_1_INTEGER) {

                // Create thread.
                //
                // CAUTION! Do NOT allocate any resources within the thread procedure!
                // The reason is that this main process thread gets forked when executing
                // external programs. A "fork" duplicates ALL resources of the parent process,
                // including ALL resources of any threads running within the parent process.
                // However, since the created child process does not have those threads running,
                // their duplicated resources will never be deallocated, which eats up memory.
                // See source code file: applicator/run/run_execute.c
                //
                // Any dynamically allocated resources needed within the thread have to be:
                // - allocated at service startup
                // - added to the internal memory
                // - handed over to the thread procedure HERE
                // - deallocated at service shutdown

                log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Create socket sense thread.");

                // Create thread.
                // The third parameter is the procedure to be called.
                pthread_create((pthread_t*) t, *NULL_POINTER, p3, p0);
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket. The base internal is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense socket. The service thread is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SENSE_SOCKET_SOURCE */
#endif
