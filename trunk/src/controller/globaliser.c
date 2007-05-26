/*
 * $RCSfile: globaliser.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GLOBALISER_SOURCE
#define GLOBALISER_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/system_constants.c"
#include "../globals/variables/variables.c"

/**
 * Allocates and initialises global variables.
 *
 * CAUTION! These global variables MUST NOT be initialised in the file
 * /globals/variables/variables.c because then constant values are expected!
 */
void globalise() {

    // fputs("Information: Globalise.\n", stdout);

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

    // Allocate and initialise integer primitive size.
    // CAUTION! The sizeof operator must be used twice here, because
    // INTEGER_PRIMITIVE_SIZE cannot be used before having been initialised.
    INTEGER_PRIMITIVE_SIZE = (int*) malloc(sizeof(int));
    *INTEGER_PRIMITIVE_SIZE = sizeof(int);

    // Allocate and initialise character primitive size.
    CHARACTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CHARACTER_PRIMITIVE_SIZE = sizeof(char);

    // Allocate and initialise wide character primitive size.
    WIDE_CHARACTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *WIDE_CHARACTER_PRIMITIVE_SIZE = sizeof(wchar_t);

    // Allocate and initialise unsigned long primitive size.
    UNSIGNED_LONG_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *UNSIGNED_LONG_PRIMITIVE_SIZE = sizeof(unsigned long);

    // Allocate and initialise pointer primitive size.
    POINTER_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *POINTER_PRIMITIVE_SIZE = sizeof(void*);

    // Allocate and initialise double primitive size.
    DOUBLE_PRIMITIVE_SIZE = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *DOUBLE_PRIMITIVE_SIZE = sizeof(double);

    //
    // Thread identifications and service interrupt flags.
    //

    // Allocate and initialise linux console thread.
    LINUX_CONSOLE_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *LINUX_CONSOLE_THREAD = *INVALID_VALUE;
    // Allocate x window system thread.
    X_WINDOW_SYSTEM_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *X_WINDOW_SYSTEM_THREAD = *INVALID_VALUE;
    // Allocate www service thread.
    WWW_SERVICE_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *WWW_SERVICE_THREAD = *INVALID_VALUE;
    // Allocate cyboi service thread.
    CYBOI_SERVICE_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *CYBOI_SERVICE_THREAD = *INVALID_VALUE;

    // Allocate and initialise linux console thread interrupt flag.
    LINUX_CONSOLE_THREAD_INTERRUPT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;
    // Allocate and initialise x window system thread interrupt flag.
    X_WINDOW_SYSTEM_THREAD_INTERRUPT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *X_WINDOW_SYSTEM_THREAD_INTERRUPT = *NUMBER_0_INTEGER;
    // Allocate and initialise www service thread interrupt flag.
    WWW_SERVICE_THREAD_INTERRUPT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *WWW_SERVICE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;
    // Allocate and initialise cyboi service thread interrupt flag.
    CYBOI_SERVICE_THREAD_INTERRUPT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CYBOI_SERVICE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;
}

/**
 * Deallocates global variables.
 *
 * CAUTION! Use descending order, as compared to allocation.
 */
void unglobalise() {

    // fputs("Information: Unglobalise.\n", stdout);

    //
    // Thread identifications and service interrupt flags.
    //

    // Free linux console thread interrupt flag.
    free(LINUX_CONSOLE_THREAD_INTERRUPT);
    // Free x window system thread interrupt flag.
    free(X_WINDOW_SYSTEM_THREAD_INTERRUPT);
    // Free www service thread interrupt flag.
    free(WWW_SERVICE_THREAD_INTERRUPT);
    // Free cyboi service thread interrupt flag.
    free(CYBOI_SERVICE_THREAD_INTERRUPT);

    // Free linux console thread.
    free(LINUX_CONSOLE_THREAD);
    // Free x window system thread.
    free(X_WINDOW_SYSTEM_THREAD);
    // Free www service thread.
    free(WWW_SERVICE_THREAD);
    // Free cyboi service thread.
    free(CYBOI_SERVICE_THREAD);

    //
    // Primitive type sizes.
    //
    // CAUTION! DO NOT use array functionality here!
    // The arrays use the logger which would cause circular references.
    // Instead, use malloc and similar functions directly!
    //

    // Free double primitive size.
    free(DOUBLE_PRIMITIVE_SIZE);

    // Free pointer primitive size.
    free(POINTER_PRIMITIVE_SIZE);

    // Free unsigned long primitive size.
    free(UNSIGNED_LONG_PRIMITIVE_SIZE);

    // Free wide character primitive size.
    free(WIDE_CHARACTER_PRIMITIVE_SIZE);

    // Free character primitive size.
    free(CHARACTER_PRIMITIVE_SIZE);

    // Free integer primitive size.
    free(INTEGER_PRIMITIVE_SIZE);
}

/* GLOBALISER_SOURCE */
#endif
