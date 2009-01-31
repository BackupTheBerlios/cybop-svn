/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: pointer_array.c,v $ $Revision: 1.22 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_ARRAY_SOURCE
#define POINTER_ARRAY_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Allocates the pointer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 */
void allocate_pointer_array(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** a = (void**) p0;

            log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) CREATE_POINTER_ARRAY_MESSAGE_LOG_MODEL, (void*) CREATE_POINTER_ARRAY_MESSAGE_LOG_MODEL_COUNT);

            // Determine the memory area to be allocated.
            // It is the product of the given size and the type size.
            size_t m = *s * *POINTER_PRIMITIVE_SIZE;

            // A minimal space in memory is always allocated,
            // even if the requested size is zero.
            // In other words, a handle to the new instance is always returned.
            *a = (void*) malloc(m);

            // Initialise array elements with null pointer.
            memset(*a, *NUMBER_0_INTEGER_MEMORY_MODEL, m);

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/**
 * Deallocates the pointer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 */
void deallocate_pointer_array(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** a = (void**) p0;

            log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) DESTROY_POINTER_ARRAY_MESSAGE_LOG_MODEL, (void*) DESTROY_POINTER_ARRAY_MESSAGE_LOG_MODEL_COUNT);

            free(*a);

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/**
 * Reallocates the pointer array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array count
 * @param p2 the array size
 */
void reallocate_pointer_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* c = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** a = (void**) p0;

                log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) RESIZE_POINTER_ARRAY_MESSAGE_LOG_MODEL, (void*) RESIZE_POINTER_ARRAY_MESSAGE_LOG_MODEL_COUNT);

                // Determine the memory area to be allocated.
                // It is the product of the given size and the type size.
                size_t m = *s * *POINTER_PRIMITIVE_SIZE;

                // Create a new array with extended size.
                *a = (void*) realloc(*a, m);

                // The NEW memory area to be allocated.
                int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (*s >= *c) {

                    // CAUTION! Do NOT change this value if the size is
                    // smaller than the count, because this will result
                    // in a negative value and cause the new array elements
                    // pointer further below to cross the array's boundary!

                    // Determine the NEW memory area to be allocated.
                    // It is the product of the given size reduced by the
                    // existing element count, and the type size.
                    n = (*s - *c) * *POINTER_PRIMITIVE_SIZE;
                }

                // The new array elements.
                void* e = *a + (m - n);

                // Initialise ONLY NEW array elements with null pointer.
                // Leave existing elements untouched.
                memset(e, *NUMBER_0_INTEGER_MEMORY_MODEL, n);

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate pointer array. The array count parameter is null.");
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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
 * @param p2 the array count
 * @param p3 the result (Hand over as reference!)
 */
void compare_pointer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* c = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The first element.
                    void** e0 = NULL_POINTER_MEMORY_MODEL;
                    // The second element.
                    void** e1 = NULL_POINTER_MEMORY_MODEL;
                    // The size.
                    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

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

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/**
 * Sets the pointer array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements (Hand over as array!)
 * @param p3 the elements count
 */
void set_pointer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* i = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *POINTER_PRIMITIVE_SIZE));
                    // The source element.
                    void** se = NULL_POINTER_MEMORY_MODEL;
                    // The destination element.
                    void** de = NULL_POINTER_MEMORY_MODEL;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The size.
                    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

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

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/**
 * Removes the pointer array elements.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the index
 * @param p3 the elements count
 */
void remove_pointer_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* i = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* m = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The destination base.
                    void* db = (void*) (p0 + (*i * *POINTER_PRIMITIVE_SIZE));
                    // The source base.
                    void* sb = (void*) (db + (*c * *POINTER_PRIMITIVE_SIZE));
                    // The source element.
                    void** se = NULL_POINTER_MEMORY_MODEL;
                    // The destination element.
                    void** de = NULL_POINTER_MEMORY_MODEL;
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
                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

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

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        void** e = (void**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* i = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                // Determine element.
                *e = (void*) (p0 + (*i * *POINTER_PRIMITIVE_SIZE));

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* ec = (int*) p3;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* ac = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    // The iteration limit.
                    int l = *ac - *ec + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    // The element.
                    void* e = *NULL_POINTER_MEMORY_MODEL;
                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= l) {

                            // The element has not been found.
                            break;
                        }

                        get_pointer_array_elements(p0, (void*) &j, (void*) &e);
                        compare_pointer_array_elements(e, p2, p3, (void*) &r);

                        if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                            // The element has been found.
                            *i = j;

                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
                }

            } else {

                log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
            }

        } else {

            log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
        }

    } else {

        log_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL, (void*) COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT);
    }
}

/* POINTER_ARRAY_SOURCE */
#endif
