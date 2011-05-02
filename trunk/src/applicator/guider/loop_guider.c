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
 * @version $RCSfile: loop_guider.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOOP_GUIDER_SOURCE
#define LOOP_GUIDER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/flow/loop_flow_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/count_array_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18);

/**
 * Loops endlessly, until the break flag is set.
 *
 * Expected parameters:
 * - model (required): the knowledge model to be executed repeatedly by the loop
 * - break (required): the break flag; once set, the loop will be left (exited)
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
void guide_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Loop program flow.");

    // The model name, abstraction, model, details.
    void** mn = NULL_POINTER_MEMORY_MODEL;
    void** mnc = NULL_POINTER_MEMORY_MODEL;
    void** mns = NULL_POINTER_MEMORY_MODEL;
    void** ma = NULL_POINTER_MEMORY_MODEL;
    void** mac = NULL_POINTER_MEMORY_MODEL;
    void** mas = NULL_POINTER_MEMORY_MODEL;
    void** mm = NULL_POINTER_MEMORY_MODEL;
    void** mmc = NULL_POINTER_MEMORY_MODEL;
    void** mms = NULL_POINTER_MEMORY_MODEL;
    void** md = NULL_POINTER_MEMORY_MODEL;
    void** mdc = NULL_POINTER_MEMORY_MODEL;
    void** mds = NULL_POINTER_MEMORY_MODEL;
    // The break flag name, abstraction, model, details.
    void** bn = NULL_POINTER_MEMORY_MODEL;
    void** bnc = NULL_POINTER_MEMORY_MODEL;
    void** bns = NULL_POINTER_MEMORY_MODEL;
    void** ba = NULL_POINTER_MEMORY_MODEL;
    void** bac = NULL_POINTER_MEMORY_MODEL;
    void** bas = NULL_POINTER_MEMORY_MODEL;
    // This value is used as integer below.
    int** bm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** bmc = NULL_POINTER_MEMORY_MODEL;
    void** bms = NULL_POINTER_MEMORY_MODEL;
    void** bd = NULL_POINTER_MEMORY_MODEL;
    void** bdc = NULL_POINTER_MEMORY_MODEL;
    void** bds = NULL_POINTER_MEMORY_MODEL;

    // Get model.
    get_universal_compound_element_by_name(
        (void*) &mn, (void*) &mnc, (void*) &mns,
        (void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &md, (void*) &mdc, (void*) &mds,
        p10, p11,
        (void*) MODEL_LOOP_FLOW_OPERATION_CYBOL_NAME, (void*) MODEL_LOOP_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p1, p2);
    // Get break flag.
    get_universal_compound_element_by_name(
        (void*) &bn, (void*) &bnc, (void*) &bns,
        (void*) &ba, (void*) &bac, (void*) &bas,
        (void*) &bm, (void*) &bmc, (void*) &bms,
        (void*) &bd, (void*) &bdc, (void*) &bds,
        p10, p11,
        (void*) BREAK_LOOP_FLOW_OPERATION_CYBOL_NAME, (void*) BREAK_LOOP_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p1, p2);

    // The direct execution flag.
    // CAUTION! The flag has to be set to true, because otherwise,
    // each loop cycle places a new signal in signal memory so that
    // these would only be processed with a delay.
    // But this is not desirable, since follow-up signals of this
    // loop may rely on its full execution, including all cycles.
    int x = *TRUE_BOOLEAN_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        // Check if break flag is set to true.
        if (**bm != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Leave the loop if the break flag is true.
            break;

        } else {

            // Send the loop model as new signal,
            // as long as the break flag is false (not set).
            handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *ma, *mac, *mm, *mmc, *md, *mdc, p12, p13, (void*) &x);
        }
    }
}

/* LOOP_GUIDER_SOURCE */
#endif
