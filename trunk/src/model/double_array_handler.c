/*
 * $RCSfile: double_array_handler.c,v $
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
 * for example: int[]
 * But it can also be written as: type*
 * for example: int*
 *
 * Array elements are accessed over their index (array base pointer + index).
 *
 * @version $Revision: 1.8 $ $Date: 2004-04-07 10:36:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_ARRAY_HANDLER_SOURCE
#define DOUBLE_ARRAY_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"

//
// Double array.
//

/**
 * Compares the double arrays.
 *
 * Returns 1 if the double elements are equal.
 * The given result remains unchanged if the arrays are unequal.
 *
 * @param p0 the first double array
 * @param p1 the second double array
 * @param p2 the size
 * @param p3 the result
 */
void compare_double_arrays(const void* p0, const void* p1, const void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* r = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                void** a1 = (void**) p1;

                if (p0 != NULL_POINTER) {

                    void** a0 = (void**) p0;

                    int i = 0;
                    double* e0 = NULL_DOUBLE_POINTER;
                    double* e1 = NULL_DOUBLE_POINTER;

                    while (1) {

                        if (i >= *s) {

                            // All elements have been compared and are equal.
                            *r = 1;

                            break;
                        }

                        // Determine the next elements at array plus index.
                        e0 = (double*) (*a0 + i);
                        e1 = (double*) (*a1 + i);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        i++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not compare double arrays. The first double array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not compare double arrays. The second double array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not compare double arrays. The size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not compare double arrays. The result is null.");
    }
}

//
// Double array element.
//

/**
 * Sets the double array element.
 *
 * @param p0 the double array
 * @param p1 the index
 * @param p2 the element
 */
void set_double_array_element(const void* p0, const void* p1, const void* p2) {

    if (p2 != NULL_POINTER) {

        double* e0 = (double*) p2;

        if (p1 != NULL_POINTER) {

            int* i = (int*) p1;

            if (p0 != NULL_POINTER) {

                void** a = (void**) p0;

                // Set element.
                double* e1 = (double*) (*a + *i);
                *e1 = *e0;

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not set double array element. The double array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not set double array element. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set double array element. The element is null.");
    }
}

/**
 * Removes the double array element.
 *
 * @param p0 the double array
 * @param p1 the size
 * @param p2 the index
 */
void remove_double_array_element(const void* p0, const void* p1, const void* p2) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* s = (int*) p1;

            if (p0 != NULL_POINTER) {

                void** a = (void**) p0;

                // Initialize loop variable with index.
                // Do not use the index itself as it was handed over as constant parameter!
                int j = *i;
                double* e0 = NULL_DOUBLE_POINTER;
                double* e1 = NULL_DOUBLE_POINTER;

                // Starting from the given index, move all remaining elements one
                // place towards the beginning of the elements.
                while (1) {

                    if ((j + 1) >= *s) {

                        break;
                    }

                    e0 = (double*) (*a + j);
                    e1 = (double*) (*a + j + 1);
                    *e0 = *e1;

                    j++;
                }

                // Set former last element to 0.0.
                e0 = (double*) (*a + j);
                *e0 = 0.0;

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not remove double array element. The double array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not remove double array element. The size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove double array element. The index is null.");
    }
}

/**
 * Gets the double array element.
 *
 * @param p0 the double array
 * @param p1 the index
 * @param p2 the element
 */
void get_double_array_element(const void* p0, const void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        double* e0 = (double*) p2;

        if (p1 != NULL_POINTER) {

            int* i = (int*) p1;

            if (p0 != NULL_POINTER) {

                void** a = (void**) p0;

                // Get element.
                double* e1 = (double*) (*a + *i);
                *e0 = *e1;

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element. The double array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element. The element is null.");
    }
}

/**
 * Gets the double array element index.
 *
 * The first occurence of the element will be considered.
 * The given index remains unchanged if no element is found.
 *
 * @param p0 the double array
 * @param p1 the size
 * @param p2 the element
 * @param p3 the index
 */
void get_double_array_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            double* e0 = (double*) p2;

            if (p1 != NULL_POINTER) {

                int* s = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** a = (void**) p0;

                    int j = 0;
                    double* e1 = NULL_DOUBLE_POINTER;

                    while (1) {

                        if (j >= *s) {

                            // The element has not been found.
                            break;
                        }

                        // Compare given element with the next integer element at array plus index.
                        e1 = (double*) (*a + j);

                        if (*e0 == *e1) {

                            // The element has been found.
                            *i = j;
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The double array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The element is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The index is null.");
    }
}

/* DOUBLE_ARRAY_HANDLER_SOURCE */
#endif
