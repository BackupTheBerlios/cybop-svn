/*
 * $RCSfile: destroy_statics.c,v $
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

#ifndef DESTROY_STATICS_SOURCE
#define DESTROY_STATICS_SOURCE

#include "../cybol/cybol_model_handler.c"
#include "../cybol/statics_cybol_model_handler.c"
#include "../model/statics.c"
#include "../model/statics_model.c"
#include "../statics/boolean_handler.c"
#include "../statics/complex_handler.c"
#include "../statics/fraction_handler.c"
#include "../statics/integer_handler.c"
#include "../statics/string_handler.c"
#include "../statics/time_handler.c"
#include "../statics/vector_handler.c"

/**
 * This is the destroy statics operation.
 *
 * It destroys a statics memory model to a given statics cybol model.
 *
 * @version $Revision: 1.8 $ $Date: 2004-01-05 20:24:12 $ $Author: christian $
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
 * Destroys the statics model.
 *
 * @param p0 the statics model
 * @param p1 the model source
 * @param p2 the abstraction
 */
void destroy_statics(void* p0, void* p1, void* p2);

//
// Statics model containers.
//

/**
 * Destroys the statics model containers.
 *
 * @param p0 the statics model
 */
void destroy_statics_model_containers(void* p0) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Destroy statics model containers.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->parts);
        free(m->parts);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not destroy statics model containers. The statics model is null.");
    }
}

//
// Statics part.
//

/**
 * Finalizes the statics part.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model part attributes
 */
void finalize_statics_part(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {

        void* name = get_map_element_with_name(p1, (void*) NAME);
        void* model = 0;
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
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        destroy_statics(memory_model, model, abstraction);

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize statics part. The statics model is null.");
    }
}

//
// Statics parts.
//

/**
 * Finalizes the statics parts.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model parts
 */
void finalize_statics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int size = 0;
    get_map_size(m, (void*) &size);
    struct statics_model* e = 0;

    while (count < size) {
    
        e = (struct statics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            finalize_statics_part(p0, e->parts);

        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize statics parts. A statics cybol model part is null.");
        }
        
        count++;
    }
}

//
// Statics model.
//

/**
 * Finalizes the statics model to a statics cybol model.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model path
 */
void finalize_statics_model(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Finalize statics model.");

/*??
        // Create temporary statics cybol model.
        struct statics_model* cybol = (struct statics_model*) malloc(sizeof(struct statics_model));
        create_statics_model_containers((void*) cybol);

        // Finalize statics model parts with statics cybol model.
        if (cybol != 0) {
            
            finalize_statics_parts(p0, cybol->parts);
            
        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The statics cybol model is null.");
        }
    
        // Write statics cybol model to file path.
        write_statics_cybol_model((void*) cybol, p1);
    
        // Destroy temporary statics cybol model.
        destroy_statics_model_containers((void*) cybol);
        free((void*) cybol);
*/
    
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The statics model is null.");
    }
}

/**
 * This is the destroy statics operation.
 *
 * It destroys a statics memory model to a given statics cybol model.
 *
 * @param p0 the statics memory model
 * @param p1 the statics cybol model path
 * @param p2 the abstraction
 */
void destroy_statics(void* p0, void* p1, void* p2) {

    char* p = (char*) p1;
    char* a = (char*) p2;

    if (p0 != 0) {
        
        if (p != 0) {
            
            log_message((void*) &INFO_LOG_LEVEL, "Destroy statics: ");
            log_message((void*) &INFO_LOG_LEVEL, p1);
        
            if (strcmp(a, STATICS_COMPOUND) == 0) {
        
                finalize_statics_model(p0, p1);
                destroy_statics_model_containers(p0);
                free(p0);

            } else if (strcmp(a, TIME_PRIMITIVE) == 0) {
        
                finalize_time_model(p0, p1);
                free(p0);
                
            } else if (strcmp(a, STRING_PRIMITIVE) == 0) {
        
                finalize_string_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, VECTOR_PRIMITIVE) == 0) {
        
                finalize_vector_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, COMPLEX_PRIMITIVE) == 0) {
        
                finalize_complex_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, FRACTION_PRIMITIVE) == 0) {
        
                finalize_fraction_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, INTEGER_PRIMITIVE) == 0) {
        
                finalize_integer_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, BOOLEAN_PRIMITIVE) == 0) {
        
                finalize_boolean_model(p0, p1);
                free(p0);
            }
        }
    }
}

/* DESTROY_STATICS_SOURCE */
#endif

