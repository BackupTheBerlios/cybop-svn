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
 * @version $RCSfile: integer_adder.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REDUCE_FRACTION_CALCULATOR_SOURCE
#define REDUCE_FRACTION_CALCULATOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"

/**
 * Reduces the fraction.
 *
 * @param p0 the fraction
 */
void calculate_fraction_reduce(void* p0) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate fraction reduce.");

    // The numerator and denominator.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* d = *NULL_POINTER_MEMORY_MODEL;

    // Get numerator and denominator.
    copy_array_forward((void*) &n, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMERATOR_FRACTION_MEMORY_NAME);
    copy_array_forward((void*) &d, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DENOMINATOR_FRACTION_MEMORY_NAME);

    // The result numerator and denominator.
    int rn = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int rd = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine absolute values.
    calculate_integer_absolute((void*) &rn, n);
    calculate_integer_absolute((void*) &rd, d);

    if ((rn > *NUMBER_1_INTEGER_MEMORY_MODEL) && (rd > *NUMBER_1_INTEGER_MEMORY_MODEL)) {

        // The loop variable.
        int i = rn;

        if (rd > i) {

            i = rd;
        }

        // The remainder of the numerator and denominator.
        int remn = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int remd = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Search numerator and denominator having a common factor
        // delivering an integral number as result (no remainder).
        // Start at the largest of both.
        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (i <= *NUMBER_1_INTEGER_MEMORY_MODEL) {

                break;
            }

            remn = rn % i;
            remd = rd % i;

            if ((remn == *NUMBER_0_INTEGER_MEMORY_MODEL) && (remd == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                //
                // If both, the numerator and the denominator have been
                // divided successfully without leaving a remainder,
                // then the lowest common denominator has been found.
                //
                // Synonyms:
                // - lowest common denominator [kleinster gemeinsamer Nenner]
                // - least common factor (LCF) [kleinster gemeinsamer Teiler]
                //

                rn = int(rn / i);
                rd = int(rd / i);
            }

            // Decrement loop variable.
            i--;
        }
    }

    // Copy result numerator and denominator to fraction.
    copy_integer(n, (void*) &rn);
    copy_integer(d, (void*) &rd);

    //
    // Correct sign by setting it back to the original value + or -.
    //

    // The comparison results.
    int r1 = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int r2 = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_integer_smaller((void*) &r1, n, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
    compare_integer_smaller((void*) &r2, d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    if (r1 != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        calculate_integer_negate((void*) &rn, (void*) &rn);
    }

    if (r2 != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        calculate_integer_negate((void*) &rd, (void*) &rd);
    }
}

/* REDUCE_FRACTION_CALCULATOR_SOURCE */
#endif
