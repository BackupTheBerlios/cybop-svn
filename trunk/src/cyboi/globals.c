/*
 * $RCSfile: globals.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2004-12-20 00:19:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GLOBALS_SOURCE
#define GLOBALS_SOURCE

#include "../global/log_constants.c"
#include "../global/variables.c"

/**
 * Initializes the global variables.
 *
 * CAUTION! These global variables can NOT be initialized in
 * /globals/variables.c because then constant values are expected!
 */
void create_globals() {

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

    // The character null pointer.
    CHARACTER_NULL_POINTER = (char*) 0;

    // The double null pointer.
    DOUBLE_NULL_POINTER = (double*) 0;

    // The file null pointer.
    FILE_NULL_POINTER = (FILE*) 0;

    //
    // Logging.
    //

    // The log level.
    LOG_LEVEL = DEBUG_LOG_LEVEL;

    // The maximum log message count.
    MAXIMUM_LOG_MESSAGE_COUNT = INTEGER_NULL_POINTER;
    create_integer((void*) &MAXIMUM_LOG_MESSAGE_COUNT);
    *MAXIMUM_LOG_MESSAGE_COUNT = 300;

    // The log output.
    LOG_OUTPUT = stderr;

    //
    // Primitive type sizes.
    //

    // The pointer primitive size.
    POINTER_PRIMITIVE_SIZE = INTEGER_NULL_POINTER;
    create_integer((void*) &POINTER_PRIMITIVE_SIZE);
    *POINTER_PRIMITIVE_SIZE = sizeof(void*);

    // The integer primitive size.
    INTEGER_PRIMITIVE_SIZE = INTEGER_NULL_POINTER;
    create_integer((void*) &INTEGER_PRIMITIVE_SIZE);
    *INTEGER_PRIMITIVE_SIZE = sizeof(int);

    // The character primitive size.
    CHARACTER_PRIMITIVE_SIZE = INTEGER_NULL_POINTER;
    create_integer((void*) &CHARACTER_PRIMITIVE_SIZE);
    *CHARACTER_PRIMITIVE_SIZE = sizeof(char);

    // The double primitive size.
    DOUBLE_PRIMITIVE_SIZE = INTEGER_NULL_POINTER;
    create_integer((void*) &DOUBLE_PRIMITIVE_SIZE);
    *DOUBLE_PRIMITIVE_SIZE = sizeof(double);
}

/**
 * Finalizes the global variables.
 *
 * Destroys allocated memory in descending order,
 * as compared to the initialize_globals procedure.
 */
void destroy_globals() {

    //
    // Primitive type sizes.
    //

    // The pointer primitive size.
    destroy_integer((void*) &POINTER_PRIMITIVE_SIZE);

    // The integer primitive size.
    destroy_integer((void*) &INTEGER_PRIMITIVE_SIZE);

    // The character primitive size.
    destroy_integer((void*) &CHARACTER_PRIMITIVE_SIZE);

    // The double primitive size.
    destroy_integer((void*) &DOUBLE_PRIMITIVE_SIZE);

    //
    // Logging.
    //

    // The maximum log message count.
    destroy_integer((void*) &MAXIMUM_LOG_MESSAGE_COUNT);
}

/* GLOBALS_SOURCE */
#endif
