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
 * @version $Revision: 1.1 $ $Date: 2004-11-23 15:24:27 $ $Author: reichenbach $
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
#include "../global/variable.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../test/test.c"
#include "../web/tcp_socket_server.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Initializes the global variables.
 */
void initialize_global_variables() {

    //
    // Logging.
    //

    // Initialize log level.
    LOG_LEVEL = DEBUG_LOG_LEVEL;

    // Initialize maximum log message count.
    MAXIMUM_LOG_MESSAGE_COUNT = 300;

    // Initialize log output.
    LOG_OUTPUT = stderr;

    //
    // Primitive type sizes.
    //

    // Initialize pointer primitive.
    POINTER_PRIMITIVE_SIZE = sizeof(void*);

    // Initialize integer primitive.
    INTEGER_PRIMITIVE_SIZE = sizeof(int);

    // Initialize character primitive.
    CHARACTER_PRIMITIVE_SIZE = sizeof(char);

    // Initialize double primitive.
    DOUBLE_PRIMITIVE_SIZE = sizeof(double);

    //
    // Null pointers.
    //
    // CAUTION!
    // These cannot be constant, because otherwise
    // one could not alter their values later.
    //

    /** The null pointer. */
    NULL_POINTER = (void*) 0;

    /** The pointer null pointer. */
    POINTER_NULL_POINTER = (void**) 0;

    /** The integer null pointer. */
    INTEGER_NULL_POINTER = (int*) 0;

    /** The character null pointer. */
    CHARACTER_NULL_POINTER = (char*) 0;

    /** The double null pointer. */
    DOUBLE_NULL_POINTER = (double*) 0;
}



/**
 * The main entry function.
 *
 * Command line arguments have to be in order:
 * - command (cyboi)
 * - abstraction (compound|operation)
 * - location (inline|file|ftp|http)
 * - model (a compound model or primitive operation, for example: exit or model.submodel)
 *
 * Usage:
 * cyboi compound|operation inline|file|ftp|http model.submodel
 *
 * Example 1 (starts up and right away shuts down the system):
 * cyboi operation inline exit
 *
 * Example 2 (calls the startup routine of some application):
 * cyboi compound file /application/logic/startup.cybol
 *
 * The main function follows a system lifecycle to start up,
 * run and shut down the CYBOI system, in the following order:
 * 1 initialize global variables
 * 2 create statics (state/ logic knowledge container etc.)
 * 3 create startup signal and add to signal memory
 * 4 run dynamics (signal waiting loop)
 * 5 destroy startup signal
 * 6 destroy statics (state/ logic knowledge container etc.)
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

    // Initialize global variables.
    // CAUTION!
    // They have to be initialized before the command line parameter check below!
    // Otherwise, the logger may not be able to log possible error messages.
    initialize_global_variables();
    log_message_debug( "init global variables" );

    //
    // Testing.
    //

    // Call testing procedures. Comment/ uncomment this as needed.
    // CAUTION! This has to stand AFTER the initialization of the
    // global variables because these are used by the testing code.
//??    test();
//??    return 0;

    if (p1 != NULL_POINTER) {

        if (p0 == STARTUP_PARAMETERS_COUNT) {
         
            //
            // create internal
            // the internal ist a pointer to array with 4 colums
            // colum 1:  pointer for the value
            // colum 2:  type for the value
            // colum 3:  count for the value
            // colum 4:  size for the value
            //
            void* p_internal = NULL_POINTER;
            create_internals_structur( (void*) &p_internal );

            //
            // copy configuration file parameters into internals
            //

            initialize_internals( p1[CONFIG_STARTUP_PARAMETER_INDEX], 
                                  (void*) &p_internal );
            //log_message_debug( "init internals with parameters" );


            //
            // Signal memory.
            //

            // The signal memory and its count and size.
            void** pp_m = NULL_POINTER;
            int* p_mc = NULL_POINTER;
            int* p_ms = NULL_POINTER;
            
            // create the internal
            create_internal( (void*) &pp_m, (void*) &INTERNAL_TYPE_POINTER );
            create_internal( (void*) &p_mc, (void*) &INTERNAL_TYPE_INTEGER );
            create_internal( (void*) &p_ms, (void*) &INTERNAL_TYPE_INTEGER );
            
            *p_mc = 0;
            *p_ms = 0;
            
            // Create signal container.
            create( pp_m, p_ms, 
                    (void*) &SIGNAL_MEMORY_ABSTRACTION,
                    (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT );
                    
            // set the signal container into internals
            set_internal( (void*) &p_internal, (void*) &pp_m,  
                          (void*) &INTERNAL_TYPE_POINTER,
                          (void*) &INTERNAL_SIGNAL_MEMORY_INDEX );

            set_internal( (void*) &p_internal, (void*) &p_mc,  
                          (void*) &INTERNAL_TYPE_INTEGER,
                          (void*) &INTERNAL_SIGNAL_MEMORY_COUNT_INDEX );

            set_internal( (void*) &p_internal, (void*) &p_ms,  
                          (void*) &INTERNAL_TYPE_INTEGER,
                          (void*) &INTERNAL_SIGNAL_MEMORY_SIZE_INDEX );

            log_message_debug( "init signal container" );

            //
            // Knowledge container.
            //

            // Initialize knowledge and its count and size.
            void* pp_k = NULL_POINTER;
            int* p_kc = NULL_POINTER;
            int* p_ks = NULL_POINTER;

            // create the internal
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

            // CAUTION! Do not create destination details!
            // It is not needed for the startup signal.

            //
            // Startup signal.
            //

            // Add startup signal to signal memory.
            set_signal( pp_m, p_mc, p_ms,   //memory
                        (void*) &da, (void*) &dac,              //dest abtsraction
                        (void*) &dm, (void*) &dmc,              //dest model
                        (void*) &dd, (void*) &ddc,              //dest details
                        (void*) &NORMAL_PRIORITY);
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

            // destroy the internals
            destroy_internals_structur( (void*) &p_internal );

            log_message((void*) &INFO_LOG_LEVEL, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

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
