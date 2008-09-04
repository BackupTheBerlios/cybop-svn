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
 * @version $RCSfile: initialiser.c,v $ $Revision: 1.19 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISER_SOURCE
#define INITIALISER_SOURCE

#include "../applicator/receive/receive_file_system.c"
#include "../controller/checker.c"
#include "../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/channel/cybol_channel.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/model/memory/pointer_memory_model.c"
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

    // The startup model abstraction, model, details.
    //
    // CAUTION! Do NOT use "normal" int as type for counts and sizes here!
    // The reason is that the "set_signal" function below expects int** parameters.
    // If, for example, the variable mac was an int, then &mac would deliver only int*
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

    // Allocate startup model abstraction, model, details.
    allocate((void*) &mac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mas, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mdc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    // Initialise startup model abstraction, model, details count and size.
    *mac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *mas = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *mmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *mms = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *mds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate startup model abstraction, model, details.
    // CAUTION! The abstraction's abstraction always HAS TO BE "character".
    allocate((void*) &ma, (void*) mas, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mm, (void*) mms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    // CAUTION! The details' abstraction always HAS TO BE "compound".
    allocate((void*) &md, (void*) mds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Decode startup model name, abstraction.
    //
    // CAUTION! The last arguments have to be "CHARACTER_VECTOR_ABSTRACTION"
    // and NOT "WIDE_CHARACTER_VECTOR_ABSTRACTION", because the "decode" function
    // expects multibyte characters (that would normally come from a CYBOL file).
    //
    // CAUTION! The source argument has to be "COMPOUND_ABSTRACTION_ASCII"
    // and NOT "COMPOUND_ABSTRACTION", because a multibyte character string
    // is expected, for conversion into a wide character string,
    // just as would be done with strings read from a CYBOL file.
/*??
    decode((void*) &ma, (void*) mac, (void*) mas, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_ABSTRACTION_ASCII, (void*) COMPOUND_ABSTRACTION_COUNT,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
*/
    decode_utf_8_unicode_character_vector((void*) &ma, (void*) mac, (void*) mas, (void*) TEXT_CYBOL_LANGUAGE_ASCII, (void*) TEXT_CYBOL_LANGUAGE_COUNT);

    fwprintf(stderr, L"TEST initialiser ma: %ls\n", (wchar_t*) ma);
    fwprintf(stderr, L"TEST initialiser mac: %i\n", *mac);

    fwprintf(stderr, L"TEST initialiser p4: %ls\n", (wchar_t*) p4);
    fwprintf(stderr, L"TEST initialiser p5: %i\n", *((int*) p5));

    // Receive startup model model and details (read from file and decode).
    receive_file_system((void*) &mm, (void*) mmc, (void*) mms, (void*) &md, (void*) mdc, (void*) mds,
        p4, p5, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add initial signal to signal memory.");

    // The signal identification.
    void** id = NULL_POINTER_MEMORY_MODEL;

    // Get new signal identification by incrementing the current maximum signal's one.
    get_new_signal_identification(p1, p2, (void*) &id);

    // Add startup signal to signal memory.
    set_signal(p1, p2, p3, (void*) &ma, (void*) &mac, (void*) &mm, (void*) &mmc, (void*) &md, (void*) &mdc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) id);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(p0);

    // Deallocate startup model abstraction, model, details.
    deallocate((void*) &ma, (void*) mas, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mas, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mm, (void*) mms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    deallocate((void*) &mmc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &md, (void*) mds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    deallocate((void*) &mdc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/* INITIALISER_SOURCE */
#endif
