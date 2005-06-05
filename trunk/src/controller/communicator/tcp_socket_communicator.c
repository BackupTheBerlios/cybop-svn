/*
 * $RCSfile: tcp_socket_communicator.c,v $
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
 * This file contains the functionality to:
 * - receive an http stream into a byte array
 * - send an http stream from a byte array
 *
 * @version $Revision: 1.2 $ $Date: 2005-06-05 11:12:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TCP_SOCKET_COMMUNICATOR_SOURCE
#define TCP_SOCKET_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/constant.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memory/array/array.c"

/**
 * Receives an http stream and writes it into a byte array.
 *
 * @param p0 the destination (byte array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (http url)
 * @param p4 the source count
 */
/*??
void receive_tcp_socket(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}
*/

/**
 * Sends an http stream that was read from a byte array.
 *
 * @param p0 the destination (client socket number) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 */
void send_tcp_socket(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            int** d = (int**) p0;

            // The output.
            void* o = (void*) p3;
            // The output count.
            int oc = *sc;
            // The send byte gets returned.
            int b = send(**d, o, oc, 0);

            if (b < 0) {

                log_message_debug("ERROR: Could not send via tcp socket.");
            }

        } else {

            log_message_debug("ERROR: The destination (client socket number) is null.");
        }

    } else {

        log_message_debug("ERROR: The source count is null.");
    }
}

/* TCP_SOCKET_COMMUNICATOR_SOURCE */
#endif
