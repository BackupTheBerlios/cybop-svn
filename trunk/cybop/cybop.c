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

/*??
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
*/

#include <stdlib.h>
#include "log_handler.c"
#include "map.c"
#include "map_handler.c"
#include "signal.c"
#include "signal_handler.c"

/**
 * This is the main function to execute the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.3 $ $Date: 2003-09-26 06:59:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * The main entry function.
 *
 * @param p0 the argument count (argc)
 * @param p1 the argument vector (argv)
 * @return the return value
 */
int main(int p0, char** p1) {

    // Return 1 to indicate an error, by default.
    int r = 1;

    if (p1 != 0) {

        if ((p0 == 3) && (p1[1] != 0) && (p1[2] != 0)) {

            // Arguments.
            void* dynamics = (void*) p1[1];
            void* statics = (void*) p1[2];

            // Log handler.
            log_level = 3;

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
            struct signal* tmp = (struct signal*) malloc(sizeof(struct signal));

            if (tmp != 0) {

                log(INFO_LOG_LEVEL, "Send signal: " + dynamics);

                // Set signal elements.
                tmp->priority = NORMAL_PRIORITY;
                tmp->language = NEURO_LANGUAGE;
                tmp->predicate = dynamics;
                tmp->object = statics;

/*??
                // Caution! Adding of signals must be synchronized between:
                // - send for adding internal CYBOP signals
                // - JavaEventHandler.dispatchEvent for adding transformed java event signals
                // These are the only procedures accessing the signal
                // memory for adding signals.
                synchronized (signal_memory) {

                    // Add signal to signal memory (interrupt vector table).
                    add_map_element(signal_memory, SIGNAL, tmp);
                }
*/

            } else {

                log(ERROR_LOG_LEVEL, "Could not send initial signal. The signal is null.");
            }

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
//??            await(signal_memory);
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

            log(INFO_LOG_LEVEL, "Exit cyboi normally.");
            // Return 0 to indicate proper shutdown.
            r = 0;

        } else {

            // Show help information.
            log(ERROR_LOG_LEVEL, "Usage:\n\
                cyboi startup cybol.core.system.system");
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not execute cyboi. The argument vector is null.");
    }

    return r;
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
void await(void* p0) {

    // The shutdown flag.
    int sf = 0;
    // Transporting signal.
    void* s = malloc(sizeof(struct signal));

    // Run endless loop handling any signals.
    while (1) {

        if (sf == 0) {

            // Receive signal.
            receive_signal(p0, s);

            // Handle signal.
            sf = handle_signal(s, 0);

            // Send signal.
            send_signal(p0, s);

            // Reset signal.
            reset_signal(s);

        } else {

            // Leave loop if the shutdown flag was set.
            break;
        }
    }
}

