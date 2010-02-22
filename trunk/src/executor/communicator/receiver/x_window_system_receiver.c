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
 * @version $RCSfile: x_window_system_communicator.c,v $ $Revision: 1.29 $ $Date: 2009-01-31 16:31:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define X_WINDOW_SYSTEM_RECEIVER_SOURCE

#include <X11/Xlib.h>
#include <pthread.h>
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../logger/logger.c"
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

    if (p15 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p15;

        if (p14 != *NULL_POINTER_MEMORY_MODEL) {

            int* t = (int*) p14;

            if (*b == Button1) {

                if (*t == ButtonPress) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(p12, p13,
                        (void*) LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p16, p17);

                } else if (*t == ButtonRelease) {

                    // Get actual command belonging to the button and event.
                    get_universal_compound_element_by_name(p12, p13,
                        (void*) LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p16, p17);
                }

            } else if (*b == Button2) {
            } else if (*b == Button3) {
            } else if (*b == Button4) {
            } else if (*b == Button5) {
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system mouse command. The event type is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system mouse command. The mouse button is null.");
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

    if (p14 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p14;

        if ((*t == ButtonPress) || (*t == ButtonRelease)) {

            sense_x_window_system_mouse_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

/*??
        } else if (*t == MouseMove) {

            // Drag'n'Drop needs to be handled differently than simple mouse clicks.
*/
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system command. The event type is null.");
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

    if (p16 != *NULL_POINTER_MEMORY_MODEL) {

        int* mz = (int*) p16;

        if (p15 != *NULL_POINTER_MEMORY_MODEL) {

            int* my = (int*) p15;

            if (p14 != *NULL_POINTER_MEMORY_MODEL) {

                int* mx = (int*) p14;

                if (p13 != *NULL_POINTER_MEMORY_MODEL) {

                    int* wmc = (int*) p13;

                    // The graphical part name, abstraction, model, details.
                    void** n = NULL_POINTER_MEMORY_MODEL;
                    void** nc = NULL_POINTER_MEMORY_MODEL;
                    void** ns = NULL_POINTER_MEMORY_MODEL;
                    void** a = NULL_POINTER_MEMORY_MODEL;
                    void** ac = NULL_POINTER_MEMORY_MODEL;
                    void** as = NULL_POINTER_MEMORY_MODEL;
                    void** m = NULL_POINTER_MEMORY_MODEL;
                    void** mc = NULL_POINTER_MEMORY_MODEL;
                    void** ms = NULL_POINTER_MEMORY_MODEL;
                    void** d = NULL_POINTER_MEMORY_MODEL;
                    void** dc = NULL_POINTER_MEMORY_MODEL;
                    void** ds = NULL_POINTER_MEMORY_MODEL;
                    // The graphical part position name, abstraction, model, details.
                    void** pn = NULL_POINTER_MEMORY_MODEL;
                    void** pnc = NULL_POINTER_MEMORY_MODEL;
                    void** pns = NULL_POINTER_MEMORY_MODEL;
                    void** pa = NULL_POINTER_MEMORY_MODEL;
                    void** pac = NULL_POINTER_MEMORY_MODEL;
                    void** pas = NULL_POINTER_MEMORY_MODEL;
                    void** pm = NULL_POINTER_MEMORY_MODEL;
                    void** pmc = NULL_POINTER_MEMORY_MODEL;
                    void** pms = NULL_POINTER_MEMORY_MODEL;
                    void** pd = NULL_POINTER_MEMORY_MODEL;
                    void** pdc = NULL_POINTER_MEMORY_MODEL;
                    void** pds = NULL_POINTER_MEMORY_MODEL;
                    // The graphical part size name, abstraction, model, details.
                    void** sn = NULL_POINTER_MEMORY_MODEL;
                    void** snc = NULL_POINTER_MEMORY_MODEL;
                    void** sns = NULL_POINTER_MEMORY_MODEL;
                    void** sa = NULL_POINTER_MEMORY_MODEL;
                    void** sac = NULL_POINTER_MEMORY_MODEL;
                    void** sas = NULL_POINTER_MEMORY_MODEL;
                    void** sm = NULL_POINTER_MEMORY_MODEL;
                    void** smc = NULL_POINTER_MEMORY_MODEL;
                    void** sms = NULL_POINTER_MEMORY_MODEL;
                    void** sd = NULL_POINTER_MEMORY_MODEL;
                    void** sdc = NULL_POINTER_MEMORY_MODEL;
                    void** sds = NULL_POINTER_MEMORY_MODEL;

                    // The graphical part position coordinates.
                    int** pmx = (int**) NULL_POINTER_MEMORY_MODEL;
                    int** pmy = (int**) NULL_POINTER_MEMORY_MODEL;
                    int** pmz = (int**) NULL_POINTER_MEMORY_MODEL;
                    // The graphical part size coordinates.
                    int** smx = (int**) NULL_POINTER_MEMORY_MODEL;
                    int** smy = (int**) NULL_POINTER_MEMORY_MODEL;
                    int** smz = (int**) NULL_POINTER_MEMORY_MODEL;

                    // The new mouse coordinates.
                    int nx = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    int ny = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    int nz = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // The loop count.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

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
                            (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            (void*) &pn, (void*) &pnc, (void*) &pns,
                            (void*) &pa, (void*) &pac, (void*) &pas,
                            (void*) &pm, (void*) &pmc, (void*) &pms,
                            (void*) &pd, (void*) &pdc, (void*) &pds,
                            p19, p20);
                        // Get graphical part size from details.
                        get_universal_compound_element_by_name(*d, *dc,
                            (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            (void*) &sn, (void*) &snc, (void*) &sns,
                            (void*) &sa, (void*) &sac, (void*) &sas,
                            (void*) &sm, (void*) &smc, (void*) &sms,
                            (void*) &sd, (void*) &sdc, (void*) &sds,
                            p19, p20);

                        // Determine graphical part position coordinates.
                        get_element(*pm, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &pmx, (void*) POINTER_MEMORY_ABSTRACTION);
                        get_element(*pm, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &pmy, (void*) POINTER_MEMORY_ABSTRACTION);
                        get_element(*pm, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) &pmz, (void*) POINTER_MEMORY_ABSTRACTION);
                        // Determine source part size coordinates.
                        get_element(*sm, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &smx, (void*) POINTER_MEMORY_ABSTRACTION);
                        get_element(*sm, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &smy, (void*) POINTER_MEMORY_ABSTRACTION);
                        get_element(*sm, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) &smz, (void*) POINTER_MEMORY_ABSTRACTION);

                        if ((*mx >= **pmx) && (*my >= **pmy) && (*mz >= **pmz)
                            && (*mx < (**pmx + **smx)) && (*my < (**pmy + **smy)) && (*mz < (**pmz + **smz))) {

                            // The event happened within the graphical part's area.

                            // Sense the graphical part's command.
                            sense_x_window_system_command(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, *d, *dc, p17, p18, p19, p20);

                            compare_equal_arrays((void*) &r, *a, *ac, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
                        n = NULL_POINTER_MEMORY_MODEL;
                        nc = NULL_POINTER_MEMORY_MODEL;
                        ns = NULL_POINTER_MEMORY_MODEL;
                        a = NULL_POINTER_MEMORY_MODEL;
                        ac = NULL_POINTER_MEMORY_MODEL;
                        as = NULL_POINTER_MEMORY_MODEL;
                        m = NULL_POINTER_MEMORY_MODEL;
                        mc = NULL_POINTER_MEMORY_MODEL;
                        ms = NULL_POINTER_MEMORY_MODEL;
                        d = NULL_POINTER_MEMORY_MODEL;
                        dc = NULL_POINTER_MEMORY_MODEL;
                        ds = NULL_POINTER_MEMORY_MODEL;
                        // Reset graphical part position name, abstraction, model, details.
                        pn = NULL_POINTER_MEMORY_MODEL;
                        pnc = NULL_POINTER_MEMORY_MODEL;
                        pns = NULL_POINTER_MEMORY_MODEL;
                        pa = NULL_POINTER_MEMORY_MODEL;
                        pac = NULL_POINTER_MEMORY_MODEL;
                        pas = NULL_POINTER_MEMORY_MODEL;
                        pm = NULL_POINTER_MEMORY_MODEL;
                        pmc = NULL_POINTER_MEMORY_MODEL;
                        pms = NULL_POINTER_MEMORY_MODEL;
                        pd = NULL_POINTER_MEMORY_MODEL;
                        pdc = NULL_POINTER_MEMORY_MODEL;
                        pds = NULL_POINTER_MEMORY_MODEL;
                        // Reset graphical part size name, abstraction, model, details.
                        sn = NULL_POINTER_MEMORY_MODEL;
                        snc = NULL_POINTER_MEMORY_MODEL;
                        sns = NULL_POINTER_MEMORY_MODEL;
                        sa = NULL_POINTER_MEMORY_MODEL;
                        sac = NULL_POINTER_MEMORY_MODEL;
                        sas = NULL_POINTER_MEMORY_MODEL;
                        sm = NULL_POINTER_MEMORY_MODEL;
                        smc = NULL_POINTER_MEMORY_MODEL;
                        sms = NULL_POINTER_MEMORY_MODEL;
                        sd = NULL_POINTER_MEMORY_MODEL;
                        sdc = NULL_POINTER_MEMORY_MODEL;
                        sds = NULL_POINTER_MEMORY_MODEL;

                        // Reset graphical part position coordinates.
                        pmx = (int**) NULL_POINTER_MEMORY_MODEL;
                        pmy = (int**) NULL_POINTER_MEMORY_MODEL;
                        pmz = (int**) NULL_POINTER_MEMORY_MODEL;
                        // Reset graphical part size coordinates.
                        smx = (int**) NULL_POINTER_MEMORY_MODEL;
                        smy = (int**) NULL_POINTER_MEMORY_MODEL;
                        smz = (int**) NULL_POINTER_MEMORY_MODEL;

                        // Reset new mouse coordinates.
                        nx = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        ny = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        nz = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Reset comparison result.
                        r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Increment loop count.
                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system part. The whole model count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system part. The mouse x coordinate is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system part. The mouse y coordinate is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not sense x window system part. The mouse z coordinate is null.");
    }
}

/**
 * Receives the x window system display into a window.
 *
 * @param p0 the destination window (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source display
 * @param p4 the source count
 */
void receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The knowledge memory.
    void** k = NULL_POINTER_MEMORY_MODEL;
    void** kc = NULL_POINTER_MEMORY_MODEL;
    void** ks = NULL_POINTER_MEMORY_MODEL;
    // The signal memory.
    void** s = NULL_POINTER_MEMORY_MODEL;
    void** sc = NULL_POINTER_MEMORY_MODEL;
    void** ss = NULL_POINTER_MEMORY_MODEL;
    // The signal memory mutex.
    pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER_MEMORY_MODEL;
    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) NULL_POINTER_MEMORY_MODEL;
    // The signal memory interrupt request flag.
    sig_atomic_t** sirq = (sig_atomic_t**) NULL_POINTER_MEMORY_MODEL;
    // The user interface root.
    void** r = NULL_POINTER_MEMORY_MODEL;
    void** rc = NULL_POINTER_MEMORY_MODEL;
    void** rs = NULL_POINTER_MEMORY_MODEL;
    // The user interface commands.
    void** c = NULL_POINTER_MEMORY_MODEL;
    void** cc = NULL_POINTER_MEMORY_MODEL;
    void** cs = NULL_POINTER_MEMORY_MODEL;
    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = (struct _XDisplay**) NULL_POINTER_MEMORY_MODEL;
    // The window.
    int** w = (int**) NULL_POINTER_MEMORY_MODEL;

    // Get knowledge memory internal.
    get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &k, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &kc, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &ks, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get signal memory internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &s, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &sc, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &ss, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &smt, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get x window system mutex.
    get_element(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &xmt, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get interrupt request internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &sirq, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get user interface root internal.
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &r, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &rc, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &rs, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get user interface commands internal.
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL_MEMORY_MEMORY_NAME, (void*) &c, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &cc, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &cs, (void*) POINTER_MEMORY_ABSTRACTION);
    // Get x window system internals.
    get_element(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &d, (void*) POINTER_MEMORY_ABSTRACTION);
    get_element(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) &w, (void*) POINTER_MEMORY_ABSTRACTION);

    // The command name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;

    //?? TODO: The temporary graphical part name, abstraction, model, details.
    void** tmpn = NULL_POINTER_MEMORY_MODEL;
    void** tmpnc = NULL_POINTER_MEMORY_MODEL;
    void** tmpns = NULL_POINTER_MEMORY_MODEL;
    void** tmpa = NULL_POINTER_MEMORY_MODEL;
    void** tmpac = NULL_POINTER_MEMORY_MODEL;
    void** tmpas = NULL_POINTER_MEMORY_MODEL;
    void** tmpm = NULL_POINTER_MEMORY_MODEL;
    void** tmpmc = NULL_POINTER_MEMORY_MODEL;
    void** tmpms = NULL_POINTER_MEMORY_MODEL;
    void** tmpd = NULL_POINTER_MEMORY_MODEL;
    void** tmpdc = NULL_POINTER_MEMORY_MODEL;
    void** tmpds = NULL_POINTER_MEMORY_MODEL;

    // The event.
    XEvent e;
    // The event type.
    int t = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The signal identification.
    void** id = NULL_POINTER_MEMORY_MODEL;

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
        if (e.xexpose.count == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Get actual command belonging to the x window system expose event.
            get_universal_compound_element_by_name(*c, *cc,
                (void*) EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                *k, *kc);

    fwprintf(stdout, L"TEST expose sense t: %i\n", t);

            // Lock signal memory mutex.
            pthread_mutex_lock(*smt);

            // Get new signal identification by incrementing the current maximum signal's one.
            get_new_signal_identification(*s, *sc, (void*) &id);

            // Add signal to signal memory.
//??            set_signal(*s, *sc, *ss, ca, cac, cm, cmc, cd, cdc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) id);

            // Set interrupt request flag, in order to notify the signal checker
            // that a new signal has been placed in the signal memory.
            **sirq = *NUMBER_1_INTEGER_MEMORY_MODEL;

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
        //?? XDrawImageString(e.xexpose.display, e.xexpose.window, gc_menu_font, 100, 100, event.xbutton.x, wcslen(event.xbutton.x));

    } else if ((t == ButtonPress) || (t == ButtonRelease)) {

    fwprintf(stdout, L"TEST button press sense t: %i\n", t);

        //?? TODO: This is a temporary solution!
        //?? There is no meta information (such as position or size) known
        //?? about the gui root node. Therefore, the actual window as its
        //?? only part element is determined here and handed over to
        //?? further procedures.
        get_compound_element_by_index(*r, *rc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL,
            (void*) &tmpn, (void*) &tmpnc, (void*) &tmpns,
            (void*) &tmpa, (void*) &tmpac, (void*) &tmpas,
            (void*) &tmpm, (void*) &tmpmc, (void*) &tmpms,
            (void*) &tmpd, (void*) &tmpdc, (void*) &tmpds);

        // Determine command, depending on mouse button and event type.
        // CAUTION! Hand over command abstraction, model, details as reference!
        sense_x_window_system_part(&cn, &cnc, &cns, &ca, &cac, &cas, &cm, &cmc, &cms, &cd, &cdc, &cds,
            *tmpm, *tmpmc, &(e.xbutton.x), &(e.xbutton.y), (void*) NUMBER_0_INTEGER_MEMORY_MODEL,
            &t, &(e.xbutton.button), *k, *kc);

        // Lock signal memory mutex.
        pthread_mutex_lock(*smt);

        // Get new signal identification by incrementing the current maximum signal's one.
        get_new_signal_identification(*s, *sc, (void*) &id);

        // Add signal to signal memory.
//??        set_signal(*s, *sc, *ss, ca, cac, cm, cmc, cd, cdc, (void*) &NORMAL_SIGNAL_PRIORITY_MODEL, (void*) id);

        // Set interrupt request flag, in order to notify the signal checker
        // that a new signal has been placed in the signal memory.
        **sirq = *NUMBER_1_INTEGER_MEMORY_MODEL;

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

/* X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
