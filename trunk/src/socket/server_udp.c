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
