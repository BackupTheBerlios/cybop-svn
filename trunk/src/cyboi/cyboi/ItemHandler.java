/*
 * $RCSfile: ItemHandler.java,v $
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
 * @version $Revision: 1.27 $ $Date: 2003-08-09 15:34:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemHandler {

    //
    // Object.
    //

    /**
     * Creates the object.
     *
     * @param p0 the category name
     * @param p1 the abstraction name
     * @return the object
     */
    static java.lang.Object create_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.Object o = null;
        java.lang.String a = (java.lang.String) p1;
        
        if (a != null) {

            java.lang.System.out.println("INFO: Create object: " + p0);

            if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                o = PrimitiveHandler.create_integer_primitive(p0);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                o = PrimitiveHandler.create_float_primitive(p0);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                o = PrimitiveHandler.create_character_primitive(p0);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                o = PrimitiveHandler.create_string_primitive(p0);

            } else if (a.equals(Statics.COMPLEX)) {

                o = new Item();
                ItemHandler.initialize_item_containers(o);
                ItemHandler.initialize_item(o, p0);
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not create object. The abstraction is null.");
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
    static void destroy_object(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) throws java.lang.Exception {

        java.lang.String a = (java.lang.String) p2;
        
        if (a != null) {

            java.lang.System.out.println("INFO: Destroy object: " + p1);

            if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                PrimitiveHandler.destroy_integer_primitive(p0);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                PrimitiveHandler.destroy_float_primitive(p0);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                PrimitiveHandler.destroy_character_primitive(p0);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                PrimitiveHandler.destroy_string_primitive(p0);

            } else if (a.equals(Statics.COMPLEX)) {

                ItemHandler.finalize_item(p0, p1);
                ItemHandler.finalize_item_containers(p0);
                p0 = null;
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not destroy object. The abstraction is null.");
        }
    }

    //
    // Item containers.
    //

    /**
     * Initializes the item containers.
     *
     * @param p0 the item
     */
    static void initialize_item_containers(java.lang.Object p0) {

        Item i = (Item) p0;
        
        if (i != null) {
            
            java.lang.System.out.println("INFO: Initialize item containers.");

            i.items = new Map();
            MapHandler.initialize_map(i.items);
            i.positions = new Map();
            MapHandler.initialize_map(i.positions);
            i.instances = new Map();
            MapHandler.initialize_map(i.instances);
            i.interactions = new Map();
            MapHandler.initialize_map(i.interactions);

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item containers. The item is null.");
        }
    }

    /**
     * Finalizes the item containers.
     *
     * @param p0 the item
     */
    static void finalize_item_containers(java.lang.Object p0) {

        Item i = (Item) p0;
        
        if (i != null) {

            java.lang.System.out.println("INFO: Finalize item containers.");

            MapHandler.finalize_map(i.interactions);
            i.interactions = null;

            MapHandler.finalize_map(i.instances);
            i.instances = null;

            MapHandler.finalize_map(i.positions);
            i.positions = null;

            MapHandler.finalize_map(i.items);
            i.items = null;

        } else {

            java.lang.System.out.println("ERROR: Could not finalize item containers. The item is null.");
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
    static void initialize_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("INFO: Initialize item: " + p1);

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
            
            java.lang.System.out.println("ERROR: Could not initialize item elements. The category is null.");
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
    static void finalize_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("INFO: Finalize item: " + p1);
        
        // Create temporary category item.        
        Item c = new Item();
        ItemHandler.initialize_item_containers(c);

        // Finalize elements with category.
        if (c != null) {
            
            ItemHandler.finalize_child_items(p0, c.items);
            ItemHandler.finalize_java_object(p0, c.java_object);
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item elements. The category is null.");
        }

        // Write category to file.
        CategoryHandler.finalize_category(c, p1);

        // Destroy temporary category item.        
        ItemHandler.finalize_item_containers(c);
        c = null;
    }

    //
    // Java object.
    //

    /**
     * Initializes the java object.
     *
     * @param p0 the item
     * @param p1 the category java object attributes
     */
    static void initialize_java_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Item i = (Item) p0;
        
        if (i != null) {
                
            Item o = (Item) p1;
            
            if (o != null) {
        
                java.lang.System.out.println("INFO: Initialize java object.");

                java.lang.Object c = MapHandler.get_map_element(o.items, CategoryHandler.CATEGORY);
                i.java_object = JavaObjectHandler.create_java_object(c);
                JavaObjectHandler.initialize_java_object_attributes(i.java_object, o.items);
    
            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize java object. The java object is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java object. The item is null.");
        }
    }

    /**
     * Finalizes the java object.
     *
     * @param p0 the item
     * @param p1 the category java object attributes
     */
    static void finalize_java_object(java.lang.Object p0, java.lang.Object p1) {
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
    static void initialize_child_items(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

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
                
                java.lang.System.out.println("ERROR: Could not initialize items. A category item is null.");
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
    static void finalize_child_items(java.lang.Object p0, java.lang.Object p1) {
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
    static void initialize_child_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Item i = (Item) p0;
        
        if (i != null) {
                
            java.lang.System.out.println("INFO: Initialize item element.");
            java.lang.Object name = MapHandler.get_map_element(p1, CategoryHandler.NAME);                
            java.lang.Object category = null;                
            java.lang.Object abstraction = null;                
            java.lang.Object o = null;

            // Item.
            category = MapHandler.get_map_element(p1, CategoryHandler.ITEM_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.ITEM_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.items, o, name);

            // Position.
            category = MapHandler.get_map_element(p1, CategoryHandler.POSITION_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.POSITION_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.positions, o, name);

            // Instance.
            category = MapHandler.get_map_element(p1, CategoryHandler.INSTANCE_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.INSTANCE_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.instances, o, name);

            // Interaction.
            category = MapHandler.get_map_element(p1, CategoryHandler.INTERACTION_CATEGORY);
            abstraction = MapHandler.get_map_element(p1, CategoryHandler.INTERACTION_ABSTRACTION);
            o = ItemHandler.create_object(category, abstraction);
            MapHandler.set_map_element(i.interactions, o, name);

            // Java object.
            java.lang.Object java_object_item = MapHandler.get_map_element(i.items, name);
            java.lang.Object java_object_position = MapHandler.get_map_element(i.positions, name);
            
            if (java_object_item != null) {
                
                if (java_object_item instanceof Item) {
                    
                    JavaObjectHandler.add_to_java_object(i.java_object, ((Item) java_object_item).java_object, java_object_position);
    
                } else {
                    
                    java.lang.System.out.println("WARNING: Could not initialize item element. The java object item is not an instance of item.");
                }

            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize item element. The java object item is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item element. The item is null.");
        }
    }
    
    /**
     * Finalizes the child item.
     *
     * @param p0 the item
     * @param p1 the category item attributes
     */
    static void finalize_child_item(java.lang.Object p0, java.lang.Object p1) {
    }
}

