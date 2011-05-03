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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_COMPARATOR_SOURCE
#define MODEL_COMPARATOR_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/model_memory_name.c"
#include "../../../executor/comparator/count_array_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Compares left and right model.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 * @param p3 the operation abstraction
 * @param p4 the deep comparison flag (number 0 for shallow comparison; number 1 for deep comparison)
 */
void compare_model_models_deep_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Compares left and right model.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 * @param p3 the operation abstraction
 * @param p4 the deep comparison flag (number 0 for shallow comparison; number 1 for deep comparison)
 */
void compare_model_models_deep(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Compares left and right model.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the deep comparison flag (number 0 for shallow comparison; number 1 for deep comparison)
 */
void compare_model_models(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* d = (int*) p4;

        // The shallow, deep comparison results.
        int sr = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int dr = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Compare left- with right model (shallow).
        compare_item((void*) &sr, p1, p2, p3, p4);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*d != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Deep comparison.

                // Compare left- with right model elements (deep).
                compare_model_elements((void*) &mdr, lm, rm, p3, p4);

                // Both, the shallow- and the deep comparison have to be successful.
                if ((msr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (mdr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                    // Set result to true only if all comparisons have been true.
                    set_array(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
                }
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare model models. The deep comparison flag is null.");
    }
}

/**
 * Compares left and right model.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 * @param p3 the operation abstraction
 * @param p4 the deep comparison flag (number 0 for shallow comparison; number 1 for deep comparison)
 */
void compare_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare model.");

    // CAUTION! The names do NOT have to be compared.
    // They are only used for identification within their corresponding whole model.

    // The left abstractions, models, details.
    void* la = *NULL_POINTER_MEMORY_MODEL;
    void* lm = *NULL_POINTER_MEMORY_MODEL;
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    // The right abstractions, models, details.
    void* ra = *NULL_POINTER_MEMORY_MODEL;
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    void* rd = *NULL_POINTER_MEMORY_MODEL;

    // Get left abstractions, models, details.
    get((void*) &la, p1, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &lm, p1, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &ld, p1, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get right abstractions, models, details.
    get((void*) &ra, p2, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rm, p2, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rd, p2, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The right abstraction data, count.
    void* rad = *NULL_POINTER_MEMORY_MODEL;
    void* rac = *NULL_POINTER_MEMORY_MODEL;

    // Get right abstraction data, count.
    get((void*) &rad, ra, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rac, ra, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The primitive operand abstraction.
    int a = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Decode primitive abstraction.
    // CAUTION! The right model's abstraction is used here,
    // but the left model's abstraction may be used as well.
    decode_primitive_abstraction((void*) &a, rad, rac);

    // The abstractions, models, details comparison results.
    int ar = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mr = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int dr = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Compare left- with right abstraction.
    compare_item((void*) &ar, la, ra, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Compare left- with right details.
        // This function returns "true" in case both details are empty.
        compare_item((void*) &dr, ld, rd, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) MODEL_PRIMITIVE_MEMORY_ABSTRACTION);

        if (dr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Compare left- with right model.
            compare_model_models((void*) &mr, lm, rm, p3, p4, (void*) &a);

            // Count the tree depth here!
            // Only set p0 below, if root level has been reached again!

            if (mr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set result to true only if all comparisons have been true.
                set_array(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            }
        }
    }
}

/* MODEL_COMPARATOR_SOURCE */
#endif
