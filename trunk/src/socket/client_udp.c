/*
 * $RCSfile: client_udp.c,v $
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
 * This file handles a client UDP socket.
 *
 * @version $Revision: 1.7 $ $Date: 2005-03-30 14:15:42 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLIENT_UDP_SOURCE
#define CLIENT_UDP_SOURCE

/*??
char *pfad = "/home/cybop/object/socket/server_udp.o";

int main() {

    int socketnummer;
    int laenge;
    int serverlaenge;
    struct sockaddr_in adressstruktur;
    struct sockaddr_in serveradresse;
    int i=0;
    int serverprocess;

    printf("Bitte geben Sie einen Wort ein! ");
    char eingabe[sizeof (*stdin)];
    scanf("%s",eingabe);

    socketnummer=socket(AF_INET,SOCK_DGRAM,0);

    serverprocess=fork();

      if (serverprocess<0) fprintf(stderr,"Fehler beim Aufruf von fork()");
      if (serverprocess==0) execl(pfad,NULL);

      sleep(2);

    adressstruktur.sin_family=AF_INET;
    adressstruktur.sin_addr.s_addr=inet_addr("127.0.0.1");
    adressstruktur.sin_port=9730;
    laenge=sizeof(adressstruktur);

    bind(socketnummer,(struct sockaddr *)&adressstruktur,laenge);

    serveradresse.sin_family=AF_INET;
    serveradresse.sin_addr.s_addr=inet_addr("127.0.0.1");
    serveradresse.sin_port=9735;
    serverlaenge=sizeof(serveradresse);

while (i<10) {

    sleep(2);
    sendto(socketnummer, eingabe, 300, 0, (struct sockaddr*) &serveradresse, serverlaenge);
    printf("sende: %s\n",eingabe);
    sleep(2);
    recvfrom(socketnummer, eingabe, 300, 0, (struct sockaddr*) &serveradresse, &serverlaenge);
    printf("empfange: %s\n",eingabe);
    i++;
    }

 close(socketnummer);
return 0;
}
*/

/* CLIENT_UDP_SOURCE */
#endif
