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
 * @version $Revision: 1.13 $ $Date: 2004-04-21 11:02:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

#include "../logger/log_handler.c"

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

    // Initialize summand 1.
    char* summand_1_pa = NULL_CHARACTER_POINTER;
    int summand_1_pas = 0;
    char* summand_1_pl = NULL_CHARACTER_POINTER;
    int summand_1_pls = 0;
    int summand_1_pm = 0;
    int summand_1_pms = 0;
    char* summand_1_poa = NULL_CHARACTER_POINTER;
    int summand_1_poas = 0;
    char* summand_1_pol = NULL_CHARACTER_POINTER;
    int summand_1_pols = 0;
    void* summand_1_pom = NULL_POINTER;
    int summand_1_poms = 0;
    char* summand_1_ca = NULL_CHARACTER_POINTER;
    int summand_1_cas = 0;
    char* summand_1_cl = NULL_CHARACTER_POINTER;
    int summand_1_cls = 0;
    void* summand_1_cm = NULL_POINTER;
    int summand_1_cms = 0;

    // Initialize summand 2.
    char* summand_2_pa = NULL_CHARACTER_POINTER;
    int summand_2_pas = 0;
    char* summand_2_pl = NULL_CHARACTER_POINTER;
    int summand_2_pls = 0;
    int summand_2_pm = 0;
    int summand_2_pms = 0;
    char* summand_2_poa = NULL_CHARACTER_POINTER;
    int summand_2_poas = 0;
    char* summand_2_pol = NULL_CHARACTER_POINTER;
    int summand_2_pols = 0;
    void* summand_2_pom = NULL_POINTER;
    int summand_2_poms = 0;
    char* summand_2_ca = NULL_CHARACTER_POINTER;
    int summand_2_cas = 0;
    char* summand_2_cl = NULL_CHARACTER_POINTER;
    int summand_2_cls = 0;
    void* summand_2_cm = NULL_POINTER;
    int summand_2_cms = 0;

    // Initialize sum.
    char* sum_pa = NULL_CHARACTER_POINTER;
    int sum_pas = 0;
    char* sum_pl = NULL_CHARACTER_POINTER;
    int sum_pls = 0;
    int sum_pm = 0;
    int sum_pms = 0;
    char* sum_poa = NULL_CHARACTER_POINTER;
    int sum_poas = 0;
    char* sum_pol = NULL_CHARACTER_POINTER;
    int sum_pols = 0;
    void* sum_pom = NULL_POINTER;
    int sum_poms = 0;
    char* sum_ca = NULL_CHARACTER_POINTER;
    int sum_cas = 0;
    char* sum_cl = NULL_CHARACTER_POINTER;
    int sum_cls = 0;
    void* sum_cm = NULL_POINTER;
    int sum_cms = 0;

    // Get operands.
    get_model_part_by_name(p0, p1, p2,
        summand_1_pa, summand_1_pas, summand_1_pl, summand_1_pls, summand_1_pm, summand_1_pms,
        summand_1_poa, summand_1_poas, summand_1_pol, summand_1_pols, summand_1_pom, summand_1_poms,
        summand_1_ca, summand_1_cas, summand_1_cl, summand_1_cls, summand_1_cm, summand_1_cms);

    get_model_part_by_name(p0, p3, p4,
        summand_2_pa, summand_2_pas, summand_2_pl, summand_2_pls, summand_2_pm, summand_2_pms,
        summand_2_poa, summand_2_poas, summand_2_pol, summand_2_pols, summand_2_pom, summand_2_poms,
        summand_2_ca, summand_2_cas, summand_2_cl, summand_2_cls, summand_2_cm, summand_2_cms);

    get_model_part_by_name(p0, p5, p6,
        sum_pa, sum_pas, sum_pl, sum_pls, sum_pm, sum_pms,
        sum_poa, sum_poas, sum_pol, sum_pols, sum_pom, sum_poms,
        sum_ca, sum_cas, sum_cl, sum_cls, sum_cm, sum_cms);

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

        log_message((void*) &ERROR_LOG_LEVEL, "Could not execute add. The summand 0 is null.");
    }
*/
};

/* ADD_SOURCE */
#endif
