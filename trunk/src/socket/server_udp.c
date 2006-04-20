/*
 * $RCSfile: server_udp.c,v $
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
 * This file handles a server UDP socket.
 *
 * @version $Revision: 1.8 $ $Date: 2006-04-20 22:36:12 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVER_UDP_SOURCE
#define SERVER_UDP_SOURCE

/*??
char *pfad = "/home/cybop/object/socket/server_udp.o";

int main() {

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

    recvfrom(socketnummer, strg, sizeof(strg), 0, (struct sockaddr*) &clientadresse, &clientlaenge);
    sleep(2);
    strcat(strg," Hallo!");
    sendto(socketnummer, strg, sizeof(strg), 0, (struct sockaddr*) &clientadresse, clientlaenge);
    sleep(2);
    i++;
    }

 close(socketnummer);
return 0;
}
*/

/* SERVER_UDP_SOURCE */
#endif
