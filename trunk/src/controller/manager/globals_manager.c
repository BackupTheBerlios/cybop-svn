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
 * @version $Revision: 1.1 $ $Date: 2005-07-12 10:38:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GLOBALS_HANDLER_SOURCE
#define GLOBALS_HANDLER_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/variables/variables.c"

/**
 * Initializes the global variables.
 *
 * CAUTION! These global variables can NOT be initialized in
 * /globals/variables.c because then constant values are expected!
 */
void create_globals() {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before these global variables are set.
    fputs("Info: Create globals.\n", stdout);

    //
    // Null pointers.
    //
    // CAUTION!
    // These cannot be constant, because otherwise
    // one could not alter their values later.
    //

    // The null pointer.
    NULL_POINTER = (void*) 0;

    // The pointer null pointer.
    POINTER_NULL_POINTER = (void**) 0;

    // The integer null pointer.
    INTEGER_NULL_POINTER = (int*) 0;

    // The unsigned long null pointer.
    UNSIGNED_LONG_NULL_POINTER = (unsigned long*) 0;

    // The character null pointer.
    CHARACTER_NULL_POINTER = (char*) 0;

    // The double null pointer.
    DOUBLE_NULL_POINTER = (double*) 0;

    // The file null pointer.
    FILE_NULL_POINTER = (FILE*) 0;

    //
    // Primitive type sizes.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // The integer primitive size.
    // CAUTION! The sizeof operator must be used twice here,
    // because INTEGER_PRIMITIVE_SIZE cannot be used before being initialized.
    // CAUTION! The integer size need to be initialised FIRST!
    INTEGER_PRIMITIVE_SIZE = (int*) malloc(sizeof(int));
    *INTEGER_PRIMITIVE_SIZE = sizeof(int);

    // The character primitive size.
    CHARACTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CHARACTER_PRIMITIVE_SIZE = sizeof(char);

    // The unsigned long primitive size.
    UNSIGNED_LONG_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *UNSIGNED_LONG_PRIMITIVE_SIZE = sizeof(unsigned long);

    // The pointer primitive size.
    POINTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *POINTER_PRIMITIVE_SIZE = sizeof(void*);

    // The double primitive size.
    DOUBLE_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *DOUBLE_PRIMITIVE_SIZE = sizeof(double);

    //
    // Logging.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // The log level.
    LOG_LEVEL = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *LOG_LEVEL = *DEBUG_LOG_LEVEL;

    // The maximum log message count.
    MAXIMUM_LOG_MESSAGE_COUNT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *MAXIMUM_LOG_MESSAGE_COUNT = 300;

    // The log output.
    LOG_OUTPUT = stderr;
}

/**
 * Finalizes the global variables.
 *
 * Destroys allocated memory in descending order,
 * as compared to the initialize_globals procedure.
 */
void destroy_globals() {

    log_message_debug("Destroy globals.");

    //
    // Logging.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // The maximum log message count.
    free(MAXIMUM_LOG_MESSAGE_COUNT);

    // The log level.
    free(LOG_LEVEL);

    //
    // Primitive type sizes.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // The double primitive size.
    free(DOUBLE_PRIMITIVE_SIZE);

    // The unsigned long primitive size.
    free(UNSIGNED_LONG_PRIMITIVE_SIZE);

    // The pointer primitive size.
    free(POINTER_PRIMITIVE_SIZE);

    // The character primitive size.
    free(CHARACTER_PRIMITIVE_SIZE);

    // The integer primitive size.
    free(INTEGER_PRIMITIVE_SIZE);
}

/* GLOBALS_HANDLER_SOURCE */
#endif
