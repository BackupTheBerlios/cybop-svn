/*
 * $RCSfile: signal_memory_creator.c,v $
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
 * This file contains the functionality to:
 * - create a signal memory in memory
 *
 * @version $Revision: 1.14 $ $Date: 2005-01-20 12:11:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_CREATOR_SOURCE
#define SIGNAL_MEMORY_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory (Hand over as reference!)
 * @param p1 the signal memory size
 */
void create_signal_memory(void* p0, const void* p1) {

    if (p0 != NULL_POINTER) {

        void** s = (void**) p0;

        log_message((void*) INFO_LOG_LEVEL, (void*) CREATE_SIGNAL_MEMORY_MESSAGE, (void*) CREATE_SIGNAL_MEMORY_MESSAGE_COUNT);

        // Create signal memory.
        create_array(p0, (void*) SIGNAL_MEMORY_COUNT, (void*) POINTER_ARRAY);

        // The abstractions, models, details, priorities, identifications.
        void* a = NULL_POINTER;
        void* ac = NULL_POINTER;
        void* m = NULL_POINTER;
        void* mc = NULL_POINTER;
        void* d = NULL_POINTER;
        void* dc = NULL_POINTER;
        void* p = NULL_POINTER;
        void* id = NULL_POINTER;

        // Create abstractions, models, details, priorities, identifications.
        create_array((void*) &a, p1, (void*) POINTER_ARRAY);
        create_array((void*) &ac, p1, (void*) POINTER_ARRAY);
        create_array((void*) &m, p1, (void*) POINTER_ARRAY);
        create_array((void*) &mc, p1, (void*) POINTER_ARRAY);
        create_array((void*) &d, p1, (void*) POINTER_ARRAY);
        create_array((void*) &dc, p1, (void*) POINTER_ARRAY);
        create_array((void*) &p, p1, (void*) POINTER_ARRAY);
        create_array((void*) &id, p1, (void*) POINTER_ARRAY);

        // Set abstractions, models, details, priorities, identifications.
        // CAUTION! Use ascending order, as compared to destruction!
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        set_array_elements(*s, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(*s, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("Could not create signal memory. The signal memory parameter is null.");
    }
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory (Hand over as reference!)
 * @param p1 the signal memory size
 */
void destroy_signal_memory(void* p0, const void* p1) {

    if (p0 != NULL_POINTER) {

        void** s = (void**) p0;

        log_message((void*) INFO_LOG_LEVEL, (void*) DESTROY_SIGNAL_MEMORY_MESSAGE, (void*) DESTROY_SIGNAL_MEMORY_MESSAGE_COUNT);

        // The abstractions, models, details, priorities, identifications.
        void* a = NULL_POINTER;
        void* ac = NULL_POINTER;
        void* m = NULL_POINTER;
        void* mc = NULL_POINTER;
        void* d = NULL_POINTER;
        void* dc = NULL_POINTER;
        void* p = NULL_POINTER;
        void* id = NULL_POINTER;

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

        // Get abstractions, models, details, priorities, identifications.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        get_array_elements(*s, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
        get_array_elements(*s, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

        // Remove abstractions, models, details, priorities, identifications.
        // CAUTION! Use descending order as compared to creation, for faster removal.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_PRIORITIES_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_DETAILS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_MODELS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        remove_array_elements(*s, (void*) SIGNAL_MEMORY_COUNT, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

        // Destroy abstractions, models, details, priorities, identifications.
        // CAUTION! Do NOT hand over as reference!
        // The variables are of type void**.
        // The expression (&*variable) is the same like (variable).
        destroy_array((void*) a, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) ac, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) m, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) mc, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) d, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) dc, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) p, p1, (void*) POINTER_ARRAY);
        destroy_array((void*) id, p1, (void*) POINTER_ARRAY);

        // Destroy signal memory.
        destroy_array(p0, (void*) SIGNAL_MEMORY_COUNT, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("Could not destroy signal memory. The signal memory parameter is null.");
    }
}

/* SIGNAL_MEMORY_CREATOR_SOURCE */
#endif
