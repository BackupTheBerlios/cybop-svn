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
 * @version $RCSfile: knowledge_handler.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef KNOWLEDGE_HANDLER_SOURCE
#define KNOWLEDGE_HANDLER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../controller/handler/operation_handler.c"
#include "../../controller/handler/part_handler.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Handles a knowledge logic.
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
 * @param p10 the model / signal
 * @param p11 the model / signal count
 * @param p12 the priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 * @param p14 the direct execution flag
 */
void handle_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Handle knowledge.");

    // The logic name, abstraction, model, details.
    void** ln = NULL_POINTER_MEMORY_MODEL;
    void** lnc = NULL_POINTER_MEMORY_MODEL;
    void** lns = NULL_POINTER_MEMORY_MODEL;
    void** la = NULL_POINTER_MEMORY_MODEL;
    void** lac = NULL_POINTER_MEMORY_MODEL;
    void** las = NULL_POINTER_MEMORY_MODEL;
    void** lm = NULL_POINTER_MEMORY_MODEL;
    void** lmc = NULL_POINTER_MEMORY_MODEL;
    void** lms = NULL_POINTER_MEMORY_MODEL;
    void** ld = NULL_POINTER_MEMORY_MODEL;
    void** ldc = NULL_POINTER_MEMORY_MODEL;
    void** lds = NULL_POINTER_MEMORY_MODEL;

    // Get compound logic element as encapsulated model.
    //
    // CAUTION!
    // The abstraction of an encapsulated name must always be "character".
    // The details are uninteresting, since an encapsulated name cannot have
    // constraints. That is, only the model is of interest. It contains the
    // hierarchical name of the knowledge part to be retrieved.
    //
    // Example of a model containing a hierarchical logic name:
    // model="application.record.logic"
    //
    // The knowledge root does not have a details container with meta
    // information, which is why a null pointer is handed over here twice.
    //
    // Compare also with procedure "get_universal_compound_element_by_name"
    // in source file "executor/accessor/getter/compound_getter.c"!
    get_compound_element_by_name(p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p10, p11,
        (void*) &ln, (void*) &lnc, (void*) &lns,
        (void*) &la, (void*) &lac, (void*) &las,
        (void*) &lm, (void*) &lmc, (void*) &lms,
        (void*) &ld, (void*) &ldc, (void*) &lds);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, *la, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, *lac, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *lm, *lmc, p12, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, *la, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, *lac, (void*) OPERATION_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            handle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *lm, *lmc, *ld, *ldc, p12, p13);
        }
    }
}

/* KNOWLEDGE_HANDLER_SOURCE */
#endif
