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

#ifndef MODEL_HANDLER_SOURCE
#define MODEL_HANDLER_SOURCE

// General.
#include <string.h>
#include "dynamics.c"
#include "log_handler.c"
#include "map.c"
#include "map_handler.c"
#include "model.c"
#include "statics.c"
#include "xml_handler.c"

// Statics.
#include "boolean_handler.c"
#include "complex_handler.c"
#include "fraction_handler.c"
#include "integer_handler.c"
#include "string_handler.c"
#include "time_handler.c"
#include "vector_handler.c"

// Dynamics.
#include "add_handler.c"

/**
 * This is the model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.1 $ $Date: 2003-11-12 11:11:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Forward declaration.
//
// These functions are the only forward declarations. They are needed
// because models can recursively create/ destroy child models using
// functions which are defined in statics_handler and dynamics_handler.
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
// Model containers.
//

/**
 * Creates the model containers.
 *
 * @param p0 the model
 */
static void create_model_containers(void* p0) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create model containers.");

        m->children = malloc(sizeof(struct map));
        initialize_map(m->children);

        m->positions = malloc(sizeof(struct map));
        initialize_map(m->positions);
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not create model containers. The model is null.");
    }
}

/**
 * Destroys the model containers.
 *
 * @param p0 the model
 */
static void destroy_model_containers(void* p0) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy model containers.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->children);
        free(m->children);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not destroy model containers. The model is null.");
    }
}

//
// Child.
//

/**
 * Initializes the child.
 *
 * @param p0 the model
 * @param p1 the CYBOL model source child attributes
 */
static void initialize_child(void* p0, void* p1) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
            
        void* name = get_map_element_with_name(p1, (void*) NAME);                
        void* model = 0;
        void* abstraction = 0;                
        void* o = 0;

        // Child.
        model = get_map_element_with_name(p1, (void*) CHILD_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) CHILD_ABSTRACTION);
        o = create_model(model, abstraction);
        set_map_element_with_name(m->children, name, o);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        o = create_model(model, abstraction);
        set_map_element_with_name(m->positions, name, o);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize child. The model is null.");
    }
}

/**
 * Finalizes the child.
 *
 * @param p0 the model
 * @param p1 the CYBOL model source child attributes
 */
static void finalize_child(void* p0, void* p1) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {

/*??
        void* name = get_map_element_name(p1, (void*) NAME);
        void* model = 0;
        void* abstraction = 0;                
        void* o = 0;

        // Child.
        model = get_map_element_with_name(p1, (void*) CHILD_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) CHILD_ABSTRACTION);
        o = destroy_model(model, abstraction);
        o = get_map_element_with_name(m->children, name);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        o = destroy_model(model, abstraction);
        set_map_element_with_name(m->positions, name, o);
*/

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not finalize child. The model is null.");
    }
}

//
// Children.
//

/**
 * Initializes the children.
 *
 * @param p0 the model
 * @param p1 the CYBOL model source children
 */
static void initialize_children(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct model* e = 0;

    while (count < *size) {
    
        e = (struct model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            initialize_child(p0, e->children);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize children. A source model child is null.");
        }
        
        count++;
    }
}

/**
 * Finalizes the children.
 *
 * @param p0 the model
 * @param p1 the CYBOL model source children
 */
static void finalize_children(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int* size = (int*) get_map_size(m);
    struct model* e = 0;

    while (count < *size) {
    
        e = (struct model*) get_map_element_at_index(m, (void*) &count);

        if (e != 0) {
            
            finalize_child(p0, e->children);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize children. A source model child is null.");
        }
        
        count++;
    }
}

//
// Model.
//

/**
 * Initializes the model from a CYBOL model source.
 *
 * @param p0 the model
 * @param p1 the model source
 */
static void initialize_model(void* p0, void* p1) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize model.");

        // Create temporary source model.
        struct model* src = (struct model*) malloc(sizeof(struct model));
        create_model_containers((void*) src);

        // Read source model from CYBOL file.
        initialize_source_model((void*) src, p1);
    
        // Initialize model elements with source model.
        if (src != 0) {
    
            initialize_children(p0, src->children);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize model. The source model is null.");
        }
    
        // Destroy temporary source model.
        destroy_model_containers((void*) src);
        free((void*) src);
    
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize model. The model is null.");
    }
}

/**
 * Finalizes the model from a CYBOL model source.
 *
 * @param p0 the model
 * @param p1 the model source
 */
static void finalize_model(void* p0, void* p1) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize model.");

        // Create temporary source model.
        struct model* src = (struct model*) malloc(sizeof(struct model));
        create_model_containers((void*) src);

        // Finalize model elements with source model.
        if (src != 0) {
            
            finalize_children(p0, src->children);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize model. The source model is null.");
        }
    
        // Write source model to CYBOL file.
        finalize_source_model((void*) src, p1);
    
        // Destroy temporary source model.
        destroy_model_containers((void*) src);
        free((void*) src);
    
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize model. The model is null.");
    }
}

/**
 * Creates a model.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the model
 */
static void* create_model(void* p0, void* p1) {

    void* m = 0;
    
    if (p0 != 0) {
        
        if (strcmp((char*) p0, "") != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Create model: ");
            log((void*) &INFO_LOG_LEVEL, p0);

            if (strcmp(p1, COMPLEX_MODEL) == 0) {
        
                m = malloc(sizeof(struct model));
                create_model_containers(m);
                initialize_model(m, p0);
        
            } else if (strcmp(p1, TIME_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct time));
                initialize_time_model(m, p0);
                
            } else if (strcmp(p1, STRING_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct string));
                initialize_string_model(m, p0);
        
            } else if (strcmp(p1, VECTOR_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct vector));
                initialize_vector_model(m, p0);
        
            } else if (strcmp(p1, COMPLEX_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct complex));
                initialize_complex_model(m, p0);
        
            } else if (strcmp(p1, FRACTION_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct fraction));
                initialize_fraction_model(m, p0);
        
            } else if (strcmp(p1, INTEGER_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct integer));
                initialize_integer_model(m, p0);
        
            } else if (strcmp(p1, BOOLEAN_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct boolean));
                initialize_boolean_model(m, p0);
            }
        }
    }
        
    return m;
}

/**
 * Destroys the model.
 *
 * @param p0 the model
 * @param p1 the model source
 * @param p2 the abstraction
 */
static void destroy_model(void* p0, void* p1, void* p2) {

    if (p0 != 0) {
        
        if (p1 != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Destroy model: ");
            log((void*) &INFO_LOG_LEVEL, p1);
        
            if (strcmp(p2, COMPLEX_MODEL) == 0) {
        
                finalize_model(p0, p1);
                destroy_model_containers(p0);
                free(p0);

            } else if (strcmp(p2, TIME_PRIMITIVE) == 0) {
        
                finalize_time_model(p0, p1);
                free(p0);
                
            } else if (strcmp(p2, STRING_PRIMITIVE) == 0) {
        
                finalize_string_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, VECTOR_PRIMITIVE) == 0) {
        
                finalize_vector_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, COMPLEX_PRIMITIVE) == 0) {
        
                finalize_complex_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, FRACTION_PRIMITIVE) == 0) {
        
                finalize_fraction_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, INTEGER_PRIMITIVE) == 0) {
        
                finalize_integer_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, BOOLEAN_PRIMITIVE) == 0) {
        
                finalize_boolean_model(p0, p1);
                free(p0);
            }
        }
    }
}

//
// Helper functions.
//

/**
 * Returns the child name.
 *
 * It is the most left name before the first dot/point "." in the given string
 * or, if there is no dot, then it is the given name itself.
 *
 * @param p0 the hierarchical model name
 * @return the child name
 */
static void* get_child_name(void* p0) {
    
    void* name = 0;
    char* n = (char*) p0;
    
    if (n != 0) {
        
/*??
        int i = n->indexOf(".");
        
        if (i != -1) {
            
            p1 = n->substring(0, i);
        
        } else {
        
            p1 = n;
        }
*/
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not get child name. The hierarchical name is null.");
    }
    
    return name;
}

/**
 * Returns the remaining name.
 *
 * It is the whole string after the first dot/point ".".
 *
 * @param p0 the hierarchical model name
 * @return the remaining name
 */
static void* get_remaining_name(void* p0) {

    void* name = 0;    
    char* n = (char*) p0;
    
    if (n != 0) {
        
/*??
        int i = n->indexOf(".");
        
        if (i != -1) {

            p1 = n->substring(i + 1);
        }
*/
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not get remaining name. The hierarchical name is null.");
    }
    
    return name;
}

//
// Model element.
//

/**
 * Sets the model element.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 * @param p2 the element
 */
static void set_model_element(void* p0, void* p1, void* p2) {

    struct model* m = (struct model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Set model element: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_child_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {

            // The given model is the parent of another parent.
            void* child = get_map_element_with_name(m->children, n);
            
            // Continue to process along the hierarchical name.
            set_model_element(child, r, p2);
            
        } else {

            // The given model is the parent of the child.
            set_map_element_with_name(m->children, n, p2);
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not set model element. The model is null.");
    }
}

/**
 * Removes the model element.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 */
static void remove_model_element(void* p0, void* p1) {

    struct model* m = (struct model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Remove model element: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_child_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is the parent of another parent.
            void* child = get_map_element_with_name(m->children, n);
            
            // Continue to process along the hierarchical name.
            remove_model_element(child, r);
            
        } else {

            // The given model is the parent of the child.
            remove_map_element_with_name(m->children, n);
        }
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove model element. The model is null.");
    }
}

/**
 * Returns the model element.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 * @return the element
 */
static void* get_model_element(void* p0, void* p1) {

    void* e = 0;
    struct model* m = (struct model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get model element: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_child_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is the parent of another parent.
            void* child = get_map_element_with_name(m->children, n);
            
            // Continue to process along the hierarchical name.
            e = get_model_element(child, r);
            
        } else {

            // The given model is the parent of the child.
            e = get_map_element_with_name(m->children, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get model element. The model is null.");
    }
    
    return e;
}

//
// Signal handling.
//

/**
 * Handles the mouse clicked action.
 *
 * @param p0 the screen item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the action
 */
static void mouse_clicked_action(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != 0) {

/*??
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
*/

    } else {
        
        puts("ERROR: Could not handle mouse clicked action. The item is null.");
    }
}

/* MODEL_HANDLER_SOURCE */
#endif

