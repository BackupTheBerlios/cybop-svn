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
 * @param p0 the destination model
 * @param p1 the source model
 * @param p2 the count
 * @param p3 the destination index
 * @param p4 the source count
 */
void set_model_models_deep(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set model models deep.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The destination part, source part model.
        void* dp = *NULL_POINTER_MEMORY_MODEL;
        void* sp = *NULL_POINTER_MEMORY_MODEL;
        // The source part model count.
        void* spc = *NULL_POINTER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            // Get source part model.
            get((void*) &sp, p1, (void*) &j, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

            if (sp != *NULL_POINTER_MEMORY_MODEL) {

                //?? TODO: Determine count one level deeper (model-item-count)?!
                // Get source part model count.
                get((void*) &spc, sp, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

                //?? TODO: Determine source part abstraction.
                //?? TODO: Create destination name.
                //?? TODO: Create destination abstraction.

                // Allocate destination part model.
                allocate((void*) &dp, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, a, ac);

                // Set source- to destination part model.
                set_model(dp, sp, spc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set model models deep. The source part model is null.");
            }

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set model models deep. The source count is null.");
    }
}

/**
 * Sets the source model models to the destination model at position index.
 *
 * @param p0 the destination model
 * @param p1 the source model
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void set_model_models(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set model models.");

        if (*a != *MODEL_PRIMITIVE_MEMORY_ABSTRACTION) {

            // Use shallow setting for primitive data like:
            // integer array, double array, fraction.

            // Set source- to destination model (shallow).
            set_item(p0, p1, p2, p3, p4, p5);

        } else {

            // Use deep setting for compound data with abstraction (type) "model".
            //
            // CAUTION! Do NOT use shallow setting here!
            // The data is just a reference (pointer) to the actual compound model.
            // If only the source pointer was set (copied), then the
            // destination would point to the same model as the source.
            // But this kind of shallow copy is not wanted here.
            // The compound models' parts (child nodes) have to be copied, too.
            // Since they do not exist, they have to be allocated first.

            // The source count.
            void* sc = *NULL_POINTER_MEMORY_MODEL;

            // Get source count.
            get((void*) &sc, p1, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

            // Set source- to destination model (deep).
            set_model_models_deep(p0, p1, p3, p4, sc);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set model models. The operand abstraction is null.");
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
 * @param p3 the destination index
 * @param p4 the source index
 */
void set_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

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
    get((void*) &sa, p1, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
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
        set_model_models(dm, sm, (void*) &a, p2, p3, p4);
        set_model_models(dd, sd, (void*) MODEL_PRIMITIVE_MEMORY_ABSTRACTION, p2, p3, p4);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set model. The destination- and source abstractions are not equal.");
    }
}

/* MODEL_SETTER_SOURCE */
#endif
