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
 * Array elements are accessed over their index.
 *
 * @version $Revision: 1.13 $ $Date: 2003-10-12 12:33:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Array.
//

/**
 * Initializes the array.
 *
 * @param p0 the array
 */
static void initialize_array(void* p0) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        log((void*) &INFO_LOG_LEVEL, "Initialize array.");

        // An array CANNOT have ZERO length, so that dereferencing a pointer to
        // the first element of an array always returns a valid result.
        // There is no NULL array.
        // See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
        a->size = sizeof(void*);
        a->internal_array = malloc(a->size);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not initialize array. The array is null.");
    }
}

/**
 * Finalizes the array.
 *
 * @param p0 the array
 */
static void finalize_array(void* p0) {

    struct array* a = (struct array*) p0;
    
    if (a != 0) {

        log((void*) &INFO_LOG_LEVEL, "Finalize array.");

        free(a->internal_array);
        a->size = 0;
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize array. The array is null.");
    }
}

/**
 * Returns the array size.
 *
 * @param p0 the array
 * @param p1 the array size
 */
static void get_array_size(void* p0, void* p1) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        int* s = (int*) p1;
        *s = a->size;

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get array size. The array is null.");
    }
}

/**
 * Extends the array by doubling its length.
 *
 * All elements are copied from the old to the new array.
 * The rest of the new array is just left empty as it is; no zeros are set.
 *
 * @param p0 the array
 */
static void extend_array(void* p0) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        // Get internal array and its size.
        int old_size = a->size;
        void** old_array = a->internal_array;
    
        if ((old_size != 0) && (old_array != 0)) {
    
            // Create new array (with extended size) and set its size.
            // If the initial size is zero and multiplied by two, the result is still zero.
            // Therefore, an integer summand of 1 is added here.
            int new_size = old_size * 2 + 1;
            void** new_array = malloc(new_size);
    
            if ((new_size != 0) && (new_array != 0)) {
                    
                // Copy all elements of the old into the new array.
                int i = 0;
    
                while (i < old_size) {
    
                    new_array[i] = old_array[i];
    
                    i++;
                }
    
                // Free old array and reset its size.
                free(old_array);
                old_size = 0;
                
                // Set internal array and its size.
                a->size = new_size;
                a->internal_array = new_array;
    
            } else {
    
                log((void*) &ERROR_LOG_LEVEL, "Could not extend array. The new internal array is null.");
            }
    
        } else {
    
            log((void*) &ERROR_LOG_LEVEL, "Could not extend array. The old internal array is null.");
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
static void set_array_element(void* p0, void* p1, void* p2) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        int* i = (int*) p1;
        int size = a->size;
        void** ia = a->internal_array;

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
                
            puts("TEST 2");
        
            // Set element.
            ia[*i] = p2;
        
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
static void remove_array_element(void* p0, void* p1) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        int* i = (int*) p1;
        int size = a->size;
        void** ia = a->internal_array;
        
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

        if (*i != INVALID_VALUE) {
            
            p2 = ia[*i];
        
        } else {
    
            log((void*) &WARNING_LOG_LEVEL, "Could not get array element. The index is invalid.");
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get array element. The array is null.");
    }
}

/* ARRAY_HANDLER_SOURCE */
#endif

