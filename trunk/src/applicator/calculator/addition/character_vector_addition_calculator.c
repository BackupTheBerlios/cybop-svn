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
 * @version $RCSfile: character_vector_addition_calculator.c,v $ $Revision: 1.3 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_VECTOR_ADDER_SOURCE
#define CHARACTER_VECTOR_ADDER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/array.c"

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
void add_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

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

                        // The summand 1.
                        void* summand1 = *NULL_POINTER_MEMORY_MODEL;
                        int summand1c = *s1c;
                        // The summand 2.
                        void* summand2 = *NULL_POINTER_MEMORY_MODEL;
                        int summand2c = *s2c;

                        // Allocate temporary input operand arrays.
                        allocate_array((void*) &summand1, (void*) &summand1c, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                        allocate_array((void*) &summand2, (void*) &summand2c, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        // Set temporary input operand arrays.
                        set_array_elements(summand1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                        set_array_elements(summand2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p5, p6, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        // CAUTION! In order to achieve correct results,
                        // the sum array needs to be resized to the exact size
                        // of summand 1 count and summand 2 count added together!
                        // If the sum array got a greater size than needed,
                        // unpredictable results might occur when using it for
                        // comparison with other strings, for example.
                        *ss = summand1c + summand2c;
                        *sc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Reallocate output operand array.
                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        // Set output operand array.
                        set_array_elements(*s, (void*) sc, summand1, (void*) &summand1c, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                        *sc = *sc + summand1c;
                        set_array_elements(*s, (void*) sc, summand2, (void*) &summand2c, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                        *sc = *sc + summand2c;

                        // Deallocate temporary operand arrays.
                        deallocate_array((void*) &summand1, (void*) &summand1c, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                        deallocate_array((void*) &summand2, (void*) &summand2c, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

/* CHARACTER_VECTOR_ADDER_SOURCE */
#endif
