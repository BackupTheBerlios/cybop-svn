/*
 * $RCSfile: client_tcp.c,v $
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
 * This file handles a client TCP socket.
 *
 * @version $Revision: 1.7 $ $Date: 2006-04-20 22:36:11 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLIENT_TCP_SOURCE
#define CLIENT_TCP_SOURCE

/*??
char *pfad = "/home/cybop/object/socket/server_tcp.o";

int main() {

    int socketnummer;
    int laenge;
    struct sockaddr_in adressstruktur;
    int result;
    int i=0;
    int serverprocess;

    printf("Bitte geben Sie einen Wort ein! ");
    char eingabe[sizeof (*stdin)];
    scanf("%s",eingabe);

    socketnummer=socket(AF_INET,SOCK_STREAM,0);

    serverprocess=fork();

      if (serverprocess<0) fprintf(stderr,"Fehler beim Aufruf von fork()");
      if (serverprocess==0) execl(pfad,NULL);

      sleep(2);

    adressstruktur.sin_family=AF_INET;
    adressstruktur.sin_addr.s_addr=inet_addr("127.0.0.1");
    adressstruktur.sin_port=9735;
    laenge=sizeof(adressstruktur);


    result=connect(socketnummer, (struct sockaddr *)&adressstruktur, laenge);

    if(result== -1) {
        perror("huch der client hat einen Fehler");
        exit(1);
    }
    else{
        printf("Verbindung zum Server hergestellt\n");
        }

    while (i<10) {

    sleep(2);
    write(socketnummer, &eingabe, 300);
    printf("sende: %s\n",eingabe);
    read(socketnummer, &eingabe,300);
    printf("empfange: %s\n",eingabe);
    i++;
    }

    close(socketnummer);

    return 0;
}
*/

/* CLIENT_TCP_SOURCE */
#endif
