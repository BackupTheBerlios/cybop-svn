/*
 * $RCSfile: internals_memory_creator.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-01-07 00:07:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNALS_MEMORY_CREATOR_SOURCE
#define INTERNALS_MEMORY_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Creates the internals memory.
 *
 * @param p0 the internals memory
 * @param p1 the internals memory size
 */
void create_internals_memory(void* p0, const void* p1) {

    log_message_debug("Create internals memory.");

    // Create internals memory.
    create_array(p0, (void*) &POINTER_ARRAY, p1);
}

/**
 * Destroys the internals memory.
 *
 * All configuration parameters are destroyed first,
 * before the actual internals memory pointer array.
 *
 * @param p0 the internals memory
 * @param p1 the internals memory size
 */
void destroy_internals_memory(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int** s = (int**) p1;

        log_message_debug("Destroy internals memory.");

        // The loop variable.
        int* j = INTEGER_NULL_POINTER;
        create_integer((void*) &j);
        *j = 0;

        // The configuration parameter.
        void* p = NULL_POINTER;

        while (1) {

            if (*j >= **s) {

                break;
            }

            // Get all configuration parameters from internals memory and
            // destroy those which are existent (unequal NULL_POINTER).

            get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &j, (void*) &p, (void*) &ONE_ELEMENT_COUNT);

            // CAUTION! Do not try to remove the parameters!
            // Each configuration parameter has a fixed position within the
            // internals memory and CANNOT be removed.

            if (p != NULL_POINTER) {

                // The internals memory is a simple pointer array and does NOT
                // hold type information about its stored configuration parameters.
                // This is possible because the type information is known
                // IN CONTEXT, wherever a configuration parameter is used.
                // In order to call the correct array desctruction procedure
                // (in other words: the correct array type),
                // all configuration parameters need to be distinguished here,
                // via conditional if-else statements.

                if (*j == INTERNALS_STARTUP_CHANNEL) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_CHANNEL_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_CHANNEL_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_ABSTRACTION) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_ABSTRACTION_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_ABSTRACTION_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_MODEL) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_MODEL_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_MODEL_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_SIGNAL_MEMORY) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_SIGNAL_MEMORY_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_SIGNAL_MEMORY_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_PORT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_ACTIVE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_SERVERSOCKETNUMBER) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);
                }
            }

            (*j)++;
        }

        destroy_integer((void*) &j);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
    }

    // Destroy internals memory.
    destroy_array(p0, (void*) &POINTER_ARRAY, p1);
}

/* INTERNALS_MEMORY_CREATOR_SOURCE */
#endif
