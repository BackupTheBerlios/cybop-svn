/*
 * $RCSfile: main.c,v $
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

/**
 * This is the main class of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * It contains a main method to execute the interpreter.
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.2 $ $Date: 2003-09-17 18:45:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * The main entry procedure.
 *
 * @param argc the character arguments
 * @param argv the array
 * @return the return value
 */
int main(int argc, char[]* argv) {

    int r = -1;

    if (args != null) {

        if ((args.length == 2) && (args[0] != null) && (args[1] != null)) {

            // Arguments.
            java.lang.Object dynamics = args[0];
            java.lang.Object statics = args[1];

            // Log handler.
            LogHandler.log_level = 3;

            // XML parser.
            CategoryHandler.xml_parser = new org.apache.xerces.parsers.DOMParser();
            CategoryHandler.initialize_xml_parser(CategoryHandler.xml_parser);

            // Signal memory (signal queue).
            map* signal_memory = new map();
            MapHandler.initialize_map(signal_memory);

            // Event handler.
            JavaEventHandler.signal_memory = signal_memory;
            java.lang.Object event_handler = new JavaEventHandler();
            JavaEventHandler.set_event_handler(event_handler);

            // Create signal for storage in signal memory.
            Signal tmp = new Signal();

            if (tmp != null) {

                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Send signal: " + dynamics);

                // Set signal elements.
                tmp.priority = SignalHandler.NORMAL_PRIORITY;
                tmp.language = SignalHandler.NEURO_LANGUAGE;
                tmp.predicate = dynamics;
                tmp.object = statics;

                // Caution! Adding of signals must be synchronized between:
                // - SignalHandler.send for adding internal CYBOP signals
                // - JavaEventHandler.dispatchEvent for adding transformed java event signals
                // These are the only procedures accessing the signal
                // memory for adding signals.
                synchronized (signal_memory) {

                    // Add signal to signal memory (interrupt vector table).
                    MapHandler.add_map_element(signal_memory, SignalHandler.SIGNAL, tmp);
                }

            } else {

                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not send initial signal. The signal is null.");
            }

            // The system is now started up and complete so that a loop
            // can be entered, waiting for signals (events/ interrupts)
            // which are stored/ found in the signal memory.
            Main.await(signal_memory);
            // The loop above is left as soon as its shutdown flag is set.

            // Event handler.
            JavaEventHandler.remove_event_handler(event_handler);
            event_handler = null;
            JavaEventHandler.signal_memory = null;

            // Signal memory (signal queue).
            MapHandler.finalize_map(signal_memory);
            signal_memory = null;

            // XML parser.
            CategoryHandler.finalize_xml_parser(CategoryHandler.xml_parser);
            CategoryHandler.xml_parser = null;

            //
            // The program exits normally, when the last non-daemon thread exits.
            //
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Exit cyboi normally.");
            value = EXIT_SUCCESS;

        } else {

            // Show help information.
            java.lang.System.out.println("Usage:\n"
                + "cyboi startup cybol.core.system.system");
        }

    } else {

        LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not execute cyboi. The argument array is null.");
    }

    return value;
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
void await(map* p0) {

    // The shutdown flag.
    boolean sf = false;
    // Transporting signal.
    signal* s = new signal();

    while (true) {

        if (sf != true) {

            // Receive signal.
            SignalHandler.receive(p0, s);

            // Handle signal.
            sf = SignalHandler.handle(s, 0);

            // Send signal.
            SignalHandler.send(p0, s);

            // Reset signal.
            SignalHandler.reset(s);

        } else {

            // Leave loop if the shutdown flag was set.
            break;
        }
    }
}

