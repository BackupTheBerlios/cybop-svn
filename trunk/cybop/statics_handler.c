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
#include "complex.c"
#include "log_handler.c"
#include "statics.c"
#include "time.c"
#include "vector.c"
#include "xml_handler.c"

/**
 * This is the statics handler.
 *
 * It implements static operators.
 * An instance is retrieved by instantiating a model.
 *
 * @version $Revision: 1.11 $ $Date: 2003-10-20 10:52:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Complex statics instance.
//

/**
 * Initializes the child.
 *
 * @param p0 the complex statics instance
 * @param p1 the child model attributes
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
 * @param p0 the complex statics instance
 * @param p1 the child model attributes
 */
static void finalize_child(void* p0, void* p1) {
}

/**
 * Initializes the children.
 *
 * @param p0 the complex statics instance
 * @param p1 the children models
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
 * @param p0 the complex statics instance
 * @param p1 the children models
 */
static void finalize_children(void* p0, void* p1) {
}

/**
 * Initializes the complex statics.
 *
 * @param p0 the complex statics instance
 * @param p1 the model
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
 * @param p0 the complex statics instance
 * @param p1 the model
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
 * Creates a complex statics instance.
 *
 * @param p0 the model
 * @return the complex statics instance
 */
static void* create_complex_statics_instance(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create complex statics instance.");

        i = malloc(sizeof(struct complex));

        if (strcmp(p0, "") != 0) {
            
            initialize_complex_statics(i, p0);
            initialize_instance(i, p0);
        }
    }
    
    return i;
}

/**
 * Destroys the complex statics instance.
 *
 * @param p0 the complex statics instance
 * @param p1 the model
 */
static void destroy_complex_statics_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy complex statics instance.");

        if (strcmp(p1, "") != 0) {
            
            finalize_instance(p0, p1);
            finalize_complex_statics(p0, p1);
        }

        free(p0);
    }
}

//
// Boolean instance.
//

/**
 * Creates a boolean instance.
 *
 * @param p0 the model
 * @return the boolean instance
 */
static int create_boolean_instance(void* p0) {

    int i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create boolean instance.");

        if (strcmp(p0, "true")) {
            
            i = 1;
            
        } else if (strcmp(p0, "false")) {
            
            i = 0;
        }
    }
    
    return i;
}

/**
 * Destroys the boolean instance.
 *
 * @param p0 the boolean instance
 * @param p1 the model
 */
static void destroy_boolean_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy boolean instance.");

/*??
        if (*p0 != 0) {
            
            *p1 = "true";
            
        } else {
    
            *p1 = "false";        
        }
*/
    }
}

//
// Integer instance.
//

/**
 * Creates an integer instance.
 *
 * @param p0 the model
 * @return the integer instance
 */
static int create_integer_instance(void* p0) {

    int i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create integer instance.");
        
        if (strcmp(p0, "") != 0) {
            
//??            i = valueOf(p0);
        }
    }
    
    return i;
}

/**
 * Destroys the integer instance.
 *
 * @param p0 the integer instance
 * @param p1 the model
 */
static void destroy_integer_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy integer instance.");

//??        make_string(p0, p1);
    }
}

//
// Float instance.
//

/**
 * Creates a float instance.
 *
 * @param p0 the model
 * @return the float instance
 */
static double create_float_instance(void* p0) {

    double i = 0.0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create float instance.");

        if (strcmp(p0, "") != 0) {
            
//??            i = valueOf(p1);
        }
    }
    
    return i;
}

/**
 * Destroys the float instance.
 *
 * @param p0 the float instance
 * @param p1 the model
 */
static void destroy_float_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy float instance.");

//??        make_string(p0, p1);
    }
}

//
// Vector instance.
//

/**
 * Creates a vector instance.
 *
 * @param p0 the model
 * @return the vector instance
 */
static void* create_vector_instance(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create vector instance.");

        if (strcmp(p0, "") != 0) {
            
            i = malloc(sizeof(struct vector));

/*??
            int i1 = s.indexOf(",");
            
            if (i1 != -1) {
                
                char[] x = s.substring(0, i1);
                char[] yz = s.substring(i1 + 1);
                int i2 = yz.indexOf(",");

                if (i2 != -1) {
                
                    char[] y = yz.substring(0, i2);
                    char[] z = yz.substring(i2 + 1);

                    p.x = java.lang.Integer.parseInt(x);
                    p.y = java.lang.Integer.parseInt(y);
                    p.z = java.lang.Integer.parseInt(z);

                } else {
                
                    log((void*) &ERROR_LOG_LEVEL, "Could not create vector instance. The vector does not contain a z coordinate.");
                }
                
            } else {
            
                log((void*) &ERROR_LOG_LEVEL, "Could not create vector instance. The vector does not contain an y coordinate.");
            }
*/
        }
    }
    
    return i;
}

/**
 * Destroys the vector instance.
 *
 * @param p0 the vector instance
 * @param p1 the model
 */
static void destroy_vector_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy vector instance.");

//??        make_string(p0, p1);
        
        free(p0);
    }
}

//
// String instance.
//

/**
 * Creates a string instance.
 *
 * @param p0 the model
 * @return the string instance
 */
static void* create_string_instance(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create string instance.");
        
        if (strcmp(p0, "") != 0) {
            
            i = malloc(0);
            
            strcpy(i, p0);
        }
    }
    
    return i;
}

/**
 * Destroys the string instance.
 *
 * @param p0 the string instance
 * @param p1 the model
 */
static void destroy_string_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy string instance.");

//??        strcpy(p1, p0);
        
        free(p0);
    }
}

//
// Time instance.
//

/**
 * Creates a time instance.
 *
 * @param p0 the model
 * @return the time instance
 */
static void* create_time_instance(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create time instance.");

        if (strcmp(p0, "") != 0) {

            i = malloc(sizeof(struct time));

//??            Copy contents of time struct here!
        }
    }
    
    return i;
}

/**
 * Destroys the time instance.
 *
 * @param p0 the time instance
 * @param p1 the model
 */
static void destroy_time_instance(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy time instance.");

//??        make_string(p0, p1);
        
        free(p0);
    }
}

//
// Statics instance.
//

/**
 * Creates a statics instance.
 *
 * @param p0 the model
 * @param p1 the abstraction
 * @return the instance
 */
static void* create_statics_instance(void* p0, void* p1) {

    void* i = 0;
    
    log((void*) &INFO_LOG_LEVEL, "Create statics instance: ");
    log((void*) &INFO_LOG_LEVEL, p0);

    if (strcmp(p1, COMPLEX_STATICS_MODEL) == 0) {

        i = create_complex_statics_instance(p0);

    } else if (strcmp(p1, BOOLEAN_PRIMITIVE) == 0) {

        i = create_boolean_instance(p0);

    } else if (strcmp(p1, INTEGER_PRIMITIVE) == 0) {

        i = create_integer_instance(p0);

    } else if (strcmp(p1, FLOAT_PRIMITIVE) == 0) {

        i = create_float_instance(p0);

    } else if (strcmp(p1, VECTOR_PRIMITIVE) == 0) {

        i = create_vector_instance(p0);

    } else if (strcmp(p1, STRING_PRIMITIVE) == 0) {

        i = create_string_instance(p0);

    } else if (strcmp(p1, TIME_PRIMITIVE) == 0) {

        i = create_time_instance(p0);
    }
    
    return i;
}

/**
 * Destroys the statics instance.
 *
 * @param p0 the instance
 * @param p1 the model
 * @param p2 the abstraction
 */
static void destroy_statics_instance(void* p0, void* p1, void* p2) {

    log((void*) &INFO_LOG_LEVEL, "Destroy statics instance: ");
    log((void*) &INFO_LOG_LEVEL, p1);

    if (strcmp(p2, COMPLEX_STATICS_MODEL) == 0) {

        destroy_complex_statics_instance(p0, p1);
        
    } else if (strcmp(p2, BOOLEAN_PRIMITIVE) == 0) {

        destroy_boolean_instance(p0, p1);

    } else if (strcmp(p2, INTEGER_PRIMITIVE) == 0) {

        destroy_integer_instance(p0, p1);

    } else if (strcmp(p2, FLOAT_PRIMITIVE) == 0) {

        destroy_float_instance(p0, p1);

    } else if (strcmp(p2, VECTOR_PRIMITIVE) == 0) {

        destroy_vector_instance(p0, p1);

    } else if (strcmp(p2, STRING_PRIMITIVE) == 0) {

        destroy_string_instance(p0, p1);

    } else if (strcmp(p2, TIME_PRIMITIVE) == 0) {

        destroy_time_instance(p0, p1);
    }
}

/* STATICS_HANDLER_SOURCE */
#endif

