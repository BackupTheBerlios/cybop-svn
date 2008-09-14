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
 * @version $RCSfile: stream_socket_communicator.c,v $ $Revision: 1.9 $ $Date: 2008-09-14 08:25:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_SOCKET_COMMUNICATOR_SOURCE
#define STREAM_SOCKET_COMMUNICATOR_SOURCE

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
 * Reads a byte array stream from the stream socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source communication partner-connected socket of this system
 *           (the client socket to accept, receive data from and attach as parameter to the
 *           cyboi signal generated later, so that this server may reply to the correct client)
 */
void read_stream_socket_data(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        size_t* bs = (size_t*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* bc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** b = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Read stream socket data.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
            fwprintf(stderr, L"TEST: sense socket thread client socket: %i \n", *ps);
*/

    fwprintf(stderr, L"TEST pre b: %s \n", (char*) *b);
    fwprintf(stderr, L"TEST pre bc: %i \n", *bc);
    fwprintf(stderr, L"TEST pre bs: %i \n", *bs);

/*??
                // Receive message from client.
                //
                // If the flags argument (fourth one) is zero, then one can
                // just as well use the "read" instead of the "recv" procedure.
                // Normally, "recv" blocks until there is input available to be read.
                // ?? Not so here, as the socket was set to "non-blocking" mode at startup. ??
                //
                // CAUTION! A message MUST NOT be longer than the given buffer size!
                *bc = recv(*ps, *b, *bs, *NUMBER_0_INTEGER_MEMORY_MODEL);
*/

    fwprintf(stderr, L"TEST post b: %s \n", (char*) *b);
    fwprintf(stderr, L"TEST post bc: %i \n", *bc);
    fwprintf(stderr, L"TEST post bs: %i \n", *bs);

                if (*bc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Successfully sensed stream socket message.");

                } else if (*bc = *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. No data could be sensed.");

                } else {

                    if (errno == EBADF) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The socket argument is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The descriptor socket is not a socket.");

                    } else if (errno == EWOULDBLOCK) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The read operation would block even though nonblocking mode has been set on the socket.");

                    } else if (errno == EINTR) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The operation was interrupted by a signal before any data was read.");

                    } else if (errno == ENOTCONN) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The socket was never connected.");

                    } else {

                        // CAUTION! Do NOT log the following error:
                        // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. An unknown error occured while receiving data.");
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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The buffer is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The buffer count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The buffer size is null.");
    }
}

/**
 * Reads a byte array stream from the stream socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source communication partner-connected socket of this system
 *           (the client socket to accept, receive data from and attach as parameter to the
 *           cyboi signal generated later, so that this server may reply to the correct client)
 */
void read_stream_socket(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ps = (int*) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Read stream socket.");

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling the procedure
        // that might cause an error.
        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
        if (*ps >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            read_stream_socket_data();

        } else {

            if (errno == EBADF) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense via stream socket. The socket argument is not a valid file descriptor.");

            } else if (errno == ENOTSOCK) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense via stream socket. The descriptor socket argument is not a socket.");

            } else if (errno == EOPNOTSUPP) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense via stream socket. The descriptor socket does not support this operation.");

            } else if (errno == EWOULDBLOCK) {

                // CAUTION! Do NOT log the following error:
                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense via stream socket. The socket has nonblocking mode set, and there are no pending connections immediately available.");
                //
                // The reason is that the socket is non-blocking,
                // so that the "accept" procedure returns always,
                // even if no connection was established,
                // which would unnecessarily fill up the log file.

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense via stream socket. An unknown error occured while accepting a socket connection.");
            }
        }
*/

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not read from stream socket. The partner-connected socket of this system is null.");
    }
}

/**
 * Writes a byte array stream to the stream socket in server mode by doing one single transfer.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source byte array count
 * @param p3 the number of bytes transferred
 */
void write_stream_socket_server_mode_single_transfer(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* sc = (int*) p2;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* d = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Write to stream socket in server mode.");

                // Send message to destination socket.
                //
                // If the flags argument (fourth one) is zero, then one can
                // just as well use the "write" instead of the "send" procedure.
                // If the socket is nonblocking, then "send" can return after
                // sending just PART OF the data.
                // Note, however, that a successful return value merely indicates
                // that the message has been SENT without error, NOT necessarily
                // that it has been received without error!
                //
                // The function returns the number of bytes transmitted
                // or -1 on failure.
                *n = send(*d, p1, *sc, *NUMBER_0_INTEGER_MEMORY_MODEL);

                if (*n < *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (errno == EBADF) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The socket argument is not a valid file descriptor.");

                    } else if (errno == EINTR) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The operation was interrupted by a signal before any data was sent.");

                    } else if (errno == ENOTSOCK) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The descriptor socket is not a socket.");

                    } else if (errno == EMSGSIZE) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                    } else if (errno == EWOULDBLOCK) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. Nonblocking mode has been set on the socket, and the write operation would block.");

                        //?? TODO: DELETE the following comment block OR the log message above!

                        // CAUTION! Do NOT log the following error:
                        // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                        //
                        // The reason is that the socket is non-blocking,
                        // so that the "accept" procedure returns always,
                        // even if no connection was established,
                        // which would unnecessarily fill up the log file.

                    } else if (errno == ENOBUFS) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. There is not enough internal buffer space available.");

                    } else if (errno == ENOTCONN) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. You never connected this socket.");

                    } else if (errno == EPIPE) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. An unknown error occured.");
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The socket of this system is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The source count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The number of transferred bytes is null.");
    }
}

/**
 * Writes a byte array stream to the stream socket in server mode.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source byte array count
 */
void write_stream_socket_server_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Write to stream socket in server mode.");

        // The byte array index to start the transfer at.
        void* i = p1;
        // The number of bytes transferred.
        int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling the procedure
        // that might cause an error.
        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // CAUTION! The send operation does not necessarily
        // handle all the bytes handed over to it, because
        // its major focus is handling the network buffers.
        // In general, it returns when the associated
        // network buffers have been filled.
        // It then returns the number of handled bytes.
        //
        // The "sent" operation therefore has to be
        // CALLED AGAIN AND AGAIN, in a loop, until
        // the complete message has been transmitted!
        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*sc <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            write_stream_socket_server_mode_single_transfer(p0, i, p2, (void*) &n);

            // Increment byte array index.
            i = i + n;
            // Decrement byte array count.
            *sc = *sc - n;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in server mode. The source count is null.");
    }
}

/**
 * Writes a byte array stream to the stream socket in client mode.
 *
 * Connects this system whose socket is given to another system whose address is given.
 *
 * @param p0 the destination socket of this system
 * @param p1 the receiver socket address (Hand over as reference!)
 * @param p2 the receiver socket address size
 */
void write_stream_socket_client_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        socklen_t* as = (socklen_t*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            struct sockaddr** a = (struct sockaddr**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* d = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Write to stream socket in client mode.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Connect this system whose socket is given
                // to another system whose address is given.
                int r = connect(*d, *a, *as);

                if (r < *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if (errno == EBADF) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. File descriptor socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The specified address is not available on the remote machine.");

                    } else if (errno == EAFNOSUPPORT) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The namespace of the addr is not supported by this socket.");

                    } else if (errno == EISCONN) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket is already connected.");

                    } else if (errno == ETIMEDOUT) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The attempt to establish the connection timed out.");

                    } else if (errno == ECONNREFUSED) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The server has actively refused to establish the connection.");

                    } else if (errno == ENETUNREACH) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The network of the given address is not reachable from this host.");

                    } else if (errno == EADDRINUSE) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The given socket address is already in use.");

                    } else if (errno == EINPROGRESS) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket is non-blocking and the connection could not be established immediately.");

                    } else if (errno == EALREADY) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket is non-blocking and already has a pending connection in progress.");

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. An unknown error occured.");
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket of this system is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket address is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket in client mode. The socket address size is null.");
    }
}

/**
 * Writes a byte array stream to the stream socket.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source count
 * @param p3 the receiver socket address (Hand over as reference!)
 * @param p4 the receiver socket address size
 * @param p5 the communication mode
 * @param p6 the communication mode count
 */
void write_stream_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Write to stream socket.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p5, p6, (void*) SERVER_COMMUNICATION_MODE_MODEL, (void*) SERVER_COMMUNICATION_MODE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Send message to destination socket.
            write_stream_socket_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p5, p6, (void*) CLIENT_COMMUNICATION_MODE_MODEL, (void*) CLIENT_COMMUNICATION_MODE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Connect this system whose socket is given to
            // another system whose address is given.
            write_stream_socket_client_mode(p0, p3, p4);
            // Send message to destination socket.
            write_stream_socket_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not write to stream socket. The communication mode is unknown.");
    }
}

/* STREAM_SOCKET_COMMUNICATOR_SOURCE */
#endif
