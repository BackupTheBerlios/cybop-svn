/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: greaterness_comparator.c.c,v $ $Revision: 1.7 $ $Date: 2008-09-16 22:47:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GREATERNESS_COMPARATOR_SOURCE
#define GREATERNESS_COMPARATOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/comparison_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Compares if the left parameter is greater than the right parameter.
 *
 * Expected parameters:
 * - left_side (required): the left side value of the comparison
 * - right_side (required): the right side value of the comparison
 * - result (required): the knowledge model in which the comparison result is stored
 * - selection (optional, only for values of abstraction "character"): the part of two string values to be compared (full, prefix, suffix, part)
 *
 * The result parameter's abstraction must be BOOLEAN.
 * The left side- and right side parameters' abstractions have to be equal.
 * They can be one of:
 * - character
 * - integer
 * - double
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void compare_greaterness(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The left side name, abstraction, model, details.
    void** lsn = NULL_POINTER_MEMORY_MODEL;
    void** lsnc = NULL_POINTER_MEMORY_MODEL;
    void** lsns = NULL_POINTER_MEMORY_MODEL;
    void** lsa = NULL_POINTER_MEMORY_MODEL;
    void** lsac = NULL_POINTER_MEMORY_MODEL;
    void** lsas = NULL_POINTER_MEMORY_MODEL;
    void** lsm = NULL_POINTER_MEMORY_MODEL;
    void** lsmc = NULL_POINTER_MEMORY_MODEL;
    void** lsms = NULL_POINTER_MEMORY_MODEL;
    void** lsd = NULL_POINTER_MEMORY_MODEL;
    void** lsdc = NULL_POINTER_MEMORY_MODEL;
    void** lsds = NULL_POINTER_MEMORY_MODEL;
    // The right side name, abstraction, model, details.
    void** rsn = NULL_POINTER_MEMORY_MODEL;
    void** rsnc = NULL_POINTER_MEMORY_MODEL;
    void** rsns = NULL_POINTER_MEMORY_MODEL;
    void** rsa = NULL_POINTER_MEMORY_MODEL;
    void** rsac = NULL_POINTER_MEMORY_MODEL;
    void** rsas = NULL_POINTER_MEMORY_MODEL;
    void** rsm = NULL_POINTER_MEMORY_MODEL;
    void** rsmc = NULL_POINTER_MEMORY_MODEL;
    void** rsms = NULL_POINTER_MEMORY_MODEL;
    void** rsd = NULL_POINTER_MEMORY_MODEL;
    void** rsdc = NULL_POINTER_MEMORY_MODEL;
    void** rsds = NULL_POINTER_MEMORY_MODEL;
    // The result name, abstraction, model, details.
    void** rn = NULL_POINTER_MEMORY_MODEL;
    void** rnc = NULL_POINTER_MEMORY_MODEL;
    void** rns = NULL_POINTER_MEMORY_MODEL;
    void** ra = NULL_POINTER_MEMORY_MODEL;
    void** rac = NULL_POINTER_MEMORY_MODEL;
    void** ras = NULL_POINTER_MEMORY_MODEL;
    int** rm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** rmc = NULL_POINTER_MEMORY_MODEL;
    void** rms = NULL_POINTER_MEMORY_MODEL;
    void** rd = NULL_POINTER_MEMORY_MODEL;
    void** rdc = NULL_POINTER_MEMORY_MODEL;
    void** rds = NULL_POINTER_MEMORY_MODEL;
    // The selection name, abstraction, model, details.
    void** sn = NULL_POINTER_MEMORY_MODEL;
    void** snc = NULL_POINTER_MEMORY_MODEL;
    void** sns = NULL_POINTER_MEMORY_MODEL;
    void** sa = NULL_POINTER_MEMORY_MODEL;
    void** sac = NULL_POINTER_MEMORY_MODEL;
    void** sas = NULL_POINTER_MEMORY_MODEL;
    void** sm = NULL_POINTER_MEMORY_MODEL;
    void** smc = NULL_POINTER_MEMORY_MODEL;
    void** sms = NULL_POINTER_MEMORY_MODEL;
    void** sd = NULL_POINTER_MEMORY_MODEL;
    void** sdc = NULL_POINTER_MEMORY_MODEL;
    void** sds = NULL_POINTER_MEMORY_MODEL;

    // Get left side.
    get_universal_compound_element_by_name(p0, p1,
        (void*) LEFT_SIDE_COMPARISON_OPERATION_CYBOL_NAME, (void*) LEFT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_COUNT,
        (void*) &lsn, (void*) &lsnc, (void*) &lsns,
        (void*) &lsa, (void*) &lsac, (void*) &lsas,
        (void*) &lsm, (void*) &lsmc, (void*) &lsms,
        (void*) &lsd, (void*) &lsdc, (void*) &lsds,
        p2, p3);
    // Get right side.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RIGHT_SIDE_COMPARISON_OPERATION_CYBOL_NAME, (void*) RIGHT_SIDE_COMPARISON_OPERATION_CYBOL_NAME_COUNT,
        (void*) &rsn, (void*) &rsnc, (void*) &rsns,
        (void*) &rsa, (void*) &rsac, (void*) &rsas,
        (void*) &rsm, (void*) &rsmc, (void*) &rsms,
        (void*) &rsd, (void*) &rsdc, (void*) &rsds,
        p2, p3);
    // Get result.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RESULT_COMPARISON_OPERATION_CYBOL_NAME, (void*) RESULT_COMPARISON_OPERATION_CYBOL_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);
    // Get selection.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SELECTION_COMPARISON_OPERATION_CYBOL_NAME, (void*) SELECTION_COMPARISON_OPERATION_CYBOL_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare if one parameter is greater than the other.");

    // The result parameter comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Compare result parameter abstraction. It must be a boolean.
    compare_arrays(*ra, *rac, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The left side parameter comparison result.
        int lr;
        // The right side parameter comparison result.
        int rr;

        //
        // Character parameters.
        //

        // Reset parameter comparison results.
        lr = *NUMBER_0_INTEGER_MEMORY_MODEL;
        rr = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Compare parameter abstractions.
        compare_arrays(*lsa, *lsac, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &lr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
        compare_arrays(*rsa, *rsac, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, (void*) &rr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if ((lr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (rr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Use character parameters.");

            if (*((wchar_t*) *lsm) > *((wchar_t*) *rsm)) {

                **rm = *TRUE_BOOLEAN_MEMORY_MODEL;

            } else {

                **rm = *FALSE_BOOLEAN_MEMORY_MODEL;
            }
        }

        //
        // Integer parameters.
        //

        // Reset parameter comparison results.
        lr = *NUMBER_0_INTEGER_MEMORY_MODEL;
        rr = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Compare parameter abstractions.
        compare_arrays(*lsa, *lsac, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &lr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
        compare_arrays(*rsa, *rsac, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &rr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if ((lr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (rr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Use integer parameters.");

            if (*((int*) *lsm) > *((int*) *rsm)) {

                **rm = *TRUE_BOOLEAN_MEMORY_MODEL;

            } else {

                **rm = *FALSE_BOOLEAN_MEMORY_MODEL;
            }
        }

        //
        // Double parameters.
        //

        // Reset parameter comparison results.
        lr = *NUMBER_0_INTEGER_MEMORY_MODEL;
        rr = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Compare parameter abstractions.
        compare_arrays(*lsa, *lsac, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &lr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
        compare_arrays(*rsa, *rsac, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) &rr, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if ((lr != *NUMBER_0_INTEGER_MEMORY_MODEL) && (rr != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Use double parameters.");

            if (*((double*) *lsm) > *((double*) *rsm)) {

                **rm = *TRUE_BOOLEAN_MEMORY_MODEL;

            } else {

                **rm = *FALSE_BOOLEAN_MEMORY_MODEL;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare if one parameter is greater than the other. The result parameter is not a boolean.");
    }
}

/* GREATERNESS_COMPARATOR_SOURCE */
#endif
