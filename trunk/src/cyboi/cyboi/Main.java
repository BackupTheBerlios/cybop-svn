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
 * @version $Revision: 1.12 $ $Date: 2003-07-24 09:46:18 $ $Author: christian $
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

                    java.lang.String statics_category = args[0];
                    java.lang.String dynamics_category = args[1];

                    ItemHandler.xml_parser = ItemHandler.create_xml_parser();

                    java.lang.Object event_handler = Main.create_event_handler();
                    Main.replaceEventQueue(event_handler);

                    java.lang.Object signal_memory = MapHandler.create_map_container();

                    java.lang.Object statics = ItemHandler.create_item_container();
                    ItemHandler.initialize(statics, statics_category);

/*??
                    java.lang.Object dynamics = ItemHandler.create_item_container();
                    ItemHandler.initialize(dynamics, dynamics_category);
*/

                    // Alternative to Java Event Handler
                    // (if it gets replaced one day, once CYBOI is implemented in C):
                    // Enter waiting loop and read events (IRQs) from devices (IVT?).
    
                    // The system is now started up and complete so that a loop
                    // can be entered, waiting for signals (events).
                    Main.await();
    
                    // The loop above is left as soon as the shutdown flag is set.
    
/*??
                    ItemHandler.finalizz(dynamics, dynamics_category);
                    ItemHandler.destroy_item_container(dynamics);
*/

                    ItemHandler.finalizz(statics, statics_category);
                    ItemHandler.destroy_item_container(statics);

                    MapHandler.destroy_map_container(signal_memory);
                    Main.destroy_event_handler(event_handler);
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
    
                    java.lang.System.out.println("ERROR: Could not execute cyboi. The argument array length is unequal to two.");
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
     */
    static void await() {

/*??
        Signal s = (Signal) createChild(getCategory(Launcher.SIGNAL));
        //?? Temporary for handling signals which stem from java event queue.
        Signal queued = null;
        Boolean b = null;

        while (true) {

            // Check shutdown flag.
            b = (Boolean) getChild(Launcher.SHUTDOWN_FLAG);

            if (b != null) {

                if (b.isEqualTo(Boolean.TRUE)) {

                    break;
                }

            } else {

                java.lang.System.out.println("Could not wait for signals. The shutdown flag is null.");
            }

            queued = fetchSignal();

            if (queued != null) {

                //?? Temporary code block for handling of signals that came from the
                //?? java event queue and were stored in the signal memory.
                //?? These signals were created outside this method but must be
                //?? destroyed here!

                java.lang.java.lang.System.out.println("DEBUG: Handle signal " + queued.getName().getJavaObject() + " with action: " + ((java.lang.String) queued.getChild(Signal.PREDICATE)).getJavaObject());
                handle(queued, new Boolean(Boolean.FALSE));

                java.lang.java.lang.System.out.println("DEBUG: Send signal " + queued.getName().getJavaObject() + " with action: " + ((java.lang.String) queued.getChild(Signal.PREDICATE)).getJavaObject());
                send(queued);

                destroyChild(queued);

            } else {

/*??
                // Check for changed flags on computer (currently done by operating system),
                // e.g. to receive a keyboard or mouse event and then create a CYBOP signal of it.
                receive(s);
                // Handle the signal by sending it through the whole system.
                handle(s, new Boolean(Boolean.FALSE));
                // After having handled the signal in this system, its answer will be sent -
                // again by changing flags on the computer (done by operating system),
                // e.g. a gui drawn onto the screen, a printout or a network message.
                send(s);

                if (s != null) {
                    
                    s.resetChild();
        
                } else {
        
                    java.lang.System.out.println("Could not reset signal. The signal is null.");
                }
*/
/*??
            }
        }

        destroyChild(s);
*/
    }
}

