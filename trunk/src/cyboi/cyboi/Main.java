/*
 * $RCSfile: Main.java,v $
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

package cyboi;

//?? import java.io.*;
//?? import org.apache.xerces.dom.*;
//?? import org.apache.xerces.parsers.*;
//?? import org.apache.xml.serialize.*;
//?? import org.w3c.dom.*;

/**
 * This is the main class of the <i>Cybernetics Oriented Interpreter</i> (CYBOI).<br><br>
 *
 * It contains a static <i>main</i> method to execute the interpreter.
 *
 * CYBOI can interpret <i>Cybernetics Oriented Language</i> (CYBOL) files,
 * which adhere to the <i>Extended Markup Language</i> (XML) format.
 *
 * @version $Revision: 1.15 $ $Date: 2003-07-25 23:47:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Main {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a Object into a byte[]

    /*
     * The main method.
     *
     * @param args the arguments
     */
    public static void main(java.lang.String[] args) {

        try {

            if (args != null) {

                if (args.length == 2) {

                    // Arguments.
                    java.lang.Object statics_category = args[0];
                    java.lang.Object dynamics_category = args[1];
                    java.lang.Object signal_category = "cybol/core/signal/signal";

                    // XML parser.
                    ItemHandler.xml_parser = ItemHandler.create_xml_parser();

                    // Event handler.
                    java.lang.Object event_handler = Main.create_event_handler();
                    Main.replaceEventQueue(event_handler);

                    // Signal memory.
                    java.lang.Object signal_memory = MapHandler.create_map();

                    // Statics.
                    java.lang.Object statics = ItemHandler.create_item();
                    ItemHandler.initialize(statics, statics_category);

/*??
                    // Dynamics.
                    java.lang.Object dynamics = ItemHandler.create_item();
                    ItemHandler.initialize(dynamics, dynamics_category);
*/

                    // Signal.
                    java.lang.Object signal = ItemHandler.create_item();
                    ItemHandler.initialize(signal, signal_category);

                    // Shutdown flag.
                    SignalHandler.shutdown_flag = 0;

                    // Alternative to Java Event Handler
                    // (if it gets replaced one day, once CYBOI is implemented in C):
                    // Enter waiting loop and read events (IRQs) from devices (IVT?).
    
                    // The system is now started up and complete so that a loop
                    // can be entered, waiting for signals (events/ interrupts).
                    Main.await(signal);
    
                    // The loop above is left as soon as the shutdown flag is set.
    
                    // Signal.
                    ItemHandler.finalizz(signal, signal_category);
                    ItemHandler.destroy_item(signal);
                    
/*??
                    // Dynamics.
                    ItemHandler.finalizz(dynamics, dynamics_category);
                    ItemHandler.destroy_item(dynamics);
*/

                    // Statics.
                    ItemHandler.finalizz(statics, statics_category);
                    ItemHandler.destroy_item(statics);

                    // Signal memory.
                    MapHandler.destroy_map(signal_memory);

                    // Event handler.
                    Main.destroy_event_handler(event_handler);

                    // XML parser.
                    ItemHandler.destroy_xml_parser(ItemHandler.xml_parser);
                    ItemHandler.xml_parser = null;
    
                    //
                    // Runtime.getRuntime().exit(0);
                    // and
                    // System.exit(0);
                    // do the same thing.
                    // The program exits normally, when the last non-daemon thread exits.
                    //
                    java.lang.System.out.println("INFO: Exit cyboi normally.");
                    java.lang.System.exit(0);

                } else {
    
                    // Help information.
                    java.lang.System.out.println("Usage:\n"
                        + "startup_cyboi cybol/core/system/system workflow");
                }

            } else {

                java.lang.System.out.println("ERROR: Could not execute cyboi. The argument array is null.");
            }

        } catch (Exception e) {

            //
            // Runtime.getRuntime().exit(0);
            // and
            // System.exit(0);
            // do the same thing.
            // The system exits normally, when the last non-daemon thread exits.
            // Since an exception was caught here, the system exits unnormally.
            //
            java.lang.System.out.println("ERROR: Exit cyboi unnormally. Undiscovered exception:\n");
            e.printStackTrace();
            java.lang.System.exit(1);
        }
    }

    //
    // Event handler.
    //
    
    /**
     * Creates an event handler.
     *
     * @return the event handler
     */
    static java.lang.Object create_event_handler() throws java.lang.Exception {

        return new EventHandler();
    }

    /**
     * Destroys the event handler.
     *
     * @param h the event handler
     */
    static void destroy_event_handler(java.lang.Object h) {
    }

    /**
     * Replaces the event queue with the event handler.
     *
     * @param h the event handler
     */
    static void replaceEventQueue(java.lang.Object h) {

        // Start the awt event thread by calling getDefaultToolkit().
        // Otherwise, the event thread is started by calling the show method
        // on a java awt frame.
        java.awt.Toolkit t = java.awt.Toolkit.getDefaultToolkit();

        if (t != null) {

            java.awt.EventQueue q = t.getSystemEventQueue();

            if (q != null) {

                // Replace the system event queue with the event handler.
                q.push((EventHandler) h);

            } else {

                java.lang.System.out.println("ERROR: Could not replace event queue. The event queue is null.");
            }

        } else {

            java.lang.System.out.println("ERROR: Could not replace event queue. The java awt toolkit is null.");
        }
    }
    
    /**
     * Waits for signals.
     *
     * @param s the signal
     */
    static void await(java.lang.Object s) {

        while (true) {

            // Check shutdown flag.
            if (SignalHandler.shutdown_flag == 1) {

                break;
            }

            // Receive signal.
            SignalHandler.receive(s);

            // Handle signal.
            SignalHandler.handle(s, 0);

            // Send signal.
            SignalHandler.send(s);

            // Reset signal.
            SignalHandler.reset(s);
        }
    }
}

