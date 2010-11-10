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

#ifndef LOG_SIZE_DETERMINER_SOURCE
#define LOG_SIZE_DETERMINER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/accessor/assigner/log_integer_assigner.c"
#include "../../variable/primitive_type_size.c"

/**
 * Determines the size of the given abstraction.
 *
 * @param p0 the size
 * @param p1 the abstraction
 */
void log_determine_size(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p1;

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not determine size. The abstraction is null."

        if (*a == *CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_assign_integer(p0, (void*) CHARACTER_PRIMITIVE_SIZE);

        } else if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_assign_integer(p0, (void*) DOUBLE_PRIMITIVE_SIZE);

        } else if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_assign_integer(p0, (void*) INTEGER_PRIMITIVE_SIZE);

        } else if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_assign_integer(p0, (void*) POINTER_PRIMITIVE_SIZE);

        } else if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_assign_integer(p0, (void*) UNSIGNED_LONG_PRIMITIVE_SIZE);

        } else if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            log_assign_integer(p0, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            // "Could not determine size. The abstraction is unknown."
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not determine size. The abstraction is null."
    }
}

/* LOG_SIZE_DETERMINER_SOURCE */
#endif
