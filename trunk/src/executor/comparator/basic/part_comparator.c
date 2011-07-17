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

#ifndef PART_COMPARATOR_SOURCE
#define PART_COMPARATOR_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/model_memory_name.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Compares left- with right model models deep.
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
 * Compares left- with right model models.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the right model
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
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
 * Compares left- with right part.
 *
 * A distinction between shallow- and deep comparison does not make sense.
 * If just the pointers of two part models are to be compared, then the
 * knowledge path strings (two pointer arrays) may be used to achieve this.
 *
 * In all other cases, the user expects the parts to be compared in every detail.
 * In other words: A deep comparison is ALWAYS applied here.
 * Note, that deep comparisons are only applicable for models
 * with abstraction "part" (formerly "compound").
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 */
void compare_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare part.");

    // CAUTION! The names do NOT have to be compared.
    // They are only used for identification within their corresponding whole model.
    // CAUTION! The abstractions do NOT have to be compared.
    // The abstraction to use for comparing is given as parametre.

    // The left model, details.
    void* lm = *NULL_POINTER_MEMORY_MODEL;
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    // The right model, details.
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    void* rd = *NULL_POINTER_MEMORY_MODEL;

    // Get left model, details.
    copy_array_forward((void*) &lm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &ld, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get right model, details.
    copy_array_forward((void*) &rm, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &rd, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // The model, details comparison results.
    int mr = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int dr = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_item((void*) &mr, lm, rm, p3, p4, p5, p6, p7);
    compare_item((void*) &dr, ld, rd, p3, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, p5, p6, p7);
--
    // Compare left- with right abstraction.
    compare_item((void*) &ar, la, ra, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (ar != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Compare left- with right details.
        // CAUTION! This function returns "true" in case both details are empty.
        compare_model_models((void*) &dr, ld, rd, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) MODEL_PRIMITIVE_MEMORY_ABSTRACTION);

        if (dr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

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

            // Compare left- with right model.
            // CAUTION! Both abstractions and both details have to be equal
            // (see comparisons above), even if the actual models are
            // compared for something differently, e.g. "smaller than".
            // Therefore, the models are compared at last here.
            compare_model_models((void*) &mr, lm, rm, p3, (void*) &a);

            if (mr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set result to true only if all comparisons have been true.
                copy_array_forward(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            }
        }
    }
}

/* PART_COMPARATOR_SOURCE */
#endif
