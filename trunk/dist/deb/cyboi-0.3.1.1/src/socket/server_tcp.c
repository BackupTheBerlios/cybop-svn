/*
 * $RCSfile: server_tcp.c,v $
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
 * This file handles a server TCP socket.
 *
 * @version $Revision: 1.1 $ $Date: 2004-12-06 14:34:54 $ $Author: reichenbach $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVER_TCP_SOURCE
#define SERVER_TCP_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{

    int server_socketnummer,client_socketnummer;
    int server_laenge,client_laenge;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;


    server_socketnummer=socket(AF_INET,SOCK_STREAM,0);

    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=9735;
    server_laenge=sizeof(server_address);
    bind(server_socketnummer,(struct sockaddr *)&server_address,server_laenge);


    char strg[300];

    listen(server_socketnummer,5);

    client_laenge=sizeof(client_address);
    client_socketnummer=accept(server_socketnummer,(struct sockaddr *)&client_address, &client_laenge);

    char hello[300]=" Hallo!";


    while(1) {

    	read(client_socketnummer,&strg,300);
	strcat(strg,hello);
	write(client_socketnummer,&strg,300);

    }
    close(client_socketnummer);
    close(server_socketnummer);
}

/* SERVER_TCP_SOURCE */
#endif
