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

#include <stdlib.h>
#include "../logger/log_handler.c"
#include "../model/array.c"
#include "../model/internal_array_handler.c"

/**
 * This is the array handler.
 *
 * Array elements are accessed over their index.
 *
 * @version $Revision: 1.8 $ $Date: 2004-02-28 19:43:30 $ $Author: christian $
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
void initialize_array(void* p0) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize array.");

        // An array CANNOT have ZERO length, so that dereferencing a pointer to
        // the first element of an array always returns a valid result.
        // There is no NULL array.
        // See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
        a->size = 0;
        a->count = 0;
        a->internal_array = malloc(a->size);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize array. The array is null.");
    }
}

/**
 * Finalizes the array.
 *
 * @param p0 the array
 */
void finalize_array(void* p0) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize array.");

        free(a->internal_array);
        a->count = -1;
        a->size = -1;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize array. The array is null.");
    }
}

/**
 * Returns the array size.
 *
 * @param p0 the array
 * @param p1 the array size
 */
void get_array_size(void* p0, void* p1) {

    struct array* a = (struct array*) p0;
    int* s = (int*) p1;

    if (a != (void*) 0) {

        *s = a->size;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array size. The array is null.");
    }
}

/**
 * Returns the array count.
 *
 * @param p0 the array
 * @param p1 the array count
 */
void get_array_count(void* p0, void* p1) {

    struct array* a = (struct array*) p0;
    int* c = (int*) p1;

    if (a != (void*) 0) {

        *c = a->count;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array count. The array is null.");
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
void set_array_element(void* p0, void* p1, void* p2) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        int* i = (int*) p1;
        int size = a->size;
        
        // If the array length is exceeded, create a new array with extended
        // (doubled) length so that the index matches.
        // If the initial size is zero and multiplied by two, the result is
        // still zero. Therefore, an integer summand of 1 is added here.
        while (*i >= size) {

            size = 2 * size + 1;
        }

        if (size != a->size) {
                
            a->size = size;
            a->internal_array = realloc(a->internal_array, size);
            //?? Our function "extend_internal_array" does not work somehow :-(
            //?? Anybody can help? Using "realloc", for now; see above.
            //?? a->internal_array = extend_internal_array(a->internal_array, (void*) &(a->size), (void*) &size);
        }

        set_internal_array_element(a->internal_array, p1, p2);
        (a->count)++;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set array element. The array is null.");
    }
}

/**
 * Removes the array element.
 *
 * @param p0 the array
 * @param p1 the index
 */
void remove_array_element(void* p0, void* p1) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        remove_internal_array_element(a->internal_array, p1, (void*) &(a->count));
        (a->count)--;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The array is null.");
    }
}

/**
 * Returns the array element.
 *
 * @param p0 the array
 * @param p1 the index
 * @return the element
 */
void* get_array_element(void* p0, void* p1) {

    void* e = (void*) 0;
    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        e = get_internal_array_element(a->internal_array, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element. The array is null.");
    }
    
    return e;
}

/* ARRAY_HANDLER_SOURCE */
#endif

