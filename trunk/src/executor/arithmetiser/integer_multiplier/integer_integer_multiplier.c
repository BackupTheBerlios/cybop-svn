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
 * @version $RCSfile: multiplier.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_INTEGER_MULTIPLIER_SOURCE
#define INTEGER_INTEGER_MULTIPLIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder/integer_integer_adder.c"
#include "../../../logger/logger.c"

/**
 * Multiplies the destination integer with the source integer.
 *
 * @param p0 the destination integer
 * @param p1 the source integer
 */
void multiply_integer_with_integer(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            int* d = (int*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Multiply integer with integer.");

            //?? For reasons of performance, the standard multiplication operator *
            //?? is used here, instead of looping and adding values manually (like below),
            //?? which would be very slow and not so efficient.
            *d = *d * (*s);

/*??
            // The product.
            // This variable is necessary, since stepwise adding to
            // the destination itself would increment the summand
            // and thus deliver a false result.
            int p = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*TRUE_BOOLEAN_MEMORY_MODEL) {

                if (j >= *s) {

                    break;
                }

                // Add original destination value to destination repeatedly,
                // as many times as specified by the source.
                add_integer_to_integer((void*) &p, p0);

                // Increment loop variable.
                j++;
            }

            // Assign result to destination.
            *d = p;
*/

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not multiply integer with integer. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not multiply integer with integer. The source is null.");
    }
}

/* INTEGER_INTEGER_MULTIPLIER_SOURCE */
#endif
