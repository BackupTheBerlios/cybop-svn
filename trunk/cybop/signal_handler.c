/*
 * $RCSfile: signal_handler.c,v $
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

/**
 * This is a signal handler.
 *
 * It offers signal processing procedures which should be called in the following order:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @version $Revision: 1.2 $ $Date: 2003-09-22 06:50:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The signal. */
static const char[] SIGNAL = "signal";

//
// Priorities.
//

/** The normal priority. */
static const char[] NORMAL_PRIORITY = "1";

//
// Languages.
//

/** The system internal (neuro) language. */
static const char[] NEURO_LANGUAGE = "neuro";

/** The textual user interface (tui) language. */
static const char[] TUI_LANGUAGE = "tui";

/** The mouse language. */
static const char[] MOUSE_LANGUAGE = "mouse";

/** The graphical user interface (gui) language. */
static const char[] GUI_LANGUAGE = "gui";

/** The socket language. */
static const char[] SOCKET_LANGUAGE = "socket";

/** The structured query language (sql). */
static const char[] SQ_LANGUAGE = "sq";

/** The java messaging service (jms) language. */
static const char[] JMS_LANGUAGE = "jms";

/** The remote method invocation (rmi) language. */
static const char[] RMI_LANGUAGE = "rmi";

/** The common object request broker architecture (corba) language. */
static const char[] CORBA_LANGUAGE = "corba";

/** The extensible markup language (xml). */
static const char[] XML_LANGUAGE = "xml";

/** The simple object access protocol (soap) language. */
static const char[] SOAP_LANGUAGE = "soap";

//
// Actions.
//

/** The show system information action. */
static const char[] SHOW_SYSTEM_INFORMATION_ACTION = "show_system_information";

/** The startup action. */
static const char[] STARTUP_ACTION = "startup";

/** The shutdown action. */
static const char[] SHUTDOWN_ACTION = "shutdown";

/** The receive action. */
static const char[] RECEIVE_ACTION = "receive";

/** The send action. */
static const char[] SEND_ACTION = "send";

//
// Attributes.
//

/** The statics. */
static item statics;

/** The dynamics. */
static item dynamics;

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
void receive_signal(int p0, int p1) {

    signal s = (signal) p1;
    
    if (s != NULL) {

        // Read and remove signal from signal memory (interrupt vector table).
        signal tmp = (signal) get_map_element(p0, 0);
        remove_map_element(p0, 0);
        
        if (tmp != NULL) {
        
            log(INFO_LOG_LEVEL, "Receive signal: " + tmp->predicate);

            // Copy signal memory signal to the transporting signal given as parameter.
            s->priority = tmp->priority;
            s->language = tmp->language;
            s->subject = tmp->subject;
            s->predicate = tmp->predicate;
            s->owner = tmp->owner;
            s->sender = tmp->sender;
            s->object = tmp->object;
            s->adverbial = tmp->adverbial;
            s->condition = tmp->condition;

            // Reset and destroy signal memory signal.
            reset_signal(tmp);
            free(tmp);
    
        } else {

            // No signal was received.
            // Do not log this as the loop runs infinite and would stuff the log record.
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not receive signal. The signal is NULL.");
    }
}

/**
 * Handles the signal.
 *
 * @param p0 the signal
 * @param p1 the remote flag
 * @return the shutdown flag
 */
int handle_signal(int p0, int p1) {

    int sf = 0;
    signal s = (signal) p0;
            
    if (s != NULL) {

        int a = s->predicate;

        if (a != NULL) {

            log(INFO_LOG_LEVEL, "Handle signal: " + a);

            if (a.equals("mouse_moved")) {

/*?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
                Item statics = statics;
                
                set_item_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                set_item_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                set_item_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                set_item_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");
*/

                reset_signal(s);

            } else if (a.equals("mouse_clicked")) {

                Item statics = statics;
                int main_frame = get_item_element(statics, "main_frame");
                Vector pointer_position = (Vector) get_item_element(statics, "mouse.pointer_position");
                
                reset_signal(s);

                if (pointer_position != NULL) {
                 
                    s->predicate = mouse_clicked_action(main_frame, pointer_position.x, pointer_position.y, pointer_position.z);
                    
                } else {
                    
                    log(ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is NULL.");
                }

            } else if (a.equals(SHOW_SYSTEM_INFORMATION_ACTION)) {

/*??
                encode("system.controller.system_information_screen_model");
                
                show();
*/
                
                reset_signal(s);

/*??
            } else if (a.equals(RECALL_PATIENT_ACTION)) {
                
                reset_signal(s);

            } else if (a.equals(REMEMBER_PATIENT_ACTION)) {
                
                reset_signal(s);

*/
            } else if (a.equals(SEND_ACTION)) {
                
                Item o = (Item) s->object;

                if (o != NULL) {
                    
                    int j = o.java_object;

                    if (j != NULL) {
                        
                        if (j instanceof java.awt.Component) {
                            
                            ((java.awt.Component) j).setVisible(true);
                        
                        } else {
                            
                            log(ERROR_LOG_LEVEL, "Could not handle send action. The java object is not a component.");
                        }
                
                    } else {
                        
                        log(ERROR_LOG_LEVEL, "Could not handle send action. The java object is NULL.");
                    }
                
                } else {
                    
                    log(ERROR_LOG_LEVEL, "Could not handle send action. The signal object is NULL.");
                }

                reset_signal(s);
                
            } else if (a.equals(STARTUP_ACTION)) {
                
                // Root (statics).
                statics = (Item) create_object(s->object, CATEGORY);

                reset_signal(s);
                
                s->predicate = SEND_ACTION;
                s->object = get_map_element(((Item) statics).items, "main_frame");

            } else if (a.equals(SHUTDOWN_ACTION)) {
                
                // Root (statics).
                destroy_object(statics, s->object, CATEGORY);
                sf = true;

                reset_signal(s);
            }
            
        } else {

            // The signal is empty and does not contain an action.
            // Do not log this as the loop runs infinite and would stuff the log record.
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not handle signal. The signal is NULL.");
    }
    
    return sf;
}

/**
 * Sends the signal.
 *
 * If a signal's action is NULL, it will get destroyed.
 * Otherwise, the signal will be stored in the signal memory for further
 * handling.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 */
void send_signal(int p0, int p1) {

    signal s = (signal) p1;
    
    if (s != NULL) {

        // Only send a new signal (store in signal memory) if an action exists.
        // Otherwise, the chain of signals/ actions finishes here, until a new
        // hardware event (interrupt) occurs.
        if (s->predicate != NULL) {
            
            // Create signal for storage in signal memory.
            signal* tmp = (signal*) malloc(sizeof(signal));
    
            if (tmp != NULL) {
            
                log(INFO_LOG_LEVEL, "Send signal: " + s->predicate);

                // Copy transporting signal given as parameter to the signal memory signal.
                tmp->priority = s->priority;
                tmp->language = s->language;
                tmp->subject = s->subject;
                tmp->predicate = s->predicate;
                tmp->owner = s->owner;
                tmp->sender = s->sender;
                tmp->object = s->object;
                tmp->adverbial = s->adverbial;
                tmp->condition = s->condition;

                // Caution! Adding of signals must be synchronized between:
                // - send for adding internal CYBOP signals
                // - JavaEventHandler.dispatchEvent for adding transformed java event signals
                // These are the only procedures accessing the signal
                // memory for adding signals.
                synchronized (p0) {

                    // Add signal to signal memory (interrupt vector table).
                    add_map_element(p0, SIGNAL, tmp);
                }

            } else {
    
                log(ERROR_LOG_LEVEL, "Could not send signal. The signal memory signal is NULL.");
            }

        } else {
            
            // Do not log this as the loop runs infinite and would stuff the log record!
            // The action is NULL. No signal gets stored in the signal memory.
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not send signal. The signal is NULL.");
    }
}

/**
 * Resets the signal.
 *
 * @param p0 the signal
 */
void reset_signal(int p0) {
    
    Signal s = (Signal) p0;
    
    if (s != NULL) {

        s->priority = NULL;
        s->language = NULL;
        s->subject = NULL;
        s->predicate = NULL;
        s->owner = NULL;
        s->sender = NULL;
        s->object = NULL;
        s->adverbial = NULL;
        s->condition = NULL;

    } else {

        log(ERROR_LOG_LEVEL, "Could not reset signal. The signal is NULL.");
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
int mouse_clicked_action(int p0, int p1, int p2, int p3) {

    int a = NULL;
    Item i = (Item) p0;
    
    if (i != NULL) {

        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(i.items);
        int child = NULL;
        vector position = NULL;
        vector expansion = NULL;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        int action = NULL;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(i.items, count);
            position = (vector) get_map_element(i.positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != NULL) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != NULL) {

                        // Determine child's expansion.
                        width = expansion->x;
                        height = expansion->y;
                        depth = expansion->z;
        
                        // Check if the given coordinates are in the child's screen area.
                        // The "if" conditions had to be inserted because in classical
                        // graphical user interfaces, the depth is normally 0 and
                        // such the boolean comparison would deliver "false".
                        // Using the conditions, the coordinates that are set to "0"
                        // are not considered for comparison.
                        contains = (x >= 0);
                        contains = contains && (x < width);
                        contains = contains && (y >= 0);
                        contains = contains && (y < height);
                        contains = contains && (z >= 0);
                        contains = contains && (z < depth);
        
                        if (contains == 1) {
        
                            // The given coordinates are in the child's screen area.
                            // Therefore, use the child's action.
                            action = mouse_clicked_action(child, x, y, z);
                
                            break;
                        }

                    } else {
                        
                        log(ERROR_LOG_LEVEL, "Could not handle mouse clicked action. An expansion is NULL.");
                    }

                } else {
                    
                    log(ERROR_LOG_LEVEL, "Could not handle mouse clicked action. A position is NULL.");
                }

            } else {
                
                log(INFO_LOG_LEVEL, "Could not handle mouse clicked action. A child is not of type Item.");
            }
            
            count++;
        }
        
        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != NULL) {
            
            a = action;

        } else {
            
            // Determine the action of the given screen item.
            a = get_map_element(i.items, "mouse_clicked_action");
        }

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The item is NULL.");
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
int add(int p0, int p1) {

    int sum = NULL;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;
    
    if (i0 != NULL) {

        if (i1 != NULL) {

            sum = new java.lang.Integer(i0.intValue() + i1.intValue());

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not add. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not add. The first parameter is NULL.");
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
int subtract(int p0, int p1) {

    int difference = NULL;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;
    
    if (i0 != NULL) {

        if (i1 != NULL) {

            difference = new java.lang.Integer(i0.intValue() - i1.intValue());

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not subtract. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not subtract. The first parameter is NULL.");
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
int multiply(int p0, int p1) {

    int product = NULL;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;
    
    if (i0 != NULL) {

        if (i1 != NULL) {

            product = new java.lang.Integer(i0.intValue() * i1.intValue());

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not multiply. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not multiply. The first parameter is NULL.");
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
int divide(int p0, int p1) {

    int quotient = NULL;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;
    
    if (i0 != NULL) {

        if (i1 != NULL) {

            quotient = new java.lang.Integer(i0.intValue() / i1.intValue());
            //?? Rest of integer division is determined with:
            //?? rest = new java.lang.Integer(i0.intValue() % i1.intValue());

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not divide. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not divide. The first parameter is NULL.");
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
boolean isDividableWithoutRest(Integer i) {

    boolean result = Boolean.FALSE;
    
    if (i != NULL) {

        java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

        if (j2 != NULL) {

            java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

            if (j1 != NULL) {

                int rest = j1.intValue() % j2.intValue();

                if (rest == 0) {
                    
                    result = Boolean.TRUE;
                }

            } else {
                
                log(ERROR_LOG_LEVEL, "Could not divide integer. This java integer 1 is NULL.");
            }

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not divide integer. The java integer 2 is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not divide integer. The integer is NULL.");
    }
    
    return result;
}

/**
 * Returns the absolute value (without sign) of this integer.
 *
 * @return the absolute value (without sign) of this integer
 */
/*??
Integer absolute() {

    Integer abs = NULL;
    
/*??
    java.lang.Integer j = (java.lang.Integer) getJavaObject();

    if (j != NULL) {
        
        int i = abs(j.intValue());
        abs = new java.lang.Integer(i);

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not determine absolute value. The java integer is NULL.");
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
int equal(int p0, int p1) {

    int result = 0;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;

    if (i0 != NULL) {

        if (i1 != NULL) {

            if (i0.intValue() == i1.intValue()) {

                result = 1;
            }

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not compare equal. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not compare equal. The first parameter is NULL.");
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
int smaller(int p0, int p1) {

    int result = false;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;

    if (i0 != NULL) {

        if (i1 != NULL) {

            if (i0.intValue() < i1.intValue()) {

                result = 1;
            }

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not compare smaller. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not compare smaller. The first parameter is NULL.");
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
int greater(int p0, int p1) {

    int result = false;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;

    if (i0 != NULL) {

        if (i1 != NULL) {

            if (i0.intValue() > i1.intValue()) {

                result = 1;
            }

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not compare greater. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not compare greater. The first parameter is NULL.");
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
int smaller_or_equal(int p0, int p1) {

    int result = false;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;

    if (i0 != NULL) {

        if (i1 != NULL) {

            if (i0.intValue() <= i1.intValue()) {

                result = 1;
            }

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not compare smaller or equal. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not compare smaller or equal. The first parameter is NULL.");
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
int greater_or_equal(int p0, int p1) {

    int result = false;
    java.lang.Integer i0 = (java.lang.Integer) p0;
    java.lang.Integer i1 = (java.lang.Integer) p1;

    if (i0 != NULL) {

        if (i1 != NULL) {

            if (i0.intValue() >= i1.intValue()) {

                result = 1;
            }

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not compare greater or equal. The second parameter is NULL.");
        }
            
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not compare greater or equal. The first parameter is NULL.");
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
int and(int p0, int p1) {

    return p0 && p1;
}

/**
 * Logical OR.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @return the boolean result
 */
int or(int p0, int p1) {

    return p0 || p1;
}

