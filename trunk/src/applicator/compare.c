/*
 * $RCSfile: compare.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.14 $ $Date: 2007-05-16 19:29:01 $ $Author: christian $
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
#include "../globals/constants/log_message/log_message_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

/**
 * Compares two parameters.
 *
 * Expected parameters:
 * - comparison: equal, smaller, greater, smaller_or_equal, greater_or_equal
 * - left: the left parameter
 * - right: the right parameter
 * - result: the comparison result
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void compare(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Compare two parameters.");

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

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) EQUAL_MODEL, (void*) EQUAL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            compare_equal(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SMALLER_MODEL, (void*) SMALLER_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            compare_smaller(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GREATER_MODEL, (void*) GREATER_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            compare_greater(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) SMALLER_OR_EQUAL_MODEL, (void*) SMALLER_OR_EQUAL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            compare_smaller_or_equal(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *cm, (void*) *cmc, (void*) GREATER_OR_EQUAL_MODEL, (void*) GREATER_OR_EQUAL_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            compare_greater_or_equal(*lsa, *lsac, *lsas, *lsm, *lsmc, *lsms, *lsd, *lsdc, *lsds,
                *rsa, *rsac, *rsas, *rsm, *rsmc, *rsms, *rsd, *rsdc, *rsds,
                *ra, *rac, *ras, *rm, *rmc, *rms, *rd, *rdc, *rds);
        }
    }
}

/* COMPARE_SOURCE */
#endif
