/*
 * $RCSfile: JavaEventHandler.java,v $
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
 * This is the java event handler.
 *
 * It dispatches java.awt.AWTEvent events, transforms them into CYBOI signals
 * and finally sends them through the whole system.
 *
 * Unfortunately, handling of most events is done via graphical components in java.
 *
 * @version $Revision: 1.7 $ $Date: 2003-08-18 17:30:07 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class JavaEventHandler extends java.awt.EventQueue {

    //
    // Events.
    //
    
    /** The mouse clicked event. */
    static java.lang.String MOUSE_CLICKED_EVENT = "mouse_clicked";

    /** The mouse moved event. */
    static java.lang.String MOUSE_MOVED_EVENT = "mouse_moved";

    //
    // Attributes.
    //
    
    /** The signal memory. */
    static java.lang.Object signal_memory;

    //
    // Event.
    //    

    /**
     * Dispatches an event.
     *
     * Example:
     * On clicking the mouse or a button, a hardware interrupt occurs.
     * The operating system catches this interrupt and transforms it
     * correctly into some meaningful piece of software code.
     * Device drivers are necessary to do this translation.
     * Now, all running processes are informed by the operating system.
     * In the case of Java processes (applications), the Java Virtual Machine (JVM)
     * (which is an application itself to the operating system) receives the events.
     * Finally, the JVM puts the events into the event queue of the
     * Abstract Windowing Toolkit (AWT).
     *
     * As we don't want to use event listeners and the like in CYBOP
     * (they are improper and unnecessarily complicated in our opinion -
     * as interfaces/ concerns/ aspects are, anyway),
     * we catch all events directly in the event queue, their first point
     * of occurence in the Java Development Kit (JDK) Class Hierarchy.
     *
     * The java events are transformed into a CYBOP signal which is then
     * stored in the signal memory.
     *
     * The AWT distinguishes between different types of events and filters
     * them out by comparing with "instanceof" - again improper.
     * As a rule of thumb, one should never use "instanceof" in
     * Object Oriented Programming (OOP) but rather rely on inheritance.
     * However, we have to use these events here but will transform them
     * into CYBOP signals which have a predicate which is a string that
     * identifies the signal's (event's) action.
     *
     * The following java awt methods might be of interest in understanding how
     * events are handled in the JDK and how clicked components are identified:
     * java.awt.EventDispatchThread::pumpOneEventForHierarchy(...);
     * java.awt.Toolkit::getSystemEventQueueImpl();
     * java.awt.Container::dispatchEvent(AWTEvent e);
     * java.awt.Container::getMouseEventTargetImpl();
     *
     * By the way, Java events can be posted using:
     * Toolkit.getEventQueue().postEvent(evt);
     *
     * @param evt the java awt event sent directly from the JVM to here
     */
    protected void dispatchEvent(java.awt.AWTEvent evt) {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Dispatch event: " + evt);

        //?? For now, we also call the AWT event handling.
        //?? Later, we will cut it off by removing this line.
        //?? I tried removing this line:
        //?? - the frame/window still gets created
        //?? - but no contents (menue and other components) is shown
        //?? Checking this out later.
        super.dispatchEvent(evt);

        try {

            // Create signal for storage in signal memory.
            Signal s = new Signal();
    
            if (s != null) {
    
                JavaEventHandler.transform_event(s, evt);
                
                if (s.predicate != null) {
                    
                    // Only send a new signal (store in signal memory) if an action exists.
                    // Otherwise, the chain of signals/ actions finishes here, until a new
                    // hardware event (interrupt) occurs.
    
                    // Caution! Adding of signals must be synchronized between
                    // SignalHandler.send and EventHandler.dispatchEvent!
                    // These are the only two procedures accessing the signal
                    // memory for adding signals.
                    // SignalHandler is for adding internal CYBOP signals.
                    // EventHandler is for adding transformed java event signals.
                    synchronized (JavaEventHandler.signal_memory) {

                        // Add signal to signal memory (interrupt vector table).
                        MapHandler.add_map_element(JavaEventHandler.signal_memory, s, SignalHandler.SIGNAL);
                    }

                } else {
                    
                    // The signal is empty and does not contain an action.
                    // Do not log this as the loop runs infinite and would stuff the log record.
                }
    
            } else {
    
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not dispatch event. The signal is null.");
            }

        } catch (Exception e) {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not dispatch event. An exception occured:\n" + e);
        }
    }

    /**
     * Transforms the java event into a CYBOP signal.
     *
     * @param p0 the signal
     * @param p1 the java event
     */
    static void transform_event(java.lang.Object p0, java.lang.Object p1) {

        Signal s = (Signal) p0;
        
        if (s != null) {
            
            s.priority = SignalHandler.NORMAL_PRIORITY;
            s.language = SignalHandler.NEURO_LANGUAGE;
//??            s.subject = Statics.SELF;

            java.awt.AWTEvent evt = (java.awt.AWTEvent) p1;
    
            if (evt != null) {
    
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Transform event.");
                
                int id = evt.getID();
    
/*??
                if (id == java.awt.event.ComponentEvent.COMPONENT_HIDDEN) {
    
                    a = Controller.COMPONENT_HIDDEN_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.ComponentEvent.COMPONENT_MOVED) {
    
                    a = Controller.COMPONENT_MOVED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.ComponentEvent.COMPONENT_RESIZED) {
    
                    a = Controller.COMPONENT_RESIZED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.ComponentEvent.COMPONENT_SHOWN) {
    
                    a = Controller.COMPONENT_SHOWN_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.FocusEvent.FOCUS_GAINED) {
    
                    a = Controller.FOCUS_GAINED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.FocusEvent.FOCUS_LOST) {
    
                    a = Controller.FOCUS_LOST_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.HierarchyEvent.ANCESTOR_MOVED) {
    
                    a = Controller.ANCESTOR_MOVED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.HierarchyEvent.ANCESTOR_RESIZED) {
    
                    a = Controller.ANCESTOR_RESIZED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.HierarchyEvent.HIERARCHY_CHANGED) {
    
                    a = Controller.HIERARCHY_CHANGED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.InputMethodEvent.CARET_POSITION_CHANGED) {
    
                    a = Controller.CARET_POSITION_CHANGED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.InputMethodEvent.INPUT_METHOD_TEXT_CHANGED) {
    
                    a = Controller.INPUT_METHOD_TEXT_CHANGED_ACTION;
                    l = Signal.NEURO_LANGUAGE;
    
                } else if (id == java.awt.event.KeyEvent.KEY_PRESSED) {
    
                    a = Controller.KEY_PRESSED_ACTION;
                    l = Signal.TUI_LANGUAGE;
    
                } else if (id == java.awt.event.KeyEvent.KEY_RELEASED) {
    
                    a = Controller.KEY_RELEASED_ACTION;
                    l = Signal.TUI_LANGUAGE;
    
                } else if (id == java.awt.event.KeyEvent.KEY_TYPED) {
    
                    a = Controller.KEY_TYPED_ACTION;
                    l = Signal.TUI_LANGUAGE;
    
                } else */if (id == java.awt.event.MouseEvent.MOUSE_CLICKED) {
    
                    s.predicate = JavaEventHandler.MOUSE_CLICKED_EVENT;

/*??
                    a = Controller.MOUSE_CLICKED_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.x_distance.quantity", ((java.awt.event.MouseEvent) evt).getX());
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.x_distance.unit", "pixel");
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.y_distance.quantity", ((java.awt.event.MouseEvent) evt).getY());
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.y_distance.unit", "pixel");
                    m = "system.controller.mouse_model.pointer_position.y_distance.unit";
*/
    
                }/*?? else if (id == java.awt.event.MouseEvent.MOUSE_DRAGGED) {
    
                    a = Controller.MOUSE_DRAGGED_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
    
                    //?? Find out which child system is active (top window)
                    //?? to use its controller here.
                    System sys = (System) getChild(Launcher.SYSTEM);
    
                    if (sys != null) {
    
                        Controller c = (Controller) sys.getChild(System.CONTROLLER);
        
                        if (c != null) {
        
                            m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
        
                            if (m != null) {
    
                                Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);
    
                                if (sp != null) {
    
                                    sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                    sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));
    
                                } else {
    
                                    throw new Exception("Could not handle java event. The pointer position is null.");
                                }
        
                            } else {
                    
                                throw new Exception("Could not handle java event. The mouse model is null.");
                            }
        
                        } else {
                
                            throw new Exception("Could not handle java event. The controller is null.");
                        }
        
                    } else {
            
                        throw new Exception("Could not handle java event. The system is null.");
                    }
    
                } else if (id == java.awt.event.MouseEvent.MOUSE_ENTERED) {
    
                    a = Controller.MOUSE_ENTERED_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
    
                    //?? Find out which child system is active (top window)
                    //?? to use its controller here.
                    System sys = (System) getChild(Launcher.SYSTEM);
    
                    if (sys != null) {
    
                        Controller c = (Controller) sys.getChild(System.CONTROLLER);
        
                        if (c != null) {
        
                            m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
        
                            if (m != null) {
    
                                Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);
    
                                if (sp != null) {
    
                                    sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                    sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));
    
                                } else {
    
                                    throw new Exception("Could not handle java event. The pointer position is null.");
                                }
        
                            } else {
                    
                                throw new Exception("Could not handle java event. The mouse model is null.");
                            }
        
                        } else {
                
                            throw new Exception("Could not handle java event. The controller is null.");
                        }
        
                    } else {
            
                        throw new Exception("Could not handle java event. The system is null.");
                    }
    
                } else if (id == java.awt.event.MouseEvent.MOUSE_EXITED) {
    
                    a = Controller.MOUSE_EXITED_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
    
                    //?? Find out which child system is active (top window)
                    //?? to use its controller here.
                    System sys = (System) getChild(Launcher.SYSTEM);
    
                    if (sys != null) {
    
                        Controller c = (Controller) sys.getChild(System.CONTROLLER);
        
                        if (c != null) {
        
                            m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
        
                            if (m != null) {
    
                                Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);
    
                                if (sp != null) {
    
                                    sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                    sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));
    
                                } else {
    
                                    throw new Exception("Could not handle java event. The pointer position is null.");
                                }
        
                            } else {
                    
                                throw new Exception("Could not handle java event. The mouse model is null.");
                            }
        
                        } else {
                
                            throw new Exception("Could not handle java event. The controller is null.");
                        }
        
                    } else {
            
                        throw new Exception("Could not handle java event. The system is null.");
                    }
    
                }*/ else if (id == java.awt.event.MouseEvent.MOUSE_MOVED) {

/*??
                    String s1 = java.lang.Integer.toString(((java.awt.event.MouseEvent) evt).getX());
                    String s2 = java.lang.Integer.toString(((java.awt.event.MouseEvent) evt).getY());
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.x_distance.quantity", s1);
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.x_distance.unit", "pixel");
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.y_distance.quantity", s2);
                    ItemHandler.set_item_element("system.controller.mouse_model.pointer_position.y_distance.unit", "pixel");
*/

                    s.predicate = JavaEventHandler.MOUSE_MOVED_EVENT;
    
                }/*?? else if (id == java.awt.event.MouseEvent.MOUSE_PRESSED) {
    
                    a = Controller.MOUSE_PRESSED_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
    
                    //?? Find out which child system is active (top window)
                    //?? to use its controller here.
                    System sys = (System) getChild(Launcher.SYSTEM);
    
                    if (sys != null) {
    
                        Controller c = (Controller) sys.getChild(System.CONTROLLER);
        
                        if (c != null) {
        
                            m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
        
                            if (m != null) {
    
                                Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);
    
                                if (sp != null) {
    
                                    sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                    sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));
    
                                } else {
    
                                    throw new Exception("Could not handle java event. The pointer position is null.");
                                }
        
                            } else {
                    
                                throw new Exception("Could not handle java event. The mouse model is null.");
                            }
        
                        } else {
                
                            throw new Exception("Could not handle java event. The controller is null.");
                        }
        
                    } else {
            
                        throw new Exception("Could not handle java event. The system is null.");
                    }
    
                } else if (id == java.awt.event.MouseEvent.MOUSE_RELEASED) {
    
                    a = Controller.MOUSE_RELEASED_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
    
                    //?? Find out which child system is active (top window)
                    //?? to use its controller here.
                    System sys = (System) getChild(Launcher.SYSTEM);
    
                    if (sys != null) {
    
                        Controller c = (Controller) sys.getChild(System.CONTROLLER);
        
                        if (c != null) {
        
                            m = (MouseModel) c.getChild(Controller.MOUSE_MODEL);
        
                            if (m != null) {
    
                                Space sp = (Space) m.getChild(MouseModel.POINTER_POSITION);
    
                                if (sp != null) {
    
                                    sp.setChild(Space.EXPANSE_X_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getX()));
                                    sp.setChild(Space.EXPANSE_Y_COORDINATE, new Integer(((java.awt.event.MouseEvent) evt).getY()));
    
                                } else {
    
                                    throw new Exception("Could not handle java event. The pointer position is null.");
                                }
        
                            } else {
                    
                                throw new Exception("Could not handle java event. The mouse model is null.");
                            }
        
                        } else {
                
                            throw new Exception("Could not handle java event. The controller is null.");
                        }
        
                    } else {
            
                        throw new Exception("Could not handle java event. The system is null.");
                    }
    
                } else if (id == java.awt.event.MouseWheelEvent.MOUSE_WHEEL) {
    
                    a = Controller.MOUSE_WHEEL_ACTION;
                    l = Signal.MOUSE_LANGUAGE;
                }
*/

            } else {
    
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not transform java event. The java event is null.");
            }

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not transform java event. The signal is null.");
        }
    }

    //
    // Event handler.
    //

    /**
     * Sets the event handler.
     *
     * @param p0 the event handler
     */
    static void set_event_handler(java.lang.Object p0) {

        // Start the awt event thread by calling getDefaultToolkit().
        // Otherwise, the event thread is started by calling the show method
        // on a java awt frame.
        java.awt.Toolkit t = java.awt.Toolkit.getDefaultToolkit();

        if (t != null) {

            java.awt.EventQueue q = t.getSystemEventQueue();

            if (q != null) {

                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Replace java event queue for dispatching events.");
                q.push((JavaEventHandler) p0);

            } else {

                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not set event handler. The java awt event queue is null.");
            }

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not set event handler. The java awt toolkit is null.");
        }
    }

    /**
     * Removes the event handler.
     *
     * @param p0 the event handler
     */
    static void remove_event_handler(java.lang.Object p0) {

        JavaEventHandler h = (JavaEventHandler) p0;

        if (h != null) {
                
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Stop dispatching events using java event queue.");
            h.pop();

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove event handler. The java event handler is null.");
        }
    }
}

