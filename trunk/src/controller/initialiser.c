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
 * @version $RCSfile: initialiser.c,v $ $Revision: 1.33 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISER_SOURCE
#define INITIALISER_SOURCE

#include "../applicator/communicator/receiving_communicator.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../constant/channel/cybol_channel.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/model/signal_priority_model.c"
#include "../controller/checker.c"
#include "../executor/accessor/getter/signal_memory_getter.c"
#include "../executor/memoriser/allocator/model_allocator.c"
#include "../executor/memoriser/deallocator/model_deallocator.c"
#include "../logger/logger.c"

/**
 * Initialises the system with an initial signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the run source
 * @param p4 the run source count
 * @param p5 the internal memory
 */
void initialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Initialise system with an initial signal.");

    // CAUTION! Do NOT use "normal" int as type for startup model counts and sizes below!
    // The reason is that the "set_signal" function below expects int** parameters.
    // If, for example, the variable mac was an int, then &ac would deliver only int*
    // (but not int**) as parameter to be handed over to the "set_signal" function.
    // All other models (and their counts and sizes) coming from knowledge memory
    // are allocated in the same way when being read from cybol sources.

    // The startup model name, abstraction, model, details.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* nc = *NULL_POINTER_MEMORY_MODEL;
    void* ns = *NULL_POINTER_MEMORY_MODEL;
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* ms = *NULL_POINTER_MEMORY_MODEL;
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    void* ds = *NULL_POINTER_MEMORY_MODEL;

    // Allocate startup model.
    allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

    // Copy startup model abstraction.
    replace_array_elements((void*) &a, (void*) ac, (void*) as, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"TEST init mc: %i\n", mc);
    fwprintf(stdout, L"TEST init mc*: %i\n", *((int*) mc));
    fwprintf(stdout, L"TEST init m: %i\n", m);
    fwprintf(stdout, L"TEST init m*: %ls\n", (wchar_t*) m);

    // Receive and decode startup model model and -details.
    communicate_receiving_with_parameters(*NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) &m, mc, ms, (void*) &d, dc, ds,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p3, p4, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);
exit(0);
    fwprintf(stdout, L"TEST init mc: %i\n", mc);
    fwprintf(stdout, L"TEST init mc*: %i\n", *((int*) mc));
    fwprintf(stdout, L"TEST init m: %i\n", m);
    fwprintf(stdout, L"TEST init m*: %ls\n", (wchar_t*) m);

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add initial signal to signal memory.");

    // The signal identification.
    void** id = NULL_POINTER_MEMORY_MODEL;

    // Get new signal identification by incrementing the current maximum signal's one.
    get_new_signal_identification((void*) &id, p0, p1);

    // Add startup model as signal to signal memory.
    set_signal(p0, p1, p2, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) id);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(p5);

    // Deallocate startup model.
    deallocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
}

/* INITIALISER_SOURCE */
#endif
