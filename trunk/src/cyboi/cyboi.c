/*
 * $RCSfile: cyboi.c,v $
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
 * This is the main file of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.50 $ $Date: 2004-12-19 00:53:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <stdio.h>
//??#include <stdlib.h>
#include "../accessor/compound_accessor.c"
#include "../accessor/signal_memory_accessor.c"
#include "../communicator/communicator.c"
#include "../creator/creator.c"
#include "../cyboi/internals.c"
#include "../cyboi/signal_waiter.c"
#include "../cyboi/config_into_internals.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../test/test.c"
#include "../web/tcp_socket_server.c"
#include "../x_windows/x_windows_handler.c"

/**
 * The main entry function.
 *
 * The main function follows a system lifecycle to start up,
 * run and shut down the CYBOI system, in the following order:
 * - create global variables
 * - create internals
 * - create signal memory
 * - create statics (state/ logic knowledge container etc.)
 * - create startup signal and add to signal memory
 * - run dynamics (signal waiting loop)
 * - destroy startup signal
 * - destroy statics (state/ logic knowledge container etc.)
 * - destroy signal memory
 * - destroy internals
 * - destroy global variables
 *
 * @param p0 the argument count (argc)
 * @param p1 the argument vector (argv)
 * @return the return value
 */
int main(int p0, char** p1) {

    // Return 1 to indicate an error, by default.
    int r = 1;

    //
    // Global variables.
    //

    // Create global variables.
    // CAUTION! They have to be created BEFORE the command line parameter check below!
    // Otherwise, the logger may not be able to log possible error messages.
    create_globals();

    //
    // Testing.
    //

    // Call testing procedures. Comment/ uncomment this as needed.
    // CAUTION! This has to stand AFTER the initialization of the
    // global variables because these are used by the testing code.
//??    test();
//??    return 0;

    if (p1 != NULL_POINTER) {

        if (p0 == *STARTUP_PARAMETERS_COUNT) {

            //
            // Internals.
            //

            // The internal ist a pointer to array with 4 colums
            // colum 1:  pointer for the value
            // colum 2:  type for the value
            // colum 3:  count for the value
            // colum 4:  size for the value
            void* p_internal = NULL_POINTER;
            create_internals_structur((void*) &p_internal);

            // Copy configuration file parameters into internals.
            initialize_internals(p1[*CONFIG_STARTUP_PARAMETER_INDEX], (void*) &p_internal);

            //
            // Signal memory.
            //

            // The signal memory and its count and size.
            void** pp_m = NULL_POINTER;
            int* p_mc = NULL_POINTER;
            int* p_ms = NULL_POINTER;

            // Create internals.
            create_internal((void*) &pp_m, (void*) &INTERNAL_TYPE_POINTER);
            create_internal((void*) &p_mc, (void*) &INTERNAL_TYPE_INTEGER);
            create_internal((void*) &p_ms, (void*) &INTERNAL_TYPE_INTEGER);

            *p_mc = 0;
            *p_ms = 0;

            // Create signal container.
            create( pp_m, p_ms,
                    (void*) &SIGNAL_MEMORY_ABSTRACTION,
                    (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);

            // Set signal container into internals.
            set_internal((void*) &p_internal, (void*) &pp_m,
                         (void*) &INTERNAL_TYPE_POINTER,
                         (void*) &INTERNAL_SIGNAL_MEMORY_INDEX);

            set_internal((void*) &p_internal, (void*) &p_mc,
                         (void*) &INTERNAL_TYPE_INTEGER,
                         (void*) &INTERNAL_SIGNAL_MEMORY_COUNT_INDEX);

            set_internal((void*) &p_internal, (void*) &p_ms,
                         (void*) &INTERNAL_TYPE_INTEGER,
                         (void*) &INTERNAL_SIGNAL_MEMORY_SIZE_INDEX);

            log_message_debug("Initialized signal container.");

            //
            // Knowledge container.
            //

            // Initialize knowledge and its count and size.
            void* pp_k = NULL_POINTER;
            int* p_kc = NULL_POINTER;
            int* p_ks = NULL_POINTER;

            // Create internal.
            create_internal( (void*) &pp_k, (void*) &INTERNAL_TYPE_POINTER );
            create_internal( (void*) &p_kc, (void*) &INTERNAL_TYPE_INTEGER );
            create_internal( (void*) &p_ks, (void*) &INTERNAL_TYPE_INTEGER );

            *p_kc = 0;
            *p_ks = 0;

            // Create knowledge container.
            create( pp_k, p_ks,
                    (void*) &COMPOUND_ABSTRACTION,
                    (void*) &COMPOUND_ABSTRACTION_COUNT );

            // set the knowledge container into internals
            set_internal( (void*) &p_internal, (void*) &pp_k,
                          (void*) &INTERNAL_TYPE_POINTER,
                          (void*) &INTERNAL_KNOWLEDGE_MODEL_INDEX );

            set_internal( (void*) &p_internal, (void*) &p_kc,
                          (void*) &INTERNAL_TYPE_INTEGER,
                          (void*) &INTERNAL_KNOWLEDGE_MODEL_COUNT_INDEX );

            set_internal( (void*) &p_internal, (void*) &p_ks,
                          (void*) &INTERNAL_TYPE_INTEGER,
                          (void*) &INTERNAL_KNOWLEDGE_MODEL_SIZE_INDEX );
            log_message_debug( "init knowledge container" );


            //
            // TCP socket.
            //

            create_tcp_socket( (void*) &p_internal );

            //
            // UNIX socket.
            //

//            // Initialize unix server socket.
//            int unix_server_socket = -1;
//            //?? Set unix server socket flag so that unix server socket gets created.
//            char unix_server_socket_flag = 0;
//            set_array_element((void*) &ci, (void*) &CHARACTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_FLAG_INDEX, (void*) &unix_server_socket_flag);
//
//            if (unix_server_socket_flag == 1) {
//
//                // Create unix server socket.
//                create_unix_socket((void*) &unix_server_socket, (void*) &UNIX_SERVER_SOCKET_FILENAME);
//            }

            //
            // Startup model.
            //

            // The source channel.
            char** sc = NULL_POINTER;
            int* scc = NULL_POINTER;
            // The source abstraction.
            char** sa = NULL_POINTER;
            int* sac = NULL_POINTER;
            // The source model.
            char** sm = NULL_POINTER;
            int* smc = NULL_POINTER;

            int internal_type = 0;

            // Get source channel.
            get_internal( (void*) &p_internal, (void*) &sc,
                          (void*) &internal_type,
                          (void*) &INTERNAL_START_CHANNEL_INDEX );
            get_internal( (void*) &p_internal, (void*) &scc,
                          (void*) &internal_type,
                          (void*) &INTERNAL_START_CHANNEL_COUNT_INDEX );

            // Get source abstraction.
            get_internal( (void*) &p_internal, (void*) &sa,
                          (void*) &internal_type,
                          (void*) &INTERNAL_START_ABSTRACTION_INDEX );
            get_internal( (void*) &p_internal, (void*) &sac,
                          (void*) &internal_type,
                          (void*) &INTERNAL_START_ABSTRACTION_COUNT_INDEX );

            // Get source model.
            get_internal( (void*) &p_internal, (void*) &sm,
                          (void*) &internal_type,
                          (void*) &INTERNAL_START_MODEL_INDEX );
            get_internal( (void*) &p_internal, (void*) &smc,
                          (void*) &internal_type,
                          (void*) &INTERNAL_START_MODEL_COUNT_INDEX );

            // The destination abstraction.
            void* da = NULL_POINTER;
            int dac = 0;
            int das = 0;
            // The destination model.
            void* dm = NULL_POINTER;
            int dmc = 0;
            int dms = 0;
            // The destination details.
            void* dd = NULL_POINTER;
            int ddc = 0;
            int dds = 0;

            // Create destination abstraction.
            create_model((void*) &da, (void*) &dac, (void*) &das,
                sa, sac,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
            log_message_debug( "create destination abstraction" );

            // Create destination model.
            create_model((void*) &dm, (void*) &dmc, (void*) &dms,
                sm, smc,
                sa, sac,
                sc, scc);
            log_message_debug( "create destination model" );

            // test_knowledge_model( (void*) &dm, (void*) &dmc );
            // CAUTION! Do not create destination details!
            // It is not needed for the startup signal.

            //
            // Startup signal.
            //

            // get the new main signal id
            int main_sig_id = 0;
            get_new_main_signal_id( pp_m, p_mc, &main_sig_id );

            // Add startup signal to signal memory.
            set_signal( pp_m, p_mc, p_ms,   //memory
                        (void*) &da, (void*) &dac,              //dest abtsraction
                        (void*) &dm, (void*) &dmc,              //dest model
                        (void*) &dd, (void*) &ddc,              //dest details
                        (void*) &NORMAL_PRIORITY,
                        (void*) &main_sig_id );
            log_message_debug( "set start signals" );

            //
            // Waiting loop.
            //

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            // The loop is left as soon as its shutdown flag is set.
            wait( (void*) &p_internal );

            //
            // Destruction.
            // CAUTION! Use descending order, as compared to creation!
            //

/*??
            // Destroy destination model.
            destroy_model((void*) &dm, (void*) &dmc, (void*) &dms,
                (void*) &sm, (void*) &smc,
                (void*) &sa, (void*) &sac,
                (void*) &sc, (void*) &scc);

            // Destroy destination abstraction.
            destroy_model((void*) &da, (void*) &dac, (void*) &das,
                (void*) &sa, (void*) &sac,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/

//            // Destroy unix server socket.
//            if (unix_server_socket_flag == 1) {
//
//                destroy_unix_socket((void*) &unix_server_socket, (void*) &UNIX_SERVER_SOCKET_FILENAME);
//            }

            // Destroy knowledge.
            destroy( pp_k, p_ks, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);

            // Destroy signal memory.
            destroy( pp_m, p_ms, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);

            // Destroy internals.
            destroy_internals_structur((void*) &p_internal);

            log_message((void*) &INFO_LOG_LEVEL, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

            // Destroy global variables.
            // CAUTION! They have to be destroyed AFTER the last log message above!
            // Otherwise, the logger may not be able to log possible error messages.
            destroy_globals();

            // Set return value to 0, to indicate proper shutdown.
            r = 0;

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT);
            log_message((void*) &INFO_LOG_LEVEL, (void*) &USAGE_MESSAGE_NEW, (void*) &USAGE_MESSAGE_NEW_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
