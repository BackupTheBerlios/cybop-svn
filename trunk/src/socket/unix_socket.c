/*
 * $RCSfile: unix_socket.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.29 $ $Date: 2005-08-09 13:04:27 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_SOCKET_SOURCE
#define UNIX_SOCKET_SOURCE

#include <sys/socket.h>
#include <sys/un.h>
#include "../globals/constants/constant.c"
#include "../globals/constants/integer_constants.c"
#include "../globals/variables/variables.c"
#include "../memoriser/accessor.c"

/**
 * Allocates the unix server socket.
 *
 * @param p0 the internals memory
 */
void allocate_unix_server_socket(void* p0) {

    // The unix server socket filename.
    void* f = NULL_POINTER;

    // Get unix server socket filename.
    get(p0, (void*) UNIX_SERVER_SOCKET_FILENAME_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (f != NULL_POINTER) {

        log_message_debug("Allocate unix server socket.");

        // The unix server socket.
        int* s = NULL_POINTER;

        // Create unix server socket.
        allocate((void*) &s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Open socket and get its number.
        // AF stands for address format. AF_LOCAL is a synonym for AF_UNIX.
        // AF_LOCAL is mandated by POSIX.1g but AF_UNIX is portable to more systems.
        // AF_UNIX was the traditional name stemming from BSD, so even most POSIX
        // systems support it. It is also the name of choice in the Unix98
        // specification.
        // AF_FILE is another synonym for AF_LOCAL, for compatibility.
        // 0 stands for the default protocol (recommended).
        *s = socket(AF_UNIX, SOCK_STREAM, 0);

        // Set unix server socket.
        set(p0, (void*) UNIX_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if (*s >= 0) {

            fprintf(stderr, "DEBUG: The unix server socket is: %d \n", *s);

            // Make socket non-blocking.
//??            fcntl(*s, F_SETFL, FNDELAY);

            // The socket address.
            struct sockaddr_un a;

            // Set address format.
            a.sun_family = AF_UNIX;

            // Set path/file name to use as socket address.
            strcpy(a.sun_path, (char*) f);
//??            strncpy(a.sun_path, *f, sizeof(a.sun_path));

            // CAUTION! The path/file length is normally limited to 108.
            // This solution works around that limitation by determining
            // the real path/file size.

            // Determine socket address size.
            int as = sizeof(struct sockaddr_un);
//??            int as = (offsetof(struct sockaddr_un, sun_path) + strlen(a.sun_path) + 1);

            // Bind number to address.
            if (bind(*s, (struct sockaddr*) &a, as) >= 0) {

                // Set the number of possible pending client connection requests.
                // The maximum number is usually 5.
                // It is NOT necessary to use this function, but it's good practice.
                listen(*s, 1);

            } else {

                log_message_debug("Could not create unix server socket. The socket could not be bound to the address.");
            }

        } else {

            log_message_debug("Could not create unix server socket. The socket is smaller than zero.");
        }

    } else {

        log_message_debug("Could not create unix server socket. The filename is null.");
    }
}

/**
 * Deallocates the unix server socket.
 *
 * @param p0 the internals memory
 */
void deallocate_unix_server_socket(void* p0) {

    // The unix server socket filename.
    void* f = NULL_POINTER;

    // Get unix server socket filename.
    get(p0, (void*) UNIX_SERVER_SOCKET_FILENAME_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (f != NULL_POINTER) {

        // The unix server socket.
        int* s = NULL_POINTER;

        // Get unix server socket.
        get(p0, (void*) UNIX_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if (s != NULL_POINTER) {

            log_message_debug("Deallocate unix server socket.");

            // Close socket.
            close(*s);

            // Unlink socket.
            unlink((char*) f);

            // Destroy unix server socket.
            deallocate((void*) &s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        } else {

            log_message_debug("Could not destroy unix server socket. The socket is null.");
        }

    } else {

        log_message_debug("Could not destroy unix server socket. The filename is null.");
    }
}

/**
 * Writes to unix socket.
 *
 * @param p0 the internals memory
 */
void write_unix_socket(void* p0) {

/*??
@param p0 the receiver address
@param p1 the receiver address count
@param p2 the message
@param p3 the message count
*/

/*??
    if (p3 != NULL_POINTER) {

        int** mc = (int**) p3;

        if (p2 != NULL_POINTER) {

            void** m = (void**) p2;

            log_message_debug("Write to unix socket.");

            // Open socket and get its number.
            // AF stands for address format. AF_LOCAL is a synonym for AF_UNIX.
            // AF_LOCAL is mandated by POSIX.1g but AF_UNIX is portable to more systems.
            // AF_UNIX was the traditional name stemming from BSD, so even most POSIX
            // systems support it. It is also the name of choice in the Unix98
            // specification.
            // AF_FILE is another synonym for AF_LOCAL, for compatibility.
            // 0 stands for the default protocol (recommended).
            int s = socket(AF_UNIX, SOCK_STREAM, 0);

            // Initialise unix socket filename and its count.
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

/*??
            // Initialise socket address.
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
            // passed as text, for example as serialised cybol file.
//??            m = htonl(m);

            // Write message to socket.
            write(s, (char*) *m, **mc);

            // Close socket.
            close(s);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }
*/
}

/**
 * Reads from unix socket.
 *
 * @param p0 the internals memory
 */
void read_unix_socket(void* p0) {

    // The unix server socket.
    int* s = NULL_POINTER;

    // Get unix server socket.
    get(p0, (void*) UNIX_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (s != NULL_POINTER) {

        log_message_debug("Read from unix socket.");

        // The client socket address.
        struct sockaddr_un ca;

        // Determine client socket address size.
        int cas = sizeof(ca);

        // CAUTION! This might block further processing!
        // The accept function waits if there are no connections pending,
        // unless the socket socket has nonblocking mode set. One can use
        // select to wait for a pending connection, with a nonblocking socket.
        // The return value is the file descriptor for the new client socket.

        // Accept client socket request and store client socket.
        int cs = accept(*s, (struct sockaddr*) &ca, &cas);

        if (cs >= 0) {

            log_message_debug("DEBUG: Accepted unix client socket request.");

            // Read message from socket.
//??            read(cs, (char*) *m, *mc);

            // Convert message to avoid byte-order problems. Many machines
            // use differing dialects (ASCII versus EBCDIC) to represent data.
            // The byte-order problem does NOT occur if data are exclusively
            // passed as text, for example as serialised cybol file.
//??            m = ntohl(m);

            close(cs);

        } else {

            fprintf(stderr, "Could not read unix server socket. The accept failed.");
        }

    } else {

        log_message_debug("Could not read unix server socket. The socket is null.");
    }
}

/* UNIX_SOCKET_SOURCE */
#endif
