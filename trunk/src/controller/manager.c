/*
 * $RCSfile: manager.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.9 $ $Date: 2005-07-22 22:42:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include "../controller/checker.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/variables.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup internal memory
 * - startup knowledge memory (statics = state knowledge + logic knowledge)
 * - startup signal memory
 * - create startup signal and add to signal memory
 * - run signal checker loop (dynamics)
 * - destroy startup signal
 * - shutdown signal memory
 * - shutdown knowledge memory (statics = state knowledge + logic knowledge)
 * - shutdown internal memory
 *
 * @param p0 the run source
 * @param p1 the run source count
 */
void manage(const void* p0, const void* p1) {

    log_message_debug("\n\n");
    log_message_debug("Manage system.");

    // The internal memory.
    void* i = NULL_POINTER;
    const int* ic = INTERNAL_MEMORY_ELEMENTS_COUNT;
    const int* is = INTERNAL_MEMORY_ELEMENTS_COUNT;
    // The knowledge memory.
    void* k = NULL_POINTER;
    int* kc = NULL_POINTER;
    int* ks = NULL_POINTER;
    // The signal memory.
    void* s = NULL_POINTER;
    int* sc = NULL_POINTER;
    int* ss = NULL_POINTER;

    // Create knowledge memory count, size.
    create_integer((void*) &kc);
    create_integer((void*) &ks);
    // Create signal memory count, size.
    create_integer((void*) &sc);
    create_integer((void*) &ss);

    // Initialise knowledge memory count, size.
    *kc = 0;
    *ks = 0;
    // Initialise signal memory count, size.
    *sc = 0;
    *ss = 0;

    // Create internal memory.
    create((void*) &i, (void*) is, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT);
    // Create knowledge memory.
    create((void*) &k, (void*) ks, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    // Create signal memory.
    create((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT);

    // CAUTION! ONLY ONE parameter can be handed over to threads!
    // For example, the tcp socket is running in an own thread.
    // Therefore, the knowledge memory and signal memory NEED TO BE ADDED
    // to the internal memory, in order to be forwardable to threads.

    // Set knowledge memory internals.
    set_array_elements(i, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(i, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(i, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    // Set signal memory internals.
    set_array_elements(i, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(i, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);
    set_array_elements(i, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

    log_message_debug("\n\n");
    log_message_debug("Create startup model.");

    // The startup model abstraction, model, details.
    void* ma = NULL_POINTER;
    int* mac = INTEGER_NULL_POINTER;
    int* mas = INTEGER_NULL_POINTER;
    void* mm = NULL_POINTER;
    int* mmc = INTEGER_NULL_POINTER;
    int* mms = INTEGER_NULL_POINTER;
    void* md = NULL_POINTER;
    int* mdc = INTEGER_NULL_POINTER;
    int* mds = INTEGER_NULL_POINTER;

    // Create startup model abstraction, model, details.
    create_integer((void*) &mac);
    create_integer((void*) &mas);
    create_integer((void*) &mmc);
    create_integer((void*) &mms);
    // CAUTION! Do not create startup model details!
    // It is not needed for the startup signal.

    // Initialise startup model abstraction, model, details.
    *mac = 0;
    *mas = 0;
    *mmc = 0;
    *mms = 0;
    // CAUTION! Do not create startup model details!
    // It is not needed for the startup signal.

    // Create startup model abstraction, model, details.
    create_model((void*) &ma, (void*) mac, (void*) mas,
        (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT,
        (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
        (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
    create_model((void*) &mm, (void*) mmc, (void*) mms,
        p0, p1,
        CYBOL_ABSTRACTION, CYBOL_ABSTRACTION_COUNT,
        FILE_CHANNEL, FILE_CHANNEL_COUNT );
    // CAUTION! Do not create startup model details!
    // It is not needed for the startup signal.

    log_message_debug("\n\n");
    log_message_debug("Add startup model as signal to signal memory.");

    // The signal id.
    int* id = INTEGER_NULL_POINTER;
    create_integer((void*) &id);
    *id = 0;
    get_new_signal_id(s, (void*) sc, (void*) id);

/*??
    fprintf(stderr, "p: %i\n", *NORMAL_PRIORITY);
    fprintf(stderr, "id: %i\n", *id);
    fprintf(stderr, "s: %i\n", s);
    fprintf(stderr, "sc: %i\n", sc);
    fprintf(stderr, "ss: %i\n", ss);
*/

    // Add startup signal to signal memory.
    set_signal(s, (void*) sc, (void*) ss, ma, (void*) mac, mm, (void*) mmc, md, (void*) mdc, (void*) NORMAL_PRIORITY, (void*) id);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(i, k, (void*) kc, (void*) ks, s, (void*) sc, (void*) ss);

    // Destroy signal memory.
    destroy((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT);
    destroy_integer((void*) &sc);
    destroy_integer((void*) &ss);
    // Destroy knowledge memory.
    destroy((void*) &k, (void*) ks, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    destroy_integer((void*) &kc);
    destroy_integer((void*) &ks);
    // Destroy internal memory.
    destroy((void*) &i, (void*) is, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT);
}

/* MANAGER_SOURCE */
#endif
