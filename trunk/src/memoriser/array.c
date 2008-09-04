/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: array.c,v $ $Revision: 1.21 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SOURCE
#define ARRAY_SOURCE

#include "../constant/abstraction/memory/array_memory_abstraction.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../memoriser/array/character_array.c"
#include "../memoriser/array/double_array.c"
#include "../memoriser/array/integer_array.c"
#include "../memoriser/array/pointer_array.c"
#include "../memoriser/array/unsigned_long_array.c"
#include "../memoriser/array/wide_character_array.c"

/**
 * Allocates the array.
 *
 * The sizeof operation can only be used for real arrays, expressed with [].
 * Since CYBOI allocates arrays dynamically and stores them as *,
 * the array size needs to be given extra here because sizeof will not work.
 * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate array.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            allocate_pointer_array(p0, p1);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            allocate_integer_array(p0, p1);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            allocate_unsigned_long_array(p0, p1);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            allocate_double_array(p0, p1);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            allocate_character_array(p0, p1);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            allocate_wide_character_array(p0, p1);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/**
 * Deallocates the array.
 *
 * The sizeof operation can only be used for real arrays, expressed with [].
 * Since CYBOI allocates arrays dynamically and stores them as *,
 * the array size needs to be given extra here because sizeof will not work.
 * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 * @param p2 the type
 */
void deallocate_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate array.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            deallocate_pointer_array(p0, p1);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            deallocate_integer_array(p0, p1);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            deallocate_unsigned_long_array(p0, p1);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            deallocate_double_array(p0, p1);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            deallocate_character_array(p0, p1);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            deallocate_wide_character_array(p0, p1);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/**
 * Reallocates the array.
 *
 * The sizeof operation can only be used for real arrays, expressed with [].
 * Since CYBOI allocates arrays dynamically and stores them as *,
 * the array size needs to be given extra here because sizeof will not work.
 * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the count
 * @param p2 the size
 * @param p3 the type
 */
void reallocate_array(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reallocate array.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            reallocate_pointer_array(p0, p1, p2);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            reallocate_integer_array(p0, p1, p2);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            reallocate_unsigned_long_array(p0, p1, p2);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            reallocate_double_array(p0, p1, p2);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            reallocate_character_array(p0, p1, p2);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            reallocate_wide_character_array(p0, p1, p2);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array elements.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            compare_pointer_array_elements(p0, p1, p2, p3);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            compare_integer_array_elements(p0, p1, p2, p3);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            compare_unsigned_long_array_elements(p0, p1, p2, p3);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            compare_double_array_elements(p0, p1, p2, p3);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            compare_character_array_elements(p0, p1, p2, p3);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            compare_wide_character_array_elements(p0, p1, p2, p3);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p3;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* fc = (int*) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare arrays.");

            if (*fc == *sc) {

                compare_array_elements(p0, p2, p3, p4, p5);
            }

        } else {

//??            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

//??        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get array elements.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            get_pointer_array_elements(p0, p1, p2);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            get_integer_array_elements(p0, p1, p2);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            get_unsigned_long_array_elements(p0, p1, p2);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            get_double_array_elements(p0, p1, p2);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            get_character_array_elements(p0, p1, p2);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            get_wide_character_array_elements(p0, p1, p2);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set array elements.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            set_pointer_array_elements(p0, p1, p2, p3);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            set_integer_array_elements(p0, p1, p2, p3);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            set_unsigned_long_array_elements(p0, p1, p2, p3);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            set_double_array_elements(p0, p1, p2, p3);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            set_character_array_elements(p0, p1, p2, p3);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            set_wide_character_array_elements(p0, p1, p2, p3);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Remove array elements.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            remove_pointer_array_elements(p0, p1, p2, p3);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            remove_integer_array_elements(p0, p1, p2, p3);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            remove_unsigned_long_array_elements(p0, p1, p2, p3);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            remove_double_array_elements(p0, p1, p2, p3);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            remove_character_array_elements(p0, p1, p2, p3);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            remove_wide_character_array_elements(p0, p1, p2, p3);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p5;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get array elements index.");

        if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            get_pointer_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            get_integer_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            get_unsigned_long_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            get_double_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            get_character_array_elements_index(p0, p1, p2, p3, p4);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            get_wide_character_array_elements_index(p0, p1, p2, p3, p4);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/* ARRAY_SOURCE */
#endif
