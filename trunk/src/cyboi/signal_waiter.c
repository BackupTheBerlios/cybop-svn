/*
 * $RCSfile: signal_waiter.c,v $
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
 * @version $Revision: 1.14 $ $Date: 2004-12-21 17:49:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_WAITER_SOURCE
#define SIGNAL_WAITER_SOURCE

#include "../accessor/signal_memory_accessor.c"
#include "../array/array.c"
#include "../cyboi/internals.c"
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
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the character internals
 * @param p4 the integer internals
 * @param p5 the pointer internals
 * @param p6 the double internals
 * @param pp_thread_parameter the only one thread parameter (typ void**)
 */
void activate_internals(void** pp_internals) {

    //
    // Unix socket.
    //

//    char unix_server_socket_flag = 0;
//
//    get_array_element(p3, (void*) &CHARACTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_FLAG_INDEX, (void*) &unix_server_socket_flag);
//
//    if (unix_server_socket_flag == 1) {
//
//        int unix_server_socket = -1;
//
//        get_array_element(p4, (void*) &INTEGER_ARRAY, (void*) &UNIX_SERVER_SOCKET_INDEX, (void*) &unix_server_socket);
//
//        receive_unix_socket((void*) &unix_server_socket);
//    }

    //
    // TCP socket.
    //

    int* p_tcp_socket_active = NULL_POINTER;
    int internal_type = 0;

    // get the active flag for tcp socket
    get_internal(pp_internals, (void*) &p_tcp_socket_active, (void*) &internal_type, (void*) &INTERNAL_TCPSOCKET_ACTIVE_INDEX);

    if ( *p_tcp_socket_active == 1) {

        //activate_tcp_socket( pp_internals );
    }

/*??
    //
    // X windows.
    //

    send_x_windows_output(NULL, NULL, p5);
    sleep(4);

    int x_windows_flag = 0;

    get_array_element(p6, (void*) &INTEGER_ARRAY, (void*) &X_WINDOWS_FLAG_INDEX, (void*) &x_windows_flag);

    if (x_windows_flag == 1) {

        receive_x_windows_input(p0, x_windows);
    }

    init_x();
*/
}

/**
 * Waits for signals.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the knowledge
 * @param p4 the knowledge count
 * @param p5 the knowledge size
 * @param p6 the character internals
 * @param p7 the integer internals
 * @param p8 the pointer internals
 * @param p9 the double internals
 */
void wait(void** pp_internal) {

    // Activate internal mechanisms for signal reception.
    activate_internals(pp_internal);

    int internal_type = 0;

    // The signal memory and knowledge model.
    void* m = NULL_POINTER;
    void* mc = NULL_POINTER;
    void* ms = NULL_POINTER;
    void* k = NULL_POINTER;
    void* kc = NULL_POINTER;
    void* ks = NULL_POINTER;

    // Get signal memory and knowledge model.
    get_internal(pp_internal, (void*) &m, (void*) &internal_type, (void*) &INTERNAL_SIGNAL_MEMORY_INDEX);
    get_internal(pp_internal, (void*) &mc, (void*) &internal_type, (void*) &INTERNAL_SIGNAL_MEMORY_COUNT_INDEX);
    get_internal(pp_internal, (void*) &ms, (void*) &internal_type, (void*) &INTERNAL_SIGNAL_MEMORY_SIZE_INDEX);
    get_internal(pp_internal, (void*) &k, (void*) &internal_type, (void*) &INTERNAL_KNOWLEDGE_MODEL_INDEX);
    get_internal(pp_internal, (void*) &kc, (void*) &internal_type, (void*) &INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX);
    get_internal(pp_internal, (void*) &ks, (void*) &internal_type, (void*) &INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX);

    // The shutdown flag.
    int* f = INTEGER_NULL_POINTER;
    create_integer((void*) &f);
    *f = 0;
    // The abstraction.
    void* a = NULL_POINTER;
    void* ac = NULL_POINTER;
    // The signal (operation).
    void* s = NULL_POINTER;
    void* sc = NULL_POINTER;
    // The parameters (details).
    void* p = NULL_POINTER;
    void* pc = NULL_POINTER;
    // The priority.
    void* pr = NULL_POINTER;
    // The main signal id
    void* id = NULL_POINTER;
    // The highest priority index.
    int* i = INTEGER_NULL_POINTER;
    create_integer((void*) &i);
    *i = -1;
    // The done flag.
    int d = 0;
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
        get_highest_priority_index((void*) &m, (void*) &mc, (void*) &i);

/*??
        //?? Wait for web input, if no signal is in memory. TODO: Use a thread for this!
        if (i < 0) {

            run_tcp_socket((void*) &pp_internal);
        }
*/

        if (*i >= 0) {

            // Get signal.
            get_signal((void*) &m, (void*) &mc, (void*) &i,
                (void*) &a, (void*) &ac, (void*) &s, (void*) &sc,
                (void*) &p, (void*) &pc, (void*) &pr, (void*) &id);

            //?? For testing only. TODO: Delete these lines later!
            fprintf(stderr, "wait i: %i\n", *i);
            fprintf(stderr, "wait a: %s\n", a);
            fprintf(stderr, "wait ac: %i\n", **((int**) ac));
            fprintf(stderr, "wait s: %s\n", s);
            fprintf(stderr, "wait sc: %i\n", **((int**) sc));
            fprintf(stderr, "wait p: %i\n", p);
            fprintf(stderr, "wait pc: %i\n", **((int**) pc));
            fprintf(stderr, "wait pr: %i\n", **((int**) pr));
            fprintf(stderr, "wait id: %i\n", **((int**) id));
            fprintf(stderr, "wait knowledge model: %s\n", "");

            // Remove signal from signal memory.
            remove_signal((void*) &m, (void*) &mc, (void*) &ms, (void*) &i);

            // CAUTION! Do NOT destroy signal here!
            // Signals are stored in the logic knowledge tree which gets created
            // at system startup and destroyed at system shutdown.
            //?? TODO: Is this still true? A signal only encapsulates a logic model.
            //?? So the signal possibly needs to be destroyed, only not the logic model!

            //
            // Handle compound signal.
            //

            if (d == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &CYBOL_ABSTRACTION, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    handle_compound_signal((void*) &s, (void*) &sc, (void*) &pr,
                        (void*) &id, (void*) &m, (void*) &mc, (void*) &ms);

                    d = 1;
                }
            }

            //
            // Handle operation signal.
            //

            if (d == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    handle_operation_signal((void*) &s, (void*) &sc, (void*) &p, (void*) &pc,
                        (void*) &k, (void*) &kc, (void*) &ks,
                        (void*) &id, (void*) &pp_internal, (void*) &f);

                    d = 1;
                }
            }

            //
            // Unknown signal abstraction.
            //

            if (d == 0) {

                log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
            }

            // Reset abstraction.
            a = NULL_POINTER;
            ac = NULL_POINTER;
            // Reset signal (operation).
            s = NULL_POINTER;
            sc = NULL_POINTER;
            // Reset parameters (details).
            p = NULL_POINTER;
            pc = NULL_POINTER;
            // Reset priority.
            pr = NULL_POINTER;
            // Reset main signal id.
            id = NULL_POINTER;
            // Reset highest priority index.
            *i = -1;
            // Reset done flag.
            d = 0;
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
