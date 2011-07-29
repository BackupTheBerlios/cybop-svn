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

#ifndef PART_ALL_COMPARATOR_SOURCE
#define PART_ALL_COMPARATOR_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/comparator/all/item_all_comparator.c"
#include "../../../executor/converter/decoder/wide_character_abstraction_decoder.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Compares all elements of the left part with those of the right array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the right array count
 * @param p6 the left part element index
 */
void compare_all_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare all part element.");

    // The left part element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get left part element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Compare all elements of the right array with those of the left part model item.
    compare_all_item_element(p0, e, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Compares all elements of the left- with those of the right part.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 */
void compare_all_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare all part.");

    // The left model.
    void* lm = *NULL_POINTER_MEMORY_MODEL;
    // The right model.
    void* rm = *NULL_POINTER_MEMORY_MODEL;

    // Get left model.
    copy_array_forward((void*) &lm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get right model.
    copy_array_forward((void*) &rm, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Compare all elements of the right- with those of the left part model item.
    compare_all_item(p0, lm, rm, p3, p4);
}

/**
 * Compares all elements of the left- with those of the right part.
 *
 * This function compares ALL meta elements: name, abstraction, model, details.
 *
 * The name, abstraction, details are ALWAYS compared for EQUALITY!
 * Anything else would not make sense and be pointless.
 * ONLY the actual model is compared using the given operation abstraction.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation abstraction
 */
void compare_all_part_all(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        void** rp = (void**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** lp = (void**) p1;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare all part all.");

            // The left part name, abstraction, model, details.
            void* ln = *NULL_POINTER_MEMORY_MODEL;
            void* la = *NULL_POINTER_MEMORY_MODEL;
            void* lm = *NULL_POINTER_MEMORY_MODEL;
            void* ld = *NULL_POINTER_MEMORY_MODEL;
            // The right part name, abstraction, model, details.
            void* rn = *NULL_POINTER_MEMORY_MODEL;
            void* ra = *NULL_POINTER_MEMORY_MODEL;
            void* rm = *NULL_POINTER_MEMORY_MODEL;
            void* rd = *NULL_POINTER_MEMORY_MODEL;
            // The right part elements data, count.
            void* rad = *NULL_POINTER_MEMORY_MODEL;
            void* rac = *NULL_POINTER_MEMORY_MODEL;
            // The right part abstraction primitive.
            int rap = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // The name, abstraction, model, details comparison results.
            int nr = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ar = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mr = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int dr = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Get left name, abstraction, model, details.
            copy_array_forward((void*) &ln, *lp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &la, *lp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
            copy_array_forward((void*) &lm, *lp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            copy_array_forward((void*) &ld, *lp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
            // Get right part name, abstraction, model, details.
            copy_array_forward((void*) &rn, *rp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &ra, *rp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
            copy_array_forward((void*) &rm, *rp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            copy_array_forward((void*) &rd, *rp, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
            // Get right part item data, count.
            copy_array_forward((void*) &rad, ra, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &rac, ra, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

            // Determine primitive abstraction.
            // CAUTION! The source abstraction arriving here had already been converted
            // from a cybol- to a cyboi abstraction, e.g. "text/plain" into "wide_character".
            // Therefore, decoding is only needed from a cyboi- to a primitive abstraction.
            decode_wide_character_abstraction((void*) &rap, (void*) rad, (void*) rac);

            // Overwrite left- with right part model item.
            // CAUTION! Do NOT use the basic function "compare_item" here,
            // since it does not compare the item counts.
            compare_all_item((void*) &nr, ln, rn, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            compare_all_item((void*) &ar, la, ra, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
            compare_all_item((void*) &mr, lm, rm, p3, (void*) &rap);
            compare_all_item((void*) &dr, ld, rd, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

            if ((nr == *NUMBER_1_INTEGER_MEMORY_MODEL)
                && (ar == *NUMBER_1_INTEGER_MEMORY_MODEL)
                && (mr == *NUMBER_1_INTEGER_MEMORY_MODEL)
                && (dr == *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                // Set result to TRUE only if all comparisons of
                // name, abstraction, model, details delivered true.
                copy_integer(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare all part all. The left part is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare all part all. The right part is null.");
    }
}

/* PART_ALL_COMPARATOR_SOURCE */
#endif
