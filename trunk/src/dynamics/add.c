/*
 * $RCSfile: add.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.20 $ $Date: 2004-06-11 18:50:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

#include "../logger/logger.c"
#include "../statics/compound.c"

/**
 * Adds two summands resulting in the sum.
 *
 * @param p0 the statics model
 * @param p1 the summand 0
 * @param p2 the summand 0 size
 * @param p3 the summand 1
 * @param p4 the summand 1 size
 * @param p5 the sum
 * @param p6 the sum size
 */
void add(void* p0, const void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6) {

/*??
    // Initialize summand 1.
    char* summand_1_pa = CHARACTER_NULL_POINTER;
    int summand_1_pas = 0;
    char* summand_1_pl = CHARACTER_NULL_POINTER;
    int summand_1_pls = 0;
    int summand_1_pm = 0;
    int summand_1_pms = 0;
    char* summand_1_poa = CHARACTER_NULL_POINTER;
    int summand_1_poas = 0;
    char* summand_1_pol = CHARACTER_NULL_POINTER;
    int summand_1_pols = 0;
    void* summand_1_pom = NULL_POINTER;
    int summand_1_poms = 0;
    char* summand_1_ca = CHARACTER_NULL_POINTER;
    int summand_1_cas = 0;
    char* summand_1_cl = CHARACTER_NULL_POINTER;
    int summand_1_cls = 0;
    void* summand_1_cm = NULL_POINTER;
    int summand_1_cms = 0;

    // Initialize summand 2.
    char* summand_2_pa = CHARACTER_NULL_POINTER;
    int summand_2_pas = 0;
    char* summand_2_pl = CHARACTER_NULL_POINTER;
    int summand_2_pls = 0;
    int summand_2_pm = 0;
    int summand_2_pms = 0;
    char* summand_2_poa = CHARACTER_NULL_POINTER;
    int summand_2_poas = 0;
    char* summand_2_pol = CHARACTER_NULL_POINTER;
    int summand_2_pols = 0;
    void* summand_2_pom = NULL_POINTER;
    int summand_2_poms = 0;
    char* summand_2_ca = CHARACTER_NULL_POINTER;
    int summand_2_cas = 0;
    char* summand_2_cl = CHARACTER_NULL_POINTER;
    int summand_2_cls = 0;
    void* summand_2_cm = NULL_POINTER;
    int summand_2_cms = 0;

    // Initialize sum.
    char* sum_pa = CHARACTER_NULL_POINTER;
    int sum_pas = 0;
    char* sum_pl = CHARACTER_NULL_POINTER;
    int sum_pls = 0;
    int sum_pm = 0;
    int sum_pms = 0;
    char* sum_poa = CHARACTER_NULL_POINTER;
    int sum_poas = 0;
    char* sum_pol = CHARACTER_NULL_POINTER;
    int sum_pols = 0;
    void* sum_pom = NULL_POINTER;
    int sum_poms = 0;
    char* sum_ca = CHARACTER_NULL_POINTER;
    int sum_cas = 0;
    char* sum_cl = CHARACTER_NULL_POINTER;
    int sum_cls = 0;
    void* sum_cm = NULL_POINTER;
    int sum_cms = 0;

    // Get operands.
    get_model_part_by_name(p0, p1, p2,
        (void*) &summand_1_pa, (void*) &summand_1_pas, (void*) &summand_1_pl, (void*) &summand_1_pls, (void*) &summand_1_pm, (void*) &summand_1_pms,
        (void*) &summand_1_poa, (void*) &summand_1_poas, (void*) &summand_1_pol, (void*) &summand_1_pols, (void*) &summand_1_pom, (void*) &summand_1_poms,
        (void*) &summand_1_ca, (void*) &summand_1_cas, (void*) &summand_1_cl, (void*) &summand_1_cls, (void*) &summand_1_cm, (void*) &summand_1_cms);

    get_model_part_by_name(p0, p3, p4,
        (void*) &summand_2_pa, (void*) &summand_2_pas, (void*) &summand_2_pl, (void*) &summand_2_pls, (void*) &summand_2_pm, (void*) &summand_2_pms,
        (void*) &summand_2_poa, (void*) &summand_2_poas, (void*) &summand_2_pol, (void*) &summand_2_pols, (void*) &summand_2_pom, (void*) &summand_2_poms,
        (void*) &summand_2_ca, (void*) &summand_2_cas, (void*) &summand_2_cl, (void*) &summand_2_cls, (void*) &summand_2_cm, (void*) &summand_2_cms);

    get_model_part_by_name(p0, p5, p6,
        (void*) &sum_pa, (void*) &sum_pas, (void*) &sum_pl, (void*) &sum_pls, (void*) &sum_pm, (void*) &sum_pms,
        (void*) &sum_poa, (void*) &sum_poas, (void*) &sum_pol, (void*) &sum_pols, (void*) &sum_pom, (void*) &sum_poms,
        (void*) &sum_ca, (void*) &sum_cas, (void*) &sum_cl, (void*) &sum_cls, (void*) &sum_cm, (void*) &sum_cms);

    // Execute addition.
    sum_pm = summand_1_pm + summand_2_pm;

/*??
    Currently, addition is only for integers.
    Later, distinguish between addition of: integer, double, fraction, complex, string!
    Compare abstractions to find out about type of operand?

    // The comparison result.
    int r = 0;

    compare_arrays((void*) &summand_1_pa, (void*) &summand_1_pas, (void*) &INTEGER_MODEL, (void*) &INTEGER_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);
    compare_arrays((void*) &summand_2_pa, (void*) &summand_2_pas, (void*) &INTEGER_MODEL, (void*) &INTEGER_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);
    compare_arrays((void*) &sum_pa, (void*) &sum_pas, (void*) &INTEGER_MODEL, (void*) &INTEGER_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

    if (r == 1) {

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not execute add. The summand 0 is null.");
    }
*/
};

/* ADD_SOURCE */
#endif
