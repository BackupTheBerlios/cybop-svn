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
 * @version $Revision: 1.4 $ $Date: 2004-06-27 00:59:43 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVER_UNIX_SOURCE
#define SERVER_UNIX_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>

/**
 * Creates a unix socket.
 */
void create_unix_socket() {

    static const char SOCKET_NAME_ARRAY[] = {'s', 'o', 'c', 'k', 'e', 't', '\0'};
    static const char* SOCKET_NAME = SOCKET_NAME_ARRAY;
    static const int SOCKET_NAME_COUNT = 7;

    // Unlink previous socket with identical name.
//??    unlink(SOCKET_NAME);

    // Open socket and get its number.
    int n = socket(AF_UNIX, SOCK_STREAM, 0);

    // The socket address.
    struct sockaddr_un a;
    // Set unix family.
    a.sun_family = AF_UNIX;
    // Set path.
    strcpy(a.sun_path, SOCKET_NAME);

    // The socket address size.
    int s = sizeof(a);

    // Bind number to address.
    bind(n, (struct sockaddr*) &a, s);

    // Listen at socket.
    // CAUTION! This might block further processing!
    // The number (5) might mean the number of possible clients which can be served.
    listen(n, 5);
    // Once listen is left, it is -- in this example -- not entered again!
    // Implement this later!

/*??
    // The following is client stuff.
    struct sockaddr_un client_address;
    int client_laenge = sizeof(client_address);
    int client_socketnummer = accept(server_socket_number, (struct sockaddr*) &client_address, &client_laenge);

    char ch;
    char strg[sizeof *stdin];
    char hello[300] = "Hallo!";
    int j = 0;

    while(1) {

        if (j == 10) {

            break;
        }

        read(client_socketnummer, &strg, 300);
        strcat(strg, hello);
        write(client_socketnummer, &strg, 300);

        j++;
    }

    close(client_socketnummer);
*/

    // Close socket.
    close(n);
}

/* SERVER_UNIX_SOURCE */
#endif
