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

#ifndef WIDE_CHARACTER_ABSTRACTION_DECODER_SOURCE
#define WIDE_CHARACTER_ABSTRACTION_DECODER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Decodes the wide character abstraction into an integer abstraction.
 *
 * @param p0 the destination integer abstraction (Hand over as reference!)
 * @param p1 the source wide character abstraction
 * @param p2 the source wide character abstraction count
 */
void decode_wide_character_abstraction(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* d = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode wide character abstraction.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        // complex

        // datetime

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        // encapsulated_knowledge_path

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) FRACTION_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        // knowledge_path

        // operation

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) PART_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) PART_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array((void*) &r, p1, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                copy_integer(p0, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode wide character abstraction. The source wide character abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode wide character abstraction. The destination integer abstraction is null.");
    }
}

/* WIDE_CHARACTER_ABSTRACTION_DECODER_SOURCE */
#endif
