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
#include "map.c"
#include "map_handler.c"
#include "signal.c"
#include "signal_handler.c"
#include "statics.c"

//?? Temporary for character screen testing.
#include "character_screen_handler.c"
#include "array_handler.c"

/**
 * This is the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.16 $ $Date: 2003-10-14 14:54:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Shows the usage information.
 */
static void show_usage_information() {

    show_message("Usage: cyboi dynamics statics");
    show_message("Example: cyboi application.dynamics.startup application.statics.system");
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
 */
static void wait(void* p0) {

    // The shutdown flag.
    int* sf = (int*) malloc(sizeof(int));
    *sf = FALSE_VALUE;

    // Transporting signal.
    void* s = malloc(sizeof(struct signal));

    // Run endless loop handling any signals.
    while (TRUE_VALUE) {

        if (*sf == FALSE_VALUE) {

            // Receive signal.

            receive_signal(p0, s);

            // Handle signal.
            handle_signal(s, (void*) &FALSE_VALUE, sf);

            // Send signal.
            send_signal(p0, s);

            // Reset signal.
            reset_signal(s);

        } else {

            // Leave loop if the shutdown flag was set.
            break;
        }
    }

    free(s);
    free(sf);
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

    // Log handler.
    log_level = (void*) &INFO_LOG_LEVEL;

    //?? Temporary character based screen output test.
    show_character_screen();

//?? --
    void* a = malloc(sizeof(struct array));
    initialize_array(a);

    void* c = (void*) "test_signal";
    void* c2 = (void*) "test_signal_2";
    int i = 0;
    int j = 1;
    set_array_element(a, (void*) &i, c);
    set_array_element(a, (void*) &j, c2);
    void* result = get_array_element(a, (void*) &i);
    void* result2 = get_array_element(a, (void*) &j);
    puts("result: ");
    puts((char*) result);
    puts((char*) result2);

    finalize_array(a);
    free(a);

    return 0;
//?? --
    
    if (p1 != 0) {

        if ((p0 == 3) && (p1[1] != 0) && (p1[2] != 0)) {

/*??
            // XML parser.
            xml_parser = new org.apache.xerces.parsers.DOMParser();
            initialize_xml_parser(xml_parser);
*/

            // Signal memory (signal queue).
            void* signal_memory = malloc(sizeof(struct map));
            initialize_map(signal_memory);

/*??
            // Event handler.
            JavaEventHandler.signal_memory = signal_memory;
            int event_handler = new JavaEventHandler();
            JavaEventHandler.set_event_handler(event_handler);
*/

            // Create signal for storage in signal memory.
            // It will get destroyed (freed) when received by signal handler.
            struct signal* tmp = (struct signal*) malloc(sizeof(struct signal));

            if (tmp != 0) {

                log((void*) &INFO_LOG_LEVEL, "Send signal: ");
                log((void*) &INFO_LOG_LEVEL, p1[1]);

                // Set signal elements.
                tmp->priority = (void*) &NORMAL_PRIORITY;
                tmp->language = (void*) &NEURO_LANGUAGE;
                tmp->predicate = (void*) p1[1];
                tmp->object = (void*) p1[2];

                // Caution! Adding of signals must be synchronized between:
                // - send for adding internal CYBOP signals
                // - JavaEventHandler.dispatchEvent for adding transformed java event signals
                // These are the only procedures accessing the signal
                // memory for adding signals.
//??                synchronized (signal_memory) {

                    // Add signal to signal memory (interrupt vector table).
                    add_map_element(signal_memory, (void*) SIGNAL, (void*) tmp);

/*??
                    struct signal* tmp = 0;
                    int i = 0;
                    get_map_element_at_index(signal_memory, (void*) &i, (void*) tmp);
                    if (tmp != 0) {
                        puts("o.k.");
                    } else {
                        puts("null");
                    }
*/

//??                }

            } else {

                log((void*) &ERROR_LOG_LEVEL, "Could not send initial signal. The signal is null.");
            }

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            wait(signal_memory);
            // The loop above is left as soon as its shutdown flag is set.

/*??
            // Event handler.
            JavaEventHandler.remove_event_handler(event_handler);
            event_handler = 0;
            JavaEventHandler.signal_memory = 0;
*/

            // Signal memory (signal queue).
            finalize_map(signal_memory);
            free(signal_memory);

/*??
            // XML parser.
            finalize_xml_parser(xml_parser);
            xml_parser = 0;
*/

            log((void*) &INFO_LOG_LEVEL, "Exit CYBOI normally.");

            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

            log((void*) &ERROR_LOG_LEVEL, "Could not execute CYBOI. The command line parameters are incorrect.");

            show_usage_information();
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not execute CYBOI. The argument vector is null.");
    }

    return r;
}

