/*
 * $RCSfile: create_dynamics.c,v $
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

#ifndef CREATE_DYNAMICS_SOURCE
#define CREATE_DYNAMICS_SOURCE

#include "cybol_model_handler.c"
#include "dynamics.c"
#include "dynamics_cybol_model_handler.c"
#include "dynamics_model.c"
#include "map.c"
#include "map_handler.c"
#include "operation_handler.c"

/**
 * This is the create dynamics operation.
 *
 * It creates a dynamics memory model from a given dynamics cybol model.
 *
 * @version $Revision: 1.3 $ $Date: 2003-12-11 13:42:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Forward declaration.
//
// These functions are the only forward declarations. They are needed
// because models can recursively create/ destroy compound models using
// functions which are defined in dynamics_model_handler.
//

/**
 * This is the create dynamics operation.
 *
 * It creates a dynamics memory model from a given dynamics cybol model.
 *
 * @param p0 the dynamics cybol model path
 * @param p1 the dynamics cybol input output names
 * @param p2 the dynamics cybol input output values
 * @param p3 the abstraction
 * @return the dynamics model
 */
void* create_dynamics(void* p0, void* p1, void* p2, void* p3);

/**
 * Creates a statics model.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the statics model
 */
void* create_statics(void* p0, void* p1);

//
// Dynamics model containers.
//

/**
 * Creates the dynamics model containers.
 *
 * @param p0 the dynamics model
 */
void create_dynamics_model_containers(void* p0) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Create dynamics model containers.");

        m->parts = malloc(sizeof(struct map));
        initialize_map(m->parts);

        m->positions = malloc(sizeof(struct map));
        initialize_map(m->positions);
        
        m->abstractions = malloc(sizeof(struct map));
        initialize_map(m->abstractions);
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not create dynamics model containers. The dynamics model is null.");
    }
}

//
// Dynamics part.
//

/**
 * Initializes the dynamics part.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model part attributes
 */
void initialize_dynamics_part(void* p0, void* p1) {
        
    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
            
        void* name = get_map_element_with_name(p1, (void*) NAME);                
        void* model = 0;
        void* io_names = 0;
        void* io_values = 0;
        void* abstraction = 0;
        void* memory_model = 0;

        // Part.
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        io_names = get_map_element_with_name(p1, (void*) PART_INPUT_OUTPUT_NAMES);
        io_values = get_map_element_with_name(p1, (void*) PART_INPUT_OUTPUT_VALUES);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        memory_model = create_dynamics(model, io_names, io_values, abstraction);
        set_map_element_with_name(m->parts, name, memory_model);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        memory_model = create_statics(model, abstraction);
        set_map_element_with_name(m->positions, name, memory_model);

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics part. The dynamics model is null.");
    }
}

//
// Dynamics parts.
//

/**
 * Initializes the dynamics parts.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model parts
 */
void initialize_dynamics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct dynamics_model* e = 0;

    while (count < *size) {
    
        e = (struct dynamics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            initialize_dynamics_part(p0, e->parts);

        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics parts. A dynamics cybol model part is null.");
        }
        
        count++;
    }
}

//
// Dynamics model.
//

/**
 * Initializes the dynamics model from a dynamics cybol model.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model
 */
void initialize_dynamics_model(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize dynamics model.");

/*??
        // Create temporary dynamics cybol model.
        struct dynamics_model* cybol = (struct dynamics_model*) malloc(sizeof(struct dynamics_model));
        create_dynamics_model_containers((void*) cybol);

        // Read dynamics cybol model from file.
        initialize_dynamics_cybol_model((void*) cybol, p1);
    
        // Initialize dynamics model parts with dynamics cybol model.
        if (cybol != 0) {
    
            initialize_dynamics_parts(p0, cybol->parts);
            
        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics model. The dynamics cybol model is null.");
        }
    
        // Destroy temporary dynamics cybol model.
        destroy_dynamics_model_containers((void*) cybol);
        free((void*) cybol);
*/
    
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics model. The dynamics model is null.");
    }
}

/**
 * This is the create dynamics operation.
 *
 * It creates a dynamics memory model from a given dynamics cybol model.
 *
 * @param p0 the dynamics cybol model path
 * @param p1 the dynamics cybol input output names
 * @param p2 the dynamics cybol input output values
 * @param p3 the abstraction
 * @return the dynamics model
 */
void* create_dynamics(void* p0, void* p1, void* p2, void* p3) {

    void* m = 0;
    char* a = (char*) p3;
    
    log_message((void*) &INFO_LOG_LEVEL, "Create dynamics model: ");
    log_message((void*) &INFO_LOG_LEVEL, p0);

    if (strcmp(a, DYNAMICS_COMPOUND) == 0) {

        char* p = (char*) p0;
        
        if (p != 0) {
            
            if (strcmp(p, "") != 0) {
                
                m = malloc(sizeof(struct dynamics_model));
                create_dynamics_model_containers(m);
                initialize_dynamics_model(m, p0);
            }
        }

    } else {

        char* io = (char*) p1;
        
        if (io != 0) {
            
            if (strcmp(io, EMPTY_STRING) != 0) {
                
                m = malloc(sizeof(struct operation));
                initialize_operation_input_and_output(m, p1, p2);
            }
        }
    }

    return m;
}

/* CREATE_DYNAMICS_SOURCE */
#endif

