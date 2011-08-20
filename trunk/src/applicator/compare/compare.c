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
 * - operator (required): the kind of comparison (equal, greater, greater_or_equal, smaller, smaller_or_equal, unequal)
 * - result (required): the knowledge model in which the comparison result is stored
 * - left (required): the left operand of the comparison
 * - right (required): the right operand of the comparison
 * - selection (optional, for models of abstraction "character"): the part of two string values to be compared (all, prefix, suffix, subsequence)
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

    // The operator.
    void* o = *NULL_POINTER_MEMORY_MODEL;
    // The result.
    void* res = *NULL_POINTER_MEMORY_MODEL;
    // The left operand.
    void* l = *NULL_POINTER_MEMORY_MODEL;
    // The right operand.
    void* r = *NULL_POINTER_MEMORY_MODEL;
    // The selection.
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // The operator part model.
    void* om = *NULL_POINTER_MEMORY_MODEL;

    // The operator part model data, count.
    void* omd = *NULL_POINTER_MEMORY_MODEL;
    void* omc = *NULL_POINTER_MEMORY_MODEL;

    // Get operator.
    get_name_array((void*) &o, p0, (void*) OPERATOR_COMPARE_OPERATION_CYBOL_NAME, (void*) OPERATOR_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get result.
    get_name_array((void*) &res, p0, (void*) RESULT_COMPARE_OPERATION_CYBOL_NAME, (void*) RESULT_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get left operand.
    get_name_array((void*) &l, p0, (void*) LEFT_OPERAND_COMPARE_OPERATION_CYBOL_NAME, (void*) LEFT_OPERAND_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get right operand.
    get_name_array((void*) &r, p0, (void*) RIGHT_OPERAND_COMPARE_OPERATION_CYBOL_NAME, (void*) RIGHT_OPERAND_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get selection.
    get_name_array((void*) &s, p0, (void*) SELECTION_COMPARE_OPERATION_CYBOL_NAME, (void*) SELECTION_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get operator part model.
    copy_array_forward((void*) &om, o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get operator part model data, count.
    copy_array_forward((void*) &omd, om, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &omc, om, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    //?? CONTINUE HERE! Which parametre to evaluate first?
    //?? Should these comparisons be moved into "executor/comparator/"?

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, *sm, (void*) ALL_COMPARISON_SELECTION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, *smc, (void*) ALL_COMPARISON_SELECTION_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_equality_all(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, *sm, (void*) PREFIX_COMPARISON_SELECTION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, *smc, (void*) PREFIX_COMPARISON_SELECTION_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_equality_prefix(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, *sm, (void*) SUFFIX_COMPARISON_SELECTION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, *smc, (void*) SUFFIX_COMPARISON_SELECTION_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_equality_suffix(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, *sm, (void*) PART_COMPARISON_SELECTION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, *smc, (void*) PART_COMPARISON_SELECTION_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            compare_equality_part(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare if left parameter is equal to right parameter. The selection parameter model is unknown.");
    }
}

/* COMPARE_SOURCE */
#endif
