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
 * @version $RCSfile: datagram_socket_communicator.c,v $ $Revision: 1.6 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATAGRAM_SOCKET_COMMUNICATOR_SOURCE
#define DATAGRAM_SOCKET_COMMUNICATOR_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../constant/model/cybol/http_request_cybol_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Reads a byte array stream from the datagram socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (original socket address of this system)
 * @param p4 the source count (original socket address of this system size)
 * @param p5 the original socket of this system
 */
void read_datagram_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* os = (int*) p5;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* bs = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* bc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** b = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Read from datagram socket.");

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

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Successfully read from datagram socket.");

                        fwprintf(stderr, L"TEST b: %s \n", (char*) *b);
                        fwprintf(stderr, L"TEST bc: %i \n", *bc);
                        fwprintf(stderr, L"TEST bs: %i \n", *bs);

                    } else if (*bc = *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. No data could be sensed.");

                    } else {

                        if (errno == EBADF) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The descriptor socket is not a socket.");

                        } else if (errno == EWOULDBLOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The read operation would block even though nonblocking mode has been set on the socket.");

                        } else if (errno == EINTR) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The operation was interrupted by a signal before any data was read.");

                        } else if (errno == ENOTCONN) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The socket was never connected.");

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

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The buffer is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The buffer count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The buffer size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from datagram socket. The original socket of this system is null.");
    }
}

/**
 * Writes a byte array stream to the datagram socket.
 *
 * @param p0 the destination receiver socket address (Hand over as reference!)
 * @param p1 the destination receiver socket address size
 * @param p2 the destination socket of this system
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void write_datagram_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* s = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                socklen_t* as = (socklen_t*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    struct sockaddr** a = (struct sockaddr**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Write to datagram socket.");

                    // Send to socket and return result.
                    int r = sendto(*s, p3, *sc, *NUMBER_0_INTEGER_MEMORY_MODEL, *a, *as);

                    if (r < *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        if (errno == EBADF) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == EINTR) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The operation was interrupted by a signal before any data was sent.");

                        } else if (errno == ENOTSOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The descriptor socket is not a socket.");

                        } else if (errno == EMSGSIZE) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                        } else if (errno == EWOULDBLOCK) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. Nonblocking mode has been set on the socket, and the write operation would block.");

                            //?? TODO: DELETE the following comment block OR the log message above!

                            // CAUTION! Do NOT log the following error:
                            // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established,
                            // which would unnecessarily fill up the log file.

                        } else if (errno == ENOBUFS) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. There is not enough internal buffer space available.");

                        } else if (errno == ENOTCONN) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. You never connected this socket.");

                        } else if (errno == EPIPE) {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. An unknown error occured.");
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The socket of this system is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The source count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The receiver socket address is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to datagram socket. The receiver socket address size is null.");
    }
}

/* DATAGRAM_SOCKET_COMMUNICATOR_SOURCE */
#endif
