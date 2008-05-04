/*
 * $RCSfile: integer_array.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.19 $ $Date: 2008-05-04 00:18:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_ARRAY_SOURCE
#define INTEGER_ARRAY_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/primitive_type_size_variables.c"

/**
 * Allocates the integer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 */
void allocate_integer_array(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) INFORMATION_LOG_LEVEL, (void*) CREATE_INTEGER_ARRAY_MESSAGE, (void*) CREATE_INTEGER_ARRAY_MESSAGE_COUNT);

            // Determine the memory area to be allocated.
            // It is the product of the given size and the type size.
            size_t m = *s * *INTEGER_PRIMITIVE_SIZE;

            // A minimal space in memory is always allocated,
            // even if the requested size is zero.
            // In other words, a handle to the new instance is always returned.
            *a = (void*) malloc(m);

            // Initialise array elements with null pointer.
            memset(*a, *NUMBER_0_INTEGER, m);

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Deallocates the integer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 */
void deallocate_integer_array(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) INFORMATION_LOG_LEVEL, (void*) DESTROY_INTEGER_ARRAY_MESSAGE, (void*) DESTROY_INTEGER_ARRAY_MESSAGE_COUNT);

            free(*a);

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Reallocates the integer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array count
 * @param p2 the array size
 */
void reallocate_integer_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* s = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* c = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** a = (void**) p0;

                log_message((void*) INFORMATION_LOG_LEVEL, (void*) RESIZE_INTEGER_ARRAY_MESSAGE, (void*) RESIZE_INTEGER_ARRAY_MESSAGE_COUNT);

                // Determine the memory area to be allocated.
                // It is the product of the given size and the type size.
                size_t m = *s * *INTEGER_PRIMITIVE_SIZE;

                // Create a new array with extended size.
                *a = (void*) realloc(*a, m);

                // Determine the NEW memory area to be allocated.
                // It is the product of the given size reduced by the
                // existing element count, and the type size.
                int n = (*s - *c) * *INTEGER_PRIMITIVE_SIZE;

                // The new array elements.
                void* e = *a + (m - n);

                // Initialise ONLY NEW array elements with null pointer.
                // Leave existing elements untouched.
                memset(e, *NUMBER_0_INTEGER, n);

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not reallocate integer array. The array count parameter is null.");
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Compares the integer array elements.
 *
 * Returns 1 if the array elements are equal;
 * leaves the given result parameter unchanged, otherwise.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the array count
 * @param p3 the result (Hand over as reference!)
 */
void compare_integer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* r = (int*) p3;

        if (p2 != *NULL_POINTER) {

            int* c = (int*) p2;

            if (p1 != *NULL_POINTER) {

                if (p0 != *NULL_POINTER) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER;
                    // The first element.
                    int* e0 = (int*) *NULL_POINTER;
                    // The second element.
                    int* e1 = (int*) *NULL_POINTER;
                    // The size.
                    int s = *NUMBER_0_INTEGER;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER;

                            break;
                        }

                        // Determine size.
                        s = j * *INTEGER_PRIMITIVE_SIZE;

                        // Determine the next elements at array plus index.
                        e0 = (int*) (p0 + s);
                        e1 = (int*) (p1 + s);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sets the integer array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements
 * @param p3 the elements count
 */
void set_integer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* sc = (int*) p3;

        if (p2 != *NULL_POINTER) {

            if (p1 != *NULL_POINTER) {

                int* i = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *INTEGER_PRIMITIVE_SIZE));
                    // The source element.
                    int* se = (int*) *NULL_POINTER;
                    // The destination element.
                    int* de = (int*) *NULL_POINTER;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER;
                    // The offset.
                    int o = *NUMBER_0_INTEGER;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= *sc) {

                            break;
                        }

                        // Determine size.
                        o = j * *INTEGER_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        se = (int*) (p2 + o);
                        de = (int*) (db + o);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Removes the integer array elements.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the index
 * @param p3 the elements count
 */
void remove_integer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER) {

            int* i = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* m = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *INTEGER_PRIMITIVE_SIZE));
                    // The source base.
                    void* sb = (void*) (db + (*c * *INTEGER_PRIMITIVE_SIZE));
                    // The source element.
                    int* se = (int*) *NULL_POINTER;
                    // The destination element.
                    int* de = (int*) *NULL_POINTER;
                    // The remaining elements size.
                    int r = *m - (*i + *c);
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER;
                    // The size.
                    int s = *NUMBER_0_INTEGER;

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
                        s = j * *INTEGER_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        de = (int*) (db + s);
                        se = (int*) (sb + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                    // Set former last elements to 0.0.
                    // This is disabled for now, since when creating an array,
                    // its elements are also NOT initialised with ''.
                    // The calling procedure may just cut off the remaining
                    // elements by decreasing the array size (resizing).

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the integer array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array reference!)
 */
void get_integer_array_elements(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        void** d = (void**) p2;

        if (p1 != *NULL_POINTER) {

            int* i = (int*) p1;

            if (p0 != *NULL_POINTER) {

                // Determine element.
                *d = (void*) (p0 + (*i * *INTEGER_PRIMITIVE_SIZE));

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the integer array elements index.
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
void get_integer_array_elements_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* i = (int*) p4;

        if (p3 != *NULL_POINTER) {

            int* ec = (int*) p3;

            if (p1 != *NULL_POINTER) {

                int* ac = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    // The iteration limit.
                    int l = *ac - *ec + *NUMBER_1_INTEGER;
                    // The element.
                    void* e = *NULL_POINTER;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= l) {

                            // The element has not been found.
                            break;
                        }

                        get_integer_array_elements(p0, (void*) &j, (void*) &e);
                        compare_integer_array_elements(e, p2, p3, (void*) &r);

                        if (r == *NUMBER_1_INTEGER) {

                            // The element has been found.
                            *i = j;

                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT);
    }
}

/* INTEGER_ARRAY_SOURCE */
#endif
