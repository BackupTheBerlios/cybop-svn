/*
 * $RCSfile: dynamics_model_handler.c,v $
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

#ifndef DYNAMICS_MODEL_HANDLER_SOURCE
#define DYNAMICS_MODEL_HANDLER_SOURCE

// General.
#include <string.h>
#include "dynamics.c"
#include "dynamics_cybol_model_handler.c"
#include "dynamics_model.c"
#include "log_handler.c"
#include "map.c"
#include "map_handler.c"

// Dynamics.
#include "and_handler.c"
#include "or_handler.c"
#include "equal_handler.c"
#include "smaller_handler.c"
#include "greater_handler.c"
#include "smaller_or_equal_handler.c"
#include "greater_or_equal_handler.c"
#include "add_handler.c"
#include "subtract_handler.c"
#include "multiply_handler.c"
#include "divide_handler.c"

/**
 * This is the dynamics model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
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
 * Creates a dynamics model.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the dynamics model
 */
static void* create_dynamics_model(void* p0, void* p1);

/**
 * Destroys the dynamics model.
 *
 * @param p0 the dynamics model
 * @param p1 the model source
 * @param p2 the abstraction
 */
static void destroy_dynamics_model(void* p0, void* p1, void* p2);

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

/**
 * Destroys the dynamics model containers.
 *
 * @param p0 the dynamics model
 */
static void destroy_dynamics_model_containers(void* p0) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy dynamics model containers.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->outputs_1);
        free(m->outputs_1);

        finalize_map(m->outputs_0);
        free(m->outputs_0);

        finalize_map(m->inputs_1);
        free(m->inputs_1);

        finalize_map(m->inputs_0);
        free(m->inputs_0);

        finalize_map(m->parts);
        free(m->parts);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not destroy dynamics model containers. The dynamics model is null.");
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
        memory_model = create_dynamics_model(model, abstraction);
        set_map_element_with_name(m->parts, name, memory_model);

        // Input 0.
        model = get_map_element_with_name(p1, (void*) INPUT_0);
        abstraction = STRING_PRIMITIVE;
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->inputs_0, name, memory_model);

        // Input 1.
        model = get_map_element_with_name(p1, (void*) INPUT_1);
        abstraction = STRING_PRIMITIVE;
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->inputs_1, name, memory_model);

        // Output 0.
        model = get_map_element_with_name(p1, (void*) OUTPUT_0);
        abstraction = STRING_PRIMITIVE;
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->outputs_0, name, memory_model);

        // Output 1.
        model = get_map_element_with_name(p1, (void*) OUTPUT_1);
        abstraction = STRING_PRIMITIVE;
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->outputs_1, name, memory_model);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        memory_model = create_statics_model(model, abstraction);
        set_map_element_with_name(m->positions, name, memory_model);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize dynamics part. The dynamics model is null.");
    }
}

/**
 * Finalizes the dynamics part.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model part attributes
 */
static void finalize_dynamics_part(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
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

        // Output 1.
        memory_model = get_map_element_with_name(m->outputs_1, name);
        model = get_map_element_with_name(p1, (void*) OUTPUT_1);
        abstraction = STRING_PRIMITIVE;
        destroy_dynamics_model(memory_model, model, abstraction);

        // Output 0.
        memory_model = get_map_element_with_name(m->outputs_0, name);
        model = get_map_element_with_name(p1, (void*) OUTPUT_0);
        abstraction = STRING_PRIMITIVE;
        destroy_dynamics_model(memory_model, model, abstraction);

        // Input 1.
        memory_model = get_map_element_with_name(m->inputs_1, name);
        model = get_map_element_with_name(p1, (void*) INPUT_1);
        abstraction = STRING_PRIMITIVE;
        destroy_dynamics_model(memory_model, model, abstraction);

        // Input 0.
        memory_model = get_map_element_with_name(m->inputs_0, name);
        model = get_map_element_with_name(p1, (void*) INPUT_0);
        abstraction = STRING_PRIMITIVE;
        destroy_dynamics_model(memory_model, model, abstraction);

        // Part.
        memory_model = get_map_element_with_name(m->parts, name);
        model = get_map_element_with_name(p1, (void*) PART_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        destroy_dynamics_model(memory_model, model, abstraction);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics part. The dynamics model is null.");
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

/**
 * Finalizes the dynamics parts.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model parts
 */
static void finalize_dynamics_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct dynamics_model* e = 0;

    while (count < *size) {
    
        e = (struct dynamics_model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            finalize_dynamics_part(p0, e->parts);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics parts. A dynamics cybol model part is null.");
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
 * Finalizes the dynamics model to a dynamics cybol model.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model
 */
static void finalize_dynamics_model(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize dynamics model.");

        // Create temporary dynamics cybol model.
        struct dynamics_model* cybol = (struct dynamics_model*) malloc(sizeof(struct dynamics_model));
        create_dynamics_model_containers((void*) cybol);

        // Finalize dynamics model parts with dynamics cybol model.
        if (cybol != 0) {
            
            finalize_dynamics_parts(p0, cybol->parts);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics model. The dynamics cybol model is null.");
        }
    
        // Write dynamics cybol model to file.
        finalize_dynamics_cybol_model((void*) cybol, p1);
    
        // Destroy temporary dynamics cybol model.
        destroy_dynamics_model_containers((void*) cybol);
        free((void*) cybol);
    
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize dynamics model. The dynamics model is null.");
    }
}

/**
 * Creates a dynamics model.
 *
 * @param p0 the dynamics cybol model
 * @param p1 the abstraction
 * @return the dynamics model
 */
static void* create_dynamics_model(void* p0, void* p1) {

    void* m = 0;
    
    if (p0 != 0) {
        
        if (strcmp((char*) p0, "") != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Create dynamics model: ");
            log((void*) &INFO_LOG_LEVEL, p0);

            if (strcmp(p1, DYNAMICS_COMPOUND) == 0) {
        
                m = malloc(sizeof(struct dynamics_model));
                create_dynamics_model_containers(m);
                initialize_dynamics_model(m, p0);
        
            } else if (strcmp(p1, AND_OPERATION) == 0) {
        
                m = malloc(sizeof(struct and));
                initialize_and_model(m, p0);
                
            } else if (strcmp(p1, OR_OPERATION) == 0) {
        
                m = malloc(sizeof(struct or));
                initialize_or_model(m, p0);
                
            } else if (strcmp(p1, EQUAL_OPERATION) == 0) {
        
                m = malloc(sizeof(struct equal));
                initialize_equal_model(m, p0);
        
            } else if (strcmp(p1, SMALLER_OPERATION) == 0) {
        
                m = malloc(sizeof(struct smaller));
                initialize_smaller_model(m, p0);
        
            } else if (strcmp(p1, GREATER_OPERATION) == 0) {
        
                m = malloc(sizeof(struct greater));
                initialize_greater_model(m, p0);
        
            } else if (strcmp(p1, SMALLER_OR_EQUAL_OPERATION) == 0) {
        
                m = malloc(sizeof(struct smaller_or_equal));
                initialize_smaller_or_equal_model(m, p0);
        
            } else if (strcmp(p1, GREATER_OR_EQUAL_OPERATION) == 0) {
        
                m = malloc(sizeof(struct greater_or_equal));
                initialize_greater_or_equal_model(m, p0);
        
            } else if (strcmp(p1, ADD_OPERATION) == 0) {
        
                m = malloc(sizeof(struct add));
                initialize_add_model(m, p0);
        
            } else if (strcmp(p1, SUBTRACT_OPERATION) == 0) {
        
                m = malloc(sizeof(struct subtract));
                initialize_subtract_model(m, p0);
        
            } else if (strcmp(p1, MULTIPLY_OPERATION) == 0) {
        
                m = malloc(sizeof(struct multiply));
                initialize_multiply_model(m, p0);
        
            } else if (strcmp(p1, DIVIDE_OPERATION) == 0) {
        
                m = malloc(sizeof(struct divide));
                initialize_divide_model(m, p0);
            }
        }
    }
        
    return m;
}

/**
 * Destroys the dynamics model.
 *
 * @param p0 the dynamics model
 * @param p1 the dynamics cybol model
 * @param p2 the abstraction
 */
static void destroy_dynamics_model(void* p0, void* p1, void* p2) {

    if (p0 != 0) {
        
        if (p1 != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Destroy dynamics model: ");
            log((void*) &INFO_LOG_LEVEL, p1);
        
            if (strcmp(p2, DYNAMICS_COMPOUND) == 0) {
        
                finalize_dynamics_model(p0, p1);
                destroy_dynamics_model_containers(p0);
                free(p0);

            } else if (strcmp(p2, AND_OPERATION) == 0) {
        
                finalize_and_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, OR_OPERATION) == 0) {
        
                finalize_or_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, EQUAL_OPERATION) == 0) {
        
                finalize_equal_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, SMALLER_OPERATION) == 0) {
        
                finalize_smaller_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, GREATER_OPERATION) == 0) {
        
                finalize_greater_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, SMALLER_OR_EQUAL_OPERATION) == 0) {
        
                finalize_smaller_or_equal_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, GREATER_OR_EQUAL_OPERATION) == 0) {
        
                finalize_greater_or_equal_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, ADD_OPERATION) == 0) {
        
                finalize_add_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, SUBTRACT_OPERATION) == 0) {
        
                finalize_subtract_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, MULTIPLY_OPERATION) == 0) {
        
                finalize_multiply_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, DIVIDE_OPERATION) == 0) {
        
                finalize_divide_model(p0, p1);
                free(p0);
            }
        }
    }
}

//
// Dynamics model part.
//

/**
 * Sets the dynamics model part.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @param p2 the part
 * @param p3 the input 0
 * @param p4 the input 1
 * @param p5 the output 0
 * @param p6 the output 1
 * @param p7 the position
 */
static void set_dynamics_model_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Set dynamics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {

            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            set_dynamics_model_part(part, r, p2, p3, p4, p5, p6, p7);
            
        } else {

            // The given model is the compound of the part.
            set_map_element_with_name(m->parts, n, p2);
            set_map_element_with_name(m->inputs_0, n, p3);
            set_map_element_with_name(m->inputs_1, n, p4);
            set_map_element_with_name(m->outputs_0, n, p5);
            set_map_element_with_name(m->outputs_1, n, p6);
            set_map_element_with_name(m->positions, n, p7);
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not set dynamics model part. The dynamics model is null.");
    }
}

/**
 * Removes the dynamics model part.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 */
static void remove_dynamics_model_part(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Remove dynamics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            remove_dynamics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            remove_map_element_with_name(m->parts, n);
            remove_map_element_with_name(m->inputs_0, n);
            remove_map_element_with_name(m->inputs_1, n);
            remove_map_element_with_name(m->outputs_0, n);
            remove_map_element_with_name(m->outputs_1, n);
            remove_map_element_with_name(m->positions, n);
        }
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove dynamics model part. The dynamics model is null.");
    }
}

/**
 * Returns the dynamics model part.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part
 */
static void* get_dynamics_model_part(void* p0, void* p1) {

    void* p = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_dynamics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->parts, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part. The dynamics model is null.");
    }
    
    return p;
}

/**
 * Returns the dynamics model part input 0.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part input 0
 */
static void* get_dynamics_model_part_input_0(void* p0, void* p1) {

    void* i = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part input 0: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            i = get_dynamics_model_part_input_0(part, r);
            
        } else {

            // The given model is the compound of the part.
            i = get_map_element_with_name(m->inputs_0, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part input 0. The dynamics model is null.");
    }
    
    return i;
}

/**
 * Returns the dynamics model part input 1.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part input 1
 */
static void* get_dynamics_model_part_input_1(void* p0, void* p1) {

    void* i = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part input 1: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            i = get_dynamics_model_part_input_1(part, r);
            
        } else {

            // The given model is the compound of the part.
            i = get_map_element_with_name(m->inputs_1, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part input 1. The dynamics model is null.");
    }
    
    return i;
}

/**
 * Returns the dynamics model part output 0.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part output 0
 */
static void* get_dynamics_model_part_output_0(void* p0, void* p1) {

    void* o = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part output 0: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            o = get_dynamics_model_part_output_0(part, r);
            
        } else {

            // The given model is the compound of the part.
            o = get_map_element_with_name(m->outputs_0, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part output 0. The dynamics model is null.");
    }
    
    return o;
}

/**
 * Returns the dynamics model part output 1.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part output 1
 */
static void* get_dynamics_model_part_output_1(void* p0, void* p1) {

    void* o = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part output 1: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            o = get_dynamics_model_part_output_1(part, r);
            
        } else {

            // The given model is the compound of the part.
            o = get_map_element_with_name(m->outputs_1, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part output 1. The dynamics model is null.");
    }
    
    return o;
}

/**
 * Returns the dynamics model part position.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part position
 */
static void* get_dynamics_model_part_position(void* p0, void* p1) {

    void* p = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part position: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_dynamics_model_part_position(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->positions, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part position. The dynamics model is null.");
    }
    
    return p;
}

//??
//?? Old signal handling. Delete this block later!
//??

/**
 * Handles the mouse clicked action.
 *
 * @param p0 the screen item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the action
 */
/*??
static void mouse_clicked_action(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != 0) {

        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = 0;
        struct vector* position = 0;
        struct vector* expansion = 0;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = 0;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != 0) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != 0) {

                        // Determine child's expansion.
                        width = expansion->x;
                        height = expansion->y;
                        depth = expansion->z;
        
                        // Check if the given coordinates are in the child's screen area.
                        // The "if" conditions had to be inserted because in classical
                        // graphical user interfaces, the depth is normally 0 and
                        // such the boolean comparison would deliver "false".
                        // Using the conditions, the coordinates that are set to "0"
                        // are not considered for comparison.
                        contains = (x >= 0);
                        contains = contains && (x < width);
                        contains = contains && (y >= 0);
                        contains = contains && (y < height);
                        contains = contains && (z >= 0);
                        contains = contains && (z < depth);
        
                        if (contains == 1) {
        
                            // The given coordinates are in the child's screen area.
                            // Therefore, use the child's action.
                            action = mouse_clicked_action(child, x, y, z, p4);
                
                            break;
                        }

                    } else {
                        
                        log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. An expansion is null.");
                    }

                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. A position is null.");
                }

            } else {
                
                log((void*) &INFO_LOG_LEVEL, "Could not handle mouse clicked action. A child is not of type Item.");
            }
            
            count++;
        }
        
        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != 0) {
            
            p4 = action;

        } else {
            
            // Determine the action of the given screen item.
            get_map_element(i->items, "mouse_clicked_action", p4);
        }

    } else {
        
        puts("ERROR: Could not handle mouse clicked action. The item is null.");
    }
}

/* DYNAMICS_MODEL_HANDLER_SOURCE */
#endif

