/*
 * Copyright (C) 1999-2011. Christian Heller.
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
#include <signal.h>

#include "../constant/channel/cybol_channel.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/double_memory_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../controller/manager/internal_memory_manager.c"
#include "../controller/manager/system_signal_handler_manager.c"
#include "../controller/checker.c"
#include "../controller/initialiser.c"
#include "../executor/memoriser/allocator/model_allocator.c"
#include "../executor/memoriser/deallocator/model_deallocator.c"
#include "../logger/logger.c"
#include "../variable/type_size/integral_type_size.c"
#include "../variable/type_size/real_type_size.c"
#include "../variable/type_size/signal_type_size.c"
#include "../variable/type_size/thread_type_size.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup internal memory (global system parametres, e.g. for input/output)
 * - startup knowledge memory (statics = state knowledge + logic knowledge)
 * - startup signal memory (knowledge models to be executed as operations)
 * - create startup signal and add to signal memory
 * - run signal checker loop (dynamics)
 * - destroy startup signal
 * - shutdown signal memory
 * - shutdown knowledge memory
 * - shutdown internal memory
 *
 * @param p0 the run source item
 */
void manage(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Manage system.");

    //
    // Variable declaration.
    //

    // The internal memory array.
    void* i = *NULL_POINTER_MEMORY_MODEL;
    // The knowledge memory part.
    void* k = *NULL_POINTER_MEMORY_MODEL;
    // The signal memory item.
    void* s = *NULL_POINTER_MEMORY_MODEL;

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
    // Why is the keyword "volatile" used here?
    //
    // In the following example, the code sets the value stored in "foo" to 0.
    // It then starts to poll that value repeatedly until it changes to 255:
    //
    // static int foo;
    // void bar(void) {
    //     foo = 0;
    //     while (foo != 255);
    // }
    //
    // An optimizing compiler will notice that no other code can possibly
    // change the value stored in "foo", and will assume that it will
    // remain equal to "0" at all times. The compiler will therefore
    // replace the function body with an infinite loop similar to this:
    //
    // void bar_optimized(void) {
    //     foo = 0;
    //     while (true);
    // }
    //
    // However, foo might represent a location that can be changed
    // by other elements of the computer system at any time,
    // such as a hardware register of a device connected to the CPU.
    // The above code would never detect such a change;
    // without the "volatile" keyword, the compiler assumes that
    // the current program is the only part of the system that could
    // change the value (which is by far the most common situation).
    //
    // To prevent the compiler from optimising code as above,
    // the "volatile" keyword is used:
    //
    // static volatile int foo;
    // void bar (void) {
    //     foo = 0;
    //     while (foo != 255);
    // }
    //
    // With this modification, the loop condition will not be optimised
    // away, and the system will detect the change when it occurs.
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

    // Allocate internal memory array.
    // CAUTION! The internal memory has a pre-defined count/size,
    // given by the constant INTERNAL_MEMORY_MEMORY_MODEL_COUNT.
    allocate_array((void*) &i, (void*) INTERNAL_MEMORY_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Allocate knowledge memory part.
    allocate_part((void*) &k, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);
    // Allocate signal memory item.
    allocate_item((void*) &s, (void*) NUMBER_1000_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Allocate signal memory interrupt request flag.
    signal_memory_irq = (volatile sig_atomic_t*) malloc(*VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE);
    // Allocate gnu/linux console interrupt request flag.
    gnu_linux_console_irq = (volatile sig_atomic_t*) malloc(*VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE);
    // Allocate x window system interrupt request flag.
    x_window_system_irq = (volatile sig_atomic_t*) malloc(*VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE);
    // Allocate www service interrupt request flag.
    www_service_irq = (volatile sig_atomic_t*) malloc(*VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE);
    // Allocate cyboi service interrupt request flag.
    cyboi_service_irq = (volatile sig_atomic_t*) malloc(*VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE);

    // Allocate signal memory mutex.
    signal_memory_mutex = (pthread_mutex_t*) malloc(*MUTEX_THREAD_TYPE_SIZE);
    // Allocate gnu/linux console mutex.
    gnu_linux_console_mutex = (pthread_mutex_t*) malloc(*MUTEX_THREAD_TYPE_SIZE);
    // Allocate x window system mutex.
    x_window_system_mutex = (pthread_mutex_t*) malloc(*MUTEX_THREAD_TYPE_SIZE);
    // Allocate www service mutex.
    www_service_mutex = (pthread_mutex_t*) malloc(*MUTEX_THREAD_TYPE_SIZE);
    // Allocate cyboi service mutex.
    cyboi_service_mutex = (pthread_mutex_t*) malloc(*MUTEX_THREAD_TYPE_SIZE);

    // Allocate signal memory sleep time.
    signal_memory_sleep_time = (double*) malloc(*DOUBLE_REAL_TYPE_SIZE);
    // Allocate gnu linux console sleep time.
    gnu_linux_console_sleep_time = (double*) malloc(*DOUBLE_REAL_TYPE_SIZE);
    // Allocate x window system sleep time.
    x_window_system_sleep_time = (double*) malloc(*DOUBLE_REAL_TYPE_SIZE);
    // Allocate www service sleep time.
    www_service_sleep_time = (double*) malloc(*DOUBLE_REAL_TYPE_SIZE);
    // Allocate cyboi service sleep time.
    cyboi_service_sleep_time = (double*) malloc(*DOUBLE_REAL_TYPE_SIZE);

    //
    // Variable initialisation.
    //

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

    startup_internal_memory(i, (void*) &k, (void*) &s,
        (void*) &signal_memory_irq, (void*) &signal_memory_mutex, (void*) &signal_memory_sleep_time,
        (void*) &gnu_linux_console_irq, (void*) &gnu_linux_console_mutex, (void*) &gnu_linux_console_sleep_time,
        (void*) &x_window_system_irq, (void*) &x_window_system_mutex, (void*) &x_window_system_sleep_time,
        (void*) &www_service_irq, (void*) &www_service_mutex, (void*) &www_service_sleep_time,
        (void*) &cyboi_service_irq, (void*) &cyboi_service_mutex, (void*) &cyboi_service_sleep_time);

    // Start up system signal handler.
    startup_system_signal_handler();

    //
    // System initialisation.
    //

    // Initialise system with an initial signal.
    initialise(s, p0, i);

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

    // Deallocate signal memory item.
    deallocate_item((void*) &s, (void*) NUMBER_1000_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Deallocate knowledge memory part.
    deallocate_part((void*) &k, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);
    // Deallocate internal memory array.
    deallocate_array((void*) &i, (void*) INTERNAL_MEMORY_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* MANAGER_SOURCE */
#endif
