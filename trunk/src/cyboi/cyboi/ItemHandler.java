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
 * @version $Revision: 1.20 $ $Date: 2003-07-29 22:38:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemHandler {

    //
    // Object.
    //

    /**
     * Initializes the object.
     *
     * @param p0 the object
     * @param p1 the category
     * @param p2 the abstraction
     */
    static void initialize_object(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) throws java.lang.Exception {

        java.lang.String a = (java.lang.String) p2;
        
        if (a != null) {

            java.lang.System.out.println("INFO: Initialize object.");

            if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                p0 = PrimitiveHandler.create_integer_primitive(p1);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                p0 = PrimitiveHandler.create_float_primitive(p1);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                p0 = PrimitiveHandler.create_character_primitive(p1);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                p0 = PrimitiveHandler.create_string_primitive(p1);

            } else if (a.equals(Statics.COMPLEX)) {

                p0 = new Item();
                ItemHandler.initialize(p0, p1);
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not initialize object. The abstraction is null.");
        }
    }

    /**
     * Finalizes the object.
     *
     * @param p0 the object
     * @param p1 the category
     * @param p2 the abstraction
     */
    static void finalize_object(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) throws java.lang.Exception {

        java.lang.String a = (java.lang.String) p2;
        
        if (a != null) {

            java.lang.System.out.println("INFO: Finalize object.");

            if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                PrimitiveHandler.destroy_integer_primitive(p0);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                PrimitiveHandler.destroy_float_primitive(p0);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                PrimitiveHandler.destroy_character_primitive(p0);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                PrimitiveHandler.destroy_string_primitive(p0);

            } else if (a.equals(Statics.COMPLEX)) {

                ItemHandler.finalizz(p0, p1);
                p0 = null;
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not finalize object. The abstraction is null.");
        }
    }

    //
    // Item.
    //

    /**
     * Initializes the item.
     *
     * @param p0 the item
     * @param p1 the category
     */
    static void initialize_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("INFO: Initialize item: " + p1);
        
        Category c = new Category();

        CategoryHandler.initialize_category(c, p1);

        ItemHandler.initialize_item_containers(p0);
        ItemHandler.initialize_item_elements(p0, c);
    }

    /**
     * Finalizes the item.
     *
     * @param p0 the item
     * @param p1 the category
     */
    static void finalize_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("INFO: Finalize item: " + p1);
        
        Category c = new Category();

        ItemHandler.finalize_item_elements(p0, c);
        ItemHandler.finalize_item_containers(p0);

        CategoryHandler.finalize_category(c, p1);
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

            i.items = MapHandler.create_map();
            i.positions = MapHandler.create_map();
            i.instances = MapHandler.create_map();
            i.interactions = MapHandler.create_map();

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

            java.lang.Object interactions = i.interactions;
            i.interactions = null;
            MapHandler.destroy_map(interactions);

            java.lang.Object instances = i.instances;
            i.instances = null;
            MapHandler.destroy_map(instances);

            java.lang.Object positions = i.positions;
            i.positions = null;
            MapHandler.destroy_map(positions);

            java.lang.Object items = i.items;
            i.items = null;
            MapHandler.destroy_map(items);

        } else {

            java.lang.System.out.println("ERROR: Could not finalize item containers. The item is null.");
        }
    }

    //
    // Item elements.
    //

    /**
     * Initializes the item elements.
     *
     * @param p0 the item
     * @param p1 the category
     */
    static void initialize_item_elements(java.lang.Object p0, java.lang.Object p1) {

        Category c = (Category) p1;
    
        if (c != null) {
            
            java.lang.System.out.println("INFO: Initialize item elements.");

            // Java object.
            initialize_java_object(p0, c.java_object);

            // Items.
            Map category_items = c.category_items;
            
            if (category_items != null) {
                
                int count = 0;
                int size = category_items.length;
                CategoryItem category_item = null;
                
                while (count < size) {
                    
                    category_item = MapHandler.get_map_element(category_items, count);

                    ItemHandler.initialize_item_element(p0, category_item);
                }
            
            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize item elements. The items is null.");
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item elements. The category is null.");
        }
    }

    /**
     * Finalizes the item elements.
     *
     * Writes the file of the given category.
     *
     * @param p0 the item
     * @param p1 the category
     */
    static void finalize_item_elements(java.lang.Object p0, java.lang.Object p1) {

        Item i = (Item) p0;
        
        if (i != null) {
            
            java.lang.System.out.println("INFO: Finalize item elements.");
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not finalize item elements. The item is null.");
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
    static void initialize_java_object(java.lang.Object p0, java.lang.Object p1) {
    
        Item i = (Item) p0;
        
        if (i != null) {
    
            java.lang.System.out.println("INFO: Initialize java object.");
            i.java_object = JavaObjectHandler.create_java_object(p1);

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java object. The item is null.");
        }
    }

    /**
     * Finalizes the java object.
     *
     * @param p0 the item
     * @param p1 the category java object
     */
    static void finalize_java_object(java.lang.Object p0, java.lang.Object p1) {
    
        Item i = (Item) p0;
        
        if (i != null) {
    
            java.lang.System.out.println("INFO: Finalize java object.");
            JavaObjectHandler.destroy_java_object(i.java_object);

        } else {
            
            java.lang.System.out.println("ERROR: Could not finalize java object. The item is null.");
        }
    }

    //
    // Item element.
    //

    /**
     * Initializes the item element.
     *
     * @param p0 the item
     * @param p1 the category item
     */
    static void initialize_item_element(java.lang.Object p0, java.lang.Object p1) {

        Item i = (Item) p0;
        
        if (i != null) {
                
            CategoryItem ci = (CategoryItem) p1;
            
            if (ci != null) {
    
                java.lang.System.out.println("INFO: Initialize item element.");

                java.lang.Object o = null;
                ItemHandler.initialize_object(o, ci.item_category, ci.item_abstraction);
                MapHandler.add_map_element(i.items, ci.name, o);
    
                java.lang.Object o = null;
                ItemHandler.initialize_object(o, ci.position_category, ci.position_abstraction);
                MapHandler.add_map_element(i.positions, ci.name, o);
    
                java.lang.Object o = null;
                ItemHandler.initialize_object(o, ci.instance_category, ci.instance_abstraction);
                MapHandler.add_map_element(i.instances, ci.name, o);
    
                java.lang.Object o = null;
                ItemHandler.initialize_object(o, ci.interaction_category, ci.interaction_abstraction);
                MapHandler.add_map_element(i.interactions, ci.name, o);
    
            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize item element. The category item is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item element. The item is null.");
        }
    }
    
    /**
     * Finalizes the item element.
     *
     * @param p0 the item
     * @param p1 the category item
     */
    static void finalize_item_element(java.lang.Object p0, java.lang.Object p1) {

        Item i = (Item) p0;
        
        if (i != null) {
                
            CategoryItem ci = (CategoryItem) p1;
            
            if (ci != null) {
    
                java.lang.System.out.println("INFO: Finalize item element.");

                java.lang.Object o = null;
                MapHandler.get_map_element(i.items, ci.name, o);
                ItemHandler.finalize_object(o, ci.item_category, ci.item_abstraction);
                MapHandler.remove_map_element(i.items, ci.name);
    
                java.lang.Object o = null;
                MapHandler.get_map_element(i.positions, ci.name, o);
                ItemHandler.finalize_object(o, ci.position_category, ci.position_abstraction);
                MapHandler.remove_map_element(i.positions, ci.name);
    
                java.lang.Object o = null;
                MapHandler.get_map_element(i.instances, ci.name, o);
                ItemHandler.finalize_object(o, ci.instance_category, ci.instance_abstraction);
                MapHandler.remove_map_element(i.instances, ci.name);
    
                java.lang.Object o = null;
                MapHandler.get_map_element(i.interactions, ci.name, o);
                ItemHandler.finalize_object(o, ci.interaction_category, ci.interaction_abstraction);
                MapHandler.remove_map_element(i.interactions, ci.name);
    
            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize item element. The category item is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item element. The item is null.");
        }
    }
}

