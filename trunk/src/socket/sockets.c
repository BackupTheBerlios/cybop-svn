/*
 * $RCSfile: sockets.c,v $
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
 * This file is just for testing of socket handling.
 *
 * @version $Revision: 1.3 $ $Date: 2004-06-24 11:45:37 $ $Author: christian $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKETS_SOURCE
#define SOCKETS_SOURCE

#include <stdio.h>

char* pfad = "/home/cybop/object/socket/client_unix.o";
char* pfad2 = "/home/cybop/object/socket/client_tcp.o";
char* pfad3 = "/home/cybop/object/socket/client_udp.o";
char* pfad4 = "/home/cybop/object/socket/client_tcp6.o";
char* pfad5 = "/home/cybop/object/socket/client_udp6.o";

void af_unix() {

    printf("starte prog af_unix \n");

    // execl means absolute path given!
    if (execl(pfad, NULL) == -1) {

        printf("Fehler beim Aufrufen von client_unix.out");
    }
}

void af_inet() {

    char auswahl;
    char str1[100];

    printf("\tUebertragungsart:\n");
    printf("\t[1]TCP\n");
    printf("\t[2]UDP\n");
    printf("\t[z]zurueck\n");
    printf("\t[x]Exit\n");
    printf("\t ");

    auswahl = getchar();                     //Zeichen aus STDIN lesen
    fgets(str1, sizeof(str1), stdin);      //Eingabepuffer leeren

    switch (auswahl) {

        case 49 :  printf("starte prog af_inet mit TCP\n");execl(pfad2,NULL);break;
        case 50 :  printf("starte prog af_inet mit UDP\n");execl(pfad3,NULL);break;
        case 120 : printf("\n bye!\n\n");exit(0);
        case 122 :                                                           break;
        default :  printf("\nFalsche Eingabe! Bitte wiederholen!\n");
    }
}

void af_inet6() {

    char auswahl;
    char str1[100];

    printf("\tUebertragungsart:\n");
    printf("\t[1]TCP\n");
    printf("\t[2]UDP\n");
    printf("\t[z]zurueck\n");
    printf("\t[x]Exit\n");
    printf("\t ");

    auswahl=getchar();                     //Zeichen aus STDIN lesen
    fgets(str1, sizeof(str1), stdin);      //Eingabepuffer leeren

    switch (auswahl) {

        case 49 :  printf("starte prog af_inet6 mit TCP\n"); break;
        case 50 :  printf("starte prog af_inet6 mit UDP\n"); break;
        case 120 : printf("\n bye!\n\n");exit(0);
        case 122 :                                           break;
        default :  printf("\nFalsche Eingabe! Bitte wiederholen!\n");
    }
}

int main() {

    char auswahl;
    char str1[100];
    int tcp;
    int rueckgabe;
    int status;

    // Abbruch wenn x gelesen
    while (auswahl != 120) {

        printf("\nDomaene:\n");
        printf("[1]AF_UNIX \n");
        printf("[2]AF_INET \n");
        printf("[3]AF_INET6 \n");
        printf("[x]Exit \n ");

        // Zeichen aus STDIN lesen
        auswahl = getchar();

        // Eingabepuffer leeren
        fgets(str1, sizeof(str1), stdin);

        switch (auswahl) {

            case 49 :  af_unix();            break;
            case 50 :  af_inet();            break;
            case 51 :  af_inet6();           break;
            case 120 : printf("\n bye!\n\n");break;
            default :  printf("\nFalsche Eingabe! Bitte wiederholen!\n");
        }
    }
}

/* SOCKETS_SOURCE */
#endif
