/*
 * $RCSfile: statics_model_handler.c,v $
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

#ifndef STATICS_MODEL_HANDLER_SOURCE
#define STATICS_MODEL_HANDLER_SOURCE

// General.
#include <string.h>
#include "log_handler.c"
#include "map.c"
#include "map_handler.c"
#include "statics.c"
#include "statics_cybol_model_handler.c"
#include "statics_model.c"

// Statics.
#include "boolean_handler.c"
#include "complex_handler.c"
#include "fraction_handler.c"
#include "integer_handler.c"
#include "string_handler.c"
#include "time_handler.c"
#include "vector_handler.c"

/**
 * This is the statics model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.2 $ $Date: 2003-12-03 15:10:14 $ $Author: christian $
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
static void* create_statics_model(void* p0, void* p1);

/**
 * Destroys the statics model.
 *
 * @param p0 the statics model
 * @param p1 the model source
 * @param p2 the abstraction
 */
static void destroy_statics_model(void* p0, void* p1, void* p2);

//
// Statics model containers.
//

/**
 * Creates the statics model containers.
 *
 * @param p0 the statics model
 */
static void create_statics_model_containers(void* p0) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create statics model containers.");

        m->parts = malloc(sizeof(struct map));
        initialize_map(m->parts);

        m->positions = malloc(sizeof(struct map));
        initialize_map(m->positions);
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not create statics model containers. The statics model is null.");
    }
}

/**
 * Destroys the statics model containers.
 *
 * @param p0 the statics model
 */
static void destroy_statics_model_containers(void* p0) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy statics model containers.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->parts);
        free(m->parts);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not destroy statics model containers. The statics model is null.");
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
static void initialize_statics_part(void* p0, void* p1) {
        
    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
            
        void* name = get_map_element_with_name(p1, (void*) NAME);                
        void* model = 0;
        void* abstraction = 0;
        void* memory_model = 0;

        // Part.
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->parts, name, memory_model);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->positions, name, memory_model);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize statics part. The statics model is null.");
    }
}

/**
 * Finalizes the statics part.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model part attributes
 */
static void finalize_statics_part(void* p0, void* p1) {

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
        destroy_statics_model(memory_model, model, abstraction);

        // Part.
        memory_model = get_map_element_with_name(m->parts, name);
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        destroy_statics_model(memory_model, model, abstraction);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not finalize statics part. The statics model is null.");
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
static void initialize_statics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct statics_model* e = 0;

    while (count < *size) {
    
        e = (struct statics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            initialize_statics_part(p0, e->parts);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize statics parts. A statics cybol model part is null.");
        }
        
        count++;
    }
}

/**
 * Finalizes the statics parts.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model parts
 */
static void finalize_statics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct statics_model* e = 0;

    while (count < *size) {
    
        e = (struct statics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            finalize_statics_part(p0, e->parts);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize statics parts. A statics cybol model part is null.");
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
static void initialize_statics_model(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize statics model.");

        // Create temporary statics cybol model.
        struct statics_model* cybol = (struct statics_model*) malloc(sizeof(struct statics_model));
        create_statics_model_containers((void*) cybol);

        // Read statics cybol model from file path.
        read_statics_cybol_model((void*) cybol, p1);
    
        // Initialize statics model parts with statics cybol model.
        if (cybol != 0) {
    
            initialize_statics_parts(p0, cybol->parts);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The statics cybol model is null.");
        }
    
        // Destroy temporary statics cybol model.
        destroy_statics_model_containers((void*) cybol);
        free((void*) cybol);
    
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The statics model is null.");
    }
}

/**
 * Finalizes the statics model to a statics cybol model.
 *
 * @param p0 the statics model
 * @param p1 the statics cybol model path
 */
static void finalize_statics_model(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize statics model.");

        // Create temporary statics cybol model.
        struct statics_model* cybol = (struct statics_model*) malloc(sizeof(struct statics_model));
        create_statics_model_containers((void*) cybol);

        // Finalize statics model parts with statics cybol model.
        if (cybol != 0) {
            
            finalize_statics_parts(p0, cybol->parts);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The statics cybol model is null.");
        }
    
        // Write statics cybol model to file path.
        write_statics_cybol_model((void*) cybol, p1);
    
        // Destroy temporary statics cybol model.
        destroy_statics_model_containers((void*) cybol);
        free((void*) cybol);
    
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The statics model is null.");
    }
}

//
// Statics model part.
//

/**
 * Sets the statics model part.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 * @param p2 the part
 * @param p3 the position
 */
static void set_statics_model_part(void* p0, void* p1, void* p2, void* p3) {

    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Set statics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {

            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            set_statics_model_part(part, r, p2, p3);
            
        } else {

            // The given model is the compound of the part.
            set_map_element_with_name(m->parts, n, p2);
            set_map_element_with_name(m->positions, n, p3);
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not set statics model part. The statics model is null.");
    }
}

/**
 * Removes the statics model part.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 */
static void remove_statics_model_part(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Remove statics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            remove_statics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            remove_map_element_with_name(m->parts, n);
            remove_map_element_with_name(m->positions, n);
        }
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove statics model part. The statics model is null.");
    }
}

/**
 * Returns the statics model part.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 * @return the part
 */
static void* get_statics_model_part(void* p0, void* p1) {

    void* p = 0;
    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get statics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_statics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->parts, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get statics model part. The statics model is null.");
    }
    
    return p;
}

/**
 * Returns the statics model part position.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 * @return the part position
 */
static void* get_statics_model_part_position(void* p0, void* p1) {

    void* p = 0;
    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get statics model part position: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_statics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->positions, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get statics model part position. The statics model is null.");
    }
    
    return p;
}

/* STATICS_MODEL_HANDLER_SOURCE */
#endif

