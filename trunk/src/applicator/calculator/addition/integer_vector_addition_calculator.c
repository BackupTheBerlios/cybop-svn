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
 * @version $RCSfile: integer_vector_addition_calculator.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:03:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_ADDER_SOURCE
#define INTEGER_VECTOR_ADDER_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Adds two integer vectors.
 *
 * @param p0 the sum (Hand over as reference!)
 * @param p1 the sum count
 * @param p2 the sum size
 * @param p3 the summand 1
 * @param p4 the summand 1 count
 * @param p5 the summand 2
 * @param p6 the summand 2 count
 */
void add_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* s2c = (int*) p6;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* s1c = (int*) p4;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ss = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* sc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        void** s = (void**) p0;

                        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Add integer vectors.");

                        // CAUTION! STORE ALL INPUT operands in temporary variables!
                        // In the possible case that an input operand pointer
                        // points to the same operand as the output pointer
                        // (or even ALL operands reference the same resource),
                        // it is important to leave the input operands untouched
                        // until the operation has been executed completely.
                        // Otherwise, when writing the result into an output operand,
                        // the input operand would be overwritten at the same time,
                        // as both are pointing to the same operand.

                        // The summand 1 vector.
                        void* summand1 = *NULL_POINTER_MEMORY_MODEL;
                        int summand1c = *s1c;
                        // The summand 2 vector.
                        void* summand2 = *NULL_POINTER_MEMORY_MODEL;
                        int summand2c = *s2c;

                        // Allocate temporary input operand arrays.
                        allocate_array((void*) &summand1, (void*) &summand1c, (void*) INTEGER_ARRAY);
                        allocate_array((void*) &summand2, (void*) &summand2c, (void*) INTEGER_ARRAY);

                        // Set temporary input operand arrays.
                        set_array_elements(summand1, (void*) NUMBER_0_INTEGER, p3, p4, (void*) INTEGER_ARRAY);
                        set_array_elements(summand2, (void*) NUMBER_0_INTEGER, p5, p6, (void*) INTEGER_ARRAY);

                        // CAUTION! In order to achieve correct results,
                        // the sum array needs to be resized to the exact size
                        // of the summand with the SMALLER count!
                        // Otherwise, the array borders of the summand with the
                        // smaller count would be crossed.
                        if (summand1c < summand2c) {

                            *ss = summand1c;

                        } else {

                            *ss = summand2c;
                        }

                        // The sum count serves as loop count below.
                        *sc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Reallocate output operand array.
                        reallocate_array(p0, p1, p2, (void*) INTEGER_ARRAY);

                        // The temporary summand 1 vector element.
                        int* tmps1 = (int*) *NULL_POINTER_MEMORY_MODEL;
                        // The temporary summand 2 vector element.
                        int* tmps2 = (int*) *NULL_POINTER_MEMORY_MODEL;
                        // The temporary sum vector element.
                        int tmps = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        while (*NUMBER_1_INTEGER) {

                            if (*sc >= *ss) {

                                break;
                            }

                            // The parameter p1 is the sum count, which serves as
                            // index that gets incremented in every loop cycle.
                            get_array_elements(summand1, p1, (void*) &tmps1, (void*) INTEGER_ARRAY);
                            get_array_elements(summand2, p1, (void*) &tmps2, (void*) INTEGER_ARRAY);

                            // Calculate temporary sum.
                            tmps = *tmps1 + *tmps2;

                            // Set output operand array.
                            set_array_elements(*s, p1, (void*) &tmps, (void*) PRIMITIVE_COUNT, (void*) INTEGER_ARRAY);

                            (*sc)++;
                        }

                        // Deallocate temporary operand arrays.
                        deallocate_array((void*) &summand1, (void*) &summand1c, (void*) INTEGER_ARRAY);
                        deallocate_array((void*) &summand2, (void*) &summand2c, (void*) INTEGER_ARRAY);

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add integer vectors. The sum is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add integer vectors. The sum count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add integer vectors. The sum size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add integer vectors. The summand 1 count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add integer vectors. The summand 2 count is null.");
    }
}

/* INTEGER_VECTOR_ADDER_SOURCE */
#endif
