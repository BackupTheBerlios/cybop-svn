/*
 * $RCSfile: complex_handler.c,v $
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
#include "complex.c"
#include "map.c"
#include "map_handler.c"

/**
 * This is the complex handler.
 *
 * Complex elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.8 $ $Date: 2003-10-12 14:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Complex.
//

/**
 * Initializes the complex.
 *
 * @param p0 the complex
 */
static void initialize_complex(void* p0) {

    struct complex* c = (struct complex*) p0;
    
    if (c != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize complex.");

        c->children = malloc(sizeof(struct map));
        initialize_map(c->children);
        c->positions = malloc(sizeof(struct map));
        initialize_map(c->positions);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize complex. The complex is null.");
    }
}

/**
 * Finalizes the complex.
 *
 * @param p0 the complex
 */
static void finalize_complex(void* p0) {

    struct complex* c = (struct complex*) p0;
    
    if (c != 0) {

        log((void*) &INFO_LOG_LEVEL, "Finalize complex.");

        finalize_map(c->positions);
        free(c->positions);

        finalize_map(c->children);
        free(c->children);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize complex. The complex is null.");
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
 * @param p0 the hierarchical complex name
 * @param p1 the child name
 */
static void get_child_name(void* p0, void* p1) {
    
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
}

/**
 * Returns the remaining name.
 *
 * It is the whole string after the first dot/point ".".
 *
 * @param p0 the hierarchical complex name
 * @param p1 the remaining name
 */
static void get_remaining_name(void* p0, void* p1) {
    
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
}

//
// Complex element.
//

/**
 * Sets the complex element.
 *
 * @param p0 the complex
 * @param p1 the hierarchical complex name
 * @param p2 the element
 */
static void set_complex_element(void* p0, void* p1, void* p2) {

    struct complex* c = (struct complex*) p0;

    if (c != 0) {

        log((void*) &INFO_LOG_LEVEL, "Set complex element: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = 0;
        void* r = 0;
        
        get_child_name(p1, n);
        get_remaining_name(p1, r);
        
        if (r != 0) {

            // The given complex is the parent of another parent.
            void* child = 0;
            
            get_map_element_with_name(c->children, n, child);
            
            // Continue to process along the hierarchical name.
            set_complex_element(child, r, p2);
            
        } else {

            // The given complex is the parent of the child.
            set_map_element(c->children, n, p2);
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not set complex element. The complex is null.");
    }
}

/**
 * Removes the complex element.
 *
 * @param p0 the complex
 * @param p1 the hierarchical complex name
 */
static void remove_complex_element(void* p0, void* p1) {

    struct complex* c = (struct complex*) p0;

    if (c != 0) {

        log((void*) &INFO_LOG_LEVEL, "Remove complex element: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = 0;
        void* r = 0;
        
        get_child_name(p1, n);
        get_remaining_name(p1, r);
        
        if (r != 0) {
            
            // The given complex is the parent of another parent.
            void* child = 0;
            
            get_map_element_with_name(c->children, n, child);
            
            // Continue to process along the hierarchical name.
            remove_complex_element(child, r);
            
        } else {

            // The given complex is the parent of the child.
            remove_map_element_with_name(c->children, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove complex element. The complex is null.");
    }
}

/**
 * Returns the complex element.
 *
 * @param p0 the complex
 * @param p1 the hierarchical complex name
 * @param p2 the element
 */
static void get_complex_element(void* p0, void* p1, void* p2) {

    struct complex* c = (struct complex*) p0;

    if (c != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get complex element: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = 0;
        void* r = 0;
        
        get_child_name(p1, n);
        get_remaining_name(p1, r);
        
        if (r != 0) {
            
            // The given complex is the parent of another parent.
            void* child = 0;
            
            get_map_element_with_name(c->children, n, child);
            
            // Continue to process along the hierarchical name.
            get_complex_element(child, r, p2);
            
        } else {

            // The given complex is the parent of the child.
            get_map_element_with_name(c->children, n, p2);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get complex element. The complex is null.");
    }
}

