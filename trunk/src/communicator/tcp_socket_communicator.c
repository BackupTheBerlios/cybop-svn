/*
 * $RCSfile: tcp_socket_communicator.c,v $
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
 * This file contains the functionality to:
 * - receive an http stream into a byte array
 * - send an http stream from a byte array
 *
 * @version $Revision: 1.2 $ $Date: 2004-12-08 14:13:27 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TCP_SOCKET_COMMUNICATOR_SOURCE
#define TCP_SOCKET_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Receives an http stream and writes it into a byte array.
 *
 * @param p0 the destination (byte array)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (http url)
 * @param p4 the source count
 */
void receive_tcp_socket(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Sends an http stream that was read from a byte array.
 *
 * @param p0 the destination (socket number)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 */
void send_tcp_socket( int* p_client_socket_number, void* p1, void* p2, 
                      const void** pp_source, const void* p_source_count ) {

    if ( p_client_socket_number == NULL_POINTER ) {
        log_message_debug( "p_client_socket_number is a NULL pointer" );
    }
    else if ( pp_source == NULL_POINTER ) {
        log_message_debug( "pp_source is a NULL pointer" );
    }
    else if ( p_source_count == NULL_POINTER ) {
        log_message_debug( "p_source_count is a NULL pointer" );
    }
    else {

        char* ausgabe = *((char**) pp_source);
        int ausgabe_count = *((int*) p_source_count);
        int send_byte = 0;
        
        send_byte = send (*p_client_socket_number, ausgabe, ausgabe_count, 0);
        if ( send_byte < 0 ) {
         
            log_message_debug( "error on sending off the tcp socket" );
        }
    }
}

/* TCP_SOCKET_COMMUNICATOR_SOURCE */
#endif
