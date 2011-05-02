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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRACTION_VALUE_COMPARATOR_SOURCE
#define FRACTION_VALUE_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/value_comparator.c"
#include "../../../logger/logger.c"

/**
 * Compares the left- with the right fraction.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 */
void compare_value_fraction(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare value fraction.");

    // The left numerator, denominator.
    void* ln = *NULL_POINTER_MEMORY_MODEL;
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    // The right numerator, denominator.
    void* rn = *NULL_POINTER_MEMORY_MODEL;
    void* rd = *NULL_POINTER_MEMORY_MODEL;

    // Get left numerator, denominator.
    get((void*) &ln, p1, (void*) NUMERATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &ld, p1, (void*) DENOMINATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get right numerator, denominator.
    get((void*) &rn, p2, (void*) NUMERATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rd, p2, (void*) DENOMINATOR_FRACTION_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    if (rd != *NULL_POINTER_MEMORY_MODEL) {

        if (rn != *NULL_POINTER_MEMORY_MODEL) {

            if (ld != *NULL_POINTER_MEMORY_MODEL) {

                if (ln != *NULL_POINTER_MEMORY_MODEL) {

                    // The expanded left numerator, right numerator.
                    // CAUTION! Initialise with ln and rn, respectively,
                    // since they are multiplied with their denominators below.
                    int eln = *((int*) ln);
                    int ern = *((int*) rn);

                    // Calculate expanded left numerator, right numerator.
                    // CAUTION! Multiplicate cross-wise.
                    multiply_with_integer((void*) &eln, (void*) &rd, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
                    multiply_with_integer((void*) &ern, (void*) &ld, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                    compare_value(p0, (void*) &eln, (void*) &ern, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare value fraction. The left numerator is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare value fraction. The left denominator is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare value fraction. The right numerator is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare value fraction. The right denominator is null.");
    }
}

/* FRACTION_VALUE_COMPARATOR_SOURCE */
#endif
