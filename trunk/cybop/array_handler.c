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

#include "array.c"
#include "dynamics_handler.c"
#include "log_handler.c"
#include "statics.c"

/**
 * This is the array handler.
 *
 * Array elements are accessed over their index.
 *
 * @version $Revision: 1.15 $ $Date: 2003-10-13 08:36:34 $ $Author: christian $
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
        a->size = 0;
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
        a->size = -1;
        
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
        
        // If the array length is exceeded, create a new array with extended length
        // so that the index matches.
        // If the initial size is zero and multiplied by two, the result is still zero.
        // Therefore, an integer summand of 1 is added here.
        while (*i >= size) {

            size = 2 * size + 1;
        }

        if (size != a->size) {
                
            a->size = size;
            extend_internal_array(a->internal_array, size);
        }
        
        set_internal_array_element(a->internal_array, p1, p2);

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

        remove_internal_array_element(a->internal_array, p1, a->size);
        //?? size als pointer?

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The array is null.");
    }
}

/**
 * Returns the array element.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the element
 */
static void get_array_element(void* p0, void* p1, void* p2) {

    struct array* a = (struct array*) p0;

    if (a != 0) {

        get_internal_array_element(a->internal_array, p1, p2);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get array element. The array is null.");
    }
}

/* ARRAY_HANDLER_SOURCE */
#endif

