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

#include <string.h>
#include "signal.c"
#include "statics_handler.c"
#include "vector.c"

/**
 * This is a signal handler.
 *
 * It offers signal processing procedures which should be called in the following order:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @version $Revision: 1.8 $ $Date: 2003-10-05 08:45:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The signal. */
static const char* SIGNAL = "signal";

//
// Priorities.
//

/** The normal priority. */
static const int NORMAL_PRIORITY = 1;

//
// Languages.
//

/** The system internal (neuro) language. */
static const char* NEURO_LANGUAGE = "neuro";

/** The textual user interface (tui) language. */
static const char* TUI_LANGUAGE = "tui";

/** The mouse language. */
static const char* MOUSE_LANGUAGE = "mouse";

/** The graphical user interface (gui) language. */
static const char* GUI_LANGUAGE = "gui";

/** The socket language. */
static const char* SOCKET_LANGUAGE = "socket";

/** The structured query language (sql). */
static const char* SQ_LANGUAGE = "sq";

/** The java messaging service (jms) language. */
static const char* JMS_LANGUAGE = "jms";

/** The remote method invocation (rmi) language. */
static const char* RMI_LANGUAGE = "rmi";

/** The common object request broker architecture (corba) language. */
static const char* CORBA_LANGUAGE = "corba";

/** The extensible markup language (xml). */
static const char* XML_LANGUAGE = "xml";

/** The simple object access protocol (soap) language. */
static const char* SOAP_LANGUAGE = "soap";

//
// Actions.
//

/** The show system information action. */
static const char* SHOW_SYSTEM_INFORMATION_ACTION = "show_system_information";

/** The startup action. */
static const char* STARTUP_ACTION = "startup";

/** The shutdown action. */
static const char* SHUTDOWN_ACTION = "shutdown";

/** The receive action. */
static const char* RECEIVE_ACTION = "receive";

/** The send action. */
static const char* SEND_ACTION = "send";

//
// Attributes.
//

/** The statics. */
static void* statics;

/** The dynamics. */
static void* dynamics;

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
static void receive_signal(void* p0, void* p1) {

    struct signal* s = (struct signal*) p1;
    
    if (s != 0) {

        // Read and remove signal from signal memory (interrupt vector table).
        struct signal* tmp = (struct signal*) get_map_element(p0, 0);
        remove_map_element(p0, 0);
        
        if (tmp != 0) {
        
            log((void*) &INFO_LOG_LEVEL, strcat("Receive signal: ", tmp->predicate));

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

        log((void*) &ERROR_LOG_LEVEL, "Could not receive signal. The signal is null.");
    }
}

/**
 * Handles the signal.
 *
 * @param p0 the signal
 * @param p1 the remote flag
 * @param p2 the shutdown flag
 */
static void handle_signal(void* p0, void* p1, void* p2) {

    struct signal* s = (struct signal*) p0;

    if (s != 0) {

        void* a = s->predicate;

        if (a != 0) {

            log((void*) &INFO_LOG_LEVEL, strcat("Handle signal: ", a));

            if (strcmp(a, "mouse_moved") == 0) {

/*?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
                Item statics = statics;
                
                set_item_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                set_item_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                set_item_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                set_item_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");
*/

                reset_signal(s);

            } else if (strcmp(a, "mouse_clicked") == 0) {

                void* statics = statics;
                void* main_frame = get_item_element(statics, "main_frame");
                struct vector* pointer_position = (struct vector*) get_item_element(statics, "mouse.pointer_position");
                
                reset_signal(s);

                if (pointer_position != 0) {
                 
                    s->predicate = mouse_clicked_action(main_frame, pointer_position->x, pointer_position->y, pointer_position->z);
                    
                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is null.");
                }

            } else if (strcmp(a, SHOW_SYSTEM_INFORMATION_ACTION) == 0) {

/*??
                encode("system.controller.system_information_screen_model");
                
                show();
*/
                
                reset_signal(s);

/*??
            } else if (strcmp(a, RECALL_PATIENT_ACTION) == 0) {
                
                reset_signal(s);

            } else if (strcmp(a, REMEMBER_PATIENT_ACTION) == 0) {
                
                reset_signal(s);

*/
            } else if (strcmp(a, SEND_ACTION) == 0) {
                
/*??
                struct item* o = (struct item*) s->object;

                if (o != 0) {
                    
                    int j = o.java_object;

                    if (j != 0) {
                        
                        if (j instanceof java.awt.Component) {
                            
                            ((java.awt.Component) j).setVisible(true);
                        
                        } else {
                            
                            log((void*) &ERROR_LOG_LEVEL, "Could not handle send action. The java object is not a component.");
                        }
                
                    } else {
                        
                        log((void*) &ERROR_LOG_LEVEL, "Could not handle send action. The java object is null.");
                    }
                
                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle send action. The signal object is null.");
                }
*/

                reset_signal(s);
                
            } else if (strcmp(a, STARTUP_ACTION) == 0) {
                
                // Root (statics).
                create_instance(statics, s->object, COMPLEX_MODEL);

                reset_signal(s);
                
/*??
                s->predicate = SEND_ACTION;
                s->object = get_map_element(statics->children, "main_frame");
*/

            } else if (strcmp(a, SHUTDOWN_ACTION) == 0) {
                
                // Root (statics).
                destroy_instance(statics, s->object, COMPLEX_MODEL);
                *p2 = 1;

                reset_signal(s);
            }
            
        } else {

            // The signal is empty and does not contain an action.
            // Do not log this as the loop runs infinite and would stuff the log record.
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not handle signal. The signal is null.");
    }
}

/**
 * Sends the signal.
 *
 * If a signal's action is 0, it will get destroyed.
 * Otherwise, the signal will be stored in the signal memory for further
 * handling.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 */
static void send_signal(void* p0, void* p1) {

    struct signal* s = (struct signal*) p1;
    
    if (s != 0) {

        // Only send a new signal (store in signal memory) if an action exists.
        // Otherwise, the chain of signals/ actions finishes here, until a new
        // hardware event (interrupt) occurs.
        if (s->predicate != 0) {
            
            // Create signal for storage in signal memory.
            struct signal* tmp = (struct signal*) malloc(sizeof(struct signal));
    
            if (tmp != 0) {
            
                log((void*) &INFO_LOG_LEVEL, strcat("Send signal: ", s->predicate));

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
/*??
                synchronized (p0) {

                    // Add signal to signal memory (interrupt vector table).
                    add_map_element(p0, SIGNAL, tmp);
                }
*/

            } else {
    
                log((void*) &ERROR_LOG_LEVEL, "Could not send signal. The signal memory signal is null.");
            }

        } else {
            
            // Do not log this as the loop runs infinite and would stuff the log record!
            // The action is 0. No signal gets stored in the signal memory.
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not send signal. The signal is null.");
    }
}

/**
 * Resets the signal.
 *
 * @param p0 the signal
 */
static void reset_signal(void* p0) {
    
    struct signal* s = (struct signal*) p0;
    
    if (s != 0) {

        s->priority = 0;
        s->language = 0;
        s->subject = 0;
        s->predicate = 0;
        s->owner = 0;
        s->sender = 0;
        s->object = 0;
        s->adverbial = 0;
        s->condition = 0;

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not reset signal. The signal is null.");
    }
}

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
 * @param p4 the action
 */
static void mouse_clicked_action(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != 0) {

/*??
        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = 0;
        struct vector* position = 0;
        struct vector* expansion = 0;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = 0;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != 0) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != 0) {

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
                            action = mouse_clicked_action(child, x, y, z, p4);
                
                            break;
                        }

                    } else {
                        
                        log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. An expansion is null.");
                    }

                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. A position is null.");
                }

            } else {
                
                log((void*) &INFO_LOG_LEVEL, "Could not handle mouse clicked action. A child is not of type Item.");
            }
            
            count++;
        }
        
        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != 0) {
            
            p4 = action;

        } else {
            
            // Determine the action of the given screen item.
            get_map_element(i->items, "mouse_clicked_action", p4);
        }
*/

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The item is null.");
    }
}

