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
 * @version $RCSfile: datagram_socket_communicator.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATAGRAM_SOCKET_RECEIVER_SOURCE
#define DATAGRAM_SOCKET_RECEIVER_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/comparator/count_array_comparator.c"

/**
 * Receives a byte array stream from the datagram socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (original socket address of this system)
 * @param p4 the source count (original socket address of this system size)
 * @param p5 the original socket of this system
 */
void receive_datagram_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* os = (int*) p5;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* bs = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* bc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** b = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive from datagram socket.");

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Sense message from client.
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" procedure.
                    // Normally, "recv" blocks until there is input available to be read.
                    // ?? Not so here, as the socket was set to "non-blocking" mode at startup. ??
                    //
                    // CAUTION! A message MUST NOT be longer than the given buffer size!
                    *bc = recvfrom(*os, *b, *bs, *NUMBER_0_INTEGER_MEMORY_MODEL, (struct sockaddr*) p3, (socklen_t*) p4);

                    if (*bc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Successfully received from datagram socket.");

                        fwprintf(stdout, L"TEST b: %s \n", (char*) *b);
                        fwprintf(stdout, L"TEST bc: %i \n", *bc);
                        fwprintf(stdout, L"TEST bs: %i \n", *bs);

                    } else if (*bc == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. No data could be sensed.");

                    } else {

                        if (errno == EBADF) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The descriptor socket is not a socket.");

                        } else if (errno == EWOULDBLOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The receive operation would block even though nonblocking mode has been set on the socket.");

                        } else if (errno == EINTR) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The operation was interrupted by a signal before any data was receive.");

                        } else if (errno == ENOTCONN) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The socket was never connected.");

                        } else {

                            // CAUTION! Do NOT log the following error:
                            // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense stream socket message. An unknown error occured while receiving data.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established.
                            // But if no connection and client socket are there,
                            // then the "recv" or "recvfrom" procedure returns an error,
                            // which would unnecessarily fill up the log file.
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The buffer is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The buffer count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The buffer size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive from datagram socket. The original socket of this system is null.");
    }
}

/* DATAGRAM_SOCKET_RECEIVER_SOURCE */
#endif
