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
 * @version $RCSfile: adder.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_INTEGER_ADDER_SOURCE
#define LOG_INTEGER_ADDER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/arithmetiser/integer_adder/log_integer_integer_adder.c"
#include "../../logger/arithmetiser/integer_adder/log_pointer_integer_adder.c"

/**
 * Adds the source integer to the destination of the given abstraction.
 *
 * @param p0 the destination (If of type "pointer", then hand over as reference!)
 * @param p1 the source integer
 * @param p2 the abstraction
 */
void log_add_integer(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p2;

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.

        if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_add_integer_to_integer(p0, p1);

        } else if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_add_integer_to_pointer(p0, p1);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            // "Could not add integer. The abstraction is unknown."
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not add integer. The abstraction is null."
    }
}

/* LOG_INTEGER_ADDER_SOURCE */
#endif
