/*
 * $RCSfile: internals.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2004-06-27 00:59:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNALS_SOURCE
#define INTERNALS_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Creates the internals.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_internals(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTERNALS_MESSAGE, (void*) &CREATE_INTERNALS_MESSAGE_COUNT);

    // Create internals.
    create_array(p0, (void*) &INTEGER_ARRAY, (void*) &INTERNALS_COUNT);

    // Initialize elements.
    int unix_socket_flag = 0;
//??    int x_windows_flag = 0;
//??    void* x_windows = NULL_POINTER;
//??    int macintosh_flag = 0;
//??    void* macintosh = NULL_POINTER;
//??    int ms_windows_flag = 0;
//??    void* ms_windows = NULL_POINTER;

    // Create elements.
//??    create_array((void*) &p, (void*) &POINTER_ARRAY, p1);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &UNIX_SOCKET_FLAG_INDEX, (void*) &unix_socket_flag);
}

/**
 * Destroys the internals.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_internals(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_INTERNALS_MESSAGE, (void*) &DESTROY_INTERNALS_MESSAGE_COUNT);

    // Initialize elements.
    int unix_socket_flag = 0;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &UNIX_SOCKET_FLAG_INDEX, (void*) &unix_socket_flag);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &INTERNALS_COUNT, (void*) &UNIX_SOCKET_FLAG_INDEX);

    // Destroy elements.
//??    destroy_array((void*) &p, (void*) &POINTER_ARRAY, p1);

    // Destroy internals.
    destroy_array(p0, (void*) &INTEGER_ARRAY, (void*) &INTERNALS_COUNT);
}

/* INTERNALS_SOURCE */
#endif
