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
 * @version $Revision: 1.31 $ $Date: 2004-08-23 07:18:33 $ $Author: christian $
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
#include "../creator/signal_memory_creator.c"
#include "../cyboi/character_internals.c"
#include "../cyboi/double_internals.c"
#include "../cyboi/integer_internals.c"
#include "../cyboi/pointer_internals.c"
#include "../cyboi/signal_waiter.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/variable.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"
#include "../test/test.c"
#include "../x_windows/x_windows_handler.c"
//?? Temporary for testing.
#include "../cyboi/character_screen.c"

/**
 * Initializes the global variables.
 */
void initialize_global_variables() {

    //
    // Logging.
    //

    // Initialize log level.
    LOG_LEVEL = INFO_LOG_LEVEL;

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

    //
    // Testing.
    //

    // Call testing procedures.
    // Comment/ uncomment this as needed.
    // CAUTION!
    // This has to stand AFTER the initialization of the
    // global variables because these are used by the testing code.
//    test();
//    return 0;

    if (p1 != NULL_POINTER) {

        if (p0 == STARTUP_PARAMETERS_COUNT) {

            //
            // Knowledge container.
            //

            // Initialize knowledge and its count and size.
            void* k = NULL_POINTER;
            int kc = 0;
            int ks = 0;

            // Create knowledge container.
            create((void*) &k, (void*) &ks, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);

            //
            // Internals containers.
            //

            // Initialize character-, integer-, pointer- and double internals.
            // Internals have a fixed size, so counts or sizes are not needed.
            void* ci = NULL_POINTER;
            void* ii = NULL_POINTER;
            void* pi = NULL_POINTER;
            void* di = NULL_POINTER;

            // Create character-, integer-, pointer- and double internals.
            create_character_internals((void*) &ci, (void*) &CHARACTER_INTERNALS_COUNT);
            create_integer_internals((void*) &ii, (void*) &INTEGER_INTERNALS_COUNT);
            create_pointer_internals((void*) &pi, (void*) &POINTER_INTERNALS_COUNT);
            create_double_internals((void*) &di, (void*) &DOUBLE_INTERNALS_COUNT);

            //
            // Signal container.
            //

            // The signal container and its count and size.
            void* s = NULL_POINTER;
            int sc = 0;
            int ss = 0;

            // Create signal container.
            create((void*) &s, (void*) &ss, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);

            //
            //?? Test to set internals values.
            //?? Either take them from command line arguments or
            //?? from an extra cyboi configuration file?
            //?? Much later, all internals shall be created by default;
            //?? a cybol application can then choose if it wants to use a
            //?? certain communication mechanism that cyboi offers or not.
            //

            // Initialize unix server socket.
            int unix_server_socket = -1;
            //?? Set unix server socket flag so that unix server socket gets created.
            char unix_server_socket_flag = 1;
            set_array_element((void*) &ci, (void*) &CHARACTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_FLAG_INDEX, (void*) &unix_server_socket_flag);

            if (unix_server_socket_flag == 1) {

                // Create unix server socket.
                create_unix_socket((void*) &unix_server_socket, (void*) &UNIX_SERVER_SOCKET_FILENAME);
            }

    fprintf(stderr, "unix_socket: %i\n", unix_server_socket);

            //
            // Startup model.
            //

            // Initialize persistent part abstraction, location, model
            // and their counts and sizes.
            void* ppa = (void*) p1[ABSTRACTION_STARTUP_PARAMETER_INDEX];
            int ppac = strlen(p1[ABSTRACTION_STARTUP_PARAMETER_INDEX]);
            int ppas = ppac;
            void* ppl = (void*) p1[LOCATION_STARTUP_PARAMETER_INDEX];
            int pplc = strlen(p1[LOCATION_STARTUP_PARAMETER_INDEX]);
            int ppls = pplc;
            void* ppm = (void*) p1[MODEL_STARTUP_PARAMETER_INDEX];
            int ppmc = strlen(p1[MODEL_STARTUP_PARAMETER_INDEX]);
            int ppms = ppmc;

            // Initialize transient part abstraction, model
            // and their counts and sizes.
            // CAUTION! A transient location is not stored,
            // since that is only needed temporarily
            // for model loading.
            void* tpa = NULL_POINTER;
            int tpac = 0;
            int tpas = 0;
            void* tpm = NULL_POINTER;
            int tpmc = 0;
            int tpms = 0;

            // Create transient part abstraction, model and their counts and sizes.
            create((void*) &tpa, (void*) &tpas,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
            create((void*) &tpm, (void*) &tpms,
                (void*) &ppa, (void*) &ppac);

            // Initialize part model buffer and its count and size.
            void* pmb = NULL_POINTER;
            int pmbc = 0;
            int pmbs = 0;

            // Create part model buffer of type character to read single bytes.
            create_array((void*) &pmb, (void*) &CHARACTER_ARRAY, (void*) &pmbs);

            // Read persistent model from location into part model buffer.
            receive_general((void*) &pmb, (void*) &pmbc, (void*) &pmbs,
                (void*) &ppm, (void*) &ppmc, (void*) &ppl, (void*) &pplc);

            // Initialize transient part abstraction, model, and their counts and sizes.
            initialize_model((void*) &tpa, (void*) &tpac, (void*) &tpas,
                (void*) &ppa, (void*) &ppac,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
            initialize_model((void*) &tpm, (void*) &tpmc, (void*) &tpms,
                (void*) &pmb, (void*) &pmbc,
                (void*) &ppa, (void*) &ppac);

            // Destroy part model buffer.
            destroy_array((void*) &pmb, (void*) &CHARACTER_ARRAY, (void*) &pmbs);

            //
            // Startup signal.
            //

            // Add startup signal to signal memory.
            set_signal((void*) &s, (void*) &sc, (void*) &ss,
                (void*) &tpm, (void*) &tpmc,
                (void*) &NORMAL_PRIORITY,
                (void*) &tpa, (void*) &tpac);

            //
            // Waiting loop.
            //

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            // The loop is left as soon as its shutdown flag is set.
            wait((void*) &s, (void*) &sc, (void*) &ss,
                (void*) &k, (void*) &kc, (void*) &ks,
                (void*) &ci, (void*) &ii, (void*) &pi, (void*) &di);

            //
            // Destruction.
            //

/*??
            // Destroy transient part abstraction, model and their counts and sizes.
            destroy_model((void*) &tpa, (void*) &tpac, (void*) &tpas,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
            destroy_model((void*) &tpm, (void*) &tpmc, (void*) &tpms,
                (void*) &ppa, (void*) &ppac);
*/

            if (unix_server_socket_flag == 1) {

                // Destroy unix server socket.
                destroy_unix_socket((void*) &unix_server_socket, (void*) &UNIX_SERVER_SOCKET_FILENAME);
            }

            // Destroy signal container.
            destroy((void*) &s, (void*) &ss, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);

            // Destroy character-, integer-, pointer- and double internals.
            destroy_character_internals((void*) &ci, (void*) &CHARACTER_INTERNALS_COUNT);
            destroy_integer_internals((void*) &ii, (void*) &INTEGER_INTERNALS_COUNT);
            destroy_pointer_internals((void*) &pi, (void*) &POINTER_INTERNALS_COUNT);
            destroy_double_internals((void*) &di, (void*) &DOUBLE_INTERNALS_COUNT);

            // Destroy knowledge.
            destroy((void*) &k, (void*) &ks, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);

            log_message((void*) &INFO_LOG_LEVEL, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT);
            log_message((void*) &INFO_LOG_LEVEL, (void*) &USAGE_MESSAGE, (void*) &USAGE_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
