/*
 * $RCSfile: receive_x_window_system.c,v $
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
 * @version $Revision: 1.18 $ $Date: 2006-06-17 10:32:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef RECEIVE_X_WINDOW_SYSTEM_SOURCE
#define RECEIVE_X_WINDOW_SYSTEM_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include <pthread.h>
#include <signal.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/cyboi_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Determine the graphical part's mouse command.
 *
 * The activated button is identified first.
 * Afterwards, the event type is identified.
 * Finally, the corresponding mouse command is returned as result.
 *
 * @param p0 the command abstraction (Hand over as reference!)
 * @param p1 the command abstraction count (Hand over as reference!)
 * @param p2 the command abstraction size (Hand over as reference!)
 * @param p3 the command model (Hand over as reference!)
 * @param p4 the command model count (Hand over as reference!)
 * @param p5 the command model size (Hand over as reference!)
 * @param p6 the command details (Hand over as reference!)
 * @param p7 the command details count (Hand over as reference!)
 * @param p8 the command details size (Hand over as reference!)
 * @param p9 the whole details
 * @param p10 the whole details count
 * @param p11 the event type
 * @param p12 the mouse button
 * @param p13 the knowledge memory
 * @param p14 the knowledge memory count
 */
void receive_x_window_system_mouse_command(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p12 != NULL_POINTER) {

        int* b = (int*) p12;

        if (p11 != NULL_POINTER) {

            int* t = (int*) p11;

            if (*b == Button1) {

                if (*t == ButtonPress) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(p9, p10,
                        (void*) GUI_LEFT_PRESS_COMMAND_NAME, (void*) GUI_LEFT_PRESS_COMMAND_NAME_COUNT,
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p13, p14);

                } else if (*t == ButtonRelease) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(p9, p10,
                        (void*) GUI_LEFT_RELEASE_COMMAND_NAME, (void*) GUI_LEFT_RELEASE_COMMAND_NAME_COUNT,
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p13, p14);
                }

            } else if (*b == Button2) {
            } else if (*b == Button3) {
            } else if (*b == Button4) {
            } else if (*b == Button5) {
            }

        } else {

            log_message_debug("Could not receive x window system mouse command. The event type is null.");
        }

    } else {

        log_message_debug("Could not receive x window system mouse command. The mouse button is null.");
    }
}

/**
 * Determine the graphical part's command.
 *
 * The event type gets identified, in order to call the corresponding procedure.
 * Mouse press or -release events have to be handled differently than drag'n'drop.
 *
 * @param p0 the command abstraction (Hand over as reference!)
 * @param p1 the command abstraction count (Hand over as reference!)
 * @param p2 the command abstraction size (Hand over as reference!)
 * @param p3 the command model (Hand over as reference!)
 * @param p4 the command model count (Hand over as reference!)
 * @param p5 the command model size (Hand over as reference!)
 * @param p6 the command details (Hand over as reference!)
 * @param p7 the command details count (Hand over as reference!)
 * @param p8 the command details size (Hand over as reference!)
 * @param p9 the whole details
 * @param p10 the whole details count
 * @param p11 the event type
 * @param p12 the mouse button
 * @param p13 the knowledge memory
 * @param p14 the knowledge memory count
 */
void receive_x_window_system_command(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p11 != NULL_POINTER) {

        int* t = (int*) p11;

        if ((*t == ButtonPress) || (*t == ButtonRelease)) {

            receive_x_window_system_mouse_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);

/*??
        } else if (*t == MouseMove) {

            // Drag'n'Drop needs to be handled differently than simple mouse clicks.
*/
        }

    } else {

        log_message_debug("Could not receive x window system command. The event type is null.");
    }
}

/**
 * Determine the graphical part that was activated by mouse,
 * in order to determine its command.
 *
 * The given tree of graphical parts is looped element by element, diving
 * deeper and deeper into those parts that belong to the area which was
 * selected by mouse, until the final part in which the mouse action happened
 * is reached.
 *
 * While reading the graphical parts, their mouse command is stored.
 * Commands of smaller parts embedded in bigger, surrounding wholes overwrite
 * any previously stored commands of their wholes. Finally, the mouse command
 * is returned as result of this procedure.
 *
 * @param p0 the command abstraction (Hand over as reference!)
 * @param p1 the command abstraction count (Hand over as reference!)
 * @param p2 the command abstraction size (Hand over as reference!)
 * @param p3 the command model (Hand over as reference!)
 * @param p4 the command model count (Hand over as reference!)
 * @param p5 the command model size (Hand over as reference!)
 * @param p6 the command details (Hand over as reference!)
 * @param p7 the command details count (Hand over as reference!)
 * @param p8 the command details size (Hand over as reference!)
 * @param p9 the whole model
 * @param p10 the whole model count
 * @param p11 the mouse x coordinate within the graphical whole
 * @param p12 the mouse y coordinate within the graphical whole
 * @param p13 the mouse z coordinate within the graphical whole
 * @param p14 the event type
 * @param p15 the mouse button
 * @param p16 the knowledge memory
 * @param p17 the knowledge memory count
 */
void receive_x_window_system_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p13 != NULL_POINTER) {

        int* mz = (int*) p13;

        if (p12 != NULL_POINTER) {

            int* my = (int*) p12;

            if (p11 != NULL_POINTER) {

                int* mx = (int*) p11;

                if (p10 != NULL_POINTER) {

                    int* wmc = (int*) p10;

                    // The graphical part abstraction, model, details.
                    void** a = &NULL_POINTER;
                    void** ac = &NULL_POINTER;
                    void** as = &NULL_POINTER;
                    void** m = &NULL_POINTER;
                    void** mc = &NULL_POINTER;
                    void** ms = &NULL_POINTER;
                    void** d = &NULL_POINTER;
                    void** dc = &NULL_POINTER;
                    void** ds = &NULL_POINTER;

                    // The graphical part position.
                    void** pa = &NULL_POINTER;
                    void** pac = &NULL_POINTER;
                    void** pas = &NULL_POINTER;
                    void** pm = &NULL_POINTER;
                    void** pmc = &NULL_POINTER;
                    void** pms = &NULL_POINTER;
                    void** pd = &NULL_POINTER;
                    void** pdc = &NULL_POINTER;
                    void** pds = &NULL_POINTER;
                    // The graphical part size.
                    void** sa = &NULL_POINTER;
                    void** sac = &NULL_POINTER;
                    void** sas = &NULL_POINTER;
                    void** sm = &NULL_POINTER;
                    void** smc = &NULL_POINTER;
                    void** sms = &NULL_POINTER;
                    void** sd = &NULL_POINTER;
                    void** sdc = &NULL_POINTER;
                    void** sds = &NULL_POINTER;

                    // The graphical part position coordinates.
                    int** pmx = (int**) &NULL_POINTER;
                    int** pmy = (int**) &NULL_POINTER;
                    int** pmz = (int**) &NULL_POINTER;
                    // The graphical part size coordinates.
                    int** smx = (int**) &NULL_POINTER;
                    int** smy = (int**) &NULL_POINTER;
                    int** smz = (int**) &NULL_POINTER;

                    // The new mouse coordinates.
                    int nx = *NUMBER_0_INTEGER;
                    int ny = *NUMBER_0_INTEGER;
                    int nz = *NUMBER_0_INTEGER;

                    // The loop count.
                    int j = 0;
                    // The comparison result.
                    int r = 0;

                    while (1) {

                        if (j >= *wmc) {

                            break;
                        }

                        // Get graphical part at index j.
                        get_compound_element_by_index(p9, p10, (void*) &j,
                            (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms,
                            (void*) &d, (void*) &dc, (void*) &ds);

                        // Get graphical part position from details.
                        get_universal_compound_element_by_name(*d, *dc,
                            (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                            (void*) &pa, (void*) &pac, (void*) &pas,
                            (void*) &pm, (void*) &pmc, (void*) &pms,
                            (void*) &pd, (void*) &pdc, (void*) &pds,
                            p16, p17);
                        // Get graphical part size from details.
                        get_universal_compound_element_by_name(*d, *dc,
                            (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                            (void*) &sa, (void*) &sac, (void*) &sas,
                            (void*) &sm, (void*) &smc, (void*) &sms,
                            (void*) &sd, (void*) &sdc, (void*) &sds,
                            p16, p17);

                        // Determine graphical part position coordinates.
                        get(*pm, (void*) NUMBER_0_INTEGER, (void*) &pmx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get(*pm, (void*) NUMBER_1_INTEGER, (void*) &pmy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get(*pm, (void*) NUMBER_2_INTEGER, (void*) &pmz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        // Determine source part size coordinates.
                        get(*sm, (void*) NUMBER_0_INTEGER, (void*) &smx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get(*sm, (void*) NUMBER_1_INTEGER, (void*) &smy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get(*sm, (void*) NUMBER_2_INTEGER, (void*) &smz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        if ((*mx >= **pmx) && (*my >= **pmy) && (*mz >= **pmz)
                            && (*mx < (**pmx + **smx)) && (*my < (**pmy + **smy)) && (*mz < (**pmz + **smz))) {

                            // The event happened within the graphical part's area.

                            // Receive the graphical part's command.
                            receive_x_window_system_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, *d, *dc, p14, p15, p16, p17);

                            compare_arrays(*a, *ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r != 0) {

                                // The graphical part model is a compound.

                                // Calculate the new mouse coordinates, relative to the part model.
                                nx = *mx - **pmx;
                                ny = *my - **pmy;
                                nz = *mz - **pmz;

                                // Recursively call this procedure for compound part model.
                                receive_x_window_system_part(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                                    *m, *mc, &nx, &ny, &nz, p14, p15, p16, p17);
                            }
                        }

                        // Reset graphical part.
                        a = &NULL_POINTER;
                        ac = &NULL_POINTER;
                        as = &NULL_POINTER;
                        m = &NULL_POINTER;
                        mc = &NULL_POINTER;
                        ms = &NULL_POINTER;
                        d = &NULL_POINTER;
                        dc = &NULL_POINTER;
                        ds = &NULL_POINTER;

                        // Reset graphical part position.
                        pa = &NULL_POINTER;
                        pac = &NULL_POINTER;
                        pas = &NULL_POINTER;
                        pm = &NULL_POINTER;
                        pmc = &NULL_POINTER;
                        pms = &NULL_POINTER;
                        pd = &NULL_POINTER;
                        pdc = &NULL_POINTER;
                        pds = &NULL_POINTER;
                        // Reset graphical part size.
                        sa = &NULL_POINTER;
                        sac = &NULL_POINTER;
                        sas = &NULL_POINTER;
                        sm = &NULL_POINTER;
                        smc = &NULL_POINTER;
                        sms = &NULL_POINTER;
                        sd = &NULL_POINTER;
                        sdc = &NULL_POINTER;
                        sds = &NULL_POINTER;

                        // Reset graphical part position coordinates.
                        pmx = (int**) &NULL_POINTER;
                        pmy = (int**) &NULL_POINTER;
                        pmz = (int**) &NULL_POINTER;
                        // Reset graphical part size coordinates.
                        smx = (int**) &NULL_POINTER;
                        smy = (int**) &NULL_POINTER;
                        smz = (int**) &NULL_POINTER;

                        // Reset new mouse coordinates.
                        nx = *NUMBER_0_INTEGER;
                        ny = *NUMBER_0_INTEGER;
                        nz = *NUMBER_0_INTEGER;

                        // Reset comparison result.
                        r = 0;

                        // Increment loop count.
                        j++;
                    }

                } else {

                    log_message_debug("Could not receive x window system part. The whole model count is null.");
                }

            } else {

                log_message_debug("Could not receive x window system part. The mouse x coordinate is null.");
            }

        } else {

            log_message_debug("Could not receive x window system part. The mouse y coordinate is null.");
        }

    } else {

        log_message_debug("Could not receive x window system part. The mouse z coordinate is null.");
    }
}

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
 * @param d the display, which is a subsumption of xserver, screens, hardware
 * @param xmt the x window system mutex
 */
int receive_x_window_system_check_events(struct _XDisplay* d, pthread_mutex_t* xmt) {

    // The number of events.
    int n = 0;

    pthread_mutex_lock(xmt);

    n = XEventsQueued(d, QueuedAfterReading);

    pthread_mutex_unlock(xmt);

    return n;
}

/**
 * Receives x window system messages (events) in an own thread.
 *
 * @param p0 the internal memory
 */
void receive_x_window_system_thread(void* p0) {

    // The knowledge memory.
    void** k = &NULL_POINTER;
    void** kc = &NULL_POINTER;
    void** ks = &NULL_POINTER;
    // The signal memory.
    void** s = &NULL_POINTER;
    void** sc = &NULL_POINTER;
    void** ss = &NULL_POINTER;
    // The signal memory mutex.
    pthread_mutex_t** smt = (pthread_mutex_t**) &NULL_POINTER;
    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) &NULL_POINTER;
    // The signal memory interrupt request flag.
    sig_atomic_t** sirq = (sig_atomic_t**) &NULL_POINTER;
    // The user interface root.
    void** r = &NULL_POINTER;
    void** rc = &NULL_POINTER;
    void** rs = &NULL_POINTER;
    // The user interface commands.
    void** c = &NULL_POINTER;
    void** cc = &NULL_POINTER;
    void** cs = &NULL_POINTER;
    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = (struct _XDisplay**) &NULL_POINTER;
    // The window.
    int** w = (int**) &NULL_POINTER;

    // Get knowledge memory internal.
    get(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internal.
    get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system mutex.
    get(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &xmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get(p0, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &sirq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get user interface root internal.
    get(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL, (void*) &r, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL, (void*) &rc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL, (void*) &rs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get user interface commands internal.
    get(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system internals.
    get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // The command abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The command model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The command details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    //?? TODO: The temporary graphical part abstraction, model, details.
    void** tmpa = &NULL_POINTER;
    void** tmpac = &NULL_POINTER;
    void** tmpas = &NULL_POINTER;
    void** tmpm = &NULL_POINTER;
    void** tmpmc = &NULL_POINTER;
    void** tmpms = &NULL_POINTER;
    void** tmpd = &NULL_POINTER;
    void** tmpdc = &NULL_POINTER;
    void** tmpds = &NULL_POINTER;

    // The event.
    XEvent e;
    // The event type.
    int t = -1;
    // The signal id.
    int* id = NULL_POINTER;

    while (1) {

        // A break condition does not exist here because the loop
        // is blocking neverendingly while waiting for signals.
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service procedure
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

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
        //   buffer and might thus cause this receive-thread to conflict
        //   with the send_x_window_system procedure of the main thread

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
        // while receive_x_window_system runs in its own thread!
        while (!receive_x_window_system_check_events(*d, *xmt)) {

            sleep(1);
        }

        pthread_mutex_lock(*xmt);

        // Get next event.
        // The XNextEvent function copies the first event from the event queue
        // into the specified XEvent structure and then removes it from the queue.
        // If the event queue is empty, XNextEvent flushes the output buffer
        // and blocks until an event is received.
        XNextEvent(*d, &e);

        pthread_mutex_unlock(*xmt);

        // Assign event type.
        t = e.type;

        if (t == Expose) {

            // Expose events are received when a window needs to be repainted
            // when being displayed after having been covered before.

            // Consider only the last in a row of multiple expose events.
            if (e.xexpose.count == 0) {

                // Get actual command belonging to the x window system expose event.
                get_universal_compound_element_by_name(*c, *cc,
                    (void*) GUI_EXPOSE_COMMAND_NAME, (void*) GUI_EXPOSE_COMMAND_NAME_COUNT,
                    (void*) &ca, (void*) &cac, (void*) &cas,
                    (void*) &cm, (void*) &cmc, (void*) &cms,
                    (void*) &cd, (void*) &cdc, (void*) &cds,
                    *k, *kc);

    fprintf(stderr, "TEST expose receive t: %i\n", t);

                // Lock signal memory mutex.
                pthread_mutex_lock(*smt);

                // Allocate signal id.
                allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *id = 0;
                get_new_signal_id(*s, *sc, (void*) id);

                // Add signal to signal memory.
                set_signal(*s, *sc, *ss, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_PRIORITY, (void*) id);

                // Set interrupt request flag, in order to notify the signal checker
                // that a new signal has been placed in the signal memory.
                **sirq = *NUMBER_1_INTEGER;

                // Unlock signal memory mutex.
                pthread_mutex_unlock(*smt);
            }

        } else if (t == MappingNotify) {

            // Mapping change events are sent when the keyboard mapping changes.

//??            XRefreshKeyboardMapping(&e);

        } else if ((t == KeyPress) || (t == KeyRelease)) {

            // Key press events relate to keyboard keys.

/*??
            Example:
            // Translate the key code to a key symbol.
            KeySym key_symbol = XKeycodeToKeysym(display, an_event.xkey.keycode, 0);
            switch (key_symbol) {
                case XK_1:
                case XK_KP_1:
                    // '1' key was pressed, either the normal '1',
                    // or the '1' on the keypad. draw the current pixel.
                    XDrawPoint(display, the_win, gc_draw, x, y);
                    break;
                case XK_Delete:
                    // DEL key was pressed, erase the current pixel.
                    XDrawPoint(display, the_win, gc_erase, x, y);
                    break;
                default:
                    // Anything else - check if it is a letter key
                    if (key_symbol >= XK_A && key_symbol <= XK_Z) {
                        int ascii_key = key_symbol - XK_A + 'A';
                        printf("Key pressed - '%c'\n", ascii_key);
                    }
                    if (key_symbol >= XK_a && key_symbol <= XK_z) {
                        int ascii_key = key_symbol - XK_a + 'a';
                        printf("Key pressed - '%c'\n", ascii_key);
                    }
                    break;
            }
*/

/*??
            KeySym k;
            char text[10];
            char str_test[1000];
            char str_zugriff[1000];
            char str_menubar[100];
            //??unsigned long //??double menu_foreground;
            // The temporary variables.
        //??    int k;
            int menu_eintrage_ende;
            int window;
            int i = 0, count_menu, count_item, indent_x, indent_y, indent_menu_item_x;
*/

/*??
            i = XLookupString(&e, text, 10, &k, 0);

            //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
            //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte

            if (i == 1 && text[0] == 'a') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'b') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'c') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;
            }

            if (i == 1 && text[0] == 'x') {

                XClearArea (d, w, 0, 0, 0, 0, True);

                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'q') {

                f = 1;
            }
*/

            //?? To erase graphical areas (such as an open menu), use:
            //?? XClearArea (d, w, 0, 0, 0, 0, True);

            //?? What is this useful for?
            //?? XDrawImageString(e.xexpose.display, e.xexpose.window, gc_menu_font, 100, 100, event.xbutton.x, strlen(event.xbutton.x));

        } else if ((t == ButtonPress) || (t == ButtonRelease)) {

    fprintf(stderr, "TEST button press receive t: %i\n", t);

            //?? TODO: This is a temporary solution!
            //?? There is no meta information (such as position or size) known
            //?? about the gui root node. Therefore, the actual window as its
            //?? only part element is determined here and handed over to
            //?? further procedures.
            get_compound_element_by_index(*r, *rc, (void*) NUMBER_0_INTEGER,
                (void*) &tmpa, (void*) &tmpac, (void*) &tmpas,
                (void*) &tmpm, (void*) &tmpmc, (void*) &tmpms,
                (void*) &tmpd, (void*) &tmpdc, (void*) &tmpds);

            // Determine command, depending on mouse button and event type.
            // CAUTION! Hand over command abstraction, model, details as reference!
            receive_x_window_system_part(&ca, &cac, &cas, &cm, &cmc, &cms, &cd, &cdc, &cds,
                *tmpm, *tmpmc, &(e.xbutton.x), &(e.xbutton.y), (void*) NUMBER_0_INTEGER,
                &t, &(e.xbutton.button), *k, *kc);

            // Lock signal memory mutex.
            pthread_mutex_lock(*smt);

            // Allocate signal id.
            allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *id = 0;
            get_new_signal_id(*s, *sc, (void*) id);

            // Add signal to signal memory.
            set_signal(*s, *sc, *ss, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_PRIORITY, (void*) id);

            // Set interrupt request flag, in order to notify the signal checker
            // that a new signal has been placed in the signal memory.
            **sirq = *NUMBER_1_INTEGER;

            // Unlock signal memory mutex.
            pthread_mutex_unlock(*smt);

        } else if (t == MotionNotify) {

/*??
            //?? The an_event.xmotion.state variable (unsigned int state) contains
            //?? a mask of the buttons (or keys) held down during this event - if any.
            //?? This field is a bitwise OR of any of the following:
            Button1Mask
            Button2Mask
            Button3Mask
            Button4Mask
            Button5Mask
            ShiftMask
            LockMask
            ControlMask
            Mod1Mask
            Mod2Mask
            Mod3Mask
            Mod4Mask
            Mod5Mask

            //?? Example:
            //?? If the 1st mouse button was held during this event,
            //?? draw a pixel at the mouse pointer location.
            if (an_event.xmotion.state & Button1Mask) {
                XDrawPoint(display, the_win, gc_draw, x, y);
            }
*/

        } else if ((t == EnterNotify) || (LeaveNotify)) {

            //?? an_event.xcrossing
        }

        // Reset command abstraction.
        ca = &NULL_POINTER;
        cac = &NULL_POINTER;
        cas = &NULL_POINTER;
        // Reset command model.
        cm = &NULL_POINTER;
        cmc = &NULL_POINTER;
        cms = &NULL_POINTER;
        // Reset command details.
        cd = &NULL_POINTER;
        cdc = &NULL_POINTER;
        cds = &NULL_POINTER;

        //?? Reset temporary graphical part abstraction, model, details.
        tmpa = &NULL_POINTER;
        tmpac = &NULL_POINTER;
        tmpas = &NULL_POINTER;
        tmpm = &NULL_POINTER;
        tmpmc = &NULL_POINTER;
        tmpms = &NULL_POINTER;
        tmpd = &NULL_POINTER;
        tmpdc = &NULL_POINTER;
        tmpds = &NULL_POINTER;

        // Reset event type.
        t = -1;
        // Reset signal id.
        id = NULL_POINTER;
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
    //
    // However, since this procedure runs an endless loop waiting for input,
    // and is NEVER left (does not have a "break" condition),
    // the loop and this thread can only be exited by an external signal
    // which is sent in the corresponding interrupt service procedure,
    // situated in the applicator/interrupt/ directory,
    // and processed in the interrupt_service_system_signal_handler procedure:
    // controller/manager/system_signal_handler_manager.c
}

/**
 * Receives x window system messages.
 *
 * @param p0 the internal memory
 * @param p1 the temporary user interface root internal
 * @param p2 the temporary user interface root count internal
 * @param p3 the temporary user interface root size internal
 * @param p4 the temporary user interface commands internal
 * @param p5 the temporary user interface commands count internal
 * @param p6 the temporary user interface commands size internal
 */
void receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_debug("Receive x window system message.");

    // Adding the following parameters to the internal memory is necessary,
    // because only one parameter (the internal memory p0) can be forwarded
    // to the thread procedure further below. Thus, p0 must contain any others.

    // Set temporary user interface root internal.
    set(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL, (void*) &p1, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL, (void*) &p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL, (void*) &p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Set temporary user interface commands internal.
    set(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL, (void*) &p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &p5, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    set(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &p6, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Create thread.
    //
    // CAUTION! Do NOT allocate any resources within the thread procedure!
    // The reason is that this main process thread gets forked when executing
    // external programs. A "fork" duplicates ALL resources of the parent process,
    // including ALL resources of any threads running within the parent process.
    // However, since the created child process does not have those threads running,
    // their duplicated resources will never be deallocated, which eats up memory.
    // See source code file: applicator/run/run_execute.c
    //
    // Any dynamically allocated resources needed within the thread have to be:
    // - allocated at service startup
    // - added to the internal memory
    // - handed over to the thread procedure HERE
    // - deallocated at service shutdown
    pthread_create(X_WINDOW_SYSTEM_THREAD, NULL_POINTER, (void*) &receive_x_window_system_thread, p0);
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_X_WINDOW_SYSTEM_SOURCE */
#endif
