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

package cyboi;

/**
 * This is an item handler.
 *
 * Item elements are accessed over their index or name.
 *
 * @version $Revision: 1.1 $ $Date: 2003-09-17 18:45:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemHandler {

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
    java.lang.Object create_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.Object o = null;
        java.lang.String a = (java.lang.String) p1;
        
        if (a != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Create object: " + p0);

            if (a.equals(Statics.BOOLEAN_PRIMITIVE)) {

                o = PrimitiveHandler.create_boolean_primitive(p0);

            } else if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                o = PrimitiveHandler.create_integer_primitive(p0);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                o = PrimitiveHandler.create_float_primitive(p0);

            } else if (a.equals(Statics.VECTOR_PRIMITIVE)) {

                o = PrimitiveHandler.create_vector_primitive(p0);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                o = PrimitiveHandler.create_character_primitive(p0);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                o = PrimitiveHandler.create_string_primitive(p0);

            } else if (a.equals(Statics.TIME_PRIMITIVE)) {

                o = PrimitiveHandler.create_time_primitive(p0);

            } else if (a.equals(Statics.CATEGORY)) {

                o = new Item();
                ItemHandler.initialize_item_containers(o);
                ItemHandler.initialize_item(o, p0);
            }
            
        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not create object. The abstraction is null.");
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
    void destroy_object(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) throws java.lang.Exception {

        java.lang.String a = (java.lang.String) p2;
        
        if (a != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Destroy object: " + p1);

            if (a.equals(Statics.BOOLEAN_PRIMITIVE)) {

                PrimitiveHandler.destroy_boolean_primitive(p0);

            } else if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                PrimitiveHandler.destroy_integer_primitive(p0);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                PrimitiveHandler.destroy_float_primitive(p0);

            } else if (a.equals(Statics.VECTOR_PRIMITIVE)) {

                PrimitiveHandler.destroy_vector_primitive(p0);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                PrimitiveHandler.destroy_character_primitive(p0);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                PrimitiveHandler.destroy_string_primitive(p0);

            } else if (a.equals(Statics.TIME_PRIMITIVE)) {

                PrimitiveHandler.destroy_time_primitive(p0);

            } else if (a.equals(Statics.CATEGORY)) {

                ItemHandler.finalize_item(p0, p1);
                ItemHandler.finalize_item_containers(p0);
                p0 = null;
            }
            
        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not destroy object. The abstraction is null.");
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
    void initialize_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize item: " + p1);

        // Create temporary category item.
        Item c = new Item();
        ItemHandler.initialize_item_containers(c);

        // Read category from file.
        CategoryHandler.initialize_category(c, p1);

        // Initialize elements with category.
        if (c != null) {

            ItemHandler.initialize_java_object(p0, c.java_object);
            ItemHandler.initialize_child_items(p0, c.items);
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize item elements. The category is null.");
        }

        // Destroy temporary category item.        
        ItemHandler.finalize_item_containers(c);
        c = null;
    }

    /**
     * Finalizes the item.
     *
     * @param p0 the item
     * @param p1 the category name
     */
    void finalize_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Finalize item: " + p1);
        
        // Create temporary category item.        
        Item c = new Item();
        ItemHandler.initialize_item_containers(c);

        // Finalize elements with category.
        if (c != null) {
            
            ItemHandler.finalize_child_items(p0, c.items);
            ItemHandler.finalize_java_object(p0, c.java_object);
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not finalize item elements. The category is null.");
        }

        // Write category to file.
        CategoryHandler.finalize_category(c, p1);

        // Destroy temporary category item.        
        ItemHandler.finalize_item_containers(c);
        c = null;
    }

    //
    // Item containers.
    //

    /**
     * Initializes the item containers.
     *
     * @param p0 the item
     */
    void initialize_item_containers(java.lang.Object p0) {

        Item i = (Item) p0;
        
        if (i != null) {
            
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize item containers.");

            i.items = new Map();
            MapHandler.initialize_map(i.items);
            i.positions = new Map();
            MapHandler.initialize_map(i.positions);
            i.instances = new Map();
            MapHandler.initialize_map(i.instances);
            i.interactions = new Map();
            MapHandler.initialize_map(i.interactions);

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize item containers. The item is null.");
        }
    }

    /**
     * Finalizes the item containers.
     *
     * @param p0 the item
     */
    void finalize_item_containers(java.lang.Object p0) {

        Item i = (Item) p0;
        
        if (i != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Finalize item containers.");

            MapHandler.finalize_map(i.interactions);
            i.interactions = null;

            MapHandler.finalize_map(i.instances);
            i.instances = null;

            MapHandler.finalize_map(i.positions);
            i.positions = null;

            MapHandler.finalize_map(i.items);
            i.items = null;

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not finalize item containers. The item is null.");
        }
    }

    //
    // Java object.
    //

    /**
     * Initializes the java object.
     *
     * @param p0 the item
     * @param p1 the category java object
     */
    void initialize_java_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Item i = (Item) p0;
        
        if (i != null) {
                
            Item o = (Item) p1;
            
            if (o != null) {
        
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize java object.");

                java.lang.Object c = MapHandler.get_map_element(o.items, CategoryHandler.CATEGORY);
                i.java_object = JavaObjectHandler.create_java_object(c);
                JavaObjectHandler.initialize_java_object_attributes(i.java_object, o.items);
    
            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize java object. The java object is null.");
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize java object. The item is null.");
        }
    }

    /**
     * Finalizes the java object.
     *
     * @param p0 the item
     * @param p1 the category java object
     */
    void finalize_java_object(java.lang.Object p0, java.lang.Object p1) {
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
    void initialize_child_items(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Map m = (Map) p1;
        int count = 0;
        int size = MapHandler.get_map_size(m);
        Item ci = null;
        Item o = null;

        while (count < size) {
        
            ci = (Item) MapHandler.get_map_element(m, count);

            if (ci != null) {
                
                ItemHandler.initialize_child_item(p0, ci.items);

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize items. A category item is null.");
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
    void finalize_child_items(java.lang.Object p0, java.lang.Object p1) {
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
    void initialize_child_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Item i = (Item) p0;
        
        if (i != null) {
                
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize item element.");
            java.lang.Object name = MapHandler.get_map_element(p1, CategoryHandler.NAME);                
            java.lang.Object category = null;                
            java.lang.Object abstraction = null;                
            java.lang.Object o = null;

            // Item.
            category = MapHandler.get_map_element(p1, CategoryHandler.ITEM_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.ITEM_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.items, name, o);

            // Position.
            category = MapHandler.get_map_element(p1, CategoryHandler.POSITION_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.POSITION_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.positions, name, o);

            // Instance.
            category = MapHandler.get_map_element(p1, CategoryHandler.INSTANCE_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.INSTANCE_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.instances, name, o);

            // Interaction.
            category = MapHandler.get_map_element(p1, CategoryHandler.INTERACTION_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.INTERACTION_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.interactions, name, o);

            // Java object.
            java.lang.Object java_object_item = MapHandler.get_map_element(i.items, name);
            java.lang.Object java_object_position = MapHandler.get_map_element(i.interactions, name);
            
            if (java_object_item != null) {
                
                if (java_object_item instanceof Item) {
                    
                    JavaObjectHandler.add_to_java_object(i.java_object, ((Item) java_object_item).java_object, java_object_position);
    
                } else {
                    
                    LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize item element. The java object item is not an instance of item.");
                }

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize item element. The java object item is null.");
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize item element. The item is null.");
        }
    }
    
    /**
     * Finalizes the child item.
     *
     * @param p0 the item
     * @param p1 the category item attributes
     */
    void finalize_child_item(java.lang.Object p0, java.lang.Object p1) {
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
    void set_item_element(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        Item i = (Item) p0;

        if (i != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Set item element: " + p1);
            java.lang.Object n = get_child_name(p1);
            java.lang.Object r = get_remaining_name(p1);
            
            if (r != null) {

                // The given item is the parent of another parent.
                java.lang.Object child = MapHandler.get_map_element(i.items, n);
                
                // Continue to process along the hierarchical name.
                ItemHandler.set_item_element(child, r, p2);
                
            } else {
    
                // The given item is the parent of the child.
                MapHandler.set_map_element(i.items, n, p2);
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not set item element. The item is null.");
        }
    }

    /**
     * Removes the item element.
     *
     * @param p0 the item
     * @param p1 the hierarchical item name
     */
    void remove_item_element(java.lang.Object p0, java.lang.Object p1) {

        Item i = (Item) p0;

        if (i != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove item element: " + p1);
            java.lang.Object n = get_child_name(p1);
            java.lang.Object r = get_remaining_name(p1);
            
            if (r != null) {
                
                // The given item is the parent of another parent.
                java.lang.Object child = MapHandler.get_map_element(i.items, n);
                
                // Continue to process along the hierarchical name.
                ItemHandler.remove_item_element(child, r);
                
            } else {
    
                // The given item is the parent of the child.
                MapHandler.remove_map_element(i.items, n);
            }
        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove item element. The item is null.");
        }
    }

    /**
     * Returns the item element.
     *
     * @param p0 the item
     * @param p1 the hierarchical item name
     * @return the element
     */
    java.lang.Object get_item_element(java.lang.Object p0, java.lang.Object p1) {

        java.lang.Object e = null;
        Item i = (Item) p0;

        if (i != null) {
    
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Get item element: " + p1);
            java.lang.Object n = get_child_name(p1);
            java.lang.Object r = get_remaining_name(p1);
            
            if (r != null) {
                
                // The given item is the parent of another parent.
                java.lang.Object child = MapHandler.get_map_element(i.items, n);
                
                // Continue to process along the hierarchical name.
                e = ItemHandler.get_item_element(child, r);
                
            } else {
    
                // The given item is the parent of the child.
                e = MapHandler.get_map_element(i.items, n);
            }

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not get item element. The item is null.");
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
    java.lang.Object get_child_name(java.lang.Object p0) {
        
        java.lang.Object child = null;
        java.lang.String n = (java.lang.String) p0;
        
        if (n != null) {
            
            int i = n.indexOf(".");
            
            if (i != -1) {
                
                child = n.substring(0, i);
            
            } else {
            
                child = n;
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not get child name. The hierarchical name is null.");
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
    java.lang.Object get_remaining_name(java.lang.Object p0) {
        
        java.lang.Object rem = null;
        java.lang.String n = (java.lang.String) p0;
        
        if (n != null) {
            
            int i = n.indexOf(".");
            
            if (i != -1) {

                rem = n.substring(i + 1);
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not get remaining name. The hierarchical name is null.");
        }
        
        return rem;
    }
}

