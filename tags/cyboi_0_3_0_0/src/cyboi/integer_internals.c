/*
 * $RCSfile: integer_internals.c,v $
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
 * This file handles cyboi internal variables which are needed to communicate
 * with underlying sub systems or hardware directly. Various platforms and
 * user interfaces are considered.
 *
 * Variables belong to for example:
 * - Socket
 * - TCP/IP
 * - X-Windows
 * - Macintosh
 * - MS Windows
 *
 * @version $Revision: 1.1 $ $Date: 2004-07-04 09:49:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_INTERNALS_SOURCE
#define INTEGER_INTERNALS_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Creates the integer internals.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_integer_internals(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTERNALS_MESSAGE, (void*) &CREATE_INTERNALS_MESSAGE_COUNT);

    // Create integer internals.
    create_array(p0, (void*) &INTEGER_ARRAY, p1);

    // Initialize elements.
    int unix_server_socket = -1;

    // Set elements in ascending order.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &UNIX_SERVER_SOCKET_INDEX, (void*) &unix_server_socket);
}

/**
 * Destroys the integer internals.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_integer_internals(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_INTERNALS_MESSAGE, (void*) &DESTROY_INTERNALS_MESSAGE_COUNT);

    // Initialize elements.
    int unix_server_socket = -1;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &UNIX_SERVER_SOCKET_INDEX, (void*) &unix_server_socket);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, p1, (void*) &UNIX_SERVER_SOCKET_INDEX);

    // Destroy integer internals.
    destroy_array(p0, (void*) &INTEGER_ARRAY, p1);
}

/* INTEGER_INTERNALS_SOURCE */
#endif
