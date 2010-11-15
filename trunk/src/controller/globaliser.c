/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <X11/Xlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <wchar.h>
#include "../constant/model/memory/double_memory_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/model/log/level_log_model.c"
#include "../variable/type_size/conversion_type_size.c"
#include "../variable/type_size/integral_type_size.c"
#include "../variable/type_size/pointer_type_size.c"
#include "../variable/type_size/process_type_size.c"
#include "../variable/type_size/real_type_size.c"
#include "../variable/type_size/signal_type_size.c"
#include "../variable/type_size/socket_type_size.c"
#include "../variable/type_size/terminal_type_size.c"
#include "../variable/type_size/thread_type_size.c"
#include "../variable/type_size/x_window_system_type_size.c"
#include "../variable/log_setting.c"
#include "../variable/reallocation_factor.c"
#include "../variable/service_interrupt.c"
#include "../variable/thread_identification.c"

/**
 * Allocates and initialises global variables.
 *
 * CAUTION! These global variables MUST NOT be initialised in the files
 * "variable/*.c" because then, constant values are expected!
 */
void globalise() {

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    // Instead, use malloc, free and similar functions directly!
    //

    //
    // CAUTION! The glibc manual states that the data type of the result
    // of the "sizeof" function may vary between compilers.
    // It therefore recommends to use type "size_t" (instead of "int")
    // as the preferred way to declare any arguments or variables
    // that hold the size of an object.
    //
    // See:
    // http://www.gnu.org/software/libtool/manual/libc/Important-Data-Types.html#Important-Data-Types
    //
    // However, cyboi assigns the sizes of all primitive types to special
    // global integer variables at system startup, in module "globaliser.c".
    // As long as these global integer variables are used, there is
    // no need to work with type "sizt_t" in cyboi source code.
    //

    //
    // CAUTION! The SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE variable needs to be
    // initialised FIRST, BEFORE all other initialisations,
    // because all other assignments below make use of it.
    //

    //
    // Integral type size variables.
    //

    // Allocate and initialise signed char integral type size.
    // CAUTION! The sizeof operator must be used twice here,
    // because SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE cannot be used
    // before having been initialised itself.
    SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(sizeof(signed char));
    *SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(signed char);

    // Allocate and initialise unsigned char integral type size.
    UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(unsigned char);

    // Allocate and initialise signed short int integral type size.
    SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed short int);

    // Allocate and initialise unsigned short int integral type size.
    UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned short int);

    // Allocate and initialise signed int integral type size.
    SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed int);

    // Allocate and initialise unsigned int integral type size.
    UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned int);

    // Allocate and initialise signed long int integral type size.
    SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed long int);

    // Allocate and initialise unsigned long int integral type size.
    UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned long int);

    // Allocate and initialise signed long long int integral type size.
    SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed long long int);

    // Allocate and initialise unsigned long long int integral type size.
    UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned long long int);

    // Allocate and initialise wchar_t integral type size.
    WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(wchar_t);

    //
    // Real type size variables.
    //

    // Allocate and initialise float real type size.
    FLOAT_REAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *FLOAT_REAL_TYPE_SIZE = sizeof(float);

    // Allocate and initialise double real type size.
    DOUBLE_REAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *DOUBLE_REAL_TYPE_SIZE = sizeof(double);

    // Allocate and initialise long double real type size.
    LONG_DOUBLE_REAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *LONG_DOUBLE_REAL_TYPE_SIZE = sizeof(long double);

    //
    // Pointer type size variables.
    //

    // Allocate and initialise void* pointer type size.
    POINTER_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *POINTER_TYPE_SIZE = sizeof(void*);

    //
    // Conversion type size variables.
    //

    // Allocate and initialise struct mbstate_t conversion type size.
    MULTIBYTE_CHARACTER_STATE_CONVERSION_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    // CAUTION! Do NOT use "struct mbstate_t" but ONLY "mbstate_t".
    // Otherwise, the compiler brings the error:
    // "invalid application of 'sizeof' to incomplete type 'struct mbstate_t'"
    *MULTIBYTE_CHARACTER_STATE_CONVERSION_TYPE_SIZE = sizeof(mbstate_t);

    //
    // Process type size variables.
    //

    // Allocate and initialise pid_t process type size.
    IDENTIFICATION_PROCESS_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *IDENTIFICATION_PROCESS_TYPE_SIZE = sizeof(pid_t);

    //
    // Signal type size variables.
    //

    // Allocate and initialise sig_atomic_t signal type size.
    ATOMIC_SIGNAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *ATOMIC_SIGNAL_TYPE_SIZE = sizeof(sig_atomic_t);

    // Allocate and initialise volatile sig_atomic_t signal type size.
    VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE = sizeof(volatile sig_atomic_t);

    //
    // Socket type size variables.
    //

    // Allocate and initialise struct in_addr socket type size.
    INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct in_addr);

    // Allocate and initialise struct sockaddr_in socket type size.
    INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_in);

    // Allocate and initialise struct in6_addr socket type size.
    INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct in6_addr);

    // Allocate and initialise struct sockaddr_in6 socket type size.
    INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_in6);

    // Allocate and initialise struct sockaddr_un socket type size.
    LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_un);

    // Allocate and initialise struct sockaddr socket type size.
    SOCKET_ADDRESS_SOCKET_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr);

    //
    // Terminal type size variables.
    //

    // Allocate and initialise struct termios terminal type size.
    INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE = sizeof(struct termios);

    //
    // Thread type size variables.
    //

    // Allocate and initialise pthread_t thread type size.
    THREAD_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *THREAD_TYPE_SIZE = sizeof(pthread_t);

    // Allocate and initialise pthread_mutex_t thread type size.
    MUTEX_THREAD_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *MUTEX_THREAD_TYPE_SIZE = sizeof(pthread_mutex_t);

    //
    // X window system type size variables.
    //

    // Allocate and initialise struct XGCValues x window system type size.
    XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    // CAUTION! Do NOT use "struct XGCValues" but ONLY "XGCValues".
    // Otherwise, the compiler brings the error:
    // "invalid application of 'sizeof' to incomplete type 'struct XGCValues'"
    *XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE = sizeof(XGCValues);

    //
    // Log variables.
    //

    // Allocate and initialise log level.
    LOG_LEVEL = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *LOG_LEVEL = *OFF_LEVEL_LOG_MODEL;

    // Allocate and initialise log message.
    LOG_MESSAGE_COUNT = (signed short int*) malloc(*SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
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

    // Allocate cyboi service thread.
    CYBOI_SERVICE_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *CYBOI_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // Allocate and initialise gnu/linux console thread.
    GNU_LINUX_CONSOLE_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *GNU_LINUX_CONSOLE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // Allocate www service thread.
    WWW_SERVICE_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *WWW_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // Allocate x window system thread.
    X_WINDOW_SYSTEM_THREAD = (pthread_t*) malloc(*THREAD_TYPE_SIZE);
    *X_WINDOW_SYSTEM_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

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

    // Allocate and initialise cyboi service thread exit flag.
    CYBOI_SERVICE_EXIT = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *CYBOI_SERVICE_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate and initialise gnu/linux console thread exit flag.
    GNU_LINUX_CONSOLE_EXIT = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *GNU_LINUX_CONSOLE_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate and initialise www service thread exit flag.
    WWW_SERVICE_EXIT = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *WWW_SERVICE_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Allocate and initialise x window system thread exit flag.
    X_WINDOW_SYSTEM_EXIT = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *X_WINDOW_SYSTEM_EXIT = *NUMBER_0_INTEGER_MEMORY_MODEL;

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

    // Allocate and initialise array reallocation factor.
    ARRAY_REALLOCATION_FACTOR = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *ARRAY_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise compound reallocation factor.
    COMPOUND_REALLOCATION_FACTOR = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *COMPOUND_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // Allocate and initialise cybol file reallocation factor.
    CYBOL_FILE_REALLOCATION_FACTOR = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    *CYBOL_FILE_REALLOCATION_FACTOR = *NUMBER_2_INTEGER_MEMORY_MODEL;
}

/**
 * Deallocates global variables.
 *
 * There seems to be no need to use descending order, as compared to allocation.
 * The variables do not depend on each other and may be freed in the same order
 * as they were allocated.
 */
void unglobalise() {

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    // Instead, use malloc, free and similar functions directly!
    //

    //
    // Integral type size variables.
    //

    // Free signed char integral type size.
    free((void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

    // Free unsigned char integral type size.
    free((void*) UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

    // Free signed short int integral type size.
    free((void*) SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned short int integral type size.
    free((void*) UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free signed int integral type size.
    free((void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned int integral type size.
    free((void*) UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free signed long int integral type size.
    free((void*) SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned long int integral type size.
    free((void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free signed long long int integral type size.
    free((void*) SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned long long int integral type size.
    free((void*) UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free wchar_t integral type size.
    free((void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

    //
    // Real type size variables.
    //

    // Free float real type size.
    free((void*) FLOAT_REAL_TYPE_SIZE);

    // Free double real type size.
    free((void*) DOUBLE_REAL_TYPE_SIZE);

    // Free long double real type size.
    free((void*) LONG_DOUBLE_REAL_TYPE_SIZE);

    //
    // Pointer type size variables.
    //

    // Free void* pointer type size.
    free((void*) POINTER_TYPE_SIZE);

    //
    // Conversion type size variables.
    //

    // Free mbstate_t conversion type size.
    free((void*) MULTIBYTE_CHARACTER_STATE_CONVERSION_TYPE_SIZE);

    //
    // Process type size variables.
    //

    // Free pid_t process type size.
    free((void*) IDENTIFICATION_PROCESS_TYPE_SIZE);

    //
    // Signal type size variables.
    //

    // Free sig_atomic_t signal type size.
    free((void*) ATOMIC_SIGNAL_TYPE_SIZE);

    // Free volatile sig_atomic_t signal type size.
    free((void*) VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE);

    //
    // Socket type size variables.
    //

    // Free in_addr socket type size.
    free((void*) INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr_in socket type size.
    free((void*) INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    // Free in6_addr socket type size.
    free((void*) INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr_in6 socket type size.
    free((void*) INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr_un socket type size.
    free((void*) LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    // Free sockaddr socket type size.
    free((void*) SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

    //
    // Terminal type size variables.
    //

    // Free termios terminal type size.
    free((void*) INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);

    //
    // Thread type size variables.
    //

    // Free pthread_t thread type size.
    free((void*) THREAD_TYPE_SIZE);

    // Free pthread_mutex_t thread type size.
    free((void*) MUTEX_THREAD_TYPE_SIZE);

    //
    // X window system type size variables.
    //

    // Free XGCValues x window system type size.
    free((void*) XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE);

    //
    // Log variables.
    //

    // Free log level.
    free((void*) LOG_LEVEL);
    // Free log message count.
    free((void*) LOG_MESSAGE_COUNT);
    // Free log message.
    free((void*) LOG_MESSAGE);

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

    //
    // Thread identification variables.
    //

    // Free cyboi service thread.
    free((void*) CYBOI_SERVICE_THREAD);
    // Free gnu/linux console thread.
    free((void*) GNU_LINUX_CONSOLE_THREAD);
    // Free www service thread.
    free((void*) WWW_SERVICE_THREAD);
    // Free x window system thread.
    free((void*) X_WINDOW_SYSTEM_THREAD);

    //
    // Service exit variables.
    //

    // Free cyboi service thread exit flag.
    free((void*) CYBOI_SERVICE_EXIT);
    // Free gnu/linux console thread exit flag.
    free((void*) GNU_LINUX_CONSOLE_EXIT);
    // Free www service thread exit flag.
    free((void*) WWW_SERVICE_EXIT);
    // Free x window system thread exit flag.
    free((void*) X_WINDOW_SYSTEM_EXIT);

    //
    // Reallocation factor variables.
    //

    // Free array reallocation factor.
    free((void*) ARRAY_REALLOCATION_FACTOR);
    // Free compound reallocation factor.
    free((void*) COMPOUND_REALLOCATION_FACTOR);
    // Free cybol file reallocation factor.
    free((void*) CYBOL_FILE_REALLOCATION_FACTOR);
}

/* GLOBALISER_SOURCE */
#endif
