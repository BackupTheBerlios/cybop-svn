/*
 * $RCSfile: double_array.c,v $
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
 * This file handles a double array.
 *
 * An array is a reserved (allocated) area in the computer memory.
 * A programming language like C provides primitive data types whose size
 * is defined, for example: pointer, integer, double, character.
 * It is therefore possible to create and destroy arrays based on primitive types.
 *
 * The syntax of an array mostly looks like: type[size]
 * Example: double[10]
 *
 * When working with an array, it is referenced by a pointer like: type* variable
 * Example: double* array
 *
 * The array can be dereferenced accordingly: *variable
 * Example: *array
 *
 * Array elements are accessed over their index (array base pointer + index).
 *
 * @version $Revision: 1.8 $ $Date: 2004-06-15 11:31:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_ARRAY_SOURCE
#define DOUBLE_ARRAY_SOURCE

#include "../global/constant.c"
#include "../global/variable.c"
#include "../logger/logger.c"

//
// Array.
//

/**
 * Creates the double array.
 *
 * @param p0 the array
 * @param p1 the maximum count
 */
void create_double_array(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* c = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_DOUBLE_ARRAY_MESSAGE, (void*) &CREATE_DOUBLE_ARRAY_MESSAGE_COUNT);

            // Determine size as product of element count and type size.
            int s = *c * DOUBLE_PRIMITIVE_SIZE;

            // A minimal space in memory is always allocated,
            // even if the requested size is zero.
            // In other words, a handle to the new instance is always returned.
            *a = (void*) malloc(s);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Destroys the double array.
 *
 * @param p0 the array
 * @param p1 the maximum count
 */
void destroy_double_array(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* c = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_DOUBLE_ARRAY_MESSAGE, (void*) &DESTROY_DOUBLE_ARRAY_MESSAGE_COUNT);

            //?? TODO: Destroy all array elements in a loop??
            //?? Which is the same as Garbage Collection!
            //?? SEE: signal_memory
            free(*a);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Resizes the double array.
 *
 * @param p0 the array
 * @param p1 the maximum count
 */
void resize_double_array(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* c = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** a = (void**) p0;

            log_message((void*) &INFO_LOG_LEVEL, (void*) &RESIZE_DOUBLE_ARRAY_MESSAGE, (void*) &RESIZE_DOUBLE_ARRAY_MESSAGE_COUNT);

            // Determine size as product of element count and type size.
            int s = *c * DOUBLE_PRIMITIVE_SIZE;

            // Create a new array with extended size.
            *a = (void*) realloc(*a, s);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Copies the double array.
 *
 * @param p0 the source array
 * @param p1 the destination array
 * @param p2 the count
 */
void copy_double_array(const void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* c = (int*) p2;

        if (p1 != NULL_POINTER) {

            void** da = (void**) p1;

            if (p0 != NULL_POINTER) {

                void** sa = (void**) p0;

                // The loop variable.
                int j = 0;
                // The source array element.
                double* sae = DOUBLE_NULL_POINTER;
                // The destination array element.
                double* dae = DOUBLE_NULL_POINTER;
                // The size.
                int s = 0;

                while (1) {

                    if (j >= *c) {

                        break;
                    }

                    // Determine size.
                    s = j * DOUBLE_PRIMITIVE_SIZE;

                    // Determine the next elements at array plus index.
                    sae = (double*) (*sa + s);
                    dae = (double*) (*da + s);

                    // Copy array element.
                    *dae = *sae;

                    j++;
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COPY_DOUBLE_ARRAY_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_COPY_DOUBLE_ARRAY_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COPY_DOUBLE_ARRAY_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_COPY_DOUBLE_ARRAY_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COPY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_COPY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

//
// Array element.
//

/**
 * Compares the double array elements.
 *
 * Returns 1 if the double elements are equal.
 * The given result remains unchanged if the array elements are unequal.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the count
 * @param p3 the result
 */
void compare_double_array_elements(const void* p0, const void* p1, const void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* r = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* c = (int*) p2;

            if (p1 != NULL_POINTER) {

                void** a1 = (void**) p1;

                if (p0 != NULL_POINTER) {

                    void** a0 = (void**) p0;

                    // The loop variable.
                    int j = 0;
                    // The first element.
                    double* e0 = DOUBLE_NULL_POINTER;
                    // The second element.
                    double* e1 = DOUBLE_NULL_POINTER;
                    // The size.
                    int s = 0;

                    while (1) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = 1;

                            break;
                        }

                        // Determine size.
                        s = j * DOUBLE_PRIMITIVE_SIZE;

                        // Determine the next elements at array plus index.
                        e0 = (double*) (*a0 + s);
                        e1 = (double*) (*a1 + s);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE, (void*) &COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Sets the double array elements.
 *
 * @param p0 the destination array
 * @param p1 the destination array index
 * @param p2 the source array
 * @param p3 the count
 */
void set_double_array_elements(void* p0, const void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** sa = (void**) p2;

            if (p1 != NULL_POINTER) {

                int* i = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** da = (void**) p0;

                    // The loop variable.
                    int j = 0;
                    // The destination base to start copying to.
                    void* db = (void*) (*da + *i * DOUBLE_PRIMITIVE_SIZE);
                    // The source element.
                    double* se = DOUBLE_NULL_POINTER;
                    // The destination element.
                    double* de = DOUBLE_NULL_POINTER;
                    // The size.
                    int s = 0;

                    while (1) {

                        if (j >= *c) {

                            break;
                        }

                        // Determine size.
                        s = j * DOUBLE_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        se = (double*) (*sa + s);
                        de = (double*) (db + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Removes the double array elements.
 *
 * @param p0 the array
 * @param p1 the maximum count
 * @param p2 the array index
 * @param p3 the count
 */
void remove_double_array_elements(void* p0, const void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* i = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* m = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** a = (void**) p0;

                    // The loop variable.
                    int j = 0;
                    // The remaining elements size.
                    int r = *m - (*i + *c);
                    // The destination base.
                    void* db = (void*) (*a + *i * DOUBLE_PRIMITIVE_SIZE);
                    // The source base.
                    void* sb = (void*) (*a + *i * DOUBLE_PRIMITIVE_SIZE + *c * DOUBLE_PRIMITIVE_SIZE);
                    // The source element.
                    double* se = DOUBLE_NULL_POINTER;
                    // The destination element.
                    double* de = DOUBLE_NULL_POINTER;
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
                        s = j * DOUBLE_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        de = (double*) (db + s);
                        se = (double*) (sb + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                    // Set former last elements to 0.0.
                    // This is disabled for now, since when creating an array,
                    // its elements are also NOT initialized with ''.
                    // The calling procedure may just cut off the remaining
                    // elements by decreasing the array size (resizing).

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the double array elements.
 *
 * @param p0 the source array
 * @param p1 the source array index
 * @param p2 the destination array
 * @param p3 the count
 */
void get_double_array_elements(const void* p0, const void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** da = (void**) p2;

            if (p1 != NULL_POINTER) {

                int* i = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** sa = (void**) p0;

                    // The loop variable.
                    int j = 0;
                    // The source base to start copying from.
                    void* sb = (void*) (*sa + *i * DOUBLE_PRIMITIVE_SIZE);
                    // The source element.
                    double* se = DOUBLE_NULL_POINTER;
                    // The destination element.
                    double* de = DOUBLE_NULL_POINTER;
                    // The size.
                    int s = 0;

                    while (1) {

                        if (j >= *c) {

                            break;
                        }

                        // Determine size.
                        s = j * DOUBLE_PRIMITIVE_SIZE;

                        // Determine source and destination element.
                        se = (double*) (sb + s);
                        de = (double*) (*da + s);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Gets the double array elements index.
 *
 * The first occurence of the element will be considered.
 * The given index remains unchanged if no element is found.
 *
 * @param p0 the array
 * @param p1 the array maximum count
 * @param p2 the comparison array
 * @param p3 the comparison array count
 * @param p4 the index within array
 */
void get_double_array_elements_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* c = (int*) p3;

            if (p2 != NULL_POINTER) {

                void** ca = (void**) p2;

                if (p1 != NULL_POINTER) {

                    int* m = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** a = (void**) p0;

                        // The loop variable.
                        int j = 0;
                        // The iteration limit.
                        int l = *m - *c;
                        // The element.
                        void* e = NULL_POINTER;
                        // The comparison result.
                        int r = 0;
                        // The size.
                        int s = 0;

                        while (1) {

                            if (j >= l) {

                                // The element has not been found.
                                break;
                            }

                            // Determine size.
                            s = j * DOUBLE_PRIMITIVE_SIZE;

                            // Determine element.
                            e = (void*) (*a + s);

                            compare_double_array_elements((void*) &e, p2, p3, (void*) &r);

                            if (r == 1) {

                                // The element has been found.
                                *i = j;

                                break;
                            }

                            j++;
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT);
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT);
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT);
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT);
    }
}

/* DOUBLE_ARRAY_SOURCE */
#endif
