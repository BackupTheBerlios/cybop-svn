/*
 * $RCSfile: character_array_handler.c,v $
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

#ifndef CHARACTER_ARRAY_HANDLER_SOURCE
#define CHARACTER_ARRAY_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../model/constants.c"

/**
 * This is the character array handler.
 *
 * An array is a reserved (allocated) area in the computer memory.
 * A programming language like C provides primitive data types whose size
 * is defined, for example: pointer, integer, double, character.
 * It is therefore possible to create and destroy arrays based on primitive types.
 *
 * The syntax of an array mostly looks like: type[size]
 * for example: int[]
 * But it can also be written as: type*
 * for example: int*
 *
 * Array elements are accessed over their index (array base pointer + index).
 *
 * @version $Revision: 1.1 $ $Date: 2004-03-10 18:06:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Character array.
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
void** extend_internal_array(const void** p0, const void* p1, const void* p2) {

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

/**
 * Compares the character arrays.
 *
 * Returns 1 if the character elements are equal.
 * Otherwise, 0 is returned.
 *
 * @param p0 the first character array
 * @param p1 the second character array
 * @param p2 the size
 * @param p3 the result
 */
void compare_character_arrays(const void* p0, const void* p1, const void* p2, void* p3) {

    int* r = (int*) p3;

    if (r != (void*) 0) {

        *r = 0;

        int* s = (int*) p2;

        if (s != (void*) 0) {

            if (p1 != (void*) 0) {

                if (p0 != (void*) 0) {

                    int i = 0;
                    char* e0 = (void*) 0;
                    char* e1 = (void*) 0;

                    while (1) {

                        if (i >= *s) {

                            // All elements have been compared and are equal.
                            *r = 1;

                            break;
                        }

                        // Determine the next elements at array plus index.
                        e0 = (char*) (p0 + i);
                        e1 = (char*) (p1 + i);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        i++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not compare character arrays. The first character array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not compare character arrays. The second character array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not compare character arrays. The size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not compare character arrays. The result is null.");
    }
}

//
// Character array element.
//

/**
 * Sets the character array element.
 *
 * @param p0 the character array
 * @param p1 the index
 * @param p2 the element
 */
void set_character_array_element(const void* p0, const void* p1, const void* p2) {

    char* e0 = (char*) p2;

    if (e0 != (void*) 0) {

        int* i = (int*) p1;

        if (i != (void*) 0) {

            if (p0 != (void*) 0) {

                // Set element.
                char* e1 = (char*) (p0 + *i);
                *e1 = *e0;

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not set character array element. The character array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not set character array element. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set character array element. The element is null.");
    }
}

/**
 * Removes the character array element.
 *
 * @param p0 the character array
 * @param p1 the index
 * @param p2 the count
 */
void remove_character_array_element(const void* p0, const void* p1, const void* p2) {

    int* c = (int*) p2;

    if (c != (void*) 0) {

        int* i = (int*) p1;

        if (i != (void*) 0) {

            if (p0 != (void*) 0) {

                // Initialize loop variable with index.
                // Do not use the index itself as it was handed over as constant parameter!
                int j = *i;
                char* e0 = (void*) 0;
                char* e1 = (void*) 0;

                // Starting from the given index, move all remaining elements one
                // place towards the beginning of the elements.
                while (1) {

                    if ((j + 1) >= *c) {

                        break;
                    }

                    e0 = (char*) (p0 + j);
                    e1 = (char*) (p0 + j + 1);
                    *e0 = *e1;

                    j++;
                }

                // Set former last element to ''.
                e0 = (char*) (p0 + j);
                *e0 = '';

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not remove character array element. The character array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not remove character array element. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove character array element. The count is null.");
    }
}

/**
 * Gets the character array element.
 *
 * @param p0 the character array
 * @param p1 the index
 * @param p2 the element
 */
void get_character_array_element(const void* p0, const void* p1, void* p2) {

    char* e0 = (char*) p2;

    if (e0 != (void*) 0) {

        int* i = (int*) p1;

        if (i != (void*) 0) {

            if (p0 != (void*) 0) {

                // Get element.
                char* e1 = (char*) (p0 + *i);
                *e0 = *e1;

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element. The character array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element. The element is null.");
    }
}

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
void get_character_array_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    int* i = (int*) p3;

    if (i != (void*) 0) {

        int* c = (int*) p2;

        if (c != (void*) 0) {

            char* e0 = (char*) p1;

            if (e0 != (void*) 0) {

                if (p0 != (void*) 0) {

                    int j = 0;
                    char* e1 = (void*) 0;

                    while (1) {

                        if (j >= *c) {

                            // The element has not been found.
                            *i = INVALID_INDEX;
                            break;
                        }

                        // Compare given element with the next integer element at array plus index.
                        e1 = (char*) (p0 + j);

                        if (*e0 == *e1) {

                            // The element has been found.
                            *i = j;
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element index. The character array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element index. The element is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element index. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get character array element index. The index is null.");
    }
}

/* CHARACTER_ARRAY_HANDLER_SOURCE */
#endif
