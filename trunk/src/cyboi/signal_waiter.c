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
 * @version $Revision: 1.12 $ $Date: 2004-12-08 14:08:19 $ $Author: rholzmueller $
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
void activate_internals( void** pp_internals ) {

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
    // tcp socket
    //

    int* p_tcp_socket_active = NULL_POINTER;
    int internal_type = 0;

    // get the active flag for tcp socket
    get_internal( pp_internals, (void*) &p_tcp_socket_active,
                  (void*) &internal_type,
                  (void*) &INTERNAL_TCPSOCKET_ACTIVE_INDEX );

    if ( *p_tcp_socket_active == 1) {

        //activate_tcp_socket( pp_internals );
    }
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
void  wait( void** pp_internal ) {

    // activate internal mechanisms for signal reception
    activate_internals( pp_internal );

    int internal_type = 0;

    //separated paramter from the internals
    void** pp_sig_memory = NULL_POINTER;
    void* p_sig_memory_count = NULL_POINTER;
    void* p_sig_memory_size = NULL_POINTER;

    void** pp_knowledge = NULL_POINTER;
    void* p_knowledge_count = NULL_POINTER;
    void* p_knowledge_size = NULL_POINTER;

    get_internal( pp_internal, (void*) &pp_sig_memory,
                  (void*) &internal_type,
                  (void*) &INTERNAL_SIGNAL_MEMORY_INDEX );
    get_internal( pp_internal, (void*) &p_sig_memory_count,
                  (void*) &internal_type,
                  (void*) &INTERNAL_SIGNAL_MEMORY_COUNT_INDEX );
    get_internal( pp_internal, (void*) &p_sig_memory_size,
                  (void*) &internal_type,
                  (void*) &INTERNAL_SIGNAL_MEMORY_SIZE_INDEX );

    get_internal( pp_internal, (void*) &pp_knowledge,
              (void*) &internal_type,
              (void*) &INTERNAL_KNOWLEDGE_MODEL_INDEX );
    get_internal( pp_internal, (void*) &p_knowledge_count,
              (void*) &internal_type,
              (void*) &INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX );
    get_internal( pp_internal, (void*) &p_knowledge_size,
              (void*) &internal_type,
              (void*) &INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX );

    // The shutdown flag.
    int f = 0;

    // The abstraction.
    void* a = NULL_POINTER;
    int ac = 0;
    // The signal (operation).
    void* s = NULL_POINTER;
    int sc = 0;
    // The parameters (details).
    void* p = NULL_POINTER;
    int pc = 0;
    // The priority.
    int pr = NORMAL_PRIORITY;
    // The main signal id
    int main_sig_id = 0;

    // The highest priority index.
    int i = -1;

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    log_message((void*) &INFO_LOG_LEVEL, (void*) &WAIT_FOR_SIGNALS_MESSAGE, (void*) &WAIT_FOR_SIGNALS_MESSAGE_COUNT);

    // Run endless loop checking signal memory for signals.
    while (1) {

        if (f == 1) {

            // Leave loop if the shutdown flag was set.
            break;
        }

        sleep(1);

        //test_knowledge_model( pp_knowledge, p_knowledge_count );

        // Get index of the top priority signal.
        get_highest_priority_index( pp_sig_memory,
                                    p_sig_memory_count,
                                    (void*) &i );

        //fals kein Signal anliegt, so auf eingabe von Web warten
        if (i<0) {

            run_tcp_socket( pp_internal );
        }

        if (i >= 0) {

            // Get signal.
            get_signal( pp_sig_memory, p_sig_memory_count,
                        (void*) &i,
                        (void*) &a, (void*) &ac,
                        (void*) &s, (void*) &sc,
                        (void*) &p, (void*) &pc,
                        (void*) &pr, (void*) &main_sig_id );

    fprintf(stderr, "wait i: %i\n", i);
    fprintf(stderr, "wait a: %s\n", a);
    fprintf(stderr, "wait ac: %i\n", ac);
    fprintf(stderr, "wait s: %s\n", s);
    fprintf(stderr, "wait sc: %i\n", sc);
    fprintf(stderr, "wait p: %i\n", p);
    fprintf(stderr, "wait pc: %i\n", pc);
    fprintf(stderr, "wait pr: %i\n", pr);
    fprintf(stderr, "wait id: %i\n", main_sig_id);

    fprintf(stderr, "wait knowledge model: %s\n", "");
//??    test_knowledge_model(p3, p4);

            // Remove signal.
            remove_signal( pp_sig_memory, p_sig_memory_count,
                           p_sig_memory_size,
                           (void*) &i);

            // CAUTION! Do NOT destroy signal here!
            // Signals are static and stored in the logic knowledge tree
            // which gets created at system startup and destroyed at system shutdown.

            //
            // Handle compound signal.
            //

            if (d == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &CYBOL_ABSTRACTION, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (r == 1) {

                    handle_compound_signal(
                        (void*) &s, (void*) &sc, (void*) &pr,
                        (void*) &main_sig_id,
                        (void*) pp_sig_memory,
                        (void*) p_sig_memory_count, (void*) p_sig_memory_size );

                    d = 1;
                }
            }

            //
            // Handle operation signal.
            //

            if (d == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (r == 1) {

                    handle_operation_signal(
                        (void*) &s, (void*) &sc,
                        (void*) &p, (void*) &pc,
                        (void*) pp_knowledge,
                        (void*) p_knowledge_count, (void*) p_knowledge_size,
                        (void*) &main_sig_id, pp_internal,
                        (void*) &f );

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
            ac = 0;
            // Reset signal (operation).
            s = NULL_POINTER;
            sc = 0;
            // Reset parameters (details).
            p = NULL_POINTER;
            pc = 0;
            // Reset priority.
            pr = NORMAL_PRIORITY;
            // Reset main signal id.
            main_sig_id = 0;
            // Reset highest priority index.
            i = -1;
            // Reset done flag.
            d = 0;
            // Reset comparison result.
            r = 0;
        }
    }
}

/* SIGNAL_WAITER_SOURCE */
#endif
