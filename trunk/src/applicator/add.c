/*
 * $RCSfile: add.c,v $
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
 * @version $Revision: 1.22 $ $Date: 2007-10-03 23:40:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

#include "../applicator/add/add_character_vector.c"
#include "../applicator/add/add_integer_vector.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

/**
 * Adds two primitive summands resulting in the sum.
 *
 * Expected parameters:
 * - abstraction (required): the abstraction of the summand 1, summand 2 and sum parameters
 * - summand_1 (required): the first summand for the addition
 * - summand_2 (required): the second summand for the addition
 * - sum (required): the sum resulting from the addition
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void add(void* p0, int* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Add two primitive summands resulting in the sum.");

    // The abstraction name, abstraction, model, details.
    void** an = NULL_POINTER;
    void** anc = NULL_POINTER;
    void** ans = NULL_POINTER;
    void** aa = NULL_POINTER;
    void** aac = NULL_POINTER;
    void** aas = NULL_POINTER;
    void** am = NULL_POINTER;
    void** amc = NULL_POINTER;
    void** ams = NULL_POINTER;
    void** ad = NULL_POINTER;
    void** adc = NULL_POINTER;
    void** ads = NULL_POINTER;
    // The summand 1 name, abstraction, model, details.
    void** s1n = NULL_POINTER;
    void** s1nc = NULL_POINTER;
    void** s1ns = NULL_POINTER;
    void** s1a = NULL_POINTER;
    void** s1ac = NULL_POINTER;
    void** s1as = NULL_POINTER;
    void** s1m = NULL_POINTER;
    void** s1mc = NULL_POINTER;
    void** s1ms = NULL_POINTER;
    void** s1d = NULL_POINTER;
    void** s1dc = NULL_POINTER;
    void** s1ds = NULL_POINTER;
    // The summand 2 name, abstraction, model, details.
    void** s2n = NULL_POINTER;
    void** s2nc = NULL_POINTER;
    void** s2ns = NULL_POINTER;
    void** s2a = NULL_POINTER;
    void** s2ac = NULL_POINTER;
    void** s2as = NULL_POINTER;
    void** s2m = NULL_POINTER;
    void** s2mc = NULL_POINTER;
    void** s2ms = NULL_POINTER;
    void** s2d = NULL_POINTER;
    void** s2dc = NULL_POINTER;
    void** s2ds = NULL_POINTER;
    // The sum name, abstraction, model, details.
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

    // Get abstraction.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COPY_ABSTRACTION_NAME, (void*) COPY_ABSTRACTION_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);
    // Get summand 1.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ADD_SUMMAND_1_NAME, (void*) ADD_SUMMAND_1_NAME_COUNT,
        (void*) &s1n, (void*) &s1nc, (void*) &s1ns,
        (void*) &s1a, (void*) &s1ac, (void*) &s1as,
        (void*) &s1m, (void*) &s1mc, (void*) &s1ms,
        (void*) &s1d, (void*) &s1dc, (void*) &s1ds,
        p2, p3);
    // Get summand 2.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ADD_SUMMAND_2_NAME, (void*) ADD_SUMMAND_2_NAME_COUNT,
        (void*) &s2n, (void*) &s2nc, (void*) &s2ns,
        (void*) &s2a, (void*) &s2ac, (void*) &s2as,
        (void*) &s2m, (void*) &s2mc, (void*) &s2ms,
        (void*) &s2d, (void*) &s2dc, (void*) &s2ds,
        p2, p3);
    // Get sum.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ADD_SUM_NAME, (void*) ADD_SUM_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*am, *amc, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            add_character_vector(sm, *smc, *sms, *s1m, *s1mc, *s2m, *s2mc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(*am, *amc, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            add_integer_vector(sm, *smc, *sms, *s1m, *s1mc, *s2m, *s2mc);
        }
    }
}

/* ADD_SOURCE */
#endif
