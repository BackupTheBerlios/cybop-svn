/*
 * $RCSfile: array_handler.c,v $
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

#ifndef ARRAY_HANDLER_SOURCE
#define ARRAY_HANDLER_SOURCE

#include "dynamics_handler.c"
#include "log_handler.c"
#include "statics.c"

/**
 * This is the array handler.
 *
 * An array represents an allocated area in the computer's memory
 * that can contain a number of abstract elements.
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * Array elements are accessed over their index.
 *
 * A double pointer ** is used to express an array of pointers!
 * Example:
 * int** a = 0; // Array of integer pointers
 * void** a = 0; // Array of void pointers
 *
 * @version $Revision: 1.12 $ $Date: 2003-10-09 10:54:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Array.
//

/**
 * Extends the array by doubling its length.
 *
 * All elements are copied from the old to the new array.
 *
 * @param p0 the array
 */
static void extend_array(void** p0) {

    void** old_array = p0;

    if (old_array != 0) {

        int old_length = sizeof(old_array);
        int new_length = old_length * 2 + 1;
        void** new_array = (void**) malloc(new_length);

        if (new_array != 0) {
                
            // Copy all elements of the old into the new array.
            int i = 0;

            while (i < old_length) {

                new_array[i] = old_array[i];

                i++;
            }

            // Free old array.
            free(old_array);
            
            // Direct pointer to new array.
            p0 = new_array;

        } else {

            log((void*) &ERROR_LOG_LEVEL, "Could not extend array. The new array is null.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not extend array. The array is null.");
    }
}

//
// Array element.
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
        int size = sizeof(p0);
        
        // If the array length is exceeded, a new array with extended length
        // is created and delivered back.
        if (*i >= size) {

            extend_array(p0);
        }

        if (*i != INVALID_VALUE) {
                
            // Set element.
            p0[*i] = p2;
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not set array element. The index is invalid.");
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
static void remove_array_element(void** p0, void* p1) {

    if (p0 != 0) {

        int* i = (int*) p1;
        
        if (*i != INVALID_VALUE) {

            // Starting from the given index, move all remaining elements one
            // place towards the beginning of the elements.
            int size = sizeof(p0);
            
            while ((*i + 1) < size) {

                p0[*i] = p0[*i + 1];

                (*i)++;
            }

            // Set former last element to 0.
            p0[*i] = 0;
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not remove array element. The index is invalid.");
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
static void get_array_element(void** p0, void* p1, void* p2) {

    if (p0 != 0) {

        int* i = (int*) p1;

        if (*i != INVALID_VALUE) {
            
            p2 = p0[*i];
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not get array element. The index is invalid.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get array element. The array is null.");
    }
}

/* ARRAY_HANDLER_SOURCE */
#endif

