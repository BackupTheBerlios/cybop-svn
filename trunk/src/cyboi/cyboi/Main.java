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

/**
 * This is the main class of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * It contains a static main method to execute the interpreter.
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) format.
 *
 * @version $Revision: 1.26 $ $Date: 2003-08-11 19:30:40 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class Main {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer an Object into a byte[]

    /*
     * The main entry procedure.
     *
     * @param args the arguments
     */
    public static void main(java.lang.String[] args) {

        try {

            if (args != null) {

                if (args.length == 2) {

                    // Arguments.
                    java.lang.Object statics_category_name = args[0];
                    java.lang.Object dynamics_category_name = args[1];

                    // XML parser.
                    CategoryHandler.xml_parser = new org.apache.xerces.parsers.DOMParser();
                    CategoryHandler.initialize_xml_parser(CategoryHandler.xml_parser);
                    
                    // Statics (system).
                    java.lang.Object statics = ItemHandler.create_object(statics_category_name, Statics.CATEGORY);

                    // Dynamics (signal).
                    java.lang.Object dynamics = ItemHandler.create_object(SignalHandler.SIGNAL_CATEGORY_NAME, Dynamics.CATEGORY);

                    // Memory (signal queue).
                    java.lang.Object signal_memory = new Map();
                    MapHandler.initialize_map(signal_memory);

                    // Event handler.
                    EventHandler.signal_memory = signal_memory;
                    java.lang.Object event_handler = new EventHandler();
                    EventHandler.replaceEventQueue(event_handler);

                    // The system is now started up and complete so that a loop
                    // can be entered, waiting for signals (events/ interrupts)
                    // which are stored/ found in the signal memory.
                    Main.await(signal_memory, dynamics);
    
                    // The loop above is left as soon as its shutdown flag is set.
    
                    // Event handler.
                    event_handler = null;
                    EventHandler.signal_memory = null;
                    
                    // Memory (signal queue).
                    MapHandler.finalize_map(signal_memory);
                    signal_memory = null;

                    // Dynamics (signal).
                    // Abstraction is set to null because it is not wanted to write
                    // and change the signal category CYBOL file.
                    ItemHandler.destroy_object(dynamics, SignalHandler.SIGNAL_CATEGORY_NAME, null);

                    // Statics (system).
                    ItemHandler.destroy_object(statics, statics_category_name, Statics.CATEGORY);

                    // XML parser.
                    CategoryHandler.finalize_xml_parser(CategoryHandler.xml_parser);
                    CategoryHandler.xml_parser = null;

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
     * @param p1 the signal
     */
    static void await(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        // The shutdown flag.
        boolean sf = false;
    
        while (true) {

            if (sf != true) {

                // Receive signal.
                SignalHandler.receive(p0, p1);
    
                // Handle signal.
                sf = SignalHandler.handle(p1, 0);
    
                // Send signal.
                SignalHandler.send(p0, p1);
    
                // Reset signal.
                SignalHandler.reset(p1);
                
            } else {
                
                // Leave loop if the shutdown flag was set.
                break;
            }
        }
    }

//?? ===================================================

    //
    // Orientations.
    //

    /** The 0 degree orientation. */
    static java.lang.String DEGREE_0_ORIENTATION = "0_degree_orientation";

    /** The 90 degree orientation. */
    static java.lang.String DEGREE_90_ORIENTATION = "90_degree_orientation";

    /** The 180 degree orientation. */
    static java.lang.String DEGREE_180_ORIENTATION = "180_degree_orientation";

    /** The 270 degree orientation. */
    static java.lang.String DEGREE_270_ORIENTATION = "270_degree_orientation";

    //
    // Child positionings.
    //

    /** The compass positioning. */
    static java.lang.String COMPASS_POSITIONING = "compass_positioning";

    /** The box positioning. */
    static java.lang.String BOX_POSITIONING = "box_positioning";

    /** The card positioning. */
    static java.lang.String CARD_POSITIONING = "card_positioning";

    /** The grid bag positioning. */
    static java.lang.String GRID_BAG_POSITIONING = "grid_bag_positioning";
}

