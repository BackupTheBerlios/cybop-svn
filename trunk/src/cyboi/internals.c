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
 * @version $Revision: 1.8 $ $Date: 2004-12-21 10:24:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNALS_SOURCE
#define INTERNALS_SOURCE

#include "../array/array.c"
#include "../cyboi/integer_internals.c"
#include "../cyboi/double_internals.c"
#include "../cyboi/character_internals.c"
#include "../cyboi/pointer_internals.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * create a internal
 *
 * @param pp_internalvalue pointer of the internal value
 * @param p_valuetype
 * @param p_arrayindex
 */
void create_internal( void** pp_internalvalue, int* p_valuetype )
{
    if ( pp_internalvalue == NULL_POINTER ) {

        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else if ( p_valuetype == NULL_POINTER ) {

        log_message_debug( "p_valuetype is a NULL POINTER" );
    }
    else {

        log_message_debug( "create_internal is started" );

        //create the value in context of the type
        if ( *p_valuetype == *INTERNAL_TYPE_INTEGER ) {

            create_integer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == *INTERNAL_TYPE_CHARACTER ) {

            create_character_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == *INTERNAL_TYPE_POINTER ) {

            create_pointer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == *INTERNAL_TYPE_DOUBLE ) {

            create_double_internal( pp_internalvalue );
        }
        else {

            log_message_debug( "no correct valuetype" );
        }
    }
}


/**
 * destroy  a internal
 *
 * @param pp_internalvalue pointer of the internal value
 */
void destroy_internal( void** pp_internalvalue, int* p_valuetype )
{
    if ( pp_internalvalue == NULL_POINTER ) {

        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else if ( p_valuetype == NULL_POINTER ) {

        log_message_debug( "p_valuetype is a NULL POINTER" );
    }
    else {

        log_message_debug( "destroy_internal is started" );

        //destroy the value in context of the type
        if ( *p_valuetype == *INTERNAL_TYPE_INTEGER ) {

            destroy_integer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == *INTERNAL_TYPE_CHARACTER ) {

            destroy_character_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == *INTERNAL_TYPE_POINTER ) {

            destroy_pointer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == *INTERNAL_TYPE_DOUBLE ) {

            destroy_double_internal( pp_internalvalue );
        }
        else {

            log_message_debug( "no correct valuetype" );
        }
    }
}

/* INTERNALS_SOURCE */
#endif
