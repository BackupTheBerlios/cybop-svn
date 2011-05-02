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

#ifndef CONTAINER_COMPARATOR_SOURCE
#define CONTAINER_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/comparator/equality/primitive_equality_comparator.c"
#include "../../logger/logger.c"

//
// Models of abstraction "complex" or "fraction" are not
// considered as container, since the comparison of their
// elements follows special rules.
//
// Example:
//
// The two fractions 4 / 2 and 2 / 1 are identical even though
// their numerators and denominators differ. If the fractions
// were treated as containers and their elements compared one by one,
// then neither the numerators 4 and 2 nor the denominators 2 and 1
// would be equal.
//
// Therefore, such constructs are static and NOT treated as
// dynamic containers. The number of their elements is fixed.
// The fraction has two elements: numerator and denominator.
// It needs a special comparison function that knows how to
// treat fractions correctly.
//

/**
 * Compares one element of the left with one of the right container.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left container
 * @param p2 the right container
 * @param p3 the index
 * @param p4 the element abstraction
 * @param p5 the operation abstraction
 */
void compare_container_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // The left element.
    void** l = NULL_POINTER_MEMORY_MODEL;
    // The right element.
    void** r = NULL_POINTER_MEMORY_MODEL;

    get_element((void*) &l, (void*) &lc, (void*) &ls, p1, p3, p4);
    get_element((void*) &r, (void*) &rc, (void*) &rs, p2, p3, p4);

    compare_value(p0, *l, *r, p5, p4);
}

/**
 * Compares all elements of the given containers.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left container
 * @param p2 the right container
 * @param p3 the container count
 * @param p4 the element abstraction
 * @param p5 the operation abstraction
 */
void compare_container_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* cc = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare container elements for equality.");

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The element comparison result.
                    int er = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *cc) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            break;
                        }

                        // Reset comparison result.
                        er = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // CAUTION! This function does not change the result flag, if unequal.
                        // Therefore, the result flag always has to be initialised with 0 before,
                        // in order to reset it if a previous comparison had the result 1.
                        compare_container_element((void*) &er, p1, p2, (void*) &j, p4, p5);

                        if (er == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Stop comparison if two elements are not equal,
                            // because then the two containers are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare container elements. The result is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare container elements. The left container is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare container elements. The right container is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare container elements. The container count is null.");
    }
}

/**
 * Compares two containers.
 *
 * This procedure compares only the element counts.
 * The actual elements comparison happens in another function.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left container
 * @param p2 the left container count
 * @param p3 the right container
 * @param p4 the right container count
 * @param p5 the element abstraction
 * @param p6 the operation abstraction
 */
void compare_container(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* lc = (int*) p2;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare containers.");

            if (*lc == *rc) {

                compare_container_elements(p0, p1, p3, p4, p5, p6);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare containers. The left container count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare containers. The right container count is null.");
    }
}

/* CONTAINER_COMPARATOR_SOURCE */
#endif
