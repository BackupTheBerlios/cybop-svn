/*
 * $RCSfile: internal_array_handler.c,v $
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
 */

#ifndef INTERNAL_ARRAY_HANDLER_SOURCE
#define INTERNAL_ARRAY_HANDLER_SOURCE

#include "../logger/log_handler.c"

/**
 * This is the internal array handler.
 *
 * An internal array is one provided by the programming language.
 * Its syntax mostly looks like: type[size].
 * Internal array elements are accessed over an index.
 *
 * @version $Revision: 1.9 $ $Date: 2004-03-03 08:22:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The invalid/ null/ not found index. */
static const int INVALID_INDEX = -1;

//
// Internal array.
//

/**
 * Extends the internal array.
 *
 * @param p0 the old internal array
 * @param p1 the old size
 * @param p2 the new size
 * @return the new internal array
 */
/*??
void** extend_internal_array(void** p0, void* p1, void* p2) {

    void** a = (void*) 0;

    if (p0 != (void*) 0) {

        int* old_size = (int*) p1;
        int* new_size = (int*) p2;
        // Create new internal array.
        a = malloc(*new_size);

        if (a != (void*) 0) {

            // Copy all elements from the old to the new array.
            // The rest of the new array is just left empty as is;
            // no zeros are set.
            int i = 0;

            while (i < *old_size) {

                a + i = p0 + i;

                i++;
            }

            // Destroy old internal array.
            free(p0);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not extend internal array. The new internal array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not extend internal array. The old internal array is null.");
    }

    return a;
}
*/

//
// Comparison.
//

/**
 * Compares the character arrays.
 *
 * Returns 1 if the character elements are equal.
 * Otherwise, 0 is returned.
 *
 * @param p0 the first internal array
 * @param p1 the second internal array
 * @param p2 the size
 * @param p3 the result
 */
void compare_character_arrays(void** p0, void** p1, void* p2, void* p3) {

    int* r = (int*) p3;

    if (r != (void*) 0) {

        *r = 0;
        int i = 0;
        char* e0 = (void*) 0;
        char* e1 = (void*) 0;

        while (1) {

            if (i == size) {

                // All elements have been compared and are equal.
                *r = 1;

                break;
            }

            // Determine the next character elements at array plus index.
            e0 = (char*) (p0 + i);

            if (*x == *e) {

--
            if ((p0 + i) != (p1 + i)) {

                // Stop comparison if two elements are not equal.
                break;
            }

            i++;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not compare character arrays. The result is null.");
    }
}

//
// Internal array element.
//

/**
 * Sets the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @param p2 the element
 */
void set_internal_array_element(void** p0, void* p1, void* p2) {

    if (p0 != (void*) 0) {

        int* i = (int*) p1;

        if (*i != INVALID_INDEX) {

            // Set element.
            p0 + *i = p2;

        } else {

            log_message((void*) &WARNING_LOG_LEVEL, "Could not set internal array element. The index is invalid.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set internal array element. The internal array is null.");
    }
}

/**
 * Removes the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @param p2 the count
 */
void remove_internal_array_element(void** p0, void* p1, void* p2) {

    if (p0 != (void*) 0) {

        int* index = (int*) p1;

        if (*index != INVALID_INDEX) {

            // Initialize loop variable with index.
            // Do not use the index itself as it was handed over as constant parameter!
            int i = *index;
            int* count = (int*) p2;
            
            // Starting from the given index, move all remaining elements one
            // place towards the beginning of the elements.
            while ((i + 1) < *count) {

                p0 + i = p0 + (i + 1);

                i++;
            }

            // Set former last element to 0.
            p0 + i = (void*) 0;

        } else {

            log_message((void*) &WARNING_LOG_LEVEL, "Could not remove internal array element. The index is invalid.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove internal array element. The internal array is null.");
    }
}

/**
 * Gets the internal array element.
 *
 * @param p0 the internal array
 * @param p1 the index
 * @return the element
 */
void* get_internal_array_element(void** p0, void* p1) {

    void* e = (void*) 0;

    if (p0 != (void*) 0) {

        int* i = (int*) p1;

        if (*i != INVALID_INDEX) {

            // Get element.
            e = p0 + *i;

        } else {

            log_message((void*) &WARNING_LOG_LEVEL, "Could not get internal array element. The index is invalid.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get internal array element. The internal array is null.");
    }

    return e;
}

//
// Pointer element.
//

/**
 * Gets the pointer array element index.
 *
 * The first occurence of the element will be considered.
 *
 * @param p0 the pointer array
 * @param p1 the element
 * @param p2 the count
 * @param p3 the index
 */
void get_pointer_array_element_index(const void** p0, const void** p1, const void* p2, void* p3) {

    int* index = (int*) p3;

    if (index != (void*) 0) {

        int* c = (int*) p2;

        if (c != (void*) 0) {

            void** e = (void**) p1;
            int i = 0;
            void** x = (void*) 0;

            while (1) {

                if (i == *c) {

                    // The element has not been found.
                    *index = INVALID_INDEX;
                    break;
                }

                // Determine the next integer element at array plus index.
                x = (void**) (p0 + i);

                if (*x == *e) {

                    // The element has been found.
                    *index = i;
                    break;
                }

                i++;
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get pointer array element index. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get pointer array element index. The index is null.");
    }
}

//
// Integer element.
//

/**
 * Gets the integer array element index.
 *
 * The first occurence of the element will be considered.
 *
 * @param p0 the integer array
 * @param p1 the element
 * @param p2 the count
 * @param p3 the index
 */
void get_integer_array_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    int* index = (int*) p3;

    if (index != (void*) 0) {

        int* c = (int*) p2;

        if (c != (void*) 0) {

            int* e = (int*) p1;
            int i = 0;
            int* x = (void*) 0;

            while (1) {

                if (i == *c) {

                    // The element has not been found.
                    *index = INVALID_INDEX;
                    break;
                }

                // Determine the next integer element at array plus index.
                x = (int*) (p0 + i);

                if (*x == *e) {

                    // The element has been found.
                    *index = i;
                    break;
                }

                i++;
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get integer array element index. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get integer array element index. The index is null.");
    }
}

//
// Double element.
//

/**
 * Gets the double array element index.
 *
 * The first occurence of the element will be considered.
 *
 * @param p0 the double array
 * @param p1 the element
 * @param p2 the count
 * @param p3 the index
 */
void get_double_array_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    int* index = (int*) p3;

    if (index != (void*) 0) {

        int* c = (int*) p2;

        if (c != (void*) 0) {

            double* e = (double*) p1;
            int i = 0;
            double* x = (void*) 0;

            while (1) {

                if (i == *c) {

                    // The element has not been found.
                    *index = INVALID_INDEX;
                    break;
                }

                // Determine the next integer element at array plus index.
                x = (double*) (p0 + i);

                if (*x == *e) {

                    // The element has been found.
                    *index = i;
                    break;
                }

                i++;
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The index is null.");
    }
}

//
// Character element.
//

/**
 * Gets the character array element index.
 *
 * The first occurence of the element will be considered.
 *
 * @param p0 the character array
 * @param p1 the element
 * @param p2 the count
 * @param p3 the index
 */
void get_character_array_element_index(const void** p0, const void* p1, const void* p2, void* p3) {

    int* index = (int*) p3;

    if (index != (void*) 0) {

        int* c = (int*) p2;

        if (c != (void*) 0) {

            char* e = (char*) p1;
            int i = 0;
            char* x = (void*) 0;

            while (1) {

                if (i == *c) {

                    // The element has not been found.
                    *index = INVALID_INDEX;
                    break;
                }

                // Determine the next integer element at array plus index.
                x = (char*) (p0 + i);

                if (*x == *e) {

                    // The element has been found.
                    *index = i;
                    break;
                }

                i++;
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element index. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element index. The index is null.");
    }
}

/* INTERNAL_ARRAY_HANDLER_SOURCE */
#endif
