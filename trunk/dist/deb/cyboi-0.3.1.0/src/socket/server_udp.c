/*
 * $RCSfile: server_udp.c,v $
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
 * This file handles a server UDP socket.
 *
 * @version $Revision: 1.1 $ $Date: 2004-11-23 15:26:26 $ $Author: reichenbach $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVER_UDP_SOURCE
#define SERVER_UDP_SOURCE

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

char *pfad = "/home/cybop/object/socket/server_udp.o";

int main()
{

    int socketnummer;
    int laenge;
    int clientlaenge;
    struct sockaddr_in adressstruktur;
    struct sockaddr_in clientadresse;
    int i=0;
    char strg[300];

    socketnummer=socket(AF_INET,SOCK_DGRAM,0);

    adressstruktur.sin_family=AF_INET;
    adressstruktur.sin_addr.s_addr=inet_addr("127.0.0.1");
    adressstruktur.sin_port=9735;
    laenge=sizeof(adressstruktur);

    bind(socketnummer,(struct sockaddr *)&adressstruktur,laenge);

    clientadresse.sin_family=AF_INET;
    clientadresse.sin_addr.s_addr=inet_addr("127.0.0.1");
    clientadresse.sin_port=9730;
    clientlaenge=sizeof(clientadresse);

while (i<10) {

    recvfrom(socketnummer, strg, sizeof(strg), 0, &clientadresse, &clientlaenge);
    sleep(2);
    strcat(strg," Hallo!");
    sendto(socketnummer, strg, sizeof(strg), 0, &clientadresse, clientlaenge);
    sleep(2);
    i++;
    }

 close(socketnummer);
return 0;
}

/* SERVER_UDP_SOURCE */
#endif
