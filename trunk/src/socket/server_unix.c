#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{

    int server_socketnummer,client_socketnummer;
    int server_laenge,client_laenge;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    unlink("server_socket");
    server_socketnummer=socket(AF_UNIX,SOCK_STREAM,0);

    server_address.sun_family=AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_laenge=sizeof(server_address);
    bind(server_socketnummer,(struct sockaddr *)&server_address,server_laenge);

    char ch;
    char strg[sizeof *stdin];
    
    

    listen(server_socketnummer,5);

    client_laenge=sizeof(client_address);
    client_socketnummer=accept(server_socketnummer,(struct sockaddr *)&client_address, &client_laenge);

    char hello[300]=" Hallo!";
    
    while(1) {
	
	
    	read(client_socketnummer,&strg,300);
	strcat(strg,hello);
	write(client_socketnummer,&strg,300);
	
    }
 close(client_socketnummer);
 close(server_socketnummer);
}
