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
#include "statics.c"

/**
 * This is the internal array handler.
 *
 * Internal array elements are accessed over their index.
 *
 * @version $Revision: 1.9 $ $Date: 2003-10-22 00:45:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
 
//
// Internal array.
//

/**
 * Extends the internal array.
 *
 * @param p0 the old internal array
 * @param p1 the old size
 * @param p2 the new size
 * @return the new internal array
 */
static void** extend_internal_array(void** p0, void* p1, void* p2) {

    void** a = 0;
    
    if (p0 != 0) {

        int* old_size = (int*) p1;
        int* new_size = (int*) p2;
        // Create new internal array.
        a = malloc(*new_size);

        if (a != 0) {
                
            // Copy all elements from the old to the new array.
            // The rest of the new array is just left empty as is;
            // no zeros are set.
            int i = 0;

            while (i < *old_size) {

                a[i] = p0[i];

                i++;
            }

            // Destroy old internal array.
            free(p0);

        } else {

            log((void*) &ERROR_LOG_LEVEL, "Could not extend internal array. The new internal array is null.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not extend internal array. The old internal array is null.");
    }
    
    return a;
}

//
// Internal array element.
//

/**
 * Sets the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @param p2 the element
 */
static void set_internal_array_element(void** p0, void* p1, void* p2) {

    if (p0 != 0) {

        int* i = (int*) p1;

        if (*i != INVALID_VALUE) {
                
            // Set element.
            p0[*i] = p2;
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not set internal array element. The index is invalid.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not set internal array element. The internal array is null.");
    }
}

/**
 * Removes the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @param p2 the size
 */
static void remove_internal_array_element(void** p0, void* p1, void* p2) {

    if (p0 != 0) {

        int* i = (int*) p1;

        if (*i != INVALID_VALUE) {

            int* size = (int*) p2;
            
            // Starting from the given index, move all remaining elements one
            // place towards the beginning of the elements.
            while ((*i + 1) < *size) {

                p0[*i] = p0[*i + 1];

                (*i)++;
            }

            // Set former last element to 0.
            p0[*i] = 0;
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not remove internal array element. The index is invalid.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove internal array element. The internal array is null.");
    }
}

/**
 * Returns the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @return the element
 */
static void* get_internal_array_element(void** p0, void* p1) {

    void* e = 0;
    
    if (p0 != 0) {

        int* i = (int*) p1;

        if (*i != INVALID_VALUE) {
            
            // Get element.
            e = p0[*i];
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not get internal array element. The index is invalid.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get internal array element. The internal array is null.");
    }
    
    return e;
}

/* INTERNAL_ARRAY_HANDLER_SOURCE */
#endif

