/*
 * $RCSfile: unix_socket.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file handles a server UNIX FILE socket.
 *
 * @version $Revision: 1.1 $ $Date: 2004-12-06 14:34:54 $ $Author: reichenbach $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_SOCKET_SOURCE
#define UNIX_SOCKET_SOURCE

#include <sys/socket.h>
#include <sys/un.h>
#include "../accessor/compound_accessor.c"
#include "../global/constant.c"
#include "../global/variable.c"

/**
 * Creates the unix socket.
 *
 * @param p0 the socket
 * @param p1 the filename
 */
void create_unix_socket(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        void** n = (void**) p1;

        if (p0 != NULL_POINTER) {

            int* s = (int*) p0;

            // Open socket and get its number.
            // AF stands for address format. AF_LOCAL is a synonym for AF_UNIX.
            // AF_LOCAL is mandated by POSIX.1g but AF_UNIX is portable to more systems.
            // AF_UNIX was the traditional name stemming from BSD, so even most POSIX
            // systems support it. It is also the name of choice in the Unix98
            // specification.
            // AF_FILE is another synonym for AF_LOCAL, for compatibility.
            // 0 stands for the default protocol (recommended).
            *s = socket(AF_UNIX, SOCK_STREAM, 0);

            // Make socket non-blocking.
//??            fcntl(*s, F_SETFL, FNDELAY);

            // Initialize socket address.
            struct sockaddr_un a;
            // Set address format.
            a.sun_family = AF_UNIX;
            // Set path/file name to use as socket address.
            strcpy(a.sun_path, (char*) *n);
//??            strncpy(a.sun_path, *sn, sizeof(a.sun_path));

            // CAUTION! The path/file length is normally limited to 108.
            // This solution works around that limitation by determining
            // the real path/file size.

            // Determine socket address size.
            int as = sizeof(struct sockaddr_un);
//??            int as = (offsetof(struct sockaddr_un, sun_path) + strlen(a.sun_path) + 1);

            // Bind number to address.
            bind(*s, (struct sockaddr*) &a, as);

            // Set the number of possible pending client connection requests.
            // The maximum number is usually 5.
            // It is NOT necessary to use this function, but it's good practice.
            listen(*s, 1);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Destroys the unix socket.
 *
 * @param p0 the socket
 * @param p1 the filename
 */
void destroy_unix_socket(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        void** n = (void**) p1;

        if (p0 != NULL_POINTER) {

            int* s = (int*) p0;

            // Close socket.
            close(*s);

            // Unlink socket.
            unlink((char*) *n);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sends a unix socket output.
 *
 * @param p0 the receiver address
 * @param p1 the receiver address count
 * @param p2 the message
 * @param p3 the message count
 */
void send_unix_socket(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5) {

    if (p3 != NULL_POINTER) {

        int* mc = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** m = (void**) p2;

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTERNALS_MESSAGE, (void*) &CREATE_INTERNALS_MESSAGE_COUNT);

            // Open socket and get its number.
            // AF stands for address format. AF_LOCAL is a synonym for AF_UNIX.
            // AF_LOCAL is mandated by POSIX.1g but AF_UNIX is portable to more systems.
            // AF_UNIX was the traditional name stemming from BSD, so even most POSIX
            // systems support it. It is also the name of choice in the Unix98
            // specification.
            // AF_FILE is another synonym for AF_LOCAL, for compatibility.
            // 0 stands for the default protocol (recommended).
            int s = socket(AF_UNIX, SOCK_STREAM, 0);

            // Initialize unix socket filename and its count.
            void* n = NULL_POINTER;
            int nc = 0;

/*??
            // Get unix socket filename and its count.
            get_compound_part_by_name(p0, p1, (void*) &NULL_POINTER,
                (void*) &UNIX_SOCKET_FILENAME_NAME, (void*) &UNIX_SOCKET_FILENAME_NAME_COUNT, (void*) &NULL_POINTER,
                (void*) &n, (void*) &nc, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
*/

            // Initialize socket address.
            struct sockaddr_un a;
            // Set address format.
            a.sun_family = AF_UNIX;
            // Set filename.
            strcpy(a.sun_path, n);
//??            strncpy(a.sun_path, n, sizeof(a.sun_path));

            // CAUTION! The path/file length is normally limited to 108.
            // This solution works around that limitation by determining
            // the real path/file size.

            // Determine socket address size.
            int as = sizeof(struct sockaddr_un);
//??            int as = (offsetof(struct sockaddr_un, sun_path) + strlen(a.sun_path) + 1);

            // Establish connection.
            // Note that connect implicitly performs a bind call,
            // which is unnecessary here, since cyboi stores the
            // server socket that was created and bound at system startup,
            // and that server socket was handed over to this procedure.
            connect(s, (struct sockaddr*) &a, as);

            // Convert message to avoid byte-order problems. Many machines
            // use differing dialects (ASCII versus EBCDIC) to represent data.
            // The byte-order problem does NOT occur if data are exclusively
            // passed as text, for example as serialized cybol file.
//??            m = htonl(m);

            // Write message to socket.
            write(s, (char*) *m, *mc);

            // Close socket.
            close(s);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Receives a unix socket input.
 *
 * @param p0 the server socket
 */
void receive_unix_socket(const void* p0) {

    if (p0 != NULL_POINTER) {

        int* s = (int*) p0;

//??        log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTERNALS_MESSAGE, (void*) &CREATE_INTERNALS_MESSAGE_COUNT);

        // Initialize client socket address and its size.
        struct sockaddr_un ca;
        int cas = sizeof(ca);

        // CAUTION! This might block further processing!
        // The accept function waits if there are no connections pending,
        // unless the socket socket has nonblocking mode set. One can use
        // select to wait for a pending connection, with a nonblocking socket.
        // The return value is the file descriptor for the new client socket.

        // Accept client socket request and store client socket.
        int cs = accept(*s, (struct sockaddr*) &ca, &cas);

        // Receive message from socket.
//??        read(cs, (char*) *m, *mc);

        // Convert message to avoid byte-order problems. Many machines
        // use differing dialects (ASCII versus EBCDIC) to represent data.
        // The byte-order problem does NOT occur if data are exclusively
        // passed as text, for example as serialized cybol file.
//??        m = ntohl(m);

        close(cs);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }
}

/* UNIX_SOCKET_SOURCE */
#endif
