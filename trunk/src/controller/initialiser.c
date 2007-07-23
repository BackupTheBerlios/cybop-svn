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
 * @version $Revision: 1.2 $ $Date: 2007-07-23 23:47:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISER_SOURCE
#define INITIALISER_SOURCE

#include "../applicator/receive/receive_file_system.c"
#include "../controller/checker.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/constants/cyboi_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/variables.c"
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

    log_message_debug("\n\n");
    log_message_debug("Information: Initialises the system with an initial signal.");

    // The startup model abstraction, model, details.
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

    // Initialise startup model abstraction, model, details.
    *mac = *NUMBER_0_INTEGER;
    *mas = *NUMBER_0_INTEGER;
    *mmc = *NUMBER_0_INTEGER;
    *mms = *NUMBER_0_INTEGER;
    *mdc = *NUMBER_0_INTEGER;
    *mds = *NUMBER_0_INTEGER;

    // Allocate startup model abstraction, model, details.
    receive_file_system_model((void*) &ma, (void*) mac, (void*) mas,
        *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
        (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
        (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
    receive_file_system_model((void*) &mm, (void*) mmc, (void*) mms,
        *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        p9, p10,
        COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT,
        FILE_CHANNEL, FILE_CHANNEL_COUNT);
    receive_file_system_model((void*) &md, (void*) mdc, (void*) mds,
        *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        *NULL_POINTER, *NULL_POINTER,
        COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT,
        FILE_CHANNEL, FILE_CHANNEL_COUNT);

/*??
    // Add enable parameter model to startup model details.
    set_compound_element_by_name(md, (void*) mdc, (void*) mds,
        (void*) OPERATION_ENABLE_NAME, (void*) OPERATION_ENABLE_NAME_COUNT, (void*) OPERATION_ENABLE_NAME_COUNT,
        (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) BOOLEAN_ABSTRACTION_COUNT,
        (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) PRIMITIVE_COUNT,
        *NULL_POINTER, *NULL_POINTER, *NULL_POINTER);
*/

    log_message_debug("\n\n");
    log_message_debug("Debug: Add initial signal to signal memory.");

    // The signal id.
    int* id = (int*) *NULL_POINTER;
    allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *id = *NUMBER_0_INTEGER;
    get_new_signal_id(p4, p5, (void*) id);

    // Add startup signal to signal memory.
    set_signal(p4, p5, p6, ma, (void*) mac, mm, (void*) mmc, md, (void*) mdc, (void*) NORMAL_PRIORITY, (void*) id);

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
