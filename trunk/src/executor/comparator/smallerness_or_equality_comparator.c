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

#ifndef SMALLERNESS_OR_EQUALITY_COMPARATOR_SOURCE
#define SMALLERNESS_OR_EQUALITY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/smallerness_or_equality/character_smallerness_or_equality_comparator.c"
#include "../../executor/comparator/smallerness_or_equality/double_smallerness_or_equality_comparator.c"
#include "../../executor/comparator/smallerness_or_equality/integer_smallerness_or_equality_comparator.c"
#include "../../executor/comparator/smallerness_or_equality/pointer_smallerness_or_equality_comparator.c"
#include "../../executor/comparator/smallerness_or_equality/unsigned_long_smallerness_or_equality_comparator.c"
#include "../../executor/comparator/smallerness_or_equality/wide_character_smallerness_or_equality_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares two values for smallerness or equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the abstraction
 */
void compare_smaller_or_equal(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare for smallerness or equality.");

        if (*a == *CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_smaller_or_equal_character(p0, p1, p2);

        } else if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_smaller_or_equal_double(p0, p1, p2);

        } else if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_smaller_or_equal_integer(p0, p1, p2);

        } else if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_smaller_or_equal_pointer(p0, p1, p2);

        } else if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_smaller_or_equal_unsigned_long(p0, p1, p2);

        } else if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_smaller_or_equal_wide_character(p0, p1, p2);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare for smallerness or equality. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare for smallerness or equality. The abstraction is null.");
    }
}

/* SMALLERNESS_OR_EQUALITY_COMPARATOR_SOURCE */
#endif
