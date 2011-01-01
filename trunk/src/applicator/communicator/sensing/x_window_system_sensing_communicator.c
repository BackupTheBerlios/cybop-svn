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
 * @version $RCSfile: x_window_system_sensing_communicator.c,v $ $Revision: 1.11 $ $Date: 2009-02-07 00:39:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SENSING_COMMUNICATOR_SOURCE
#define X_WINDOW_SYSTEM_SENSING_COMMUNICATOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include <pthread.h>
#include <signal.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../variable/thread_identification.c"

/**
 * Checks for x window system messages (events).
 *
 * As an exception to other procedures in CYBOI, parameters are NOT handed over
 * as void* to this procedure, in order to avoid type casts and to gain faster
 * processing results.
 *
 * Another exception is that this procedure is actually a function, since it
 * returns a value, as opposed to other procedures in CYBOI which return
 * nothing (void).
 *
 * @param mt the mutex
 * @param d the display
 */
int communicate_sensing_x_window_system_check_events(pthread_mutex_t* mt, struct _XDisplay* d) {

    // The number of events.
    int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

    pthread_mutex_lock(mt);

    // Check the number of events in the event queue.
    // XEventsQueued always returns immediately without
    // input/ output if there are events already in the queue.
    //
    // There are three possible modes:
    // 1 QueuedAlready: XEventsQueued returns the number of events
    //   already in the event queue (and never performs a system call).
    //   XEventsQueued with mode QueuedAlready is identical
    //   to the XQLength function.
    // 2 QueuedAfterFlush: XEventsQueued returns the number of events
    //   already in the queue if the number is nonzero. If there are no
    //   events in the queue, XEventsQueued flushes the output buffer,
    //   attempts to read more events out of the applications connection,
    //   and returns the number read.
    // 3 QueuedAfterReading: XEventsQueued returns the number of events
    //   already in the queue if the number is nonzero. If there are no
    //   events in the queue, XEventsQueued attempts to read more events
    //   out of the applications connection WITHOUT flushing the output
    //   buffer and returns the number read.
    //
    // The decision fell on mode number 3, because:
    // - mode number 1 did not display the x window initially, since
    //   probably no expose events are placed in the queue at startup
    // - mode number 2 is undesirable, since it would flush the output
    //   buffer and might thus cause this sense-thread to conflict
    //   with the send_x_window_system procedure of the main thread
    n = XEventsQueued(d, QueuedAfterReading);

    pthread_mutex_unlock(mt);

    return n;
}

/**
 * Senses x window system message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the display
 */
void communicate_sensing_x_window_system_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        struct _XDisplay* is = (struct _XDisplay*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            unsigned int* st = (unsigned int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* irq = (int*) p0;

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // Also, this function runs in an endless loop and would produce huge log files.
                    // log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Sense x window system message.");

                    // CAUTION! Do NOT use the following statement directly here:
                    // while (XEventsQueued(*d, QueuedAfterReading) == 0) { ...}
                    //
                    // The direct call to XEventsQueued causes the following error:
                    // Xlib: sequence lost (0x10025 > 0x36) in reply type 0x7!
                    //
                    // This is because the x window system may process events in the
                    // main thread of CYBOI while XEventsQueued tries to read events.
                    // As workaround to this problem, an extra function has been defined
                    // that locks the x window system mutex before calling XEventsQueued.
                    //
                    // There is no alternative to using busy waiting (while + sleep) here.
                    // If XNextEvent was used already here (to block/ save processing time),
                    // no x windows could ever be painted by send_x_window_system meanwhile,
                    // since the x mutex is set before XNextEvent and denies access to X
                    // (which is necessary to avoid "Xlib: unexpected async reply" errors).
                    // Note that send_x_window_system runs in CYBOI's main thread,
                    // while communicate_sensing_x_window_system runs in its own thread!
                    //
                    // CAUTION! A global variable MAY be used to set the sleep time,
                    // because it is only read but not written, and thus thread-safe.
                    // The global variable should only be manipulated in cyboi's main thread.
                    while (!communicate_sensing_x_window_system_check_events(p1, p3)) {

                        sleep(*st);
                    }

                    // Lock x window system mutex.
                    pthread_mutex_lock(mt);

                    // Set x window system interrupt request to indicate
                    // that a message has been received via x window system,
                    // which may now be processed in the main thread of this system.
                    *irq = *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Unlock x window system mutex.
                    pthread_mutex_unlock(mt);

                    while (*irq == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                        // Sleep as long as the x window system interrupt is not handled and reset yet.
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        sleep(*st);
                    }

                } else {

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system message. The interrupt is null.");
                }

            } else {

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system message. The mutex is null.");
            }

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system message. The sleep time is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system message. The display is null.");
    }
}

/**
 * Senses x window system messages.
 *
 * @param p0 the internal memory
 */
void communicate_sensing_x_window_system(void* p0) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.
    // log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Sense x window system.");

    // The interrupt.
    void** irq = NULL_POINTER_MEMORY_MODEL;
    // The mutex.
    void** mt = NULL_POINTER_MEMORY_MODEL;
    // The sleep time.
    void** st = NULL_POINTER_MEMORY_MODEL;
    // The display.
    void** d = NULL_POINTER_MEMORY_MODEL;

    // Get interrupt.
    get((void*) &irq, p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get mutex.
    get((void*) &mt, p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get sleep time.
    get((void*) &st, p0, (void*) X_WINDOW_SYSTEM_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get display.
    get((void*) &d, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        // A break condition does not exist here because the loop
        // is running neverendingly while sensing messages.
        //
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service function
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

        communicate_sensing_x_window_system_message(*irq, *mt, *st, *d);
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the function that was used to create it (this function).
    // The pthread_exit() function does therefore not have to be called here.
    // However, since this function runs an endless loop waiting for input, it may
    // only be left using an external signal (see comment at "break" condition above).
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* X_WINDOW_SYSTEM_SENSING_COMMUNICATOR_SOURCE */
#endif
