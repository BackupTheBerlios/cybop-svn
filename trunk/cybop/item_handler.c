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

/**
 * This is an item handler.
 *
 * Item elements are accessed over their index or name.
 *
 * @version $Revision: 1.2 $ $Date: 2003-09-22 06:50:53 $ $Author: christian $
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
int create_object(int p0, int p1) {

    int o = NULL;
    
    if (a != NULL) {

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

            o = (int) malloc(sizeof(item));
            initialize_item_containers(o);
            initialize_item(o, p0);
        }
        
    } else {
        
        log(WARNING_LOG_LEVEL, "Could not create object. The abstraction is NULL.");
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
void destroy_object(int p0, int p1, int p2) {

    if (a != NULL) {

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
        
        log(WARNING_LOG_LEVEL, "Could not destroy object. The abstraction is NULL.");
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
void initialize_item(int p0, int p1) {

    log(INFO_LOG_LEVEL, "Initialize item: " + p1);

    // Create temporary category item.
    int c = (int) malloc(sizeof(item));
    initialize_item_containers(c);

    // Read category from file.
    initialize_category(c, p1);

    // Initialize elements with category.
    if (c != NULL) {

        initialize_child_items(p0, c.items);
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item elements. The category is NULL.");
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
void finalize_item(int p0, int p1) {

    log(INFO_LOG_LEVEL, "Finalize item: " + p1);
    
    // Create temporary category item.        
    int c = (int) malloc(sizeof(item));
    initialize_item_containers(c);

    // Finalize elements with category.
    if (c != NULL) {
        
        finalize_child_items(p0, c.items);
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not finalize item elements. The category is NULL.");
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
void initialize_item_containers(int p0) {

    item i = (item) p0;
    
    if (i != NULL) {
        
        log(INFO_LOG_LEVEL, "Initialize item containers.");

        i.items = (map*) malloc(sizeof(map));
        initialize_map(i.items);
        i.positions = (map*) malloc(sizeof(map));
        initialize_map(i.positions);
        i.instances = (map*) malloc(sizeof(map));
        initialize_map(i.instances);
        i.interactions = (map*) malloc(sizeof(map));
        initialize_map(i.interactions);

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item containers. The item is NULL.");
    }
}

/**
 * Finalizes the item containers.
 *
 * @param p0 the item
 */
void finalize_item_containers(int p0) {

    item i = (item) p0;
    
    if (i != NULL) {

        log(INFO_LOG_LEVEL, "Finalize item containers.");

        finalize_map(i.interactions);
        free(i.interactions);

        finalize_map(i.instances);
        free(i.instances);

        finalize_map(i.positions);
        free(i.positions);

        finalize_map(i.items);
        free(i.items);

    } else {

        log(ERROR_LOG_LEVEL, "Could not finalize item containers. The item is NULL.");
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
void initialize_child_items(int p0, int p1) {

    map m = (map) p1;
    int count = 0;
    int size = get_map_size(m);
    item ci = NULL;
    item o = NULL;

    while (count < size) {
    
        ci = (item) get_map_element(m, count);

        if (ci != NULL) {
            
            initialize_child_item(p0, ci.items);

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not initialize items. A category item is NULL.");
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
void finalize_child_items(int p0, int p1) {
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
void initialize_child_item(int p0, int p1) {

    item i = (item) p0;
    
    if (i != NULL) {
            
        log(INFO_LOG_LEVEL, "Initialize item element.");
        int name = get_map_element(p1, NAME);                
        int category = NULL;                
        int abstraction = NULL;                
        int o = NULL;

        // Item.
        category = get_map_element(p1, ITEM_CATEGORY);
        abstraction = get_map_element(p1, ITEM_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i.items, name, o);

        // Position.
        category = get_map_element(p1, POSITION_CATEGORY);
        abstraction = get_map_element(p1, POSITION_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i.positions, name, o);

        // Instance.
        category = get_map_element(p1, INSTANCE_CATEGORY);
        abstraction = get_map_element(p1, INSTANCE_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i.instances, name, o);

        // Interaction.
        category = get_map_element(p1, INTERACTION_CATEGORY);
        abstraction = get_map_element(p1, INTERACTION_ABSTRACTION);
        o = create_object(category, abstraction);
        set_map_element(i.interactions, name, o);

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize item element. The item is NULL.");
    }
}

/**
 * Finalizes the child item.
 *
 * @param p0 the item
 * @param p1 the category item attributes
 */
void finalize_child_item(int p0, int p1) {
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
void set_item_element(int p0, int p1, int p2) {

    item i = (item) p0;

    if (i != NULL) {

        log(INFO_LOG_LEVEL, "Set item element: " + p1);
        int n = get_child_name(p1);
        int r = get_remaining_name(p1);
        
        if (r != NULL) {

            // The given item is the parent of another parent.
            int child = get_map_element(i.items, n);
            
            // Continue to process along the hierarchical name.
            set_item_element(child, r, p2);
            
        } else {

            // The given item is the parent of the child.
            set_map_element(i.items, n, p2);
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not set item element. The item is NULL.");
    }
}

/**
 * Removes the item element.
 *
 * @param p0 the item
 * @param p1 the hierarchical item name
 */
void remove_item_element(int p0, int p1) {

    item i = (item) p0;

    if (i != NULL) {

        log(INFO_LOG_LEVEL, "Remove item element: " + p1);
        int n = get_child_name(p1);
        int r = get_remaining_name(p1);
        
        if (r != NULL) {
            
            // The given item is the parent of another parent.
            int child = get_map_element(i.items, n);
            
            // Continue to process along the hierarchical name.
            remove_item_element(child, r);
            
        } else {

            // The given item is the parent of the child.
            remove_map_element(i.items, n);
        }
    } else {

        log(ERROR_LOG_LEVEL, "Could not remove item element. The item is NULL.");
    }
}

/**
 * Returns the item element.
 *
 * @param p0 the item
 * @param p1 the hierarchical item name
 * @return the element
 */
int get_item_element(int p0, int p1) {

    int e = NULL;
    item i = (item) p0;

    if (i != NULL) {

        log(INFO_LOG_LEVEL, "Get item element: " + p1);
        int n = get_child_name(p1);
        int r = get_remaining_name(p1);
        
        if (r != NULL) {
            
            // The given item is the parent of another parent.
            int child = get_map_element(i.items, n);
            
            // Continue to process along the hierarchical name.
            e = get_item_element(child, r);
            
        } else {

            // The given item is the parent of the child.
            e = get_map_element(i.items, n);
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get item element. The item is NULL.");
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
int get_child_name(int p0) {
    
    int child = NULL;
    
    if (n != NULL) {
        
        int i = n.indexOf(".");
        
        if (i != -1) {
            
            child = n.substring(0, i);
        
        } else {
        
            child = n;
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not get child name. The hierarchical name is NULL.");
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
int get_remaining_name(int p0) {
    
    int rem = NULL;
    
    if (n != NULL) {
        
        int i = n.indexOf(".");
        
        if (i != -1) {

            rem = n.substring(i + 1);
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not get remaining name. The hierarchical name is NULL.");
    }
    
    return rem;
}

