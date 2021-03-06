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
 * @version $RCSfile: handler.c,v $ $Revision: 1.41 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../controller/handler/compound_handler.c"
#include "../controller/handler/encapsulated_handler.c"
#include "../controller/handler/knowledge_handler.c"
#include "../controller/handler/operation_handler.c"
#include "../logger/logger.c"
#include "../executor/comparator/array_equality_comparator.c"

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

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
    fwprintf(stdout, L"TEST handle ac: %i\n", p11);
    fwprintf(stdout, L"TEST handle *ac: %i\n", *((int*) p11));
    fwprintf(stdout, L"TEST handle a: %i\n", p10);
    fwprintf(stdout, L"TEST handle *a: %ls\n", (wchar_t*) p10);
*/

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! Do NOT remove this section with "COMPOUND_MEMORY_ABSTRACTION"!
        // It is needed for at least initial startup logic residing in CYBOL
        // files only, before any logic is created and contained as runtime
        // knowledge models in the knowledge memory.
        compare_equal_arrays((void*) &r, p10, p11, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            handle_encapsulated(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            handle_knowledge(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p16, p17, p18);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) OPERATION_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            handle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_LOG_MODEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_LOG_MODEL_COUNT);
    }
}

/* HANDLER_SOURCE */
#endif
