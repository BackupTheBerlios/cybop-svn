/*
 * $RCSfile: array_handler.c,v $
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
 * @version $Revision: 1.15 $ $Date: 2004-03-04 14:32:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Array.
//

/**
 * Initializes the array.
 *
 * @param p0 the array
 * @param p1 the type
 */
void initialize_array(void* p0, void* p1) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        int* t = (int*) p1;

        if (t != (void*) 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Initialize array.");

            // An array CANNOT have ZERO length, so that dereferencing a pointer to
            // the first element of an array always returns a valid result.
            // There is no NULL array.
            // See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
            a->type = *t;
            a->size = 0;
            a->count = 0;

            if (*t == 0) {

                a->pointer_array = malloc(a->size);

            } else if ((*t == 1) || (*t == 2) || (*t ==3)) {

                a->internal_array = malloc(a->size);
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize array. The type is null.");
        }

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

/**
 * Returns the array type.
 *
 * @param p0 the array
 * @param p1 the array type
 */
void get_array_count(void* p0, void* p1) {

    struct array* a = (struct array*) p0;
    int* t = (int*) p1;

    if (a != (void*) 0) {

        *t = a->type;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array type. The array is null.");
    }
}

/**
 * Compares the arrays.
 *
 * Returns 1 if the arrays are equal in:
 * - size
 * - count (number of elements)
 * - elements
 *
 * Otherwise, 0 is returned.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the result
 */
void compare_arrays(void* p0, void* p1, void* p2) {

    struct array* a0 = (struct array*) p0;

    if (a0 != (void*) 0) {

        struct array* a1 = (struct array*) p1;

        if (a1 != (void*) 0) {

            // The size must be equal.
            if (a0->size == a1->size) {

                // The count must be equal.
                if (a0->count == a1->count) {

                    // The elements must be equal.
                    compare_character_arrays(a0->internal_array, a1->internal_array, (void*) &(a0->size), p2);
                }
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not compare array elements. The second array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not compare array elements. The first array is null.");
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
        int s = a->size;

        // If the array length is exceeded, create a new array with extended
        // (doubled) length so that the index matches.
        // If the initial size is zero and multiplied by two, the result is
        // still zero. Therefore, an integer summand of 1 is added here.
        while (*i >= s) {

            s = s * 2 + 1;
        }

        if (s != a->size) {

            a->size = s;
            a->internal_array = realloc(a->internal_array, s);
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
 * Adds the array element.
 *
 * @param p0 the array
 * @param p1 the element
 */
void add_array_element(void* p0, void* p1) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        int c = a->count;

        set_array_element(p0, (void*) &c, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not add array element. The array is null.");
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
 * Gets the array element.
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

/**
 * Gets the array element index.
 *
 * The first occurence of the element will be considered.
 *
 * @param p0 the array
 * @param p1 the element
 * @param p2 the type
 * @param p3 the index
 */
void get_array_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    struct array* a = (struct array*) p0;

    if (a != (void*) 0) {

        int* t = (int*) p2;

        if (*t == POINTER) {

            get_internal_array_pointer_element_index(a->internal_array, p1, (void*) &(a->count), p3);

        } else if (*t == INTEGER) {

            get_internal_array_integer_element_index(a->internal_array, p1, (void*) &(a->count), p3);

        } else if (*t == DOUBLE) {

            get_internal_array_double_element_index(a->internal_array, p1, (void*) &(a->count), p3);

        } else if (*t == CHARACTER) {

            get_internal_array_character_element_index(a->internal_array, p1, (void*) &(a->count), p3);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element index. The array is null.");
    }
}

/* ARRAY_HANDLER_SOURCE */
#endif
