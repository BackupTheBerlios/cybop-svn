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
 * @version $RCSfile: character_vector_addition_calculator.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_VECTOR_ADDITION_CALCULATOR_SOURCE
#define CHARACTER_VECTOR_ADDITION_CALCULATOR_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../logger/logger.c"

/**
 * Adds two character vectors.
 *
 * @param p0 the sum (Hand over as reference!)
 * @param p1 the sum count
 * @param p2 the sum size
 * @param p3 the summand 1
 * @param p4 the summand 1 count
 * @param p5 the summand 2
 * @param p6 the summand 2 count
 */
void calculate_addition_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

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

                        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Add character vectors.");

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
                        void* summand1c = *NULL_POINTER_MEMORY_MODEL;
                        void* summand1s = *NULL_POINTER_MEMORY_MODEL;
                        // The summand 2 vector.
                        void* summand2 = *NULL_POINTER_MEMORY_MODEL;
                        void* summand2c = *NULL_POINTER_MEMORY_MODEL;
                        void* summand2s = *NULL_POINTER_MEMORY_MODEL;

                        // Allocate temporary input operand arrays.
                        allocate_model((void*) &summand1, (void*) &summand1c, (void*) &summand1s, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
                        allocate_model((void*) &summand2, (void*) &summand2c, (void*) &summand2s, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

                        // Set temporary input operand arrays.
                        replace_array(summand1, p3, p4, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                        *((int*) summand1c) = *((int*) p4);
                        replace_array(summand2, p5, p6, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                        *((int*) summand2c) = *((int*) p6);

                        // CAUTION! In order to achieve correct results,
                        // the sum array needs to be resized to the exact size
                        // of summand 1 count and summand 2 count added together!
                        // If the sum array got a greater size than needed,
                        // unpredictable results might occur when using it for
                        // comparison with other strings, for example.
                        *ss = *((int*) summand1c) + *((int*) summand2c);
                        *sc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Reallocate output operand array.
                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                        // Set output operand array.
                        replace_array(*s, summand1, summand1c, (void*) sc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                        *sc = *sc + *((int*) summand1c);
                        replace_array(*s, summand2, summand2c, (void*) sc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
                        *sc = *sc + *((int*) summand2c);

                        // Deallocate temporary operand arrays.
                        deallocate_model((void*) &summand1, (void*) &summand1c, (void*) &summand1s, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
                        deallocate_model((void*) &summand2, (void*) &summand2c, (void*) &summand2s, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add character vectors. The sum is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add character vectors. The sum count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add character vectors. The sum size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add character vectors. The summand 1 count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add character vectors. The summand 2 count is null.");
    }
}

/* CHARACTER_VECTOR_ADDITION_CALCULATOR_SOURCE */
#endif
