/*
 * $RCSfile: boolean_handler.c,v $
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

#include <string.h>
#include "model.c"
#include "map.c"
#include "map_handler.c"

/**
 * This is the model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.1 $ $Date: 2003-10-20 14:42:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Model.
//

/**
 * Initializes the model.
 *
 * @param p0 the model
 */
static void initialize_model(void* p0) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize model.");

        m->children = malloc(sizeof(struct map));
        initialize_map(m->children);
        m->positions = malloc(sizeof(struct map));
        initialize_map(m->positions);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize model. The model is null.");
    }
}

/**
 * Finalizes the model.
 *
 * @param p0 the model
 */
static void finalize_model(void* p0) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Finalize model.");

        finalize_map(m->positions);
        free(m->positions);

        finalize_map(m->children);
        free(m->children);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize model. The model is null.");
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

