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
 * @version $Revision: 1.1 $ $Date: 2004-12-06 14:34:54 $ $Author: reichenbach $
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
#include "../accessor/compound_accessor.c"
#include "../accessor/signal_memory_accessor.c"
#include "../array/array.c"
#include "../creator/creator.c"
#include "../cyboi/internals.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/variable.c"
#include "../logger/logger.c"

/**
 * Ermmittelt aus einen request eines Browser die request Zeile
 * Bsp. für request zeile: GET /paramater HTTP/1.1
 */
void get_request_row( char** req, int* req_count, 
                      char** req_row, int* req_row_count  ) {
 
    *req_row_count = 0;
    char element = ' '; 
    while ( 1 ) {
        
        if ( *req_row_count >= *req_count ) {
            break;   
        }
        
        get_array_element( req, (void*) &CHARACTER_ARRAY,
                           req_row_count, (void*) &element );
        if ( element == '\r' ) {

            //ende der request Zeile erreicht
            break;
        }

        int max_count = *req_row_count + 1;
        resize_array( req_row, (void*) &CHARACTER_ARRAY,
                      (void*) &max_count );
        set_array_element( req_row, (void*) &CHARACTER_ARRAY,
                           req_row_count, (void*) &element );
        
        *req_row_count = *req_row_count + 1;
    }
}

/**
 * Ermmittelt aus einer request zeile die Parameter des request
 * Bsp. für request zeile: GET /lib/ausgabe.cybol HTTP/1.1
 *      Als Ergebnis möchte ich nur die Parameter haben
 *      lib/ausgabe.cybol
 */
void get_param_from_request_row( char** req_row, int* req_row_count, 
                                 char** param, int* param_count  ) {
 
    int req_row_index = 0;
    int start_param_flag = 0;
    char element = ' '; 

    *param_count = 0;

    while ( 1 ) {
        
        if ( req_row_index >= *req_row_count ) {
            break;   
        }
        
        get_array_element( req_row, (void*) &CHARACTER_ARRAY,
                           (void*) &req_row_index, (void*) &element );

        //check of ending the paramaters
        if ( ( start_param_flag == 1 ) && ( element == ' ' ) ) {
          
            break;
        }

        //complete the parameters 
        if ( start_param_flag == 1 ) {

            int max_count = *param_count + 1;
            resize_array( param, (void*) &CHARACTER_ARRAY,
                          (void*) &max_count);
            set_array_element( param, (void*) &CHARACTER_ARRAY,
                               param_count, (void*) &element );
            *param_count = *param_count + 1;
        }
                           
        //check of beginning the paramaters
        if ( element == '/' ) {

            //begin from the parameters
            start_param_flag = 1;
        }

        
        req_row_index = req_row_index + 1;
    }
}

/**
 * Erstellt ein Compund mit einen Eintrag
 * Dieser Eintrag sieht folgendermaßen aus:
 *   - name=receiver
 *   - channel=inline
 *   - abstraction=integer
 *   - model=<client_socketnumber>
 */
void create_detail_client_socketnumber( void** detail, int* detail_count,
                                        int* detail_size, 
                                        int* client_socketnumber ) {

    //create the detail compound
    create( detail, detail_count, 
            (void*) &COMPOUND_ABSTRACTION, 
            (void*) &COMPOUND_ABSTRACTION_COUNT );
            
    // The destination name.
    void* dn = NULL_POINTER;
    int dnc = 0;
    int dns = 0;

    // The destination abstraction.
    void* da = NULL_POINTER;
    int dac = 0;
    int das = 0;
    // The destination model.
    void* dm = NULL_POINTER;
    int dmc = 0;
    int dms = 0;
    // The destination details.
    void* dd = NULL_POINTER;
    int ddc = 0;
    int dds = 0;

    //create model destinantion name
    create_model( (void*) &dn, (void*) &dnc, (void*) &dns,
                  (void*) &RECEIVER_NAME_ABSTRACTION, 
                  (void*) &RECEIVER_NAME_ABSTRACTION_COUNT,
                  (void*) &STRING_ABSTRACTION, 
                  (void*) &STRING_ABSTRACTION_COUNT,
                  (void*) &INLINE_CHANNEL, 
                  (void*) &INLINE_CHANNEL_COUNT );
                
    //create model destinantion abstraction
    create_model( (void*) &da, (void*) &dac, (void*) &das,
                  (void*) &INTEGER_ABSTRACTION, 
                  (void*) &INTEGER_ABSTRACTION_COUNT,
                  (void*) &STRING_ABSTRACTION, 
                  (void*) &STRING_ABSTRACTION_COUNT,
                  (void*) &INLINE_CHANNEL, 
                  (void*) &INLINE_CHANNEL_COUNT );

    //create model destinantion model
    create_model( (void*) &da, (void*) &dac, (void*) &das,
                  (void*) &client_socketnumber, 
                  (void*) &INTEGER_COUNT,
                  (void*) &INTEGER_ABSTRACTION, 
                  (void*) &INTEGER_ABSTRACTION_COUNT,
                  (void*) &INLINE_CHANNEL, 
                  (void*) &INLINE_CHANNEL_COUNT );
                
    set_compound_element_by_name( 
        detail, detail_count, detail_size,
        (void*) &dn, (void*) &dnc, (void*) &dns,  
        (void*) &da, (void*) &dac, (void*) &das,  
        (void*) &dm, (void*) &dmc, (void*) &dms,  
        (void*) &dd, (void*) &ddc, (void*) &dds );
}

void handle_request( void** pp_internals, int* p_client_socketnumber ) {
 
    fprintf( stderr, "request registriert \n" );
    
    if ( pp_internals == NULL_POINTER ) {
     
        log_message_debug( "pp_internals is a NULL POINTER");
    }
    else if ( p_client_socketnumber == NULL_POINTER ) {
     
        log_message_debug( "p_client_socketnumber is a NULL POINTER");
    }
    else {

        char *request = getenv("PATH");

        char* msg;
        int max_msg_count = 1024;
        create_array( (void*) &msg, 
                      (void*) &CHARACTER_ARRAY, 
                      (void*) &max_msg_count );
        int msg_count = 0;
        
        msg_count = recv( *p_client_socketnumber, msg, max_msg_count, 0 );
        /* read the message from the client */
        if ( msg_count == -1 ) {
            log_message_debug( "error while receiving reply" );
            exit(1);
        }
        
        //:todo auf get prüfen 
        //:todo parameter aus empfangenen Daten ermitteln
        char* msg_row = NULL_POINTER;
        int msg_row_count = 0;
        create_array( (void*) &msg_row, (void*) &CHARACTER_ARRAY, 
                      (void*) &msg_row_count );
        get_request_row( &msg, &msg_count, &msg_row, &msg_row_count );
        
        char* param = NULL_POINTER;
        int param_count = 0;
        create_array( (void*) &param, (void*) &CHARACTER_ARRAY, 
                      (void*) &param_count );

        get_param_from_request_row( &msg_row, &msg_row_count,
                                    &param, &param_count );
                    
        
        /* write the answer to the client  */
//        if( send( *p_client_socketnumber, msg, msg_count, 0) == -1 ) {
//            log_message_debug( "error while replying" );
//            exit(1);
//        }

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


        // The source channel.
        char c_sc[] = "inline";
        char* sc = &c_sc[0];
        int scc = 6;
        // The source abstraction.
        char c_sa[] = "cybol";
        char* sa = &c_sa[0];
        int sac = 5;
        // The source model.
        char* sm = param;
        int smc = param_count;

        // The destination abstraction.
        void* da = NULL_POINTER;
        int dac = 0;
        int das = 0;
        // The destination model.
        void* dm = NULL_POINTER;
        int dmc = 0;
        int dms = 0;
        // The destination details.
        void* dd = NULL_POINTER;
        int ddc = 0;
        int dds = 0;

        // Create destination abstraction.
        create_model((void*) &da, (void*) &dac, (void*) &das,
            (void*) &sa, (void*) &sac,
            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
            (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
        log_message_debug( "create destination abstraction" );

        // Create destination model.
        create_model((void*) &dm, (void*) &dmc, (void*) &dms,
            (void*) &sm, (void*) &smc,
            (void*) &sa, (void*) &sac,
            (void*) &sc, (void*) &scc);
        log_message_debug( "create destination model" );

        
        // Create destination detail
        create_detail_client_socketnumber( 
            (void*) &dd, (void*) &ddc, (void*) &dds,
            p_client_socketnumber );
        
        
        //
        // set the signal 
        //

        int main_sig_id = 0;
        get_new_main_signal_id( pp_signal_memory, p_signal_memory_count, 
                                (void*) &main_sig_id );
        set_signal( pp_signal_memory, p_signal_memory_count, p_signal_memory_size,   //memory
                    (void*) &da, (void*) &dac,              //dest abtsraction
                    (void*) &dm, (void*) &dmc,              //dest model
                    (void*) &dd, (void*) &ddc,              //dest details
                    (void*) &NORMAL_PRIORITY,
                    (void*) &main_sig_id );
        log_message_debug( "set start signals" );

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
        
        //while (1) {
    
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
            
            //char ausgabe[] = "Hello World";
            //send (client_socketnumber, ausgabe, strlen(ausgabe), 0);
    
            handle_request( pp_internals, &client_socketnumber );        
    
            // close the socket connection 
            close( client_socketnumber );
        //}
        
        //pthread_exit((void *) 0);

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

/*
 *  Funktion liest Daten in der POST- oder GET-Methode ein.
 *  Rückgabewert: String puffer mit den Daten
 *  bei Fehler  : NULL
*/
/*
char *getdata()
{
   unsigned long size;
   char *puffer = NULL;
   char *request = getenv("REQUEST_METHOD");
   char *cont_len;
   char *cgi_string;

   // Zuerst die Request-Methode überprüfen 
   if(  NULL == request )
      return NULL;
   else if( strcmp(request, "GET") == 0 )
      {
         // Die Methode GET -> Query String abholen 
         cgi_string = getenv("QUERY_STRING");
         if( NULL == cgi_string )
            return NULL;
         else
            {
               puffer =(char *) Strdup(cgi_string);
               return puffer; // Rückgabewert an den Aufrufer 
            }
      }
   else if( strcmp(request, "POST") == 0 )
      {
         // Die Methode POST -> Länge des Strings
         //   ermitteln (CONTENT_LENGTH) 
         cont_len = getenv("CONTENT_LENGTH");
         if( NULL == cont_len)
            return NULL;
         else
            {
               // String CONTENT_LENGTH in
                  unsigned long umwandeln 
               size = (unsigned long) atoi(cont_len);
               if(size <= 0)
                  return NULL; // Keine Eingabe!?!? 
            }
         // Jetzt lesen wir die Daten von stdin ein 
         puffer =(char *) malloc(size+1);
         if( NULL == puffer )
            return NULL;
         else
            {
               if( NULL == fgets(puffer, size+1, stdin) )
                  {
                     free(puffer);
                     return NULL;
                  }
               else  // Rückgabewerte an den Ausrufer 
                  return puffer;
            }
      }
   else // Weder GET-Methode noch die POST-Methode
        //   wurden verwendet 
      return NULL;
      
}
*/
/* TCP_SOCKET_SERVER_SOURCE */
#endif
