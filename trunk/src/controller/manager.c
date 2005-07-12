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
 * @version $Revision: 1.2 $ $Date: 2005-07-12 13:35:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include "../applicator/create.c"
#include "../applicator/destroy.c"
//?? #include "../controller/internals_memory_manager.c"
#include "../controller/knowledge_memory_manager.c"
#include "../controller/signal_memory_manager.c"
#include "../controller/checker.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/constant.c"
#include "../globals/constants/integer_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/variables.c"
#include "../memoriser/array/array.c"
#include "../memoriser/creator/integer_creator.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup knowledge memory (statics = state knowledge + logic knowledge)
 * - startup signal memory
 * - startup input output
 * - create startup signal and add to signal memory
 * - run signal waiting loop (dynamics)
 * - destroy startup signal
 * - shutdown input output
 * - shutdown signal memory
 * - shutdown knowledge memory (statics = state knowledge + logic knowledge)
 *
 * @param p0 the internals memory
 * @param p1 the run source
 * @param p2 the run source count
 */
void manage(void* p0, void* p1, void* p2) {

    log_message_debug("Manage system.");

    if (p0 != NULL_POINTER) {

        startup_knowledge_memory(p0);
        startup_signal_memory(p0);

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

        // Initialize startup model abstraction, model, details.
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
            p1, p2,
            CYBOL_ABSTRACTION, CYBOL_ABSTRACTION_COUNT,
            FILE_CHANNEL, FILE_CHANNEL_COUNT );
        // CAUTION! Do not create startup model details!
        // It is not needed for the startup signal.

        log_message_debug("Add startup model as signal to signal memory.");

        // The signal memory.
        void** s = POINTER_NULL_POINTER;
        void** sc = POINTER_NULL_POINTER;
        void** ss = POINTER_NULL_POINTER;

        // Get signal memory.
        get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_ARRAY);

        if (s != POINTER_NULL_POINTER) {

            if (sc != POINTER_NULL_POINTER) {

                if (ss != POINTER_NULL_POINTER) {

                    // The signal id.
                    int* id = INTEGER_NULL_POINTER;
                    create_integer((void*) &id);
                    *id = 0;
                    get_new_signal_id(*s, *sc, (void*) id);

                    fprintf(stderr, "p: %i\n", *NORMAL_PRIORITY);
                    fprintf(stderr, "id: %i\n", *id);
                    fprintf(stderr, "s: %i\n", *s);
                    fprintf(stderr, "sc: %i\n", *((int*) *sc));
                    fprintf(stderr, "ss: %i\n", *((int*) *ss));

                    // Add startup signal to signal memory.
                    set_signal(*s, *sc, *ss,
                        ma, (void*) mac,
                        mm, (void*) mmc,
                        md, (void*) mdc,
                        (void*) NORMAL_PRIORITY, (void*) id);

                    // The system is now started up and complete so that a loop
                    // can be entered, checking for signals (events/ interrupts)
                    // which are stored/ found in the signal memory.
                    // The loop is left as soon as its shutdown flag is set.
                    check(p0);

                } else {

                    log_message_debug("Could not manage system. The signal memory size is null.");
                }

            } else {

                log_message_debug("Could not manage system. The signal memory count is null.");
            }

        } else {

            log_message_debug("Could not manage system. The signal memory is null.");
        }

        shutdown_signal_memory(p0);
        shutdown_knowledge_memory(p0);

    } else {

        log_message_debug("Could not manage system. The internal memory is null.");
    }
}

/* MANAGER_SOURCE */
#endif
