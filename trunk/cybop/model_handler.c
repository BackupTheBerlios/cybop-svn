/*
 * $RCSfile: model_handler.c,v $
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

#include <string.h>
#include "model.c"
#include "map.c"
#include "map_handler.c"
//?? #include "statics_handler.c"
#include "xml_handler.c"

/**
 * This is the model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.5 $ $Date: 2003-10-23 14:27:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Forward declaration.
//
// These two functions are the only forward declarations. They are needed
// because models can recursively create/ destroy child models.
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

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create statics model containers.");

        m->children = malloc(sizeof(struct map));
        initialize_map(m->children);

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

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy statics model containers.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->children);
        free(m->children);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not destroy statics model containers. The statics model is null.");
    }
}

//
// Child.
//

/**
 * Initializes the child.
 *
 * @param p0 the statics model
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
        o = create_statics_model(model, abstraction);
        set_map_element_with_name(m->children, name, o);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        o = create_statics_model(model, abstraction);
        set_map_element_with_name(m->positions, name, o);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize child. The statics model is null.");
    }
}

/**
 * Finalizes the child.
 *
 * @param p0 the statics model
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
        o = destroy_statics_model(model, abstraction);
        o = get_map_element_with_name(m->children, name);

        // Position.
        model = get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        o = destroy_statics_model(model, abstraction);
        set_map_element_with_name(m->positions, name, o);
*/

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not finalize child. The statics model is null.");
    }
}

//
// Children.
//

/**
 * Initializes the children.
 *
 * @param p0 the statics model
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
 * @param p0 the statics model
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
// Statics model.
//

/**
 * Initializes the statics model from a CYBOL model source.
 *
 * @param p0 the statics model
 * @param p1 the model source
 */
static void initialize_statics_model(void* p0, void* p1) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize statics model.");

        // Create temporary source model.
        struct model* src = (struct model*) malloc(sizeof(struct model));
        create_statics_model_containers((void*) src);

        // Read source model from CYBOL file.
        initialize_source_model((void*) src, p1);
    
        // Initialize statics model elements with source model.
        if (src != 0) {
    
            initialize_children(p0, src->children);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The source model is null.");
        }
    
        // Destroy temporary source model.
        destroy_statics_model_containers((void*) src);
        free((void*) src);
    
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The statics model is null.");
    }
}

/**
 * Finalizes the statics model from a CYBOL model source.
 *
 * @param p0 the statics model
 * @param p1 the model source
 */
static void finalize_statics_model(void* p0, void* p1) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize statics model.");

        // Create temporary source model.
        struct model* src = (struct model*) malloc(sizeof(struct model));
        create_statics_model_containers((void*) src);

        // Finalize statics model elements with source model.
        if (src != 0) {
            
            finalize_children(p0, src->children);
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The source model is null.");
        }
    
        // Write source model to CYBOL file.
        finalize_source_model((void*) src, p1);
    
        // Destroy temporary source model.
        destroy_statics_model_containers((void*) src);
        free((void*) src);
    
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The statics model is null.");
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
// Statics model element.
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

/* MODEL_HANDLER_SOURCE */
#endif

