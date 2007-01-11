/*
 * $RCSfile: socket_communicator.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2007-01-11 22:30:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SOCKET_COMMUNICATOR_SOURCE
#define SOCKET_COMMUNICATOR_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../globals/constants/structure_constants.c"
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
 * Writes a byte array stream to the socket.
 *
 * @param p0 the destination (receiver) socket address (Hand over as reference!)
 * @param p1 the destination (receiver) socket address count
 * @param p2 the destination (receiver) socket address size
 * @param p3 the source byte array
 * @param p4 the source count
 * @param p5 the sender socket (of this system itself)
 * @param p6 the communication style
 */
void write_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != NULL_POINTER) {

        int* st = (int*) p6;

        if (p5 != NULL_POINTER) {

            int* so = (int*) p5;

            if (p4 != NULL_POINTER) {

                int* sc = (int*) p4;

                if (p2 != NULL_POINTER) {

                    socklen_t* ds = (socklen_t*) p2;

                    if (p0 != NULL_POINTER) {

                        struct sockaddr** d = (struct sockaddr**) p0;

                        log_message_debug("Information: Write to socket.");

                        // The result.
                        int r = *INVALID_VALUE;

        fprintf(stderr, "TEST: write socket d: %i \n", *so);

                        if (*st == SOCK_STREAM) {

                            // Initialise error number.
                            // It is a global variable/ function and other operations
                            // may have set some value that is not wanted here.
                            //
                            // CAUTION! Initialise the error number BEFORE calling the procedure
                            // that might cause an error.
                            errno = *NUMBER_0_INTEGER;

                            // Connect this system whose socket is given
                            // to another system whose address is given.
                            r = connect(*so, *d, *ds);

                            if (r >= *NUMBER_0_INTEGER) {

                                // Reset result.
                                r = *INVALID_VALUE;

                                // Initialise error number.
                                // It is a global variable/ function and other operations
                                // may have set some value that is not wanted here.
                                //
                                // CAUTION! Initialise the error number BEFORE calling the procedure
                                // that might cause an error.
                                errno = *NUMBER_0_INTEGER;

                                // Send message to destination (server) socket.
                                // If the flags argument (fourth one) is zero, then one can
                                // just as well use the "write" instead of the "send" procedure.
                                // If the socket is nonblocking, then "send" can return after
                                // sending just PART OF the data.
                                // Note, however, that a successful return value merely indicates
                                // that the message has been SENT without error, NOT necessarily
                                // that it has been received without error!
                                // The function returns the number of bytes transmitted
                                // or -1 on failure.
                                r = send(*so, p3, *sc, *NUMBER_0_INTEGER);

                                if (r < *NUMBER_0_INTEGER) {

                                    if (errno == EBADF) {

                                        log_message_debug("Error: Could not write to socket. The socket argument is not a valid file descriptor.");

                                    } else if (errno == EINTR) {

                                        log_message_debug("Error: Could not write to socket. The operation was interrupted by a signal before any data was sent.");

                                    } else if (errno == ENOTSOCK) {

                                        log_message_debug("Error: Could not write to socket. The descriptor socket is not a socket.");

                                    } else if (errno == EMSGSIZE) {

                                        log_message_debug("Error: Could not write to socket. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                                    } else if (errno == EWOULDBLOCK) {

                                        log_message_debug("Error: Could not write to socket. Nonblocking mode has been set on the socket, and the write operation would block.");

                                        //?? TODO: DELETE the following comment block OR the log message above!

                                        // CAUTION! Do NOT log the following error:
                                        // log_message_debug("Error: Could not write to socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                                        //
                                        // The reason is that the socket is non-blocking,
                                        // so that the "accept" procedure returns always,
                                        // even if no connection was established,
                                        // which would unnecessarily fill up the log file.

                                    } else if (errno == ENOBUFS) {

                                        log_message_debug("Error: Could not write to socket. There is not enough internal buffer space available.");

                                    } else if (errno == ENOTCONN) {

                                        log_message_debug("Error: Could not write to socket. You never connected this socket.");

                                    } else if (errno == EPIPE) {

                                        log_message_debug("Error: Could not write to socket. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                                    } else {

                                        log_message_debug("Error: Could not write to socket. An unknown error occured.");
                                    }
                                }

                            } else {

                                if (errno == EBADF) {

                                    log_message_debug("Error: Could not write to socket. The socket is not a valid file descriptor.");

                                } else if (errno == ENOTSOCK) {

                                    log_message_debug("Error: Could not write to socket. File descriptor socket is not a socket.");

                                } else if (errno == EADDRNOTAVAIL) {

                                    log_message_debug("Error: Could not write to socket. The specified address is not available on the remote machine.");

                                } else if (errno == EAFNOSUPPORT) {

                                    log_message_debug("Error: Could not write to socket. The namespace of the addr is not supported by this socket.");

                                } else if (errno == EISCONN) {

                                    log_message_debug("Error: Could not write to socket. The socket is already connected.");

                                } else if (errno == ETIMEDOUT) {

                                    log_message_debug("Error: Could not write to socket. The attempt to establish the connection timed out.");

                                } else if (errno == ECONNREFUSED) {

                                    log_message_debug("Error: Could not write to socket. The server has actively refused to establish the connection.");

                                } else if (errno == ENETUNREACH) {

                                    log_message_debug("Error: Could not write to socket. The network of the given address is not reachable from this host.");

                                } else if (errno == EADDRINUSE) {

                                    log_message_debug("Error: Could not write to socket. The given socket address is already in use.");

                                } else if (errno == EINPROGRESS) {

                                    log_message_debug("Error: Could not write to socket. The socket is non-blocking and the connection could not be established immediately.");

                                } else if (errno == EALREADY) {

                                    log_message_debug("Error: Could not write to socket. The socket is non-blocking and already has a pending connection in progress.");

                                } else {

                                    log_message_debug("Error: Could not write to socket. An unknown error occured.");
                                }
                            }

                        } else if (*st == SOCK_DGRAM) {

                            r = sendto(*so, p3, *sc, *NUMBER_0_INTEGER, *d, *ds);

                            if (r < *NUMBER_0_INTEGER) {

                                if (errno == EBADF) {

                                    log_message_debug("Error: Could not write to socket. The socket argument is not a valid file descriptor.");

                                } else if (errno == EINTR) {

                                    log_message_debug("Error: Could not write to socket. The operation was interrupted by a signal before any data was sent.");

                                } else if (errno == ENOTSOCK) {

                                    log_message_debug("Error: Could not write to socket. The descriptor socket is not a socket.");

                                } else if (errno == EMSGSIZE) {

                                    log_message_debug("Error: Could not write to socket. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                                } else if (errno == EWOULDBLOCK) {

                                    log_message_debug("Error: Could not write to socket. Nonblocking mode has been set on the socket, and the write operation would block.");

                                    //?? TODO: DELETE the following comment block OR the log message above!

                                    // CAUTION! Do NOT log the following error:
                                    // log_message_debug("Error: Could not write to socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                                    //
                                    // The reason is that the socket is non-blocking,
                                    // so that the "accept" procedure returns always,
                                    // even if no connection was established,
                                    // which would unnecessarily fill up the log file.

                                } else if (errno == ENOBUFS) {

                                    log_message_debug("Error: Could not write to socket. There is not enough internal buffer space available.");

                                } else if (errno == ENOTCONN) {

                                    log_message_debug("Error: Could not write to socket. You never connected this socket.");

                                } else if (errno == EPIPE) {

                                    log_message_debug("Error: Could not write to socket. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                                } else {

                                    log_message_debug("Error: Could not write to socket. An unknown error occured.");
                                }
                            }

                        } else if (*st == SOCK_RAW) {

                            // Not implemented.

                        } else {

                            log_message_debug("Error: Could not write to socket. The communication style is unknown.");
                        }

                    } else {

                        log_message_debug("Error: Could not write to socket. The receiver socket address is null.");
                    }

                } else {

                    log_message_debug("Error: Could not write to socket. The receiver socket address size is null.");
                }

            } else {

                log_message_debug("Error: Could not write to socket. The source count is null.");
            }

        } else {

            log_message_debug("Error: Could not write to socket. The server socket of the sender (this system) is null. A server socket must be started up for this system, before messages can be sent to another system.");
        }

    } else {

        log_message_debug("Error: Could not write to socket. The communication style is null.");
    }
}

/* SOCKET_COMMUNICATOR_SOURCE */
#endif
