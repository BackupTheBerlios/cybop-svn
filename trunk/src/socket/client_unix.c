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
