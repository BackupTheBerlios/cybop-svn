/*
 * $RCSfile: cyboi.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This is the main file of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.15 $ $Date: 2004-04-05 16:10:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <stdlib.h>
#include <string.h>
#include "internals.c"
#include "logger/log_handler.c"
#include "model/statics_models.c"
#include "signal/signal_memory_handler.c"
#include "x_windows/x_windows_handler.c"

//?? Temporary for character screen testing.
#include "character_screen_handler.c"

/**
 * Shows the usage information.
 */
void show_usage_information() {

    show_message("Usage: cyboi signal");
    show_message((void*) "\n");
    show_message("Example: cyboi cybop.sample.hello_world.dynamics.startup");
    show_message((void*) "\n");
}

/**
 * Waits for signals.
 *
 * The processing of signals follows this sequence:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @param p0 the signal memory
 * @param p1 the statics
 * @param p2 the dynamics
 * @param p3 the internals
 */
void wait(void* p0, void* p1, void* p2, void* p3) {

    log_message((void*) &INFO_LOG_LEVEL, "Wait for signals.");

    // These are internal data and flags for legacy stuff and
    // handling of various platforms and graphical user interfaces
    // such as X-Windows, Macintosh or MS Windows.
    struct internals* i = (struct internals*) p3;

    if (i != NULL) {

        // Initialize shutdown flag to false.
        int f = 0;
        int index = -1;
        void* s = NULL;
        char* a = NULL;
        void* p = NULL;

        //?? Testing!
        init_x();

        // Run endless loop handling signals.
        while (1) {

            if (f == 0) {

                //?? test x windows
//??                send_x_windows_output(NULL, NULL, p3);
                sleep(4);

                // Check for x windows events and send them as cyboi signals.
                if (i->x_windows_flag == 1) {

//??                    receive_x_windows_input(p0, i->x_windows);
                }

//??                break;

                // Get top priority signal from signal memory and remove it from there.
//??                get_highest_priority_index(p0, (void*) &index);
                index = 0;

                s = get_signal(p0, (void*) &index);
                a = (char*) get_abstraction(p0, (void*) &index);
                p = get_priority(p0, (void*) &index);

                // Abstraction and priority are removed internally,
                // together with the signal.
                remove_signal(p0, (void*) &index);

                // Destroy signal. Do not destroy the signal's abstraction and
                // priority here; they are static within CYBOI.
                destroy_model(s, NULL, NULL, (void*) a);

                // Handle signal.
                log_message((void*) &INFO_LOG_LEVEL, "0");
                if (strcmp(a, COMPOUND_MODEL) == 0) {

                    log_message((void*) &INFO_LOG_LEVEL, "1");
                    handle_compound_signal(p0, s, p);

                } else if (strcmp(a, OPERATION_MODEL) == 0) {

                    log_message((void*) &INFO_LOG_LEVEL, "2");
                    handle_operation_signal(s, p1, p2, p3, (void*) &f);

                } else {

                    log_message((void*) &WARNING_LOG_LEVEL, "Could not handle signal. The signal abstraction is unknown.");
                    log_message((void*) &WARNING_LOG_LEVEL, a);
                }

            } else {

                // Leave loop if the shutdown flag was set.
                break;
            }
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not wait for signals. The internals is null.");
    }
}

/**
 * The main entry function.
 *
 * Command line arguments have to be in order:
 * - command
 * - dynamics
 * - statics
 *
 * Example:
 * cyboi application.dynamics.startup application.statics.system
 *
 * @param p0 the argument count (argc)
 * @param p1 the argument vector (argv)
 * @return the return value
 */
int main(int p0, char** p1) {

    // Return 1 to indicate an error, by default.
    int r = 1;

    // Log level as static (global) variable.
    log_level = (void*) &INFO_LOG_LEVEL;

    if (p1 != NULL) {

        if (p0 == 2) {

            // Create statics.
            void* s = NULL;
            create_compound_model((void*) &s);

            // Create dynamics.
            void* d = NULL;
            create_compound_model((void*) &d);

            // Create internals.
            void* i = NULL;
            create_map((void*) &i);

            // Create signal memory.
            void* sm = NULL;
            int sms = 0;
            create_array(sm, (void*) &sms);

            // Create startup signal.
            void* ss = NULL;
            create_model(ss, (void*) p1[1], NULL, (void*) OPERATION_MODEL);

            // Add startup signal to signal memory.
            set_signal_memory_part(sm, sms, (void*) OPERATION_MODEL, ss, (void*) &NORMAL_PRIORITY);

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait(sm, s, d, i);
            // The loop above is left as soon as its shutdown flag is set.

            // Startup signal does not get destroyed here.
            // Signals are destroyed when being read from signal memory.

            // Destroy signal memory.
            destroy_signal_memory(sm);
            free(sm);

            // Destroy internals.
            free(i);

            // Destroy dynamics.
            destroy_model_containers(d);
            free(d);

            // Destroy statics.
            destroy_model_containers(s);
            free(s);

            log_message((void*) &INFO_LOG_LEVEL, "Exit CYBOI normally.");

            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not execute CYBOI. The command line argument number is incorrect.");
            show_usage_information();
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not execute CYBOI. The command line argument vector is null.");
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
