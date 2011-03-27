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
 * @version $RCSfile: addition_calculator.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADDITION_CALCULATOR_SOURCE
#define ADDITION_CALCULATOR_SOURCE

#include "../../applicator/calculator/addition/character_vector_addition_calculator.c"
#include "../../applicator/calculator/addition/integer_vector_addition_calculator.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/arithmetic/addition_arithmetic_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/equality/array_equality_comparator.c"
#include "../../logger/logger.c"

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
void calculate_addition(void* p0, int* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Add two primitive summands resulting in the sum.");

    // The abstraction name, abstraction, model, details.
    void** an = NULL_POINTER_MEMORY_MODEL;
    void** anc = NULL_POINTER_MEMORY_MODEL;
    void** ans = NULL_POINTER_MEMORY_MODEL;
    void** aa = NULL_POINTER_MEMORY_MODEL;
    void** aac = NULL_POINTER_MEMORY_MODEL;
    void** aas = NULL_POINTER_MEMORY_MODEL;
    void** am = NULL_POINTER_MEMORY_MODEL;
    void** amc = NULL_POINTER_MEMORY_MODEL;
    void** ams = NULL_POINTER_MEMORY_MODEL;
    void** ad = NULL_POINTER_MEMORY_MODEL;
    void** adc = NULL_POINTER_MEMORY_MODEL;
    void** ads = NULL_POINTER_MEMORY_MODEL;
    // The summand 1 name, abstraction, model, details.
    void** s1n = NULL_POINTER_MEMORY_MODEL;
    void** s1nc = NULL_POINTER_MEMORY_MODEL;
    void** s1ns = NULL_POINTER_MEMORY_MODEL;
    void** s1a = NULL_POINTER_MEMORY_MODEL;
    void** s1ac = NULL_POINTER_MEMORY_MODEL;
    void** s1as = NULL_POINTER_MEMORY_MODEL;
    void** s1m = NULL_POINTER_MEMORY_MODEL;
    void** s1mc = NULL_POINTER_MEMORY_MODEL;
    void** s1ms = NULL_POINTER_MEMORY_MODEL;
    void** s1d = NULL_POINTER_MEMORY_MODEL;
    void** s1dc = NULL_POINTER_MEMORY_MODEL;
    void** s1ds = NULL_POINTER_MEMORY_MODEL;
    // The summand 2 name, abstraction, model, details.
    void** s2n = NULL_POINTER_MEMORY_MODEL;
    void** s2nc = NULL_POINTER_MEMORY_MODEL;
    void** s2ns = NULL_POINTER_MEMORY_MODEL;
    void** s2a = NULL_POINTER_MEMORY_MODEL;
    void** s2ac = NULL_POINTER_MEMORY_MODEL;
    void** s2as = NULL_POINTER_MEMORY_MODEL;
    void** s2m = NULL_POINTER_MEMORY_MODEL;
    void** s2mc = NULL_POINTER_MEMORY_MODEL;
    void** s2ms = NULL_POINTER_MEMORY_MODEL;
    void** s2d = NULL_POINTER_MEMORY_MODEL;
    void** s2dc = NULL_POINTER_MEMORY_MODEL;
    void** s2ds = NULL_POINTER_MEMORY_MODEL;
    // The sum name, abstraction, model, details.
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

    // Get abstraction.
    get_universal_compound_element_by_name(
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p0, p1,
        (void*) ABSTRACTION_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get summand 1.
    get_universal_compound_element_by_name(
        (void*) &s1n, (void*) &s1nc, (void*) &s1ns,
        (void*) &s1a, (void*) &s1ac, (void*) &s1as,
        (void*) &s1m, (void*) &s1mc, (void*) &s1ms,
        (void*) &s1d, (void*) &s1dc, (void*) &s1ds,
        p0, p1,
        (void*) SUMMAND_1_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) SUMMAND_1_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get summand 2.
    get_universal_compound_element_by_name(
        (void*) &s2n, (void*) &s2nc, (void*) &s2ns,
        (void*) &s2a, (void*) &s2ac, (void*) &s2as,
        (void*) &s2m, (void*) &s2mc, (void*) &s2ms,
        (void*) &s2d, (void*) &s2dc, (void*) &s2ds,
        p0, p1,
        (void*) SUMMAND_2_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) SUMMAND_2_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get sum.
    get_universal_compound_element_by_name(
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p0, p1,
        (void*) SUM_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME, (void*) SUM_ADDITION_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, *am, *amc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            calculate_addition_character_vector(sm, *smc, *sms, *s1m, *s1mc, *s2m, *s2mc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, *am, *amc, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            calculate_addition_integer_vector(sm, *smc, *sms, *s1m, *s1mc, *s2m, *s2mc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not add two primitive summands. The abstraction is unknown.");
    }
}

/* ADDITION_CALCULATOR_SOURCE */
#endif
