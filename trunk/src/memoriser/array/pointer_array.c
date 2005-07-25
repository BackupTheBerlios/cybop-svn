/*
 * $RCSfile: pointer_array.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * This file handles a pointer array.
 *
 * An array is a reserved (allocated) area in the computer memory.
 * A programming language like C provides primitive data types whose size
 * is defined, for example: pointer, integer, double, character.
 * It is therefore possible to create and destroy arrays based on primitive types.
 *
 * The syntax of an array mostly looks like: type[size]
 * Example: void*[10]
 *
 * When working with an array, it is referenced by a pointer like: type* variable
 * Example: void** array
 *
 * The array can be dereferenced accordingly: *variable
 * Example: *array
 *
 * Array elements are accessed over their index (array base pointer + index).
 *
 * @version $Revision: 1.4 $ $Date: 2005-07-25 21:01:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_ARRAY_SOURCE
#define POINTER_ARRAY_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../globals/constants/log_constants.c"
#include "../../globals/variables/variables.c"
#include "../../globals/logger/logger.c"

/**
 * Creates the pointer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 */
void allocate_pointer_array(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) INFO_LOG_LEVEL, (void*) CREATE_POINTER_ARRAY_MESSAGE, (void*) CREATE_POINTER_ARRAY_MESSAGE_COUNT);

            // Determine the memory area to be allocated,
            // as product of element count and type size.
            int m = *s * *POINTER_PRIMITIVE_SIZE;

            // A minimal space in memory is always allocated,
            // even if the requested size is zero.
            // In other words, a handle to the new instance is always returned.
            *a = (void*) malloc(m);

            // Initialise array elements with null pointer.
            memset(*a, 0, m);

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Destroys the pointer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 */
void deallocate_pointer_array(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) INFO_LOG_LEVEL, (void*) DESTROY_POINTER_ARRAY_MESSAGE, (void*) DESTROY_POINTER_ARRAY_MESSAGE_COUNT);

            free(*a);

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Resizes the pointer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 */
void resize_pointer_array(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) INFO_LOG_LEVEL, (void*) RESIZE_POINTER_ARRAY_MESSAGE, (void*) RESIZE_POINTER_ARRAY_MESSAGE_COUNT);

            // Determine the memory area to be allocated,
            // as product of element count and type size.
            int m = *s * *POINTER_PRIMITIVE_SIZE;

            // Create a new array with extended size.
            *a = (void*) realloc(*a, m);

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Compares the pointer array elements.
 *
 * Returns 1 if the array elements are equal;
 * leaves the given result parameter unchanged, otherwise.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the count
 * @param p3 the result (Hand over as reference!)
 */
void compare_pointer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* r = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* c = (int*) p2;

            if (p1 != NULL_POINTER) {

                if (p0 != NULL_POINTER) {

                    // The loop variable.
                    int j = 0;
                    // The first element.
                    void** e0 = POINTER_NULL_POINTER;
                    // The second element.
                    void** e1 = POINTER_NULL_POINTER;
                    // The size.
                    int s = 0;

                    while (1) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = 1;

                            break;
                        }

                        // Determine size.
                        s = j * *POINTER_PRIMITIVE_SIZE;

                        // Determine the next elements at array plus index.
                        e0 = (void**) (p0 + s);
                        e1 = (void**) (p1 + s);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sets the pointer array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array!)
 * @param p3 the count
 */
void set_pointer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            if (p1 != NULL_POINTER) {

                int* i = (int*) p1;

                if (p0 != NULL_POINTER) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *POINTER_PRIMITIVE_SIZE));
                    // The source element.
                    void** se = POINTER_NULL_POINTER;
                    // The destination element.
                    void** de = POINTER_NULL_POINTER;
                    // The loop variable.
                    int j = 0;
                    // The size.
                    int s = 0;

                    while (1) {

                        if (j >= *c) {

                            break;
                        }

                        // Determine size.
                        s = j * *POINTER_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        se = (void**) (p2 + s);
                        de = (void**) (db + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Removes the pointer array elements.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the index
 * @param p3 the count
 */
void remove_pointer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* i = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* m = (int*) p1;

                if (p0 != NULL_POINTER) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *POINTER_PRIMITIVE_SIZE));
                    // The source base.
                    void* sb = (void*) (db + (*c * *POINTER_PRIMITIVE_SIZE));
                    // The source element.
                    void** se = POINTER_NULL_POINTER;
                    // The destination element.
                    void** de = POINTER_NULL_POINTER;
                    // The remaining elements size.
                    int r = *m - (*i + *c);
                    // The loop variable.
                    int j = 0;
                    // The size.
                    int s = 0;

                    // Starting from the given index, move all remaining elements
                    // one place towards the beginning of the elements.
                    // Example: "test..array"
                    // maxcount = 11
                    // index = 4 (remove "..")
                    // count = 2
                    // rest = 11 - (4 + 2) = 11 - 6 = 5
                    while (1) {

                        if (j >= r) {

                            break;
                        }

                        // Determine size.
                        s = j * *POINTER_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        de = (void**) (db + s);
                        se = (void**) (sb + s);

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

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the pointer array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array reference!)
 */
void get_pointer_array_elements(void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        void** e = (void**) p2;

        if (p1 != NULL_POINTER) {

            int* i = (int*) p1;

            if (p0 != NULL_POINTER) {

                // Determine element.
                *e = (void*) (p0 + (*i * *POINTER_PRIMITIVE_SIZE));

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the pointer array elements index.
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
void get_pointer_array_elements_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* ec = (int*) p3;

            if (p1 != NULL_POINTER) {

                int* ac = (int*) p1;

                if (p0 != NULL_POINTER) {

                    // The iteration limit.
                    int l = *ac - *ec + 1;
                    // The element.
                    void* e = NULL_POINTER;
                    // The loop variable.
                    int j = 0;
                    // The comparison result.
                    int r = 0;

                    while (1) {

                        if (j >= l) {

                            // The element has not been found.
                            break;
                        }

                        get_pointer_array_elements(p0, (void*) &j, (void*) &e);
                        compare_pointer_array_elements(e, p2, p3, (void*) &r);

                        if (r == 1) {

                            // The element has been found.
                            *i = j;

                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT);
    }
}

/* POINTER_ARRAY_SOURCE */
#endif
