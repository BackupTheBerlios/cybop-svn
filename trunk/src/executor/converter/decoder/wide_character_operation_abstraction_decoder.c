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

#ifndef WIDE_CHARACTER_OPERATION_ABSTRACTION_DECODER_SOURCE
#define WIDE_CHARACTER_OPERATION_ABSTRACTION_DECODER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/operation_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Decodes the wide character operation abstraction into an integer abstraction.
 *
 * @param p0 the destination integer operation abstraction (Hand over as reference!)
 * @param p1 the source wide character operation abstraction
 * @param p2 the source wide character operation abstraction count
 */
void decode_wide_character_operation_abstraction(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* d = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode wide character operation abstraction.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) EQUAL_OPERATION_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) EQUAL_OPERATION_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *d = EQUAL_PRIMITIVE_OPERATION_ABSTRACTION;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) GREATER_OPERATION_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) GREATER_OPERATION_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *d = GREATER_PRIMITIVE_OPERATION_ABSTRACTION;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_OR_EQUAL_OPERATION_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) GREATER_OR_EQUAL_OPERATION_ABSTRACTION_COUNT);
            compare_array_wide_character_equal((void*) &r, p1, p2, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *d = GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) SMALLER_OPERATION_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SMALLER_OPERATION_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *d = SMALLER_PRIMITIVE_OPERATION_ABSTRACTION;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) SMALLER_OR_EQUAL_OPERATION_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SMALLER_OR_EQUAL_OPERATION_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *d = SMALLER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode wide character operation abstraction. The source wide character operation abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode wide character operation abstraction. The destination integer operation abstraction is null.");
    }
}

/* WIDE_CHARACTER_OPERATION_ABSTRACTION_DECODER_SOURCE */
#endif
