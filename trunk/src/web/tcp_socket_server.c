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
 * @version $Revision: 1.2 $ $Date: 2004-11-16 16:57:26 $ $Author: rholzmueller $
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
#include "../array/array.c"
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
 * Creates the tcp socket.
 *
 * @param pPort the port number for the socket (type int*)
 * @param pSocketNumber this is the socket number for the generated socket
 *                      this is the return value of the function (type int*)
 * @return errorcode for this function
 * 
 */
int create_tcp_socket( const void* p_port, void* p_socketnumber ) {

    log_message_debug( "create_tcp_socket is started" );
    if ( p_port == NULL_POINTER ) {

        log_message_debug( "p_port is a NULL POINTER" );
        return -1;
    }
    else if ( p_socketnumber == NULL_POINTER ) {
       
        log_message_debug( "p_socketnumber is a NULL POINTER" );
        return -2;
    }
    else {
        
        int* pint_port = (int*) p_port;
        int* pint_socketnumber = (int*) p_socketnumber;

        struct sockaddr_in server_address;
        int server_address_size;
    
        /* create the socket */
        *pint_socketnumber = socket( PF_INET, SOCK_STREAM, 0);
        if ( *pint_socketnumber < 0 ) {
            
            //errormessage and close the thread
            log_message_debug( "failed to create socket" );
            return -3;
        }
        fprintf( stderr, "create the socket - socketnumber: %d \n", *pint_socketnumber );
    
        /* create the socket address of the server */
        server_address.sin_family       = AF_INET;
        server_address.sin_addr.s_addr  = INADDR_ANY;
        server_address.sin_port         = htons( *pint_port );
        server_address_size              = sizeof(server_address);
    
        /* bind the socket to the server address */
        if ( bind( *pint_socketnumber, (struct sockaddr *) &server_address,
                   server_address_size ) < 0 ) 
        {
    
            //errormessage and close the thread
            log_message_debug( "failed to bind socket" );
            return -4;
        };
           
        fprintf( stderr, "bind the socket on the port %d \n", *pint_port );
        
        /* listen for request of the clients */
        listen( *pint_socketnumber, 1);
        
    }
    return 0;
}

/**
 * run the tcp socket server
 * the function is running in a thread, because the loop in the
 * function wait for request of the client
 * 
 * @param p_thread_parameter the only one thread parameter (type void**)
 */
void run_tcp_socket( void* p_thread_parameter ) {
/*    
    if ( p_thread_parameter == NULL_POINTER ) {
     
        log_message_debug( "p_thread_parameter in run_tcp_socket  is a NULL POINTER" );  
    }
    else {
     
        void* p_signal_memory;
        void* p_signal_memory_count;
        void* p_signal_memory_size;
        void* p_cint;
        void* p_iint;
        void* p_pint;
        void* p_dint;
        
        //splitt the thread parameter in the separate parts
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_SIGNAL_MEMORY_INDEX,
                           p_signal_memory );
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_SIGNAL_MEMORY_COUNT_INDEX,
                           p_signal_memory_count );
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_SIGNAL_MEMORY_SIZE_INDEX,
                           p_signal_memory_size );
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_CHAR_INTERNAL_INDEX,
                           p_cint );
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_INTEGER_INTERNAL_INDEX,
                           p_iint );
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_POINTER_INTERNAL_INDEX,
                           p_pint );
        get_array_element( p_thread_parameter,
                           (void*) &POINTER_ARRAY,
                           (void*) &TCP_SOCKET_PARAMETER_ARRAY_DOUBLE_INTERNAL_INDEX,
                           p_dint );
    }        
    int client_socketnumber;
    struct sockaddr_in client_address;
    int client_address_size;
    
    while (1) {

        client_address_size = sizeof( client_address );
        //client_socketnumber = accept( server_socketnumber, 
        //                              (struct sockaddr*) &client_address, 
        //                              &client_size );
                                      
        log_message_debug("after accept");
        if (client_socketnumber < 0) {

            //errormessage and close the thread
            fprintf( stderr, "accept failed" );
            pthread_exit((void *) 0);
        }
        
        char ausgabe[] = "Hello World";
        send (client_socketnumber, ausgabe, strlen(ausgabe), 0);

        handle_request( client_socketnumber );        

        // close the socket connection 
        close( client_socketnumber );
    }
    
    pthread_exit((void *) 0);
*/    
}


/**
 * Start the tcp socket server
 * 
 * @param p_thread_parameter tthe only one thread parameter (type void**)
 */
void activate_tcp_socket( void* p_thread_parameter ) 
{
    log_message_debug( "activate_tcp_spcket is started");
    if ( p_thread_parameter == NULL_POINTER ) {
    
        log_message_debug( "pp_thread_parameter is a NULL POINTER" );
    }
    else {

        void** pp_thread_parameter = (void**) p_thread_parameter;
        
        //create the thread 
        pthread_t tcp_socket_thread;
            
        int err = 0;
        err = pthread_create( &tcp_socket_thread, NULL, 
                              (void*) &run_tcp_socket, 
                              *pp_thread_parameter );
        if( err != 0) {
        
            log_message_debug( "error by the create the thread tcp socket");
        }
    }
}

/* TCP_SOCKET_SERVER_SOURCE */
#endif
