/*
 * $RCSfile: add_character_vector.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
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
 *
 * @version $Revision: 1.9 $ $Date: 2008-05-04 00:18:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_CHARACTER_VECTOR_SOURCE
#define ADD_CHARACTER_VECTOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

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

    if (p6 != *NULL_POINTER) {

        int* s2c = (int*) p6;

        if (p4 != *NULL_POINTER) {

            int* s1c = (int*) p4;

            if (p2 != *NULL_POINTER) {

                int* ss = (int*) p2;

                if (p1 != *NULL_POINTER) {

                    int* sc = (int*) p1;

                    if (p0 != *NULL_POINTER) {

                        void** s = (void**) p0;

                        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Add character vectors.");

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
                        void* summand1 = *NULL_POINTER;
                        int summand1c = *s1c;
                        // The summand 2.
                        void* summand2 = *NULL_POINTER;
                        int summand2c = *s2c;

                        // Allocate temporary input operand arrays.
                        allocate_array((void*) &summand1, (void*) &summand1c, (void*) CHARACTER_ARRAY);
                        allocate_array((void*) &summand2, (void*) &summand2c, (void*) CHARACTER_ARRAY);

                        // Set temporary input operand arrays.
                        set_array_elements(summand1, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);
                        set_array_elements(summand2, (void*) NUMBER_0_INTEGER, p5, p6, (void*) CHARACTER_ARRAY);

                        // CAUTION! In order to achieve correct results,
                        // the sum array needs to be resized to the exact size
                        // of summand 1 count and summand 2 count added together!
                        // If the sum array got a greater size than needed,
                        // unpredictable results might occur when using it for
                        // comparison with other strings, for example.
                        *ss = summand1c + summand2c;
                        *sc = *NUMBER_0_INTEGER;

                        // Reallocate output operand array.
                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                        // Set output operand array.
                        set_array_elements(*s, (void*) sc, summand1, (void*) &summand1c, (void*) CHARACTER_ARRAY);
                        *sc = *sc + summand1c;
                        set_array_elements(*s, (void*) sc, summand2, (void*) &summand2c, (void*) CHARACTER_ARRAY);
                        *sc = *sc + summand2c;

                        // Deallocate temporary operand arrays.
                        deallocate_array((void*) &summand1, (void*) &summand1c, (void*) CHARACTER_ARRAY);
                        deallocate_array((void*) &summand2, (void*) &summand2c, (void*) CHARACTER_ARRAY);

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not add character vectors. The sum is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not add character vectors. The sum count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not add character vectors. The sum size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not add character vectors. The summand 1 count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not add character vectors. The summand 2 count is null.");
    }
}

/* ADD_CHARACTER_VECTOR_SOURCE */
#endif
