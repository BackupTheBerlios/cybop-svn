/*
 * $RCSfile: signal_memory_handler.c,v $
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
 * Signal processing procedures should be called in the following order:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @version $Revision: 1.36 $ $Date: 2004-04-22 13:25:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_HANDLER_SOURCE
#define SIGNAL_MEMORY_HANDLER_SOURCE

#include "../constants.c"
#include "../dynamics/add.c"
#include "../dynamics/create_model.c"
#include "../dynamics/destroy_model.c"
#include "../logger/log_handler.c"
#include "../model/array_handler.c"
#include "../model/model_handler.c"
#include "../x_windows/x_windows_handler.c"

//
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 */
void create_signal_memory(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Create signal memory.");

    // Create signal memory.
    create_array(p0, (void*) &SIGNAL_MEMORY_SIZE);

    // Initialize elements.
    int s = 10; //?? CHANGE to int s = 0;
    int c = 0;
    void* sig = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* as = NULL_POINTER;

    // Create elements.
    create_array((void*) &sig, (void*) &s);
    create_array((void*) &p, (void*) &s);
    create_array((void*) &a, (void*) &s);
    create_array((void*) &as, (void*) &s);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_SIZE_INDEX, (void*) &s);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &sig);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_INDEX, (void*) &p);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 */
void destroy_signal_memory(void* p0) {

    // Initialize elements.
    int s = 0;
    int c = 0;
    void* sig = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* as = NULL_POINTER;

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

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy signal memory.");

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &sig);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &PRIORITIES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &SIGNALS_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &SIGNALS_COUNT_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &SIGNALS_SIZE_INDEX);

    // Destroy elements.
    destroy_array((void*) &sig, (void*) &s);
    destroy_array((void*) &p, (void*) &s);
    destroy_array((void*) &a, (void*) &s);
    destroy_array((void*) &as, (void*) &s);

    // Destroy signal memory.
    destroy_array(p0, (void*) &SIGNAL_MEMORY_SIZE);
}

//
// Signal memory element (signal).
//

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 * @param p2 the priority
 * @param p3 the abstraction
 * @param p4 the abstraction size
 */
void set_signal(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    // Initialize elements.
    int s = 0;
    int c = 0;
    void* sig = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* as = NULL_POINTER;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &sig);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);

    // The index.
    int i = c;

    if (i >= 0) {

        if (i == s) {

            // Increase size.
            s = s * 2 + 1;

            fprintf(stderr, "set signal s: %d\n", s);
            fprintf(stderr, "set signal c: %d\n", c);
            fprintf(stderr, "set signal sig: %d\n", sig);
            fprintf(stderr, "set signal p: %d\n", p);
            fprintf(stderr, "set signal a: %d\n", a);
            fprintf(stderr, "set signal as: %d\n", as);

            // Resize elements.
            resize_array((void*) &sig, (void*) &s);
            fputs("set signal TEST 0\n", stderr);
            resize_array((void*) &p, (void*) &s);
            fputs("set signal TEST 1\n", stderr);
            resize_array((void*) &a, (void*) &s);
            fputs("set signal TEST 2\n", stderr);
            resize_array((void*) &as, (void*) &s);
            fputs("set signal TEST 3\n", stderr);

            // Set array size which is equal for all arrays.
            set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_SIZE_INDEX, (void*) &s);
        }

        if (i < s) {

            // Set signal.
            set_array_element((void*) &sig, (void*) &POINTER_ARRAY, (void*) &i, p1);
            set_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &i, p2);
            set_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) &i, p3);
            set_array_element((void*) &as, (void*) &INTEGER_ARRAY, (void*) &i, p4);

            // Increment count.
            c++;

            // Set count.
            set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index exceeds the size.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index is negativ.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
void remove_signal(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

            // Initialize elements.
            int s = 0;
            int c = 0;
            void* sig = NULL_POINTER;
            void* p = NULL_POINTER;
            void* a = NULL_POINTER;
            void* as = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &sig);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);

            fprintf(stderr, "i: %d\n", *i);
            fprintf(stderr, "s: %d\n", s);
            fprintf(stderr, "c: %d\n", c);
            fprintf(stderr, "sig: %d\n", sig);
            fprintf(stderr, "p: %d\n", p);
            fprintf(stderr, "a: %d\n", a);
            fprintf(stderr, "as: %d\n", as);

            if (*i < c) {

                fputs("TEST a\n", stderr);
                // Remove signal.
                remove_array_element((void*) &sig, (void*) &POINTER_ARRAY, (void*) &c, p1);
                fputs("TEST d\n", stderr);
                remove_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &as, (void*) &INTEGER_ARRAY, (void*) &c, p1);

                // Decrement count.
                c--;

                // Set count.
                fputs("TEST e\n", stderr);
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
                fputs("TEST f\n", stderr);

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index exceeds the count.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index is negativ.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index is null.");
    }
}

/**
 * Gets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @param p2 the signal
 * @param p3 the priority
 * @param p4 the abstraction
 * @param p5 the abstraction size
 */
void get_signal(const void* p0, const void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

            // Initialize elements.
            int s = 0;
            int c = 0;
            void* sig = NULL_POINTER;
            void* p = NULL_POINTER;
            void* a = NULL_POINTER;
            void* as = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_INDEX, (void*) &sig);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);

            if (*i < c) {

                // Get signal.
                get_array_element((void*) &sig, (void*) &POINTER_ARRAY, p1, p2);
                get_array_element((void*) &p, (void*) &INTEGER_ARRAY, p1, p3);
                get_array_element((void*) &a, (void*) &POINTER_ARRAY, p1, p4);
                get_array_element((void*) &as, (void*) &INTEGER_ARRAY, p1, p5);

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index exceeds the count.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index is negativ.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index is null.");
    }
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
void get_highest_priority_index(const void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        // Initialize elements.
        int c = 0;
        void* p = NULL_POINTER;

        // Get elements.
        get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNALS_COUNT_INDEX, (void*) &c);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_INDEX, (void*) &p);

        // The loop variable.
        int j = 0;
        // The priority.
        int prio = 0;
        // The highest priority.
        int h = prio;

        while (1) {

            if (j >= c) {

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

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The index is null.");
    }
}

//
// Signal handling.
//

/**
 * Handles the compound signal.
 *
 * @param p0 the signal memory
 * @param p1 the compound signal
 * @param p2 the priority
 */
void handle_compound_signal(void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Handle compound signal.");

    // Initialize elements.
    int c = 0;
    void* pa = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pm = NULL_POINTER;

    // Get elements.
    get_array_element(p1, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);

    // The part signal model.
    int j = 0;
    void* a = NULL_POINTER;
    int as = 0;
    void* m = NULL_POINTER;

    while (1) {

        if (j >= c) {

            break;
        }

        // Get part signal.
        get_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &j, (void*) &a);
        get_array_element((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &as);
        get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &j, (void*) &m);

        // Add part signal to memory, using the whole signal's priority.
        // (Each signal has a priority. A signal may consist of part
        // signals. The part signals cannot have higher/lower priority
        // than their original whole signal.)
        set_signal(p0, (void*) &m, p2, (void*) &a, (void*) &as);

        j++;
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the operation signal
 * @param p1 the statics
 * @param p2 the dynamics
 * @param p3 the internals
 * @param p4 the shutdown flag
 */
void handle_operation_signal(const void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Handle operation signal.");

    // Initialize elements.
    int s = 0;
    void* p = NULL_POINTER;
    void* ps = NULL_POINTER;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);

    // Initialize parameter names.
    // The first parameter p0 is the operation name.
    // Following parameters p1 .. are input and output names.
    void* param0 = NULL_POINTER;
    int param0s = 0;
    void* param1 = NULL_POINTER;
    int param1s = 0;
    void* param2 = NULL_POINTER;
    int param2s = 0;
    void* param3 = NULL_POINTER;
    int param3s = 0;
    void* param4 = NULL_POINTER;
    int param4s = 0;
    void* param5 = NULL_POINTER;
    int param5s = 0;
    void* param6 = NULL_POINTER;
    int param6s = 0;
    void* param7 = NULL_POINTER;
    int param7s = 0;
    void* param8 = NULL_POINTER;
    int param8s = 0;
    void* param9 = NULL_POINTER;
    int param9s = 0;
    void* param10 = NULL_POINTER;
    int param10s = 0;

    // Get parameter names.
    int j = 0;

    while (1) {

        if (j >= s) {

            break;
        }

        if (j == 0) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param0);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param0s);

        } else if (j == 1) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param1);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param1s);

        } else if (j == 2) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param2);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param2s);

        } else if (j == 3) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param3);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param3s);

        } else if (j == 4) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param4);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param4s);

        } else if (j == 5) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param5);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param5s);

        } else if (j == 6) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param6);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param6s);

        } else if (j == 7) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param7);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param7s);

        } else if (j == 8) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param8);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param8s);

        } else if (j == 9) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param9);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param9s);

        } else if (j == 10) {

            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &j, (void*) &param10);
            get_array_element((void*) &ps, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &param10s);
        }

        j++;
    }

    // The comparison result.
    int r = 0;

    // Add.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &ADD_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &ADD_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

        add(p1, (void*) &param1, (void*) &param1s, (void*) &param2, (void*) &param2s, (void*) &param3, (void*) &param3s);

    } else {

    // Create statics.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &CREATE_STATICS_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CREATE_STATICS_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

/*??
        void* m = NULL_POINTER;
        int ms = 0;

        * @param p0 the transient model
        * @param p1 the transient model size
        * @param p2 the persistent model
        * @param p3 the persistent model size
        * @param p4 the abstraction
        * @param p5 the abstraction size
        //?? Work this out! Hand over 9 or just 3 parameters,
        //?? for only part or also position and constraint?
        //?? ATTENTION! One of the given cybol parameters must specify
        //?? the whole model that the newly created part model will be attached to.
        create_model(get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));
        set_map_element_with_name(s->part_models, get_array_element(v, (void*) &ONE_NUMBER), m);
*/

    } else {

    // Destroy statics.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &DESTROY_STATICS_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DESTROY_STATICS_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

/*??
        struct model* s = (struct model*) p1;

        if (s != NULL_POINTER) {

            //?? Work this out! Hand over 9 or just 3 parameters,
            //?? for only part or also position and constraint?
            void* m = get_map_element_with_name(s->part_models, get_map_element_with_name(v, (void*) &ONE_NUMBER));
            destroy_model(m, get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle destroy statics model. The statics is null.");
        }
*/

    } else {

    // Create dynamics.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &CREATE_DYNAMICS_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CREATE_DYNAMICS_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

/*??
        struct model* d = (struct model*) p2;

        if (d != NULL_POINTER) {

            //?? Work this out! Hand over 9 or just 3 parameters,
            //?? for only part or also position and constraint?
            void* m = create_model(get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));
            set_map_element_with_name(d->part_models, get_array_element(v, (void*) &ONE_NUMBER), m);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle create dynamics model. The dynamics is null.");
        }
*/

    } else {

    // Destroy dynamics.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &DESTROY_DYNAMICS_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DESTROY_DYNAMICS_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

/*??
        struct model* d = (struct model*) p2;

        if (d != NULL_POINTER) {

            //?? Work this out! Hand over 9 or just 3 parameters,
            //?? for only part or also position and constraint?
            void* m = get_map_element_with_name(d->part_models, get_map_element_with_name(v, (void*) &ONE_NUMBER));
            destroy_model(m, get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle destroy dynamics model. The dynamics is null.");
        }
*/

    } else {

    // Send.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &SEND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SEND_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

/*??
        void* l = get_map_element_with_name(v, "language");

        if (strcmp(l, X_WINDOWS_LANGUAGE) == 0) {

            send_x_windows_output(get_array_element(v, (void*) &ONE_NUMBER), get_array_element(v, (void*) &TWO_NUMBER), p3);

        } else if (strcmp(l, TUI_LANGUAGE) == 0) {

        }
*/

    } else {

    // Receive.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &RECEIVE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &RECEIVE_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

    } else {

    // Exit.
    //?? CAUTION! Still compare sizes here!
    compare_array_elements((void*) &param0, (void*) &EXIT_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &EXIT_ABSTRACTION_SIZE, (void*) &r);

    if (r == 1) {

        log_message((void*) &INFO_LOG_LEVEL, (void*) &"Set shutdown flag.");

        int* f = (int*) p4;
        *f = 1;

    } // Exit.
    } // Receive.
    } // Send.
    } // Destroy dynamics.
    } // Create dynamics.
    } // Destroy statics.
    } // Create statics.
    } // Add.

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

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. The pointer position is null.");
            }
        }
*/
}

/* SIGNAL_MEMORY_HANDLER_SOURCE */
#endif
