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

#include "add_handler.c"
#include "and_handler.c"
#include "divide_handler.c"
#include "dynamics.c"
#include "dynamics_cybol_model_handler.c"
#include "dynamics_model.c"
#include "equal_handler.c"
#include "greater_handler.c"
#include "greater_or_equal_handler.c"
#include "multiply_handler.c"
#include "or_handler.c"
#include "smaller_handler.c"
#include "smaller_or_equal_handler.c"
#include "subtract_handler.c"

/**
 * This is the create dynamics operation.
 *
 * It creates a dynamics memory model from a given dynamics cybol model.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-05 12:10:33 $ $Author: christian $
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
 * Creates a dynamics.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the dynamics model
 */
void* create_dynamics(void* p0, void* p1);

//
// Dynamics model containers.
//

/**
 * Creates the dynamics model containers.
 *
 * @param p0 the dynamics model
 */
static void create_dynamics_model_containers(void* p0) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create dynamics model containers.");

        m->parts = malloc(sizeof(struct map));
        initialize_map(m->parts);

        m->inputs_0 = malloc(sizeof(struct map));
        initialize_map(m->inputs_0);

        m->inputs_1 = malloc(sizeof(struct map));
        initialize_map(m->inputs_1);

        m->outputs_0 = malloc(sizeof(struct map));
        initialize_map(m->outputs_0);

        m->outputs_1 = malloc(sizeof(struct map));
        initialize_map(m->outputs_1);

        m->positions = malloc(sizeof(struct map));
        initialize_map(m->positions);
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not create dynamics model containers. The dynamics model is null.");
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
static void initialize_dynamics_part(void* p0, void* p1) {
        
    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
            
        void* name = get_map_element_with_name(p1, (void*) NAME);                
        void* model = 0;
        void* abstraction = 0;
        void* memory_model = 0;

        // Part.
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        memory_model = create_dynamics(model, abstraction);
        set_map_element_with_name(m->parts, name, memory_model);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        memory_model = create_statics(model, abstraction);
        set_map_element_with_name(m->positions, name, memory_model);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics part. The dynamics model is null.");
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
static void initialize_dynamics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct dynamics_model* e = 0;

    while (count < *size) {
    
        e = (struct dynamics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            initialize_dynamics_part(p0, e->parts);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics parts. A dynamics cybol model part is null.");
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
static void initialize_dynamics_model(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize dynamics model.");

        // Create temporary dynamics cybol model.
        struct dynamics_model* cybol = (struct dynamics_model*) malloc(sizeof(struct dynamics_model));
        create_dynamics_model_containers((void*) cybol);

        // Read dynamics cybol model from file.
        initialize_dynamics_cybol_model((void*) cybol, p1);
    
        // Initialize dynamics model parts with dynamics cybol model.
        if (cybol != 0) {
    
            initialize_dynamics_parts(p0, cybol->parts);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics model. The dynamics cybol model is null.");
        }
    
        // Destroy temporary dynamics cybol model.
        destroy_dynamics_model_containers((void*) cybol);
        free((void*) cybol);
    
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics model. The dynamics model is null.");
    }
}

/**
 * This is the create dynamics operation.
 *
 * It creates a dynamics memory model from a given dynamics cybol model.
 *
 * @param p0 the dynamics cybol model path
 * @param p1 the dynamics cybol inputs and outputs
 * @param p2 the abstraction
 * @return the dynamics model
 */
void* create_dynamics(void* p0, void* p1, void* p2) {

    void* m = 0;
    char* a = (char*) p2;
    
    log((void*) &INFO_LOG_LEVEL, "Create dynamics model: ");
    log((void*) &INFO_LOG_LEVEL, p0);

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
            
            if (strcmp(io, "") != 0) {
                
                m = malloc(sizeof(struct operation));
                initialize_operation_model(m, p1);
            }
        }
    }

    return m;
}

/* CREATE_DYNAMICS_SOURCE */
#endif

