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

#ifndef VALUE_SETTER_SOURCE
#define VALUE_SETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/copier/value_setter/character_value_setter.c"
#include "../../executor/copier/value_setter/double_value_setter.c"
#include "../../executor/copier/value_setter/integer_value_setter.c"
#include "../../executor/copier/value_setter/pointer_value_setter.c"
#include "../../executor/copier/value_setter/unsigned_long_value_setter.c"
#include "../../executor/copier/value_setter/wide_character_value_setter.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/comparator/count_array_comparator.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Sets the value.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void set_value(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set value.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p2, p3, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_value_character(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p2, p3, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_value_double(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p2, p3, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_value_integer(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p2, p3, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_value_pointer(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p2, p3, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_value_unsigned_long(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p2, p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_value_wide_character(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not set value. The abstraction is unknown.");
    }
}

/* VALUE_SETTER_SOURCE */
#endif
