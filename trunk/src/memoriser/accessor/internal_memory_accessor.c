/*
 * $RCSfile: internal_memory_accessor.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2005-07-28 23:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef INTERNAL_MEMORY_ACCESSOR_SOURCE
#define INTERNAL_MEMORY_ACCESSOR_SOURCE

#include "../../globals/constants/constant.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Add the client socket.
 *
 * @param p0 the internal memory
 * @param p1 the client socket
 */
void add_client_socket_number(void* p0, void* p1) {

    // The client sockets.
    void** cs = POINTER_NULL_POINTER;
    void** csc = POINTER_NULL_POINTER;
    void** css = POINTER_NULL_POINTER;

    // Get client sockets.
    get(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Resize client sockets array.
    if ( *((int*)*csc) >= *((int*)*css) ) {

        (*((int*)*css))++;

        resize_array((void*) cs, (void*) *css, (void*) INTEGER_ARRAY);

        set(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, *cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    }

    // Add socket number.
    set_array_elements(*cs, (void*) *csc, p1, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

    (*((int*)*csc))++;
}

/**
 * Add the signal id.
 *
 * @param p0 the internal memory
 * @param p1 the signal identification
 */
void add_signal_id(void* p0, void* p1) {

    // Get main signal id from internal memory.
    void** id = POINTER_NULL_POINTER;
    void** idc = POINTER_NULL_POINTER;
    void** ids = POINTER_NULL_POINTER;

    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Resize the array for the client socket number as a requirement.
    if ( **((int**)idc) >= **((int**)ids) ){

        (**((int**)ids))++;

        resize_array((void*) id, (void*) *ids, (void*) INTEGER_ARRAY);

        set(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, *id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    }

    // Add the socket number.
    set_array_elements(*id, (void*) *idc, p1, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

    (*((int*)*idc))++;
}

/**
 * Removes the client socket and the signal id.
 *
 * @param p0 the internal memory
 * @param p1 the index
 */
void remove_relation_clientsocketnumber_mainsignalid(void* p0, void* p1) {

    // The signal id.
    void** id = POINTER_NULL_POINTER;
    void** idc = POINTER_NULL_POINTER;
    void** ids = POINTER_NULL_POINTER;

    // Get signal id.
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Remove signal id.
    remove_array_elements(*id, *ids, p1, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

    (*((int*)*idc))--;

    // Get client socket.
    void** cs = POINTER_NULL_POINTER;
    void** csc = POINTER_NULL_POINTER;
    void** css = POINTER_NULL_POINTER;

    get(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Remove client socket.
    remove_array_elements(*cs, *css, p1, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

    (*((int*)*csc))--;
}

/**
 * Get the index from the signal id array.
 *
 * @param p0 the internal memory
 * @param p1 the signal identification
 * @param p2 the index (hand over as reference)
 */
void get_index_for_signal_id(void* p0, void* p1, void* p2) {

    // The signal id.
    void** id = POINTER_NULL_POINTER;
    void** idc = POINTER_NULL_POINTER;
    void** ids = POINTER_NULL_POINTER;

    // Get signal id.
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Get index.
    get_array_elements_index(*id, (void*) *ids, p1, (void*) NUMBER_1_INTEGER, p2, (void*) INTEGER_ARRAY);
}

/**
 * Get the client socket.
 *
 * @param p0 the internal memory
 * @param p1 the index
 * @param p2 the client socket
 */
void get_client_socket_number_for_index(void* p0, void* p1, void* p2) {

    // The client sockets.
    void** cs = NULL_POINTER;
    void** csc = NULL_POINTER;
    void** css = NULL_POINTER;

    // Get client sockets.
    get(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Get client socket.
    get_array_elements(*cs, p1, p2, (void*) INTEGER_ARRAY);
}

/* INTERNAL_MEMORY_ACCESSOR_SOURCE */
#endif
