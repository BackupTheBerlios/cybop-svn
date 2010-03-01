/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: branch_guider.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BRANCH_GUIDER_SOURCE
#define BRANCH_GUIDER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/flow/branch_flow_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18);

/**
 * Branches the program flow, depending on a flag.
 *
 * Expected parameters:
 * - criterion (required): the flag specifying which of the two models to execute
 * - true (required): the logic knowledge model to be executed if the condition is true
 * - false (required): the logic knowledge model to be executed if the condition is false
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the parameters
 * @param p11 the parameters count
 * @param p12 the priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 */
void guide_branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Branch program flow.");

    // The criterion name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;
    // The true model name, abstraction, model, details.
    void** tn = NULL_POINTER_MEMORY_MODEL;
    void** tnc = NULL_POINTER_MEMORY_MODEL;
    void** tns = NULL_POINTER_MEMORY_MODEL;
    void** ta = NULL_POINTER_MEMORY_MODEL;
    void** tac = NULL_POINTER_MEMORY_MODEL;
    void** tas = NULL_POINTER_MEMORY_MODEL;
    void** tm = NULL_POINTER_MEMORY_MODEL;
    void** tmc = NULL_POINTER_MEMORY_MODEL;
    void** tms = NULL_POINTER_MEMORY_MODEL;
    void** td = NULL_POINTER_MEMORY_MODEL;
    void** tdc = NULL_POINTER_MEMORY_MODEL;
    void** tds = NULL_POINTER_MEMORY_MODEL;
    // The false model name, abstraction, model, details.
    void** fn = NULL_POINTER_MEMORY_MODEL;
    void** fnc = NULL_POINTER_MEMORY_MODEL;
    void** fns = NULL_POINTER_MEMORY_MODEL;
    void** fa = NULL_POINTER_MEMORY_MODEL;
    void** fac = NULL_POINTER_MEMORY_MODEL;
    void** fas = NULL_POINTER_MEMORY_MODEL;
    void** fm = NULL_POINTER_MEMORY_MODEL;
    void** fmc = NULL_POINTER_MEMORY_MODEL;
    void** fms = NULL_POINTER_MEMORY_MODEL;
    void** fd = NULL_POINTER_MEMORY_MODEL;
    void** fdc = NULL_POINTER_MEMORY_MODEL;
    void** fds = NULL_POINTER_MEMORY_MODEL;

    // Get criterion.
    get_universal_compound_element_by_name(
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p10, p11,
        (void*) CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME, (void*) CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p1, p2);

    // Get true model.
    get_universal_compound_element_by_name(
        (void*) &tn, (void*) &tnc, (void*) &tns,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p10, p11,
        (void*) TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME, (void*) TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p1, p2);

    // Get false model.
    get_universal_compound_element_by_name(
        (void*) &fn, (void*) &fnc, (void*) &fns,
        (void*) &fa, (void*) &fac, (void*) &fas,
        (void*) &fm, (void*) &fmc, (void*) &fms,
        (void*) &fd, (void*) &fdc, (void*) &fds,
        p10, p11,
        (void*) FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME, (void*) FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p1, p2);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_equal_arrays(&r, *cm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

    // The direct execution flag.
    int x = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The criterion is true.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *ta, *tac, *tm, *tmc, *td, *tdc, p12, p13, (void*) &x);

    } else {

        // The criterion is false.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *fa, *fac, *fm, *fmc, *fd, *fdc, p12, p13, (void*) &x);
    }
}

/* BRANCH_GUIDER_SOURCE */
#endif
