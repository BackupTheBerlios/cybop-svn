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
#include "../../../executor/comparator/equality/array_equality_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Compares left and right model.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 */
void compare_model(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare model.");

    // CAUTION! The names do NOT have to be identical.
    // They are only used for identification within their corresponding whole model.

    // The left names, abstractions, models, details.
    void* la = *NULL_POINTER_MEMORY_MODEL;
    void* lm = *NULL_POINTER_MEMORY_MODEL;
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    // The right names, abstractions, models, details.
    void* ra = *NULL_POINTER_MEMORY_MODEL;
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    void* rd = *NULL_POINTER_MEMORY_MODEL;

    // Get left names, abstractions, models, details.
    get((void*) &la, p1, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &lm, p1, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &ld, p1, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get right names, abstractions, models, details.
    get((void*) &ra, p2, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rm, p2, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rd, p2, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The right abstraction data, count.
    void* rad = *NULL_POINTER_MEMORY_MODEL;
    void* rac = *NULL_POINTER_MEMORY_MODEL;

    // Get right abstraction data, count.
    get((void*) &rad, ra, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rac, ra, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The abstractions, models, details comparison results.
    int ar = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mr = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int dr = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Compare left- with right model.
    compare_item((void*) &ar, la, ra, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_item((void*) &mr, lm, rm, rad, rac);

        if (mr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_item((void*) &dr, ld, rd, (void*) MODEL_MEMORY_ABSTRACTION, (void*) MODEL_MEMORY_ABSTRACTION_COUNT);

            if (dr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set result to true only if all comparisons have been true.
                set_array(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            }
        }
    }
}

/* MODEL_COMPARATOR_SOURCE */
#endif
