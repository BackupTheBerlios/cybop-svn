/*
 * $RCSfile: signal_memory_creator.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * This file contains the functionality to:
 * - create a signal memory in memory
 *
 * @version $Revision: 1.5 $ $Date: 2004-12-20 00:19:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_CREATOR_SOURCE
#define SIGNAL_MEMORY_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the signal memory.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void create_signal_memory(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Create signal memory.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT);

    // The abstractions, models, details, priorities, main signal id.
    void* sa = NULL_POINTER;
    void* sac = NULL_POINTER;
    void* sm = NULL_POINTER;
    void* smc = NULL_POINTER;
    void* sd = NULL_POINTER;
    void* sdc = NULL_POINTER;
    void* sp = NULL_POINTER;
    void* msid = NULL_POINTER;

    // Create abstractions, models, details, priorities.
    create_array((void*) &sa, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &sac, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &sm, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &smc, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &sd, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &sdc, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &sp, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &msid, (void*) &POINTER_ARRAY, p1);

    // Set abstractions, models, details, priorities.
    // CAUTION! Use ascending order, as compared to destruction!
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_INDEX, (void*) &sd, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &sdc, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX, (void*) &msid, (void*) &ONE_ELEMENT_COUNT);
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void destroy_signal_memory(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_SIGNAL_MEMORY_MESSAGE, (void*) &DESTROY_SIGNAL_MEMORY_MESSAGE_COUNT);

    // The abstractions, models, details, priorities, main signal id.
    void* sa = NULL_POINTER;
    void* sac = NULL_POINTER;
    void* sm = NULL_POINTER;
    void* smc = NULL_POINTER;
    void* sd = NULL_POINTER;
    void* sdc = NULL_POINTER;
    void* sp = NULL_POINTER;
    void* ids = NULL_POINTER;

/*??
    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy all signals left in signal memory.");

    int i = 0;
    get_array_count(m->signals, (void*) &i);
    i--;
    void* s = NULL_POINTER;
    void* a = NULL_POINTER;

    while (i >= 0) {

        s = (void*) get_signal(p0, (void*) &i);
        a = (void*) get_abstraction(p0, (void*) &i);
        // Priority is not needed to destroy the signal.

        // Abstraction and priority are removed internally,
        // together with the signal.
        remove_signal(p0, (void*) &i);

        // Destroy signal. Do not destroy the signal's abstraction and
        // priority here; they are static within CYBOI.
        destroy_model(s, NULL, NULL, (void*) a);

        i--;
    }
*/

    // Get abstractions, models, details, priorities.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_INDEX, (void*) &sd, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &sdc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX, (void*) &ids, (void*) &ONE_ELEMENT_COUNT);

    // Remove abstractions, models, details, priorities.
    // CAUTION! Use descending order, as compared to creation!
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_DETAILS_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_MODELS_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX, (void*) &ONE_ELEMENT_COUNT);

    // Destroy abstractions, models, details, priorities.
    destroy_array((void*) &sa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &sac, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &sm, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &smc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &sd, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &sdc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &sp, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &ids, (void*) &POINTER_ARRAY, p1);

    // Destroy signal memory.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT);
}

/* SIGNAL_MEMORY_CREATOR_SOURCE */
#endif
