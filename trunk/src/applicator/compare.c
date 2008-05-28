/*
 * $RCSfile: compare.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.22 $ $Date: 2008-05-28 22:39:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_SOURCE
#define COMPARE_SOURCE

#include "../applicator/compare/compare_equal.c"
#include "../applicator/compare/compare_greater.c"
#include "../applicator/compare/compare_greater_or_equal.c"
#include "../applicator/compare/compare_smaller.c"
#include "../applicator/compare/compare_smaller_or_equal.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

/**
 * Compares two parameters.
 *
 * Expected parameters:
 * - comparison (required): the kind of comparison to be applied (equal, smaller_or_equal, ...)
 * - left_side (required): the left side value of the comparison
 * - right_side (required): the right side value of the comparison
 * - result (required): the knowledge model in which the comparison result is stored
 * - selection (optional, only for values of abstraction "character"): the part of two string values to be compared (full, prefix, suffix, part)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void compare(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Compare two parameters.");

    // The comparison name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;
    // The left side name, abstraction, model, details.
    void** lsn = NULL_POINTER;
    void** lsnc = NULL_POINTER;
    void** lsns = NULL_POINTER;
    void** lsa = NULL_POINTER;
    void** lsac = NULL_POINTER;
    void** lsas = NULL_POINTER;
    void** lsm = NULL_POINTER;
    void** lsmc = NULL_POINTER;
    void** lsms = NULL_POINTER;
    void** lsd = NULL_POINTER;
    void** lsdc = NULL_POINTER;
    void** lsds = NULL_POINTER;
    // The right side name, abstraction, model, details.
    void** rsn = NULL_POINTER;
    void** rsnc = NULL_POINTER;
    void** rsns = NULL_POINTER;
    void** rsa = NULL_POINTER;
    void** rsac = NULL_POINTER;
    void** rsas = NULL_POINTER;
    void** rsm = NULL_POINTER;
    void** rsmc = NULL_POINTER;
    void** rsms = NULL_POINTER;
    void** rsd = NULL_POINTER;
    void** rsdc = NULL_POINTER;
    void** rsds = NULL_POINTER;
    // The result name, abstraction, model, details.
    void** rn = NULL_POINTER;
    void** rnc = NULL_POINTER;
    void** rns = NULL_POINTER;
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;
    // The selection name, abstraction, model, details.
    void** sn = NULL_POINTER;
    void** snc = NULL_POINTER;
    void** sns = NULL_POINTER;
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // Get comparison.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COMPARISON_NAME, (void*) COMPARISON_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);
    // Get left side.
    get_universal_compound_element_by_name(p0, p1,
        (void*) LEFT_SIDE_NAME, (void*) LEFT_SIDE_NAME_COUNT,
        (void*) &lsn, (void*) &lsnc, (void*) &lsns,
        (void*) &lsa, (void*) &lsac, (void*) &lsas,
        (void*) &lsm, (void*) &lsmc, (void*) &lsms,
        (void*) &lsd, (void*) &lsdc, (void*) &lsds,
        p2, p3);
    // Get right side.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RIGHT_SIDE_NAME, (void*) RIGHT_SIDE_NAME_COUNT,
        (void*) &rsn, (void*) &rsnc, (void*) &rsns,
        (void*) &rsa, (void*) &rsac, (void*) &rsas,
        (void*) &rsm, (void*) &rsmc, (void*) &rsms,
        (void*) &rsd, (void*) &rsdc, (void*) &rsds,
        p2, p3);
    // Get result.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RESULT_NAME, (void*) RESULT_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);
    // Get selection.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COUNT_SELECTION_NAME, (void*) COUNT_SELECTION_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) EQUAL_MODEL, (void*) EQUAL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            compare_equal(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds,
                *sm, *smc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SMALLER_MODEL, (void*) SMALLER_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            compare_smaller(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GREATER_MODEL, (void*) GREATER_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            compare_greater(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SMALLER_OR_EQUAL_MODEL, (void*) SMALLER_OR_EQUAL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            compare_smaller_or_equal(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GREATER_OR_EQUAL_MODEL, (void*) GREATER_OR_EQUAL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            compare_greater_or_equal(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) L"Could not compare two parameters. The comparison model is unknown.");
    }
}

/* COMPARE_SOURCE */
#endif
