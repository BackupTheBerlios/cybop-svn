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
 * @version $Revision: 1.18 $ $Date: 2005-01-08 14:28:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_WAITER_SOURCE
#define SIGNAL_WAITER_SOURCE

#include "../accessor/signal_memory_accessor.c"
#include "../array/array.c"
#include "../cyboi/signal_handler.c"
#include "../global/abstraction_constants.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../web/tcp_socket_server.c"
#include "../test/test.c"

/**
 * Activates the internals.
 *
 * Before the actual signal waiting loop is entered, all internal mechanisms
 * for signal reception have to be started, for example:
 * - socket communication
 * - x windows events
 * - others more
 *
 * These have their own internal signal/ action/ event waiting loops
 * which get activated here.
 * Whenever such a signal/ action/ event occurs, it gets transformed
 * into a cyboi signal and is finally placed in cyboi's signal memory.
 *
 * TODO: Since many internal waiting loops run in parallel,
 * the adding of signals to the signal memory must be synchronized!
 * How to do this properly in C?
 *
 * @param p0 the internals memory
 */
void activate_internals(void* p0) {

    log_message_debug("Activate internals.");

    // The activation flag.
    int* f = INTEGER_NULL_POINTER;
    create_integer((void*) &f);
    *f = 0;

    // UNIX socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        receive_unix_socket(p0);

        *f = 0;
    }

    // TCP socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        receive_tcp_socket(p0);

        *f = 0;
    }

    // X windows.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &X_WINDOWS_ACTIVE_INTERNAL, (void*) &f, (void*) &ONE_ELEMENT_COUNT);

    if (*f == 1) {

        receive_x_windows(p0);

        *f = 0;
    }

//?? TEST only!
//??    send_x_windows_output(NULL, NULL, p5);
//??    sleep(4);
//??    init_x();

    // Destroy activation flag.
    destroy_integer((void*) &f);
}

/**
 * Waits for signals.
 *
 * @param p0 the internals memory
 */
void wait(void* p0) {

    log_message_debug("Run signal waiting loop.");

    // Activate internal mechanisms for signal reception.
    activate_internals(p0);

    // The knowledge memory, signal memory.
    void* k = NULL_POINTER;
    void* kc = NULL_POINTER;
    void* ks = NULL_POINTER;
    void* s = NULL_POINTER;
    void* sc = NULL_POINTER;
    void* ss = NULL_POINTER;

    // Get knowledge memory, signal memory.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) &ONE_ELEMENT_COUNT);

    // The shutdown flag.
    int* f = INTEGER_NULL_POINTER;
    create_integer((void*) &f);
    *f = 0;
    // The abstraction.
    void* a = NULL_POINTER;
    void* ac = NULL_POINTER;
    // The model (signal operation).
    void* m = NULL_POINTER;
    void* mc = NULL_POINTER;
    // The details (parameters).
    void* d = NULL_POINTER;
    void* dc = NULL_POINTER;
    // The priority.
    void* p = NULL_POINTER;
    // The signal id.
    void* id = NULL_POINTER;
    // The highest priority index.
    int* i = INTEGER_NULL_POINTER;
    create_integer((void*) &i);
    *i = -1;
    // The comparison result.
    int* r = INTEGER_NULL_POINTER;
    create_integer((void*) &r);
    *r = 0;

    log_message((void*) &INFO_LOG_LEVEL, (void*) &WAIT_FOR_SIGNALS_MESSAGE, (void*) &WAIT_FOR_SIGNALS_MESSAGE_COUNT);

    // Run endless loop checking signal memory for signals.
    while (1) {

        if (*f == 1) {

            // Leave loop if the shutdown flag was set.
            break;
        }

        //?? For testing only. TODO: Delete this line later!
//??        sleep(1);

        //?? Test knowledge model. TODO: Delete later!
//??        test_knowledge_model((void*) &k, (void*) &kc);

        // Get index of the top priority signal.
        get_highest_priority_index((void*) &s, (void*) &sc, (void*) &i);

/*??
        //?? Wait for web input, if no signal is in memory. TODO: Use a thread for this!
        if (*i < 0) {

            run_tcp_socket((void*) &p0);
        }
*/

        if (*i >= 0) {

            // Get signal.
            get_signal((void*) &s, (void*) &sc, (void*) &i,
                (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
                (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

            //?? For testing only. TODO: Delete these lines later!
            fprintf(stderr, "wait i: %i\n", *i);
            fprintf(stderr, "wait a: %s\n", a);
            fprintf(stderr, "wait ac: %i\n", **((int**) ac));
            fprintf(stderr, "wait s: %s\n", m);
            fprintf(stderr, "wait sc: %i\n", **((int**) mc));
            fprintf(stderr, "wait p: %i\n", d);
            fprintf(stderr, "wait pc: %i\n", **((int**) dc));
            fprintf(stderr, "wait pr: %i\n", **((int**) p));
            fprintf(stderr, "wait id: %i\n", **((int**) id));
            fprintf(stderr, "wait knowledge model: %s\n", "");

            // Remove signal from signal memory.
            remove_signal((void*) &s, (void*) &sc, (void*) &ss, (void*) &i);

            // CAUTION! Do NOT destroy signal here!
            // Signals are stored in the logic knowledge tree which gets created
            // at system startup and destroyed at system shutdown.
            //?? TODO: Is this still true? A signal only encapsulates a logic model.
            //?? So the signal possibly needs to be destroyed, only not the logic model!

            //
            // Handle compound signal.
            //

            if (*r == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &CYBOL_ABSTRACTION, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    handle_compound_signal((void*) &m, (void*) &mc, (void*) &p,
                        (void*) &id, (void*) &s, (void*) &sc, (void*) &ss);
                }
            }

            //
            // Handle operation signal.
            //

            if (*r == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    handle_operation_signal((void*) &m, (void*) &mc, (void*) &d, (void*) &dc,
                        (void*) &k, (void*) &kc, (void*) &ks,
                        (void*) &id, p0, (void*) &f);
                }
            }

            //
            // Unknown signal abstraction.
            //

            if (*r == 0) {

                log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
            }

            // Destroy signal (id and priority).
            destroy_integer((void*) &id);
            destroy_integer((void*) &p);

            // Reset abstraction.
            a = NULL_POINTER;
            ac = NULL_POINTER;
            // Reset model (signal operation).
            m = NULL_POINTER;
            mc = NULL_POINTER;
            // Reset details (parameters).
            d = NULL_POINTER;
            dc = NULL_POINTER;
            // Reset priority.
            p = NULL_POINTER;
            // Reset main signal id.
            id = NULL_POINTER;
            // Reset highest priority index.
            *i = -1;
            // Reset comparison result.
            *r = 0;
        }
    }

    destroy_integer((void*) &r);
    destroy_integer((void*) &i);
    destroy_integer((void*) &f);
}

/* SIGNAL_WAITER_SOURCE */
#endif
