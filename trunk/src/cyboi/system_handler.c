/*
 * $RCSfile: system_handler.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.8 $ $Date: 2005-01-13 11:38:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SYSTEM_HANDLER_SOURCE
#define SYSTEM_HANDLER_SOURCE

#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../cyboi/knowledge_memory_handler.c"
#include "../cyboi/signal_memory_handler.c"
#include "../cyboi/input_output_handler.c"
#include "../cyboi/signal_waiter.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/constant.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"
#include "../logic/create.c"
#include "../logic/destroy.c"

/**
 * Handles the system.
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
 */
void handle_system(void* p0) {

    log_message_debug("Handle system.");

    startup_knowledge_memory(p0);
    startup_signal_memory(p0);
    startup_input_output(p0);

    log_message_debug("Get startup parameters.");

    // The startup parameters channel, abstraction, model.
    // CAUTION! These were created while reading from the configuration file,
    // and such do not have to be created here!
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;

    // Get startup parameters channel, abstraction, model.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_CHANNEL_INTERNAL, (void*) &pc);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_CHANNEL_COUNT_INTERNAL, (void*) &pcc);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_ABSTRACTION_INTERNAL, (void*) &pa);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_ABSTRACTION_COUNT_INTERNAL, (void*) &pac);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_MODEL_INTERNAL, (void*) &pm);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_MODEL_COUNT_INTERNAL, (void*) &pmc);

    log_message_debug("Create startup model.");

    // The startup model abstraction, model, details.
    void** ma = POINTER_NULL_POINTER;
    int* mac = INTEGER_NULL_POINTER;
    int* mas = INTEGER_NULL_POINTER;
    void** mm = POINTER_NULL_POINTER;
    int* mmc = INTEGER_NULL_POINTER;
    int* mms = INTEGER_NULL_POINTER;
    void** md = POINTER_NULL_POINTER;
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
    create_model((void*) &ma, (void*) &mac, (void*) &mas, pa, pac,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
    create_model((void*) &mm, (void*) &mmc, (void*) &mms,
        pm, pmc, pa, pac, pc, pcc);
    // CAUTION! Do not create startup model details!
    // It is not needed for the startup signal.

    log_message_debug("Add startup model as signal to signal memory.");

    // The signal memory.
    void* s = NULL_POINTER;
    void* sc = NULL_POINTER;
    void* ss = NULL_POINTER;

    // Get signal memory.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &s);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss);

    // The signal id.
    int* id = INTEGER_NULL_POINTER;
    create_integer((void*) &id);
    *id = 0;
    get_new_signal_id(s, (void*) &sc, (void*) &id);

    fprintf(stderr, "sm: %i\n", s);
    fprintf(stderr, "smc: %i\n", *((int*) sc));
    fprintf(stderr, "sms: %i\n", *((int*) ss));

    fprintf(stderr, "ma: %i\n", ma);
    fprintf(stderr, "mac: %i\n", mac);
    fprintf(stderr, "mm: %i\n", mm);
    fprintf(stderr, "mmc: %i\n", mmc);
    fprintf(stderr, "md: %i\n", md);
    fprintf(stderr, "mdc: %i\n", mdc);
    fprintf(stderr, "p: %i\n", *NORMAL_PRIORITY);
    fprintf(stderr, "id: %i\n", *id);

    // Add startup signal to signal memory.
    set_signal(s, (void*) &sc, (void*) &ss,
        (void*) &ma, (void*) &mac, (void*) &mm, (void*) &mmc,
        (void*) &md, (void*) &mdc, (void*) &NORMAL_PRIORITY, (void*) &id);

    // The system is now started up and complete so that a loop
    // can be entered, waiting for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    wait(p0);

    // Destroy startup signal.
    // CAUTION! All signals are destroyed in the signal waiting loop,
    // after having been read from the signal memory.
    // Since this also counts for the startup signal,
    // it MUST NOT be destroyed here!
    // However, the startup signal's MODEL needs to be destroyed.

    log_message_debug("Destroy startup model.");

    // CAUTION! Do not destroy startup model details!
    // It was not needed for the startup signal.
    destroy_model((void*) &mm, (void*) &mmc, (void*) &mms,
        pm, pmc, pa, pac, pc, pcc);
    destroy_model((void*) &ma, (void*) &mac, (void*) &mas, pa, pac,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

    // CAUTION! Do not destroy startup model details!
    // It was not needed for the startup signal.
    destroy_integer((void*) &mms);
    destroy_integer((void*) &mmc);
    destroy_integer((void*) &mas);
    destroy_integer((void*) &mac);

    shutdown_input_output(p0);
    shutdown_signal_memory(p0);
    shutdown_knowledge_memory(p0);
}

/* SYSTEM_HANDLER_SOURCE */
#endif
