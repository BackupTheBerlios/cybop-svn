/*
 * $RCSfile: checker.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-07-16 00:18:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

#include "../controller/handler.c"
#include "../globals/constants/integer_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/signal_memory_accessor.c"

/**
 * Checks for signals.
 *
 * @param p0 the internal memory
 */
void check(void* p0) {

    log_message((void*) INFO_LOG_LEVEL, (void*) CHECK_FOR_SIGNALS_MESSAGE, (void*) CHECK_FOR_SIGNALS_MESSAGE_COUNT);

    //?? TODO: Debugging stuff from Rolf Holzmueller.
    void** socket_flag = POINTER_NULL_POINTER;
    void** blocking_flag = POINTER_NULL_POINTER;

    // The knowledge memory.
    void** k = POINTER_NULL_POINTER;
    void** kc = POINTER_NULL_POINTER;
    void** ks = POINTER_NULL_POINTER;
    // The signal memory.
    void** s = POINTER_NULL_POINTER;
    void** sc = POINTER_NULL_POINTER;
    void** ss = POINTER_NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_ARRAY);
    // Get signal memory.
    get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_ARRAY);

    if (k != POINTER_NULL_POINTER) {

        if (kc != POINTER_NULL_POINTER) {

            if (ks != POINTER_NULL_POINTER) {

                if (s != POINTER_NULL_POINTER) {

                    if (sc != POINTER_NULL_POINTER) {

                        if (ss != POINTER_NULL_POINTER) {

                            // The shutdown flag.
                            int f = 0;
                            // The abstraction.
                            void** a = POINTER_NULL_POINTER;
                            void** ac = POINTER_NULL_POINTER;
                            // The model (signal operation).
                            void** m = POINTER_NULL_POINTER;
                            void** mc = POINTER_NULL_POINTER;
                            // The details (parameters).
                            void** d = POINTER_NULL_POINTER;
                            void** dc = POINTER_NULL_POINTER;
                            // The priority.
                            void** p = POINTER_NULL_POINTER;
                            // The signal id.
                            void** id = POINTER_NULL_POINTER;
                            // The highest priority index.
                            int i = -1;
                            // The comparison result.
                            int r = 0;
                            // The direct execution flag.
                            int x = 0;

                            // Run endless loop checking signal memory for signals.
                            while (1) {

                                if (f == 1) {

                                    // Leave loop if the shutdown flag was set.
                                    break;
                                }

                                // Get index of the top priority signal.
                                get_highest_priority_index(*s, *sc, (void*) &i);

                                //?? Wait for web input, if no signal is in memory. TODO: Use a thread for this!
                                //debug for rolf Holzm?ller
                                get_array_elements(p0, (void*) TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &socket_flag, (void*) POINTER_ARRAY);
                                get_array_elements(p0, (void*) TCP_SERVER_SOCKET_BLOCKING_INTERNAL, (void*) &blocking_flag, (void*) POINTER_ARRAY);

                                if ((socket_flag != POINTER_NULL_POINTER) && (blocking_flag != NULL_POINTER)) {

                                    if ((*socket_flag != NULL_POINTER) && (*blocking_flag != NULL_POINTER)) {

                                        if ((**((int**) socket_flag) == 1) && (i < 0) && (**((int**) blocking_flag) == 1)) {

                                            run_tcp_socket(p0);
                                        }
                                    }
                                }

                                if (i >= 0) {

                                    // Get signal.
                                    get_signal(*s, *sc, (void*) &i,
                                        (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
                                        (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

                                    if (a != POINTER_NULL_POINTER) {

                                        if (ac != POINTER_NULL_POINTER) {

                                            if (m != POINTER_NULL_POINTER) {

                                                if (mc != POINTER_NULL_POINTER) {

                                                    if (d != POINTER_NULL_POINTER) {

                                                        if (dc != POINTER_NULL_POINTER) {

                                                            if (p != POINTER_NULL_POINTER) {

                                                                if (id != POINTER_NULL_POINTER) {

/*??
                                                                    //?? For testing only. TODO: Delete these lines later!
                                                                    fprintf(stderr, "check i: %i\n", i);
                                                                    fprintf(stderr, "check a: %s\n", (char*) *a);
                                                                    fprintf(stderr, "check ac: %i\n", *((int*) *ac));
                                                                    fprintf(stderr, "check m: %s\n", (char*) *m);
                                                                    fprintf(stderr, "check mc: %i\n", *((int*) *mc));
                                                                    //?? d and dc are NULL. DO NOT try to print their values here!
                                                                    fprintf(stderr, "check p: %i\n", *((int*) *p));
                                                                    fprintf(stderr, "check id: %i\n", *((int*) *id));
                                                                    fprintf(stderr, "check knowledge model: %s\n", "");
//??                                                                    test_knowledge_model(*k, *kc, 0);
*/

                                                                    // CAUTION! Do NOT destroy signal here!
                                                                    // Signals are stored in the logic knowledge tree which gets created
                                                                    // at system startup and destroyed at system shutdown.
                                                                    //?? TODO: Is this still true? A signal only encapsulates a logic model.
                                                                    //?? So the signal possibly needs to be destroyed, only not the logic model!

                                                                    //
                                                                    // Handle signal.
                                                                    //

                                                                    handle(*a, *ac, *m, *mc, *d, *dc, *p, *id, (void*) &f, p0, &x);

                                                                    // Remove signal from signal memory.
                                                                    remove_signal(*s, *sc, *ss, (void*) &i);

                                                                    // Destroy signal id.
                                                                    // CAUTION! Do NOT hand over as reference!
                                                                    // The id was read from signal memory and is of type void**.
                                                                    // The expression (&*id) is the same like (id).
//??                                                                    fprintf(stderr, "TEST check pre integer destroy i: %i\n", i);
//??                                                                    destroy_integer((void*) id);
//??                                                                    fprintf(stderr, "TEST check post integer destroy i: %i\n", i);
                                                                    // CAUTION! Do NOT destroy the signal priority!
                                                                    // It is a FIXED system constant.

                                                                } else {

                                                                    log_message_debug("Could not check for signals. The identification is null.");
                                                                }

                                                            } else {

                                                                log_message_debug("Could not check for signals. The priority is null.");
                                                            }

                                                        } else {

                                                            log_message_debug("Could not check for signals. The details count is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not check for signals. The details is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not check for signals. The model count is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not check for signals. The model is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not check for signals. The abstraction count is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not check for signals. The abstraction is null.");
                                    }

                                    // Reset abstraction.
                                    a = POINTER_NULL_POINTER;
                                    ac = POINTER_NULL_POINTER;
                                    // Reset model (signal operation).
                                    m = POINTER_NULL_POINTER;
                                    mc = POINTER_NULL_POINTER;
                                    // Reset details (parameters).
                                    d = POINTER_NULL_POINTER;
                                    dc = POINTER_NULL_POINTER;
                                    // Reset priority.
                                    p = POINTER_NULL_POINTER;
                                    // Reset main signal id.
                                    id = POINTER_NULL_POINTER;
                                    // Reset highest priority index.
                                    i = -1;
                                    // Reset comparison result.
                                    r = 0;
                                }
                            }

                        } else {

                            log_message_debug("Could not check for signals. The signal memory size is null.");
                        }

                    } else {

                        log_message_debug("Could not check for signals. The signal memory count is null.");
                    }

                } else {

                    log_message_debug("Could not check for signals. The signal memory is null.");
                }

            } else {

                log_message_debug("Could not check for signals. The knowledge memory size is null.");
            }

        } else {

            log_message_debug("Could not check for signals. The knowledge memory count is null.");
        }

    } else {

        log_message_debug("Could not check for signals. The knowledge memory is null.");
    }
}

/* CHECKER_SOURCE */
#endif
