/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef ARRAY_REALLOCATOR_SOURCE
#define ARRAY_REALLOCATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Reallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the count
 * @param p2 the size
 * @param p3 the abstraction
 */
void reallocate_array(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* c = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** a = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reallocate array.");

                // The memory area.
                int ma = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Determine abstraction (type) size.
                determine_size((void*) &ma, p3);

                // Calculate memory area.
                multiply_with_integer((void*) &ma, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (ma > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    //
                    // CAUTION! The memory area (new array size)
                    // MUST NOT be zero or smaller!
                    // If it were equal to zero, then the "realloc"
                    // function call would be equivalent to "free" --
                    // an unwanted side effect that would destroy
                    // allocated memory areas and lead to errors.
                    // Therefore, that case is excluded by this condition.
                    //

                    // Create a new array with extended size.
                    //
                    // Since the space after the end of the block may be in use,
                    // realloc may find it necessary to copy the block to a
                    // new address where more free space is available.
                    // The value of realloc is the new address of the block.
                    // If the block needs to be moved, realloc copies the old contents.
                    //
                    // CAUTION! The "ma" variable MAY NOT be casted to "size_t",
                    // because it is NOT a pointer, but an integer value!
                    *a = realloc(*a, ma);

                    if (*s > *c) {

                        // CAUTION! If count and size are equal, then nothing
                        // is to be done.
                        // CAUTION! Do NOT change this value if the size is
                        // smaller than the count, because this will result
                        // in a negative value and cause the new array elements
                        // pointer further below to cross the array's boundary!

                        // The NEW memory area to be initialised.
                        int nma = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Calculate extra array size, which is the given array size
                        // reduced by the existing element count.
                        int es = *s - *c;

                        // Determine abstraction (type) size.
                        determine_size((void*) &nma, p3);

                        // Calculate new memory area.
                        multiply_with_integer((void*) &nma, (void*) &es, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                        // The new array elements.
                        void* na = *a + (ma - nma);

                        // Initialise ONLY NEW array elements (new memory area)
                        // with null pointer. Leave existing elements untouched.
                        memset(na, *NUMBER_0_INTEGER_MEMORY_MODEL, nma);
                    }

                } else {

                    log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The memory area is not greater than zero.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array. The size is null.");
    }
}

/**
 * Reallocates the array so that there is place for exactly
 * as many elements as required.
 *
 * The number of required elements is determined as:
 * count of currently contained elements + additional count of new elements to be added
 *
 * If the current size is big enough to also store all new elements,
 * then nothing is done here, i.e. no reallocation will happen.
 *
 * This function is intended to be used when memory space matters,
 * but time does not. The memory usage is limited to a minimum,
 * but processing time may increase, since for each single element
 * to be added, a new memory area needs to be found.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the count
 * @param p2 the size
 * @param p3 the abstraction
 * @param p4 the additional count
 */
void reallocate_array_exact(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* ac = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* s = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* c = (int*) p1;

                // The new count.
                int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Add count to new count.
                add_integer((void*) &n, p1, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                // Add additional count to new count.
                add_integer((void*) &n, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                if (n > *s) {

                    // Reallocate array using new count as size.
                    reallocate_array(p0, p1, (void*) &n, p3);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array exact. The count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array exact. The size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array exact. The additional count is null.");
    }
}

/**
 * Reallocates the array so that there is place for at least
 * as many elements as required, or more.
 *
 * The number of required elements is determined as:
 * (count of currently contained elements + additional count of new elements to be added) * factor
 *
 * If the current size is big enough to also store all new elements,
 * then nothing is done here, i.e. no reallocation will happen.
 *
 * This function is intended to be used when performance matters,
 * but memory does not. The processing time is limited to a minimum,
 * since reallocation uses a factor and thus allocates more memory
 * than actually needed. That way, new elements may be added
 * without having to reallocate the array for each single element.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the count
 * @param p2 the size
 * @param p3 the abstraction
 * @param p4 the additional count
 * @param p5 the factor
 */
void reallocate_array_estimated(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* f = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* ac = (int*) p4;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* s = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* c = (int*) p1;

                    // The new count.
                    int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Add count to new count.
                    add_integer((void*) &n, p1, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                    // Add additional count to new count.
                    add_integer((void*) &n, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                    // Multiply new count with factor.
                    multiply_with_integer((void*) &n, p5, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (n > *s) {

                        // Reallocate array using new count as size.
                        reallocate_array(p0, p1, (void*) &n, p3);
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array estimated. The count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array exact. The size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array estimated. The additional count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate array estimated. The factor is null.");
    }
}

/* ARRAY_REALLOCATOR_SOURCE */
#endif
