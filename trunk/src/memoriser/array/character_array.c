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
 * @version $RCSfile: character_array.c,v $ $Revision: 1.19 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ARRAY_SOURCE
#define CHARACTER_ARRAY_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../globals/variables/primitive_type_size_variables.c"

/**
 * Allocates the character array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 */
void allocate_character_array(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** a = (void**) p0;

            log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) CREATE_CHARACTER_ARRAY_MESSAGE, (void*) CREATE_CHARACTER_ARRAY_MESSAGE_COUNT);

            // Determine the memory area to be allocated.
            // It is the product of the given size and the type size.
            size_t m = *s * *CHARACTER_PRIMITIVE_SIZE;

            // A minimal space in memory is always allocated,
            // even if the requested size is zero.
            // In other words, a handle to the new instance is always returned.
            *a = (void*) malloc(m);

            // Initialise array elements with null pointer.
            memset(*a, *NUMBER_0_INTEGER, m);

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Deallocates the character array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 */
void deallocate_character_array(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** a = (void**) p0;

            log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) DESTROY_CHARACTER_ARRAY_MESSAGE, (void*) DESTROY_CHARACTER_ARRAY_MESSAGE_COUNT);

            free(*a);

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Reallocates the character array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array count
 * @param p2 the array size
 */
void reallocate_character_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* c = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** a = (void**) p0;

                log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) RESIZE_CHARACTER_ARRAY_MESSAGE, (void*) RESIZE_CHARACTER_ARRAY_MESSAGE_COUNT);

                // Determine the memory area to be allocated.
                // It is the product of the given size and the type size.
                size_t m = *s * *CHARACTER_PRIMITIVE_SIZE;

                // Create a new array with extended size.
                *a = (void*) realloc(*a, m);

                // Determine the NEW memory area to be allocated.
                // It is the product of the given size reduced by the
                // existing element count, and the type size.
                int n = (*s - *c) * *CHARACTER_PRIMITIVE_SIZE;

                // The new array elements.
                void* e = *a + (m - n);

                // Initialise ONLY NEW array elements with null pointer.
                // Leave existing elements untouched.
                memset(e, *NUMBER_0_INTEGER, n);

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate character array. The array count parameter is null.");
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Compares the character array elements.
 *
 * Returns 1 if the array elements are equal;
 * leaves the given result parameter unchanged, otherwise.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the array count
 * @param p3 the result (Hand over as reference!)
 */
void compare_character_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* c = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The first element.
                    char* e0 = (char*) *NULL_POINTER_MEMORY_MODEL;
                    // The second element.
                    char* e1 = (char*) *NULL_POINTER_MEMORY_MODEL;
                    // The size.
                    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER;

                            break;
                        }

                        // Determine size.
                        s = j * *CHARACTER_PRIMITIVE_SIZE;

                        // Determine the next elements at array plus index.
                        e0 = (char*) (p0 + s);
                        e1 = (char*) (p1 + s);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sets the character array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array!)
 * @param p3 the elements count
 */
void set_character_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* i = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *CHARACTER_PRIMITIVE_SIZE));
                    // The source element.
                    char* se = (char*) *NULL_POINTER_MEMORY_MODEL;
                    // The destination element.
                    char* de = (char*) *NULL_POINTER_MEMORY_MODEL;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The size.
                    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= *c) {

                            break;
                        }

                        // Determine size.
                        s = j * *CHARACTER_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        se = (char*) (p2 + s);
                        de = (char*) (db + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Removes the character array elements.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the index
 * @param p3 the elements count
 */
void remove_character_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* i = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* m = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *CHARACTER_PRIMITIVE_SIZE));
                    // The source base.
                    void* sb = (void*) (db + (*c * *CHARACTER_PRIMITIVE_SIZE));
                    // The source element.
                    char* se = (char*) *NULL_POINTER_MEMORY_MODEL;
                    // The destination element.
                    char* de = (char*) *NULL_POINTER_MEMORY_MODEL;
                    // The remaining elements size.
                    int r = *m - (*i + *c);
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The size.
                    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Starting from the given index, move all remaining elements
                    // one place towards the beginning of the elements.
                    // Example: "test..array"
                    // maxcount = 11
                    // index = 4 (remove "..")
                    // count = 2
                    // rest = 11 - (4 + 2) = 11 - 6 = 5
                    while (*NUMBER_1_INTEGER) {

                        if (j >= r) {

                            break;
                        }

                        // Determine size.
                        s = j * *CHARACTER_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        de = (char*) (db + s);
                        se = (char*) (sb + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                    // Set former last elements to ''. The ASCII of '' is 0.
                    // This is disabled for now, since when creating an array,
                    // its elements are also NOT initialised with ''.
                    // The calling procedure may just cut off the remaining
                    // elements by decreasing the array size (resizing).

                } else {

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the character array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array reference!)
 */
void get_character_array_elements(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        void** e = (void**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* i = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                // Determine element.
                *e = (void*) (p0 + (*i * *CHARACTER_PRIMITIVE_SIZE));

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the character array elements index.
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
 */
void get_character_array_elements_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* ec = (int*) p3;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* ac = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The iteration limit.
                    int l = *ac - *ec + *NUMBER_1_INTEGER;
                    // The element.
                    void* e = *NULL_POINTER_MEMORY_MODEL;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= l) {

                            // The element has not been found.
                            break;
                        }

                        get_character_array_elements(p0, (void*) &j, (void*) &e);
                        compare_character_array_elements(e, p2, p3, (void*) &r);

                        if (r == *NUMBER_1_INTEGER) {

                            // The element has been found.
                            *i = j;

                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT);
    }
}

/* CHARACTER_ARRAY_SOURCE */
#endif
