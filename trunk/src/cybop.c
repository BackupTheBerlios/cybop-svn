/*
 * $RCSfile: cybop.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <stdlib.h>
#include <string.h>
#include "internals.c"
#include "log_handler.c"
#include "signal_memory.c"
#include "signal_memory_handler.c"
#include "statics.c"
#include "x_windows_handler.c"

//?? Temporary for character screen testing.
#include "character_screen_handler.c"

/**
 * This is the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.12 $ $Date: 2003-12-19 12:44:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

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
    
    if (i != (void*) 0) {
        
        // Initialize shutdown flag to false.
        int f = 0;
        int index = -1;
        void* s = (void*) 0;
        char* a = (void*) 0;
        void* p = (void*) 0;
        
        // Run endless loop handling signals.
        while (TRUE_VALUE) {
    
            if (f == 0) {

                // Check for x windows events and send them as cyboi signals.
                if (i->x_windows_flag == 1) {

                    receive_x_windows_input(i->x_windows);
                }
                
                //?? test x windows
                send_x_windows_output((void*) 0, (void*) 0, p3);
                break;
                
/*??
                // Get top priority signal from signal memory and remove it from there.
                get_highest_priority_index(p0, (void*) &index);
                s = get_signal(p0, (void*) &index);
                a = (char*) get_abstraction(p0, (void*) &index);
                p = get_priority(p0, (void*) &index);
                remove_signal(p0, (void*) &index);
    
                // Handle signal.
                log_message((void*) &INFO_LOG_LEVEL, "0");
                if (strcmp(a, DYNAMICS_COMPOUND) == 0) {
                    
                    log_message((void*) &INFO_LOG_LEVEL, "1");
                    handle_compound_signal(p0, s, p);
            
                } else {
            
                    log_message((void*) &INFO_LOG_LEVEL, "2");
                    handle_operation_signal(s, a, p1, p2, p3, (void*) &f);
                }
*/
    
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

    if (p1 != (void*) 0) {

        if (p0 == 2) {

            // Create statics.
            void* s = malloc(sizeof(struct statics_model));
            create_statics_model_containers(s);
            
            // Create dynamics.
            void* d = malloc(sizeof(struct dynamics_model));
            create_dynamics_model_containers(d);
            
            // Create internals.
            void* i = malloc(sizeof(struct internals));
            
            // Create signal memory.
            void* sm = malloc(sizeof(struct signal_memory));
            create_signal_memory(sm);

            // Create startup signal.
            void* ss = create_dynamics((void*) p1[1], (void*) 0, (void*) 0, (void*) DYNAMICS_COMPOUND);

            // Add startup signal to signal memory.
            // Caution! Adding of signals must be synchronized between:
            // - internal CYBOI signals added here
            // - hardware interrupt signals sent from the operating system
            // These are the only two accessing the signal memory for adding.
//??            synchronized (p0) {

                // Add "part" signal to signal memory,
                // using the "whole" signal's priority.
                // (Each signal/action has a priority.
                // An action may consist of "part" actions.
                // The "part" actions cannot have higher/lower priority
                // than their original "whole" action.)
                add_signal(sm, ss, (void*) DYNAMICS_COMPOUND, (void*) &NORMAL_PRIORITY);
//??            }

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait(sm, s, d, i);
            // The loop above is left as soon as its shutdown flag is set.

            // Destroy startup signal.
            destroy_dynamics(ss, (void*) p1[1], (void*) 0, (void*) 0, (void*) DYNAMICS_COMPOUND);

            // Destroy signal memory.
            destroy_signal_memory(sm);
            free(sm);

            // Destroy internals.
            free(i);
            
            // Destroy dynamics.
            destroy_dynamics_model_containers(d);
            free(d);
            
            // Destroy statics.
            destroy_statics_model_containers(s);
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
