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
 * @version $Revision: 1.59 $ $Date: 2005-01-07 11:59:47 $ $Author: christian $
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
#include "../creator/integer_creator.c"
#include "../cyboi/signal_waiter.c"
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
 * - create statics (state/ logic knowledge memory etc.)
 * - create startup signal and add to signal memory
 * - run dynamics (signal waiting loop)
 * - destroy startup signal
 * - destroy statics (state/ logic knowledge memory etc.)
 * - destroy signal memory
 * - destroy internals
 * - destroy global variables
 *
 * @param p0 the argument count (argc), the first argument being the command
 * @param p1 the argument vector (argv)
 * @return the return value
 */
int main(int p0, char** p1) {

    // Return 1 to indicate an error, by default.
    int r = 1;

    //
    // Global variables.
    //

    log_message_debug("Create globals.");

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
            // Internals memory.
            //

            log_message_debug("Create internals memory.");

            // The configuration file name.
            void* c = NULL_POINTER;
            // The configuration file name count.
            int* cc = INTEGER_NULL_POINTER;
            create_integer((void*) &cc);
            *cc = 0;
            // The internals memory.
            void* i = NULL_POINTER;

            // Get configuration file name.
            get_array_elements(p1, (void*) &POINTER_ARRAY, (void*) &CONFIGURATION_FILE_PARAMETER_INDEX, (void*) &c, (void*) &ONE_ELEMENT_COUNT);
            // Get configuration file name count.
            *cc = strlen((char*) c);
            // Create internals memory and fill it with the parameters read
            // from the configuration file that was given at command line.
            create_model((void*) &i, (void*) &INTERNALS_MEMORY_ELEMENTS_COUNT, (void*) &INTERNALS_MEMORY_ELEMENTS_COUNT,
                (void*) &c, (void*) &cc,
                (void*) &CONFIGURATION_ABSTRACTION, (void*) &CONFIGURATION_ABSTRACTION_COUNT,
                (void*) &FILE_CHANNEL, (void*) &FILE_CHANNEL_COUNT);

            //
            // Knowledge memory.
            //

            log_message_debug("Create knowledge memory.");

            // The knowledge memory count.
            int* kc = INTEGER_NULL_POINTER;
            create_integer((void*) &kc);
            *kc = 0;

            // The knowledge memory size.
            int* ks = INTEGER_NULL_POINTER;
            create_integer((void*) &ks);
            *ks = 0;

            // The knowledge memory.
            void* k = NULL_POINTER;
            create((void*) &k, (void*) &ks, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);

            // Set knowledge memory into internals.
            set_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_KNOWLEDGE_MEMORY, (void*) &k, (void*) &ONE_ELEMENT_COUNT);
            set_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_KNOWLEDGE_MEMORY_COUNT, (void*) &kc, (void*) &ONE_ELEMENT_COUNT);
            set_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_KNOWLEDGE_MEMORY_SIZE, (void*) &ks, (void*) &ONE_ELEMENT_COUNT);

            //
            // Signal memory.
            //

            log_message_debug("Create signal memory.");

            // The signal memory count.
            int* sc = INTEGER_NULL_POINTER;
            create_integer((void*) &sc);
            *sc = 0;

            // The signal memory size.
            int* ss = INTEGER_NULL_POINTER;
            create_integer((void*) &ss);
            *ss = 0;

            // The signal memory.
            void* s = NULL_POINTER;
            create((void*) &s, (void*) &ss, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);

            // Set signal memory into internals.
            set_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_SIGNAL_MEMORY, (void*) &s, (void*) &ONE_ELEMENT_COUNT);
            set_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_SIGNAL_MEMORY_COUNT, (void*) &sc, (void*) &ONE_ELEMENT_COUNT);
            set_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_SIGNAL_MEMORY_SIZE, (void*) &ss, (void*) &ONE_ELEMENT_COUNT);

            //
            // TCP socket.
            //

            log_message_debug("Create tcp socket.");

            create_tcp_socket((void*) &i);

            //
            // UNIX socket.
            //

//??            log_message_debug("Create unix socket.");

//            // Initialize unix server socket.
//            int unix_server_socket = -1;
//            //?? Set unix server socket flag so that unix server socket gets created.
//            char unix_server_socket_flag = 0;
//            set_array_element((void*) &i, (void*) &CHARACTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_FLAG_INDEX, (void*) &unix_server_socket_flag);
//
//            if (unix_server_socket_flag == 1) {
//
//                // Create unix server socket.
//                create_unix_socket((void*) &unix_server_socket, (void*) &UNIX_SERVER_SOCKET_FILENAME);
//            }

            //
            // Startup model.
            //

            log_message_debug("Determine startup parameters.");

            // The startup parameters channel, abstraction, model.
            // CAUTION! These were created while reading from the configuration file,
            // and such do not have to be created here!
            void* pc = NULL_POINTER;
            void* pcc = NULL_POINTER;
            void* pa = NULL_POINTER;
            void* pac = NULL_POINTER;
            void* pm = NULL_POINTER;
            void* pmc = NULL_POINTER;

            // Get startup parameters channel, abstraction, model.
            get_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_CHANNEL, (void*) &pc, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_CHANNEL_COUNT, (void*) &pcc, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_ABSTRACTION, (void*) &pa, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_ABSTRACTION_COUNT, (void*) &pac, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_MODEL, (void*) &pm, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements((void*) &i, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_MODEL_COUNT, (void*) &pmc, (void*) &ONE_ELEMENT_COUNT);

            log_message_debug("Create startup model abstraction.");

            // The startup model abstraction count.
            int* mac = INTEGER_NULL_POINTER;
            create_integer((void*) &mac);
            *mac = 0;

            // The startup model abstraction size.
            int* mas = INTEGER_NULL_POINTER;
            create_integer((void*) &mas);
            *mas = 0;

            // The startup model abstraction.
            void* ma = NULL_POINTER;
            create_model((void*) &ma, (void*) &mac, (void*) &mas,
                (void*) &pa, (void*) &pac,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

            log_message_debug("Create startup model model.");

            // The startup model model count.
            int* mmc = INTEGER_NULL_POINTER;
            create_integer((void*) &mmc);
            *mmc = 0;

            // The startup model model size.
            int* mms = INTEGER_NULL_POINTER;
            create_integer((void*) &mms);
            *mms = 0;

            // The startup model model.
            void* mm = NULL_POINTER;
            create_model((void*) &mm, (void*) &mmc, (void*) &mms,
                (void*) &pm, (void*) &pmc,
                (void*) &pa, (void*) &pac,
                (void*) &pc, (void*) &pcc);

            // The startup model details.
            int* mdc = INTEGER_NULL_POINTER;
            int* mds = INTEGER_NULL_POINTER;
            void* md = NULL_POINTER;

            // CAUTION! Do not create startup model details!
            // It is not needed for the startup signal.

            //
            // Startup signal.
            //

            log_message_debug("Create startup signal.");

            // The signal id.
            int* id = INTEGER_NULL_POINTER;
            create_integer((void*) &id);
            *id = 0;

            // Get new main signal id.
            get_new_signal_id((void*) &s, (void*) &sc, (void*) &id);

            // Add startup signal to signal memory.
            set_signal((void*) &s, (void*) &sc, (void*) &ss,
                (void*) &ma, (void*) &mac, (void*) &mm, (void*) &mmc,
                (void*) &md, (void*) &mdc, (void*) &NORMAL_PRIORITY, (void*) &id);

            //
            // Waiting loop.
            //

            log_message_debug("Enter signal waiting loop.");

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            // The loop is left as soon as its shutdown flag is set.
            wait((void*) &i);

            //
            // Destruction.
            // CAUTION! Use descending order, as compared to creation!
            //

            // Destroy startup signal.
            // CAUTION! All signals are destroyed in the signal waiting loop,
            // after having been read from the signal memory.
            // Since this also counts for the startup signal,
            // it must not be destroyed here!

            // Destroy startup model model, count, size.
/*??
            destroy_model((void*) &mm, (void*) &mmc, (void*) &mms,
                (void*) &pm, (void*) &pmc,
                (void*) &pa, (void*) &pac,
                (void*) &pc, (void*) &pcc);
*/
            destroy_integer((void*) &mms);
            destroy_integer((void*) &mmc);

            // Destroy startup model abstraction, count, size.
/*??
            destroy_model((void*) &ma, (void*) &mac, (void*) &mas,
                (void*) &pa, (void*) &pac,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
*/
            destroy_integer((void*) &mas);
            destroy_integer((void*) &mac);

//??            log_message_debug("Destroy unix socket.");

//            // Destroy unix server socket.
//            if (unix_server_socket_flag == 1) {
//
//                destroy_unix_socket((void*) &unix_server_socket, (void*) &UNIX_SERVER_SOCKET_FILENAME);
//            }

            // Destroy signal memory.
            log_message_debug("Destroy signal memory.");
            destroy((void*) &s, (void*) &ss, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT);
            destroy_integer((void*) &ss);
            destroy_integer((void*) &sc);

            // Destroy knowledge.
            log_message_debug("Destroy knowledge memory.");
            destroy((void*) &k, (void*) &ks, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);
            destroy_integer((void*) &ks);
            destroy_integer((void*) &kc);

            // Destroy internals memory and all its configuration parameters.
            log_message_debug("Destroy internals memory.");
/*??
            destroy_model((void*) &i, (void*) &INTERNALS_MEMORY_ELEMENTS_COUNT, (void*) &INTERNALS_MEMORY_ELEMENTS_COUNT,
                (void*) &c, (void*) &cc,
                (void*) &CONFIGURATION_ABSTRACTION, (void*) &CONFIGURATION_ABSTRACTION_COUNT,
                (void*) &FILE_CHANNEL, (void*) &FILE_CHANNEL_COUNT);
*/
            // CAUTION! The configuration file name string MUST NOT be destroyed
            // as it was given as constant command line parameter string.
            destroy_integer((void*) &cc);

            log_message((void*) &INFO_LOG_LEVEL, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

            // Destroy global variables.
            // CAUTION! They have to be destroyed AFTER the last log message above!
            // Otherwise, the logger may not be able to log possible error messages.
            log_message_debug("Destroy globals.");
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
