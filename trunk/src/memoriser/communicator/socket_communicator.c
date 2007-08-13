/*
 * $RCSfile: socket_communicator.c,v $
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
 * This file contains the functionality to:
 * - receive an http stream into a byte array
 * - send an http stream from a byte array
 *
 * @version $Revision: 1.11 $ $Date: 2007-08-13 16:37:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SOCKET_COMMUNICATOR_SOURCE
#define SOCKET_COMMUNICATOR_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

/**
 * Reads a byte array stream from the socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source socket
 * @param p4 the source count
 */
/*??
void read_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {
}
*/

/**
 * Writes a byte array stream to the stream socket in server mode by doing one single transfer.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void write_socket_stream_server_mode_single_transfer(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER) {

            int* sc = (int*) p2;

            if (p0 != *NULL_POINTER) {

                int* d = (int*) p0;

                log_message_debug("Information: Write to stream socket in server mode.");

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
                *n = send(*d, p1, *sc, *NUMBER_0_INTEGER);

                if (*n < *NUMBER_0_INTEGER) {

                    if (errno == EBADF) {

                        log_message_debug("Error: Could not write to stream socket in server mode. The socket argument is not a valid file descriptor.");

                    } else if (errno == EINTR) {

                        log_message_debug("Error: Could not write to stream socket in server mode. The operation was interrupted by a signal before any data was sent.");

                    } else if (errno == ENOTSOCK) {

                        log_message_debug("Error: Could not write to stream socket in server mode. The descriptor socket is not a socket.");

                    } else if (errno == EMSGSIZE) {

                        log_message_debug("Error: Could not write to stream socket in server mode. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                    } else if (errno == EWOULDBLOCK) {

                        log_message_debug("Error: Could not write to stream socket in server mode. Nonblocking mode has been set on the socket, and the write operation would block.");

                        //?? TODO: DELETE the following comment block OR the log message above!

                        // CAUTION! Do NOT log the following error:
                        // log_message_debug("Error: Could not write to stream socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                        //
                        // The reason is that the socket is non-blocking,
                        // so that the "accept" procedure returns always,
                        // even if no connection was established,
                        // which would unnecessarily fill up the log file.

                    } else if (errno == ENOBUFS) {

                        log_message_debug("Error: Could not write to stream socket in server mode. There is not enough internal buffer space available.");

                    } else if (errno == ENOTCONN) {

                        log_message_debug("Error: Could not write to stream socket in server mode. You never connected this socket.");

                    } else if (errno == EPIPE) {

                        log_message_debug("Error: Could not write to stream socket in server mode. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                    } else {

                        log_message_debug("Error: Could not write to stream socket in server mode. An unknown error occured.");
                    }
                }

            } else {

                log_message_debug("Error: Could not write to stream socket in server mode. The socket of this system is null.");
            }

        } else {

            log_message_debug("Error: Could not write to stream socket in server mode. The source count is null.");
        }

    } else {

        log_message_debug("Error: Could not write to stream socket in server mode. The number of transferred bytes is null.");
    }
}

/**
 * Writes a byte array stream to the stream socket in server mode.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source count
 */
void write_socket_stream_server_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* sc = (int*) p2;

        log_message_debug("Information: Write to stream socket in server mode.");

        // The byte array index to start the transfer at.
        void* i = p1;
        // The number of bytes transferred.
        int n = *NUMBER_0_INTEGER;

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling the procedure
        // that might cause an error.
        errno = *NUMBER_0_INTEGER;

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
        while (*NUMBER_1_INTEGER) {

            if (*sc <= *NUMBER_0_INTEGER) {

                break;
            }

            write_socket_stream_server_mode_single_transfer(p0, i, p2, (void*) &n);

            // Increment byte array index.
            i = i + n;
            // Decrement byte array count.
            *sc = *sc - n;
        }

    } else {

        log_message_debug("Error: Could not write to stream socket in server mode. The source count is null.");
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
void write_socket_stream_client_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        socklen_t* as = (socklen_t*) p2;

        if (p1 != *NULL_POINTER) {

            struct sockaddr** a = (struct sockaddr**) p1;

            if (p0 != *NULL_POINTER) {

                int* d = (int*) p0;

                log_message_debug("Information: Write to stream socket in client mode.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER;

                // Connect this system whose socket is given
                // to another system whose address is given.
                int r = connect(*d, *a, *as);

                if (r < *NUMBER_0_INTEGER) {

                    if (errno == EBADF) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The socket is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

                        log_message_debug("Error: Could not write to stream socket in client mode. File descriptor socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The specified address is not available on the remote machine.");

                    } else if (errno == EAFNOSUPPORT) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The namespace of the addr is not supported by this socket.");

                    } else if (errno == EISCONN) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The socket is already connected.");

                    } else if (errno == ETIMEDOUT) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The attempt to establish the connection timed out.");

                    } else if (errno == ECONNREFUSED) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The server has actively refused to establish the connection.");

                    } else if (errno == ENETUNREACH) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The network of the given address is not reachable from this host.");

                    } else if (errno == EADDRINUSE) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The given socket address is already in use.");

                    } else if (errno == EINPROGRESS) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The socket is non-blocking and the connection could not be established immediately.");

                    } else if (errno == EALREADY) {

                        log_message_debug("Error: Could not write to stream socket in client mode. The socket is non-blocking and already has a pending connection in progress.");

                    } else {

                        log_message_debug("Error: Could not write to stream socket in client mode. An unknown error occured.");
                    }
                }

            } else {

                log_message_debug("Error: Could not write to stream socket in client mode. The socket of this system is null.");
            }

        } else {

            log_message_debug("Error: Could not write to stream socket in client mode. The socket address is null.");
        }

    } else {

        log_message_debug("Error: Could not write to stream socket in client mode. The socket address size is null.");
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
void write_socket_stream(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_debug("Information: Write to stream socket.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) SERVER_COMMUNICATION_MODE_MODEL, (void*) SERVER_COMMUNICATION_MODE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Send message to destination socket.
            write_socket_stream_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p5, p6, (void*) CLIENT_COMMUNICATION_MODE_MODEL, (void*) CLIENT_COMMUNICATION_MODE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Connect this system whose socket is given to
            // another system whose address is given.
            write_socket_stream_client_mode(p0, p3, p4);
            // Send message to destination socket.
            write_socket_stream_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_message_debug("Error: Could not write to stream socket. The communication mode is unknown.");
    }
}

/**
 * Writes a byte array stream to the datagram socket.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source count
 * @param p3 the receiver socket address (Hand over as reference!)
 * @param p4 the receiver socket address size
 */
void write_socket_dgram(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        socklen_t* as = (socklen_t*) p4;

        if (p3 != *NULL_POINTER) {

            struct sockaddr** a = (struct sockaddr**) p3;

            if (p2 != *NULL_POINTER) {

                int* sc = (int*) p2;

                if (p0 != *NULL_POINTER) {

                    int* d = (int*) p0;

                    log_message_debug("Information: Write to datagram socket.");

                    // Send to socket and return result.
                    int r = sendto(*d, p1, *sc, *NUMBER_0_INTEGER, *a, *as);

                    if (r < *NUMBER_0_INTEGER) {

                        if (errno == EBADF) {

                            log_message_debug("Error: Could not write to datagram socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == EINTR) {

                            log_message_debug("Error: Could not write to datagram socket. The operation was interrupted by a signal before any data was sent.");

                        } else if (errno == ENOTSOCK) {

                            log_message_debug("Error: Could not write to datagram socket. The descriptor socket is not a socket.");

                        } else if (errno == EMSGSIZE) {

                            log_message_debug("Error: Could not write to datagram socket. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                        } else if (errno == EWOULDBLOCK) {

                            log_message_debug("Error: Could not write to datagram socket. Nonblocking mode has been set on the socket, and the write operation would block.");

                            //?? TODO: DELETE the following comment block OR the log message above!

                            // CAUTION! Do NOT log the following error:
                            // log_message_debug("Error: Could not write to datagram socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established,
                            // which would unnecessarily fill up the log file.

                        } else if (errno == ENOBUFS) {

                            log_message_debug("Error: Could not write to datagram socket. There is not enough internal buffer space available.");

                        } else if (errno == ENOTCONN) {

                            log_message_debug("Error: Could not write to datagram socket. You never connected this socket.");

                        } else if (errno == EPIPE) {

                            log_message_debug("Error: Could not write to datagram socket. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                        } else {

                            log_message_debug("Error: Could not write to datagram socket. An unknown error occured.");
                        }
                    }

                } else {

                    log_message_debug("Error: Could not write to datagram socket. The socket of this system is null.");
                }

            } else {

                log_message_debug("Error: Could not write to datagram socket. The source count is null.");
            }

        } else {

            log_message_debug("Error: Could not write to datagram socket. The receiver socket address is null.");
        }

    } else {

        log_message_debug("Error: Could not write to datagram socket. The receiver socket address size is null.");
    }
}

/**
 * Writes a byte array stream to the raw socket.
 */
void write_socket_raw() {

    // Not implemented.
    log_message_debug("Information: Write to raw socket.");
    log_message_debug("Error: The raw socket functionality is NOT implemented!");
}

/**
 * Writes a byte array stream to the socket.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source count
 * @param p3 the socket address of the communication partner (Hand over as reference!)
 * @param p4 the socket address size
 * @param p5 the communication mode
 * @param p6 the communication mode count
 * @param p7 the communication style
 */
void write_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER) {

        int* st = (int*) p7;

        log_message_debug("Information: Write to socket.");

        if (*st == SOCK_STREAM) {

            write_socket_stream(p0, p1, p2, p3, p4, p5, p6);

        } else if (*st == SOCK_DGRAM) {

            write_socket_dgram(p0, p1, p2, p3, p4);

        } else if (*st == SOCK_RAW) {

            write_socket_raw();

        } else {

            log_message_debug("Error: Could not write to socket. The communication style is unknown.");
        }

    } else {

        log_message_debug("Error: Could not write to socket. The communication style is null.");
    }
}

/* SOCKET_COMMUNICATOR_SOURCE */
#endif
