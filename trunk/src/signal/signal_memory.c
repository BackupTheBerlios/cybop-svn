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
 * @version $Revision: 1.26 $ $Date: 2004-06-13 23:13:31 $ $Author: christian $
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

                        // Initialize whole name and its count and size.
                        void* wn = NULL_POINTER;
                        int wnc = 0;
                        int wns = 0;
                        // Initialize part name and its count and size.
                        void* pn = NULL_POINTER;
                        int pnc = 0;
                        int pns = 0;
                        // Initialize part abstraction and its count and size.
                        void* pa = NULL_POINTER;
                        int pac = 0;
                        int pas = 0;
                        // Initialize part location and its count and size.
                        void* pl = NULL_POINTER;
                        int plc = 0;
                        int pls = 0;
                        // Initialize part model and its count and size.
                        void* pm = NULL_POINTER;
                        int pmc = 0;
                        int pms = 0;
                        // Initialize part constraints and its count and size.
                        void* pc = NULL_POINTER;
                        int pcc = 0;
                        int pcs = 0;
                        // Initialize position abstraction and its count and size.
                        void* poa = NULL_POINTER;
                        int poac = 0;
                        int poas = 0;
                        // Initialize position location and its count and size.
                        void* pol = NULL_POINTER;
                        int polc = 0;
                        int pols = 0;
                        // Initialize position model and its count and size.
                        void* pom = NULL_POINTER;
                        int pomc = 0;
                        int poms = 0;
                        // Initialize position constraints and its count and size.
                        void* poc = NULL_POINTER;
                        int pocc = 0;
                        int pocs = 0;

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

                                // Get whole name and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &wn);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &wnc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &wns);

                            } else if (j == 2) {

                                // Get part name and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pn);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pnc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pns);

                            } else if (j == 3) {

                                // Get part abstraction and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pa);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pac);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pas);

                            } else if (j == 4) {

                                // Get part location and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pl);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &plc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pls);

                            } else if (j == 5) {

                                // Get part model and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pm);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pmc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pms);

                            } else if (j == 6) {

                                // Get part constraints and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pc);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pcc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pcs);

                            } else if (j == 7) {

                                // Get position abstraction and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &poa);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &poac);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &poas);

                            } else if (j == 8) {

                                // Get position location and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pol);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &polc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pols);

                            } else if (j == 9) {

                                // Get position model and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pom);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pomc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &poms);

                            } else if (j == 10) {

                                // Get position constraints and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &poc);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pocc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pocs);
                            }

                            j++;
                        }

                        // Initialize whole model and its count and size.
                        void* wm = NULL_POINTER;
                        int wmc = 0;
                        int wms = 0;

                        // Get whole model.
                        if (wn == NULL_POINTER) {

                            // If the whole model name is null, the knowledge
                            // root is taken as whole model.
                            wm = *k;
                            wmc = *kc;
                            wms = *ks;

                        } else {

                            // If a whole model name exists, the whole model is
                            // determined within the knowledge root.
                            // Abstraction and constraints as well as the model's
                            // position within the knowledge root are not of interest.
                            get_compound_part_by_name(p4, p5, p6,
                                (void*) &wn, (void*) &wnc, (void*) &wns,
                                (void*) &wm, (void*) &wmc, (void*) &wms,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
                        }

                        // Initialize transient part model, position
                        // and their count and size.
                        void* tpm = NULL_POINTER;
                        int tpmc = 0;
                        int tpms = 0;
                        void* tpom = NULL_POINTER;
                        int tpomc = 0;
                        int tpoms = 0;

                        // Create transient part model, position
                        // and their count and size.
                        create_model((void*) &tpm, (void*) &tpmc, (void*) &tpms,
                            (void*) &tpom, (void*) &tpomc, (void*) &tpoms,
                            (void*) &pa, (void*) &pac,
                            (void*) &pl, (void*) &plc,
                            (void*) &pm, (void*) &pmc,
                            (void*) &poa, (void*) &poac,
                            (void*) &pol, (void*) &polc,
                            (void*) &pom, (void*) &pomc);

                        //?? If "add", then first check if name exists in whole;
                        //?? if yes, add "_0" or "_1" or "_2" etc.
                        //?? to name, taking first non-existing suffix!
                        //?? If "set", then just replace the model
                        //?? with equal name; but where to destroy it if
                        //?? no whole keeps a reference to it anymore?

                        // Set transient part model, position
                        // and their count and size.
                        set_compound_part_by_name((void*) &wm, (void*) &wmc, (void*) &wms,
                            (void*) &pn, (void*) &pnc, (void*) &pns,
                            (void*) &pm, (void*) &pmc, (void*) &pms,
                            (void*) &pa, (void*) &pac, (void*) &pas,
                            (void*) &pc, (void*) &pcc, (void*) &pcs,
                            (void*) &pom, (void*) &pomc, (void*) &poms,
                            (void*) &poa, (void*) &poac, (void*) &poas,
                            (void*) &poc, (void*) &pocc, (void*) &pocs);

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
