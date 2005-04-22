/*
 * $RCSfile: interupt_tcp_socket.c,v $
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

#ifndef INTERUPT_TCP_SOCKET_SOURCE
#define INTERUPT_TCP_SOCKET_SOURCE

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
 * Interupts the tcp socket service.
 *
 * @param internals the internals memory
 * @param know the knowledge
 * @param know_count the knowledge count
 * @param know_size the knowledge size
 */
void interupt_tcp_socket( void* internals, const void* know, 
                          const void* know_count, const void* know_size ) 
{

    log_message_debug("interupt tcp socket.");
    
    //check of null pointer
    if ( internals != NULL_POINTER ) {
                    
        
        //set the activation flag in the internal
        void** socket_flag = POINTER_NULL_POINTER;

        get_array_elements( internals, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, 
                            (void*) &socket_flag, (void*) POINTER_ARRAY );

        if ( (socket_flag!=NULL_POINTER) && (*socket_flag!=NULL_POINTER) ) {
         
            **((int**)socket_flag) = 0; 
        }
    } 
    else {

        log_message_debug("Could not interupt the tcp server socket. The internal is null.");
    }
}

/* INTERUPT_TCP_SOCKET_SOURCE */
#endif
