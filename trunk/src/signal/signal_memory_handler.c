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
#include "add.c"
#include "array_handler.c"
#include "create_dynamics.c"
#include "create_statics.c"
#include "destroy_dynamics.c"
#include "destroy_statics.c"
#include "dynamics.c"
#include "dynamics_model.c"
#include "map.c"
#include "map_handler.c"
#include "statics_model_handler.c"
#include "vector.c"
#include "x_windows_handler.c"

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
 * @version $Revision: 1.11 $ $Date: 2003-12-18 16:40:03 $ $Author: christian $
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

/** The textual user interface (tui) language. */
static const char* TUI_LANGUAGE = "tui";

/** The mouse language. */
static const char* MOUSE_LANGUAGE = "mouse";

/** The x windows language. */
static const char* X_WINDOWS_LANGUAGE = "x_windows";

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
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 */
void create_signal_memory(void* p0) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != (void*) 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Create signal memory.");

        m->signals = malloc(sizeof(struct array));
        initialize_array(m->signals);

        m->abstractions = malloc(sizeof(struct array));
        initialize_array(m->abstractions);

        m->priorities = malloc(sizeof(struct array));
        initialize_array(m->priorities);
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not create signal memory. The signal memory is null.");
    }
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 */
void destroy_signal_memory(void* p0) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != (void*) 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Destroy signal memory.");

        finalize_array(m->priorities);
        free(m->priorities);

        finalize_array(m->abstractions);
        free(m->abstractions);

        finalize_array(m->signals);
        free(m->signals);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not destroy signal memory. The signal memory is null.");
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
 * @param p3 the abstraction
 * @param p4 the priority
 */
void set_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != (void*) 0) {
        
        set_array_element(m->signals, p1, p2);
        set_array_element(m->abstractions, p1, p3);
        set_array_element(m->priorities, p1, p4);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set signal. The signal memory is null.");
    }
}

/**
 * Adds the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 * @param p2 the abstraction
 * @param p3 the priority
 */
void add_signal(void* p0, void* p1, void* p2, void* p3) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != (void*) 0) {

        int i = 0;
        get_array_count(m->signals, (void*) &i);
        set_signal(p0, (void*) &i, p1, p2, p3);
        
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not add signal. The signal memory is null.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
void remove_signal(void* p0, void* p1) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != (void*) 0) {

        remove_array_element(m->signals, p1);
        remove_array_element(m->abstractions, p1);
        remove_array_element(m->priorities, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The signal memory is null.");
    }
}

/**
 * Gets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the signal
 */
void* get_signal(void* p0, void* p1) {

    void* s = (void*) 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != (void*) 0) {

        s = get_array_element(m->signals, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get signal. The signal memory is null.");
    }
    
    return s;
}

/**
 * Gets the abstraction.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the abstraction
 */
void* get_abstraction(void* p0, void* p1) {

    void* a = (void*) 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != (void*) 0) {

        a = get_array_element(m->abstractions, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get abstraction. The signal memory is null.");
    }
    
    return a;
}

/**
 * Gets the priority.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the priority
 */
void* get_priority(void* p0, void* p1) {

    void* p = (void*) 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != (void*) 0) {

        p = get_array_element(m->priorities, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get priority. The signal memory is null.");
    }
    
    return p;
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the signal index
 */
void get_highest_priority_index(void* p0, void* p1) {
    
    struct signal_memory* m = (struct signal_memory*) p0;
    int* index = (int*) p1;

    if (m != (void*) 0) {

        int i = 0;
        int count = 0;
        get_array_count(m->priorities, (void*) &count);
        int* p = (void*) 0;
        int h = *index;
    
        while (i < count) {
    
            p = (int*) get_array_element(m->priorities, (void*) &i);
    
            // If a signal with higher priority is found,
            // then its index is the one to be returned.
            if (*p > h) {
            
                *index = i;
                h = *p;
            }
    
            i++;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get index of the signal with highest priority. The signal memory is null.");
    }
}

//
// Signal handling.
//

/**
 * Handles the compound signal.
 *
 * @param p0 the signal memory
 * @param p1 the compound signal
 * @param p2 the priority
 */
void handle_compound_signal(void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Handle compound signal.");

    struct dynamics_model* m = (struct dynamics_model*) p1;
    
    if (m != (void*) 0) {

        int count = 0;
        get_array_count(m->parts, (void*) &count);
        int pos = 0;
        int i = 0;
        int* position = (void*) 0;
        void* abstr = (void*) 0;
        void* part = (void*) 0;

        // All positions.
        while (pos < count) {
            
            // All parts.
            while (i < count) {
                
                // Determine position.
                position = (int*) get_map_element_at_index(m->positions, (void*) &i);
            
                // All parts at the current position.
                if (*position == pos) {

                    // Determine part signal as dynamics model.
                    part = get_map_element_at_index(m->parts, (void*) &i);
                
                    // Determine abstraction.
                    abstr = get_map_element_at_index(m->abstractions, (void*) &i);

                    // Caution! Adding of signals must be synchronized between:
                    // - internal CYBOI signals added here
                    // - hardware interrupt signals sent from the operating system
                    // These are the only two accessing the signal memory for adding.
//??                    synchronized (p0) {
    
                        // Add "part" signal to signal memory,
                        // using the "whole" signal's priority.
                        // (Each signal/action has a priority.
                        // An action may consist of "part" actions.
                        // The "part" actions cannot have higher/lower priority
                        // than their original "whole" action.)
                        add_signal(p0, part, abstr, p2);
//??                    }
                }
                
                i++;
            }
            
            pos++;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not handle compound signal. The signal dynamics model is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the operation signal
 * @param p1 the abstraction
 * @param p2 the statics
 * @param p3 the dynamics
 * @param p4 the internals
 * @param p5 the shutdown flag
 */
void handle_operation_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message((void*) &INFO_LOG_LEVEL, "Handle operation signal.");

    struct operation* o = (struct operation*) p0;
    
    if (o != (void*) 0) {

        char* a = (char*) p1;
        void* io = o->inputs_outputs;
    
        if (io != (void*) 0) {
    
            if (strcmp(a, ADD_ARITHMETIC) == 0) {
                
                // Dereference function pointer and hand over inputs and outputs.
                add(get_map_element_with_name(io, "summand_0"), get_map_element_with_name(io, "summand_1"), get_map_element_with_name(io, "sum"));

            } else if (strcmp(a, CREATE_STATICS_MEMORY_MANAGEMENT) == 0) {
        
                struct statics_model* s = (struct statics_model*) p2;
                
                if (s != (void*) 0) {
                        
                    void* m = create_statics(get_map_element_with_name(io, "model"), get_map_element_with_name(io, "abstraction"));
                    set_map_element_with_name(s->parts, get_map_element_with_name(io, "name"), m);
        
                } else {
            
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle create statics operation signal. The statics is null.");
                }

            } else if (strcmp(a, DESTROY_STATICS_MEMORY_MANAGEMENT) == 0) {
        
                struct statics_model* s = (struct statics_model*) p2;
                
                if (s != (void*) 0) {
                        
                    void* m = get_map_element_with_name(s->parts, get_map_element_with_name(io, "name"));
                    destroy_statics(m, get_map_element_with_name(io, "model"), get_map_element_with_name(io, "abstraction"));
        
                } else {
            
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle destroy statics operation signal. The statics is null.");
                }

            } else if (strcmp(a, CREATE_DYNAMICS_MEMORY_MANAGEMENT) == 0) {
        
                struct dynamics_model* d = (struct dynamics_model*) p3;
                
                if (d != (void*) 0) {
                        
                    void* m = create_dynamics(get_map_element_with_name(io, "model"), get_map_element_with_name(io, "io_names"), get_map_element_with_name(io, "io_values"), get_map_element_with_name(io, "abstraction"));
                    set_map_element_with_name(d->parts, get_map_element_with_name(io, "name"), m);
        
                } else {
            
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle create dynamics operation signal. The dynamics is null.");
                }

            } else if (strcmp(a, DESTROY_DYNAMICS_MEMORY_MANAGEMENT) == 0) {
        
                struct dynamics_model* d = (struct dynamics_model*) p3;
                
                if (d != (void*) 0) {
                        
                    void* m = get_map_element_with_name(d->parts, get_map_element_with_name(io, "name"));
                    destroy_dynamics(m, get_map_element_with_name(io, "model"), get_map_element_with_name(io, "io_names"), get_map_element_with_name(io, "io_values"), get_map_element_with_name(io, "abstraction"));
        
                } else {
            
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle destroy dynamics operation signal. The dynamics is null.");
                }

            } else if (strcmp(a, SEND_INPUT_OUTPUT) == 0) {

                void* l = get_map_element_with_name(io, "language");

                if (strcmp(l, X_WINDOWS_LANGUAGE) == 0) {
                    
                    send_x_windows_output(get_map_element_with_name(io, "addressee"), get_map_element_with_name(io, "message"), p4);
        
                } else if (strcmp(l, TUI_LANGUAGE) == 0) {

                }
                
            } else if (strcmp(a, RECEIVE_INPUT_OUTPUT) == 0) {
        
            } else if (strcmp(a, EXIT_LIFECYCLE_STEP) == 0) {
        
                // Set shutdown flag.
                int* f = (int*) p5;
                *f = 1;
            }

/*??
            //?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
            if (strcmp(l, "mouse_moved") == 0) {
        
                Model statics = statics;
                
                set_model_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                set_model_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                set_model_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                set_model_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");
        
            } else if (strcmp(l, "mouse_clicked") == 0) {
        
                void* main_frame = get_statics_model_part(statics, (void*) "main_frame");
                struct vector* pointer_position = get_statics_model_part(statics, (void*) "mouse.pointer_position");
                
                reset_signal(s);
        
                if (pointer_position != 0) {
                 
    //??            mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);
                    
                } else {
                    
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is null.");
                }
            }
*/
        } else {
    
            log_message((void*) &ERROR_LOG_LEVEL, "Could not handle operation signal. The inputs/outputs is null.");
        }
    
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not handle operation signal. The signal dynamics model is null.");
    }
}

/* SIGNAL_MEMORY_HANDLER_SOURCE */
#endif

