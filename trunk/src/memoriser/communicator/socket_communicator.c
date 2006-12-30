/*
 * $RCSfile: socket_communicator.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2006-12-30 21:55:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SOCKET_COMMUNICATOR_SOURCE
#define SOCKET_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/array.c"

/**
 * Reads a byte array stream from the socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source socket
 * @param p4 the source count
 */
/*??
void read_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {
}
*/

/**
 * Writes a byte array stream to the socket.
 *
 * @param p0 the destination socket (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte array
 * @param p4 the source count
 */
void write_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                log_message_debug("Error: Could not write to socket.");
            }

        } else {

            log_message_debug("Error: The destination (client socket number) is null.");
        }

    } else {

        log_message_debug("Error: The source count is null.");
    }
}

/* SOCKET_COMMUNICATOR_SOURCE */
#endif
