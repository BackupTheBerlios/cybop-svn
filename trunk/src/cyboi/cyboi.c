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
 * @version $Revision: 1.11 $ $Date: 2004-05-31 17:49:23 $ $Author: christian $
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
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the statics
 * @param p4 the dynamics
 * @param p5 the internals
 */
void wait(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != NULL_POINTER) {

        // The internal data and flags for legacy stuff and
        // handling of various platforms and graphical user interfaces
        // such as X-Windows, Macintosh or MS Windows.
//??        struct internals* intern = (struct internals*) p5;
        // The shutdown flag.
        int f = 0;
        // The highest priority index.
        int i = -1;
        // The signal.
        void* s = NULL_POINTER;
        // The signal count.
        int sc = 0;
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
//??            send_x_windows_output(NULL, NULL, p5);
//??            sleep(4);

            // Check for x windows events and send them as cyboi signals.
//??            if (intern->x_windows_flag == 1) {

//??                receive_x_windows_input(p0, intern->x_windows);
//??            }

//??            break;

            // Get top priority signal from signal memory and remove it from there.
            get_highest_priority_index(p0, p1, (void*) &i);

            if (i >= 0) {

                get_signal(p0, p1, (void*) &i, (void*) &s, (void*) &sc, (void*) &p, (void*) &a, (void*) &ac);

                // Abstraction and priority are removed internally,
                // together with the signal.
                remove_signal(p0, p1, p2, (void*) &i);

                // CAUTION! Do NOT destroy signal here!
                // Signals are static and stored in the logic knowledge tree
                // which gets created at system startup and destroyed at system shutdown.

                //
                // Handle compound signal.
                //

                if (d == 0) {

                    if (ac == COMPOUND_ABSTRACTION_COUNT) {

                        compare_array_elements((void*) &a, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            handle_compound_signal(p0, p1, p2, (void*) &s, (void*) &sc, (void*) &p);

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

                            handle_operation_signal((void*) &s, (void*) &sc, p3, p4, p5, (void*) &f);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) &COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
                }

                // Reset signal.
                s = NULL_POINTER;
                // Reset signal count.
                sc = 0;
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
    // Testing.
    //

    // Call testing procedures.
    // Comment/ uncomment this as needed.
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

            //
            // State root container.
            //

            // The state root.
            void* s = NULL_POINTER;
            // The state root count.
            int sc = 0;
            // The state root size.
            int ss = 0;

            // Create state root.
            create_compound((void*) &s, (void*) &sc, (void*) &ss);

            //
            // Logic root container.
            //

            // The logic root.
            void* l = NULL_POINTER;
            // The logic root count.
            int lc = 0;
            // The logic root size.
            int ls = 0;

            // Create logic root.
            create_compound((void*) &l, (void*) &lc, (void*) &ls);

            //
            // Internals container.
            //

            // The internals.
            void* i = NULL_POINTER;
            // The internals count.
            int ic = 0;
            // The internals size.
            int is = 0;

            // Create internals.
//??            create_internals((void*) &i);

            //
            // Signal memory container.
            // The initial count and size is set to 1,
            // for storing the startup signal.
            //

            // The signal memory.
            void* m = NULL_POINTER;
            // The signal memory count.
            int mc = 1;
            // The signal memory size.
            int ms = 1;

            // Create signal memory.
            create_signal_memory((void*) &m, (void*) &mc, (void*) &ms);

            //
            // Startup signal.
            //

            // The startup signal.
            void* ss = NULL_POINTER;
            // The startup signal count.
            int ssc = 0;
            // The startup signal size.
            int sss = 0;
            // The startup signal model.
            void* sm = (void*) p1[1];
            // The startup signal model count.
            int smc = strlen(p1[1]);
            // The startup signal abstraction.
            void* sa = (void*) OPERATION_ABSTRACTION; //?? COMPOUND_ABSTRACTION
            // The startup signal abstraction count.
            int sac = OPERATION_ABSTRACTION_COUNT; //?? COMPOUND_ABSTRACTION_COUNT
            // The startup signal location.
            void* sl = (void*) INLINE_LOCATION; //?? FILE_LOCATION;
            // The startup signal location count.
            int slc = INLINE_LOCATION_COUNT; //?? FILE_LOCATION_COUNT;

            // Create startup signal.
            // The transient signal gets initialized from a persistent
            // cybol source whose location was given at command line.
            create_model((void*) &ss, (void*) &ssc, (void*) &sss, (void*) &sm, (void*) &smc, (void*) &sa, (void*) &sac, (void*) &sl, (void*) &slc);

            // Add startup signal to signal memory.
            set_signal((void*) &m, (void*) &mc, (void*) &ms, (void*) &ss, (void*) &NORMAL_PRIORITY, (void*) &sa, (void*) &sac);

            //
            // Waiting loop.
            //

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait((void*) &m, (void*) &mc, (void*) &ms, (void*) &s, (void*) &l, (void*) &i);
            // The loop above is left as soon as its shutdown flag is set.

            //
            // Destruction.
            //

            // Destroy startup signal.
            destroy_model((void*) &sig, (void*) &sigc, (void*) &p, (void*) &pc, (void*) &a, (void*) &ac, (void*) &l, (void*) &lc);

            // Destroy signal memory.
            destroy_signal_memory((void*) &m, (void*) &mc, (void*) &ms);

            // Destroy internals.
//??            destroy_internals(i);

            // Destroy logic container.
            destroy_compound((void*) &l, (void*) &lc, (void*) &ls);

            // Destroy state container.
            destroy_compound((void*) &s, (void*) &sc, (void*) &ss);

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
