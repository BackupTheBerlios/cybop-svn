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
 * @version $Revision: 1.23 $ $Date: 2003-09-09 14:37:26 $ $Author: christian $
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
    static Item statics;

    /** The dynamics. */
    static Item dynamics;

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

                if (a.equals("mouse_moved")) {

/*?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
                    Item statics = SignalHandler.statics;
                    
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                    ItemHandler.set_item_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");
*/

                    SignalHandler.reset(s);

                } else if (a.equals("mouse_clicked")) {

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
                    
                    // Root (statics).
                    SignalHandler.statics = (Item) ItemHandler.create_object(s.object, Statics.CATEGORY);

                    SignalHandler.reset(s);
                    
                    s.predicate = SignalHandler.SEND_ACTION;
                    s.object = MapHandler.get_map_element(((Item) statics).items, "main_frame");

                } else if (a.equals(SignalHandler.SHUTDOWN_ACTION)) {
                    
                    // Root (statics).
                    ItemHandler.destroy_object(SignalHandler.statics, s.object, Statics.CATEGORY);
                    sf = true;

                    SignalHandler.reset(s);
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
                        MapHandler.add_map_element(p0, SignalHandler.SIGNAL, tmp);
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
    
    //
    // Signal handling.
    //
    
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

            // Only set this screen item's action if it exists.
            // Otherwise, the previously set action of the parent screen item
            // remains untouched and will be returned.
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
            java.lang.Object width = null;
            java.lang.Object height = null;
            java.lang.Object depth = null;
            boolean contains = false;
            
            while (count < size) {

                // Determine child and its position within the given screen item.
                child = MapHandler.get_map_element(i.items, count);
                position = MapHandler.get_map_element(i.positions, count);
                
                // Translate the given coordinates according to the child's position.
                x = SignalHandler.subtract(p1, ItemHandler.get_item_element(position, "x_distance.quantity"));
                y = SignalHandler.subtract(p2, ItemHandler.get_item_element(position, "y_distance.quantity"));
                z = SignalHandler.subtract(p3, ItemHandler.get_item_element(position, "z_distance.quantity"));
                
                // Determine child's expansion.
                width = ItemHandler.get_item_element(child, "expansion.x_distance.quantity");
                height = ItemHandler.get_item_element(child, "expansion.y_distance.quantity");
                depth = ItemHandler.get_item_element(child, "expansion.z_distance.quantity");

                // Check if the given coordinates are in the child's screen area.
                // The "if" conditions had to be inserted because in classical
                // graphical user interfaces, the depth is normally 0 and
                // such the boolean comparison would deliver "false".
                // Using the conditions, the coordinates that are set to "0"
                // are not considered for comparison.
                contains = SignalHandler.greater_or_equal(x, new java.lang.Integer(0));
                contains = SignalHandler.and(contains, SignalHandler.smaller(x, width));
                contains = SignalHandler.and(contains, SignalHandler.greater_or_equal(y, new java.lang.Integer(0)));
                contains = SignalHandler.and(contains, SignalHandler.smaller(y, height));
                //?? contains = SignalHandler.and(contains, SignalHandler.greater_or_equal(z, new java.lang.Integer(0)));
                //?? contains = SignalHandler.and(contains, SignalHandler.smaller(z, depth));

                if (contains == true) {

                    // The given coordinates are in the child's screen area.
                    // Therefore, use the child's action.
                    a = SignalHandler.mouse_clicked_action(child, x, y, z);
                }
            }
    
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The item is null.");
        }
        
        return a;
    }

    //
    // Algebra.
    //

    /**
     * Adds the parameters.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return the sum
     */
    static java.lang.Object add(java.lang.Object p0, java.lang.Object p1) {

        java.lang.Object sum = null;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;
        
        if (i0 != null) {

            if (i1 != null) {

                sum = new java.lang.Integer(i0.intValue() + i1.intValue());

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add. The first parameter is null.");
        }
        
        return sum;
    }

    /**
     * Subtracts the parameters.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return the difference
     */
    static java.lang.Object subtract(java.lang.Object p0, java.lang.Object p1) {

        java.lang.Object difference = null;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;
        
        if (i0 != null) {

            if (i1 != null) {

                difference = new java.lang.Integer(i0.intValue() - i1.intValue());

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not subtract. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not subtract. The first parameter is null.");
        }
        
        return difference;
    }

    /**
     * Multiplies the parameters.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return the product
     */
    static java.lang.Object multiply(java.lang.Object p0, java.lang.Object p1) {

        java.lang.Object product = null;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;
        
        if (i0 != null) {

            if (i1 != null) {

                product = new java.lang.Integer(i0.intValue() * i1.intValue());

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not multiply. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not multiply. The first parameter is null.");
        }
        
        return product;
    }

    /**
     * Divides the parameters.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return the integer quotient (without rest)
     */
    static java.lang.Object divide(java.lang.Object p0, java.lang.Object p1) {

        java.lang.Object quotient = null;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;
        
        if (i0 != null) {

            if (i1 != null) {

                quotient = new java.lang.Integer(i0.intValue() / i1.intValue());
                //?? Rest of integer division is determined with:
                //?? rest = new java.lang.Integer(i0.intValue() % i1.intValue());

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not divide. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not divide. The first parameter is null.");
        }
        
        return quotient;
    }

    /**
     * Compares if this integer is dividable by the integer without rest.
     *
     * @param i the integer
     * @return true - if this integer is dividable by the integer without rest;
     * false - otherwise
     */
/*??
    static boolean isDividableWithoutRest(Integer i) {

        boolean result = Boolean.FALSE;
        
        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    int rest = j1.intValue() % j2.intValue();

                    if (rest == 0) {
                        
                        result = Boolean.TRUE;
                    }

                } else {
                    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not divide integer. This java integer 1 is null.");
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not divide integer. The java integer 2 is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not divide integer. The integer is null.");
        }
        
        return result;
    }

    /**
     * Returns the absolute value (without sign) of this integer.
     *
     * @return the absolute value (without sign) of this integer
     */
/*??
    static Integer absolute() {

        Integer abs = null;
        
/*??
        java.lang.Integer j = (java.lang.Integer) getJavaObject();

        if (j != null) {
            
            int i = abs(j.intValue());
            abs = new java.lang.Integer(i);

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not determine absolute value. The java integer is null.");
        }
*/
/*??

        return abs;
    }

    //
    // Comparison.
    //
    
    /**
     * Compares if the first parameter is equal to the second parameter.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return true if equal; false otherwise
     */
    static boolean equal(java.lang.Object p0, java.lang.Object p1) {

        boolean result = false;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;

        if (i0 != null) {

            if (i1 != null) {

                if (i0.intValue() == i1.intValue()) {

                    result = true;
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare equal. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare equal. The first parameter is null.");
        }

        return result;        
    }

    /**
     * Compares if the first parameter is smaller than the second parameter.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return true if smaller; false otherwise
     */
    static boolean smaller(java.lang.Object p0, java.lang.Object p1) {

        boolean result = false;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;

        if (i0 != null) {

            if (i1 != null) {

                if (i0.intValue() < i1.intValue()) {

                    result = true;
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare smaller. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare smaller. The first parameter is null.");
        }

        return result;        
    }

    /**
     * Compares if the first parameter is greater than the second parameter.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return true if greater; false otherwise
     */
    static boolean greater(java.lang.Object p0, java.lang.Object p1) {

        boolean result = false;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;

        if (i0 != null) {

            if (i1 != null) {

                if (i0.intValue() > i1.intValue()) {

                    result = true;
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare greater. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare greater. The first parameter is null.");
        }

        return result;        
    }
    
    /**
     * Compares if the first parameter is smaller than or equal to the second parameter.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return true if smaller or equal; false otherwise
     */
    static boolean smaller_or_equal(java.lang.Object p0, java.lang.Object p1) {

        boolean result = false;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;

        if (i0 != null) {

            if (i1 != null) {

                if (i0.intValue() <= i1.intValue()) {

                    result = true;
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare smaller or equal. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare smaller or equal. The first parameter is null.");
        }

        return result;        
    }
    
    /**
     * Compares if the first parameter is greater than or equal to the second parameter.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return true if greater or equal; false otherwise
     */
    static boolean greater_or_equal(java.lang.Object p0, java.lang.Object p1) {

        boolean result = false;
        java.lang.Integer i0 = (java.lang.Integer) p0;
        java.lang.Integer i1 = (java.lang.Integer) p1;

        if (i0 != null) {

            if (i1 != null) {

                if (i0.intValue() >= i1.intValue()) {

                    result = true;
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare greater or equal. The second parameter is null.");
            }
                
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not compare greater or equal. The first parameter is null.");
        }

        return result;        
    }

    //
    // Bool operations.
    //
    
    /**
     * Logical AND.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return the boolean result
     */
    static boolean and(boolean p0, boolean p1) {

        return p0 && p1;
    }
    
    /**
     * Logical OR.
     *
     * @param p0 the first parameter
     * @param p1 the second parameter
     * @return the boolean result
     */
    static boolean or(boolean p0, boolean p1) {

        return p0 || p1;
    }
}

