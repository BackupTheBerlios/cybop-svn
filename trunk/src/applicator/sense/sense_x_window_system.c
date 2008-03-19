/*
 * $RCSfile: sense_x_window_system.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-12-28 19:25:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef SENSE_X_WINDOW_SYSTEM_SOURCE
#define SENSE_X_WINDOW_SYSTEM_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include <pthread.h>
#include <signal.h>
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/sleep_time_variables.c"
#include "../../globals/variables/thread_identification_variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

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
int sense_x_window_system_check_events(pthread_mutex_t* mt, struct _XDisplay* d) {

    // CAUTION! Do NOT add a log message here!
    // It would eat up too much performance, since this function is called repeatedly.

    // The number of events.
    int n = *NUMBER_0_INTEGER;

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
void sense_x_window_system_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        struct _XDisplay* is = (struct _XDisplay*) p3;

        if (p2 != *NULL_POINTER) {

            unsigned int* st = (unsigned int*) p2;

            if (p1 != *NULL_POINTER) {

                pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                if (p0 != *NULL_POINTER) {

                    int* irq = (int*) p0;

                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Sense x window system message.");

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
                    // while sense_x_window_system runs in its own thread!
                    //
                    // CAUTION! A global variable MAY be used to set the sleep time,
                    // because it is only read but not written, and thus thread-safe.
                    // The global variable should only be manipulated in cyboi's main thread.
                    while (!sense_x_window_system_check_events(p1, p3)) {

                        sleep(*st);
                    }

                    // Lock x window system mutex.
                    pthread_mutex_lock(mt);

                    // Set x window system interrupt request to indicate
                    // that a message has been received via x window system,
                    // which may now be processed in the main thread of this system.
                    *irq = *NUMBER_1_INTEGER;

                    // Unlock x window system mutex.
                    pthread_mutex_unlock(mt);

                    while (*irq == *NUMBER_1_INTEGER) {

                        // Sleep as long as the x window system interrupt is not handled and reset yet.
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        sleep(*st);
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system message. The interrupt is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system message. The mutex is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system message. The sleep time is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system message. The display is null.");
    }
}

/**
 * Senses x window system messages.
 *
 * @param p0 the internal memory
 */
void sense_x_window_system(void* p0) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Sense x window system.");

    // The interrupt.
    void** irq = NULL_POINTER;
    // The mutex.
    void** mt = NULL_POINTER;
    // The sleep time.
    void** st = NULL_POINTER;
    // The display.
    void** d = NULL_POINTER;

    // Get interrupt.
    get_element(p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get mutex.
    get_element(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get sleep time.
    get_element(p0, (void*) X_WINDOW_SYSTEM_SLEEP_TIME_INTERNAL, (void*) &st, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get display.
    get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    while (*NUMBER_1_INTEGER) {

        // A break condition does not exist here because the loop
        // is running neverendingly while sensing messages.
        //
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service function
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

        sense_x_window_system_message(*irq, *mt, *st, *d);
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

/* SENSE_X_WINDOW_SYSTEM_SOURCE */
#endif