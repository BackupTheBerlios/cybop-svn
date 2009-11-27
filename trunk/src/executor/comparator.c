/*
 * Copyright (C) 1999-2009. Christian Heller.
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

#ifndef COMPARATOR_SOURCE
#define COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Compares values.
 *
 * @param p0 the result (number 1 if equal; unchanged otherwise)
 * @param p1 the first array
 * @param p2 the second array
 * @param p3 the offset
 * @param p4 the type
 */
void compare(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p4;

        // The first element.
        // CAUTION! It HAS TO BE initialised with p1,
        // since an offset is added to it below.
        void* e1 = p1;
        // The second element.
        // CAUTION! It HAS TO BE initialised with p2,
        // since an offset is added to it below.
        void* e2 = p2;

        // Add offset to first element.
        add_integer((void*) &e1, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        // Add offset to second element.
        add_integer((void*) &e2, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare values.");

        if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            compare_character(p0, e1, e2);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            compare_double(p0, e1, e2);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            compare_integer(p0, e1, e2);

        } else if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            compare_pointer(p0, e1, e2);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            compare_unsigned_long(p0, e1, e2);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            compare_wide_character(p0, e1, e2);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare values. The type is null.");
    }
}

/* COMPARATOR_SOURCE */
#endif
