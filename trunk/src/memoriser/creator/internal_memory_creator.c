/*
 * $RCSfile: internal_memory_creator.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-07-12 14:19:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_CREATOR_SOURCE
#define INTERNAL_MEMORY_CREATOR_SOURCE

#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array/array.c"

/**
 * Creates the internal memory.
 *
 * @param p0 the internal memory (Hand over as reference!)
 * @param p1 the internal memory size
 */
void create_internal_memory(void* p0, const void* p1) {

    log_message_debug("Create internal memory.");

    // Create internal memory.
    create_array(p0, p1, (void*) POINTER_ARRAY);
}

/**
 * Destroys the internal memory.
 *
 * All configuration parameters are destroyed first,
 * before the actual internal memory pointer array.
 *
 * @param p0 the internal memory (Hand over as reference!)
 * @param p1 the internal memory size
 */
void destroy_internal_memory(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* s = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** i = (void**) p0;

            log_message_debug("Destroy internal memory.");

            // The loop variable.
            int j = 0;
            // The configuration parameter.
            void* p = NULL_POINTER;

            while (1) {

                if (j >= *s) {

                    break;
                }

                // Get all configuration parameters from internal memory and
                // destroy those which are existent (unequal NULL_POINTER).
                // The p0 parameter needs to be dereferenced since it is handed over
                // as reference, but this procedure expects a normal array.
                get_array_elements(*i, (void*) &j, (void*) &p, (void*) POINTER_ARRAY);

                // CAUTION! Do not try to remove the parameters!
                // Each configuration parameter has a fixed position within the
                // internal memory and CANNOT be removed.

                if (p != NULL_POINTER) {

                    // The internal memory is a simple pointer array and does NOT
                    // hold type information about its stored configuration parameters.
                    // This is possible because the type information is known
                    // IN CONTEXT, wherever a configuration parameter is used.
                    // In order to call the correct array desctruction procedure
                    // (in other words: the correct array type),
                    // all configuration parameters need to be distinguished here,
                    // via conditional if-else statements.

                    if (j == *KNOWLEDGE_MEMORY_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

                    } else if (j == *KNOWLEDGE_MEMORY_COUNT_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *KNOWLEDGE_MEMORY_SIZE_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *SIGNAL_MEMORY_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

                    } else if (j == *SIGNAL_MEMORY_COUNT_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *SIGNAL_MEMORY_SIZE_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *TCP_SERVER_SOCKET_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

//                    } else if (j == *TCP_SERVER_SOCKET_PORT_INTERNAL) {
//
//                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);
//
                    } else if (j == *TCP_SERVER_SOCKET_ACTIVE_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *TCP_CLIENT_SOCKETS_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

                    } else if (j == *TCP_CLIENT_SOCKETS_COUNT_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *TCP_CLIENT_SOCKETS_SIZE_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

                    } else if (j == *TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);

                    } else if (j == *TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL) {

                        destroy_array(p, (void*) ONE_INTEGER, (void*) INTEGER_ARRAY);
                    }

                    //?? TODO: some variables are missing here which causes memory leaks!!
                }

                // Reset configuration parameter.
                p = NULL_POINTER;

                j++;
            }

        } else {

            log_message_debug("Could not destroy internal memory. The internal memory parameter is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
    }

    // Destroy internal memory.
    destroy_array(p0, p1, (void*) POINTER_ARRAY);
}

/* INTERNAL_MEMORY_CREATOR_SOURCE */
#endif