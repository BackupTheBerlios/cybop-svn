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
 * @version $Revision: 1.29 $ $Date: 2004-06-18 22:55:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_SOURCE
#define SIGNAL_MEMORY_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logic/add.c"
#include "../logic/create_model.c"
#include "../logic/destroy_model.c"
#include "../logger/logger.c"
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
void handle_compound_signal(const void* p0, const void* p1, const void* p2, void* p3, void* p4, void* p5) {

    if (p2 != NULL_POINTER) {

        int* sc = (int*) p2;

        log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT);

        // Initialize part models, abstractions
        // and their counts.
        void* pm = NULL_POINTER;
        void* pmc = NULL_POINTER;
        void* pa = NULL_POINTER;
        void* pac = NULL_POINTER;

        // Get part models, abstractions
        // and their counts.
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);

        // Initialize part model, abstraction
        // and their count.
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
 * Handles the create model signal.
 *
 * CYBOL Examples:
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,whole name,part name,
 *      part abstraction,part location,part model,part constraints,
 *      position abstraction,position location,position model,position constraints /-->
 *
 * <part name="create_domain" part_abstraction="operation" part_location="inline"
 *      part_model="create,,domain,compound,file,/helloworld/domain.cybol,null,null,null,null,null"/>
 *
 * <part name="create_find_dialog" part_abstraction="operation" part_location="inline"
 *      part_model="create,application.gui,find_dialog,compound,file,application/find_dialog.cybol,,
 *          vector,inline,100;100;0,x<1000;y<1000;z=0"/>
 *
 * @param p0 the signal parameters count
 * @param p1 the parameters
 * @param p2 the parameters counts
 * @param p3 the parameters sizes
 * @param p4 the knowledge
 * @param p5 the knowledge count
 * @param p6 the knowledge size
 */
void handle_create_model_signal(const void* p0,
    const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6) {

    if (p6 != NULL_POINTER) {

        int* ks = (int*) p6;

        if (p5 != NULL_POINTER) {

            int* kc = (int*) p5;

            if (p4 != NULL_POINTER) {

                void** k = (void**) p4;

                if (p0 != NULL_POINTER) {

                    int* sc = (int*) p0;

                    if (*sc == 11) {

                        // Initialize persistent whole name and its count and size.
                        void* pwn = NULL_POINTER;
                        int pwnc = 0;
                        int pwns = 0;

                        // Initialize persistent part name,
                        // part abstraction, location, model, constraint,
                        // position abstraction, location, model, constraint,
                        // and their counts and sizes.
                        void* ppn = NULL_POINTER;
                        int ppnc = 0;
                        int ppns = 0;
                        void* ppa = NULL_POINTER;
                        int ppac = 0;
                        int ppas = 0;
                        void* ppl = NULL_POINTER;
                        int pplc = 0;
                        int ppls = 0;
                        void* ppm = NULL_POINTER;
                        int ppmc = 0;
                        int ppms = 0;
                        void* ppc = NULL_POINTER;
                        int ppcc = 0;
                        int ppcs = 0;
                        void* ppoa = NULL_POINTER;
                        int ppoac = 0;
                        int ppoas = 0;
                        void* ppol = NULL_POINTER;
                        int ppolc = 0;
                        int ppols = 0;
                        void* ppom = NULL_POINTER;
                        int ppomc = 0;
                        int ppoms = 0;
                        void* ppoc = NULL_POINTER;
                        int ppocc = 0;
                        int ppocs = 0;

                        // CAUTION! The parameter at index 0 is the logic/ operation name.
                        // Input and output parameters start with index 1.

                        // The loop variable.
                        int j = 1;

                        while (1) {

                            if (j >= *sc) {

                                break;
                            }

                            // CAUTION! The parameter at index 0 is the logic/ operation name.
                            // Input and output parameters start with index 1.

                            if (j == 1) {

                                // Get persistent whole name and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pwn);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pwnc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pwns);

                            } else if (j == 2) {

                                // Get persistent part name and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppn);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppnc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppns);

                            } else if (j == 3) {

                                // Get persistent part abstraction and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppa);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppac);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppas);

                            } else if (j == 4) {

                                // Get persistent part location and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppl);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pplc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppls);

                            } else if (j == 5) {

                                // Get persistent part model and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppm);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppmc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppms);

                            } else if (j == 6) {

                                // Get persistent part constraints and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppc);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppcc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppcs);

                            } else if (j == 7) {

                                // Get persistent position abstraction and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppoa);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppoac);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppoas);

                            } else if (j == 8) {

                                // Get persistent position location and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppol);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppolc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppols);

                            } else if (j == 9) {

                                // Get persistent position model and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppom);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppomc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppoms);

                            } else if (j == 10) {

                                // Get persistent position constraints and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppoc);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppocc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppocs);
                            }

                            j++;
                        }

                        // Initialize transient whole model and its count and size.
                        void* twm = NULL_POINTER;
                        int twmc = 0;
                        int twms = 0;

                        // Get transient whole model.
                        if (pwn == NULL_POINTER) {

                            // If the persistent whole model name is null, the
                            // knowledge root is taken as transient whole model.
                            twm = *k;
                            twmc = *kc;
                            twms = *ks;

                        } else {

                            // If a persistent whole model name exists, the transient
                            // whole model is determined within the knowledge root.
                            // Abstraction and constraints as well as the model's
                            // position within the knowledge root are not of interest.
                            get_compound_part_by_name(p4, p5, p6,
                                (void*) &pwn, (void*) &pwnc, (void*) &pwns,
                                (void*) &twm, (void*) &twmc, (void*) &twms,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
                        }

                        // Initialize transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        // CAUTION! A transient location is not stored,
                        // since that is only needed temporarily
                        // for model loading.
                        void* tpn = NULL_POINTER;
                        int tpnc = 0;
                        int tpns = 0;
                        void* tpa = NULL_POINTER;
                        int tpac = 0;
                        int tpas = 0;
                        void* tpm = NULL_POINTER;
                        int tpmc = 0;
                        int tpms = 0;
                        void* tpc = NULL_POINTER;
                        int tpcc = 0;
                        int tpcs = 0;
                        void* tpoa = NULL_POINTER;
                        int tpoac = 0;
                        int tpoas = 0;
                        void* tpom = NULL_POINTER;
                        int tpomc = 0;
                        int tpoms = 0;
                        void* tpoc = NULL_POINTER;
                        int tpocc = 0;
                        int tpocs = 0;

                        // Create transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        interpret_model((void*) &tpn, (void*) &tpnc, (void*) &tpns,
                            (void*) &ppn, (void*) &ppnc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        interpret_model((void*) &tpa, (void*) &tpac, (void*) &tpas,
                            (void*) &ppa, (void*) &ppac,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        interpret_located_model((void*) &tpm, (void*) &tpmc, (void*) &tpms,
                            (void*) &ppa, (void*) &ppac,
                            (void*) &ppl, (void*) &pplc,
                            (void*) &ppm, (void*) &ppmc);
                        interpret_model((void*) &tpc, (void*) &tpcc, (void*) &tpcs,
                            (void*) &ppc, (void*) &ppcc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        interpret_model((void*) &tpoa, (void*) &tpoac, (void*) &tpoas,
                            (void*) &ppoa, (void*) &ppoac,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        interpret_located_model((void*) &tpom, (void*) &tpomc, (void*) &tpoms,
                            (void*) &ppoa, (void*) &ppoac,
                            (void*) &ppol, (void*) &ppolc,
                            (void*) &ppom, (void*) &ppomc);
                        interpret_model((void*) &tpoc, (void*) &tpocc, (void*) &tpocs,
                            (void*) &ppoc, (void*) &ppocc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

                        //?? If "add", then first check if name exists in whole;
                        //?? if yes, add "_0" or "_1" or "_2" etc.
                        //?? to name, taking first non-existing suffix!
                        //?? If "set", then just replace the model
                        //?? with equal name; but where to destroy it if
                        //?? no whole keeps a reference to it anymore?

                        // Set transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        set_compound_part_by_name((void*) &twm, (void*) &twmc, (void*) &twms,
                            (void*) &tpn, (void*) &tpnc, (void*) &tpns,
                            (void*) &tpm, (void*) &tpmc, (void*) &tpms,
                            (void*) &tpa, (void*) &tpac, (void*) &tpas,
                            (void*) &tpc, (void*) &tpcc, (void*) &tpcs,
                            (void*) &tpom, (void*) &tpomc, (void*) &tpoms,
                            (void*) &tpoa, (void*) &tpoac, (void*) &tpoas,
                            (void*) &tpoc, (void*) &tpocc, (void*) &tpocs);

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Handles the send signal.
 *
 * CYBOL Example:
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,signal name /-->
 * <part name="send_signal" part_abstraction="operation" part_location="inline"
 *      part_model="send,path.name.signal"/>
 *
 * @param p0 the signal parameters count
 * @param p1 the parameters
 * @param p2 the parameters counts
 * @param p3 the parameters sizes
 * @param p4 the knowledge
 * @param p5 the knowledge count
 * @param p6 the knowledge size
 * @param p7 the signal memory
 * @param p8 the signal memory count
 * @param p9 the signal memory size
 */
void handle_send_signal(const void* p0,
    const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, void* p6,
    void* p7, void* p8, void* p9) {

    if (p0 != NULL_POINTER) {

        int* sc = (int*) p0;

        if (*sc == 2) {

            // Initialize signal name and its count and size.
            void* sn = NULL_POINTER;
            int snc = 0;
            int sns = 0;

            // CAUTION! The parameter at index 0 is the logic/ operation name.
            // Input and output parameters start with index 1.

            // The loop variable.
            int j = 1;

            while (1) {

                if (j >= *sc) {

                    break;
                }

                // CAUTION! The parameter at index 0 is the logic/ operation name.
                // Input and output parameters start with index 1.

                if (j == 1) {

                    // Get signal name and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &sn);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &snc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &sns);
                }

                j++;
            }

            // Initialize part model, abstraction,
            // and their count and size.
            void* pm = NULL_POINTER;
            int pmc = 0;
            int pms = 0;
            void* pa = NULL_POINTER;
            int pac = 0;
            int pas = 0;

            // Get part model, abstraction,
            // and their count and size.
            get_compound_part_by_name(p4, p5, p6,
                (void*) &sn, (void*) &snc, (void*) &sns,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);

            // Add part model (signal) to signal memory.
            set_signal(p7, p8, p9,
                (void*) &pm, (void*) &pmc,
                (void*) &NORMAL_PRIORITY,
                (void*) &pa, (void*) &pac);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_SEND_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
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
 * @param p5 the internals
 * @param p6 the internals count
 * @param p7 the internals size
 * @param p8 the signal memory
 * @param p9 the signal memory count
 * @param p10 the signal memory size
 * @param p11 the shutdown flag
 */
void handle_operation_signal(const void* p0, const void* p1,
    void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10,
    void* p11) {

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

            fprintf(stderr, "TEST operation: %s\n", (char*) l);
            fprintf(stderr, "TEST operation_count: %i\n", lc);

            // Add.
            if (d == 0) {

                if (lc == ADD_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &ADD_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &ADD_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

//??                        handle_add_signal(p2, (void*) &param1, (void*) &param1c, (void*) &param2, (void*) &param2c, (void*) &param3, (void*) &param3c);

                        d = 1;
                    }
                }
            }

            // Create model.
            if (d == 0) {

                if (lc == CREATE_MODEL_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &CREATE_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CREATE_MODEL_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        handle_create_model_signal(p1,
                            (void*) &p, (void*) &pc, (void*) &ps,
                            p2, p3, p4);

                        d = 1;
                    }
                }
            }

            // Destroy model.
            if (d == 0) {

                if (lc == DESTROY_MODEL_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &DESTROY_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DESTROY_MODEL_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        d = 1;
                    }
                }
            }

            // Send.
            if (d == 0) {

                if (lc == SEND_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &SEND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SEND_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        handle_send_signal(p1,
                            (void*) &p, (void*) &pc, (void*) &ps,
                            p2, p3, p4,
                            p8, p9, p10);

                        d = 1;
                    }
                }
            }

            // Receive.
            if (d == 0) {

                if (lc == RECEIVE_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &RECEIVE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &RECEIVE_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        d = 1;
                    }
                }
            }

            // Exit.
            if (d == 0) {

                if (lc == EXIT_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &EXIT_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &EXIT_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        log_message((void*) &INFO_LOG_LEVEL, (void*) &SET_SHUTDOWN_FLAG_MESSAGE, (void*) &SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

                        int* f = (int*) p5;
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

        //??            mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);

                    } else {

        //??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. The pointer position is null.");
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
