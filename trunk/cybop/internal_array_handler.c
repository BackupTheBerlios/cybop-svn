/*
 * $RCSfile: internal_array_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

#ifndef INTERNAL_ARRAY_HANDLER_SOURCE
#define INTERNAL_ARRAY_HANDLER_SOURCE

#include "log_handler.c"

/**
 * This is the internal array handler.
 *
 * Internal array elements are accessed over their index.
 *
 * @version $Revision: 1.1 $ $Date: 2003-10-12 14:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Internal array element.
//

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the element
 */
static void set_array_element(void** p0, void* p1, void* p2) {

    if (p0 != 0) {

        int* i = (int*) p1;
        int size = a->size;
        void** ia = a->internal_array;

        if (ia != 0) {
                
            puts("TEST 0");
            
            // If the array length is exceeded, create a new array with extended length.
            // Do this as long as the given index is greater or equal to the array's size.
            while (*i >= size) {
    
                puts("TEST 1");
    
                //?? Change this behaviour!
                //?? First calculate the new array size and then create the new array!
                //?? This avoids repeated copying of array elements.
                //?? Possibly move the contents of the "extend_array" function to here!
                extend_array(a);
                size = a->size;
            }
    
            if (*i != INVALID_VALUE) {
                    
                // Set element.
                ia[*i] = p2;
            
            } else {
        
                log((void*) &WARNING_LOG_LEVEL, "Could not set array element. The index is invalid.");
            }

        } else {
    
            log((void*) &ERROR_LOG_LEVEL, "Could not set array element. The internal array is null.");
        }
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not set array element. The array is null.");
    }
}

/**
 * Removes the array element.
 *
 * @param p0 the array
 * @param p1 the index
 */
static void remove_array_element(void* p0, void* p1) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        int* i = (int*) p1;
        int size = a->size;
        void** ia = a->internal_array;
        
        if (ia != 0) {
                
            if (*i != INVALID_VALUE) {
    
                // Starting from the given index, move all remaining elements one
                // place towards the beginning of the elements.
                while ((*i + 1) < size) {
    
                    ia[*i] = ia[*i + 1];
    
                    (*i)++;
                }
    
                // Set former last element to 0.
                ia[*i] = 0;
            
            } else {
        
                log((void*) &WARNING_LOG_LEVEL, "Could not remove array element. The index is invalid.");
            }
    
        } else {
    
            log((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The internal array is null.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The array is null.");
    }
}

/**
 * Returns the element.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the element
 */
static void get_array_element(void* p0, void* p1, void* p2) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        int* i = (int*) p1;
        void** ia = a->internal_array;

        if (ia != 0) {
                
            if (*i != INVALID_VALUE) {
                
                p2 = ia[*i];
            
            } else {
        
                log((void*) &WARNING_LOG_LEVEL, "Could not get array element. The index is invalid.");
            }

        } else {
    
            log((void*) &ERROR_LOG_LEVEL, "Could not get array element. The internal array is null.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get array element. The array is null.");
    }
}

/* INTERNAL_ARRAY_HANDLER_SOURCE */
#endif

