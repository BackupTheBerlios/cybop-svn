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
 * @version $RCSfile: branch_guider.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BRANCHER_SOURCE
#define BRANCHER_SOURCE

#include "../globals/constants/boolean/boolean_constants.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../constant/model/log/message_log_model.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

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
 * @param p8 the interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the parameters
 * @param p11 the parameters count
 * @param p12 the priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 */
void branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Branch program flow.");

    // The criterion name, abstraction, model, details.
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
    // The true model name, abstraction, model, details.
    void** tn = NULL_POINTER;
    void** tnc = NULL_POINTER;
    void** tns = NULL_POINTER;
    void** ta = NULL_POINTER;
    void** tac = NULL_POINTER;
    void** tas = NULL_POINTER;
    void** tm = NULL_POINTER;
    void** tmc = NULL_POINTER;
    void** tms = NULL_POINTER;
    void** td = NULL_POINTER;
    void** tdc = NULL_POINTER;
    void** tds = NULL_POINTER;
    // The false model name, abstraction, model, details.
    void** fn = NULL_POINTER;
    void** fnc = NULL_POINTER;
    void** fns = NULL_POINTER;
    void** fa = NULL_POINTER;
    void** fac = NULL_POINTER;
    void** fas = NULL_POINTER;
    void** fm = NULL_POINTER;
    void** fmc = NULL_POINTER;
    void** fms = NULL_POINTER;
    void** fd = NULL_POINTER;
    void** fdc = NULL_POINTER;
    void** fds = NULL_POINTER;

    // Get criterion.
    get_universal_compound_element_by_name(p10, p11,
        (void*) CRITERION_NAME, (void*) CRITERION_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p1, p2);

    // Get true model.
    get_universal_compound_element_by_name(p10, p11,
        (void*) TRUE_MODEL_NAME, (void*) TRUE_MODEL_NAME_COUNT,
        (void*) &tn, (void*) &tnc, (void*) &tns,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p1, p2);

    // Get false model.
    get_universal_compound_element_by_name(p10, p11,
        (void*) FALSE_MODEL_NAME, (void*) FALSE_MODEL_NAME_COUNT,
        (void*) &fn, (void*) &fnc, (void*) &fns,
        (void*) &fa, (void*) &fac, (void*) &fas,
        (void*) &fm, (void*) &fmc, (void*) &fms,
        (void*) &fd, (void*) &fdc, (void*) &fds,
        p1, p2);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_arrays(*cm, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, &r, (void*) INTEGER_ARRAY);

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

/* BRANCHER_SOURCE */
#endif
