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
 * @version $RCSfile: initialiser.c,v $ $Revision: 1.29 $ $Date: 2008-12-31 00:14:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISER_SOURCE
#define INITIALISER_SOURCE

#include "../applicator/communicator/receiving/file_system_receiving_communicator.c"
#include "../controller/checker.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/channel/cybol_channel.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/model/signal_priority_model.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/signal_memory_accessor.c"
#include "../memoriser/allocator.c"

/**
 * Initialises the system with an initial signal.
 *
 * @param p0 the internal memory
 * @param p1 the signal memory
 * @param p2 the signal memory count
 * @param p3 the signal memory size
 * @param p4 the run source
 * @param p5 the run source count
 */
void initialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Initialise system with an initial signal.");

/*??
    // The startup model abstraction, model, details.
    //
    // CAUTION! Do NOT use "normal" int as type for counts and sizes here!
    // The reason is that the "set_signal" function below expects int** parameters.
    // If, for example, the variable mac was an int, then &ac would deliver only int*
    // (but not int**) as parameter to be handed over to the "set_signal" function.
    // All other models (and their counts and sizes) coming from knowledge memory
    // are allocated in the same way when being read from cybol sources.
    //
    // CAUTION! A (transient) knowledge model channel is not created,
    // since that is only needed temporarily for model loading.
    void* ma = *NULL_POINTER_MEMORY_MODEL;
    int* mac = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* mas = (int*) *NULL_POINTER_MEMORY_MODEL;
    void* mm = *NULL_POINTER_MEMORY_MODEL;
    int* mmc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* mms = (int*) *NULL_POINTER_MEMORY_MODEL;
    void* md = *NULL_POINTER_MEMORY_MODEL;
    int* mdc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* mds = (int*) *NULL_POINTER_MEMORY_MODEL;
*/

    // The part name.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* nc = *NULL_POINTER_MEMORY_MODEL;
    void* ns = *NULL_POINTER_MEMORY_MODEL;
    // The part abstraction.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;
    // The part model.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* ms = *NULL_POINTER_MEMORY_MODEL;
    // The part details.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    void* ds = *NULL_POINTER_MEMORY_MODEL;

    // Allocate destination part.
    // CAUTION! Use the temporary RUNTIME abstraction as source here!
    allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

    // Decode (in this case just copy) abstraction.
    replace((void*) &a, (void*) ac, (void*) as, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Receive and decode destination part model and details.
    // CAUTION! Use the original CYBOL abstraction as source here!
    communicate_receiving_with_parameters(*NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p4, p5, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add initial signal to signal memory.");

    // The signal identification.
    void** id = NULL_POINTER_MEMORY_MODEL;

    // Get new signal identification by incrementing the current maximum signal's one.
    get_new_signal_identification(p1, p2, (void*) &id);

    // Add startup signal to signal memory.
    set_signal(p1, p2, p3, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) id);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(p0);

/*??
    // Deallocate startup model abstraction, model, details.
    deallocate((void*) &a, (void*) mas, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &ac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &as, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &m, (void*) mms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &mc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &ms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &d, (void*) mds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &dc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &ds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION_COUNT);
*/
}

/* INITIALISER_SOURCE */
#endif
