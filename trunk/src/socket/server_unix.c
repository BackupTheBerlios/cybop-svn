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
 * @version $Revision: 1.3 $ $Date: 2004-06-24 11:45:37 $ $Author: christian $
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

int main() {

    int server_socketnummer, client_socketnummer;
    int server_laenge, client_laenge;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    // Unlink previous server socket with similar name.
    unlink("server_socket");
    server_socketnummer = socket(AF_UNIX,SOCK_STREAM,0);

    server_address.sun_family=AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");

    server_laenge = sizeof(server_address);
    bind(server_socketnummer, (struct sockaddr*) &server_address, server_laenge);

    char ch;
    char strg[sizeof *stdin];

    // This might BLOCK further processing!!!
    // 5 might?? mean the number of possible clients which can be served!
    listen(server_socketnummer, 5);
    // Once listen is left, it is -- in this example -- not entered again!
    // Implement this later!

    client_laenge = sizeof(client_address);
    client_socketnummer = accept(server_socketnummer, (struct sockaddr*) &client_address, &client_laenge);

    char hello[300] = "Hallo!";

    int j = 0;

    while(1) {

        if (j == 10) {

            break;
        }

        read(client_socketnummer,&strg,300);
        strcat(strg,hello);
        write(client_socketnummer,&strg,300);

        j++;
    }

    close(client_socketnummer);
    close(server_socketnummer);
}

/* SERVER_UNIX_SOURCE */
#endif
