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
 * @version $Revision: 1.28 $ $Date: 2004-04-21 11:08:42 $ $Author: christian $
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
// Array type constants.
//

//?? Possibly remove pointer array, if a pointer is really identical to an integer.

/** The pointer array constant. */
static const int POINTER_ARRAY = 0;

/** The integer array constant. */
static const int INTEGER_ARRAY = 1;

//?? Possibly remove character array, if a character primitive is really
//?? identical to an integer primitive. Are they?

/** The character array constant. */
static const int CHARACTER_ARRAY = 3;

//?? Possibly remove double array, if a double primitive can be replaced by
//?? a compound structure like "fraction". How would this effect performance
//?? when ALU will not work with doubles but they rather get transformed into
//?? integers first?

/** The double array constant. */
static const int DOUBLE_ARRAY = 2;

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

            // An array CANNOT have ZERO length, so that dereferencing a pointer to
            // the first element of an array always returns a valid result.
            // There is no NULL array.
            // See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
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
 * Compares the arrays.
 *
 * Returns 1 if the arrays are equal.
 * The given result remains unchanged if the arrays are unequal.
 *
 * @param p0 the first array
 * @param p1 the first size
 * @param p2 the second array
 * @param p3 the second size
 * @param p4 the type
 * @param p5 the result
 */
void compare_arrays(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4, void* p5) {

    if (p4 != NULL_POINTER) {

        int* t = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* s2 = (int*) p3;

            if (p1 != NULL_POINTER) {

                int* s1 = (int*) p1;

                // The size must be equal.
                if (*s1 == *s2) {

                    // The elements must be equal.
                    if (*t == POINTER_ARRAY) {

                        compare_pointer_arrays(p0, p2, p1, p5);

                    } else if (*t == INTEGER_ARRAY) {

                        compare_integer_arrays(p0, p2, p1, p5);

                    } else if (*t == DOUBLE_ARRAY) {

                        compare_double_arrays(p0, p2, p1, p5);

                    } else if (*t == CHARACTER_ARRAY) {

                        compare_character_arrays(p0, p2, p1, p5);
                    }
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare arrays. The first size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare arrays. The second size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare arrays. The type is null.");
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

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            // Create a new array with extended size.
            *a = (void*) realloc(*a, *s);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not resize array. The array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not resize array. The size is null.");
    }
}

//
// Array element.
//

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the index
 * @param p3 the element
 */
void set_array_element(void* p0, const void* p1, const void* p2, const void* p3) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            set_pointer_array_element(p0, p2, p3);

        } else if (*t == INTEGER_ARRAY) {

            set_integer_array_element(p0, p2, p3);

        } else if (*t == DOUBLE_ARRAY) {

            set_double_array_element(p0, p2, p3);

        } else if (*t == CHARACTER_ARRAY) {

            set_character_array_element(p0, p2, p3);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set array element. The type is null.");
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

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            remove_pointer_array_element(p0, p2, p3);

        } else if (*t == INTEGER_ARRAY) {

            remove_integer_array_element(p0, p2, p3);

        } else if (*t == DOUBLE_ARRAY) {

            remove_double_array_element(p0, p2, p3);

        } else if (*t == CHARACTER_ARRAY) {

            remove_character_array_element(p0, p2, p3);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove array element. The type is null.");
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

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            get_pointer_array_element(p0, p2, p3);

        } else if (*t == INTEGER_ARRAY) {

            get_integer_array_element(p0, p2, p3);

        } else if (*t == DOUBLE_ARRAY) {

            get_double_array_element(p0, p2, p3);

        } else if (*t == CHARACTER_ARRAY) {

            get_character_array_element(p0, p2, p3);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get array element. The type is null.");
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

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            get_pointer_array_element_index(p0, p2, p3, p4);

        } else if (*t == INTEGER_ARRAY) {

            get_integer_array_element_index(p0, p2, p3, p4);

        } else if (*t == DOUBLE_ARRAY) {

            get_double_array_element_index(p0, p2, p3, p4);

        } else if (*t == CHARACTER_ARRAY) {

            get_character_array_element_index(p0, p2, p3, p4);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get array element index. The type is null.");
    }
}

/* ARRAY_HANDLER_SOURCE */
#endif
