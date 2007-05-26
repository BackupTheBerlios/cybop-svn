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
 * @version $Revision: 1.24 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <string.h>
#include "../controller/globaliser.c"
#include "../controller/manager.c"
#include "../controller/optionaliser.c"
#include "../controller/tester.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/constants/cyboi_constants.c"
#include "../globals/variables/variables.c"

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
    //
    // YET TO ANSWER: How is that with forgotten threads?
    // Are they killed automatically when a process is shut down?

    // Return 1 to indicate an error, by default.
    int r = *NUMBER_1_INTEGER;

    if (p1 != *NULL_POINTER) {

        // fputs("Information: Execute cyboi.\n", stdout);

        // Startup global variables.
        globalise();

        // The operation mode.
        // CAUTION! It is initialised with the help operation mode,
        // to display the help message if no command line argument
        // is given by the user.
        int m = *HELP_OPERATION_MODE;

        // The cybol knowledge file path.
        void* k = *NULL_POINTER;
        int kc = *NUMBER_0_INTEGER;

        // Optionalise command line argument options.
        optionalise((void*) &m, (void*) &k, (void*) &kc, (void*) &LOG_LEVEL, (void*) &LOG_OUTPUT, (void*) p1, (void*) &p0);

        if (m == *VERSION_OPERATION_MODE) {

            // Write cyboi version to standard output.
            write(fileno(stdout), (void*) CYBOI_VERSION_LOG_MESSAGE, *CYBOI_VERSION_LOG_MESSAGE_COUNT);

        } else if (m == *HELP_OPERATION_MODE) {

            // Write cyboi help message to standard output.
            write(fileno(stdout), (void*) CYBOI_HELP_LOG_MESSAGE, *CYBOI_HELP_LOG_MESSAGE_COUNT);

        } else if (m == *TEST_OPERATION_MODE) {

            // Call test function.
            test();

        } else if (m == *KNOWLEDGE_OPERATION_MODE) {

            if ((k != *NULL_POINTER) && (kc >= *NUMBER_0_INTEGER)) {

                // Manage system startup and shutdown using the given cybol knowledge file.
                manage(k, (void*) &kc);

            } else {

                fputs("Error: Could not execute cyboi in knowledge operation mode. A cybol file name needs to be given behind the '--knowledge' command line argument.\n", stdout);

                // Write cyboi help message to standard output.
                write(fileno(stdout), (void*) CYBOI_HELP_LOG_MESSAGE, *CYBOI_HELP_LOG_MESSAGE_COUNT);
            }
        }

        // Deoptionalise command line argument options.
        deoptionalise((void*) &LOG_OUTPUT);

        // Shutdown global variables.
        unglobalise();

        // fputs("Information: Exit cyboi normally.\n", stdout);

        // Set return value to 0, to indicate proper shutdown.
        r = *NUMBER_0_INTEGER;

    } else {

        fputs("Error: Could not execute cyboi. The command line argument vector is null.\n", stdout);
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
