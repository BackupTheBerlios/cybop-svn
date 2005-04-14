/*
 * $RCSfile: startup_tcp_socket.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-04-14 06:41:28 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_TCP_SOCKET_SOURCE
#define STARTUP_TCP_SOCKET_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../global/abstraction_constants.c"
#include "../../global/integer_constants.c"
#include "../../global/structure_constants.c"
#include "../../global/variables.c"

/**
 * Starts up the tcp socket service.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_tcp_socket( void* internals, const void* know, 
                         const void* know_count, const void* know_size,
                         void* socket_port_abstr, void* socket_port_abstr_count,
                         void* socket_port_model, void* socket_port_model_count ) 
{

    log_message_debug("Startup tcp socket.");
    
    //check of null pointer
    if (    (internals != NULL_POINTER)
         && (know != NULL_POINTER)
         && (know_count != NULL_POINTER)
         && (know_size != NULL_POINTER)
         && (socket_port_abstr != NULL_POINTER) 
         && (socket_port_abstr_count != NULL_POINTER)
         && (socket_port_model != NULL_POINTER)
         && (socket_port_model_count != NULL_POINTER) )
    {
     
        int res = 0;
        
        //check the socket port of integer
        compare_arrays( (void*) socket_port_abstr, 
                        (void*) socket_port_abstr_count, 
                        (void*) INTEGER_ABSTRACTION, 
                        (void*) INTEGER_ABSTRACTION_COUNT, 
                        (void*) &res, (void*) CHARACTER_ARRAY);
                        
        if ( res == 1 ) {
         
            log_message_debug("Create tcp server socket.");
    
            fprintf(stderr, "DEBUG: The port is: %d \n", *(int*)socket_port_model);
    
            // The tcp server socket.
            int* s = INTEGER_NULL_POINTER;
            // The tcp client sockets.
            void* cs = NULL_POINTER;
            int* csc = INTEGER_NULL_POINTER;
            int* css = INTEGER_NULL_POINTER;
            // The tcp signal ids.
            void* id = NULL_POINTER;
            int* idc = INTEGER_NULL_POINTER;
            int* ids = INTEGER_NULL_POINTER;
    
            // Create tcp server socket.
            create_integer((void*) &s);
            *s = socket(PF_INET, SOCK_STREAM, 0);
            // Create tcp client sockets.
            create_integer((void*) &csc);
            *csc = 0;
            create_integer((void*) &css);
            *css = 0;
            create_array((void*) &cs, (void*) css, (void*) INTEGER_ARRAY);
            // Create tcp signal ids.
            create_integer((void*) &idc);
            *idc = 0;
            create_integer((void*) &ids);
            *ids = 0;
            create_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY);
    
            // Set tcp server socket.
            set_array_elements(internals, (void*) TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            // Set tcp client sockets.
            set_array_elements(internals, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(internals, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(internals, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            // Set tcp signal ids.
            set_array_elements(internals, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(internals, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(internals, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
    
            if (*s >= 0) {
    
                fprintf(stderr, "DEBUG: The tcp server socket is: %d \n", *s);
    
                // The socket address.
                struct sockaddr_in a;
    
                // Set address format.
                a.sin_family = AF_INET;
                a.sin_addr.s_addr = INADDR_ANY;
                a.sin_port = htons(*((int*)socket_port_model) );
    
                // Determine socket address size.
                int as = sizeof(struct sockaddr_in);
    
                // Bind number to address.
                if (bind(*s, (struct sockaddr*) &a, as) >= 0) {
    
                    // Set the number of possible pending client connection requests.
                    listen(*s, 1);
                    
                    //set the activation flahg in the internal
                    void** socket_flag = POINTER_NULL_POINTER;
                    get_array_elements(internals, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &socket_flag, (void*) POINTER_ARRAY);
                    if ( (socket_flag!=NULL_POINTER) && (*socket_flag!=NULL_POINTER) ) {
                     
                        **((int**)socket_flag) = 1; 
                    }
    
                } else {
    
                    log_message_debug("Could not create tcp server socket. The socket could not be bound to the address.");
                }
    
            } else {
    
                log_message_debug("Could not create tcp server socket. The socket is smaller than zero.");
            }
        }
    }
}

/* STARTUP_TCP_SOCKET_SOURCE */
#endif
