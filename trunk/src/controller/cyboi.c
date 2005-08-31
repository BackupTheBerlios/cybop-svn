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
 * @version $Revision: 1.11 $ $Date: 2005-08-31 14:50:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <string.h>
#include "../controller/manager/globals_manager.c"
#include "../controller/manager.c"
#include "../globals/logger/logger.c"
#include "../tester/tester.c"

/**
 * The main entry function.
 *
 * It reads the command line parameters that were handed over and
 * takes care about basic system parameters:
 * - create global variables
 * - create internal memory
 * - handle system
 * - destroy internal memory
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

    // Startup global variables.
    // CAUTION! They have to be created BEFORE the command line parameter check below!
    // Otherwise, the logger may not be able to log possible error messages.
    startup_globals();

    // Call testing procedures. Comment/ uncomment this as needed!
    // CAUTION! This has to stand AFTER the initialization of the
    // global variables because these are used by the testing code.
//??    test(); deallocate_globals(); r = 0; return r;

    if (p1 != NULL_POINTER) {

        if (p0 == *STARTUP_PARAMETERS_COUNT) {

            log_message_debug("Execute CYBOI.");

            // The run source name.
            void** s = &NULL_POINTER;

            // Get run source name.
            get_array_elements((void*) p1, (void*) RUN_FILE_PARAMETER_INDEX, (void*) &s, (void*) POINTER_ARRAY);

            if (*s != NULL_POINTER) {

                // CAUTION! This is a DIRTY workaround!
                // The run source count (number of file path characters)
                // is not known. There are two possibilities to determine it:
                // 1 Force the user to give it as third command line parameter
                // (this would be rather weird and not very user-friendly)
                // 2 Rely on the null termination character to determine it
                // (in this case, the strlen function can be used)
                // Possibility 2 is applied here.
                int sc = strlen((char*) *s);

                // Manage system.
                manage(*s, (void*) &sc);

                log_message((void*) INFO_LOG_LEVEL, (void*) EXIT_CYBOI_NORMALLY_MESSAGE, (void*) EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

                // Set return value to 0, to indicate proper shutdown.
                r = 0;

            } else {

                log_message_debug("Could not execute CYBOI. The run source name is null.");
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT);
            log_message((void*) INFO_LOG_LEVEL, (void*) USAGE_MESSAGE, (void*) USAGE_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }

    // Shutdown global variables.
    // CAUTION! They have to be destroyed AFTER the log messages above!
    // Otherwise, the logger may not be able to log possible error messages.
    shutdown_globals();

    return r;
}

/* CYBOI_SOURCE */
#endif
