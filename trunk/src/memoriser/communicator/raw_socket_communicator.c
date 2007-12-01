/*
 * $RCSfile: raw_socket_communicator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2007-12-01 23:57:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RAW_SOCKET_COMMUNICATOR_SOURCE
#define RAW_SOCKET_COMMUNICATOR_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Reads a byte array stream from the raw socket.
 *
 * @param p0 the destination byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source socket
 * @param p4 the source count
 */
void read_raw_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Read from raw socket.");
    log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "The raw socket functionality is NOT implemented yet.");
}

/**
 * Writes a byte array stream to the raw socket.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source byte array count
 * @param p3 the socket address of the communication partner (Hand over as reference!)
 * @param p4 the socket address of the communication partner size
 * @param p5 the communication mode
 * @param p6 the communication mode count
 * @param p7 the communication style
 */
void write_raw_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // Not implemented.
    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Write to raw socket.");
    log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "The raw socket functionality is NOT implemented yet!");
}

/* RAW_SOCKET_COMMUNICATOR_SOURCE */
#endif
