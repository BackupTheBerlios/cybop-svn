/*
 * $RCSfile: create_statics.c,v $
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

#ifndef CREATE_STATICS_SOURCE
#define CREATE_STATICS_SOURCE

#include "boolean_handler.c"
#include "complex_handler.c"
#include "cybol_model_handler.c"
#include "fraction_handler.c"
#include "integer_handler.c"
#include "statics.c"
#include "statics_cybol_model_handler.c"
#include "statics_model.c"
#include "string_handler.c"
#include "time_handler.c"
#include "vector_handler.c"

/**
 * This is the create statics operation.
 *
 * It creates a statics memory model from a given statics cybol model.
 *
 * @version $Revision: 1.4 $ $Date: 2003-12-11 13:42:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Forward declaration.
//
// These functions are the only forward declarations. They are needed
// because models can recursively create/ destroy compound models using
// functions which are defined in statics_model_handler.
//

/**
 * Creates a statics model.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the statics model
 */
void* create_statics(void* p0, void* p1);

//
// Statics model containers.
//

/**
 * Creates the statics model containers.
 *
 * @param p0 the statics model
 */
void create_statics_model_containers(void* p0) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Create statics model containers.");

        m->parts = malloc(sizeof(struct map));
        initialize_map(m->parts);

        m->positions = malloc(sizeof(struct map));
        initialize_map(m->positions);
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not create statics model containers. The statics model is null.");
    }
}

//
// Statics part.
//

/**
 * Initializes the statics part.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model part attributes
 */
void initialize_statics_part(void* p0, void* p1) {
        
    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
            
        void* name = get_map_element_with_name(p1, (void*) NAME);                
        void* model = 0;
        void* abstraction = 0;
        void* memory_model = 0;

        // Part.
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        memory_model = create_statics(model, abstraction);
        set_map_element_with_name(m->parts, name, memory_model);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        memory_model = create_statics(model, abstraction);
        set_map_element_with_name(m->positions, name, memory_model);

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize statics part. The statics model is null.");
    }
}

//
// Statics parts.
//

/**
 * Initializes the statics parts.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model parts
 */
void initialize_statics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct statics_model* e = 0;

    while (count < *size) {
    
        e = (struct statics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            initialize_statics_part(p0, e->parts);

        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize statics parts. A statics cybol model part is null.");
        }
        
        count++;
    }
}

//
// Statics model.
//

/**
 * Initializes the statics model from a statics cybol model.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model path
 */
void initialize_statics_model(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize statics model.");

/*??
        // Create temporary statics cybol model.
        struct statics_model* cybol = (struct statics_model*) malloc(sizeof(struct statics_model));
        create_statics_model_containers((void*) cybol);

        // Read statics cybol model from file path.
        read_statics_cybol_model((void*) cybol, p1);
    
        // Initialize statics model parts with statics cybol model.
        if (cybol != 0) {
    
            initialize_statics_parts(p0, cybol->parts);
            
        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The statics cybol model is null.");
        }
    
        // Destroy temporary statics cybol model.
        destroy_statics_model_containers((void*) cybol);
        free((void*) cybol);
*/
    
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The statics model is null.");
    }
}

/**
 * This is the create statics operation.
 *
 * It creates a statics memory model from a given statics cybol model.
 *
 * @param p0 the statics cybol model path
 * @param p1 the abstraction
 * @return the statics model
 */
void* create_statics(void* p0, void* p1) {

    void* m = 0;
    char* p = (char*) p0;
    char* a = (char*) p1;
    
    if (p != 0) {
        
        if (strcmp(p, "") != 0) {
            
            log_message((void*) &INFO_LOG_LEVEL, "Create statics: ");
            log_message((void*) &INFO_LOG_LEVEL, p0);

            if (strcmp(a, STATICS_COMPOUND) == 0) {
        
                m = malloc(sizeof(struct statics_model));
                create_statics_model_containers(m);
                initialize_statics_model(m, p0);
        
            } else if (strcmp(a, TIME_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct time));
                initialize_time_model(m, p0);
                
            } else if (strcmp(a, STRING_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct string));
                initialize_string_model(m, p0);
        
            } else if (strcmp(a, VECTOR_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct vector));
                initialize_vector_model(m, p0);
        
            } else if (strcmp(a, COMPLEX_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct complex));
                initialize_complex_model(m, p0);
        
            } else if (strcmp(a, FRACTION_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct fraction));
                initialize_fraction_model(m, p0);
        
            } else if (strcmp(a, INTEGER_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct integer));
                initialize_integer_model(m, p0);
        
            } else if (strcmp(a, BOOLEAN_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct boolean));
                initialize_boolean_model(m, p0);
            }
        }
    }
        
    return m;
}

/* CREATE_STATICS_SOURCE */
#endif

