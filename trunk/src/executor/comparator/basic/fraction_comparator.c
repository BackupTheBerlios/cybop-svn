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

#ifndef FRACTION_COMPARATOR_SOURCE
#define FRACTION_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/fraction_memory_name.c"
#include "../../../executor/calculator/integer_multiplier/integer_integer_multiplier.c"
#include "../../../executor/comparator/basic/integer_comparator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Compares the left- with the right fraction.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 */
void compare_fraction(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare fraction.");

    // The left numerator, denominator.
    void* ln = *NULL_POINTER_MEMORY_MODEL;
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    // The right numerator, denominator.
    void* rn = *NULL_POINTER_MEMORY_MODEL;
    void* rd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination numerator, denominator.
    copy_array_forward((void*) &ln, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMERATOR_FRACTION_MEMORY_NAME);
    copy_array_forward((void*) &ld, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DENOMINATOR_FRACTION_MEMORY_NAME);
    // Get source numerator, denominator.
    copy_array_forward((void*) &rn, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMERATOR_FRACTION_MEMORY_NAME);
    copy_array_forward((void*) &rd, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DENOMINATOR_FRACTION_MEMORY_NAME);

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
                    multiply_integer_with_integer((void*) &eln, (void*) &rd);
                    multiply_integer_with_integer((void*) &ern, (void*) &ld);

                    compare_integer(p0, (void*) &eln, (void*) &ern, p3);

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare fraction. The left numerator is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare fraction. The left denominator is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare fraction. The right numerator is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare fraction. The right denominator is null.");
    }
}

/* FRACTION_COMPARATOR_SOURCE */
#endif
