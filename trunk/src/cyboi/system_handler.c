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
 * @version $Revision: 1.3 $ $Date: 2005-01-09 01:30:12 $ $Author: christian $
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
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_CHANNEL_INTERNAL, (void*) &pc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_CHANNEL_COUNT_INTERNAL, (void*) &pcc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_ABSTRACTION_INTERNAL, (void*) &pa, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_ABSTRACTION_COUNT_INTERNAL, (void*) &pac, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_MODEL_INTERNAL, (void*) &pm, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &STARTUP_MODEL_COUNT_INTERNAL, (void*) &pmc, (void*) &ONE_ELEMENT_COUNT);

    log_message_debug("Create startup model abstraction.");

    // The startup model abstraction count.
    int* mac = INTEGER_NULL_POINTER;
    create_integer((void*) &mac);
    *mac = 0;

    // The startup model abstraction size.
    int* mas = INTEGER_NULL_POINTER;
    create_integer((void*) &mas);
    *mas = 0;

    // The startup model abstraction.
    void* ma = NULL_POINTER;
    create_model((void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &pa, (void*) &pac,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

    log_message_debug("Create startup model model.");

    // The startup model model count.
    int* mmc = INTEGER_NULL_POINTER;
    create_integer((void*) &mmc);
    *mmc = 0;

    // The startup model model size.
    int* mms = INTEGER_NULL_POINTER;
    create_integer((void*) &mms);
    *mms = 0;

    // The startup model model.
    void* mm = NULL_POINTER;
    create_model((void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &pm, (void*) &pmc,
        (void*) &pa, (void*) &pac,
        (void*) &pc, (void*) &pcc);

    log_message_debug("Do not create unnecessary startup model details.");

    // The startup model details.
    int* mdc = INTEGER_NULL_POINTER;
    int* mds = INTEGER_NULL_POINTER;
    void* md = NULL_POINTER;

    // CAUTION! Do not create startup model details!
    // It is not needed for the startup signal.

    log_message_debug("Add startup model as signal to signal memory.");

    // The signal memory.
    void* s = NULL_POINTER;
    void* sc = NULL_POINTER;
    void* ss = NULL_POINTER;

    // Get signal memory.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) &ONE_ELEMENT_COUNT);

    // The signal id.
    int* id = INTEGER_NULL_POINTER;
    create_integer((void*) &id);
    *id = 0;

    // Get new main signal id.
    get_new_signal_id((void*) &s, (void*) &sc, (void*) &id);

    // Add startup signal to signal memory.
    set_signal((void*) &s, (void*) &sc, (void*) &ss,
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

    log_message_debug("Do not destroy nonexistent startup model details.");

    log_message_debug("Destroy startup model model.");

    destroy_model((void*) &mm, (void*) &mmc, (void*) &mms,
        (void*) &pm, (void*) &pmc,
        (void*) &pa, (void*) &pac,
        (void*) &pc, (void*) &pcc);
    destroy_integer((void*) &mms);
    destroy_integer((void*) &mmc);

    log_message_debug("Destroy startup model abstraction.");
    destroy_model((void*) &ma, (void*) &mac, (void*) &mas,
        (void*) &pa, (void*) &pac,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
        (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
    destroy_integer((void*) &mas);
    destroy_integer((void*) &mac);

    shutdown_input_output(p0);
    shutdown_signal_memory(p0);
    shutdown_knowledge_memory(p0);
}

/* SYSTEM_HANDLER_SOURCE */
#endif
