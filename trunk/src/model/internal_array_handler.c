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

#include "../logger/log_handler.c"

/**
 * This is the internal array handler.
 *
 * An internal array is one provided by the programming language.
 * Its syntax mostly looks like: type[size].
 * Internal array elements are accessed over an index.
 *
 * @version $Revision: 1.6 $ $Date: 2004-01-05 16:38:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The invalid index. */
static const int INVALID_INDEX = -1;

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
/*??
void** extend_internal_array(void** p0, void* p1, void* p2) {

    void** a = (void*) 0;
    
    if (p0 != (void*) 0) {

        int* old_size = (int*) p1;
        int* new_size = (int*) p2;
        // Create new internal array.
        a = malloc(*new_size);

        if (a != (void*) 0) {
                
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

            log_message((void*) &ERROR_LOG_LEVEL, "Could not extend internal array. The new internal array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not extend internal array. The old internal array is null.");
    }
    
    return a;
}
*/

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
void set_internal_array_element(void** p0, void* p1, void* p2) {

    if (p0 != (void*) 0) {

        int* i = (int*) p1;

        if (*i != INVALID_INDEX) {
                
            // Set element.
            p0[*i] = p2;
        
        } else {
    
            log_message((void*) &WARNING_LOG_LEVEL, "Could not set internal array element. The index is invalid.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set internal array element. The internal array is null.");
    }
}

/**
 * Removes the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @param p2 the count
 */
void remove_internal_array_element(void** p0, void* p1, void* p2) {

    if (p0 != (void*) 0) {

        int* index = (int*) p1;

        if (*index != INVALID_INDEX) {

            // Initialize loop variable with index.
            // Do not use the index itself as it was handed over as constant parameter!
            int i = *index;
            int* count = (int*) p2;
            
            // Starting from the given index, move all remaining elements one
            // place towards the beginning of the elements.
            while ((i + 1) < *count) {

                p0[i] = p0[i + 1];

                i++;
            }

            // Set former last element to 0.
            p0[i] = (void*) 0;
        
        } else {
    
            log_message((void*) &WARNING_LOG_LEVEL, "Could not remove internal array element. The index is invalid.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove internal array element. The internal array is null.");
    }
}

/**
 * Returns the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @return the element
 */
void* get_internal_array_element(void** p0, void* p1) {

    void* e = (void*) 0;
    
    if (p0 != (void*) 0) {

        int* i = (int*) p1;

        if (*i != INVALID_INDEX) {
            
            // Get element.
            e = p0[*i];
        
        } else {
    
            log_message((void*) &WARNING_LOG_LEVEL, "Could not get internal array element. The index is invalid.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get internal array element. The internal array is null.");
    }
    
    return e;
}

/* INTERNAL_ARRAY_HANDLER_SOURCE */
#endif

