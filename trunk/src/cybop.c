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

#include <stdlib.h>
#include <string.h>
#include "log_handler.c"
#include "signal.c"
#include "signal_memory.c"
#include "signal_memory_handler.c"
#include "statics.c"

//?? Temporary for character screen testing.
#include "character_screen_handler.c"

/**
 * This is the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.2 $ $Date: 2003-12-03 15:10:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Shows the usage information.
 */
static void show_usage_information() {

    show_message("Usage: cyboi signal");
    show_message("Example: cyboi cybop.sample.hello_world.dynamics.startup");
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
 */
static void wait(void* p0, void* p1, void* p2) {

    // Create shutdown flag and initialize to false.
    int* f = (int*) malloc(sizeof(int));
    *f = 0;
    
    // Run endless loop handling signals.
    while (TRUE_VALUE) {

        if (*f != 1) {

            // Get top priority signal from signal memory and remove it from there.
            int i = get_highest_priority_index(p0);
            void* s = get_signal(p0, (void*) &i);
            char* a = (char*) get_abstraction(p0, (void*) &i);
            void* p = get_priority(p0, (void*) &i);
            remove_signal(p0, (void*) &i);

            // Handle signal.
            if (strcmp(a, DYNAMICS_COMPOUND) == 0) {
                
                handle_compound_signal(p0, s, p);
        
            } else {
        
                handle_operation_signal(s, a, p1, p2, f);
            }

        } else {

            // Leave loop if the shutdown flag was set.
            break;
        }
    }

    free(f);
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

    if (p1 != 0) {

        if (p0 == 2) {

            // Create statics.
            void* s = malloc(sizeof(struct statics_model));
            create_statics_model_containers(s);
            
            // Create dynamics.
            void* d = malloc(sizeof(struct dynamics_model));
            create_dynamics_model_containers(d);
            
            // Create signal memory.
            void* sm = malloc(sizeof(struct map));
            initialize_map(sm);

            // Create startup signal.
            void* ss = create_dynamics_model((void*) p1[1], (void*) DYNAMICS_COMPOUND);

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
                add_signal(sm, ss, (void*) DYNAMICS_COMPOUND, (void*) NORMAL_PRIORITY);
//??            }

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait(sm, s, d);
            // The loop above is left as soon as its shutdown flag is set.

            // Destroy startup signal.
            destroy_dynamics_model(ss, (void*) p1[1], (void*) DYNAMICS_COMPOUND);

            // Destroy signal memory.
            finalize_map(sm);
            free(sm);

            // Destroy dynamics.
            destroy_dynamics_model_containers(d);
            free(d);
            
            // Destroy statics.
            destroy_statics_model_containers(s);
            free(s);
            
            log((void*) &INFO_LOG_LEVEL, "Exit CYBOI normally.");

            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

            log((void*) &ERROR_LOG_LEVEL, "Could not execute CYBOI. The command line argument number is incorrect.");
            show_usage_information();
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not execute CYBOI. The command line argument vector is null.");
    }

    return r;
}

