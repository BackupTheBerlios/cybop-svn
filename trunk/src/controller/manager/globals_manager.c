/*
 * $RCSfile: globals_manager.c,v $
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
 * @version $Revision: 1.10 $ $Date: 2006-03-09 22:45:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GLOBALS_MANAGER_SOURCE
#define GLOBALS_MANAGER_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"

/**
 * Starts up the global variables.
 *
 * They are created, where necessary, and initialised.
 *
 * CAUTION! These global variables can NOT be initialised in the file
 * /globals/variables/variables.c because then constant values are expected!
 */
void startup_globals() {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before these global variables are set.
//??    fputs("Info: Startup globals.\n", stdout);

    //
    // Null pointer.
    //
    // CAUTION! It must not be constant, because otherwise
    // one could not alter the values it points to.
    //

    // Initialise null pointer.
    NULL_POINTER = (void*) 0;

    //
    // Primitive type sizes.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //
    // CAUTION! The integer size needs to be initialised FIRST,
    // BEFORE all other initialisations below.
    //

    // Allocate integer primitive size.
    // CAUTION! The sizeof operator must be used twice here, because
    // INTEGER_PRIMITIVE_SIZE cannot be used before having being initialised.
    INTEGER_PRIMITIVE_SIZE = (int*) malloc(sizeof(int));
    *INTEGER_PRIMITIVE_SIZE = sizeof(int);

    // Allocate character primitive size.
    CHARACTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CHARACTER_PRIMITIVE_SIZE = sizeof(char);

    // Allocate wide character primitive size.
    WIDE_CHARACTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *WIDE_CHARACTER_PRIMITIVE_SIZE = sizeof(wchar_t);

    // Allocate unsigned long primitive size.
    UNSIGNED_LONG_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *UNSIGNED_LONG_PRIMITIVE_SIZE = sizeof(unsigned long);

    // Allocate pointer primitive size.
    POINTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *POINTER_PRIMITIVE_SIZE = sizeof(void*);

    // Allocate double primitive size.
    DOUBLE_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *DOUBLE_PRIMITIVE_SIZE = sizeof(double);

    //
    // Logging.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // Allocate log level.
    LOG_LEVEL = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *LOG_LEVEL = *DEBUG_LOG_LEVEL;

    // The log file name.
    char* n = "cyboi.log";
    // The log file status flags.
    int s = O_TRUNC | O_CREAT | O_WRONLY;
    // The log file.
    int f = open(n, s);

    if (f >= 0) {

        // The file owner.
        int o = -1;

        // The file group.
        int g = -1;

        // Set file owner.
        chown(n, o, g);

        // The file access rights.
        //?? TODO: When trying to cross-compile cyboi for windows,
        //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
        int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

        // Set file access rights.
        chmod(n, r);

        // The log output.
        // Example: LOG_OUTPUT = stderr;
        LOG_OUTPUT = f;

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        fputs("Error: Could not open log file. A file error occured.\n", stdout);
    }
}

/**
 * Shuts down the global variables.
 *
 * Deallocates allocated memory in descending order,
 * as compared to the initialise_globals procedure.
 */
void shutdown_globals() {

//??    fputs("Info: Shutdown globals.\n", stdout);

    //
    // Logging.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // The log file.
    int f = LOG_OUTPUT;

    if (f >= 0) {

        // Close log file.
        close(f);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        fputs("Error: Could not close log file. A file error occured.\n", stdout);
    }

    // Free log level.
    free(LOG_LEVEL);

    //
    // Primitive type sizes.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // Free double primitive size.
    free(DOUBLE_PRIMITIVE_SIZE);

    // Free unsigned long primitive size.
    free(UNSIGNED_LONG_PRIMITIVE_SIZE);

    // Free pointer primitive size.
    free(POINTER_PRIMITIVE_SIZE);

    // Free wide character primitive size.
    free(WIDE_CHARACTER_PRIMITIVE_SIZE);

    // Free character primitive size.
    free(CHARACTER_PRIMITIVE_SIZE);

    // Free integer primitive size.
    free(INTEGER_PRIMITIVE_SIZE);
}

/* GLOBALS_MANAGER_SOURCE */
#endif
