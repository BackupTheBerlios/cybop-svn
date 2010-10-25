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
 * @version $RCSfile: manager.c,v $ $Revision: 1.56 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include <pthread.h>
#include "../controller/manager/internal_memory_manager.c"
#include "../controller/manager/system_signal_handler_manager.c"
#include "../controller/checker.c"
#include "../controller/initialiser.c"
#include "../constant/channel/cybol_channel.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../executor/memoriser/allocator.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup internal memory
 * - startup knowledge memory (statics = state knowledge + logic knowledge)
 * - startup signal memory
 * - create startup signal and add to signal memory
 * - run signal checker loop (dynamics)
 * - destroy startup signal
 * - shutdown signal memory
 * - shutdown knowledge memory (statics = state knowledge + logic knowledge)
 * - shutdown internal memory
 *
 * @param p0 the run source
 * @param p1 the run source count
 */
void manage(void* p0, void* p1) {

fwprintf(stdout, L"TEST 0: %i\n", p0);

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Manage system.");

fwprintf(stdout, L"TEST 1: %i\n", p0);

    //
    // Variable declaration.
    //

    // The internal memory.
    void* i = *NULL_POINTER_MEMORY_MODEL;
    int ic = *INTERNAL_MEMORY_MEMORY_MODEL_COUNT;
    int is = *INTERNAL_MEMORY_MEMORY_MODEL_COUNT;

    // The knowledge memory.
    void* k = *NULL_POINTER_MEMORY_MODEL;
    int* kc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ks = (int*) *NULL_POINTER_MEMORY_MODEL;

    // A meta knowledge memory?
    // Theoretically, a meta knowledge memory could be created, too, and be
    // forwarded throughout the system, just like the normal knowledge memory.
    // In practice, however, it does not make sense to keep meta knowledge
    // about the knowledge memory root.
    // And also without that root meta knowledge memory, it is possible for
    // parts of the standard knowledge memory to keep meta knowledge,
    // just that for the very root of the knowledge memory it is not.
    // Example:
    // .resmedicinae.gui.menubar#background     --> background colour as meta knowledge about menubar
    // .resmedicinae#name                       --> name as meta knowledge about resmedicinae application
    // #something                               --> meta knowledge about knowledge root = nonsense

    // The signal memory.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    int* sc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ss = (int*) *NULL_POINTER_MEMORY_MODEL;

    //
    // The signal memory interrupt request flag.
    //
    // Unix system signal handlers that return normally must modify some global
    // variable in order to have any effect. Typically, the variable is one that
    // is examined periodically by the program during normal operation.
    //
    // Whether the data in an application concerns atoms, or mere text, one has to
    // be careful about the fact that access to a single datum is not necessarily
    // atomic. This means that it can take more than one instruction to read or
    // write a single object. In such cases, a signal handler might be invoked in
    // the middle of reading or writing the object.
    // The usage of data types that are always accessed atomically is one way to
    // cope with this problem. Therefore, this flag is of type sig_atomic_t.
    //
    // Reading and writing this data type is guaranteed to happen in a single
    // instruction, so there's no way for a handler to run in the middle of an access.
    // The type sig_atomic_t is always an integer data type, but which one it is,
    // and how many bits it contains, may vary from machine to machine.
    // In practice, one can assume that int and other integer types no longer than
    // int are atomic, that is objects of this type are always accessed atomically.
    // One can also assume that pointer types are atomic; that is very convenient.
    // Both of these assumptions are true on all of the machines that the GNU C
    // library supports and on all known POSIX systems.
    //
    volatile sig_atomic_t* signal_memory_irq = (volatile sig_atomic_t*) *NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console interrupt request flag.
    volatile sig_atomic_t* gnu_linux_console_irq = (volatile sig_atomic_t*) *NULL_POINTER_MEMORY_MODEL;
    // The x window system interrupt request flag.
    volatile sig_atomic_t* x_window_system_irq = (volatile sig_atomic_t*) *NULL_POINTER_MEMORY_MODEL;
    // The www service interrupt request flag.
    volatile sig_atomic_t* www_service_irq = (volatile sig_atomic_t*) *NULL_POINTER_MEMORY_MODEL;
    // The cyboi service interrupt request flag.
    volatile sig_atomic_t* cyboi_service_irq = (volatile sig_atomic_t*) *NULL_POINTER_MEMORY_MODEL;

    // The signal memory mutex.
    pthread_mutex_t* signal_memory_mutex = (pthread_mutex_t*) *NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console mutex.
    pthread_mutex_t* gnu_linux_console_mutex = (pthread_mutex_t*) *NULL_POINTER_MEMORY_MODEL;
    // The x window system mutex.
    pthread_mutex_t* x_window_system_mutex = (pthread_mutex_t*) *NULL_POINTER_MEMORY_MODEL;
    // The www service mutex.
    pthread_mutex_t* www_service_mutex = (pthread_mutex_t*) *NULL_POINTER_MEMORY_MODEL;
    // The cyboi service mutex.
    pthread_mutex_t* cyboi_service_mutex = (pthread_mutex_t*) *NULL_POINTER_MEMORY_MODEL;

    // The signal memory sleep time.
    double* signal_memory_sleep_time = (double*) *NULL_POINTER_MEMORY_MODEL;
    // The gnu linux console sleep time.
    double* gnu_linux_console_sleep_time = (double*) *NULL_POINTER_MEMORY_MODEL;
    // The x window system sleep time.
    double* x_window_system_sleep_time = (double*) *NULL_POINTER_MEMORY_MODEL;
    // The www service sleep time.
    double* www_service_sleep_time = (double*) *NULL_POINTER_MEMORY_MODEL;
    // The cyboi service sleep time.
    double* cyboi_service_sleep_time = (double*) *NULL_POINTER_MEMORY_MODEL;

    //
    // Variable allocation.
    //

fwprintf(stdout, L"TEST 2: %i\n", p0);

    // The internal memory count and size do not have to be allocated,
    // since they have fixed values that cannot be changed at runtime.
    // Allocate knowledge memory count, size.
    allocate((void*) &kc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    allocate((void*) &ks, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Allocate signal memory count, size.
    allocate((void*) &sc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    allocate((void*) &ss, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

fwprintf(stdout, L"TEST 3: %i\n", p0);

    // Allocate signal memory interrupt request flag.
    signal_memory_irq = (volatile sig_atomic_t*) malloc(sizeof(volatile sig_atomic_t));
    // Allocate gnu/linux console interrupt request flag.
    gnu_linux_console_irq = (volatile sig_atomic_t*) malloc(sizeof(volatile sig_atomic_t));
    // Allocate x window system interrupt request flag.
    x_window_system_irq = (volatile sig_atomic_t*) malloc(sizeof(volatile sig_atomic_t));
    // Allocate www service interrupt request flag.
    www_service_irq = (volatile sig_atomic_t*) malloc(sizeof(volatile sig_atomic_t));
    // Allocate cyboi service interrupt request flag.
    cyboi_service_irq = (volatile sig_atomic_t*) malloc(sizeof(volatile sig_atomic_t));

    // Allocate signal memory mutex.
    signal_memory_mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    // Allocate gnu/linux console mutex.
    gnu_linux_console_mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    // Allocate x window system mutex.
    x_window_system_mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    // Allocate www service mutex.
    www_service_mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    // Allocate cyboi service mutex.
    cyboi_service_mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));

    // Allocate signal memory sleep time.
    signal_memory_sleep_time = (double*) malloc(*DOUBLE_PRIMITIVE_SIZE);
    // Allocate gnu linux console sleep time.
    gnu_linux_console_sleep_time = (double*) malloc(*DOUBLE_PRIMITIVE_SIZE);
    // Allocate x window system sleep time.
    x_window_system_sleep_time = (double*) malloc(*DOUBLE_PRIMITIVE_SIZE);
    // Allocate www service sleep time.
    www_service_sleep_time = (double*) malloc(*DOUBLE_PRIMITIVE_SIZE);
    // Allocate cyboi service sleep time.
    cyboi_service_sleep_time = (double*) malloc(*DOUBLE_PRIMITIVE_SIZE);

    //
    // Variable initialisation.
    //

fwprintf(stdout, L"TEST 4: %i\n", p0);

    // The internal memory count and size do not have to be initialised here,
    // since they have already been initialised above, right at their declaration.
    // Initialise knowledge memory count, size.
    *kc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *ks = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Initialise signal memory count, size.
    *sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    *ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Initialise signal memory interrupt request flag.
    *signal_memory_irq = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Initialise gnu/linux console interrupt request flag.
    *gnu_linux_console_irq = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Initialise x window system interrupt request flag.
    *x_window_system_irq = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Initialise www service interrupt request flag.
    *www_service_irq = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Initialise cyboi service interrupt request flag.
    *cyboi_service_irq = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // In the following mutex initialisation functions, the second parameter
    // specifies attributes that are to be used to initialise the mutex.
    // If the parameter is null, the mutex is initialised with default attributes.
    //

fwprintf(stdout, L"TEST 5: %i\n", p0);

    // Initialise signal memory mutex.
    pthread_mutex_init(signal_memory_mutex, *NULL_POINTER_MEMORY_MODEL);
    // Initialise gnu/linux console mutex.
    pthread_mutex_init(gnu_linux_console_mutex, *NULL_POINTER_MEMORY_MODEL);
    // Initialise x window system mutex.
    pthread_mutex_init(x_window_system_mutex, *NULL_POINTER_MEMORY_MODEL);
    // Initialise www service mutex.
    pthread_mutex_init(www_service_mutex, *NULL_POINTER_MEMORY_MODEL);
    // Initialise cyboi service mutex.
    pthread_mutex_init(cyboi_service_mutex, *NULL_POINTER_MEMORY_MODEL);

    // Initialise signal memory sleep time.
    *signal_memory_sleep_time = *NUMBER_0_1_DOUBLE_MEMORY_MODEL;
    // Initialise gnu linux console sleep time.
    *gnu_linux_console_sleep_time = *NUMBER_0_1_DOUBLE_MEMORY_MODEL;
    // Initialise x window system sleep time.
    *x_window_system_sleep_time = *NUMBER_0_1_DOUBLE_MEMORY_MODEL;
    // Initialise www service sleep time.
    *www_service_sleep_time = *NUMBER_0_1_DOUBLE_MEMORY_MODEL;
    // Initialise cyboi service sleep time.
    *cyboi_service_sleep_time = *NUMBER_0_1_DOUBLE_MEMORY_MODEL;

    //
    // CAUTION! As an exception, the following allocations have to be done AFTER the sizes
    // have been initialised above, since the sizes are used for allocation.
    //

fwprintf(stdout, L"TEST 6: %i\n", p0);

    // Allocate internal memory.
    // CAUTION! The internal memory size was declared as int (not int*) above,
    // so that a reference needs to be handed over here!
    allocate((void*) &i, (void*) &is, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Allocate knowledge memory.
    allocate((void*) &k, (void*) ks, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Allocate signal memory.
    allocate((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

fwprintf(stdout, L"TEST 7: %i\n", p0);

    //
    // System startup.
    //

    // Start up internal memory.
    //
    // CAUTION! The internal memory items have a fixed position,
    // determined by constants. The items HAVE TO be assigned an
    // initial value, since all source code relies on them.
    //
    // Most values are compared against the *NULL_POINTER_MEMORY_MODEL constant
    // to find out whether they are set or not. If now initial values
    // would be arbitrary pointers, the program would follow a wrong path,
    // because it would guess that an instance was properly allocated,
    // while in reality the value was just an arbitrary initial one.
    // Therefore, such values are initialised with the well-defined *NULL_POINTER_MEMORY_MODEL.
    //
    // CAUTION! ONLY ONE parameter can be handed over to threads!
    // For example, the tcp socket is running in an own thread.
    // Therefore, the knowledge memory and signal memory NEED TO BE ADDED
    // to the internal memory, in order to be forwardable to threads.

    startup_internal_memory(i,
        (void*) &k, (void*) &kc, (void*) &ks,
        (void*) &s, (void*) &sc, (void*) &ss,
        (void*) &signal_memory_irq, (void*) &signal_memory_mutex, (void*) &signal_memory_sleep_time,
        (void*) &gnu_linux_console_irq, (void*) &gnu_linux_console_mutex, (void*) &gnu_linux_console_sleep_time,
        (void*) &x_window_system_irq, (void*) &x_window_system_mutex, (void*) &x_window_system_sleep_time,
        (void*) &www_service_irq, (void*) &www_service_mutex, (void*) &www_service_sleep_time,
        (void*) &cyboi_service_irq, (void*) &cyboi_service_mutex, (void*) &cyboi_service_sleep_time);

fwprintf(stdout, L"TEST 8: %i\n", p0);

    // Start up system signal handler.
    startup_system_signal_handler();

    //
    // System initialisation.
    //

fwprintf(stdout, L"TEST 9: %i\n", p0);

    // Initialise system with an initial signal.
    initialise(s, (void*) sc, (void*) ss, p0, p1, i);

fwprintf(stdout, L"TEST 10: %i\n", p0);

    //
    // System shutdown.
    //

    // The following calls of "shutdown" procedures are just to be sure,
    // in case a cybol application developer has forgotten to call the
    // corresponding service shutdown operation in cybol logic templates.
    // The "interrupt" procedures are called within the "shutdown" procedures.

    // Shutdown gnu/linux console.
    maintain_shutting_gnu_linux_console(i, (void*) GNU_LINUX_CONSOLE_THREAD, (void*) GNU_LINUX_CONSOLE_EXIT);
    // Shutdown x window system.
    maintain_shutting_x_window_system(i, (void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
    // Shutdown www service.
    maintain_shutting_socket(i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME,(void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);
    // Shutdown cyboi service.
    maintain_shutting_socket(i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME, (void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);

    //
    // Variable finalisation.
    //

    // CAUTION! Do NOT remove any internal memory internals!
    // The internals have a fixed position within the internal memory.
    // Removing them would shift all entries by one position and
    // thus make all entries invalid, since they could not be found
    // at their original index anymore.

    // Destroy signal memory mutex.
    pthread_mutex_destroy(signal_memory_mutex);
    // Destroy gnu/linux console mutex.
    pthread_mutex_destroy(gnu_linux_console_mutex);
    // Destroy x window system mutex.
    pthread_mutex_destroy(x_window_system_mutex);
    // Destroy www service mutex.
    pthread_mutex_destroy(www_service_mutex);
    // Destroy cyboi service mutex.
    pthread_mutex_destroy(cyboi_service_mutex);

    //
    // Variable deallocation.
    //

    // Deallocate signal memory interrupt request flag.
    free((void*) signal_memory_irq);
    // Deallocate gnu/linux console interrupt request flag.
    free((void*) gnu_linux_console_irq);
    // Deallocate x window system interrupt request flag.
    free((void*) x_window_system_irq);
    // Deallocate www service interrupt request flag.
    free((void*) www_service_irq);
    // Deallocate cyboi service interrupt request flag.
    free((void*) cyboi_service_irq);

    // Deallocate signal memory mutex.
    free((void*) signal_memory_mutex);
    // Deallocate gnu/linux console mutex.
    free((void*) gnu_linux_console_mutex);
    // Deallocate x window system mutex.
    free((void*) x_window_system_mutex);
    // Deallocate www service mutex.
    free((void*) www_service_mutex);
    // Deallocate cyboi service mutex.
    free((void*) cyboi_service_mutex);

    // Deallocate signal memory sleep time.
    free((void*) signal_memory_sleep_time);
    // Deallocate gnu linux console sleep time.
    free((void*) gnu_linux_console_sleep_time);
    // Deallocate x window system sleep time.
    free((void*) x_window_system_sleep_time);
    // Deallocate www service sleep time.
    free((void*) www_service_sleep_time);
    // Deallocate cyboi service sleep time.
    free((void*) cyboi_service_sleep_time);

    // Deallocate signal memory.
    deallocate((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &sc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &ss, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Deallocate knowledge memory.
    deallocate((void*) &k, (void*) ks, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &kc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &ks, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
    // Deallocate internal memory.
    deallocate((void*) &i, (void*) &is, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
}

/* MANAGER_SOURCE */
#endif
