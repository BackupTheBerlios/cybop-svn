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
 * @version $Revision: 1.4 $ $Date: 2004-11-16 16:47:36 $ $Author: rholzmueller $
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
void create_internal(void** pp_internal) {

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else {

        log_message_debug( "create_internal is started" );

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

        // create internal value count
        void* p_int_valuecount = NULL_POINTER;
        create_array( (void*) &p_int_valuecount, (void*) &INTEGER_ARRAY, 
                      (void*) &INTERNAL_ARRAY_COUNT );
        set_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUECOUNT_INDEX,
                           (void*) &p_int_valuecount );        

        // create internal value size
        void* p_int_valuesize = NULL_POINTER;
        create_array( (void*) &p_int_valuesize, (void*) &INTEGER_ARRAY, 
                      (void*) &INTERNAL_ARRAY_COUNT );
        set_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUESIZE_INDEX,
                           (void*) &p_int_valuesize );        
    }                      
}

/**
 * destroys the internals
 *
 * @param p_internal pointer of the internal
 */
void destroy_internal(void** pp_internal) {

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else {

        log_message_debug( "destroy_internal is started" );

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

        // destroy internal value count
        void* p_int_valuecount = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUECOUNT_INDEX,
                           (void*) &p_int_valuecount );        
        destroy_array( (void*) &p_int_valuecount, (void*) &INTEGER_ARRAY, 
                       (void*) &INTERNAL_ARRAY_COUNT );

        // destroy internal value size
        void* p_int_valuesize = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUESIZE_INDEX,
                           (void*) &p_int_valuesize );        
        destroy_array( (void*) &p_int_valuesize, (void*) &INTEGER_ARRAY, 
                       (void*) &INTERNAL_ARRAY_COUNT );
                           
        // destroy internal
        destroy_array( pp_internal, (void*) &POINTER_ARRAY, 
                      (void*) &INTERNAL_COLUMN_COUNT );
                           
    }                      
}

/**
 * set the internals
 *
 * @param pp_internal pointer of the internal
 * @param pp_value
 * @param p_valuetype
 * @param p_valuecount
 * @param p_valuesize
 * @param p_arrayindex
 */
void set_internal( void** pp_internal, 
                   void** pp_value, int* p_valuetype, 
                   int* p_valuecount, int* p_valuesize,
                   int* p_arrayindex ) 
{

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    if ( pp_value == NULL_POINTER ) {
      
        log_message_debug( "pp_value is a NULL POINTER" );
    }
    else if ( p_valuetype == NULL_POINTER ) {
        
        log_message_debug( "p_valuetype is a NULL POINTER" );
    }
    else if ( p_valuecount == NULL_POINTER ) {
        
        log_message_debug( "p_valuecount is a NULL POINTER" );
    }
    else if ( p_valuesize == NULL_POINTER ) {
        
        log_message_debug( "p_valuesize is a NULL POINTER" );
    }
    else {

        log_message_debug( "set_internal is started" );

        // set the value into internal
        void* p_internalvalue = NULL_POINTER;
        
        // get the value internal column
        void* p_int_value = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUE_INDEX,
                           (void*) &p_int_value );        


        //create the value in context of the type
        if ( *p_valuetype == INTERNAL_TYPE_INTEGER ) {
        
            create_integer_internal( (void*) &p_internalvalue,
                                     pp_value,   
                                     p_valuecount );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_CHARACTER ) {
            
            create_character_internal( (void*) &p_internalvalue,
                                     pp_value,   
                                     p_valuecount );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_POINTER ) {
            
            create_pointer_internal( (void*) &p_internalvalue,
                                     pp_value,   
                                     p_valuecount );
        }
        else if ( *p_valuetype == INTERNAL_TYPE_DOUBLE ) {
            
            create_double_internal( (void*) &p_internalvalue,
                                     pp_value,   
                                     p_valuecount );
        }
        else {
         
            log_message_debug( "no correct valuetype" );
        }
        
        // set the value into internals
        set_array_element( (void*) &p_int_value,
                           (void*) &POINTER_ARRAY,
                           p_arrayindex,
                           (void*) &p_internalvalue );        


        // set the value type into internal
        void* p_int_valuetype = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUETYPE_INDEX,
                           (void*) &p_int_valuetype );        
        set_array_element( (void*) &p_int_valuetype,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuetype );        

        // set the value count into internal
        void* p_int_valuecount = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUECOUNT_INDEX,
                           (void*) &p_int_valuecount );        
        set_array_element( (void*) &p_int_valuecount,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuecount );        

        // set the value size into internal
        void* p_int_valuesize = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUESIZE_INDEX,
                           (void*) &p_int_valuesize );        
        set_array_element( (void*) &p_int_valuesize,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuesize );        
                           
    }
}

/**
 * get the internals
 *
 * @param pp_internal pointer of the internal
 * @param p_value
 * @param p_valuetype
 * @param p_valuecount
 * @param p_valuesize
 * @param p_arrayindex
 */
void get_internal( void** pp_internal, 
                   void** pp_value, int* p_valuetype, 
                   int* p_valuecount, int* p_valuesize,
                   int* p_arrayindex ) 
{

    if ( pp_internal == NULL_POINTER ) {
      
        log_message_debug( "pp_internal is a NULL POINTER" );
    }
    else if ( pp_value == NULL_POINTER ) {
        
        log_message_debug( "pp_value is a NULL POINTER" );
    }
    else if ( p_valuetype == NULL_POINTER ) {
        
        log_message_debug( "p_valuetype is a NULL POINTER" );
    }
    else if ( p_valuecount == NULL_POINTER ) {
        
        log_message_debug( "p_valuecount is a NULL POINTER" );
    }
    else if ( p_valuesize == NULL_POINTER ) {
        
        log_message_debug( "p_valuesize is a NULL POINTER" );
    }
    else {

        log_message_debug( "get_internal is started" );

        // get the value into internal
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

        // get the value count into internal
        void* p_int_valuecount = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUECOUNT_INDEX,
                           (void*) &p_int_valuecount );        
        get_array_element( (void*) &p_int_valuecount,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuecount);        

        // get the value size into internal
        void* p_int_valuesize = NULL_POINTER;
        get_array_element( pp_internal,
                           (void*) &POINTER_ARRAY,
                           (void*) &INTERNAL_COLUMN_VALUESIZE_INDEX,
                           (void*) &p_int_valuesize );        
        get_array_element( (void*) &p_int_valuesize,
                           (void*) &INTEGER_ARRAY,
                           p_arrayindex,
                           p_valuesize);        
                           
    }
}

/* INTERNALS_SOURCE */
#endif
