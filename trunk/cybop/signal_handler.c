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
#include "complex_handler.c"
#include "map_handler.c"
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
 * @version $Revision: 1.11 $ $Date: 2003-10-07 23:07:41 $ $Author: christian $
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
            
                log((void*) &INFO_LOG_LEVEL, "Send signal:");
                log((void*) &INFO_LOG_LEVEL, s->predicate);

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
//??                synchronized (p0) {

                    // Add signal to signal memory (interrupt vector table).
                    add_map_element(p0, (void*) SIGNAL, (void*) tmp);
//??                }

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
        struct signal* tmp = 0;
        int i = 0;
        
        get_map_element_at_index(p0, (void*) &i, (void*) tmp);
        remove_map_element_at_index(p0, (void*) &i);

        if (tmp != 0) {
        
            log((void*) &INFO_LOG_LEVEL, "Receive signal:");
            log((void*) &INFO_LOG_LEVEL, tmp->predicate);

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
    int* sf = (int*) p2;

    if (s != 0) {

        char* a = (char*) s->predicate;

        if (a != 0) {

            log((void*) &INFO_LOG_LEVEL, "Handle signal:");
            log((void*) &INFO_LOG_LEVEL, a);

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

                void* main_frame = malloc(0);
                struct vector* pointer_position = malloc(0);
                
                get_complex_element(statics, "main_frame", main_frame);
                get_complex_element(statics, "mouse.pointer_position", pointer_position);
                
                reset_signal(s);

                if (pointer_position != 0) {
                 
                    mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);
                    
                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is null.");
                }
                
                free(pointer_position);
                free(main_frame);

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
                create_instance(statics, s->object, &COMPLEX_MODEL);

                reset_signal(s);
                
/*??
                s->predicate = SEND_ACTION;
                s->object = get_map_element(statics->children, "main_frame");
*/

            } else if (strcmp(a, SHUTDOWN_ACTION) == 0) {
                
                // Root (statics).
                destroy_instance(statics, s->object, &COMPLEX_MODEL);
                *sf = 1;

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

