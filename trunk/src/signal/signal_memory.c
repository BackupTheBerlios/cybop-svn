/*
 * $RCSfile: signal_memory.c,v $
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
 * This file handles a signal memory.
 *
 * A signal memory is capable of storing signals.
 * For each signal, the following meta information is stored:
 * - signal
 * - priority
 * - language
 *
 * A signal is a transient logic model.
 * It is stored in the computer's random access memory (ram).
 *
 * @version $Revision: 1.34 $ $Date: 2004-07-04 09:49:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_SOURCE
#define SIGNAL_MEMORY_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"
#include "../logic/add.c"
#include "../logic/create.c"
#include "../logic/destroy.c"
#include "../logic/receive.c"
#include "../logic/send.c"
#include "../state/compound.c"
#include "../x_windows/x_windows_handler.c"

//
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory size
 */
void create_signal_memory(void* p0, void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Create signal memory.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT);

    // Initialize signal models, priorities, abstractions
    // and their counts.
    void* sm = NULL_POINTER;
    void* smc = NULL_POINTER;
    void* sp = NULL_POINTER;
    void* sa = NULL_POINTER;
    void* sac = NULL_POINTER;

    // Create signal models, priorities, abstractions
    // and their counts.
    create_array((void*) &sm, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &smc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &sp, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &sa, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &sac, (void*) &INTEGER_ARRAY, p1);

    //
    // Use ascending order.
    //

    // Set signal models, priorities, abstractions
    // and their counts.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory size
 */
void destroy_signal_memory(void* p0, void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_SIGNAL_MEMORY_MESSAGE, (void*) &DESTROY_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Initialize signal models, priorities, abstractions
    // and their counts.
    void* sm = NULL_POINTER;
    void* smc = NULL_POINTER;
    void* sp = NULL_POINTER;
    void* sa = NULL_POINTER;
    void* sac = NULL_POINTER;

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

    // Get signal models, priorities, abstractions
    // and their counts.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

    //
    // Use descending order.
    //

    // Remove signal models, priorities, abstractions
    // and their counts.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_PRIORITIES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_MODELS_INDEX);

    // Destroy signal models, priorities, abstractions
    // and their counts.
    destroy_array((void*) &sm, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &smc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &sp, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &sa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &sac, (void*) &INTEGER_ARRAY, p1);

    // Destroy signal memory.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT);
}

//
// Signal memory element (signal).
//

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the signal model
 * @param p4 the signal model count
 * @param p5 the signal priority
 * @param p6 the signal abstraction
 * @param p7 the signal abstraction count
 */
void set_signal(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5, const void* p6, const void* p7) {

    if (p2 != NULL_POINTER) {

        int* s = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            // Initialize signal models, priorities, abstractions
            // and their counts.
            void* sm = NULL_POINTER;
            void* smc = NULL_POINTER;
            void* sp = NULL_POINTER;
            void* sa = NULL_POINTER;
            void* sac = NULL_POINTER;

            // Get signal models, priorities, abstractions
            // and their counts.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

            // The index.
            int i = *c;

            if (i >= 0) {

                if (i == *s) {

                    // Increase size.
                    *s = *s * SIGNAL_MEMORY_RESIZE_FACTOR + 1;

                    // Resize signal models, priorities, abstractions
                    // and their counts.
                    resize_array((void*) &sm, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &smc, (void*) &INTEGER_ARRAY, p2);
                    resize_array((void*) &sp, (void*) &INTEGER_ARRAY, p2);
                    resize_array((void*) &sa, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &sac, (void*) &INTEGER_ARRAY, p2);
                }

                if (i < *s) {

                    // Set signal model, priority, abstraction
                    // and their count.
                    set_array_element((void*) &sm, (void*) &POINTER_ARRAY, (void*) &i, p3);
                    set_array_element((void*) &smc, (void*) &INTEGER_ARRAY, (void*) &i, p4);
                    set_array_element((void*) &sp, (void*) &INTEGER_ARRAY, (void*) &i, p5);
                    set_array_element((void*) &sa, (void*) &POINTER_ARRAY, (void*) &i, p6);
                    set_array_element((void*) &sac, (void*) &INTEGER_ARRAY, (void*) &i, p7);

                    // Increment count.
                    (*c)++;

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index exceeds the size.");
                }

            } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index is negativ.");
            }

        } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The signal count is null.");
        }

    } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The signal size is null.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the index
 */
void remove_signal(void* p0, void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                if (*i >= 0) {

                    // Initialize signal models, priorities, abstractions
                    // and their counts.
                    void* sm = NULL_POINTER;
                    void* smc = NULL_POINTER;
                    void* sp = NULL_POINTER;
                    void* sa = NULL_POINTER;
                    void* sac = NULL_POINTER;

                    // Get signal models, priorities, abstractions
                    // and their counts.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

                    if (*i < *c) {

                        // Remove signal model, priority, abstraction
                        // and their count.
                        remove_array_element((void*) &sm, (void*) &POINTER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &smc, (void*) &INTEGER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sp, (void*) &INTEGER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sa, (void*) &POINTER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sac, (void*) &INTEGER_ARRAY, (void*) c, p3);

                        // Decrement count.
                        (*c)--;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index exceeds the count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The signal memory count is null.");
            }

        } else {

//??           log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The signal memory size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index is null.");
    }
}

/**
 * Gets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the index
 * @param p3 the signal model
 * @param p4 the signal model count
 * @param p5 the signal priority
 * @param p6 the signal abstraction
 * @param p7 the signal abstraction count
 */
void get_signal(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            if (*i >= 0) {

                // Initialize signal models, priorities, abstractions
                // and their counts.
                void* sm = NULL_POINTER;
                void* smc = NULL_POINTER;
                void* sp = NULL_POINTER;
                void* sa = NULL_POINTER;
                void* sac = NULL_POINTER;

                // Get signal models, priorities, abstractions
                // and their counts.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

                if (*i < *c) {

                    // Get signal model, priority, abstraction
                    // and their count.
                    get_array_element((void*) &sm, (void*) &POINTER_ARRAY, p2, p3);
                    get_array_element((void*) &smc, (void*) &INTEGER_ARRAY, p2, p4);
                    get_array_element((void*) &sp, (void*) &INTEGER_ARRAY, p2, p5);
                    get_array_element((void*) &sa, (void*) &POINTER_ARRAY, p2, p6);
                    get_array_element((void*) &sac, (void*) &INTEGER_ARRAY, p2, p7);

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index exceeds the count.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index is negativ.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The signal memory count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index is null.");
    }
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the index
 */
void get_highest_priority_index(const void* p0, const void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            // Initialize signal priorities.
            void* sp = NULL_POINTER;

            // Get signal priorities.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);

            // The loop variable.
            int j = 0;
            // The priority.
            int prio = -1;
            // The highest priority.
            // CAUTION! Do not set it to zero, because then the priority
            // will not be set, due to the comparison: if (prio > h)
            // The smallest possible priority is zero and greater than minus one.
            int h = -1;

            while (1) {

                if (j >= *c) {

                    break;
                }

                // Get signal priority.
                get_array_element((void*) &sp, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &prio);

                if (prio > h) {

                    h = prio;

                    // If a signal with higher priority is found,
                    // then its index is the one to be returned.
                    *i = j;
                }

                j++;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The index is null.");
    }
}

//
// Signal handling.
//

/**
 * Handles the compound signal.
 *
 * @param p0 the signal
 * @param p1 the signal count
 * @param p2 the signal priority
 * @param p3 the signal memory
 * @param p4 the signal memory count
 * @param p5 the signal memory size
 */
void handle_compound_signal(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5) {

    if (p2 != NULL_POINTER) {

        int* sc = (int*) p2;

        log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT);

        // Initialize part models, abstractions and their counts.
        void* pm = NULL_POINTER;
        void* pmc = NULL_POINTER;
        void* pa = NULL_POINTER;
        void* pac = NULL_POINTER;

        // Get part models, abstractions and their counts.
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);

        // Initialize part model, abstraction and their count.
        void* m = NULL_POINTER;
        int mc = 0;
        void* a = NULL_POINTER;
        int ac = 0;

        // The loop variable.
        int j = 0;

        while (1) {

            if (j >= *sc) {

                break;
            }

            // Get part model, abstraction
            // and their count.
            get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &j, (void*) &m);
            get_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &mc);
            get_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &j, (void*) &a);
            get_array_element((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ac);

            // Add part model (signal) to memory, using the whole signal's priority.
            // (Each signal has a priority. A signal may consist of part
            // signals. The part signals cannot have higher/lower priority
            // than their original whole signal.)
            set_signal(p3, p4, p5, (void*) &m, (void*) &mc, p2, (void*) &a, (void*) &ac);

            j++;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle compound signal. The signal memory count is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the signal
 * @param p1 the signal parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the character internals
 * @param p6 the integer internals
 * @param p7 the pointer internals
 * @param p8 the double internals
 * @param p9 the shutdown flag
 */
void handle_operation_signal(const void* p0, const void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p1 != NULL_POINTER) {

        int* sc = (int*) p1;

        // The signal parameters count must be greater than zero.
        if (*sc >= 1) {

            log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

            // Initialize parameters
            // and their counts and sizes.
            void* p = NULL_POINTER;
            int pc = 0;
            int ps = 0;

            // Get parameters
            // and their counts and sizes.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);

            // Initialize logic (operation) name
            // and its count.
            // The first parameter param0 is the operation name.
            // Following parameters param1 .. are input and output names.
            void* l = NULL_POINTER;
            int lc = 0;

            // The logic (operation) name parameter index.
            int i = 0;

            // Get logic (operation) name
            // and its count.
            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &i, (void*) &l);
            get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &lc);

            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;

            fprintf(stderr, "TEST logic: %s\n", (char*) l);
            fprintf(stderr, "TEST logic_count: %i\n", lc);

            if (d == 0) {

                if (lc == ADD_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &ADD_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &ADD_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        add(p1, (void*) &p, (void*) &pc, (void*) &ps, p2, p3, p4);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == CREATE_MODEL_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &CREATE_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CREATE_MODEL_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        create(p1, (void*) &p, (void*) &pc, (void*) &ps, p2, p3, p4);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == DESTROY_MODEL_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &DESTROY_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DESTROY_MODEL_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

/*??
                        destroy(p1, (void*) &p, (void*) &pc, (void*) &ps, p2, p3, p4);
*/

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == SEND_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &SEND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SEND_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        send_message(p1, (void*) &p, (void*) &pc, (void*) &ps,
                            p2, p3, p4, p5, p6, p7, p8);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == RECEIVE_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &RECEIVE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &RECEIVE_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

/*??
                        receive_message(p1, (void*) &p, (void*) &pc, (void*) &ps,
                            p2, p3, p4, p5, p6, p7, p8);
*/

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == EXIT_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &EXIT_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &EXIT_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        log_message((void*) &INFO_LOG_LEVEL, (void*) &SET_SHUTDOWN_FLAG_MESSAGE, (void*) &SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

                        int* f = (int*) p9;
                        *f = 1;

                        d = 1;
                    }
                }
            }

/*??
                //?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
                if (strcmp(l, "mouse_moved") == 0) {

                    Model statics = statics;

                    set_model_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                    set_model_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                    set_model_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                    set_model_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");

                } else if (strcmp(l, "mouse_clicked") == 0) {

                    void* main_frame = get_statics_model_part(statics, (void*) "main_frame");
                    struct vector* pointer_position = get_statics_model_part(statics, (void*) "mouse.pointer_position");

                    reset_signal(s);

                    if (pointer_position != NULL_POINTER) {

//??                    mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. The pointer position is null.");
                    }
                }
*/

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle operation signal. The signal parameters count is zero.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle operation signal. The signal parameters count is null.");
    }
}

/* SIGNAL_MEMORY_SOURCE */
#endif
