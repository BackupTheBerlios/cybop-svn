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
 * @version $Revision: 1.18 $ $Date: 2004-04-21 11:06:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <stdlib.h>
#include <string.h>
#include "constants.c"
#include "internals.c"
#include "logger/log_handler.c"
#include "model/statics_models.c"
#include "signal/signal_memory_handler.c"
#include "test/test.c"
#include "x_windows/x_windows_handler.c"

//?? Temporary for character screen testing.
#include "character_screen_handler.c"

//
// Message constants.
//

// The usage message array.
static const char USAGE_MESSAGE_ARRAY[] = {'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 's', 'i', 'g', 'n', 'a', 'l'};

// The usage message.
//??static const char* USAGE_MESSAGE = USAGE_MESSAGE_ARRAY;
static const char* USAGE_MESSAGE = (char*) {'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 's', 'i', 'g', 'n', 'a', 'l'};

// The example message array.
static const char EXAMPLE_MESSAGE_ARRAY[] = {'E', 'x', 'a', 'm', 'p', 'l', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'c', 'y', 'b', 'o', 'p', '.', 's', 'a', 'm', 'p', 'l', 'e', '.', 'h', 'e', 'l', 'l', 'o', '_', 'w', 'o', 'r', 'l', 'd', '.', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's', '.', 's', 't', 'a', 'r', 't', 'u', 'p'};

// The example message.
static const char* EXAMPLE_MESSAGE = EXAMPLE_MESSAGE_ARRAY;

/**
 * Shows the usage information.
 */
void show_usage_information() {

    show_message((void*) &USAGE_MESSAGE);
    show_message((void*) &EXAMPLE_MESSAGE);
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

    if (p3 != NULL_POINTER) {

        // These are internal data and flags for legacy stuff and
        // handling of various platforms and graphical user interfaces
        // such as X-Windows, Macintosh or MS Windows.
//??        struct internals* intern = (struct internals*) p3;

        // Initialize shutdown flag to false.
        int f = 0;
        int i = -1;
        void* s = NULL_POINTER;
        int p = NORMAL_PRIORITY;
        void* a = NULL_POINTER;
        int as = 0;

        //?? Testing!
//??        init_x();

        log_message((void*) &INFO_LOG_LEVEL, (void*) &"Wait for signals.");

        // Run endless loop handling signals.
        while (1) {

            if (f == 1) {

                // Leave loop if the shutdown flag was set.
                break;
            }

            //?? test x windows
//??            send_x_windows_output(NULL, NULL, p3);
//??            sleep(4);

            // Check for x windows events and send them as cyboi signals.
//??            if (intern->x_windows_flag == 1) {

//??                receive_x_windows_input(p0, intern->x_windows);
//??            }

//??            break;

            // Get top priority signal from signal memory and remove it from there.
//??            get_highest_priority_index(p0, (void*) &i);
            i = 0;

            get_signal(p0, (void*) &i, (void*) &s, (void*) &p, (void*) &a, (void*) &as);

            // Abstraction and priority are removed internally,
            // together with the signal.
            remove_signal(p0, (void*) &i);

            // Destroy signal.
            int ss = 0;
            void* pers = NULL_POINTER;
            int perss = 0;
            destroy_model((void*) &s, (void*) &ss, (void*) &pers, (void*) &perss, (void*) &a, (void*) &as);

            // The comparison result.
            int r = 0;

            log_message((void*) &INFO_LOG_LEVEL, (void*) &"TEST 0");

            // Handle compound signal.
            compare_arrays((void*) &a, (void*) &as, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

            if (r == 1) {

                log_message((void*) &INFO_LOG_LEVEL, (void*) &"TEST 1");
                handle_compound_signal(p0, (void*) &s, (void*) &p);

            } else {

            // Handle operation signal.
            compare_arrays((void*) &a, (void*) &as, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

            if (r == 1) {

                log_message((void*) &INFO_LOG_LEVEL, (void*) &"TEST 2");
                handle_operation_signal((void*) &s, p1, p2, p3, (void*) &f);

            } else {

                log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not handle signal. The signal abstraction is unknown.");

            } // Operation signal.
            } // Compound signal.
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not wait for signals. The internals is null.");
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
 * cyboi application.dynamics.startup
 *
 * @param p0 the argument count (argc)
 * @param p1 the argument vector (argv)
 * @return the return value
 */
int main(int p0, char** p1) {

    // Calls testing procedures. Comment/ uncomment this as needed.
//    test();
//    return 0;

    // Return 1 to indicate an error, by default.
    int r = 1;

    // Log level as static (global) variable.
    log_level = INFO_LOG_LEVEL;

    if (p1 != NULL_POINTER) {

        fputs("TEST 0\n", stderr);

        if (p0 == 2) {

            fputs("TEST 1\n", stdout);

            // Create statics.
            void* s = NULL_POINTER;
            create_compound((void*) &s);

            fputs("TEST 2\n", stdout);

            // Create dynamics.
            void* d = NULL_POINTER;
            create_compound((void*) &d);

            // Create internals.
            void* i = NULL_POINTER;
//??            create_map((void*) &i);

            // Create signal memory.
            void* sm = NULL_POINTER;
            create_signal_memory((void*) &sm);

            // Create (transient) startup signal from (persistent) cybol source.
            void* ss = NULL_POINTER;
            int sss = 0;
            char* p = p1[1];
            int ps = strlen(p1[1]);
            create_model((void*) &ss, (void*) &sss, (void*) &p, (void*) &ps, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_SIZE);

            // Add startup signal to signal memory.
            set_signal((void*) &sm, (void*) &ss, (void*) &NORMAL_PRIORITY, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_SIZE);

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait((void*) &sm, (void*) &s, (void*) &d, (void*) &i);
            // The loop above is left as soon as its shutdown flag is set.

            // Startup signal does not get destroyed here.
            // Signals are destroyed when being read from signal memory.

            // Destroy signal memory.
            destroy_signal_memory((void*) &sm);

            // Destroy internals.
//??            free(i);

            // Destroy dynamics.
            destroy_compound((void*) &d);

            // Destroy statics.
            destroy_compound((void*) &s);

            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Exit CYBOI normally.");

            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not execute CYBOI. The command line argument number is incorrect.");

            show_usage_information();
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not execute CYBOI. The command line argument vector is null.");
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
