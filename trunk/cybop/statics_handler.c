/*
 * $RCSfile: statics_handler.c,v $
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

#ifndef STATICS_HANDLER_SOURCE
#define STATICS_HANDLER_SOURCE

#include <string.h>
#include "boolean_handler.c"
#include "complex_handler.c"
#include "fraction_handler.c"
#include "integer_handler.c"
#include "log_handler.c"
#include "model_handler.c"
#include "statics.c"
#include "string_handler.c"
#include "time_handler.c"
#include "vector_handler.c"

/**
 * This is the statics handler.
 *
 * It implements static operators.
 * A model is retrieved by instantiating a model source.
 *
 * @version $Revision: 1.14 $ $Date: 2003-10-22 14:41:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Complex statics model.
//

/**
 * Initializes the child.
 *
 * @param p0 the complex statics model
 * @param p1 the child model source attributes
 */
static void initialize_child(void* p0, void* p1) {

/*??
    struct item* i = (struct item*) p0;
    
    if (i != 0) {
            
        log((void*) &INFO_LOG_LEVEL, "Initialize item element.");
        void* name = get_map_element(p1, NAME);                
        void* category = 0;                
        void* abstraction = 0;                
        void* o = 0;

        // Item.
        category = get_map_element(p1, ITEM_CATEGORY);
        abstraction = get_map_element(p1, ITEM_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->children, name, o);

        // Position.
        category = get_map_element(p1, POSITION_CATEGORY);
        abstraction = get_map_element(p1, POSITION_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->positions, name, o);

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize item element. The item is null.");
    }
*/
}

/**
 * Finalizes the child.
 *
 * @param p0 the complex statics model
 * @param p1 the child model source attributes
 */
static void finalize_child(void* p0, void* p1) {
}

/**
 * Initializes the children.
 *
 * @param p0 the complex statics model
 * @param p1 the children models sources
 */
static void initialize_children(void* p0, void* p1) {

/*??
    struct map* m = (struct map*) p1;
    int count = 0;
    int size = get_map_size(m);
    struct item* ci = 0;
    struct item* o = 0;

    while (count < size) {
    
        ci = (struct item*) get_map_element(m, count);

        if (ci != 0) {
            
            initialize_child_item(p0, ci->items);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not initialize items. A category item is null.");
        }
        
        count++;
    }
*/
}

/**
 * Finalizes the children.
 *
 * @param p0 the complex statics model
 * @param p1 the children models sources
 */
static void finalize_children(void* p0, void* p1) {
}

/**
 * Initializes the complex statics.
 *
 * @param p0 the complex statics model
 * @param p1 the model source
 */
static void initialize_complex_statics(void* p0, void* p1) {

/*??
    log((void*) &INFO_LOG_LEVEL, "Initialize item: " + p1);

    // Create temporary category item.
    struct item* c = (struct item*) malloc(sizeof(item));
    initialize_item_containers(c);

    // Read category from file.
    initialize_category(c, p1);

    // Initialize elements with category.
    if (c != 0) {

        initialize_child_items(p0, c->children);
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize item elements. The category is null.");
    }

    // Destroy temporary category item.        
    finalize_item_containers(c);
    free(c);
*/
}

/**
 * Finalizes the complex statics.
 *
 * @param p0 the complex statics model
 * @param p1 the model source
 */
static void finalize_complex_statics(void* p0, void* p1) {

/*??
    log((void*) &INFO_LOG_LEVEL, "Finalize item: " + p1);
    
    // Create temporary category item.
    struct item* c = (struct item*) malloc(sizeof(item));
    initialize_item_containers(c);

    // Finalize elements with category.
    if (c != 0) {
        
        finalize_child_items(p0, c->children);
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not finalize item elements. The category is null.");
    }

    // Write category to file.
    finalize_category(c, p1);

    // Destroy temporary category item.        
    finalize_item_containers(c);
    free(c);
*/
}

/**
 * Creates a complex statics model.
 *
 * @param p0 the model source
 * @return the complex statics model
 */
static void* create_complex_statics_model(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create complex statics model.");

        if (strcmp(p0, "") != 0) {
            
            i = malloc(sizeof(struct model));

            initialize_complex_statics(i, p0);
            initialize_model(i, p0);
        }
    }
    
    return i;
}

/**
 * Destroys the complex statics model.
 *
 * @param p0 the complex statics model
 * @param p1 the model source
 */
static void destroy_complex_statics_model(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy complex statics model.");

        if (strcmp(p1, "") != 0) {
            
            finalize_model(p0, p1);
            finalize_complex_statics(p0, p1);
        }

        free(p0);
    }
}

//
// Statics model.
//

/**
 * Creates a statics model.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the statics model
 */
static void* create_statics_model(void* p0, void* p1) {

    void* m = 0;
    
    if (p0 != 0) {
        
        if (strcmp((char*) p0, "") != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Create statics model: ");
            log((void*) &INFO_LOG_LEVEL, p0);
    
            if (strcmp(p1, COMPLEX_STATICS_MODEL) == 0) {
        
                m = malloc(sizeof(struct model));
                initialize_statics_model(m, p0);
        
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
 * Destroys the statics model.
 *
 * @param p0 the statics model
 * @param p1 the model source
 * @param p2 the abstraction
 */
static void destroy_statics_model(void* p0, void* p1, void* p2) {

    if (p0 != 0) {
        
        if (p1 != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Destroy statics model: ");
            log((void*) &INFO_LOG_LEVEL, p1);
        
            if (strcmp(p2, COMPLEX_STATICS_MODEL) == 0) {
        
                finalize_statics_model(p0, p1);
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

/* STATICS_HANDLER_SOURCE */
#endif

