/*
 * $RCSfile: cyboi.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.76 $ $Date: 2005-03-30 14:15:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include "../creator/integer_creator.c"
#include "../creator/pointer_creator.c"
#include "../cyboi/globals_handler.c"
#include "../cyboi/system_handler.c"
#include "../global/channel_constants.c"
#include "../global/integer_constants.c"
#include "../logic/create.c"
#include "../test/test.c"

/**
 * The main entry function.
 *
 * It reads the command line parameters that were handed over and
 * takes care about basic system parameters:
 * - create global variables
 * - create internals memory
 * - handle system
 * - destroy internals memory
 * - destroy global variables
 *
 * The test function is only provided for testing reasons and can be ignored.
 *
 * @param p0 the argument count (argc), the first argument being the command
 * @param p1 the argument vector (argv)
 * @return the return value
 */
int main(int p0, char** p1) {

    // Return 1 to indicate an error, by default.
    int r = 1;

    // Create global variables.
    // CAUTION! They have to be created BEFORE the command line parameter check below!
    // Otherwise, the logger may not be able to log possible error messages.
    create_globals();

    // Call testing procedures. Comment/ uncomment this as needed.
    // CAUTION! This has to stand AFTER the initialization of the
    // global variables because these are used by the testing code.
//??    test(); destroy_globals(); r = 0; return r;

    if (p1 != NULL_POINTER) {

        if (p0 == *STARTUP_PARAMETERS_COUNT) {

            log_message_debug("Execute CYBOI.");

            // The configuration file name.
            void** c = POINTER_NULL_POINTER;

            // Get configuration file name.
            get_array_elements((void*) p1, (void*) CONFIGURATION_FILE_PARAMETER_INDEX, (void*) &c, (void*) POINTER_ARRAY);

            if (c != POINTER_NULL_POINTER) {

                // CAUTION! This is a DIRTY workaround!
                // The configuration file count (number of file path characters)
                // is not known. There are two possibilities to determine it:
                // 1 Force the user to give it as third command line parameter
                // (this would be rather weird and not very user-friendly)
                // 2 Rely on the null termination character to determine it
                // (in this case, the strlen function can be used)
                // Possibility 2 is applied here.
                int cc = strlen((char*) *c);
                // The internals memory.
                void* i = NULL_POINTER;

                // Create internals memory.
                // Fill it with the parameters read from the configuration file.
                create_model((void*) &i, (void*) INTERNALS_MEMORY_ELEMENTS_COUNT, (void*) INTERNALS_MEMORY_ELEMENTS_COUNT,
                    *c, (void*) &cc,
                    (void*) CONFIGURATION_ABSTRACTION, (void*) CONFIGURATION_ABSTRACTION_COUNT,
                    (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

                // Handle system.
                handle_system(i);

                // Destroy internals memory.
                // All its configuration parameters are destroyed, too.
                destroy_model((void*) &i, (void*) INTERNALS_MEMORY_ELEMENTS_COUNT, (void*) INTERNALS_MEMORY_ELEMENTS_COUNT,
                    *c, (void*) &cc,
                    (void*) CONFIGURATION_ABSTRACTION, (void*) CONFIGURATION_ABSTRACTION_COUNT,
                    (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

                log_message((void*) INFO_LOG_LEVEL, (void*) EXIT_CYBOI_NORMALLY_MESSAGE, (void*) EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

                // Set return value to 0, to indicate proper shutdown.
                r = 0;

            } else {

                log_message_debug("Could not execute CYBOI. The configuration file name is null.");
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT);
            log_message((void*) INFO_LOG_LEVEL, (void*) USAGE_MESSAGE, (void*) USAGE_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }

    // Destroy global variables.
    // CAUTION! They have to be destroyed AFTER the log messages above!
    // Otherwise, the logger may not be able to log possible error messages.
    destroy_globals();

    return r;
}

/* CYBOI_SOURCE */
#endif
