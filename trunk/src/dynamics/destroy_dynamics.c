/*
 * $RCSfile: destroy_dynamics.c,v $
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

#ifndef DESTROY_DYNAMICS_SOURCE
#define DESTROY_DYNAMICS_SOURCE

#include "cybol_model_handler.c"
#include "dynamics.c"
#include "dynamics_cybol_model_handler.c"
#include "dynamics_model.c"
#include "map.c"
#include "map_handler.c"
#include "operation_handler.c"

/**
 * This is the destroy dynamics operation.
 *
 * It destroys a dynamics memory model to a given dynamics cybol model.
 *
 * @version $Revision: 1.5 $ $Date: 2003-12-15 14:48:59 $ $Author: christian $
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
 * This is the destroy dynamics operation.
 *
 * It destroys a dynamics memory model to a given dynamics cybol model.
 *
 * @param p0 the dynamics memory model
 * @param p1 the dynamics cybol model path
 * @param p2 the dynamics cybol input output names
 * @param p3 the dynamics cybol input output values
 * @param p4 the abstraction
 */
void destroy_dynamics(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Destroys the statics model.
 *
 * @param p0 the statics model
 * @param p1 the model source
 * @param p2 the abstraction
 */
void destroy_statics(void* p0, void* p1, void* p2);

//
// Dynamics model containers.
//

/**
 * Destroys the dynamics model containers.
 *
 * @param p0 the dynamics model
 */
void destroy_dynamics_model_containers(void* p0) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Destroy dynamics model containers.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->abstractions);
        free(m->abstractions);

        finalize_map(m->parts);
        free(m->parts);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not destroy dynamics model containers. The dynamics model is null.");
    }
}

//
// Dynamics part.
//

/**
 * Finalizes the dynamics part.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model part attributes
 */
void finalize_dynamics_part(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {

        void* name = get_map_element_with_name(p1, (void*) NAME);                
        void* model = 0;
        void* io_names = 0;
        void* io_values = 0;
        void* abstraction = 0;
        void* memory_model = 0;

        // Position.
        memory_model = get_map_element_with_name(m->positions, name);
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        destroy_statics(memory_model, model, abstraction);

        // Part.
        memory_model = get_map_element_with_name(m->parts, name);
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        io_names = get_map_element_with_name(p1, (void*) PART_INPUT_OUTPUT_NAMES);
        io_values = get_map_element_with_name(p1, (void*) PART_INPUT_OUTPUT_VALUES);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        destroy_dynamics(memory_model, model, io_names, io_values, abstraction);

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics part. The dynamics model is null.");
    }
}

//
// Dynamics parts.
//

/**
 * Finalizes the dynamics parts.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model parts
 */
void finalize_dynamics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int size = 0;
    get_map_size(m, (void*) &size);
    struct dynamics_model* e = 0;

    while (count < size) {
    
        e = (struct dynamics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            finalize_dynamics_part(p0, e->parts);

        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics parts. A dynamics cybol model part is null.");
        }
        
        count++;
    }
}

//
// Dynamics model.
//

/**
 * Finalizes the dynamics model to a dynamics cybol model.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model
 */
void finalize_dynamics_model(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Finalize dynamics model.");

/*??
        // Create temporary dynamics cybol model.
        struct dynamics_model* cybol = (struct dynamics_model*) malloc(sizeof(struct dynamics_model));
        create_dynamics_model_containers((void*) cybol);

        // Finalize dynamics model parts with dynamics cybol model.
        if (cybol != 0) {
            
            finalize_dynamics_parts(p0, cybol->parts);
            
        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics model. The dynamics cybol model is null.");
        }
    
        // Write dynamics cybol model to file.
        finalize_dynamics_cybol_model((void*) cybol, p1);
    
        // Destroy temporary dynamics cybol model.
        destroy_dynamics_model_containers((void*) cybol);
        free((void*) cybol);
*/
    
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics model. The dynamics model is null.");
    }
}

/**
 * This is the destroy dynamics operation.
 *
 * It destroys a dynamics memory model to a given dynamics cybol model.
 *
 * @param p0 the dynamics memory model
 * @param p1 the dynamics cybol model path
 * @param p2 the dynamics cybol input output names
 * @param p3 the dynamics cybol input output values
 * @param p4 the abstraction
 */
void destroy_dynamics(void* p0, void* p1, void* p2, void* p3, void* p4) {

    char* a = (char*) p4;

    if (p0 != 0) {
            
        log_message((void*) &INFO_LOG_LEVEL, "Destroy dynamics model: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);
    
        if (strcmp(a, DYNAMICS_COMPOUND) == 0) {
    
            char* p = (char*) p1;
        
            if (p != 0) {
                
                finalize_dynamics_model(p0, p1);
                destroy_dynamics_model_containers(p0);
                free(p0);
            }

        } else {
    
            char* io = (char*) p2;
            
            if (io != 0) {
                
                finalize_operation_input_and_output(p0, p2, p3);
                free(p0);
            }
        }
    }
}

/* DESTROY_DYNAMICS_SOURCE */
#endif

