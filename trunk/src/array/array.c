/*
 * $RCSfile: array.c,v $
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
 * To work with an array, the procedures need additional information, in concrete:
 * - the array type
 *   (type of the contained elements)
 * - the array maximum count
 *   (maximum possible number of elements that match into the array)
 * - the size
 *   (actual allocated memory; calculated from the maximum count by
 *   multiplying it with the size of the primitive data type)
 *
 * The sizeof operation can only be used for real arrays, expressed with [].
 * Since CYBOI allocates arrays dynamically and stores them as *,
 * the array size needs to be given extra here because sizeof will not work.
 * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
 *
 * @version $Revision: 1.13 $ $Date: 2004-10-29 08:31:22 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SOURCE
#define ARRAY_SOURCE

#include "../array/character_array.c"
#include "../array/double_array.c"
#include "../array/integer_array.c"
#include "../array/pointer_array.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

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
 * @param p4 the result (1 if equal; 0 otherwise)
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

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sets the array elements.
 *
 * @param p0 the destination array
 * @param p1 the type
 * @param p2 the destination array index
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

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the array index
 * @param p3 the element
 */
void set_array_element(void* p0, const void* p1, const void* p2, const void* p3) {

    // The elements count.
    int c = 1;

    // The element p3 needs to be handed over as array to set_array_elements.
    // Therefore, it has to be transformed into a pointer.
    // Example 1:
    // - array p0: char* handed over as char**
    // - element p3: single char handed over as char*
    // - the element of type char* gets transformed to type char** with &p3
    // Example 2:
    // - array p0: char** handed over as char***
    // - element p3: string char* handed over as char**
    // - the element of type char** gets transformed to type char*** with &p3
    set_array_elements(p0, p1, p2, (void*) &p3, (void*) &c);
}

/**
 * Removes the array elements.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the array index
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

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Removes the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the array index
 */
void remove_array_element(void* p0, const void* p1, const void* p2, const void* p3) {

    // The elements count.
    int c = 1;

    remove_array_elements(p0, p1, p2, p3, (void*) &c);
}

/**
 * Gets the array elements.
 *
 * @param p0 the source array
 * @param p1 the type
 * @param p2 the source array index
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

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the array element.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the array index
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
 * @param p2 the array maximum count
 * @param p3 the comparison array
 * @param p4 the comparison array count
 * @param p5 the index within array
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

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the array element index.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the size
 * @param p3 the element
 * @param p4 the index within array
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

//
// Array.
//

/**
 * Creates the array.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the maximum count
 */
void create_array(void* p0, const void* p1, const void* p2) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            create_pointer_array(p0, p2);

        } else if (*t == INTEGER_ARRAY) {

            create_integer_array(p0, p2);

        } else if (*t == DOUBLE_ARRAY) {

            create_double_array(p0, p2);

        } else if (*t == CHARACTER_ARRAY) {

            create_character_array(p0, p2);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Destroys the array.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the maximum count
 */
void destroy_array(void* p0, const void* p1, const void* p2) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            destroy_pointer_array(p0, p2);

        } else if (*t == INTEGER_ARRAY) {

            destroy_integer_array(p0, p2);

        } else if (*t == DOUBLE_ARRAY) {

            destroy_double_array(p0, p2);

        } else if (*t == CHARACTER_ARRAY) {

            destroy_character_array(p0, p2);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Resizes the array.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the maximum count
 */
void resize_array(void* p0, const void* p1, const void* p2) {

    if (p1 != NULL_POINTER) {

        int* t = (int*) p1;

        if (*t == POINTER_ARRAY) {

            resize_pointer_array(p0, p2);

        } else if (*t == INTEGER_ARRAY) {

            resize_integer_array(p0, p2);

        } else if (*t == DOUBLE_ARRAY) {

            resize_double_array(p0, p2);

        } else if (*t == CHARACTER_ARRAY) {

            resize_character_array(p0, p2);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE, (void*) &COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Compares the arrays.
 *
 * @param p0 the first array
 * @param p1 the first array count
 * @param p2 the second array
 * @param p3 the second array count
 * @param p4 the result (1 if equal; 0 otherwise)
 * @param p5 the type
 */
void compare_arrays(const void* p0, const void* p1, const void* p2, const void* p3,
    void* p4, const void* p5) {


    if (p3 != NULL_POINTER) {

        int* sc = (int*) p3;

        if (p1 != NULL_POINTER) {

            int* fc = (int*) p1;

            if (*fc == *sc) {

                compare_array_elements(p0, p2, p5, p3, p4);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }

    	
}

/* ARRAY_SOURCE */
#endif
