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
 * @version $RCSfile: comparator.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_COMPARATOR_SOURCE
#define ARRAY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/comparator/element_equality_comparator.c"
#include "../../../logger/logger.c"

/**
 * Compares one element of the left with one of the right array for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the index
 * @param p4 the primitive abstraction
 */
void compare_equal_array_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The type size.
    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine type size.
    determine_size((void*) &s, p4);

    // The offset.
    // Initialise offset with type size, since it is used as
    // first factor and result of the multiplication below.
    int o = s;

    // Calculate offset.
    multiply_with_integer((void*) &o, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // The left element.
    // CAUTION! It HAS TO BE initialised with p1,
    // since an offset is added to it below.
    void* le = p1;
    // The right element.
    // CAUTION! It HAS TO BE initialised with p2,
    // since an offset is added to it below.
    void* re = p2;

    // Add offset to left element.
    add_integer((void*) &le, (void*) &o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Add offset to right element.
    add_integer((void*) &re, (void*) &o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    compare_equal_element(p0, le, re, p4);
}

/**
 * Compares the left- with the right array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the array count
 * @param p4 the array index
 * @param p5 the operand abstraction
 * @param p6 the operand abstraction count
 * @param p7 the operation abstraction
 * @param p8 the operation abstraction count
 */
void compare_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array.");

                    // The left array, right array.
                    // CAUTION! They HAVE TO BE initialised with p1 and p2,
                    // since an offset is added below.
                    void* l = p1;
                    void* r = p2;

                    // The offset (memory area).
                    int os = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Determine abstraction (type) size.
                    determine_size((void*) &os, p5, p6);

                    // Calculate offset.
                    multiply_with_integer((void*) &os, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                    // Add offset to left array, right array.
                    add_integer((void*) &l, (void*) &os, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    add_integer((void*) &r, (void*) &os, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The value comparison result.
                    int vr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *c) {

                            // All elements have been compared.
                            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            break;
                        }

                        // Reset value comparison result.
                        vr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // CAUTION! This function does not change the result flag, if unequal.
                        // Therefore, the result flag always has to be initialised with zero before!
                        compare_value_offset((void*) &vr, l, r, (void*) &j, p5, p6, p7, p8);

                        if (vr == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Stop comparison if two elements are not equal,
                            // because then the two arrays are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array. The result is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array. The left array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array. The right array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array. The array count is null.");
    }
}

/**
 * Compares two arrays for equality.
 *
 * This procedure compares only the element counts.
 * The actual elements comparison happens in another function.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the left array count
 * @param p3 the right array
 * @param p4 the right array count
 * @param p5 the primitive abstraction
 */
void compare_equal_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

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

/* ARRAY_COMPARATOR_SOURCE */
#endif
