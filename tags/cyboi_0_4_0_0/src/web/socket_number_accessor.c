/*
 * $RCSfile: socket_number_accessor.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.13 $ $Date: 2005-01-19 19:31:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SOCKET_NUMBER_ACCESSOR_SOURCE
#define SOCKET_NUMBER_ACCESSOR_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Adds the client socket.
 *
 * @param p0 the internals memory
 * @param p1 the client socket
 */
void add_client_socket_number(void* p0, void* p1) {

    // The client sockets.
    void* cs = NULL_POINTER;
    int* csc = INTEGER_NULL_POINTER;
    int* css = INTEGER_NULL_POINTER;

    // Get client sockets.
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_ARRAY);

    // Resize client sockets array.
    if (*csc >= *css) {

        (*css)++;

        resize_array((void*) &cs, (void*) css, (void*) INTEGER_ARRAY);

        set_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
    }

    // Add socket number.
    set_array_elements(cs, (void*) csc, p1, (void*) ONE_NUMBER, (void*) INTEGER_ARRAY);

    (*csc)++;
}

/**
 * Adds the signal id.
 *
 * @param p0 the internals memory
 * @param p1 the signal identification
 */
void add_signal_id(void* p0, void* p1) {

    // get the main signal id from internal
    void* id = NULL_POINTER;
    int* idc = INTEGER_NULL_POINTER;
    int* ids = INTEGER_NULL_POINTER;

    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_ARRAY);

    // Resize the array for the client socket number as a requirement.
    if (*idc >= *ids) {

        (*ids)++;

        resize_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY);

        set_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
    }

    // Add the socket number.
    set_array_elements(id, (void*) idc, p1, (void*) ONE_NUMBER, (void*) INTEGER_ARRAY);

    (*idc)++;
}

/**
 * Removes the client socket.
 *
 * Its signal id is removed as well.
 *
 * @param p0 the internals memory
 * @param p1 the index
 */
void remove_relation_clientsocketnumber_mainsignalid(void* p0, void* p1) {

    // The signal id.
    void* id = NULL_POINTER;
    int* idc = INTEGER_NULL_POINTER;
    int* ids = INTEGER_NULL_POINTER;

    // Get signal id.
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_ARRAY);

    // Remove signal id.
    remove_array_elements(id, (void*) ids, p1, (void*) ONE_NUMBER, (void*) INTEGER_ARRAY);

    (*idc)--;

    // Get client socket.
    void* cs = NULL_POINTER;
    int* csc = INTEGER_NULL_POINTER;
    int* css = INTEGER_NULL_POINTER;

    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_ARRAY);

    // Remove client socket.
    remove_array_elements(cs, (void*) css, p1, (void*) ONE_NUMBER, (void*) INTEGER_ARRAY);

    (*csc)--;
}

/**
 * Gets the index for the signal id.
 *
 * @param p0 the internals memory
 * @param p1 the signal identification
 * @param p2 the index
 */
void get_index_for_signal_id(void* p0, const void* p1, void* p2) {

    // The signal id.
    void* id = NULL_POINTER;
    void* idc = NULL_POINTER;
    void* ids = NULL_POINTER;

    // Get signal id.
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_ARRAY);

    // Get index.
    get_array_elements_index(id, (void*) ids, p1, (void*) ONE_NUMBER, p2, (void*) INTEGER_ARRAY);
}

/**
 * Gets the client socket.
 *
 * @param p0 the internals memory
 * @param p1 the index
 * @param p2 the client socket
 */
void get_client_socket_number_for_index(void* p0, void* p1, void* p2) {

    // The client sockets.
    void* cs = NULL_POINTER;
    void* csc = NULL_POINTER;
    void* css = NULL_POINTER;

    // Get client sockets.
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_ARRAY);

    // Get client socket.
    get_array_elements(cs, p1, p2, (void*) INTEGER_ARRAY);
}

/* SOCKET_NUMBER_ACCESSOR_SOURCE */
#endif
