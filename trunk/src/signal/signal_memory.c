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
 * @version $Revision: 1.21 $ $Date: 2004-05-31 17:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_SOURCE
#define SIGNAL_MEMORY_SOURCE

#include "../array/array.c"
#include "../constants/constants.c"
#include "../dynamics/add.c"
#include "../dynamics/create_model.c"
#include "../dynamics/destroy_model.c"
#include "../logger/logger.c"
#include "../statics/compound.c"
#include "../x_windows/x_windows_handler.c"

//
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 */
void create_signal_memory(void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Create signal memory.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT);

    // Initialize elements.
    void* s = NULL_POINTER;
    void* sc = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* ac = NULL_POINTER;

    // Create elements.
    create_array((void*) &s, (void*) &POINTER_ARRAY, p2);
    create_array((void*) &sc, (void*) &INTEGER_ARRAY, p2);
    create_array((void*) &p, (void*) &INTEGER_ARRAY, p2);
    create_array((void*) &a, (void*) &POINTER_ARRAY, p2);
    create_array((void*) &ac, (void*) &INTEGER_ARRAY, p2);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &s);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_COUNTS_INDEX, (void*) &sc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 */
void destroy_signal_memory(void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_SIGNAL_MEMORY_MESSAGE, (void*) &DESTROY_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Initialize elements.
    void* s = NULL_POINTER;
    void* sc = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* ac = NULL_POINTER;

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

    // Get elements.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &s);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_COUNTS_INDEX, (void*) &sc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_PRIORITIES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT, (void*) &SIGNALS_INDEX);

    // Destroy elements.
    destroy_array((void*) &s, (void*) &POINTER_ARRAY, p2);
    destroy_array((void*) &sc, (void*) &INTEGER_ARRAY, p2);
    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, p2);
    destroy_array((void*) &a, (void*) &POINTER_ARRAY, p2);
    destroy_array((void*) &ac, (void*) &INTEGER_ARRAY, p2);

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
 * @param p3 the signal
 * @param p4 the signal count
 * @param p5 the signal priority
 * @param p6 the signal abstraction
 * @param p7 the signal abstraction size
 */
void set_signal(void* p0, void* p1, void* p2, const void* p3, const void* p4, const void* p5, const void* p6, const void* p7) {

    if (p2 != NULL_POINTER) {

        int* s = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            // Initialize elements.
            void* s = NULL_POINTER;
            void* sc = NULL_POINTER;
            void* p = NULL_POINTER;
            void* a = NULL_POINTER;
            void* ac = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &s);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_COUNTS_INDEX, (void*) &sc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);

            // The index.
            int i = *c;

            if (i >= 0) {

                if (i == *s) {

                    // Increase size.
                    *s = *s * SIGNAL_MEMORY_RESIZE_FACTOR + 1;

                    // Resize elements.
                    resize_array((void*) &s, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &sc, (void*) &INTEGER_ARRAY, p2);
                    resize_array((void*) &p, (void*) &INTEGER_ARRAY, p2);
                    resize_array((void*) &a, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &ac, (void*) &INTEGER_ARRAY, p2);
                }

                if (i < *s) {

                    // Set signal.
                    set_array_element((void*) &s, (void*) &POINTER_ARRAY, (void*) &i, p3);
                    set_array_element((void*) &sc, (void*) &INTEGER_ARRAY, (void*) &i, p4);
                    set_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &i, p5);
                    set_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) &i, p6);
                    set_array_element((void*) &ac, (void*) &INTEGER_ARRAY, (void*) &i, p7);

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

                    // Initialize elements.
                    void* s = NULL_POINTER;
                    void* sc = NULL_POINTER;
                    void* p = NULL_POINTER;
                    void* a = NULL_POINTER;
                    void* ac = NULL_POINTER;

                    // Get elements.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &s);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_COUNTS_INDEX, (void*) &sc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);

                    if (*i < c) {

                        // Remove signal.
                        remove_array_element((void*) &s, (void*) &POINTER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sc, (void*) &INTEGER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &ac, (void*) &INTEGER_ARRAY, (void*) c, p3);

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
 * @param p3 the signal
 * @param p4 the signal count
 * @param p5 the signal priority
 * @param p6 the signal abstraction
 * @param p7 the signal abstraction size
 */
void get_signal(const void* p0, const void* p1, const void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            if (*i >= 0) {

                // Initialize elements.
                void* s = NULL_POINTER;
                void* sc = NULL_POINTER;
                void* p = NULL_POINTER;
                void* a = NULL_POINTER;
                void* ac = NULL_POINTER;

                // Get elements.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &s);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_COUNTS_INDEX, (void*) &sc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);

                if (*i < *c) {

                    // Get signal.
                    get_array_element((void*) &s, (void*) &POINTER_ARRAY, p2, p3);
                    get_array_element((void*) &sc, (void*) &INTEGER_ARRAY, p2, p4);
                    get_array_element((void*) &p, (void*) &INTEGER_ARRAY, p2, p5);
                    get_array_element((void*) &a, (void*) &POINTER_ARRAY, p2, p6);
                    get_array_element((void*) &ac, (void*) &INTEGER_ARRAY, p2, p7);

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

            // Initialize elements.
            void* p = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);

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

                // Get element (signal) priority.
                get_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &prio);

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
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the compound signal
 * @param p4 the compound signal count
 * @param p5 the priority
 */
void handle_compound_signal(void* p0, void* p1, void* p2, const void* p3, const void* p4, const void* p5) {

    if (p4 != NULL_POINTER) {

        int* c = (int*) p4;

        log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT);

        // Initialize elements.
        void* pm = NULL_POINTER;
        void* pmc = NULL_POINTER;
        void* pa = NULL_POINTER;
        void* pac = NULL_POINTER;

        // Get elements.
        get_array_element(p3, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
        get_array_element(p3, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
        get_array_element(p3, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
        get_array_element(p3, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);

        // The part signal model.
        int j = 0;
        void* m = NULL_POINTER;
        int mc = 0;
        void* a = NULL_POINTER;
        int ac = 0;

        while (1) {

            if (j >= *c) {

                break;
            }

            // Get part signal.
            get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &j, (void*) &m);
            get_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &mc);
            get_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &j, (void*) &a);
            get_array_element((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ac);

            // Add part signal to memory, using the whole signal's priority.
            // (Each signal has a priority. A signal may consist of part
            // signals. The part signals cannot have higher/lower priority
            // than their original whole signal.)
            set_signal(p0, p1, p2, (void*) &m, (void*) &mc, p5, (void*) &a, (void*) &ac);

            j++;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle compound signal. The signal memory count is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the operation signal
 * @param p1 the operation signal parameters count
 * @param p2 the state root
 * @param p3 the logic root
 * @param p4 the internals
 * @param p5 the shutdown flag
 */
void handle_operation_signal(const void* p0, const void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p1 != NULL_POINTER) {

        int* c = (int*) p1;

        log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

        // Initialize elements.
        void* p = NULL_POINTER;
        void* pc = NULL_POINTER;

        // Get elements.
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);

        // Initialize parameter names.
        // The first parameter param0 is the operation name.
        // Following parameters param1 .. are input and output names.
        void* param0 = NULL_POINTER;
        int param0c = 0;
        void* param1 = NULL_POINTER;
        int param1c = 0;
        void* param2 = NULL_POINTER;
        int param2c = 0;
        void* param3 = NULL_POINTER;
        int param3c = 0;
        void* param4 = NULL_POINTER;
        int param4c = 0;
        void* param5 = NULL_POINTER;
        int param5c = 0;
        void* param6 = NULL_POINTER;
        int param6c = 0;
        void* param7 = NULL_POINTER;
        int param7c = 0;
        void* param8 = NULL_POINTER;
        int param8c = 0;
        void* param9 = NULL_POINTER;
        int param9c = 0;
        void* param10 = NULL_POINTER;
        int param10c = 0;
        void* param11 = NULL_POINTER;
        int param11c = 0;
        void* param12 = NULL_POINTER;
        int param12c = 0;

        // Get parameter names.
        int j = 0;

        while (1) {

            if (j >= *c) {

                break;
            }

            if (j == 0) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param0);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param0c);

            } else if (j == 1) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param1);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param1c);

            } else if (j == 2) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param2);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param2c);

            } else if (j == 3) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param3);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param3c);

            } else if (j == 4) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param4);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param4c);

            } else if (j == 5) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param5);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param5c);

            } else if (j == 6) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param6);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param6c);

            } else if (j == 7) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param7);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param7c);

            } else if (j == 8) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param8);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param8c);

            } else if (j == 9) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param9);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param9c);

            } else if (j == 10) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param10);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param10c);

            } else if (j == 11) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param11);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param11c);

            } else if (j == 12) {

                get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param12);
                get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param12c);
            }

            j++;
        }

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        fprintf(stderr, "TEST param0: %s\n", (char*) param0);
        fprintf(stderr, "TEST param0c: %i\n", param0c);

        // Add.
        if (d == 0) {

            if (param0c == ADD_ABSTRACTION_COUNT) {

                compare_array_elements((void*) &param0, (void*) &ADD_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &ADD_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    //?? Check parameter array size to avoid accessing
                    //?? not existing array element/ crossing array limits!

                    add(p2, (void*) &param1, (void*) &param1c, (void*) &param2, (void*) &param2c, (void*) &param3, (void*) &param3c);

                    d = 1;
                }
            }
        }

        // Create model.
        if (d == 0) {

            if (param0c == CREATE_MODEL_ABSTRACTION_COUNT) {

                compare_array_elements((void*) &param0, (void*) &CREATE_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CREATE_MODEL_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    //?? Check parameter array size to avoid accessing
                    //?? not existing array element/ crossing array limits!

/*??
<!-- create operation,whole model,part name,part abstraction,part location,part model /-->
<part name="create_domain" part_abstraction="operation" part_location="inline" part_model="create,root,domain,compound,file,/helloworld/domain.cybol"/>

                    create_model((void*) &param1, (void*) &param1s,
                        (void*) &param2, (void*) &param2s,
                        (void*) &param3, (void*) &param3s,
                        (void*) &param4, (void*) &param4s,
                        (void*) &param5, (void*) &param5s,
                        (void*) &param6, (void*) &param6s,
                        (void*) &param7, (void*) &param7s,
                        (void*) &param8, (void*) &param8s,
                        (void*) &param9, (void*) &param9s,
                        (void*) &param10, (void*) &param10s,
                        (void*) &param11, (void*) &param11s,
                        (void*) &param12, (void*) &param12s);
*/

                    d = 1;
                }
            }
        }

        // Destroy model.
        if (d == 0) {

            if (param0c == DESTROY_MODEL_ABSTRACTION_COUNT) {

                compare_array_elements((void*) &param0, (void*) &DESTROY_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DESTROY_MODEL_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    d = 1;
                }
            }
        }

        // Send.
        if (d == 0) {

            if (param0c == SEND_ABSTRACTION_COUNT) {

                compare_array_elements((void*) &param0, (void*) &SEND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SEND_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

    /*??
                    void* l = get_map_element_with_name(v, "language");

                    if (strcmp(l, X_WINDOWS_LANGUAGE) == 0) {

                        send_x_windows_output(get_array_element(v, (void*) &ONE_NUMBER), get_array_element(v, (void*) &TWO_NUMBER), p4);

                    } else if (strcmp(l, TUI_LANGUAGE) == 0) {

                    }
    */

                    d = 1;
                }
            }
        }

        // Receive.
        if (d == 0) {

            if (param0c == RECEIVE_ABSTRACTION_COUNT) {

                compare_array_elements((void*) &param0, (void*) &RECEIVE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &RECEIVE_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    d = 1;
                }
            }
        }

        // Exit.
        if (d == 0) {

            if (param0c == EXIT_ABSTRACTION_COUNT) {

                compare_array_elements((void*) &param0, (void*) &EXIT_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &EXIT_ABSTRACTION_COUNT, (void*) &r);

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

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle operation signal. The operation signal parameters count is null.");
    }
}

/* SIGNAL_MEMORY_SOURCE */
#endif
