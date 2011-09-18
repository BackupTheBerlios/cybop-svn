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

#ifndef LOG_INTEGER_INTEGER_MULTIPLIER_SOURCE
#define LOG_INTEGER_INTEGER_MULTIPLIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/arithmetiser/integer_adder/log_integer_integer_adder.c"

/**
 * Multiplies the destination integer with the source integer.
 *
 * @param p0 the destination integer
 * @param p1 the source integer
 */
void log_calculate_integer_multiply(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            int* d = (int*) p0;

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.

            //?? For reasons of performance, the standard multiplication operator *
            //?? is used here, instead of looping and adding values manually (like below),
            //?? which would be very slow and not so efficient.
            *d = *d * (*s);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            // "Could not multiply integer with integer. The destination is null."
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not multiply integer with integer. The source is null."
    }
}

/* LOG_INTEGER_INTEGER_MULTIPLIER_SOURCE */
#endif
