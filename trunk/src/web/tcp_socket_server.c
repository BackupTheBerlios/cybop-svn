/*
 * $RCSfile: tcp_socket_server.c,v $
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
 * This file handles a server TCP socket.
 *
 * @version $Revision: 1.1 $ $Date: 2004-10-28 18:47:13 $ $Author: rholzmueller $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TCP_SOCKET_SERVER_SOURCE
#define TCP_SOCKET_SERVER_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include "../global/abstraction_constants.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/variable.c"
#include "../logger/logger.c"

void handle_request() {
 
    fprintf( stderr, "request registriert \n" );   
}


/**
 * run the tcp socket server
 * the function is running in a thread, because the loop in the
 * function wait for request of the client
 * 
 * @param pPort the port for the socket
 */
void run_tcp_socket_server( void* pPort ) {
    
    int server_socketnumber, client_socketnumber;
    int server_size, client_size;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    fprintf( stderr, "init the tcp socket server \n" );
    fprintf( stderr, "portnumber: %d \n", *(int*)pPort );

    /* create the socket */
    server_socketnumber = socket( PF_INET, SOCK_STREAM, 0);
    if (server_socketnumber < 0) {
        
        //errormessage and close the thread
        fprintf( stderr, "failed to create socket \n");
        pthread_exit((void *) 0);
    }
    fprintf( stderr, "create the socket - socketnumber: %d \n", server_socketnumber );

    /* create the socket address of the server */
    server_address.sin_family       = AF_INET;
    server_address.sin_addr.s_addr  = INADDR_ANY;
    server_address.sin_port         = htons( *(int*)pPort );
    server_size                     = sizeof(server_address);

    /* bind the socket to the server address */
    if ( bind( server_socketnumber, (struct sockaddr *)&server_address,
               server_size ) < 0 ) 
    {

        //errormessage and close the thread
        fprintf( stderr, "failed to bind  socket \n");
        pthread_exit((void *) 0);
    };
       
    fprintf( stderr, "bind the socket on the port %d \n", *(int*)pPort );
    
    /* listen for request of the clients */
    listen( server_socketnumber, 5);
    
    while (1) {

        client_size = sizeof( client_address );
        client_socketnumber = accept( server_socketnumber, 
                                      (struct sockaddr*)&client_address, 
                                      &client_size );
        if (client_socketnumber < 0) {

            //errormessage and close the thread
            fprintf( stderr, "accept failed" );
            pthread_exit((void *) 0);
        }

        handle_request( client_socketnumber );        

        /* close the socket connection */
        close( client_socketnumber );
    }
    
    pthread_exit((void *) 0);
}

/**
 * create the thread for running the tcp socket server
 * 
 * @param pPort the port for the socket
 */
void create_tcp_socket_server_thread( void* pPort ) {

    //create the thread 
    pthread_t tcp_socket_thread;
    
    if(pthread_create(&tcp_socket_thread, NULL, (void *)&run_tcp_socket_server, pPort) != 0) {

         fprintf(stderr, "Fehler bei Thread 1......\n");
         exit(0);
    }
}

/**
 * Start the tcp socket server
 * 
 * @param pActive flag for starting the server 
 *        1 - start the tcp socket server
 *        0 - dosn't start the tcp socket server
 * @param pPort the port for the socket
 */
void start_tcp_socket_server( void* pActive, void* pPort ) {
   
    if ( pActive == NULL_POINTER ) {
     
       fprintf( stderr, "function tcp_socket_server: pActive is a NULL_POINTER \n");
    }
    else if ( pPort == NULL_POINTER ) {
     
       fprintf( stderr, "function tcp_socket_server: pPort is a NULL_POINTER \n");
    }
    else {
        
        if ( *(int*)pActive == 1 ) {
          
            create_tcp_socket_server_thread( pPort );    
        }
    }
}

/* TCP_SOCKET_SERVER_SOURCE */
#endif
