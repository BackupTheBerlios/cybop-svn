#include <stdio.h>
#include <sys/types.h>   //int socket(..)
#include <sys/socket.h>  //int socket(..),int bind(..)
#include <netinet/in.h>
#include <arpa/inet.h>

char *pfad = "/home/cybop/object/socket/server_udp.o";

int main()
{

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
    sendto(socketnummer, eingabe, 300, 0, &serveradresse, serverlaenge);
    printf("sende: %s\n",eingabe);
    sleep(2);
    recvfrom(socketnummer, eingabe, 300, 0, &serveradresse, &serverlaenge);
    printf("empfange: %s\n",eingabe);
    i++;
    }

 close(socketnummer);
return 0;
}
