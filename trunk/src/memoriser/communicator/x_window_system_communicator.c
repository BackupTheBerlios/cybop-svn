/*
 * $RCSfile: x_window_system_communicator.c,v $
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
 * @version $Revision: 1.16 $ $Date: 2008-02-15 15:47:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE
#define X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE

#include <X11/Xlib.h>
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"

/**
 * Determine the graphical part's mouse command.
 *
 * The activated button is identified first.
 * Afterwards, the event type is identified.
 * Finally, the corresponding mouse command is returned as result.
 *
 * @param p0 the command name (Hand over as reference!)
 * @param p1 the command name count (Hand over as reference!)
 * @param p2 the command name size (Hand over as reference!)
 * @param p3 the command abstraction (Hand over as reference!)
 * @param p4 the command abstraction count (Hand over as reference!)
 * @param p5 the command abstraction size (Hand over as reference!)
 * @param p6 the command model (Hand over as reference!)
 * @param p7 the command model count (Hand over as reference!)
 * @param p8 the command model size (Hand over as reference!)
 * @param p9 the command details (Hand over as reference!)
 * @param p10 the command details count (Hand over as reference!)
 * @param p11 the command details size (Hand over as reference!)
 * @param p12 the whole details
 * @param p13 the whole details count
 * @param p14 the event type
 * @param p15 the mouse button
 * @param p16 the knowledge memory
 * @param p17 the knowledge memory count
 */
void sense_x_window_system_mouse_command(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p15 != *NULL_POINTER) {

        int* b = (int*) p15;

        if (p14 != *NULL_POINTER) {

            int* t = (int*) p14;

            if (*b == Button1) {

                if (*t == ButtonPress) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(p12, p13,
                        (void*) GUI_LEFT_PRESS_COMMAND_NAME, (void*) GUI_LEFT_PRESS_COMMAND_NAME_COUNT,
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p16, p17);

                } else if (*t == ButtonRelease) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(p12, p13,
                        (void*) GUI_LEFT_RELEASE_COMMAND_NAME, (void*) GUI_LEFT_RELEASE_COMMAND_NAME_COUNT,
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p16, p17);
                }

            } else if (*b == Button2) {
            } else if (*b == Button3) {
            } else if (*b == Button4) {
            } else if (*b == Button5) {
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system mouse command. The event type is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system mouse command. The mouse button is null.");
    }
}

/**
 * Determine the graphical part's command.
 *
 * The event type gets identified, in order to call the corresponding procedure.
 * Mouse press or -release events have to be handled differently than drag'n'drop.
 *
 * @param p0 the command name (Hand over as reference!)
 * @param p1 the command name count (Hand over as reference!)
 * @param p2 the command name size (Hand over as reference!)
 * @param p3 the command abstraction (Hand over as reference!)
 * @param p4 the command abstraction count (Hand over as reference!)
 * @param p5 the command abstraction size (Hand over as reference!)
 * @param p6 the command model (Hand over as reference!)
 * @param p7 the command model count (Hand over as reference!)
 * @param p8 the command model size (Hand over as reference!)
 * @param p9 the command details (Hand over as reference!)
 * @param p10 the command details count (Hand over as reference!)
 * @param p11 the command details size (Hand over as reference!)
 * @param p12 the whole details
 * @param p13 the whole details count
 * @param p14 the event type
 * @param p15 the mouse button
 * @param p16 the knowledge memory
 * @param p17 the knowledge memory count
 */
void sense_x_window_system_command(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p14 != *NULL_POINTER) {

        int* t = (int*) p14;

        if ((*t == ButtonPress) || (*t == ButtonRelease)) {

            sense_x_window_system_mouse_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

/*??
        } else if (*t == MouseMove) {

            // Drag'n'Drop needs to be handled differently than simple mouse clicks.
*/
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system command. The event type is null.");
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
 * @param p0 the command name (Hand over as reference!)
 * @param p1 the command name count (Hand over as reference!)
 * @param p2 the command name size (Hand over as reference!)
 * @param p3 the command abstraction (Hand over as reference!)
 * @param p4 the command abstraction count (Hand over as reference!)
 * @param p5 the command abstraction size (Hand over as reference!)
 * @param p6 the command model (Hand over as reference!)
 * @param p7 the command model count (Hand over as reference!)
 * @param p8 the command model size (Hand over as reference!)
 * @param p9 the command details (Hand over as reference!)
 * @param p10 the command details count (Hand over as reference!)
 * @param p11 the command details size (Hand over as reference!)
 * @param p12 the whole model
 * @param p13 the whole model count
 * @param p14 the mouse x coordinate within the graphical whole
 * @param p15 the mouse y coordinate within the graphical whole
 * @param p16 the mouse z coordinate within the graphical whole
 * @param p17 the event type
 * @param p18 the mouse button
 * @param p19 the knowledge memory
 * @param p20 the knowledge memory count
 */
void sense_x_window_system_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20) {

    if (p16 != *NULL_POINTER) {

        int* mz = (int*) p16;

        if (p15 != *NULL_POINTER) {

            int* my = (int*) p15;

            if (p14 != *NULL_POINTER) {

                int* mx = (int*) p14;

                if (p13 != *NULL_POINTER) {

                    int* wmc = (int*) p13;

                    // The graphical part name, abstraction, model, details.
                    void** n = NULL_POINTER;
                    void** nc = NULL_POINTER;
                    void** ns = NULL_POINTER;
                    void** a = NULL_POINTER;
                    void** ac = NULL_POINTER;
                    void** as = NULL_POINTER;
                    void** m = NULL_POINTER;
                    void** mc = NULL_POINTER;
                    void** ms = NULL_POINTER;
                    void** d = NULL_POINTER;
                    void** dc = NULL_POINTER;
                    void** ds = NULL_POINTER;
                    // The graphical part position name, abstraction, model, details.
                    void** pn = NULL_POINTER;
                    void** pnc = NULL_POINTER;
                    void** pns = NULL_POINTER;
                    void** pa = NULL_POINTER;
                    void** pac = NULL_POINTER;
                    void** pas = NULL_POINTER;
                    void** pm = NULL_POINTER;
                    void** pmc = NULL_POINTER;
                    void** pms = NULL_POINTER;
                    void** pd = NULL_POINTER;
                    void** pdc = NULL_POINTER;
                    void** pds = NULL_POINTER;
                    // The graphical part size name, abstraction, model, details.
                    void** sn = NULL_POINTER;
                    void** snc = NULL_POINTER;
                    void** sns = NULL_POINTER;
                    void** sa = NULL_POINTER;
                    void** sac = NULL_POINTER;
                    void** sas = NULL_POINTER;
                    void** sm = NULL_POINTER;
                    void** smc = NULL_POINTER;
                    void** sms = NULL_POINTER;
                    void** sd = NULL_POINTER;
                    void** sdc = NULL_POINTER;
                    void** sds = NULL_POINTER;

                    // The graphical part position coordinates.
                    int** pmx = (int**) NULL_POINTER;
                    int** pmy = (int**) NULL_POINTER;
                    int** pmz = (int**) NULL_POINTER;
                    // The graphical part size coordinates.
                    int** smx = (int**) NULL_POINTER;
                    int** smy = (int**) NULL_POINTER;
                    int** smz = (int**) NULL_POINTER;

                    // The new mouse coordinates.
                    int nx = *NUMBER_0_INTEGER;
                    int ny = *NUMBER_0_INTEGER;
                    int nz = *NUMBER_0_INTEGER;

                    // The loop count.
                    int j = *NUMBER_0_INTEGER;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER;

                    while (*NUMBER_1_INTEGER) {

                        if (j >= *wmc) {

                            break;
                        }

                        // Get graphical part at index j.
                        get_compound_element_by_index(p12, p13, (void*) &j,
                            (void*) &n, (void*) &nc, (void*) &ns,
                            (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms,
                            (void*) &d, (void*) &dc, (void*) &ds);

                        // Get graphical part position from details.
                        get_universal_compound_element_by_name(*d, *dc,
                            (void*) UI_POSITION_NAME, (void*) UI_POSITION_NAME_COUNT,
                            (void*) &pn, (void*) &pnc, (void*) &pns,
                            (void*) &pa, (void*) &pac, (void*) &pas,
                            (void*) &pm, (void*) &pmc, (void*) &pms,
                            (void*) &pd, (void*) &pdc, (void*) &pds,
                            p19, p20);
                        // Get graphical part size from details.
                        get_universal_compound_element_by_name(*d, *dc,
                            (void*) UI_SIZE_NAME, (void*) UI_SIZE_NAME_COUNT,
                            (void*) &sn, (void*) &snc, (void*) &sns,
                            (void*) &sa, (void*) &sac, (void*) &sas,
                            (void*) &sm, (void*) &smc, (void*) &sms,
                            (void*) &sd, (void*) &sdc, (void*) &sds,
                            p19, p20);

                        // Determine graphical part position coordinates.
                        get_element(*pm, (void*) NUMBER_0_INTEGER, (void*) &pmx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get_element(*pm, (void*) NUMBER_1_INTEGER, (void*) &pmy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get_element(*pm, (void*) NUMBER_2_INTEGER, (void*) &pmz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        // Determine source part size coordinates.
                        get_element(*sm, (void*) NUMBER_0_INTEGER, (void*) &smx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get_element(*sm, (void*) NUMBER_1_INTEGER, (void*) &smy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        get_element(*sm, (void*) NUMBER_2_INTEGER, (void*) &smz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        if ((*mx >= **pmx) && (*my >= **pmy) && (*mz >= **pmz)
                            && (*mx < (**pmx + **smx)) && (*my < (**pmy + **smy)) && (*mz < (**pmz + **smz))) {

                            // The event happened within the graphical part's area.

                            // Sense the graphical part's command.
                            sense_x_window_system_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, *d, *dc, p17, p18, p19, p20);

                            compare_arrays(*a, *ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                            if (r != *NUMBER_0_INTEGER) {

                                // The graphical part model is a compound.

                                // Calculate the new mouse coordinates, relative to the part model.
                                nx = *mx - **pmx;
                                ny = *my - **pmy;
                                nz = *mz - **pmz;

                                // Recursively call this procedure for compound part model.
                                sense_x_window_system_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, *m, *mc, &nx, &ny, &nz, p17, p18, p19, p20);
                            }
                        }

                        // Reset graphical part name, abstraction, model, details.
                        n = NULL_POINTER;
                        nc = NULL_POINTER;
                        ns = NULL_POINTER;
                        a = NULL_POINTER;
                        ac = NULL_POINTER;
                        as = NULL_POINTER;
                        m = NULL_POINTER;
                        mc = NULL_POINTER;
                        ms = NULL_POINTER;
                        d = NULL_POINTER;
                        dc = NULL_POINTER;
                        ds = NULL_POINTER;
                        // Reset graphical part position name, abstraction, model, details.
                        pn = NULL_POINTER;
                        pnc = NULL_POINTER;
                        pns = NULL_POINTER;
                        pa = NULL_POINTER;
                        pac = NULL_POINTER;
                        pas = NULL_POINTER;
                        pm = NULL_POINTER;
                        pmc = NULL_POINTER;
                        pms = NULL_POINTER;
                        pd = NULL_POINTER;
                        pdc = NULL_POINTER;
                        pds = NULL_POINTER;
                        // Reset graphical part size name, abstraction, model, details.
                        sn = NULL_POINTER;
                        snc = NULL_POINTER;
                        sns = NULL_POINTER;
                        sa = NULL_POINTER;
                        sac = NULL_POINTER;
                        sas = NULL_POINTER;
                        sm = NULL_POINTER;
                        smc = NULL_POINTER;
                        sms = NULL_POINTER;
                        sd = NULL_POINTER;
                        sdc = NULL_POINTER;
                        sds = NULL_POINTER;

                        // Reset graphical part position coordinates.
                        pmx = (int**) NULL_POINTER;
                        pmy = (int**) NULL_POINTER;
                        pmz = (int**) NULL_POINTER;
                        // Reset graphical part size coordinates.
                        smx = (int**) NULL_POINTER;
                        smy = (int**) NULL_POINTER;
                        smz = (int**) NULL_POINTER;

                        // Reset new mouse coordinates.
                        nx = *NUMBER_0_INTEGER;
                        ny = *NUMBER_0_INTEGER;
                        nz = *NUMBER_0_INTEGER;

                        // Reset comparison result.
                        r = *NUMBER_0_INTEGER;

                        // Increment loop count.
                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system part. The whole model count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system part. The mouse x coordinate is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system part. The mouse y coordinate is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not sense x window system part. The mouse z coordinate is null.");
    }
}

/**
 * Reads the x window system display into a window.
 *
 * @param p0 the destination window (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source display
 * @param p4 the source count
 */
void read_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The knowledge memory.
    void** k = NULL_POINTER;
    void** kc = NULL_POINTER;
    void** ks = NULL_POINTER;
    // The signal memory.
    void** s = NULL_POINTER;
    void** sc = NULL_POINTER;
    void** ss = NULL_POINTER;
    // The signal memory mutex.
    pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER;
    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) NULL_POINTER;
    // The signal memory interrupt request flag.
    sig_atomic_t** sirq = (sig_atomic_t**) NULL_POINTER;
    // The user interface root.
    void** r = NULL_POINTER;
    void** rc = NULL_POINTER;
    void** rs = NULL_POINTER;
    // The user interface commands.
    void** c = NULL_POINTER;
    void** cc = NULL_POINTER;
    void** cs = NULL_POINTER;
    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = (struct _XDisplay**) NULL_POINTER;
    // The window.
    int** w = (int**) NULL_POINTER;

    // Get knowledge memory internal.
    get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system mutex.
    get_element(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &xmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL, (void*) &sirq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get user interface root internal.
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL, (void*) &r, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL, (void*) &rc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL, (void*) &rs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get user interface commands internal.
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system internals.
    get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // The command name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;

    //?? TODO: The temporary graphical part name, abstraction, model, details.
    void** tmpn = NULL_POINTER;
    void** tmpnc = NULL_POINTER;
    void** tmpns = NULL_POINTER;
    void** tmpa = NULL_POINTER;
    void** tmpac = NULL_POINTER;
    void** tmpas = NULL_POINTER;
    void** tmpm = NULL_POINTER;
    void** tmpmc = NULL_POINTER;
    void** tmpms = NULL_POINTER;
    void** tmpd = NULL_POINTER;
    void** tmpdc = NULL_POINTER;
    void** tmpds = NULL_POINTER;

    // The event.
    XEvent e;
    // The event type.
    int t = *NUMBER_MINUS_1_INTEGER;
    // The signal identification.
    void** id = NULL_POINTER;

    pthread_mutex_lock(*xmt);

    // Get next event.
    // The XNextEvent function copies the first event from the event queue
    // into the specified XEvent structure and then removes it from the queue.
    // If the event queue is empty, XNextEvent flushes the output buffer
    // and blocks until an event is sensed.
    XNextEvent(*d, &e);

    pthread_mutex_unlock(*xmt);

    // Assign event type.
    t = e.type;

    if (t == Expose) {

        // Expose events are sensed when a window needs to be repainted
        // when being displayed after having been covered before.

        // Consider only the last in a row of multiple expose events.
        if (e.xexpose.count == *NUMBER_0_INTEGER) {

            // Get actual command belonging to the x window system expose event.
            get_universal_compound_element_by_name(*c, *cc,
                (void*) GUI_EXPOSE_COMMAND_NAME, (void*) GUI_EXPOSE_COMMAND_NAME_COUNT,
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                *k, *kc);

    fprintf(stderr, "TEST expose sense t: %i\n", t);

            // Lock signal memory mutex.
            pthread_mutex_lock(*smt);

            // Get new signal identification by incrementing the current maximum signal's one.
            get_new_signal_identification(*s, *sc, (void*) &id);

            // Add signal to signal memory.
            set_signal(*s, *sc, *ss, ca, cac, cm, cmc, cd, cdc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) id);

            // Set interrupt request flag, in order to notify the signal checker
            // that a new signal has been placed in the signal memory.
            **sirq = *NUMBER_1_INTEGER;

            // Unlock signal memory mutex.
            pthread_mutex_unlock(*smt);
        }

    } else if (t == MappingNotify) {

        // Mapping change events are sent when the keyboard mapping changes.

//??        XRefreshKeyboardMapping(&e);

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

    fprintf(stderr, "TEST button press sense t: %i\n", t);

        //?? TODO: This is a temporary solution!
        //?? There is no meta information (such as position or size) known
        //?? about the gui root node. Therefore, the actual window as its
        //?? only part element is determined here and handed over to
        //?? further procedures.
        get_compound_element_by_index(*r, *rc, (void*) NUMBER_0_INTEGER,
            (void*) &tmpn, (void*) &tmpnc, (void*) &tmpns,
            (void*) &tmpa, (void*) &tmpac, (void*) &tmpas,
            (void*) &tmpm, (void*) &tmpmc, (void*) &tmpms,
            (void*) &tmpd, (void*) &tmpdc, (void*) &tmpds);

        // Determine command, depending on mouse button and event type.
        // CAUTION! Hand over command abstraction, model, details as reference!
        sense_x_window_system_part(&cn, &cnc, &cns, &ca, &cac, &cas, &cm, &cmc, &cms, &cd, &cdc, &cds,
            *tmpm, *tmpmc, &(e.xbutton.x), &(e.xbutton.y), (void*) NUMBER_0_INTEGER,
            &t, &(e.xbutton.button), *k, *kc);

        // Lock signal memory mutex.
        pthread_mutex_lock(*smt);

        // Get new signal identification by incrementing the current maximum signal's one.
        get_new_signal_identification(*s, *sc, (void*) &id);

        // Add signal to signal memory.
        set_signal(*s, *sc, *ss, ca, cac, cm, cmc, cd, cdc, (void*) &NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) id);

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
}

/**
 * Writes the window onto the x window system display.
 *
 * @param p0 the destination display (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory
 * @param p4 the source count
 */
void write_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER) {

        struct _XDisplay** d = (struct _XDisplay**) p0;

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Write to x window system display.");

        // The window.
        int** w = (int**) NULL_POINTER;

        // Get x window system internals.
        get_element(p3, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Request input events (signals) to be put into event queue.
        XSelectInput(*d, **w, ExposureMask
            | KeyPressMask | KeyReleaseMask
            | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ButtonMotionMask
            | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask
            | EnterWindowMask | LeaveWindowMask);

        // Show the window (make it visible).
        XMapWindow(*d, **w);

        // Flush all pending requests to the X server.
        XFlush(*d);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not write to x window system display. The destination display is null.");
    }
}

/* X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE */
#endif
