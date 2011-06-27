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

#ifndef PART_COPIER_SOURCE
#define PART_COPIER_SOURCE

#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/separator_cybol_name.c"
#include "../../constant/name/memory/model_memory_name.c"
#include "../../executor/comparator/count_array_comparator.c"
#include "../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/**
 * Copies the array to the part container element.
 *
 * @param p0 the part container
 * @param p1 the array
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the part container index
 * @param p5 the array index
 * @param p6 the part container element index
 */
void copy_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part element.");

    // The part container element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get part container element.
    copy_array_offset((void*) &e, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Set item to part container element.
    // The count is adjusted automatically.
    copy_item_element(e, p1, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Copies count source part model elements into the destination part at position index.
 *
 * @param p0 the destination part model
 * @param p1 the source part model
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void copy_part_model_deep(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

/*??
    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part model deep.");

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy part model deep. The source part model is null.");
            }

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy part model deep. The source count is null.");
    }
*/
}

/**
 * Copies source part model into the destination part model.
 *
 * @param p0 the destination part model
 * @param p1 the source part model
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void copy_part_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part model.");

        if (*a != *COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION) {

            // Use shallow copying for primitive data like:
            // integer, double, wide_character, fraction.

            // Set source- to destination model (shallow).
            copy_item(p0, p1, p2, p3, p4, p5);

        } else {

            // Use deep copying for compound data.
            //
            // CAUTION! Do NOT use shallow copying here!
            // The data is just a reference to the actual compound model.
            // If only the source pointer was copied, then the
            // destination would point to the same model as the source.
            // But this kind of shallow copy is not wanted here.
            // The compound model's parts (child nodes) have to be copied, too.
            // Since they do not exist, they have to be allocated first.

            // Set source- to destination model (deep).
//??            copy_part_model_deep(p0, p1, p3, p4, sc);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy part model. The operand abstraction is null.");
    }
}

/**
 * Copies count source part elements into the destination part at position index.
 *
 * CAUTION! The destination already HAS TO EXIST and has to have a NAME.
 * The source name is NOT copied into the destination name.
 *
 * CAUTION! The source abstraction has to be IDENTICAL to the
 * destination abstraction. The equality of both is NOT tested here.
 * The given "operand abstraction" is used for destination and source.
 * The source abstraction is NOT copied into the destination abstraction.
 *
 * CAUTION! The size of the destination has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void copy_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part.");

    // The destination model, details.
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source model, details.
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination model, details.
    copy_array_offset((void*) &dm, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_offset((void*) &dd, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get source model, details.
    copy_array_offset((void*) &sm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_offset((void*) &sd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // Set source- to destination model, details.
    // CAUTION! The name and abstraction are NOT copied.
    copy_part_model(dm, sm, p2, p3, p4, p5);
    copy_part_model(dd, sd, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION, p3, p4, p5);
}

/* PART_COPIER_SOURCE */
#endif