/*
 * $RCSfile: server_unix.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2004-06-29 13:57:26 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVER_UNIX_SOURCE
#define SERVER_UNIX_SOURCE

//??#include <stdio.h>
//??#include <unistd.h>
#include <sys/socket.h>
//??#include <sys/types.h>
#include <sys/un.h>
#include "../global/variable.c"

/**
 * Creates the unix socket.
 *
 * @param p0 the socket
 * @param p1 the socket name
 */
void create_unix_socket(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        char** sn = (char**) p1;

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

            // Initialize socket address.
            struct sockaddr_un a;
            // Set address format.
            a.sun_family = AF_UNIX;
            // Set path/file name to use as socket address.
            strcpy(a.sun_path, *sn);
//??            strncpy(a.sun_path, *sn, sizeof(a.sun_path));

            // CAUTION! The path/file length is normally limited to 108.
            // This solution works around that limitation by determining
            // the real path/file size.

            // Determine socket address size.
            int as = sizeof(struct sockaddr_un);
//??            int as = (offsetof(struct sockaddr_un, sun_path) + strlen(a.sun_path) + 1);

            // Bind number to address.
            bind(*s, (struct sockaddr*) &a, as);

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
 * @param p1 the socket name
 */
void destroy_unix_socket(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        char** sn = (char**) p1;

        if (p0 != NULL_POINTER) {

            int* s = (int*) p0;

            // Close socket.
            close(*s);

            // Unlink socket.
            unlink(*sn);

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
 * @param p0 the socket
 */
void receive_unix_socket_input(void* p0) {

    if (p0 != NULL_POINTER) {

        int* s = (int*) p0;

//??        log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTERNALS_MESSAGE, (void*) &CREATE_INTERNALS_MESSAGE_COUNT);

        // Listen for client connection requests.
        // The second parameter specifies the allowed number of pending
        // connection requests of clients which want to be served.
        listen(*s, 1);
        // Once listen is left, it is -- in this example -- not entered again!
        // Implement this later!

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
        // TODO: Set O_NONBLOCK flag for nonblocking mode! How??

        // After accept, the original socket *s remains open and unconnected,
        // and continues listening until being closed.
        // One can accept further connections with socket by calling accept again.

/*??
        char ch;
        char strg[sizeof *stdin];
        char hello[300] = "Hallo!";
        int j = 0;

        while(1) {

            if (j == 10) {

                break;
            }

            read(cs, &strg, 300);
            strcat(strg, hello);
            write(cs, &strg, 300);

            j++;
        }

        close(cs);
*/

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }
}

/* SERVER_UNIX_SOURCE */
#endif
