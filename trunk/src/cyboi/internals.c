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
 * @version $Revision: 1.5 $ $Date: 2004-11-23 08:17:37 $ $Author: rholzmueller $
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
 * create the internal
 *
 * @param p_internal pointer of the internal
 */
void create_internals_structur(void** pp_internal) {

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else {

        log_message_debug( "create_internals_structur is started" );

        // create internal
        create_array( pp_internal, (void*) &POINTER_ARRAY, 
                      (void*) &INTERNAL_COLUMN_COUNT );
                      
        // create internal value
        void* p_int_value = NULL_POINTER;
        create_array( (void*) &p_int_value, (void*) &POINTER_ARRAY, 
                      (void*) &INTERNAL_ARRAY_COUNT );
        set_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUE_INDEX,
                           (void*) &p_int_value );        

        // create internal value type
        void* p_int_valuetype = NULL_POINTER;
        create_array( (void*) &p_int_valuetype, (void*) &INTEGER_ARRAY, 
                      (void*) &INTERNAL_ARRAY_COUNT );
        set_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUETYPE_INDEX,
                           (void*) &p_int_valuetype );        
    }                      
}

/**
 * destroys the internals
 *
 * @param p_internal pointer of the internal
 */
void destroy_internals_structur(void** pp_internal) {

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else {

        log_message_debug( "destroy_internals_structur is started" );

        // destroy internal value 
        void* p_int_value = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUE_INDEX,
                           (void*) &p_int_value );        
        destroy_array( (void*) &p_int_value, (void*) &POINTER_ARRAY, 
                       (void*) &INTERNAL_ARRAY_COUNT );

        // destroy internal value type
        void* p_int_valuetype = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUETYPE_INDEX,
                           (void*) &p_int_valuetype );        
        destroy_array( (void*) &p_int_valuetype, (void*) &INTEGER_ARRAY, 
                       (void*) &INTERNAL_ARRAY_COUNT );

        // destroy internal
        destroy_array( pp_internal, (void*) &POINTER_ARRAY, 
                      (void*) &INTERNAL_COLUMN_COUNT );
    }                      
}



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
        if ( *p_valuetype == INTERNAL_TYPE_INTEGER ) {
        
            create_integer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_CHARACTER ) {
            
            create_character_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_POINTER ) {
            
            create_pointer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_DOUBLE ) {
            
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
        if ( *p_valuetype == INTERNAL_TYPE_INTEGER ) {
        
            destroy_integer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_CHARACTER ) {
            
            destroy_character_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_POINTER ) {
            
            destroy_pointer_internal( pp_internalvalue );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_DOUBLE ) {
            
            destroy_double_internal( pp_internalvalue );
        }
        else {
         
            log_message_debug( "no correct valuetype" );
        }
    }
}

/**
 * get the internals
 *
 * @param pp_internal pointer of the internal
 * @param p_value return the value for the internal
 * @param p_valuetype return the value type for the internal
 * @param p_arrayindex index in the internal array
 */
void get_internal( void** pp_internal, 
                   void** pp_value, int* p_valuetype, 
                   int* p_arrayindex ) {

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else if ( pp_value == NULL_POINTER ) {
        
        log_message_debug( "pp_value is a NULL POINTER" );
    }
    else if ( p_valuetype == NULL_POINTER ) {
        
        log_message_debug( "p_valuetype is a NULL POINTER" );
    }
    else {

        log_message_debug( "get_internal is started" );

        // get the value from internals
        void* p_int_value = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUE_INDEX,
                           (void*) &p_int_value );        
        get_array_element( (void*) &p_int_value,
                           (void*) &POINTER_ARRAY,
                           p_arrayindex,
                           pp_value );        
                           
        // get the value type into internal
        void* p_int_valuetype = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUETYPE_INDEX,
                           (void*) &p_int_valuetype );        
        get_array_element( (void*) &p_int_valuetype,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuetype);        
    }
}


/**
 * get the internals
 *
 * @param pp_internal pointer of the internal
 * @param p_value the value for the internal
 * @param p_valuetype the value type for the internal
 * @param p_arrayindex index in the internal array
 */
void set_internal( void** pp_internal, 
                   void** pp_internalvalue, int* p_valuetype, 
                   int* p_arrayindex ) {

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else if ( pp_internalvalue == NULL_POINTER ) {
        
        log_message_debug( "pp_intenralvalue is a NULL POINTER" );
    }
    else if ( p_valuetype == NULL_POINTER ) {
        
        log_message_debug( "p_valuetype is a NULL POINTER" );
    }
//    else if ( p_newvalue == NULL_POINTER ) {
//        
//        log_message_debug( "p_newvalue is a NULL POINTER" );
//    }
    else if ( p_arrayindex == NULL_POINTER ) {
        
        log_message_debug( "p_arrayindex is a NULL POINTER" );
    }
    else {

        log_message_debug( "set_internal is started" );

//        //set the new value into the inernal value
//        if ( *p_valuetype == INTERNAL_TYPE_INTEGER ) {
//        
//            set_integer_internal( pp_internalvalue, p_newvalue );
//        }
//        else if ( *p_valuetype == INTERNAL_TYPE_CHARACTER ) {
//            
//            set_character_internal( pp_internalvalue, p_newvalue );
//        }
//        else if ( *p_valuetype == INTERNAL_TYPE_POINTER ) {
//            
//            set_pointer_internal( pp_internalvalue, p_newvalue );
//        }
//        else if ( *p_valuetype == INTERNAL_TYPE_DOUBLE ) {
//            
//            set_double_internal( pp_internalvalue, p_newvalue );
//        }
//        else {
//         
//            log_message_debug( "no correct valuetype" );
//        }


        // set the value into internals
        void* p_int_value = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUE_INDEX,
                           (void*) &p_int_value );        
        set_array_element( (void*) &p_int_value,
                           (void*) &POINTER_ARRAY,
                           p_arrayindex,
                           pp_internalvalue );        
                           
        // set the value type into internal
        void* p_int_valuetype = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUETYPE_INDEX,
                           (void*) &p_int_valuetype );        
        set_array_element( (void*) &p_int_valuetype,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuetype);        
    }
}

/* INTERNALS_SOURCE */
#endif
