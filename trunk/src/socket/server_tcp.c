#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{

    int server_socketnummer,client_socketnummer;
    int server_laenge,client_laenge;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    
    server_socketnummer=socket(AF_INET,SOCK_STREAM,0);

    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=9735;
    server_laenge=sizeof(server_address);
    bind(server_socketnummer,(struct sockaddr *)&server_address,server_laenge);

    
    char strg[300];
    
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
