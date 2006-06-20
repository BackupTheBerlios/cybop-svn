/*
 * $RCSfile: manager.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.24 $ $Date: 2006-06-20 16:16:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include <pthread.h>
#include "../controller/checker.c"
#include "../controller/manager/system_signal_handler_manager.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/variables.c"
#include "../memoriser/allocator.c"

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

    log_message_debug("\n\n");
    log_message_debug("Info: Manage system.");

    // The internal memory.
    void* i = NULL_POINTER;
    int* ic = INTERNAL_MEMORY_ELEMENTS_COUNT;
    int* is = INTERNAL_MEMORY_ELEMENTS_COUNT;

    // The knowledge memory.
    void* k = NULL_POINTER;
    int* kc = NULL_POINTER;
    int* ks = NULL_POINTER;

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
    void* s = NULL_POINTER;
    int* sc = NULL_POINTER;
    int* ss = NULL_POINTER;

    // The signal memory mutex.
    pthread_mutex_t* smt = NULL_POINTER;
    // The x window system mutex.
    pthread_mutex_t* xmt = NULL_POINTER;

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
    volatile sig_atomic_t* irq = NULL_POINTER;

    // Allocate knowledge memory count, size.
    allocate((void*) &kc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &ks, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Allocate signal memory count, size.
    allocate((void*) &sc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &ss, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Allocate signal memory mutex.
    smt = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    // Allocate x window system mutex.
    xmt = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    // Allocate signal memory interrupt request flag.
    irq = (volatile sig_atomic_t*) malloc(sizeof(volatile sig_atomic_t));

    // Initialise knowledge memory count, size.
    *kc = *NUMBER_0_INTEGER;
    *ks = *NUMBER_0_INTEGER;
    // Initialise signal memory count, size.
    *sc = *NUMBER_0_INTEGER;
    *ss = *NUMBER_0_INTEGER;
    // Initialise signal memory mutex.
    pthread_mutex_init(smt, NULL_POINTER);
    // Initialise x window system mutex.
    pthread_mutex_init(xmt, NULL_POINTER);
    // Initialise signal memory interrupt request flag.
    *irq = *NUMBER_0_INTEGER;

    // Allocate internal memory.
    allocate((void*) &i, (void*) is, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT);
    // Allocate knowledge memory.
    allocate((void*) &k, (void*) ks, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    // Allocate signal memory.
    allocate((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT);

    // CAUTION! ONLY ONE parameter can be handed over to threads!
    // For example, the tcp socket is running in an own thread.
    // Therefore, the knowledge memory and signal memory NEED TO BE ADDED
    // to the internal memory, in order to be forwardable to threads.

    // Set knowledge memory internals.
    set(i, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(i, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(i, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set signal memory internals.
    set(i, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(i, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(i, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set signal memory mutex.
    set(i, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set x window system mutex.
    set(i, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &xmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set signal memory interrupt request flag.
    set(i, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Start up system signal handler.
    startup_system_signal_handler();

    log_message_debug("\n\n");
    log_message_debug("Info: Allocate startup model.");

    // The startup model abstraction, model, details.
    void* ma = NULL_POINTER;
    int* mac = NULL_POINTER;
    int* mas = NULL_POINTER;
    void* mm = NULL_POINTER;
    int* mmc = NULL_POINTER;
    int* mms = NULL_POINTER;
    void* md = NULL_POINTER;
    int* mdc = NULL_POINTER;
    int* mds = NULL_POINTER;

    // Allocate startup model abstraction, model, details.
    allocate((void*) &mac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    allocate((void*) &mms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // CAUTION! Do not allocate startup model details!
    // It is not needed for the startup signal.

    // Initialise startup model abstraction, model, details.
    *mac = 0;
    *mas = 0;
    *mmc = 0;
    *mms = 0;
    // CAUTION! Do not allocate startup model details!
    // It is not needed for the startup signal.

    // Create startup model abstraction, model, details.
    receive_file_system_model((void*) &ma, (void*) mac, (void*) mas,
        (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
        (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
        (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
    receive_file_system_model((void*) &mm, (void*) mmc, (void*) mms,
        p0, p1,
        COMPOUND_ABSTRACTION, COMPOUND_ABSTRACTION_COUNT,
        FILE_CHANNEL, FILE_CHANNEL_COUNT);
    // CAUTION! Do not create startup model details!
    // It is not needed for the startup signal.

    log_message_debug("\n\n");
    log_message_debug("Info: Add startup model as signal to signal memory.");

    // The signal id.
    int* id = NULL_POINTER;
    allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *id = 0;
    get_new_signal_id(s, (void*) sc, (void*) id);

    // Add startup signal to signal memory.
    set_signal(s, (void*) sc, (void*) ss, ma, (void*) mac, mm, (void*) mmc, md, (void*) mdc, (void*) NORMAL_PRIORITY, (void*) id);

    // The system is now started up and complete so that a loop
    // can be entered, checking for signals (events/ interrupts)
    // which are stored/ found in the signal memory.
    // The loop is left as soon as its shutdown flag is set.
    check(i, k, (void*) kc, (void*) ks, s, (void*) sc, (void*) ss, (void*) smt, (void*) irq);

    // Destroy signal memory mutex.
    pthread_mutex_destroy(smt);
    // Destroy x window system mutex.
    pthread_mutex_destroy(xmt);

    // Deallocate signal memory interrupt request flag.
    free((void*) irq);
    // Deallocate signal memory mutex.
    free((void*) smt);
    // Deallocate x window system mutex.
    free((void*) xmt);
    // Deallocate signal memory.
    deallocate((void*) &s, (void*) ss, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &sc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &ss, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Deallocate knowledge memory.
    deallocate((void*) &k, (void*) ks, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
    deallocate((void*) &kc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &ks, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Deallocate internal memory.
    deallocate((void*) &i, (void*) is, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT);
}

/* MANAGER_SOURCE */
#endif
