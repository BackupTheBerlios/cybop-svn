/*
 * $RCSfile: signal_memory_handler.c,v $
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

#ifndef SIGNAL_MEMORY_HANDLER_SOURCE
#define SIGNAL_MEMORY_HANDLER_SOURCE

#include <string.h>
#include "array_handler.c"
#include "map.c"
#include "map_handler.c"
#include "signal.c"
#include "statics_model_handler.c"
#include "vector.c"

/**
 * This is the signal memory handler.
 *
 * It offers signal processing procedures which should be called in the
 * following order:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @version $Revision: 1.3 $ $Date: 2003-11-26 14:40:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Priorities.
//

/** The normal priority. */
static const int NORMAL_PRIORITY = 0;

//
// Languages.
//

/** The system internal language. */
static const char* INTERNAL_LANGUAGE = "internal";

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
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 */
static void create_signal_memory(void* p0) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create signal memory.");

        m->signals = malloc(sizeof(struct array));
        initialize_array(m->signals);

        m->priorities = malloc(sizeof(struct array));
        initialize_array(m->priorities);
        
        m->languages = malloc(sizeof(struct array));
        initialize_array(m->languages);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not create signal memory. The signal memory is null.");
    }
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 */
static void destroy_signal_memory(void* p0) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy signal memory.");

        finalize_array(m->languages);
        free(m->languages);

        finalize_array(m->priorities);
        free(m->priorities);

        finalize_array(m->signals);
        free(m->signals);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not destroy signal memory. The signal memory is null.");
    }
}

//
// Signal.
//

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @param p2 the signal
 * @param p3 the priority
 * @param p4 the language
 */
static void set_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != 0) {
        
        set_array_element(m->signals, p1, p2);
        set_array_element(m->priorities, p1, p3);
        set_array_element(m->languages, p1, p4);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not set signal. The signal memory is null.");
    }
}

/**
 * Adds the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 * @param p2 the priority
 * @param p3 the language
 */
static void add_signal(void* p0, void* p1, void* p2, void* p3) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != 0) {

        void* c = get_array_count(m->signals);
        set_signal(p0, c, p1, p2, p3);
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not add signal. The signal memory is null.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
static void remove_signal(void* p0, void* p1) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != 0) {

        remove_array_element(m->signals, p1);
        remove_array_element(m->priorities, p1);
        remove_array_element(m->languages, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The signal memory is null.");
    }
}

/**
 * Returns the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the signal
 */
static void* get_signal(void* p0, void* p1) {

    void* s = 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != 0) {

        s = get_array_element(m->signals, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get signal. The signal memory is null.");
    }
    
    return s;
}

/**
 * Returns the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 */
static int get_highest_priority_index(void* p0) {
    
    int index = -1;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != 0) {

        int i = 0;
        int* count = (int*) get_array_count(m->priorities);
        int* p = 0;
        int h = 0;
    
        while (i < *count) {
    
            p = (int*) get_array_element(m->priorities, (void*) &i);
    
            // If a name equal to the searched one is found,
            // then its index is the one to be returned
            // since this element will have to be replaced.
            if (*p > h) {
    
                index = i;
                h = *p;
            }
    
            i++;
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get signal. The signal memory is null.");
    }
    
    return index;
}

/**
 * Returns the language.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the language
 */
static void* get_language(void* p0, void* p1) {

    void* l = 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != 0) {

        l = get_array_element(m->languages, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get language. The signal memory is null.");
    }
    
    return l;
}

/**
 * Resets the signal.
 *
 * @param p0 the signal
 */
static void reset_signal(void* p0) {
    
    struct signal* s = (struct signal*) p0;
    
    if (s != 0) {

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
 * The signal will be stored in the signal memory for further handling.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 * @param p2 the priority
 * @param p3 the language
 */
static void send_signal(void* p0, void* p1, void* p2, void* p3) {

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

                // Copy transporting signal given as parameter to the signal.
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
                    add_signal(p0, (void*) tmp, p2, p3);
//??                }

            } else {
    
                log((void*) &ERROR_LOG_LEVEL, "Could not send signal. The signal is null.");
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
 * - copies that signal to the transporting signal handed over as parameter
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
        
        int index = get_highest_priority_index(p0);
        char* language = (char*) get_language(p0, (void*) &index);
        struct signal* tmp = get_signal(p0, (void*) &index);
        remove_signal(p0, (void*) &index);

        if (tmp != 0) {
        
            log((void*) &INFO_LOG_LEVEL, "Receive signal:");
            log((void*) &INFO_LOG_LEVEL, tmp->predicate);

            // Copy signal to the transporting signal given as parameter.
            s->subject = tmp->subject;
            s->predicate = tmp->predicate;
            s->owner = tmp->owner;
            s->sender = tmp->sender;
            s->object = tmp->object;
            s->adverbial = tmp->adverbial;
            s->condition = tmp->condition;

            // Destroy signal.
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
                Model statics = statics;
                
                set_model_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                set_model_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                set_model_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                set_model_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");
*/

                reset_signal(s);

            } else if (strcmp(a, "mouse_clicked") == 0) {

                void* main_frame = get_statics_model_part(statics, (void*) "main_frame");
                struct vector* pointer_position = get_statics_model_part(statics, (void*) "mouse.pointer_position");
                
                reset_signal(s);

                if (pointer_position != 0) {
                 
//??                    mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);
                    
                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is null.");
                }
                
/*??
            } else if (strcmp(a, SHOW_SYSTEM_INFORMATION_ACTION) == 0) {

                encode("system.controller.system_information_screen_model");
                
                show();
                
                reset_signal(s);

/*??
            } else if (strcmp(a, RECALL_PATIENT_ACTION) == 0) {
                
                reset_signal(s);

            } else if (strcmp(a, REMEMBER_PATIENT_ACTION) == 0) {
                
                reset_signal(s);
*/

/*??
            } else if (strcmp(a, SEND_ACTION) == 0) {
                
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

                reset_signal(s);
                
/*??
            } else if (strcmp(a, STARTUP_ACTION) == 0) {
                
                // Root (statics).
//??                statics = create_statics_model(s->object, (void*) COMPLEX_STATICS_MODEL);
                //?? Temporary replacement: Character based screen output test.
//??                statics = create_character_screen();
            
                reset_signal(s);
                
/*??
                s->predicate = SEND_ACTION;
                s->object = get_map_element_with_name(statics->children, "main_frame");
                s->receiver = ALL;
*/
                //?? Temporary replacement.
//??                show_character_screen(statics);

/*??
            } else if (strcmp(a, SHUTDOWN_ACTION) == 0) {
                
                // Root (statics).
//??                destroy_statics_model(statics, s->object, (void*) COMPLEX_STATICS_MODEL);
                *sf = 1;

                reset_signal(s);
*/
            }
            
        } else {

            // The signal is empty and does not contain an action.
            // Do not log this as the loop runs infinite and would stuff the log record.
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not handle signal. The signal is null.");
    }
}

/* SIGNAL_MEMORY_HANDLER_SOURCE */
#endif

