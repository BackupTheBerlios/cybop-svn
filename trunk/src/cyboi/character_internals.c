/*
 * $RCSfile: character_internals.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2004-11-16 16:49:00 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_INTERNALS_SOURCE
#define CHARACTER_INTERNALS_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"


/**
 * creates a character internal
 *
 * @param pp_internalvalue
 * @param pp_value
 * @param p_valuecount
 */
void create_character_internal( void** pp_internalvalue, void** pp_value,
                              int* p_valuecount ) {

    create_array( pp_internalvalue, (void*) &CHARACTER_ARRAY, p_valuecount );
    
    int array_index = 0;
    set_array_elements( pp_internalvalue, (void*) &CHARACTER_ARRAY, 
                        (void*) &array_index, 
                        pp_value, p_valuecount );
}                                 

/**
 * destroy a character internal
 *
 * @param pp_internalvalue
 * @param p_valuecount
 */
void destroy_character_internal( void** pp_internalvalue, 
                              int* p_valuecount ) {

    destroy_array( pp_internalvalue, (void*) &CHARACTER_ARRAY, p_valuecount );
}                                 


/* CHARACTER_INTERNALS_SOURCE */
#endif
