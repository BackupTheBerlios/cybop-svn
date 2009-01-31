/*
 * Copyright (C) 1999-2009. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
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
#include "../constant/model/memory/double_memory_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/model/log/level_log_model.c"
#include "../variable/log_setting.c"
#include "../variable/primitive_type_size.c"
#include "../variable/reallocation_factor.c"
#include "../variable/service_interrupt.c"
#include "../variable/thread_identification.c"

/**
 * Allocates and initialises global variables.
 *
 * CAUTION! These global variables MUST NOT be initialised in the files
 * /globals/variables/*_variables.c because then, constant values are expected!
 */
void globalise() {

    //
    // Primitive type size variables.
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
    // Log variables.
    //

    // Allocate and initialise log level.
    LOG_LEVEL = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *LOG_LEVEL = *OFF_LEVEL_LOG_MODEL;

    // Allocate and initialise log level.
    LOG_MESSAGE_COUNT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *LOG_MESSAGE_COUNT = *NUMBER_10000_INTEGER_MEMORY_MODEL;

    // Allocate log message.
    LOG_MESSAGE = (wchar_t*) malloc(*LOG_MESSAGE_COUNT);

    // CAUTION! Do NOT try to allocate or initialise the log output of type FILE!
    //
    // FILE objects are allocated and managed internally by the input/ output
    // library functions. The library creates objects of type FILE.
    // Programs should deal only with pointers to these objects (FILE* values),
    // rather than the objects themselves.
    //
    // See module "optionaliser.c", which cares about log file creation!
    //
    // Hence, the following line would not make sense and is FORBIDDEN:
    // LOG_OUTPUT = (FILE*) malloc(sizeof(FILE));
    LOG_OUTPUT = *NULL_POINTER_MEMORY_MODEL;

    //
    // Thread identification variables.
    //

    // Allocate and initialise gnu/linux console thread.
    GNU_LINUX_CONSOLE_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *GNU_LINUX_CONSOLE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // Allocate x window system thread.
    X_WINDOW_SYSTEM_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *X_WINDOW_SYSTEM_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // Allocate www service thread.
    WWW_SERVICE_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *WWW_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // Allocate cyboi service thread.
    CYBOI_SERVICE_THREAD = (pthread_t*) malloc(sizeof(pthread_t));
    *CYBOI_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    //
    // Service exit variables.
    //
    // These are accessed in the system signal handler.
    // Since the "interrupt_service_system_signal_handler" function
    // receives no parameters besides a simple signal numeric code,
    // neither the exit variables nor the internal memory can be
    // handed over as argument.
    // Therefore, they HAVE TO be defined as GLOBAL variables here.
    //

    // Allocate and initialise gnu/linux console thread exit flag.
    GNU_LINUX_CONSOLE_EXIT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *GNU_LINUX_CONSOLE_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate and initialise x window system thread exit flag.
    X_WINDOW_SYSTEM_EXIT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *X_WINDOW_SYSTEM_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate and initialise www service thread exit flag.
    WWW_SERVICE_EXIT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *WWW_SERVICE_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate and initialise cyboi service thread exit flag.
    CYBOI_SERVICE_EXIT = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CYBOI_SERVICE_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // Reallocation factor variables.
    //
    // If a source model is to be copied to a destination model, the size of
    // the destination has to be large enough to take on the source's elements.
    // If the destination is too small, its size has to be extended.
    // The reallocation factors determine how fast the destination is to grow.
    //
    // The reallocation factors have the following meaning:
    // 0 - neglect number of destination elements and count only source elements
    //     CAUTION! This may delete existing content of the destination, since
    //     its size may shrink, depending on the number of source elements.
    //     The usage of this zero reallocation factor is NOT recommended!
    // 1 - extend destination by adding the exact number of source elements
    //     This is the most memory-efficient solution. The memory structures
    //     using this reallocation factor are only as big as necessary, that is
    //     their size and count (number of elements) are IDENTICAL.
    //     If elements get removed from the memory structure, its size is
    //     shrinked by the exact number of removed elements.
    //     However, this variant is not very effective.
    // 2 - extend destination by twice its count and add number of source elements
    //     This is a more effective solution to what concerns runtime speed.
    //     Whenever the destination gets reallocated, its element count gets
    //     doubled. Therefore, it does not have to get reallocated so often.
    //     However, this variant uses more memory.
    // 3 - extend destination by thrice its count and add number of source elements
    //     This solution is similar to a reallocation factor of two, only that
    //     it is yet more effective, but also uses yet more memory.
    // x - and so on
    //

    // Allocate and initialise cybol file reallocation factor.
    CYBOL_FILE_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CYBOL_FILE_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise character vector reallocation factor.
    CHARACTER_VECTOR_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *CHARACTER_VECTOR_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise wide character vector reallocation factor.
    WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise integer vector reallocation factor.
    INTEGER_VECTOR_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *INTEGER_VECTOR_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise unsigned long vector reallocation factor.
    UNSIGNED_LONG_VECTOR_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *UNSIGNED_LONG_VECTOR_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise double vector reallocation factor.
    DOUBLE_VECTOR_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *DOUBLE_VECTOR_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise pointer vector reallocation factor.
    POINTER_VECTOR_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *POINTER_VECTOR_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise compound reallocation factor.
    COMPOUND_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *COMPOUND_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise signal memory reallocation factor.
    SIGNAL_MEMORY_REALLOCATION_FACTOR = (int*) malloc(*INTEGER_PRIMITIVE_SIZE);
    *SIGNAL_MEMORY_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
}

/**
 * Deallocates global variables.
 *
 * CAUTION! Use descending order, as compared to allocation.
 */
void unglobalise() {

    //
    // Reallocation factor variables.
    //

    // Free cybol file reallocation factor.
    free(CYBOL_FILE_REALLOCATION_FACTOR);
    // Free character vector reallocation factor.
    free(CHARACTER_VECTOR_REALLOCATION_FACTOR);
    // Free wide character vector reallocation factor.
    free(WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR);
    // Free integer vector reallocation factor.
    free(INTEGER_VECTOR_REALLOCATION_FACTOR);
    // Free unsigned long vector reallocation factor.
    free(UNSIGNED_LONG_VECTOR_REALLOCATION_FACTOR);
    // Free double vector reallocation factor.
    free(DOUBLE_VECTOR_REALLOCATION_FACTOR);
    // Free pointer vector reallocation factor.
    free(POINTER_VECTOR_REALLOCATION_FACTOR);
    // Free compound reallocation factor.
    free(COMPOUND_REALLOCATION_FACTOR);
    // Free signal memory reallocation factor.
    free(SIGNAL_MEMORY_REALLOCATION_FACTOR);

    //
    // Service exit variables.
    //

    // Free gnu/linux console thread exit flag.
    free(GNU_LINUX_CONSOLE_EXIT);
    // Free x window system thread exit flag.
    free(X_WINDOW_SYSTEM_EXIT);
    // Free www service thread exit flag.
    free(WWW_SERVICE_EXIT);
    // Free cyboi service thread exit flag.
    free(CYBOI_SERVICE_EXIT);

    //
    // Thread identification variables.
    //

    // Free gnu/linux console thread.
    free(GNU_LINUX_CONSOLE_THREAD);
    // Free x window system thread.
    free(X_WINDOW_SYSTEM_THREAD);
    // Free www service thread.
    free(WWW_SERVICE_THREAD);
    // Free cyboi service thread.
    free(CYBOI_SERVICE_THREAD);

    //
    // Log variables.
    //

    // CAUTION! Do NOT try to free the log output of type FILE!
    // It was already closed in module "optionaliser.c".
    //
    // FILE objects are allocated and managed internally by the input/ output
    // library functions. The library creates objects of type FILE.
    // Programs should deal only with pointers to these objects (FILE* values),
    // rather than the objects themselves.
    //
    // Hence, the following line would not make sense and is FORBIDDEN:
    // free(LOG_OUTPUT);

    // Free log message.
    free(LOG_MESSAGE);

    // Free log message count.
    free(LOG_MESSAGE_COUNT);

    // Free log level.
    free(LOG_LEVEL);

    //
    // Primitive type size variables.
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
