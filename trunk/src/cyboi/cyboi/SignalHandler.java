/*
 * $RCSfile: SignalHandler.java,v $
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
 * This is a signal handler.
 *
 * It offers signal processing procedures which should be called in the following order:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @version $Revision: 1.22 $ $Date: 2003-09-08 14:58:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class SignalHandler {

    //
    // Constants.
    //

    /** The signal. */
    static java.lang.String SIGNAL = "signal";

    //
    // Priorities.
    //

    /** The normal priority. */
    static java.lang.String NORMAL_PRIORITY = "1";

    //
    // Languages.
    //

    /** The system internal (neuro) language. */
    static java.lang.String NEURO_LANGUAGE = "neuro";

    /** The textual user interface (tui) language. */
    static java.lang.String TUI_LANGUAGE = "tui";

    /** The mouse language. */
    static java.lang.String MOUSE_LANGUAGE = "mouse";

    /** The graphical user interface (gui) language. */
    static java.lang.String GUI_LANGUAGE = "gui";

    /** The socket language. */
    static java.lang.String SOCKET_LANGUAGE = "socket";

    /** The structured query language (sql). */
    static java.lang.String SQ_LANGUAGE = "sq";

    /** The java messaging service (jms) language. */
    static java.lang.String JMS_LANGUAGE = "jms";

    /** The remote method invocation (rmi) language. */
    static java.lang.String RMI_LANGUAGE = "rmi";

    /** The common object request broker architecture (corba) language. */
    static java.lang.String CORBA_LANGUAGE = "corba";

    /** The extensible markup language (xml). */
    static java.lang.String XML_LANGUAGE = "xml";

    /** The simple object access protocol (soap) language. */
    static java.lang.String SOAP_LANGUAGE = "soap";

    //
    // Actions.
    //

    /** The show system information action. */
    static java.lang.String SHOW_SYSTEM_INFORMATION_ACTION = "show_system_information";

    /** The startup action. */
    static java.lang.String STARTUP_ACTION = "startup";

    /** The shutdown action. */
    static java.lang.String SHUTDOWN_ACTION = "shutdown";
    
    /** The receive action. */
    static java.lang.String RECEIVE_ACTION = "receive";

    /** The send action. */
    static java.lang.String SEND_ACTION = "send";

    //
    // Attributes.
    //

    /** The statics. */
    static java.lang.Object statics;

    /** The dynamics. */
    static java.lang.Object dynamics;

    //
    // Signal.
    //
    
    /**
     * Receives the signal.
     *
     * The JDK sends java.awt.AWTEvent events.
     * The EventHandler catches these events in the EventHandler.dispatchEvent method,
     * transforms them into CYBOP signals and stores them in the signal memory.
     *
     * This method:
     * - gets the top priority signal from the signal memory and removes it from there
     * - copies that signal memory signal to the transporting signal handed over as parameter
     *
     * The idea is that one day, signals (interrupts) might be read from the
     * interrupt vector table.
     * Currently, the operating system checks for changed flags on the computer,
     * to receive for example keyboard or mouse events.
     *
     * @param p0 the signal memory
     * @param p1 the signal
     */
    static void receive(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Signal s = (Signal) p1;
        
        if (s != null) {

            // Read and remove signal from signal memory (interrupt vector table).
            Signal tmp = (Signal) MapHandler.get_map_element(p0, 0);
            MapHandler.remove_map_element(p0, 0);
            
            if (tmp != null) {
            
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Receive signal: " + tmp.predicate);

                // Copy signal memory signal to the transporting signal given as parameter.
                s.priority = tmp.priority;
                s.language = tmp.language;
                s.subject = tmp.subject;
                s.predicate = tmp.predicate;
                s.owner = tmp.owner;
                s.sender = tmp.sender;
                s.object = tmp.object;
                s.adverbial = tmp.adverbial;
                s.condition = tmp.condition;

                // Reset and destroy signal memory signal.
                SignalHandler.reset(tmp);
                tmp = null;
        
            } else {
    
                // No signal was received.
                // Do not log this as the loop runs infinite and would stuff the log record.
            }
    
        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not receive signal. The signal is null.");
        }
    }

    /**
     * Handles the signal.
     *
     * @param p0 the signal
     * @param p1 the remote flag
     * @return the shutdown flag
     */
    static boolean handle(java.lang.Object p0, int p1) throws java.lang.Exception {

        boolean sf = false;
        Signal s = (Signal) p0;
                
        if (s != null) {

            java.lang.Object a = s.predicate;

            if (a != null) {

                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Handle signal: " + a);

                if (a.equals(JavaEventHandler.MOUSE_MOVED_EVENT)) {

/*?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
                    Item statics = SignalHandler.statics;
                    
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");
*/

                    SignalHandler.reset(s);

                } else if (a.equals(JavaEventHandler.MOUSE_CLICKED_EVENT)) {

                    Item statics = SignalHandler.statics;
                    java.lang.Object main_frame = ItemHandler.get_item_element(statics, "main_frame");
                    java.lang.Object x = ItemHandler.get_item_element(statics, "mouse.pointer_position.x_distance.quantity");
                    java.lang.Object y = ItemHandler.get_item_element(statics, "mouse.pointer_position.y_distance.quantity");
                    java.lang.Object z = ItemHandler.get_item_element(statics, "mouse.pointer_position.z_distance.quantity");

                    SignalHandler.reset(s);
                    s.predicate = SignalHandler.mouse_clicked_action(main_frame, x, y, z);

                } else if (a.equals(SignalHandler.SHOW_SYSTEM_INFORMATION_ACTION)) {

/*??
                    encode("system.controller.system_information_screen_model");
                    
                    show();
*/
                    
                    SignalHandler.reset(s);

/*??
                } else if (a.equals(SignalHandler.RECALL_PATIENT_ACTION)) {
                    
                    SignalHandler.reset(s);

                } else if (a.equals(SignalHandler.REMEMBER_PATIENT_ACTION)) {
                    
                    SignalHandler.reset(s);

*/
                } else if (a.equals(SignalHandler.SEND_ACTION)) {
                    
                    Item o = (Item) s.object;

                    if (o != null) {
                        
                        java.lang.Object j = o.java_object;

                        if (j != null) {
                            
                            if (j instanceof java.awt.Component) {
                                
                                ((java.awt.Component) j).setVisible(true);
                            
                            } else {
                                
                                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not handle send action. The java object is not a component.");
                            }
                    
                        } else {
                            
                            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not handle send action. The java object is null.");
                        }
                    
                    } else {
                        
                        LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not handle send action. The signal object is null.");
                    }

                    SignalHandler.reset(s);
                    
                } else if (a.equals(SignalHandler.STARTUP_ACTION)) {
                    
                    SignalHandler.reset(s);
                    
                    // Root (statics).
                    SignalHandler.root = ItemHandler.create_object(s.object, Statics.CATEGORY);
                    s.predicate = SignalHandler.SEND_ACTION;
                    s.object = MapHandler.get_map_element(((Item) statics).items, "main_frame");

                } else if (a.equals(SignalHandler.SHUTDOWN_ACTION)) {
                    
                    SignalHandler.reset(s);

                    // Root (statics).
                    ItemHandler.destroy_object(SignalHandler.statics, s.object, Statics.CATEGORY);
                    sf = true;
                }
                
            } else {
    
                // The signal is empty and does not contain an action.
                // Do not log this as the loop runs infinite and would stuff the log record.
            }
    
        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not handle signal. The signal is null.");
        }
        
        return sf;
    }

    /**
     * Sends the signal.
     *
     * If a signal's action is null, it will get destroyed.
     * Otherwise, the signal will be stored in the signal memory for further
     * handling.
     *
     * @param p0 the signal memory
     * @param p1 the signal
     */
    static void send(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Signal s = (Signal) p1;
        
        if (s != null) {

            // Only send a new signal (store in signal memory) if an action exists.
            // Otherwise, the chain of signals/ actions finishes here, until a new
            // hardware event (interrupt) occurs.
            if (s.predicate != null) {
                
                // Create signal for storage in signal memory.
                Signal tmp = new Signal();
        
                if (tmp != null) {
                
                    LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Send signal: " + s.predicate);

                    // Copy transporting signal given as parameter to the signal memory signal.
                    tmp.priority = s.priority;
                    tmp.language = s.language;
                    tmp.subject = s.subject;
                    tmp.predicate = s.predicate;
                    tmp.owner = s.owner;
                    tmp.sender = s.sender;
                    tmp.object = s.object;
                    tmp.adverbial = s.adverbial;
                    tmp.condition = s.condition;

                    // Caution! Adding of signals must be synchronized between:
                    // - SignalHandler.send for adding internal CYBOP signals
                    // - JavaEventHandler.dispatchEvent for adding transformed java event signals
                    // These are the only procedures accessing the signal
                    // memory for adding signals.
                    synchronized (p0) {

                        // Add signal to signal memory (interrupt vector table).
                        MapHandler.add_map_element(p0, tmp, SignalHandler.SIGNAL);
                    }

                } else {
        
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not send signal. The signal memory signal is null.");
                }

            } else {
                
                // Do not log this as the loop runs infinite and would stuff the log record!
                // The action is null. No signal gets stored in the signal memory.
            }
    
        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not send signal. The signal is null.");
        }
    }

    /**
     * Resets the signal.
     *
     * @param p0 the signal
     */
    static void reset(java.lang.Object p0) {
        
        Signal s = (Signal) p0;
        
        if (s != null) {

            s.priority = null;
            s.language = null;
            s.subject = null;
            s.predicate = null;
            s.owner = null;
            s.sender = null;
            s.object = null;
            s.adverbial = null;
            s.condition = null;

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not reset signal. The signal is null.");
        }
    }
    
    //??
    //?? Temporary operations. To be replaced by CYBOL action files.
    //??
    
    /**
     * Handles the mouse clicked action.
     *
     * @param p0 the screen item
     * @param p1 the x coordinate
     * @param p2 the y coordinate
     * @param p3 the z coordinate
     * @return the action
     */
    static java.lang.Object mouse_clicked_action(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2, java.lang.Object p3) {

        java.lang.Object a = null;
        Item i = (Item) p0;
        
        if (i != null) {

            // Determine the action of the given screen item.
            java.lang.Object action = MapHandler.get_map_element(i.items, "mouse_clicked_action");
            
            if (action != null) {
                
                a = action;
            }

            // Determine the action of any child screen items and overwrite
            // the action of the parent screen item (set above) with it.
            int count = 0;
            int size = MapHandler.get_map_size(i.items);
            java.lang.Object child = null;
            java.lang.Object position = null;
            java.lang.Object x = null;
            java.lang.Object y = null;
            java.lang.Object z = null;
            boolean contains = false;
            
            while (count < size) {

                child = MapHandler.get_map_element(i.items, count);
                position = MapHandler.get_map_element(i.positions, count);
                x = SignalHandler.subtract(p1, ItemHandler.get_item_element(position, "x_distance.quantity"));
                y = SignalHandler.subtract(p2, ItemHandler.get_item_element(position, "y_distance.quantity"));
                z = SignalHandler.subtract(p3, ItemHandler.get_item_element(position, "z_distance.quantity"));
                width = ItemHandler.get_item_element(child, "expansion.x_distance.quantity");
                height = ItemHandler.get_item_element(child, "expansion.y_distance.quantity");
                depth = ItemHandler.get_item_element(child, "expansion.z_distance.quantity");

                //?? This list is a recursion of AND operations!
                contains = SignalHandler.is_greater_than_or_equal(x, new java.lang.Integer(0))
                    && SignalHandler.is_smaller_than(x, width)
                    && SignalHandler.is_greater_than_or_equal(y, new java.lang.Integer(0))
                    && SignalHandler.is_smaller_than(y, height)
                    && SignalHandler.is_greater_than_or_equal(z, new java.lang.Integer(0))
                    && SignalHandler.is_smaller_than(z, depth);

                if (contains == true) {
                
                    a = SignalHandler.mouse_clicked_action(child, x, y, z);
                }
            }
    
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The item is null.");
        }
        
        return a;
    }
    
    //?? Add primitive operations here! See old java code!
}

