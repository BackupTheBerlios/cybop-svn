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
 * @version $Revision: 1.12 $ $Date: 2004-06-06 21:34:21 $ $Author: christian $
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
 * @param p3 the knowledge
 * @param p4 the knowledge count
 * @param p5 the knowledge size
 * @param p6 the internals
 * @param p7 the internals count
 * @param p8 the internals size
 */
void wait(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8) {

    if (p5 != NULL_POINTER) {

        // The internal data and flags for legacy stuff and
        // handling of various platforms and graphical user interfaces
        // such as X-Windows, Macintosh or MS Windows.
//??        void** intern = (void**) p9;

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

                            handle_compound_signal((void*) &s, (void*) &sc, (void*) &p, p0, p1, p2);

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

                            handle_operation_signal((void*) &s, (void*) &sc,
                                p3, p4, p5, p6, p7, p8, p0, p1, p2,
                                (void*) &f);

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
            // Knowledge container.
            //

            // The knowledge container.
            void* k = NULL_POINTER;
            // The knowledge container count.
            int kc = 0;
            // The knowledge container size.
            int ks = 0;

            // Create knowledge container.
            create_compound((void*) &s, (void*) &sc, (void*) &ss);

            //
            // Internals container.
            //

            // The internals container.
            void* i = NULL_POINTER;
            // The internals container count.
            int ic = 0;
            // The internals container size.
            int is = 0;

            // Create internals container.
//??            create_internals((void*) &i);

            //
            // Signal container.
            // The initial count and size is set to 1,
            // for storing the startup signal.
            //

            // The signal container.
            void* s = NULL_POINTER;
            // The signal container count.
            int sc = 1;
            // The signal container size.
            int ss = 1;

            // Create signal container.
            create_signal_memory((void*) &s, (void*) &sc, (void*) &ss);

            //
            // Startup signal.
            //

            // The startup signal.
            void* sig = NULL_POINTER;
            // The startup signal count.
            int sigc = 0;
            // The startup signal size.
            int sigs = 0;
            // The startup signal model.
            void* sigm = (void*) p1[1];
            // The startup signal model count.
            int sigmc = strlen(p1[1]);
            // The startup signal abstraction.
            void* siga = (void*) OPERATION_ABSTRACTION; //?? COMPOUND_ABSTRACTION
            // The startup signal abstraction count.
            int sigac = OPERATION_ABSTRACTION_COUNT; //?? COMPOUND_ABSTRACTION_COUNT
            // The startup signal location.
            void* sigl = (void*) INLINE_LOCATION; //?? FILE_LOCATION;
            // The startup signal location count.
            int siglc = INLINE_LOCATION_COUNT; //?? FILE_LOCATION_COUNT;

            // Create startup signal.
            // The transient signal gets initialized from a persistent
            // cybol source whose location was given at command line.
            create_model((void*) &sig, (void*) &sigc, (void*) &sigs, (void*) &sigm, (void*) &sigmc, (void*) &siga, (void*) &sigac, (void*) &sigl, (void*) &siglc);

            // Add startup signal to signal memory.
            set_signal((void*) &s, (void*) &sc, (void*) &ss, (void*) &sig, (void*) &NORMAL_PRIORITY, (void*) &siga, (void*) &sigac);

            //
            // Waiting loop.
            //

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait((void*) &s, (void*) &sc, (void*) &ss,
                (void*) &k, (void*) &kc, (void*) &ks,
                (void*) &i, (void*) &ic, (void*) &is);
            // The loop above is left as soon as its shutdown flag is set.

            //
            // Destruction.
            //

            // Destroy startup signal.
            destroy_model((void*) &sig, (void*) &sigc, (void*) &sigm, (void*) &sigmc, (void*) &siga, (void*) &sigac, (void*) &sigl, (void*) &siglc);

            // Destroy signal container.
            destroy_signal_memory((void*) &s, (void*) &sc, (void*) &ss);

            // Destroy internals container.
//??            destroy_internals(i);

            // Destroy knowledge container.
            destroy_compound((void*) &k, (void*) &kc, (void*) &ks);

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
