/*
 * $RCSfile: optionaliser.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-04-16 21:28:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPTIONALISER_SOURCE
#define OPTIONALISER_SOURCE

#include <stdio.h>
#include "../controller/manager.c"
#include "../controller/tester.c"
#include "../globals/constants/command_line/command_line_constants.c"
#include "../globals/constants/integer/integer_constants.c"

/**
 * Optionalises the given command line argument options.
 *
 * The GNU Standards for Command Line Interfaces to be found at:
 * http://www.gnu.org/prep/standards/html_node/Command_002dLine-Interfaces.html
 * write:
 * "All programs should support two standard options: '--version' and '--help'."
 * Therefore, this function checks for these two command line argument options.
 *
 * A further option that was added is '--test'. It is just to ease cyboi
 * development because that way, programmers can easily call test functions.
 *
 * If none of these options can be found, cyboi interprets the option command
 * line argument as cybol knowledge model file and starts up the system.
 *
 * @param p0 the option
 * @param p1 the option count
 */
void optionalise(void* p0, void* p1) {

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p0, p1, (void*) VERSION_COMMAND_LINE_OPTION, (void*) VERSION_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Write cyboi version to standard output.
            write(fileno(stdout), (void*) CYBOI_VERSION_LOG_MESSAGE, *CYBOI_VERSION_LOG_MESSAGE_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p0, p1, (void*) HELP_COMMAND_LINE_OPTION, (void*) HELP_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Write help message to standard output.
            write(fileno(stdout), (void*) CYBOI_HELP_LOG_MESSAGE, *CYBOI_HELP_LOG_MESSAGE_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p0, p1, (void*) TEST_COMMAND_LINE_OPTION, (void*) TEST_COMMAND_LINE_OPTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            // Call test function.
            // CAUTION! This has to stand AFTER the initialisation of
            // global variables, because these are used by the testing code!
            test();
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        // Manage system startup and shutdown using the given cybol file.
        manage(p0, p1);
    }
}

/* OPTIONALISER_SOURCE */
#endif
