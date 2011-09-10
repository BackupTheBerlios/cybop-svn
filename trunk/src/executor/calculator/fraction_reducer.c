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

#ifndef FRACTION_REDUCER_SOURCE
#define FRACTION_REDUCER_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"

/**
 * Reduces the fraction.
 *
 * @param p0 the fraction
 */
void reduce_fraction(void* p0) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reduce fraction.");

    // The numerator and denominator.
    int n = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int d = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get numerator and denominator.
    get((void*) &n, p1, (void*) NUMERATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &d, p1, (void*) DENOMINATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The result numerator and denominator.
    int rn = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int rd = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine absolute values.
    int rn = abs(n);
    int rd = abs(d);

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

    //
    // Correct sign by setting it back to the original value + or -.
    //

    if (n < *NUMBER_0_INTEGER_MEMORY_MODEL) {

        rn = rn * *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    }

    if (d < *NUMBER_0_INTEGER_MEMORY_MODEL) {

        rd = rd * *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    }
}

/* FRACTION_REDUCER_SOURCE */
#endif
