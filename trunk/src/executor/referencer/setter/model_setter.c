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

#ifndef MODEL_SETTER_SOURCE
#define MODEL_SETTER_SOURCE

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
 * Sets the source model models to the destination model deep.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 * @param p3 the operation abstraction
 * @param p4 the count
 */
void compare_model_models_deep(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p4;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            int* r = (int*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare model models deep.");

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The left, right part model.
            void* lp = *NULL_POINTER_MEMORY_MODEL;
            void* rp = *NULL_POINTER_MEMORY_MODEL;
            // The model comparison result.
            int mr = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *c) {

                    // All part models have been compared successfully.
                    // The comparison of all part model pairs delivered "true".
                    //
                    // CAUTION! The part models are expected to be equal,
                    // even if the count is zero. This is important, because
                    // many otherwise equal models contain empty parts.
                    *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                    break;
                }

                // Get left, right part model.
                get((void*) &lp, p1, (void*) &j, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get((void*) &rp, p2, (void*) &j, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

                // Reset model comparison result.
                mr = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // CAUTION! This function does not change the result flag, if unequal.
                // Therefore, the result flag always has to be reset to zero before!
                compare_model((void*) &mr, lp, rp, p3);

                if (mr == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Stop comparison if two part models do not match the
                    // criteria, i.e. the comparison delivered "false".
                    // Because then, the comparison of the two part models is "false".
                    break;
                }

                j++;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare model models deep. The result is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare model models deep. The count is null.");
    }
}

/**
 * Sets the source model models to the destination model at position index.
 *
 * @param p0 the destination model
 * @param p1 the source model
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the index
 */
void compare_model_models(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare model models.");

        if (*a != *MODEL_PRIMITIVE_MEMORY_ABSTRACTION) {

            // Use shallow comparison for primitive data like:
            // integer array, double array, fraction.

            // Compare left- with right model (shallow).
            compare_item(p0, p1, p2, p3, p4);

/*??
            set_item(dm, sm, (void*) &a, p2, p3);
            set_item(dd, sd, (void*) MODEL_PRIMITIVE_MEMORY_ABSTRACTION, p2, p3);
*/

        } else {

            // Use deep comparison for compound data with abstraction (type) "model".
            //
            // CAUTION! Do NOT use shallow comparison here!
            // It might seem useful to compare the items' counts.
            // However, since it also compares their data,
            // false results will occur, because the data is just
            // a reference (pointer) to the actual compound model.
            // Instead of comparing these pointers, a comparison
            // of the compound models' parts (child nodes) is needed.

            // CAUTION! The sizes do NOT have to be identical,
            // since they just represent allocated memory.
            // For comparison, only the actual number of elements is of interest.

            // The left, right count.
            void* lc = *NULL_POINTER_MEMORY_MODEL;
            void* rc = *NULL_POINTER_MEMORY_MODEL;

            // Get left, right count.
            get((void*) &lc, p1, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
            get((void*) &rc, p2, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

            // The count comparison result.
            int cr = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Compare left- with right count.
            // CAUTION! Use the equal operation to compare both counts.
            compare_array((void*) &cr, lc, rc, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            if (cr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Compare left- with right model (deep).
                // CAUTION! The right model's count is used here,
                // but the left model's count may be used as well.
                compare_model_models_deep(p0, p1, p2, p3, rc);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare model models. The operand abstraction is null.");
    }
}

/**
 * Sets the source model to the destination model at position index.
 *
 * CAUTION! The destination already HAS TO EXIST and has to have a NAME.
 * The source name is NOT copied into the destination name.
 *
 * CAUTION! The source abstraction has to be IDENTICAL to the
 * destination abstraction. The equality of both IS tested here.
 * If they are not equal, then the model will NOT be set.
 *
 * CAUTION! The size of the destination model has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination model
 * @param p1 the source model
 * @param p2 the count
 * @param p3 the index
 */
void set_model(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set model.");

    // CAUTION! The name and abstraction are NOT copied.
    // The abstractions are only compared for equality.

    // The destination abstractions, models, details.
    void* da = *NULL_POINTER_MEMORY_MODEL;
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source abstractions, models, details.
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination abstractions, models, details.
    get((void*) &da, p0, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dm, p0, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dd, p0, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get source abstractions, models, details.
    get((void*) &sa, p0, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sm, p1, (void*) MODELS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sd, p1, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The abstractions comparison results.
    int ar = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Compare destination- with source abstraction.
    compare_item((void*) &ar, da, sa, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The destination abstraction data, count.
        void* dad = *NULL_POINTER_MEMORY_MODEL;
        void* dac = *NULL_POINTER_MEMORY_MODEL;

        // Get destination abstraction data, count.
        get((void*) &dad, da, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &dac, da, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        // The primitive operand abstraction.
        int a = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Decode primitive abstraction.
        decode_primitive_abstraction((void*) &a, dad, dac);

        // Set source models, details into destination.
        set_model_models(dm, sm, (void*) &a, p2, p3);
        set_model_models(dd, sd, (void*) MODEL_PRIMITIVE_MEMORY_ABSTRACTION, p2, p3);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set model. The destination- and source abstractions are not equal.");
    }
}

/* MODEL_SETTER_SOURCE */
#endif
