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
 * @version $RCSfile: equality_comparator.c,v $ $Revision: 1.7 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_SOURCE
#define COMPARE_SOURCE

#include "../../applicator/comparator/equality/all_equality_comparator.c"
#include "../../applicator/comparator/equality/part_equality_comparator.c"
#include "../../applicator/comparator/equality/prefix_equality_comparator.c"
#include "../../applicator/comparator/equality/suffix_equality_comparator.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/cybol/comparison_selection_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/comparison_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares left and right parametre.
 *
 * Expected parametres:
 * - result (required): the knowledge model in which the comparison result is stored
 * - left (required): the left operand of the comparison
 * - right (required): the right operand of the comparison
 * - operation (required): the kind of comparison (equal, greater, greater_or_equal, smaller, smaller_or_equal, unequal)
 * - abstraction (required): the operand abstraction
 * - selection (required): the part of two text strings to be compared (all, prefix, suffix, subsequence)
 *
 * The "selection" parametre is actually only needed
 * for comparing models of abstraction "character".
 * However, this function relies on it, also if numbers are
 * to be compared, for finding the right comparison function to call.
 * Therefore, that parametre is REQUIRED.
 *
 * The result parametre's abstraction has to be BOOLEAN.
 * The left- and right parametres' abstractions have to be equal.
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_compare(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply compare.");

    // The result part.
    void* res = *NULL_POINTER_MEMORY_MODEL;
    // The left operand part.
    void* lo = *NULL_POINTER_MEMORY_MODEL;
    // The right operand part.
    void* ro = *NULL_POINTER_MEMORY_MODEL;
    // The operation part.
    void* o = *NULL_POINTER_MEMORY_MODEL;
    // The operand abstraction part.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The selection part.
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // The result part model.
    void* resm = *NULL_POINTER_MEMORY_MODEL;
    // The operation part model.
    void* om = *NULL_POINTER_MEMORY_MODEL;
    // The operand abstraction part model.
    void* am = *NULL_POINTER_MEMORY_MODEL;
    // The selection part model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;

    // The result part model data, count.
    void* resmd = *NULL_POINTER_MEMORY_MODEL;
    // The operation part model data, count.
    void* omd = *NULL_POINTER_MEMORY_MODEL;
    // The operand abstraction part model data, count.
    void* amd = *NULL_POINTER_MEMORY_MODEL;
    // The selection part model data, count.
    void* smd = *NULL_POINTER_MEMORY_MODEL;

    // Get result part.
    get_name_array((void*) &res, p0, (void*) RESULT_COMPARE_OPERATION_CYBOL_NAME, (void*) RESULT_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get left operand part.
    get_name_array((void*) &lo, p0, (void*) LEFT_OPERAND_COMPARE_OPERATION_CYBOL_NAME, (void*) LEFT_OPERAND_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get right operand part.
    get_name_array((void*) &ro, p0, (void*) RIGHT_OPERAND_COMPARE_OPERATION_CYBOL_NAME, (void*) RIGHT_OPERAND_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get operation part.
    get_name_array((void*) &o, p0, (void*) OPERATOR_COMPARE_OPERATION_CYBOL_NAME, (void*) OPERATOR_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get operand abstraction part.
    get_name_array((void*) &a, p0, (void*) OPERATOR_COMPARE_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get selection part.
    get_name_array((void*) &s, p0, (void*) SELECTION_COMPARE_OPERATION_CYBOL_NAME, (void*) SELECTION_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get result part model.
    copy_array_forward((void*) &resm, res, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get operation part model.
    copy_array_forward((void*) &om, o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get operand abstraction part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get selection part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get result part model data, count.
    copy_array_forward((void*) &resmd, resm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get operation part model data, count.
    copy_array_forward((void*) &omd, om, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get operand abstraction part model data, count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get selection part model data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, smd, (void*) ALL_COMPARISON_SELECTION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_all_part(resmd, lo, ro, omd, amd);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, smd, (void*) PREFIX_COMPARISON_SELECTION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_prefix_part(resmd, lo, ro, omd, amd);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, smd, (void*) SUFFIX_COMPARISON_SELECTION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_suffix_part(resmd, lo, ro, omd, amd);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, smd, (void*) SUBSEQUENCE_COMPARISON_SELECTION_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_subsequence_part(resmd, lo, ro, omd, amd);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not apply compare. The selection parametre model is unknown.");
    }
}

/* COMPARE_SOURCE */
#endif
