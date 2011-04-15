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

#ifndef SIZE_DETERMINER_SOURCE
#define SIZE_DETERMINER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/equality/array_equality_comparator.c"
#include "../../executor/modifier/assigner/integer_assigner.c"
#include "../../logger/logger.c"
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/pointer_type_size.c"
#include "../../variable/type_size/real_type_size.c"

/**
 * Determines the size of the given abstraction.
 *
 * @param p0 the size
 * @param p1 the abstraction
 */
void determine_size(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Determine size.");

        if (*a == *CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            assign_integer(p0, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

            assign_integer(p0, (void*) DOUBLE_REAL_TYPE_SIZE);

        } else if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

            assign_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            assign_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

            assign_integer(p0, (void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            assign_integer(p0, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not determine size. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not determine size. The abstraction is null.");
    }
}

/**
 * Determines the size of the given abstraction.
 *
 * @param p0 the size
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void determine_size_NEW(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Determine size.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p1, p2, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            assign_integer(p0, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p1, p2, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            assign_integer(p0, (void*) DOUBLE_REAL_TYPE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p1, p2, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            assign_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            assign_integer(p0, (void*) POINTER_TYPE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p1, p2, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            assign_integer(p0, (void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p1, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            assign_integer(p0, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not determine size. The abstraction is unknown.");
    }
}

/* SIZE_DETERMINER_SOURCE */
#endif
