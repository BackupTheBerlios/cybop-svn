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
 *
 * This file handles an array.
 *
 * An array represents an allocated area in the computer's memory,
 * that can contain a number of abstract elements.
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * The C programming language provides a number of primitive data types whose
 * size is defined so that an array can be created of them. The types are:
 * - pointer
 * - integer
 * - character
 * - double
 *
 * To work with an array, this handler needs additional information, in concrete:
 * - the array size (allocated memory)
 * - the array type (of data)
 *
 * There is no extra "count" value. Arrays are always as big as the number of
 * elements they contain.
 *
 * The sizeof operation can only be used for real arrays, expressed with [].
 * Since CYBOI allocates arrays dynamically and stores them as *,
 * the array size needs to be given extra here because sizeof will not work.
 * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
 *
 * @version $Revision: 1.31 $ $Date: 2004-04-22 08:54:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_HANDLER_SOURCE
#define ARRAY_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"
#include "../model/character_array_handler.c"
#include "../model/double_array_handler.c"
#include "../model/integer_array_handler.c"
#include "../model/pointer_array_handler.c"

//
// Array.
//

/**
 * Creates the array.
 *
 * @param p0 the array
 * @param p1 the size
 */
void create_array(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Create array.");

            // A minimal space in memory is always allocated,
            // even if the requested size is zero.
            // In other words, a handle to the new instance is always returned.
            *a = (void*) malloc(*s);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create array. The array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create array. The size is null.");
    }
}

/**
 * Destroys the array.
 *
 * @param p0 the array
 * @param p1 the size
 */
void destroy_array(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy array.");

            //?? TODO: Destroy all array elements in a loop??
            //?? Which is the same as Garbage Collection!
            //?? SEE: signal_memory_handler

            free(*a);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not destroy array. The array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not destroy array. The size is null.");
    }
}

/**
 * Resizes the array with the given size.
 *
 * @param p0 the array
 * @param p1 the size
 */
void resize_array(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;
        fprintf(stderr, "resize s: %d\n", *s);

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;
            fprintf(stderr, "resize a1: %d\n", *a);

            // Create a new array with extended size.
            *a = (void*) realloc(*a, *s);
            fprintf(stderr, "resize a2: %d\n", *a);

        } else {

            fputs("ERROR array\n", stderr);
            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not resize array. The array is null.");
        }

    } else {

        fputs("ERROR size\n", stderr);
        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not resize array. The size is null.");
    }
}

//
// Array element.
//

/**
 * Compares the array elements.
 *
 * Returns 1 if the array elements are equal.
 * The given result remains unchanged if the array elements are unequal.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the result
 */
void compare_array_elements(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    if (p2 != NULL_POINTER) {

        int* t = (int*) p2;

        if (*t == POINTER_ARRAY) {

            compare_pointer_array_elements(p0, p1, p3, p4);

        } else if (*t == INTEGER_ARRAY) {

            compare_integer_array_elements(p0, p1, p3, p4);

        } else if (*t == DOUBLE_ARRAY) {

            compare_double_array_elements(p0, p1, p3, p4);

        } else if (*t == CHARACTER_ARRAY) {

            compare_character_array_elements(p0, p1, p3, p4);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare array elements. The type is null.");
    }
}

/**
 * Sets the array elements.
 *
 * @param p0 the destination array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the source array
 * @param p4 the count
 */
void set_array_elements(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            set_pointer_array_elements(p0, p2, p3, p4);

        } else if (*t == INTEGER_ARRAY) {

            set_integer_array_elements(p0, p2, p3, p4);

        } else if (*t == DOUBLE_ARRAY) {

            set_double_array_elements(p0, p2, p3, p4);

        } else if (*t == CHARACTER_ARRAY) {

            set_character_array_elements(p0, p2, p3, p4);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set array elements. The type is null.");
    }
}

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the element
 */
void set_array_element(void* p0, const void* p1, const void* p2, const void* p3) {

    // The elements count.
    int c = 1;

    // The element needs to be handed over as array.
    // Therefore, it has to be transformed into a pointer.
    // Example:
    // - array: char* handed over as char**
    // - element: char handed over as char*
    // - the element of type char* gets transformed to type char** with &element
    set_array_elements(p0, p1, p2, (void*) &p3, (void*) &c);
}

/**
 * Removes the array elements.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the index
 * @param p4 the count
 */
void remove_array_elements(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            remove_pointer_array_elements(p0, p2, p3, p4);

        } else if (*t == INTEGER_ARRAY) {

            remove_integer_array_elements(p0, p2, p3, p4);

        } else if (*t == DOUBLE_ARRAY) {

            remove_double_array_elements(p0, p2, p3, p4);

        } else if (*t == CHARACTER_ARRAY) {

            remove_character_array_elements(p0, p2, p3, p4);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove array elements. The type is null.");
    }
}

/**
 * Removes the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the index
 */
void remove_array_element(void* p0, const void* p1, const void* p2, const void* p3) {

    // The elements count.
    int c = 1;

    // The element needs to be handed over as array.
    // Therefore, it has to be transformed into a pointer.
    // Example:
    // - array: char* handed over as char**
    // - element: char handed over as char*
    // - the element of type char* gets transformed to type char** with &element
    remove_array_elements(p0, p1, p2, (void*) &p3, (void*) &c);
}

/**
 * Gets the array elements.
 *
 * @param p0 the source array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the destination array
 * @param p4 the count
 */
void get_array_elements(const void* p0, const void* p1, const void* p2, void* p3, const void* p4) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            get_pointer_array_elements(p0, p2, p3, p4);

        } else if (*t == INTEGER_ARRAY) {

            get_integer_array_elements(p0, p2, p3, p4);

        } else if (*t == DOUBLE_ARRAY) {

            get_double_array_elements(p0, p2, p3, p4);

        } else if (*t == CHARACTER_ARRAY) {

            get_character_array_elements(p0, p2, p3, p4);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get array elements. The type is null.");
    }
}

/**
 * Gets the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the element
 */
void get_array_element(const void* p0, const void* p1, const void* p2, void* p3) {

    // The elements count.
    int c = 1;

    // The element needs to be handed over as array.
    // Therefore, it has to be transformed into a pointer.
    // Example:
    // - array: char* handed over as char**
    // - element: char handed over as char*
    // - the element of type char* gets transformed to type char** with &element
    get_array_elements(p0, p1, p2, (void*) &p3, (void*) &c);
}

/**
 * Gets the array elements index.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the comparison array
 * @param p4 the count
 * @param p5 the index
 */
void get_array_elements_index(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4, void* p5) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            get_pointer_array_elements_index(p0, p2, p3, p4, p5);

        } else if (*t == INTEGER_ARRAY) {

            get_integer_array_elements_index(p0, p2, p3, p4, p5);

        } else if (*t == DOUBLE_ARRAY) {

            get_double_array_elements_index(p0, p2, p3, p4, p5);

        } else if (*t == CHARACTER_ARRAY) {

            get_character_array_elements_index(p0, p2, p3, p4, p5);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get array elements index. The type is null.");
    }
}

/**
 * Gets the array element index.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the element
 * @param p4 the index
 */
void get_array_element_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    // The elements count.
    int c = 1;

    // The element needs to be handed over as array.
    // Therefore, it has to be transformed into a pointer.
    // Example:
    // - array: char* handed over as char**
    // - element: char handed over as char*
    // - the element of type char* gets transformed to type char** with &element
    get_array_elements_index(p0, p1, p2, (void*) &p3, (void*) &c, p4);
}

/* ARRAY_HANDLER_SOURCE */
#endif
