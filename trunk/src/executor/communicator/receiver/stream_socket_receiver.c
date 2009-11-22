/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: stream_socket_communicator.c,v $ $Revision: 1.15 $ $Date: 2009-02-08 22:34:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_SOCKET_RECEIVER_SOURCE
#define STREAM_SOCKET_RECEIVER_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/cybol/communication_mode_cybol_model.c"
#include "../../constant/model/cybol/http_request_cybol_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Receives a byte array stream from the stream socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination byte array count
 * @param p2 the destination byte array size
 * @param p3 the source communication partner-connected socket of this system
 *           (the client socket to accept, receive data from and attach as parameter to the
 *           cyboi signal generated later, so that this server may reply to the correct client)
 */
void receive_stream_socket(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ps = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* bs = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* bc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** b = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive stream socket.");

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Receive message from client.
                    //
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" procedure.
                    // Normally, "recv" blocks until there is input available to be read.
                    //
                    // CAUTION! A message MUST NOT be longer than the given buffer size!
                    *bc = recv(*ps, *b, *((size_t*) bs), *NUMBER_0_INTEGER_MEMORY_MODEL);

                    if (*bc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Successfully received stream socket.");

                    } else if (*bc == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. No data could be sensed.");

                    } else {

                        if (errno == EBADF) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The descriptor socket is not a socket.");

                        } else if (errno == EWOULDBLOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The read operation would block even though nonblocking mode has been set on the socket.");

                        } else if (errno == EINTR) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The operation was interrupted by a signal before any data was received.");

                        } else if (errno == ENOTCONN) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The socket was never connected.");

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. An unknown error occured while receiving data.");
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The buffer is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The buffer count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The buffer size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not receive stream socket. The partner-connected socket of this system is null.");
    }
}

/* STREAM_SOCKET_RECEIVER_SOURCE */
#endif
