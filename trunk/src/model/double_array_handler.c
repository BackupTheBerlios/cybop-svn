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
 */

#ifndef DOUBLE_ARRAY_HANDLER_SOURCE
#define DOUBLE_ARRAY_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../model/constants.c"

/**
 * This is the double array handler.
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
 * @version $Revision: 1.3 $ $Date: 2004-03-11 14:33:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

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

    int* r = (int*) p3;

    if (r != (void*) 0) {

        int* s = (int*) p2;

        if (s != (void*) 0) {

            if (p1 != (void*) 0) {

                if (p0 != (void*) 0) {

                    int i = 0;
                    double* e0 = (void*) 0;
                    double* e1 = (void*) 0;

                    while (1) {

                        if (i >= *s) {

                            // All elements have been compared and are equal.
                            *r = 1;

                            break;
                        }

                        // Determine the next elements at array plus index.
                        e0 = (double*) (p0 + i);
                        e1 = (double*) (p1 + i);

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

    double* e0 = (double*) p2;

    if (e0 != (void*) 0) {

        int* i = (int*) p1;

        if (i != (void*) 0) {

            if (p0 != (void*) 0) {

                // Set element.
                double* e1 = (double*) (p0 + *i);
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
 * @param p1 the index
 * @param p2 the size
 */
void remove_double_array_element(const void* p0, const void* p1, const void* p2) {

    int* s = (int*) p2;

    if (s != (void*) 0) {

        int* i = (int*) p1;

        if (i != (void*) 0) {

            if (p0 != (void*) 0) {

                // Initialize loop variable with index.
                // Do not use the index itself as it was handed over as constant parameter!
                int j = *i;
                double* e0 = (void*) 0;
                double* e1 = (void*) 0;

                // Starting from the given index, move all remaining elements one
                // place towards the beginning of the elements.
                while (1) {

                    if ((j + 1) >= *s) {

                        break;
                    }

                    e0 = (double*) (p0 + j);
                    e1 = (double*) (p0 + j + 1);
                    *e0 = *e1;

                    j++;
                }

                // Set former last element to 0.0.
                e0 = (double*) (p0 + j);
                *e0 = 0.0;

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not remove double array element. The double array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not remove double array element. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove double array element. The size is null.");
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

    double* e0 = (double*) p2;

    if (e0 != (void*) 0) {

        int* i = (int*) p1;

        if (i != (void*) 0) {

            if (p0 != (void*) 0) {

                // Get element.
                double* e1 = (double*) (p0 + *i);
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
 * @param p1 the element
 * @param p2 the size
 * @param p3 the index
 */
void get_double_array_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    int* i = (int*) p3;

    if (i != (void*) 0) {

        int* s = (int*) p2;

        if (s != (void*) 0) {

            double* e0 = (double*) p1;

            if (e0 != (void*) 0) {

                if (p0 != (void*) 0) {

                    int j = 0;
                    double* e1 = (void*) 0;

                    while (1) {

                        if (j >= *s) {

                            // The element has not been found.
                            break;
                        }

                        // Compare given element with the next integer element at array plus index.
                        e1 = (double*) (p0 + j);

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

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The element is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get double array element index. The index is null.");
    }
}

/* DOUBLE_ARRAY_HANDLER_SOURCE */
#endif
