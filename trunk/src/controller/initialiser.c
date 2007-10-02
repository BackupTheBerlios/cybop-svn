/*
 * $RCSfile: initialiser.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.9 $ $Date: 2007-10-02 21:16:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISER_SOURCE
#define INITIALISER_SOURCE

#include "../applicator/receive/receive_file_system.c"
#include "../controller/checker.c"
#include "../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/signal_memory_accessor.c"
#include "../memoriser/allocator.c"

/**
 * Initialises the system with an initial signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the interrupt request flag
 * @param p8 the signal memory mutex
 * @param p9 the run source
 * @param p10 the run source count
 */
void initialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "\n\n");
    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Information: Initialise system with an initial signal.");

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
    void* ma = *NULL_POINTER;
    int* mac = (int*) *NULL_POINTER;
    int* mas = (int*) *NULL_POINTER;
    void* mm = *NULL_POINTER;
    int* mmc = (int*) *NULL_POINTER;
    int* mms = (int*) *NULL_POINTER;
    void* md = *NULL_POINTER;
    int* mdc = (int*) *NULL_POINTER;
    int* mds = (int*) *NULL_POINTER;

    // Allocate startup model abstraction, model, details.
    allocate((void*) &mac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    // Initialise startup model abstraction, model, details count and size.
    *mac = *NUMBER_0_INTEGER;
    *mas = *NUMBER_0_INTEGER;
    *mmc = *NUMBER_0_INTEGER;
    *mms = *NUMBER_0_INTEGER;
    *mdc = *NUMBER_0_INTEGER;
    *mds = *NUMBER_0_INTEGER;

    // Allocate startup model abstraction, model, details.
    // CAUTION! The abstraction's abstraction always HAS TO BE "character".
    allocate((void*) &ma, (void*) mas, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mm, (void*) mms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    // CAUTION! The details' abstraction always HAS TO BE "compound".
    allocate((void*) &md, (void*) mds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Decode startup model name, abstraction.
    decode((void*) &ma, (void*) mac, (void*) mas, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
        *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    // Receive startup model model and details (read from file and decode).
    receive_file_system((void*) &mm, (void*) mmc, (void*) mms, (void*) &md, (void*) mdc, (void*) mds,
        p9, p10, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "\n\n");
    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Debug: Add initial signal to signal memory.");

    // The signal identification.
    void** id = NULL_POINTER;

    // Get new signal identification by incrementing the current maximum signal's one.
    get_new_signal_identification(p4, p5, (void*) &id);

    // Add startup signal to signal memory.
    set_signal(p4, p5, p6, (void*) &ma, (void*) &mac, (void*) &mm, (void*) &mmc, (void*) &md, (void*) &mdc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) id);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    // Deallocate startup model abstraction, model, details.
    deallocate((void*) &ma, (void*) mas, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mm, (void*) mms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    deallocate((void*) &mmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &md, (void*) mds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    deallocate((void*) &mdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/* INITIALISER_SOURCE */
#endif
