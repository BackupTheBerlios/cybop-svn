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
 * @version $RCSfile: handler.c,v $ $Revision: 1.30 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../controller/handler/compound_handler.c"
#include "../controller/handler/operation_handler.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../memoriser/array.c"

/**
 * Handles the signal.
 *
 * This procedure identifies the signal abstraction and then calls either
 * the compound signal handler, or the operation signal handler procedure.
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
 * @param p10 the abstraction
 * @param p11 the abstraction count
 * @param p12 the model / signal
 * @param p13 the model / signal count
 * @param p14 the details / parameters
 * @param p15 the details / parameters count
 * @param p16 the priority (Hand over as reference!)
 * @param p17 the signal identification (Hand over as reference!)
 * @param p18 the direct execution flag
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Handle signal.");

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
    // The encapsulated logic name, abstraction, model, details.
    void** eln = NULL_POINTER_MEMORY_MODEL;
    void** elnc = NULL_POINTER_MEMORY_MODEL;
    void** elns = NULL_POINTER_MEMORY_MODEL;
    void** ela = NULL_POINTER_MEMORY_MODEL;
    void** elac = NULL_POINTER_MEMORY_MODEL;
    void** elas = NULL_POINTER_MEMORY_MODEL;
    void** elm = NULL_POINTER_MEMORY_MODEL;
    void** elmc = NULL_POINTER_MEMORY_MODEL;
    void** elms = NULL_POINTER_MEMORY_MODEL;
    void** eld = NULL_POINTER_MEMORY_MODEL;
    void** eldc = NULL_POINTER_MEMORY_MODEL;
    void** elds = NULL_POINTER_MEMORY_MODEL;

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST handle a: %ls\n", (wchar_t*) p10);
    fwprintf(stderr, L"TEST handle ac: %i\n", *((int*) p11));

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! Do NOT remove this section with "COMPOUND_ABSTRACTION"!
        // It is needed for at least initial startup logic residing in CYBOL
        // files only, before any logic is created and contained as runtime
        // knowledge models in the knowledge memory.
        compare_arrays(p10, p11, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Handle compound logic.
            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Get compound logic element as double-encapsulated model.
            //
            // CAUTION!
            // The abstraction of an encapsulated name must always be "character".
            // The details are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model pointing to another model containing a logic name:
            // model="application.record.logic_name"
            //
            // The knowledge root does not have a details container with meta
            // information, which is why a null pointer is handed over here twice.
            //
            // Compare also with procedure "get_universal_compound_element_by_name"
            // in source file "memoriser/accessor/compound_accessor.c"!
            get_compound_element_by_name(p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                p12, p13,
                (void*) &eln, (void*) &elnc, (void*) &elns,
                (void*) &ela, (void*) &elac, (void*) &elas,
                (void*) &elm, (void*) &elmc, (void*) &elms,
                (void*) &eld, (void*) &eldc, (void*) &elds);

            // The knowledge root does not have a details container with meta
            // information, which is why a null pointer is handed over here twice.
            get_compound_element_by_name(p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                *elm, *elmc,
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds);

            // Handle compound logic.
            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *lm, *lmc, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
            // in source file "memoriser/accessor/compound_accessor.c"!
            get_compound_element_by_name(p1, p2, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                p12, p13,
                (void*) &ln, (void*) &lnc, (void*) &lns,
                (void*) &la, (void*) &lac, (void*) &las,
                (void*) &lm, (void*) &lmc, (void*) &lms,
                (void*) &ld, (void*) &ldc, (void*) &lds);

            // Handle compound logic.
            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *lm, *lmc, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Handle simple operation.
            handle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
    }
}

/* HANDLER_SOURCE */
#endif
