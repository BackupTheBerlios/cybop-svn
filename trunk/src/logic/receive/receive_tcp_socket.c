/*
 * $RCSfile: receive_tcp_socket.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.1 $ $Date: 2005-04-22 08:02:39 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef RECEIVE_TCP_SOCKET_SOURCE
#define RECEIVE_TCP_SOCKET_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../array/array.c"
#include "../../global/abstraction_constants.c"
#include "../../global/character_constants.c"
#include "../../global/integer_constants.c"
#include "../../global/structure_constants.c"
#include "../../global/variables.c"
#include "../../web/tcp_socket_server.c"

/**
 * Receive over the tcp socket service.
 *
 * @param internals the internals memory
 * @param know the knowledge
 * @param know_count the knowledge count
 * @param know_size the knowledge size
 * @param blocking_abstr the blocking abtsraction
 * @param blocking_abstr_count the blocking abtsraction count
 * @param blocking_model the blocking model
 * @param blocking_model_count the blocking model count
 */
void receive_tcp_socket( void* internals, const void* know, 
                          const void* know_count, const void* know_size,
                          void* blocking_abstr, void* blocking_abstr_count,
                          void* blocking_model, void* blocking_model_count ) 
{

    log_message_debug("receive tcp socket.");
    
    //check of null pointer
    if ( internals != NULL_POINTER ) {
                    
        
        //
        if (    (blocking_abstr != NULL_POINTER) 
             && (blocking_abstr_count != NULL_POINTER)
             && (blocking_model != NULL_POINTER)
             && (blocking_model_count != NULL_POINTER) )
        {
         
            int r = 0;
            compare_arrays( (void*) blocking_abstr, 
                            (void*) blocking_abstr_count, 
                            (void*) INTEGER_ABSTRACTION, 
                            (void*) INTEGER_ABSTRACTION_COUNT, 
                            (void*) &r, (void*) CHARACTER_ARRAY);
                            
            if ( r==1) {
             
                if ( *((int*)blocking_model) == *ZERO_NUMBER ) {
                 
                    // The thread.
                    pthread_t t;
                
                    // Create thread returning an error value.
                    int e = pthread_create( &t, NULL_POINTER, 
                                            (void*) &run_tcp_socket_server, 
                                            internals );
                
                    if (e != 0) {
                
                        log_message_debug("Could not receive tcp socket. An error occured while creating the thread.");
                    }
                 
                }
                 
                //set the activation flag in the internal
                void** socket_flag = POINTER_NULL_POINTER;
        
                get_array_elements( internals, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, 
                                    (void*) &socket_flag, (void*) POINTER_ARRAY );
        
                if ( (socket_flag!=NULL_POINTER) && (*socket_flag!=NULL_POINTER) ) {
                 
                    **((int**)socket_flag) = 1; 
                }
                
                //set the blocking flag in the internal
                void** blocking_flag = POINTER_NULL_POINTER;
        
                get_array_elements( internals, (void*) TCP_SERVER_SOCKET_BLOCKING_INTERNAL, 
                                    (void*) &blocking_flag, (void*) POINTER_ARRAY );
        
                if ( (blocking_flag!=NULL_POINTER) && (*blocking_flag!=NULL_POINTER) ) {
                 
                    **((int**)blocking_flag) = *((int*)blocking_model); 
                }
                
            }                            
        }             
    } 
    else {

        log_message_debug("Could not receive the tcp server socket. The internal is null.");
    }
}

/* RECEIVE_TCP_SOCKET_SOURCE */
#endif
