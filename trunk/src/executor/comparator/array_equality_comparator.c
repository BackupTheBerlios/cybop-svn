/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef ARRAY_EQUALITY_COMPARATOR_SOURCE
#define ARRAY_EQUALITY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/comparator/equality_comparator.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Compares the array elements for equality.
 *
 * Returns the number one if the array elements are equal;
 * leaves the given result parameter unchanged, otherwise.
 *
 * @param p0 the result (Hand over as reference!)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the array count
 * @param p4 the primitive abstraction
 */
void compare_equal_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ac = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array elements for equality.");

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The type size.
                    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The offset.
                    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The comparison result.
                    int r2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Determine type size.
                    determine_size((void*) &s, p4);

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *ac) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            break;
                        }

                        // Reset offset to type size.
                        o = s;

                        // Calculate offset.
                        multiply_with_integer((void*) &o, (void*) &j, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                        // Reset comparison result.
                        r2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // CAUTION! This function does not change the result flag, if unequal.
                        // Therefore, the result flag always has to be initialised with zero before!
                        compare_equal_with_offset((void*) &r2, p1, p2, p4, (void*) &o);

                        if (r2 == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements for equality. The result is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements for equality. The left array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements for equality. The right array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements for equality. The array count is null.");
    }
}

/**
 * Compares the arrays for equality.
 *
 * This procedure compares only the element counts of both arrays.
 * The actual elements comparison happens in compare_array_elements.
 *
 * @param p0 the result (Hand over as reference!)
 * @param p1 the left array
 * @param p2 the left array count
 * @param p3 the right array
 * @param p4 the right array count
 * @param p5 the primitive abstraction
 */
void compare_equal_arrays(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* lc = (int*) p2;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare arrays for equality.");

            if (*lc == *rc) {

                compare_equal_array_elements(p0, p1, p3, p4, p5);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare arrays for equality. The left array count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare arrays for equality. The right array count is null.");
    }
}

/* ARRAY_EQUALITY_COMPARATOR_SOURCE */
#endif
