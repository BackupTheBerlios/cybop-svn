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
 * @version $Revision: 1.2 $ $Date: 2004-09-08 19:44:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_WAITER_SOURCE
#define SIGNAL_WAITER_SOURCE

#include "../accessor/signal_memory_accessor.c"
#include "../array/array.c"
#include "../cyboi/signal_handler.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"

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
 */
void activate_internals(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6) {

    //
    // Unix socket.
    //

    char unix_server_socket_flag = 0;

    get_array_element(p3, (void*) &CHARACTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_FLAG_INDEX, (void*) &unix_server_socket_flag);

    if (unix_server_socket_flag == 1) {

        int unix_server_socket = -1;

        get_array_element(p4, (void*) &INTEGER_ARRAY, (void*) &UNIX_SERVER_SOCKET_INDEX, (void*) &unix_server_socket);

        receive_unix_socket((void*) &unix_server_socket);
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
void wait(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9) {

    // Activate internal mechanisms for signal reception.
    activate_internals(p0, p1, p2, p6, p7, p8, p9);

    // The shutdown flag.
    int f = 0;
    // The highest priority index.
    int i = -1;
    // The signal.
    void* s = NULL_POINTER;
    // The signal count.
    int sc = 0;
    // The priority.
    int p = NORMAL_PRIORITY;
    // The abstraction.
    void* a = NULL_POINTER;
    // The abstraction count.
    int ac = 0;
    // The signal size.
    int ss = 0;
    // The persistent model.
    void* pers = NULL_POINTER;
    // The persistent model size.
    int perss = 0;
    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    log_message((void*) &INFO_LOG_LEVEL, (void*) &WAIT_FOR_SIGNALS_MESSAGE, (void*) &WAIT_FOR_SIGNALS_MESSAGE_COUNT);

    // Run endless loop handling signals.
    while (1) {

        if (f == 1) {

            // Leave loop if the shutdown flag was set.
            break;
        }

        // Get top priority signal from signal memory and remove it from there.
        get_highest_priority_index(p0, p1, (void*) &i);

        if (i >= 0) {

            get_signal(p0, p1, (void*) &i,
                (void*) &s, (void*) &sc, (void*) &p, (void*) &a, (void*) &ac);

    fprintf(stderr, "wait i: %i\n", i);
    fprintf(stderr, "wait s: %i\n", s);
    fprintf(stderr, "wait sc: %i\n", sc);
    fprintf(stderr, "wait p: %i\n", p);
    fprintf(stderr, "wait a: %i\n", a);
    fprintf(stderr, "wait ac: %i\n", ac);

            // Abstraction and priority are removed internally,
            // together with the signal.
            remove_signal(p0, p1, p2, (void*) &i);

            // CAUTION! Do NOT destroy signal here!
            // Signals are static and stored in the logic knowledge tree
            // which gets created at system startup and destroyed at system shutdown.

            //
            // Handle compound signal.
            //

            if (d == 0) {

                if (ac == COMPOUND_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &a, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        handle_compound_signal((void*) &s, (void*) &sc, (void*) &p, p0, p1, p2);

                        d = 1;
                    }
                }
            }

            //
            // Handle operation signal.
            //

            if (d == 0) {

                if (ac == OPERATION_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &a, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        handle_operation_signal((void*) &s, (void*) &sc,
                            p3, p4, p5, p6, p7, p8, p9, (void*) &f);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
            }

            // Reset signal.
            s = NULL_POINTER;
            // Reset signal count.
            sc = 0;
            // Reset priority.
            p = NORMAL_PRIORITY;
            // Reset abstraction.
            a = NULL_POINTER;
            // Reset abstraction count.
            ac = 0;
            // Reset highest priority index.
            i == -1;
            // Reset done flag.
            d == 0;
            // Reset comparison result.
            r == 0;
        }
    }
}

/* SIGNAL_WAITER_SOURCE */
#endif
