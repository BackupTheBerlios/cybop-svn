/*
 * $RCSfile: socket_number_accessor.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2004-12-21 17:49:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_NUMBER_ACCESSOR_SOURCE
#define SOCKET_NUMBER_ACCESSOR_SOURCE

#include "../array/array.c"
#include "../cyboi/internals.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Add the client socket number in a integer array.
 *
 * @param pp_internals the pointer to the internals
 * @param p_socket_number the client socket number
 */
void add_client_socket_number(void** pp_internals, int* p_socket_number) {

    // get the client socket number from internal
    void** pp_clientsocketnumbers = NULL_POINTER;
    int* p_clientsocketnumbers_count = NULL_POINTER;
    int* p_clientsocketnumbers_size = NULL_POINTER;

    int internal_type = 0;
    get_internal( pp_internals, (void*) &pp_clientsocketnumbers,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER );
    get_internal( pp_internals, (void*) &p_clientsocketnumbers_count,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT );
    get_internal( pp_internals, (void*) &p_clientsocketnumbers_size,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE);

    //resize the array for the client socket number as a requirement
    if (*p_clientsocketnumbers_count >= *p_clientsocketnumbers_size) {

        *p_clientsocketnumbers_size = *p_clientsocketnumbers_size + 1;

        resize_array(pp_clientsocketnumbers, (void*) &INTEGER_ARRAY, p_clientsocketnumbers_size);

        set_internal(pp_internals, (void*) &pp_clientsocketnumbers,
            (void*) &INTERNAL_TYPE_POINTER,
            (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER);
    }

    // Add the socket number.
    set_array_elements(pp_clientsocketnumbers, (void*) &INTEGER_ARRAY,
        p_clientsocketnumbers_count, p_socket_number, (void*) &ONE_ELEMENT_COUNT);

    *p_clientsocketnumbers_count = *p_clientsocketnumbers_count+1;
}

/**
 * Adds the main signal id in a integer array.
 *
 * @param pp_internals the pointer to the internals
 * @param p_main_signal_id the main signal id
 */
void add_main_signal_id(void** pp_internals, int* main_signal_id) {

    // get the main signal id from internal
    void** pp_mainsignal_ids = NULL_POINTER;
    int* p_mainsignal_ids_count = NULL_POINTER;
    int* p_mainsignal_ids_size = NULL_POINTER;

    int internal_type = 0;

    get_internal( pp_internals, (void*) &pp_mainsignal_ids,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID );
    get_internal( pp_internals, (void*) &p_mainsignal_ids_count,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT );
    get_internal( pp_internals, (void*) &p_mainsignal_ids_size,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE );

    //resize the array for the client socket number as a requirement
    if (*p_mainsignal_ids_count >= *p_mainsignal_ids_size) {

        *p_mainsignal_ids_size = *p_mainsignal_ids_size + 1;
        resize_array( pp_mainsignal_ids, (void*) &INTEGER_ARRAY,
                      p_mainsignal_ids_size );
        set_internal( pp_internals, (void*) &pp_mainsignal_ids,
                      (void*) &INTERNAL_TYPE_POINTER,
                      (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID );
    }

    // Add the socket number.
    set_array_elements(pp_mainsignal_ids, (void*) &INTEGER_ARRAY,
        p_mainsignal_ids_count, main_signal_id, (void*) &ONE_ELEMENT_COUNT);

    *p_mainsignal_ids_count = *p_mainsignal_ids_count+1;
}

/**
 * remove the client socket number and the main signal id from the internals
  *
 * @param pp_internals the pointer to the internals
 * @param p_index the index to remove from the array in the internals
 */
void remove_relation_clientsocketnumber_mainsignalid( void** pp_internals,
                                                      int* p_index ){

    if ( pp_internals == NULL_POINTER ) {

        log_message_debug( "pp_internals is a NULL POINTER" );
    }
    else if ( p_index  == NULL_POINTER ) {

        log_message_debug( "p_index is a NULl POINTER" );
    }
    else {

        // get the main signal id from internal
        void** pp_mainsignal_ids = NULL_POINTER;
        int* p_mainsignal_ids_count = NULL_POINTER;
        int* p_mainsignal_ids_size = NULL_POINTER;

        int internal_type = 0;

        get_internal( pp_internals, (void*) &pp_mainsignal_ids,
                      (void*) &internal_type,
                      (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID );
        get_internal( pp_internals, (void*) &p_mainsignal_ids_count,
                      (void*) &internal_type,
                      (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT );
        get_internal( pp_internals, (void*) &p_mainsignal_ids_size,
                      (void*) &internal_type,
                      (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE );

        //remove the main signal id
        remove_array_element( pp_mainsignal_ids, (void*) &INTEGER_ARRAY,
                              p_mainsignal_ids_size, p_index );
        *p_mainsignal_ids_count = *p_mainsignal_ids_count -1;

        // get the client socket number from internal
        void** pp_clientsocketnumbers = NULL_POINTER;
        int* p_clientsocketnumbers_count = NULL_POINTER;
        int* p_clientsocketnumbers_size = NULL_POINTER;

        get_internal( pp_internals, (void*) &pp_clientsocketnumbers,
                      (void*) &internal_type,
                      (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER );
        get_internal( pp_internals, (void*) &p_clientsocketnumbers_count,
                      (void*) &internal_type,
                      (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT );
        get_internal( pp_internals, (void*) &p_clientsocketnumbers_size,
                      (void*) &internal_type,
                      (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE );
        //remove the client socket number
        remove_array_element( pp_clientsocketnumbers, (void*) &INTEGER_ARRAY,
                              p_clientsocketnumbers_size, p_index );
        *p_clientsocketnumbers_count = *p_clientsocketnumbers_count - 1;
    }
}

/**
 * get the index from the main signal id from the internals array
 *
 * @param pp_internals the pointer to the internals
 * @param p_main_signal_id the main signal id
 * @oaram p_index return the index in the array
 */
void get_index_for_main_signal_id(void** pp_internals, int* p_main_signal_id, int* p_index) {

    // get the main signal id from internal
    void** pp_mainsignal_ids = NULL_POINTER;
    int* p_mainsignal_ids_count = NULL_POINTER;
    int* p_mainsignal_ids_size = NULL_POINTER;

    int internal_type = 0;

    get_internal( pp_internals, (void*) &pp_mainsignal_ids,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID );
    get_internal( pp_internals, (void*) &p_mainsignal_ids_count,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID_COUNT );
    get_internal( pp_internals, (void*) &p_mainsignal_ids_size,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_MAINSIGNALID_SIZE );

    //get the index
    get_array_element_index( pp_mainsignal_ids, (void*) &INTEGER_ARRAY,
                             p_mainsignal_ids_size, p_main_signal_id,
                             p_index );
}

/**
 * get the client socket number from the internal on the array index
 *
 * @param pp_internals the pointer to the internals
 * @oaram p_index the index in the array
 * @param p_client_socket_number the client socket number in the array
 */
void get_client_socket_number_for_index( void** pp_internals,
                                         int* p_index,
                                         int* p_client_socket_number ) {

    // get the client socket number from internal
    void** pp_clientsocketnumbers = NULL_POINTER;
    int* p_clientsocketnumbers_count = NULL_POINTER;
    int* p_clientsocketnumbers_size = NULL_POINTER;

    int internal_type = 0;
    get_internal( pp_internals, (void*) &pp_clientsocketnumbers,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER );
    get_internal( pp_internals, (void*) &p_clientsocketnumbers_count,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT );
    get_internal( pp_internals, (void*) &p_clientsocketnumbers_size,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE );

    get_array_element(pp_clientsocketnumbers, (void*) &INTEGER_ARRAY,
                      p_index, p_client_socket_number);
}

/* SOCKET_NUMBER_ACCESSOR_SOURCE */
#endif
