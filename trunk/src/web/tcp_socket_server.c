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
 * @version $Revision: 1.4 $ $Date: 2004-11-23 13:34:56 $ $Author: rholzmueller $
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
#include "../cyboi/internals.c"
#include "../global/abstraction_constants.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/variable.c"
#include "../logger/logger.c"

void handle_request( void** pp_internals ) {
 
    fprintf( stderr, "request registriert \n" );
    
    if ( pp_internals == NULL_POINTER ) {
     
        log_message_debug( "pp_internals is a NULL POINTER");
    }
    else {

    }       
}

/**
 * Creates the tcp socket.
 *
 * @param pp_internals the internals
 * 
 */
void create_tcp_socket( void** pp_internals ) {

    log_message_debug( "create_tcp_socket is started" );
    
    if ( pp_internals == NULL_POINTER ) {
     
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else {
        
        // The active flag and port.
        int* p_tcp_socket_active = NULL_POINTER;
        int* p_tcp_socket_port = NULL_POINTER;
        int* p_tcp_socket_number = NULL_POINTER;
        int internal_type;
    
        //create the server socket number internals
        create_internal( (void*) &p_tcp_socket_number, 
                         (void*) &INTERNAL_TYPE_INTEGER );
        set_internal( pp_internals, (void*) &p_tcp_socket_number,
                      (void*) &INTERNAL_TYPE_INTEGER, 
                      (void*) &INTERNAL_TCPSOCKET_SERVERSOCKETNUMBER_INDEX );
            

        // get active flag 
        get_internal( pp_internals, (void*) &p_tcp_socket_active,
                      (void*) &internal_type, 
                      (void*) &INTERNAL_TCPSOCKET_ACTIVE_INDEX );
        
        // get port
        get_internal( pp_internals, (void*) &p_tcp_socket_port,
                      (void*) &internal_type, 
                      (void*) &INTERNAL_TCPSOCKET_PORT_INDEX );

        // Start tcp socket server.
        if ( *p_tcp_socket_active==1 ) {

            int err = 0;
            if ( p_tcp_socket_port == NULL_POINTER ) {
        
                log_message_debug( "p_tcp_socket_port is a NULL POINTER" );
                err = -1;
            }
            else if ( p_tcp_socket_number == NULL_POINTER ) {
               
                log_message_debug( "p_tcp_socket_number is a NULL POINTER" );
                err = -2;
            }
            else {
                
                struct sockaddr_in server_address;
                int server_address_size;
            
                /* create the socket */
                *p_tcp_socket_number = socket( PF_INET, SOCK_STREAM, 0);
                if ( *p_tcp_socket_number < 0 ) {
                    
                    //errormessage and close the thread
                    log_message_debug( "failed to create socket" );
                    err = -3;
                }
                fprintf( stderr, "create the socket - socketnumber: %d \n", *p_tcp_socket_number );
            
                /* create the socket address of the server */
                server_address.sin_family       = AF_INET;
                server_address.sin_addr.s_addr  = INADDR_ANY;
                server_address.sin_port         = htons( *p_tcp_socket_port );
                server_address_size             = sizeof(server_address);
            
                /* bind the socket to the server address */
                if ( bind( *p_tcp_socket_number, (struct sockaddr *) &server_address,
                           server_address_size ) < 0 ) 
                {
            
                    //errormessage and close the thread
                    log_message_debug( "failed to bind socket" );
                    err = -4;
                }
                   
                fprintf( stderr, "bind the socket on the port %d \n", *p_tcp_socket_port );
                
                /* listen for request of the clients */
                listen( *p_tcp_socket_number, 1);
                
            }
            if ( err == 0 ) {
              
                log_message_debug( "create tcp socket was successful");
            }
            else {
                
                log_message_debug( "create tcp socket was incorrect");
                
                //deactivat the active flag for tcp socket 
                *p_tcp_socket_active = 0;
            }
        } // if ( *p_tcp_socket_active==1 ) {
    }
}

/**
 * run the tcp socket server
 * the function is running in a thread, because the loop in the
 * function wait for request of the client
 * 
 * @param pp_internals the internals
 */
void run_tcp_socket( void** pp_internals ) {
    
    log_message_debug( "run_tcp_socket is started" );  
    if ( pp_internals == NULL_POINTER ) {
     
        log_message_debug( "pp_internal is a NULL POINTER" );  
    }
    else {

        int internal_type = 0;
     
        void** pp_signal_memory = NULL_POINTER;
        int* p_signal_memory_count = NULL_POINTER;
        int* p_signal_memory_size = NULL_POINTER;

        get_internal( pp_internals, (void*) &pp_signal_memory, 
                      (void*) &internal_type, 
                      (void*) &INTERNAL_SIGNAL_MEMORY_INDEX );
        get_internal( pp_internals, (void*) &p_signal_memory_count, 
                      (void*) &internal_type, 
                      (void*) &INTERNAL_SIGNAL_MEMORY_COUNT_INDEX );
        get_internal( pp_internals, (void*) &p_signal_memory_size, 
                      (void*) &internal_type, 
                      (void*) &INTERNAL_SIGNAL_MEMORY_SIZE_INDEX );

        int* p_tcp_server_socket_number = NULL_POINTER;
        get_internal( pp_internals, (void*) &p_tcp_server_socket_number, 
                      (void*) &internal_type, 
                      (void*) &INTERNAL_TCPSOCKET_SERVERSOCKETNUMBER_INDEX );

        int client_socketnumber;
        struct sockaddr_in client_address;
        int client_address_size;
        
        while (1) {
    
            client_address_size = sizeof( client_address );
            client_socketnumber = accept( *p_tcp_server_socket_number, 
                                          (struct sockaddr*) &client_address, 
                                          &client_address_size );
                                          
            log_message_debug("after accept");
            if (client_socketnumber < 0) {
    
                //errormessage and close the thread
                fprintf( stderr, "accept failed" );
                pthread_exit((void *) 0);
            }
            
            char ausgabe[] = "Hello World";
            send (client_socketnumber, ausgabe, strlen(ausgabe), 0);
    
            handle_request( pp_internals );        
    
            // close the socket connection 
            close( client_socketnumber );
        }
        
        pthread_exit((void *) 0);

    }        
    
}


/**
 * Start the tcp socket server
 * 
 * @param pp_internals the internals
 */
void activate_tcp_socket( void** pp_internals ) 
{
    log_message_debug( "activate_tcp_spcket is started");

    if ( pp_internals == NULL_POINTER ) {
    
        log_message_debug( "pp_internals is a NULL POINTER" );
    }
    else {

        //create the thread 
        pthread_t tcp_socket_thread;
            
        int err = 0;
        err = pthread_create( &tcp_socket_thread, NULL, 
                              (void*) &run_tcp_socket, 
                              pp_internals );
        if( err != 0) {
        
            log_message_debug( "error by the create the thread tcp socket");
        }
    }
}

/* TCP_SOCKET_SERVER_SOURCE */
#endif
