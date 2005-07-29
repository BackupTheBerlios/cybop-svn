/*
 * $RCSfile: compare.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.7 $ $Date: 2005-07-29 16:46:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_SOURCE
#define COMPARE_SOURCE

#include "../applicator/compare/compare_equal.c"
#include "../applicator/compare/compare_greater.c"
#include "../applicator/compare/compare_greater_or_equal.c"
#include "../applicator/compare/compare_smaller.c"
#include "../applicator/compare/compare_smaller_or_equal.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
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

    // The comparison abstraction.
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    // The comparison model.
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    // The comparison details.
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;

    // The left side abstraction.
    void** lsa = NULL_POINTER;
    void** lsac = NULL_POINTER;
    void** lsas = NULL_POINTER;
    // The left side model.
    void** lsm = NULL_POINTER;
    void** lsmc = NULL_POINTER;
    void** lsms = NULL_POINTER;
    // The left side details.
    void** lsd = NULL_POINTER;
    void** lsdc = NULL_POINTER;
    void** lsds = NULL_POINTER;

    // The right side abstraction.
    void** rsa = NULL_POINTER;
    void** rsac = NULL_POINTER;
    void** rsas = NULL_POINTER;
    // The right side model.
    void** rsm = NULL_POINTER;
    void** rsmc = NULL_POINTER;
    void** rsms = NULL_POINTER;
    // The right side details.
    void** rsd = NULL_POINTER;
    void** rsdc = NULL_POINTER;
    void** rsds = NULL_POINTER;

    // The result abstraction.
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    // The result model.
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    // The result details.
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;

    // Get comparison.
    get_real_compound_element_by_name(p0, p1,
        (void*) COMPARISON_NAME, (void*) COMPARISON_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);

    // Get left side.
    get_real_compound_element_by_name(p0, p1,
        (void*) LEFT_SIDE_NAME, (void*) LEFT_SIDE_NAME_COUNT,
        (void*) &lsa, (void*) &lsac, (void*) &lsas,
        (void*) &lsm, (void*) &lsmc, (void*) &lsms,
        (void*) &lsd, (void*) &lsdc, (void*) &lsds,
        p2, p3);

    // Get right side.
    get_real_compound_element_by_name(p0, p1,
        (void*) RIGHT_SIDE_NAME, (void*) RIGHT_SIDE_NAME_COUNT,
        (void*) &rsa, (void*) &rsac, (void*) &rsas,
        (void*) &rsm, (void*) &rsmc, (void*) &rsms,
        (void*) &rsd, (void*) &rsdc, (void*) &rsds,
        p2, p3);

    // Get result.
    get_real_compound_element_by_name(p0, p1,
        (void*) RESULT_NAME, (void*) RESULT_NAME_COUNT,
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
