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
 * @version $Revision: 1.8 $ $Date: 2004-05-27 14:47:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <stdlib.h>
#include "../constants/constants.c"
#include "../cyboi/internals.c"
#include "../logger/logger.c"
#include "../signal/signal_memory.c"
#include "../test/test.c"
#include "../x_windows/x_windows_handler.c"
//?? Temporary for character screen testing.
#include "../cyboi/character_screen.c"

/**
 * Waits for signals.
 *
 * @param p0 the signal memory
 * @param p1 the statics
 * @param p2 the dynamics
 * @param p3 the internals
 */
void wait(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        // The internal data and flags for legacy stuff and
        // handling of various platforms and graphical user interfaces
        // such as X-Windows, Macintosh or MS Windows.
//??        struct internals* intern = (struct internals*) p3;
        // The shutdown flag.
        int f = 0;
        // The highest priority index.
        int i = -1;
        // The signal.
        void* s = NULL_POINTER;
        // The priority.
        int p = NORMAL_PRIORITY;
        // The abstraction.
        char* a = CHARACTER_NULL_POINTER;
        // The abstraction count.
        int ac = 0;
        // The signal size.
        int ss = 0;
        // The persistent model.
        void* pers = NULL_POINTER;
        // The persistent model size.
        int perss = 0;
        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;
        //?? Testing!
//??        init_x();

        log_message((void*) &INFO_LOG_LEVEL, (void*) &WAIT_FOR_SIGNALS_MESSAGE, (void*) &WAIT_FOR_SIGNALS_MESSAGE_COUNT);

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
            get_highest_priority_index(p0, (void*) &i);

            if (i >= 0) {

                get_signal(p0, (void*) &i, (void*) &s, (void*) &p, (void*) &a, (void*) &ac);

                // Abstraction and priority are removed internally,
                // together with the signal.
                remove_signal(p0, (void*) &i);

                // Do NOT destroy signal here!
                // Signals are static and stored in the logic knowledge tree
                // which gets created at system startup and destroyed at system shutdown.

                //
                // Handle compound signal.
                //

                if (d == 0) {

                    if (ac == COMPOUND_ABSTRACTION_COUNT) {

                        compare_array_elements((void*) &a, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            handle_compound_signal(p0, (void*) &s, (void*) &p);

                            d = 1;
                        }
                    }
                }

                //
                // Handle operation signal.
                //

                if (d == 0) {

                    if (ac == OPERATION_ABSTRACTION_COUNT) {

                        compare_array_elements((void*) &a, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            handle_operation_signal((void*) &s, p1, p2, p3, (void*) &f);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
                }

                // Reset signal.
                s = NULL_POINTER;
                // Reset priority.
                p = NORMAL_PRIORITY;
                // Reset abstraction.
                a = CHARACTER_NULL_POINTER;
                // Reset abstraction count.
                ac = 0;
                // Reset highest priority index.
                i == -1;
                // Reset done flag.
                d == 0;
                // Reset comparison result.
                r == 0;
            }
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE, (void*) &COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_COUNT);
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

    // Return 1 to indicate an error, by default.
    int r = 1;

    //
    // Calls testing procedures.
    // Comment/ uncomment this as needed.
    //

//    test();
//    return 0;

    //
    // Global variables for logger.
    //

    // Set log level.
    log_level = INFO_LOG_LEVEL;
    // Set maximum log message count.
    maximum_log_message_count = 200;
    // Set log output.
    log_output = stderr;

    //
    // System lifecycle.
    //

    if (p1 != NULL_POINTER) {

        if (p0 == 2) {

            // Create statics.
            void* s = NULL_POINTER;
            int sc = 0;
            create_compound((void*) &s, (void*) &sc);

            // Create dynamics.
            void* d = NULL_POINTER;
            int dc = 0;
            create_compound((void*) &d, (void*) &dc);

            // Create internals.
            void* i = NULL_POINTER;
//??            create_map((void*) &i);

            // Create signal memory.
            void* sm = NULL_POINTER;
            int sms = 0;
            int smc = 0;
            create_signal_memory((void*) &sm, (void*) &sms, (void*) &smc);

            // Create startup signal.
            void* sig = NULL_POINTER;
            int sigc = 0;
            void* p = (void*) p1[1];
            int pc = strlen(p1[1]);
            void* a = (void*) OPERATION_ABSTRACTION;
            int ac = OPERATION_ABSTRACTION_COUNT;
            void* l = (void*) FILE_LOCATION;
            int lc = FILE_LOCATION_COUNT;

            // The transient signal gets initialized from a persistent
            // cybol source whose location was given at command line.
            //?? CHANGE OPERATION_ABSTRACTION to COMPOUND_ABSTRACTION,
            //?? when testing with only EXIT_SIGNAL is over!
            create_model((void*) &sig, (void*) &sigc, (void*) &p, (void*) &pc, (void*) &a, (void*) &ac, (void*) &l, (void*) &lc);

            // Add startup signal to signal memory.
            set_signal((void*) &sm, (void*) &sig, (void*) &NORMAL_PRIORITY, (void*) &a, (void*) &ac);

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait((void*) &sm, (void*) &s, (void*) &d, (void*) &i);
            // The loop above is left as soon as its shutdown flag is set.

            // Destroy startup signal.
            destroy_model((void*) &sig, (void*) &sigc, (void*) &p, (void*) &pc, (void*) &a, (void*) &ac, (void*) &l, (void*) &lc);

            // Destroy signal memory.
            destroy_signal_memory((void*) &sm, (void*) &sms, (void*) &smc);

            // Destroy internals.
//??            free(i);

            // Destroy dynamics.
            destroy_compound((void*) &d, (void*) &dc);

            // Destroy statics.
            destroy_compound((void*) &s, (void*) &sc);

            log_message((void*) &INFO_LOG_LEVEL, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE, (void*) &EXIT_CYBOI_NORMALLY_MESSAGE_COUNT);

            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT);
            log_message((void*) &INFO_LOG_LEVEL, (void*) &USAGE_MESSAGE, (void*) &USAGE_MESSAGE_COUNT);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE, (void*) &COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT);
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
