#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

char *pfad = "/home/cybop/object/socket/server_tcp.o";

int main()
{
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
