/*
 * $RCSfile: item_handler.c,v $
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

#include "item.c"

/**
 * This is an item handler.
 *
 * Item elements are accessed over their index or name.
 *
 * @version $Revision: 1.5 $ $Date: 2003-09-27 00:22:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Item object.
//

/**
 * Creates the object.
 *
 * @param p0 the category name
 * @param p1 the abstraction name
 * @return the object
 */
void* create_object(void* p0, void* p1) {

    void* o = 0;
    
    if (p1 != 0) {

        log(INFO_LOG_LEVEL, "Create object: " + p0);

        if (a.equals(BOOLEAN_PRIMITIVE)) {

            o = create_boolean_primitive(p0);

        } else if (a.equals(INTEGER_PRIMITIVE)) {

            o = create_integer_primitive(p0);

        } else if (a.equals(FLOAT_PRIMITIVE)) {

            o = create_float_primitive(p0);

        } else if (a.equals(VECTOR_PRIMITIVE)) {

            o = create_vector_primitive(p0);

        } else if (a.equals(CHAR_PRIMITIVE)) {

            o = create_character_primitive(p0);

        } else if (a.equals(STRING_PRIMITIVE)) {

            o = create_string_primitive(p0);

        } else if (a.equals(TIME_PRIMITIVE)) {

            o = create_time_primitive(p0);

        } else if (a.equals(CATEGORY)) {

            o = malloc(sizeof(item));
            initialize_item_containers(o);
            initialize_item(o, p0);
        }
        
    } else {
        
        log(WARNING_LOG_LEVEL, "Could not create object. The abstraction is null.");
    }
    
    return o;
}

/**
 * Destroys the object.
 *
 * @param p0 the object
 * @param p1 the category name
 * @param p2 the abstraction name
 */
void destroy_object(void* p0, void* p1, void* p2) {

    if (p2 != 0) {

        log(INFO_LOG_LEVEL, "Destroy object: " + p1);

        if (a.equals(BOOLEAN_PRIMITIVE)) {

            destroy_boolean_primitive(p0);

        } else if (a.equals(INTEGER_PRIMITIVE)) {

            destroy_integer_primitive(p0);

        } else if (a.equals(FLOAT_PRIMITIVE)) {

            destroy_float_primitive(p0);

        } else if (a.equals(VECTOR_PRIMITIVE)) {

            destroy_vector_primitive(p0);

        } else if (a.equals(CHAR_PRIMITIVE)) {

            destroy_character_primitive(p0);

        } else if (a.equals(STRING_PRIMITIVE)) {

            destroy_string_primitive(p0);

        } else if (a.equals(TIME_PRIMITIVE)) {

            destroy_time_primitive(p0);

        } else if (a.equals(CATEGORY)) {

            finalize_item(p0, p1);
            finalize_item_containers(p0);
            free(p0);
        }
        
    } else {
        
        log(WARNING_LOG_LEVEL, "Could not destroy object. The abstraction is null.");
    }
}

//
// Item.
//

/**
 * Initializes the item.
 *
 * @param p0 the item
 * @param p1 the category name
 */
void initialize_item(void* p0, void* p1) {

    log(INFO_LOG_LEVEL, "Initialize item: " + p1);

    // Create temporary category item.
    struct item* c = (struct item*) malloc(sizeof(item));
    initialize_item_containers(c);

    // Read category from file.
    initialize_category(c, p1);

    // Initialize elements with category.
    if (c != 0) {

        initialize_child_items(p0, c->children);
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item elements. The category is null.");
    }

    // Destroy temporary category item.        
    finalize_item_containers(c);
    free(c);
}

/**
 * Finalizes the item.
 *
 * @param p0 the item
 * @param p1 the category name
 */
void finalize_item(void* p0, void* p1) {

    log(INFO_LOG_LEVEL, "Finalize item: " + p1);
    
    // Create temporary category item.
    struct item* c = (struct item*) malloc(sizeof(item));
    initialize_item_containers(c);

    // Finalize elements with category.
    if (c != 0) {
        
        finalize_child_items(p0, c->children);
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not finalize item elements. The category is null.");
    }

    // Write category to file.
    finalize_category(c, p1);

    // Destroy temporary category item.        
    finalize_item_containers(c);
    free(c);
}

//
// Item containers.
//

/**
 * Initializes the item containers.
 *
 * @param p0 the item
 */
void initialize_item_containers(void* p0) {

    struct item* i = (struct item*) p0;
    
    if (i != 0) {
        
        log(INFO_LOG_LEVEL, "Initialize item containers.");

        i->children = malloc(sizeof(map));
        initialize_map(i->children);
        i->positions = malloc(sizeof(map));
        initialize_map(i->positions);
        i->instances = malloc(sizeof(map));
        initialize_map(i->instances);
        i->interactions = malloc(sizeof(map));
        initialize_map(i->interactions);

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item containers. The item is null.");
    }
}

/**
 * Finalizes the item containers.
 *
 * @param p0 the item
 */
void finalize_item_containers(void* p0) {

    struct item* i = (struct item*) p0;
    
    if (i != 0) {

        log(INFO_LOG_LEVEL, "Finalize item containers.");

        finalize_map(i->interactions);
        free(i->interactions);

        finalize_map(i->instances);
        free(i->instances);

        finalize_map(i->positions);
        free(i->positions);

        finalize_map(i->children);
        free(i->children);

    } else {

        log(ERROR_LOG_LEVEL, "Could not finalize item containers. The item is null.");
    }
}

//
// Child items.
//

/**
 * Initializes the child items.
 *
 * @param p0 the item
 * @param p1 the category items
 */
void initialize_child_items(void* p0, void* p1) {

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
            
            log(ERROR_LOG_LEVEL, "Could not initialize items. A category item is null.");
        }
        
        count++;
    }
}

/**
 * Finalizes the child items
 *
 * @param p0 the item
 * @param p1 the category items
 */
void finalize_child_items(void* p0, void* p1) {
}

//
// Child item.
//

/**
 * Initializes the child item.
 *
 * @param p0 the item
 * @param p1 the category item attributes
 */
void initialize_child_item(void* p0, void* p1) {

    struct item* i = (struct item*) p0;
    
    if (i != 0) {
            
        log(INFO_LOG_LEVEL, "Initialize item element.");
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

        // Instance.
        category = get_map_element(p1, INSTANCE_CATEGORY);
        abstraction = get_map_element(p1, INSTANCE_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->instances, name, o);

        // Interaction.
        category = get_map_element(p1, INTERACTION_CATEGORY);
        abstraction = get_map_element(p1, INTERACTION_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i->interactions, name, o);

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item element. The item is null.");
    }
}

/**
 * Finalizes the child item.
 *
 * @param p0 the item
 * @param p1 the category item attributes
 */
void finalize_child_item(void* p0, void* p1) {
}

//
// Item element.
//

/**
 * Sets the item element.
 *
 * @param p0 the item
 * @param p1 the hierarchical item name
 * @param p2 the element
 */
void set_item_element(void* p0, void* p1, void* p2) {

    struct item* i = (struct item*) p0;

    if (i != 0) {

        log(INFO_LOG_LEVEL, "Set item element: " + p1);
        void* n = get_child_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {

            // The given item is the parent of another parent.
            void* child = get_map_element(i->children, n);
            
            // Continue to process along the hierarchical name.
            set_item_element(child, r, p2);
            
        } else {

            // The given item is the parent of the child.
            set_map_element(i->children, n, p2);
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not set item element. The item is null.");
    }
}

/**
 * Removes the item element.
 *
 * @param p0 the item
 * @param p1 the hierarchical item name
 */
void remove_item_element(void* p0, void* p1) {

    struct item* i = (struct item*) p0;

    if (i != 0) {

        log(INFO_LOG_LEVEL, "Remove item element: " + p1);
        void* n = get_child_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given item is the parent of another parent.
            void* child = get_map_element(i->items, n);
            
            // Continue to process along the hierarchical name.
            remove_item_element(child, r);
            
        } else {

            // The given item is the parent of the child.
            remove_map_element(i->children, n);
        }
    } else {

        log(ERROR_LOG_LEVEL, "Could not remove item element. The item is null.");
    }
}

/**
 * Returns the item element.
 *
 * @param p0 the item
 * @param p1 the hierarchical item name
 * @return the element
 */
void* get_item_element(void* p0, void* p1) {

    void* e = 0;
    struct item* i = (struct item*) p0;

    if (i != 0) {

        log(INFO_LOG_LEVEL, "Get item element: " + p1);
        void* n = get_child_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given item is the parent of another parent.
            void* child = get_map_element(i->items, n);
            
            // Continue to process along the hierarchical name.
            e = get_item_element(child, r);
            
        } else {

            // The given item is the parent of the child.
            e = get_map_element(i->items, n);
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get item element. The item is null.");
    }
    
    return e;
}

/**
 * Returns the child name.
 *
 * It is the most left name before the first dot/point "." in the given string
 * or, if there is no dot, then it is the given name itself.
 *
 * @param p0 the hierarchical item name
 * @return the child name
 */
void* get_child_name(void* p0) {
    
    void* child = 0;
    char* n = (char*) p0;
    
    if (n != 0) {
        
        int i = n->indexOf(".");
        
        if (i != -1) {
            
            child = n->substring(0, i);
        
        } else {
        
            child = n;
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not get child name. The hierarchical name is null.");
    }
    
    return child;
}

/**
 * Returns the remaining name.
 *
 * It is the whole string after the first dot/point ".".
 *
 * @param p0 the hierarchical item name
 * @return the remaining name
 */
void* get_remaining_name(void* p0) {
    
    void* rem = 0;
    char* n = (char*) p0;
    
    if (n != 0) {
        
        int i = n->indexOf(".");
        
        if (i != -1) {

            rem = n->substring(i + 1);
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not get remaining name. The hierarchical name is null.");
    }
    
    return rem;
}

