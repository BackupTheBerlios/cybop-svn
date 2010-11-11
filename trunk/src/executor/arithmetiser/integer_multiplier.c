/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef INTEGER_MULTIPLIER_SOURCE
#define INTEGER_MULTIPLIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_multiplier/integer_integer_multiplier.c"
//?? #include "../../executor/arithmetiser/integer_multiplier/pointer_integer_multiplier.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Multiplies the destination of the given abstraction with the source integer.
 *
 * @param p0 the destination (If of type "pointer", then hand over as reference!)
 * @param p1 the source integer
 * @param p2 the abstraction
 */
void multiply_with_integer(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Multiply with integer.");

        if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1);

        } else if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

//??            multiply_pointer_with_integer(p0, p1);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not multiply with integer. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not multiply with integer. The abstraction is null.");
    }
}

/* INTEGER_MULTIPLIER_SOURCE */
#endif
