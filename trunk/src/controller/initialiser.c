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
#include "../executor/memoriser/deallocator/part_deallocator.c"
#include "../logger/logger.c"

/**
 * Initialises the system with an initial signal.
 *
 * @param p0 the signal memory item
 * @param p1 the run source item
 * @param p2 the internal memory array
 */
void initialise(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Initialise system with startup signal.");

    // CAUTION! Do NOT use "normal" int as type for startup model counts and sizes below!
    // The reason is that the "set_signal" function below expects int** parameters.
    // If, for example, the variable mac was an int, then &ac would deliver only int*
    // (but not int**) as parameter to be handed over to the "set_signal" function.
    // All other models (and their counts and sizes) coming from knowledge memory
    // are allocated in the same way when being read from cybol sources.

    // The startup signal part.
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // Allocate startup signal part.
    allocate_part((void*) &s, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

    // Copy startup signal abstraction, model, details.
    // CAUTION! A name is not necessary, since only
    // the actual model and details are of interest.
    overwrite_part_element(s, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);

    // Receive and decode startup model model and -details.
    //?? TODO! Get file path item data and item count
    //?? and replace 2x p3 below.
    communicate_receiving_with_parameters(*NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) &m, mc, ms, (void*) &d, dc, ds,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p3, p3, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add startup signal to signal memory.");

    // Add part model (signal) to signal memory.
    append_item_element(p0, (void*) &s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(p2);

    // Deallocate startup signal part.
    deallocate_part((void*) &s, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* INITIALISER_SOURCE */
#endif
