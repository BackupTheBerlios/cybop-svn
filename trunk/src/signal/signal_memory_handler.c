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
#include "dynamics_model.c"
#include "map.c"
#include "map_handler.c"
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
 * @version $Revision: 1.2 $ $Date: 2003-12-03 15:10:14 $ $Author: christian $
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
 * @param p3 the abstraction
 * @param p4 the priority
 */
static void set_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    struct signal_memory* m = (struct signal_memory*) p0;
    
    if (m != 0) {
        
        set_array_element(m->signals, p1, p2);
        set_array_element(m->abstractions, p1, p3);
        set_array_element(m->priorities, p1, p4);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not set signal. The signal memory is null.");
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
        remove_array_element(m->abstractions, p1);
        remove_array_element(m->priorities, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The signal memory is null.");
    }
}

/**
 * Gets the signal.
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
 * Gets the abstraction.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the abstraction
 */
static void* get_abstraction(void* p0, void* p1) {

    void* a = 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != 0) {

        a = get_array_element(m->abstractions, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get abstraction. The signal memory is null.");
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
static void* get_priority(void* p0, void* p1) {

    void* p = 0;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != 0) {

        p = get_array_element(m->priorities, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get priority. The signal memory is null.");
    }
    
    return p;
}

/**
 * Gets the index of the signal with highest priority.
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

        log((void*) &ERROR_LOG_LEVEL, "Could not get index of the signal with highest priority. The signal memory is null.");
    }
    
    return index;
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
static void handle_compound_signal(void* p0, void* p1, void* p2) {

    log((void*) &INFO_LOG_LEVEL, "Handle compound signal:");

    struct dynamics_model* m = (struct dynamics_model*) p1;
    
    if (m != null) {

        int count = get_array_count(m->parts);
        int pos = 0;
        int i = 0;
        void* abstr = 0;
        void* part = 0;

        // All positions.
        while (pos < count) {
            
            // All parts.
            while (i < count) {
                
                // All parts at the current position.
                if (get_map_element_at_index(m->positions, i) == pos) {

                    // Determine part signal as dynamics model.
                    part = get_map_element_at_index(m->parts, i);
                
                    // Determine abstraction.
                    abstr = get_map_element_at_index(m->abstractions, i);

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

        log((void*) &ERROR_LOG_LEVEL, "Could not handle compound signal. The signal dynamics model is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the operation signal
 * @param p1 the abstraction
 * @param p2 the statics
 * @param p3 the dynamics
 * @param p4 the shutdown flag
 */
static void handle_operation_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log((void*) &INFO_LOG_LEVEL, "Handle operation signal:");
    log((void*) &INFO_LOG_LEVEL, l);

    struct operation* o = (struct operation*) p0;
    
    if (o != null) {

        char* a = (char*) p1;
        void* io = o->inputs_outputs;
    
        if (io != 0) {
    
            if (strcmp(a, ADD_OPERATION) == 0) {
                
                // Dereference function pointer and hand over inputs and outputs.
                add(get_map_element_with_name(io, "summand_0"), get_map_element_with_name(io, "summand_1"), get_map_element_with_name(io, "sum"));

            } else if (strcmp(a, CREATE_STATICS_OPERATION) == 0) {
        
                struct statics_model* s = (struct statics_model*) p2;
                
                if (s != null) {
                        
                    m = create_statics_model(get_map_element_with_name(io, "model"), get_map_element_with_name(io, "abstraction"));
                    set_map_element_with_name(s->parts, get_map_element_with_name(io, "name"), m);
        
                } else {
            
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle create statics operation signal. The statics is null.");
                }

            } else if (strcmp(a, DESTROY_STATICS_OPERATION) == 0) {
        
                struct statics_model* s = (struct statics_model*) p2;
                
                if (s != null) {
                        
                    m = get_map_element_with_name(s->parts, get_map_element_with_name(io, "name"));
                    destroy_statics_model(m, get_map_element_with_name(io, "model"), get_map_element_with_name(io, "abstraction"));
        
                } else {
            
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle destroy statics operation signal. The statics is null.");
                }

            } else if (strcmp(a, CREATE_DYNAMICS_OPERATION) == 0) {
        
                struct dynamics_model* d = (struct dynamics_model*) p3;
                
                if (d != null) {
                        
                    void* m = create_dynamics_model(get_map_element_with_name(io, "model"), get_map_element_with_name(io, "abstraction"));
                    set_map_element_with_name(d->parts, get_map_element_with_name(io, "name"), m);
        
                } else {
            
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle create dynamics operation signal. The dynamics is null.");
                }

            } else if (strcmp(a, DESTROY_DYNAMICS_OPERATION) == 0) {
        
                struct dynamics_model* d = (struct dynamics_model*) p3;
                
                if (d != null) {
                        
                    void* m = get_map_element_with_name(d->parts, get_map_element_with_name(io, "name"));
                    destroy_dynamics_model(m, get_map_element_with_name(io, "model"), get_map_element_with_name(io, "abstraction"));
        
                } else {
            
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle destroy dynamics operation signal. The dynamics is null.");
                }

            } else if (strcmp(a, EXIT_OPERATION) == 0) {
        
                // Set shutdown flag.
                int* f = (int*) p4;
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
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is null.");
                }
            }
*/
        } else {
    
            log((void*) &ERROR_LOG_LEVEL, "Could not handle operation signal. The inputs/outputs is null.");
        }
    
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not handle operation signal. The signal dynamics model is null.");
    }
}

/* SIGNAL_MEMORY_HANDLER_SOURCE */
#endif

