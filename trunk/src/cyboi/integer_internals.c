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
 * @version $Revision: 1.3 $ $Date: 2004-11-23 08:17:37 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_INTERNALS_SOURCE
#define INTEGER_INTERNALS_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"


/**
 * creates a integer internal
 *
 * @param pp_internalvalue
 * @param pp_value
 * @param p_valuecount
 */
void create_integer_internal( void** pp_internalvalue ) {

    int count = 1;
    create_array( pp_internalvalue, (void*) &INTEGER_ARRAY, (void*) &count );
}                                 

/**
 * destroy a integer internal
 *
 * @param pp_internalvalue
 * @param p_valuecount
 */
void destroy_integer_internal( void** pp_internalvalue ) {

    int count = 1;
    destroy_array( pp_internalvalue, (void*) &INTEGER_ARRAY, (void*) &count );
}                                 

/**
 * set a integer internal
 *
 * @param pp_internalvalue
 * @param p_valuecount
 */
void set_integer_internal( void** pp_internalvalue, void* p_newvalue ) {

    if ( pp_internalvalue == NULL_POINTER ) {
        
        log_message_debug( "pp_internalvalue is a NULL POINTER" );
    }
    else if ( p_newvalue == NULL_POINTER ) {
     
        log_message_debug( "p_newvalue is a NULL POINTER" );
    }
    else {
        
        int arrayindex = 0;
        set_array_element( pp_internalvalue,
                           (void*) &INTEGER_ARRAY,
                           (void*) &arrayindex,
                           p_newvalue );        
    }
}                                 



/* INTEGER_INTERNALS_SOURCE */
#endif
