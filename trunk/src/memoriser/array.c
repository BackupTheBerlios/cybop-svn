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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SOURCE
#define ARRAY_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Allocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 * @param p2 the array type
 */
void allocate_array(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** a = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate array.");

        // The memory area to be allocated.
        int ma = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Calculate memory area depending on given array type.
        calculate_area((void*) &ma, p1, p2);

        // A minimal space in memory is always allocated,
        // even if the requested size is zero.
        // In other words, a handle to the new instance is always returned.
        *a = (void*) malloc((size_t) ma);

        // Initialise array elements with null pointer.
        memset(*a, *NUMBER_0_INTEGER_MEMORY_MODEL, ma);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate array. The array is null.");
    }
}

/**
 * Deallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 * @param p2 the array type
 */
void deallocate_array(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** a = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate array.");

        free(*a);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate array. The array is null.");
    }
}

/**
 * Reallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the array type
 */
void reallocate_array(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* ac = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** a = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reallocate array.");

                // The memory area to be allocated.
                int ma = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Calculate memory area depending on given array type.
                calculate_area((void*) &ma, p2, p3);

                // Create a new array with extended size.
                *a = (void*) realloc(*a, (size_t) ma);

                // The NEW memory area to be initialised.
                int nma = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (*as >= *ac) {

                    // CAUTION! Do NOT change this value if the size is
                    // smaller than the count, because this will result
                    // in a negative value and cause the new array elements
                    // pointer further below to cross the array's boundary!

                    // Calculate extra array size, which is the given array size
                    // reduced by the existing element count.
                    int eas = *as - *ac;

                    // Calculate new memory area depending on given array type.
                    calculate_area((void*) &nma, (void*) &eas, p3);
                }

                // The new array elements.
                void* na = *a + (ma - nma);

                // Initialise ONLY NEW array elements (new memory area)
                // with null pointer. Leave existing elements untouched.
                memset(na, *NUMBER_0_INTEGER_MEMORY_MODEL, nma);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The array count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The array size is null.");
    }
}

/**
 * Compares the array elements.
 *
 * Returns the number one if the array elements are equal;
 * leaves the given result parameter unchanged, otherwise.
 *
 * @param p0 the result (Hand over as reference!)
 * @param p1 the first array
 * @param p2 the second array
 * @param p3 the array count
 * @param p4 the array type
 */
void compare_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ac = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array elements.");

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The memory area.
                    int ma = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The comparison result.
                    int r2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *ac) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            break;
                        }

                        // Calculate memory area depending on given array type.
                        calculate_area((void*) &ma, (void*) &j, p4);

                        // Reset comparison result.
                        r2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        compare((void*) &r2, p1, p2, (void*) &ma, p4);

                        if (r2 == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements. The result is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements. The first array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements. The second array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements. The array count is null.");
    }
}

/**
 * Sets the array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements
 * @param p3 the elements count
 * @param p4 the array type
 */
void set_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p3;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set array elements.");

            // The offset.
            int o = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The destination base.
            // CAUTION! It HAS TO BE initialised with p0,
            // since an offset is added to it below.
            void* db = p0;
            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Calculate offset depending on given array type.
            calculate_area((void*) &o, p1, p4);
            add_integer((void*) &db, (void*) &o, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *sc) {

                    break;
                }

                assign_area_with_offset(db, p2, (void*) &j, p4);

                j++;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set array elements. The array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set array elements. The elements count is null.");
    }
}

/**
 * Removes the array elements.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the index
 * @param p3 the elements count
 * @param p4 the array type
 */
void remove_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* as = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Remove array elements.");

                // The destination offset.
                int dos = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The source offset.
                int sos = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Calculate destination offset depending on given array type.
                calculate_area((void*) &dos, p2, p4);
                // Calculate source offset depending on given array type.
                calculate_area((void*) &sos, p3, p4);

                // The destination.
                // CAUTION! It HAS TO BE initialised with p0,
                // since an offset is added to it below.
                void* d = p0;

                // Add offset to destination.
                add_integer((void*) &d, (void*) &dos, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                // The source.
                // CAUTION! It HAS TO BE initialised with d,
                // AFTER the offset has been added to d above,
                // since an offset is added to it below.
                void* s = d;

                // Add offset to source.
                add_integer((void*) &s, (void*) &sos, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                // The subtrahend.
                // CAUTION! It HAS TO BE initialised with *i,
                // since an offset is added to it below.
                int sub = *i;

                // Add elements count to subtrahend.
                add_integer((void*) &sub, p3, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

                // The remaining elements size.
                // CAUTION! It HAS TO BE initialised with *as,
                // since an offset is added to it below.
                int r = *as;

                // Subtract subtrahend from array size.
                subtract_integer((void*) &r, (void*) &sub, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

                // The loop variable.
                int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Starting from the given index, move all remaining elements
                // one place towards the beginning of the elements.
                //
                // Example: "test..array"
                // maxcount = 11
                // index = 4 (remove "..")
                // count = 2
                // rest = 11 - (4 + 2) = 11 - 6 = 5
                //
                // Finally, all remaining elements are moved by
                // "element count" places towards the beginning of the array.
                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (j >= r) {

                        break;
                    }

                    assign_area_with_offset(d, s, (void*) &j, p4);

                    j++;
                }

                // There is no need to set the former last elements to 0.
                // The calling procedure may just cut off the remaining
                // elements by decreasing the array size (resizing).

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove array elements. The array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove array elements. The array size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove array elements. The index is null.");
    }
}

/**
 * Gets the destination array elements from the source array starting at index.
 *
 * @param p0 the destination elements (Hand over as array reference!)
 * @param p1 the source array
 * @param p2 the index
 * @param p3 the array type
 */
void get_array_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get array elements.");

            // The offset.
            int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Calculate offset depending on given array type.
            calculate_area((void*) &o, p2, p3);

            // The destination elements.
            // CAUTION! It HAS TO BE initialised with p1,
            // since an offset is added to it below.
            *d = p1;

            // Add offset to destination elements.
            add_integer(p0, (void*) &o, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements. The destination elements is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements. The source array is null.");
    }
}

/**
 * Gets the array elements index.
 *
 * Returns the index if the array elements could be found;
 * leaves the given index parameter unchanged, otherwise.
 * Only the first occurence of the elements is considered.
 *
 * @param p0 the index (Hand over as reference!)
 * @param p1 the array
 * @param p2 the array count
 * @param p3 the elements
 * @param p4 the elements count
 * @param p5 the array type
 */
void get_array_elements_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* ec = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ac = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* i = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get array elements index.");

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

                        get_array_elements((void*) &e, p1, (void*) &j, p5);
                        compare_array_elements((void*) &r, e, p3, p4, p5);

                        if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                            // The element has been found.
                            *i = j;

                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The index is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The array count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get array elements index. The elements count is null.");
    }
}

/* ARRAY_SOURCE */
#endif
