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
 * @version $Revision: 1.14 $ $Date: 2004-06-11 19:34:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <stdio.h>
//??#include <stdlib.h>
#include "../constant/constant.c"
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

                get_signal(p0, p1, (void*) &i,
                    (void*) &s, (void*) &sc, (void*) &p, (void*) &a, (void*) &ac);

                // Abstraction and priority are removed internally,
                // together with the signal.
                remove_signal(p0, p1, p2, (void*) &i);

                // CAUTION! Do NOT destroy signal here!
                // Signals are static and stored in the logic knowledge tree
                // which gets created at system startup and destroyed at system shutdown.

                //
                // Handle compound signal.
                //

    fprintf(stderr, "a: %s\n", a);

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
 * - command (cyboi)
 * - abstraction (compound|operation)
 * - location (inline|file|ftp|http)
 * - model (a compound model or primitive operation, for example: exit or model.submodel)
 *
 * Usage:
 * cyboi compound|operation inline|file|ftp|http model.submodel
 *
 * Example 1 (starts up and right away shuts down the system):
 * cyboi operation inline exit
 *
 * Example 2 (calls the startup routine of some application):
 * cyboi compound file /application/logic/startup.cybol
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
    // Global variables.
    //

    /** The log output. */
    log_output = stderr;

    //
    // System lifecycle.
    //

    if (p1 != NULL_POINTER) {

        if (p0 == STARTUP_PARAMETERS_COUNT) {

            //
            // Knowledge container.
            //

            // The knowledge container and its count and size.
            void* k = NULL_POINTER;
            int kc = 0;
            int ks = 0;

            // Create knowledge container.
            create_compound((void*) &k, (void*) &ks);

            //
            // Internals container.
            //

            // The internals container and its count and size.
            void* i = NULL_POINTER;
            int ic = 0;
            int is = 0;

            // Create internals container.
//??            create_internals((void*) &i, (void*) &ic, (void*) &is);

            //
            // Signal container.
            // The initial count and size is set to 1,
            // for storing the startup signal.
            //

            // The signal container and its count and size.
            void* s = NULL_POINTER;
            int sc = 1;
            int ss = 1;

            // Create signal container.
            create_signal_memory((void*) &s, (void*) &ss);

            //
            // Startup model.
            //

            // The transient model and its count and size.
            void* t = NULL_POINTER;
            int tc = 0;
            int ts = 0;

            // The persistent part abstraction and its count.
            void* pa = (void*) p1[ABSTRACTION_STARTUP_PARAMETER_INDEX];
            int pac = strlen(p1[ABSTRACTION_STARTUP_PARAMETER_INDEX]);

            // The persistent part location and its count.
            void* pl = (void*) p1[LOCATION_STARTUP_PARAMETER_INDEX];
            int plc = strlen(p1[LOCATION_STARTUP_PARAMETER_INDEX]);

            // The persistent part model and its count.
            void* pm = (void*) p1[MODEL_STARTUP_PARAMETER_INDEX];
            int pmc = strlen(p1[MODEL_STARTUP_PARAMETER_INDEX]);

    fprintf(stderr, "pa: %s\n", pa);
    fprintf(stderr, "pac: %i\n", pac);
    fprintf(stderr, "pl: %s\n", pl);
    fprintf(stderr, "plc: %i\n", plc);
    fprintf(stderr, "pm: %s\n", pm);
    fprintf(stderr, "pmc: %i\n", pmc);

            // Create startup model.
            create_model((void*) &t, (void*) &tc, (void*) &ts,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &pa, (void*) &pac,
                (void*) &pl, (void*) &plc,
                (void*) &pm, (void*) &pmc,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER);

    fprintf(stderr, "t: %i\n", t);
    fprintf(stderr, "tc: %i\n", tc);
    fprintf(stderr, "ts: %i\n", ts);

            //
            // Startup signal.
            //

            // Add startup signal to signal memory.
            set_signal((void*) &s, (void*) &sc, (void*) &ss,
                (void*) &t, (void*) &tc,
                (void*) &NORMAL_PRIORITY,
                (void*) &pa, (void*) &pac);

            //
            // Waiting loop.
            //

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            // The loop is left as soon as its shutdown flag is set.
            wait((void*) &s, (void*) &sc, (void*) &ss,
                (void*) &k, (void*) &kc, (void*) &ks,
                (void*) &i, (void*) &ic, (void*) &is);

            //
            // Destruction.
            //

            // Destroy startup model.
            destroy_model((void*) &t, (void*) &tc, (void*) &ts,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &pa, (void*) &pac,
                (void*) &pl, (void*) &plc,
                (void*) &pm, (void*) &pmc,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER);

            // Destroy signal container.
            destroy_signal_memory((void*) &s, (void*) &ss);

            // Destroy internals container.
//??            destroy_internals((void*) &i, (void*) &ic, (void*) &is);

            // Destroy knowledge container.
            destroy_compound((void*) &k, (void*) &ks);

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
