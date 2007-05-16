/*
 * $RCSfile: cyboi.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.23 $ $Date: 2007-05-16 19:29:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <string.h>
#include "../controller/manager/globals_manager.c"
#include "../controller/optionaliser.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log_message/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"

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
 * @param p0 the argument count (argc)
 * @param p1 the argument vector (argv), the first argument being the command
 * @return the return value (0 for normal shutdown; 1 for error)
 */
int main(int p0, char** p1) {

    // One note about dynamic memory allocation:
    // There is no point in freeing blocks at the end of a program, because all
    // of the program's space is given back to the system when the process terminates.
    // Of course, all dynamically allocated memory should also be freed properly.
    // However, if some memory to be freed is forgotten, it will not harm
    // the operating system, as it will be freed automatically on process shutdown.

    // Return 1 to indicate an error, by default.
    int r = *NUMBER_1_INTEGER;

    // Startup global variables.
    // CAUTION! They have to be created BEFORE the command line parameter check below!
    // Otherwise, the logger may not be able to log possible error messages.
    startup_globals();

    if (p1 != *NULL_POINTER) {

        if (p0 == *COMMAND_LINE_ARGUMENTS_COUNT) {

            log_message_debug("Information: Execute CYBOI.");

            // The option command line argument.
            void** o = NULL_POINTER;

            // Get option command line argument.
            get_array_elements((void*) p1, (void*) OPTION_COMMAND_LINE_ARGUMENT_INDEX, (void*) &o, (void*) POINTER_ARRAY);

            if (*o != *NULL_POINTER) {

                // Get option command line argument count (number of characters).
                //
                // There are two possibilities to determine it:
                // 1 Force the user to give it as third command line parameter
                // (this would be proper, but not very user-friendly)
                // 2 Rely on the null termination character to determine it
                // (this is a rather dirty workaround, but the strlen function can be used)
                // Possibility 2 is applied here.
                int oc = strlen((char*) *o);

                // Optionalise option command line argument.
                optionalise(*o, (void*) &oc);

                log_message((void*) INFO_LOG_LEVEL, (void*) EXIT_CYBOI_NORMALLY_MESSAGE, (void*) EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

                // Set return value to 0, to indicate proper shutdown.
                r = *NUMBER_0_INTEGER;

            } else {

                log_message_debug("Error: Could not execute CYBOI. The run source name is null.");
            }

        } else {

            log_message((void*) ERROR_LOG_LEVEL, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE, (void*) COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT);
            log_message((void*) INFO_LOG_LEVEL, (void*) CYBOI_HELP_LOG_MESSAGE, (void*) CYBOI_HELP_LOG_MESSAGE_COUNT);
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
