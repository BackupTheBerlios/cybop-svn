/*
 * $RCSfile: client_unix.c,v $
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
 * This file handles a client UNIX FILE socket.
 *
 * @version $Revision: 1.3 $ $Date: 2004-06-24 11:45:37 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLIENT_UNIX_SOURCE
#define CLIENT_UNIX_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>

char *pfad = "/home/cybop/object/socket/server_unix.o";

int main() {

    int socketnummer;
    int laenge;
    struct sockaddr_un adressstruktur;
    int result;
    char ch='A';
    int i=0;
    int serverprocess;

    printf("Bitte geben Sie einen Wort ein! ");
    char eingabe[sizeof (*stdin)];
    scanf("%s",eingabe);

    socketnummer = socket(AF_UNIX, SOCK_STREAM, 0);

    // Server wird aus Client gestartet, nur zum Testen!!
    // Server kann auch als eigener Prozess von Kommandozeile ausgefuehrt werden,
    // dann aber dieses "fork" beseitigen, da nicht mehr notwendig!
    serverprocess=fork();

    if (serverprocess<0) fprintf(stderr,"Fehler beim Aufruf von fork()");
    if (serverprocess==0) execl(pfad,NULL);
    // ... fork bis hier loeschen!

    sleep(2);

    adressstruktur.sun_family=AF_UNIX;
    strcpy(adressstruktur.sun_path, "server_socket");
    laenge=sizeof(adressstruktur);

    // Establish connection.
    result = connect(socketnummer, (struct sockaddr*) &adressstruktur, laenge);

    if (result == -1) {

        perror("huch der client hat einen Fehler");

        return(1);//exit(1);
        // Socket must be closed in case of error!!
        // Otherwise socket program is still executed, even if this program has exited.

    } else {

        printf("Verbindung zum Server hergestellt\n");
    }

    while (i<10) {

        write(socketnummer, &eingabe, 300);
        printf("sende: %s\n", eingabe);

        read(socketnummer, &eingabe, 300);
        printf("empfange: %s\n", eingabe);

        i++;
    }

    close(socketnummer);

    return(0);//exit(0);
}

/* CLIENT_UNIX_SOURCE */
#endif
