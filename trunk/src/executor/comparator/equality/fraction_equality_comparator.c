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

#ifndef FRACTION_EQUALITY_COMPARATOR_SOURCE
#define FRACTION_EQUALITY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Compares two fractions for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left fraction
 * @param p2 the right fraction
 */
void compare_equal_fraction(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare fractions for equality.");

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

        // The expanded left numerator, right numerator.
        int eln = *((int*) ln);
        int ern = *((int*) rn);

        // Calculate expanded left numerator, right numerator.
        multiply_with_integer((void*) &eln, (void*) &rd, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        multiply_with_integer((void*) &ern, (void*) &ld, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

/*
        if (eln == ern) {

            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;
        }
*/
        compare_array(p0, (void*) &eln, (void*) &ern, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare fractions for equality. The result is null.");
    }
}

/* FRACTION_EQUALITY_COMPARATOR_SOURCE */
#endif
