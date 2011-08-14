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

    // The message (run source, file name) item data, count.
    void* md = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;

    // Get message item data, count.
    copy_array_forward((void*) &md, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mc, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The startup signal part.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The startup signal part model, details.
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;
    // The startup signal part model data, count, size.
    void* smd = *NULL_POINTER_MEMORY_MODEL;
    void* smc = *NULL_POINTER_MEMORY_MODEL;
    void* sms = *NULL_POINTER_MEMORY_MODEL;
    // The startup signal part details data, count, size.
    void* sdd = *NULL_POINTER_MEMORY_MODEL;
    void* sdc = *NULL_POINTER_MEMORY_MODEL;
    void* sds = *NULL_POINTER_MEMORY_MODEL;

    // Allocate startup signal part.
    allocate_part((void*) &s, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

    // Copy startup signal part abstraction.
    // CAUTION! A name is not necessary, since only
    // the actual model and details are of interest.
    // CAUTION! The model and details are received below.
    overwrite_part_element(s, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);

    // Get startup signal part model, details.
    copy_array_forward((void*) &sm, s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &sd, s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get startup signal part model data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sms, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIZE_ITEM_MEMORY_NAME);
    // Get startup signal part details data, count.
    copy_array_forward((void*) &sdd, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sdc, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sds, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIZE_ITEM_MEMORY_NAME);

    // Receive startup signal model, details.
    apply_receive_file_system((void*) &smd, smc, sms, (void*) &sdd, sdc, sds, md, mc, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT);

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
