/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: greaterness_or_equality_comparator.c.c,v $ $Revision: 1.3 $ $Date: 2008-09-06 23:17:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GREATERNESS_OR_EQUALITY_COMPARATOR_SOURCE
#define GREATERNESS_OR_EQUALITY_COMPARATOR_SOURCE

#include "../../globals/constants/boolean/boolean_constants.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Compares if the left parameter is greater than or equal to the right parameter.
 *
 * The result parameter's abstraction must be BOOLEAN.
 * The left side- and right side parameters' abstractions have to be equal.
 * They can be one of:
 * - CHARACTER
 * - INTEGER
 * - DOUBLE
 *
 * @param p0 the left side parameter abstraction
 * @param p1 the left side parameter abstraction count
 * @param p2 the left side parameter abstraction size
 * @param p3 the left side parameter model
 * @param p4 the left side parameter model count
 * @param p5 the left side parameter model size
 * @param p6 the left side parameter details
 * @param p7 the left side parameter details count
 * @param p8 the left side parameter details size
 * @param p9 the right side parameter abstraction
 * @param p10 the right side parameter abstraction count
 * @param p11 the right side parameter abstraction size
 * @param p12 the right side parameter model
 * @param p13 the right side parameter model count
 * @param p14 the right side parameter model size
 * @param p15 the right side parameter details
 * @param p16 the right side parameter details count
 * @param p17 the right side parameter details size
 * @param p18 the result parameter abstraction
 * @param p19 the result parameter abstraction count
 * @param p20 the result parameter abstraction size
 * @param p21 the result parameter model
 * @param p22 the result parameter model count
 * @param p23 the result parameter model size
 * @param p24 the result parameter details
 * @param p25 the result parameter details count
 * @param p26 the result parameter details size
 */
void compare_greater_or_equal(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14,
    void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20,
    void* p21, void* p22, void* p23,
    void* p24, void* p25, void* p26) {

    if (p21 != *NULL_POINTER_MEMORY_MODEL) {

        int* rm = (int*) p21;

        if (p12 != *NULL_POINTER_MEMORY_MODEL) {

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare if one parameter is greater than or equal to the other.");

                // The result parameter comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Compare result parameter abstraction. It must be a boolean.
                compare_arrays(p18, p19, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The left side parameter comparison result.
                    int lr;
                    // The right side parameter comparison result.
                    int rr;

                    //
                    // Character parameters.
                    //

                    // Reset parameter comparison results.
                    lr = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    rr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Compare parameter abstractions.
                    compare_arrays(p0, p1, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &lr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    compare_arrays(p9, p10, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &rr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if ((lr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (rr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Use character parameters.");

                        if (*((wchar_t*) p3) >= *((wchar_t*) p12)) {

                            *rm = *TRUE_BOOLEAN;

                        } else {

                            *rm = *FALSE_BOOLEAN;
                        }
                    }

                    //
                    // Integer parameters.
                    //

                    // Reset parameter comparison results.
                    lr = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    rr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Compare parameter abstractions.
                    compare_arrays(p0, p1, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &lr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    compare_arrays(p9, p10, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &rr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if ((lr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (rr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Use integer parameters.");

                        if (*((int*) p3) >= *((int*) p12)) {

                            *rm = *TRUE_BOOLEAN;

                        } else {

                            *rm = *FALSE_BOOLEAN;
                        }
                    }

                    //
                    // Double parameters.
                    //

                    // Reset parameter comparison results.
                    lr = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    rr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Compare parameter abstractions.
                    compare_arrays(p0, p1, (void*) DOUBLE_VECTOR_MEMORY_ABSTRACTION, (void*) DOUBLE_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &lr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    compare_arrays(p9, p10, (void*) DOUBLE_VECTOR_MEMORY_ABSTRACTION, (void*) DOUBLE_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &rr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if ((lr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (rr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Use double parameters.");

                        if (*((double*) p3) >= *((double*) p12)) {

                            *rm = *TRUE_BOOLEAN;

                        } else {

                            *rm = *FALSE_BOOLEAN;
                        }
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare if one parameter is greater than or equal to the other. The result parameter is not a boolean.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare if one parameter is greater than or equal to the other. The left side parameter is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare if one parameter is greater than or equal to the other. The right side parameter is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare if one parameter is greater than or equal to the other. The result parameter is null.");
    }
}

/* GREATERNESS_OR_EQUALITY_COMPARATOR_SOURCE */
#endif
