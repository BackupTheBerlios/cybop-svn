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
 * @version $RCSfile: checker.c,v $ $Revision: 1.72 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/model/log/level_log_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/name/memory/internal_memory_memory_name.c"
#include "../controller/checker/signal_checker.c"
#include "../executor/accessor/getter.c"
#include "../logger/logger.c"

/**
 * Checks the signal memory for signals.
 *
 * @param p0 the internal memory
 */
void check(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL, (void*) CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL_COUNT);

    // CAUTION! The parameters were not handed over as function arguments,
    // since it is more flexible to just hand over the internal memory as argument.
    //
    // It is very likely that new services (besides gnu/linux console, x window system, socket etc.)
    // will be added in the future. So it is easier not to have to change the function arguments,
    // but instead just retrieve them from the internal memory below.
    //
    // CAUTION! ALL parameters are retrieved from the internal memory HERE,
    // since doing so within the loop further below would eat up precious cpu time.

    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The knowledge memory.
    void** k = NULL_POINTER_MEMORY_MODEL;
    void** kc = NULL_POINTER_MEMORY_MODEL;
    void** ks = NULL_POINTER_MEMORY_MODEL;
    // The signal memory.
    void** s = NULL_POINTER_MEMORY_MODEL;
    void** sc = NULL_POINTER_MEMORY_MODEL;
    void** ss = NULL_POINTER_MEMORY_MODEL;
    // The signal memory sleep time.
    void** signal_memory_sleep_time = NULL_POINTER_MEMORY_MODEL;

    // Get knowledge memory internals.
    get((void*) &k, p0, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &kc, p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &ks, p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory internals.
    get((void*) &s, p0, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sc, p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &ss, p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory sleep time.
    get((void*) &signal_memory_sleep_time, p0, (void*) SIGNAL_MEMORY_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The shutdown flag.
    int f = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Run endless loop checking signal memory for signals.
    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (f == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, *k, *kc, *ks, *s, *sc, *ss, (void*) &f, *signal_memory_sleep_time);
    }
}

/* CHECKER_SOURCE */
#endif
