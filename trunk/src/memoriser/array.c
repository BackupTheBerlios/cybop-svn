/*
 * $RCSfile: array.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.14 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SOURCE
#define ARRAY_SOURCE

#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array/character_array.c"
#include "../memoriser/array/double_array.c"
#include "../memoriser/array/integer_array.c"
#include "../memoriser/array/pointer_array.c"
#include "../memoriser/array/unsigned_long_array.c"
#include "../memoriser/array/wide_character_array.c"

/**
 * Allocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* t = (int*) p2;

        log_message_debug("Allocate array.");

        if (*t == *POINTER_ARRAY) {

            allocate_pointer_array(p0, p1);

        } else if (*t == *INTEGER_ARRAY) {

            allocate_integer_array(p0, p1);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            allocate_unsigned_long_array(p0, p1);

        } else if (*t == *DOUBLE_ARRAY) {

            allocate_double_array(p0, p1);

        } else if (*t == *CHARACTER_ARRAY) {

            allocate_character_array(p0, p1);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            allocate_wide_character_array(p0, p1);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Deallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 * @param p2 the type
 */
void deallocate_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* t = (int*) p2;

        log_message_debug("Deallocate array.");

        if (*t == *POINTER_ARRAY) {

            deallocate_pointer_array(p0, p1);

        } else if (*t == *INTEGER_ARRAY) {

            deallocate_integer_array(p0, p1);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            deallocate_unsigned_long_array(p0, p1);

        } else if (*t == *DOUBLE_ARRAY) {

            deallocate_double_array(p0, p1);

        } else if (*t == *CHARACTER_ARRAY) {

            deallocate_character_array(p0, p1);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            deallocate_wide_character_array(p0, p1);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Reallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the count
 * @param p2 the size
 * @param p3 the type
 */
void reallocate_array(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* t = (int*) p3;

        log_message_debug("Reallocate array.");

        if (*t == *POINTER_ARRAY) {

            reallocate_pointer_array(p0, p1, p2);

        } else if (*t == *INTEGER_ARRAY) {

            reallocate_integer_array(p0, p1, p2);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            reallocate_unsigned_long_array(p0, p1, p2);

        } else if (*t == *DOUBLE_ARRAY) {

            reallocate_double_array(p0, p1, p2);

        } else if (*t == *CHARACTER_ARRAY) {

            reallocate_character_array(p0, p1, p2);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            reallocate_wide_character_array(p0, p1, p2);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Compares the array elements.
 *
 * Returns 1 if the array elements are equal;
 * leaves the given result parameter unchanged, otherwise.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the count
 * @param p3 the result (Hand over as reference!)
 * @param p4 the type
 */
void compare_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* t = (int*) p4;

        log_message_debug("Compare array elements.");

        if (*t == *POINTER_ARRAY) {

            compare_pointer_array_elements(p0, p1, p2, p3);

        } else if (*t == *INTEGER_ARRAY) {

            compare_integer_array_elements(p0, p1, p2, p3);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            compare_unsigned_long_array_elements(p0, p1, p2, p3);

        } else if (*t == *DOUBLE_ARRAY) {

            compare_double_array_elements(p0, p1, p2, p3);

        } else if (*t == *CHARACTER_ARRAY) {

            compare_character_array_elements(p0, p1, p2, p3);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            compare_wide_character_array_elements(p0, p1, p2, p3);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Compares the arrays.
 *
 * This procedure compares only the element counts of both arrays.
 * The actual elements comparison happens in compare_array_elements.
 *
 * @param p0 the first array
 * @param p1 the first array count
 * @param p2 the second array
 * @param p3 the second array count
 * @param p4 the result (Hand over as reference!)
 * @param p5 the type
 */
void compare_arrays(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER) {

        int* sc = (int*) p3;

        if (p1 != *NULL_POINTER) {

            int* fc = (int*) p1;

            log_message_debug("Compare arrays.");

            if (*fc == *sc) {

                compare_array_elements(p0, p2, p3, p4, p5);
            }

        } else {

//??            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array reference!)
 * @param p3 the type
 */
void get_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* t = (int*) p3;

        log_message_debug("Get array elements.");

        if (*t == *POINTER_ARRAY) {

            get_pointer_array_elements(p0, p1, p2);

        } else if (*t == *INTEGER_ARRAY) {

            get_integer_array_elements(p0, p1, p2);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            get_unsigned_long_array_elements(p0, p1, p2);

        } else if (*t == *DOUBLE_ARRAY) {

            get_double_array_elements(p0, p1, p2);

        } else if (*t == *CHARACTER_ARRAY) {

            get_character_array_elements(p0, p1, p2);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            get_wide_character_array_elements(p0, p1, p2);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * get the firts position of the serach array in the array.
 *
 * if found the search array then the position ist the position in the array
 * else ist the position -1
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the search array
 * @param p3 the search array count
 * @param p4 the position (Hand over as reference!)
 * @param p5 the type
 */
void get_index_in_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER) {

        int* position = (int*) p4;
        *position = -1;

        if (p3 != *NULL_POINTER) {

            int* sc = (int*) p3;

            if (p1 != *NULL_POINTER) {

                int* ac = (int*) p1;

                log_message_debug("Get index in array.");

                int array_counter = 0;
                int comp_res = 0;
                void* start_comp = *NULL_POINTER;

                while (1) {

                    if (array_counter >= *ac - *sc + 1) {

                        break;
                    }

                    get_array_elements( p0, &array_counter, &start_comp, p5 );
                    comp_res = 0;
                    compare_array_elements( start_comp, p2, p3, &comp_res, p5);

                    if ( comp_res == 1 ) {

                        //the search array is founded in array
                        *position = array_counter;

                        break;
                    }

                    array_counter = array_counter + 1;
                }

            } else {

    //??            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

    //??        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
        }
    } else {

    }
}

/**
 * Sets the array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array!)
 * @param p3 the count
 * @param p4 the type
 */
void set_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* t = (int*) p4;

        log_message_debug("Set array elements.");

        if (*t == *POINTER_ARRAY) {

            set_pointer_array_elements(p0, p1, p2, p3);

        } else if (*t == *INTEGER_ARRAY) {

            set_integer_array_elements(p0, p1, p2, p3);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            set_unsigned_long_array_elements(p0, p1, p2, p3);

        } else if (*t == *DOUBLE_ARRAY) {

            set_double_array_elements(p0, p1, p2, p3);

        } else if (*t == *CHARACTER_ARRAY) {

            set_character_array_elements(p0, p1, p2, p3);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            set_wide_character_array_elements(p0, p1, p2, p3);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Removes the array elements.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the index
 * @param p3 the count
 * @param p4 the type
 */
void remove_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* t = (int*) p4;

        log_message_debug("Remove array elements.");

        if (*t == *POINTER_ARRAY) {

            remove_pointer_array_elements(p0, p1, p2, p3);

        } else if (*t == *INTEGER_ARRAY) {

            remove_integer_array_elements(p0, p1, p2, p3);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            remove_unsigned_long_array_elements(p0, p1, p2, p3);

        } else if (*t == *DOUBLE_ARRAY) {

            remove_double_array_elements(p0, p1, p2, p3);

        } else if (*t == *CHARACTER_ARRAY) {

            remove_character_array_elements(p0, p1, p2, p3);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            remove_wide_character_array_elements(p0, p1, p2, p3);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}


/**
 * Gets the array elements index.
 *
 * Returns the index if the array elements could be found;
 * leaves the given index parameter unchanged, otherwise.
 * Only the first occurence of the elements is considered.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the elements
 * @param p3 the elements count
 * @param p4 the index (Hand over as reference!)
 * @param p5 the type
 */
void get_array_elements_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER) {

        int* t = (int*) p5;

        log_message_debug("Get array elements index.");

        if (*t == *POINTER_ARRAY) {

            get_pointer_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *INTEGER_ARRAY) {

            get_integer_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *UNSIGNED_LONG_ARRAY) {

            get_unsigned_long_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *DOUBLE_ARRAY) {

            get_double_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *CHARACTER_ARRAY) {

            get_character_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *WIDE_CHARACTER_ARRAY) {

            get_wide_character_array_elements_index(p0, p1, p2, p3, p4);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_COUNT);
    }
}

/* ARRAY_SOURCE */
#endif
