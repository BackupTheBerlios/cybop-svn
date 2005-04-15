/*
 * $RCSfile: input_output_handler.c,v $
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
 * @version $Revision: 1.16 $ $Date: 2005-04-15 09:01:01 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INPUT_OUTPUT_HANDLER_SOURCE
#define INPUT_OUTPUT_HANDLER_SOURCE

#include "../creator/integer_creator.c"
#include "../global/integer_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../socket/unix_socket.c"
#include "../web/tcp_socket_server.c"

/**
 * Starts up the input output.
 *
 * in the internals must be create the atctivation flag
 * for the different input / output mechanismen
 *
 * To the mechanisms belong:
 * - unix socket
 * - tcp socket
 * - x window system
 *
 * @param p0 the internals memory
 */
void startup_input_output(void* p0) {

    if ( p0 != NULL_POINTER ) {

        log_message_debug("Startup input output.");

        int* activation_flag = INTEGER_NULL_POINTER;

        // The activation flag for unix socket.
        activation_flag = INTEGER_NULL_POINTER;
        create_integer( &activation_flag );
        *activation_flag = 0;
        
        set_array_elements( p0, 
                            (void*) UNIX_SERVER_SOCKET_ACTIVE_INTERNAL,
                            (void*) &activation_flag, 
                            (void*) ONE_NUMBER, 
                            (void*) POINTER_ARRAY );
    
        // The activation flag for tcp server socket.
        activation_flag = INTEGER_NULL_POINTER;
        create_integer( &activation_flag );
        *activation_flag = 0;
        
        set_array_elements( p0, 
                            (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL,
                            (void*) &activation_flag, 
                            (void*) ONE_NUMBER, 
                            (void*) POINTER_ARRAY );
    }
    else {
     
        log_message_debug( "Can not startup_input_output. The internal is null.");
    }        
}

/**
 * Shuts down the input output mechanisms.
 * 
 * in the internals must be destroy the atctivation flag
 * for the different input / output mechanismen
 * 
 * To the mechanisms belong:
 * - x window system
 * - tcp socket
 * - unix socket
 *
 * @param p0 the internals memory
 */
void shutdown_input_output(void* p0) {

    log_message_debug("Shutdown input output.");

    // The activation flag.
    void** f = POINTER_NULL_POINTER;

    // UNIX socket server.
    get_array_elements(p0, (void*) UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        destroy_integer( f );

        f = POINTER_NULL_POINTER;
    }

    // TCP socket server.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_ARRAY);

    if (f != NULL_POINTER) {

        destroy_integer( f );

        f = POINTER_NULL_POINTER;
    }
}

/* INPUT_OUTPUT_HANDLER_SOURCE */
#endif
