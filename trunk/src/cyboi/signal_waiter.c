/*
 * $RCSfile: signal_waiter.c,v $
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
 * @version $Revision: 1.29 $ $Date: 2005-01-28 23:30:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SIGNAL_WAITER_SOURCE
#define SIGNAL_WAITER_SOURCE

#include "../accessor/signal_memory_accessor.c"
#include "../cyboi/input_output_activator.c"
#include "../cyboi/signal_handler.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Waits for signals.
 *
 * @param p0 the internals memory
 */
void wait(void* p0) {

    log_message((void*) INFO_LOG_LEVEL, (void*) WAIT_FOR_SIGNALS_MESSAGE, (void*) WAIT_FOR_SIGNALS_MESSAGE_COUNT);

    // Activate input output mechanisms for signal reception.
    activate_input_output(p0);

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

                            // Run endless loop checking signal memory for signals.
                            while (1) {

                                if (f == 1) {

                                    // Leave loop if the shutdown flag was set.
                                    break;
                                }

                                // Get index of the top priority signal.
                                get_highest_priority_index(*s, *sc, (void*) &i);

/*??
                                //?? Wait for web input, if no signal is in memory. TODO: Use a thread for this!
                                if (*i < 0) {

                                    run_tcp_socket((void*) &p0);
                                }
*/

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

                                                                    //?? For testing only. TODO: Delete these lines later!
                                                                    fprintf(stderr, "wait i: %i\n", i);
                                                                    fprintf(stderr, "wait a: %s\n", (char*) *a);
                                                                    fprintf(stderr, "wait ac: %i\n", *((int*) *ac));
                                                                    fprintf(stderr, "wait m: %s\n", (char*) *m);
                                                                    fprintf(stderr, "wait mc: %i\n", *((int*) *mc));
                                                                    //?? d and dc are NULL. DO NOT try to print their values here!
                                                                    fprintf(stderr, "wait p: %i\n", *((int*) *p));
                                                                    fprintf(stderr, "wait id: %i\n", *((int*) *id));
                                                                    fprintf(stderr, "wait knowledge model: %s\n", "");

                                                                    // Remove signal from signal memory.
                                                                    remove_signal(*s, *sc, *ss, (void*) &i);

                                                                    // CAUTION! Do NOT destroy signal here!
                                                                    // Signals are stored in the logic knowledge tree which gets created
                                                                    // at system startup and destroyed at system shutdown.
                                                                    //?? TODO: Is this still true? A signal only encapsulates a logic model.
                                                                    //?? So the signal possibly needs to be destroyed, only not the logic model!

                                                                    //
                                                                    // Handle compound signal.
                                                                    //

                                                                    if (r != 1) {

                                                                        compare_arrays(*a, *ac, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                                        if (r == 1) {

                                                                            handle_compound_signal(*m, *mc, *p, *id, *s, *sc, *ss);
                                                                        }
                                                                    }

                                                                    //
                                                                    // Handle operation signal.
                                                                    //

                                                                    if (r != 1) {

                                                                        compare_arrays(*a, *ac, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                                        if (r == 1) {

                                                                            handle_operation_signal(*m, *mc, *d, *dc, *k, *kc, *ks, *id, p0, (void*) &f);
                                                                        }
                                                                    }

                                                                    //
                                                                    // Unknown signal abstraction.
                                                                    //

                                                                    if (r != 1) {

                                                                        log_message((void*) WARNING_LOG_LEVEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
                                                                    }

                                                                    // Destroy signal id.
                                                                    // CAUTION! Do NOT hand over as reference!
                                                                    // The id was read from signal memory and is of type void**.
                                                                    // The expression (&*id) is the same like (id).
                                                                    destroy_integer((void*) id);
                                                                    // CAUTION! Do NOT destroy the signal priority!
                                                                    // It is a FIXED system constant.

                                                                } else {

                                                                    log_message_debug("Could not wait for signals. The identification is null.");
                                                                }

                                                            } else {

                                                                log_message_debug("Could not wait for signals. The priority is null.");
                                                            }

                                                        } else {

                                                            log_message_debug("Could not wait for signals. The details count is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not wait for signals. The details is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not wait for signals. The model count is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not wait for signals. The model is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not wait for signals. The abstraction count is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not wait for signals. The abstraction is null.");
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

                            log_message_debug("Could not wait for signals. The signal memory size is null.");
                        }

                    } else {

                        log_message_debug("Could not wait for signals. The signal memory count is null.");
                    }

                } else {

                    log_message_debug("Could not wait for signals. The signal memory is null.");
                }

            } else {

                log_message_debug("Could not wait for signals. The knowledge memory size is null.");
            }

        } else {

            log_message_debug("Could not wait for signals. The knowledge memory count is null.");
        }

    } else {

        log_message_debug("Could not wait for signals. The knowledge memory is null.");
    }
}

/* SIGNAL_WAITER_SOURCE */
#endif
