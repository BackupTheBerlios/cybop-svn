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
 * This is an item handler.<br><br>
 *
 * Item elements are accessed over their index or name.
 *
 * An item has well-defined methods useable by outside entities. An outside
 * entity which contains items is called their container. Containers have a contract
 * with the items they contain, in that methods are called in a specific order,
 * called a lifecycle.<br><br>
 *
 * By calling the lifecycle methods, a container ensures the proper startup and
 * shutdown of each item, to work correctly. One or more methods can be called
 * by the container, but the order must be the same.<br>
 *
 * An item has the following lifecycle:
 *  <ul>
 *      <li>constructor(): called without any parameters on keyword <code>new</code></li>
 *      <li>abstract()</li>
 *      <li>name()</li>
 *      <li>inherit()</li>
 *      <li>categorize()</li>
 *      <li>position()</li>
 *      <li>constrain()</li>
 *      <li>behave()</li>
 *      <li>globalize()</li>
 *      <li>initialize()</li>
 *      <li>finalize(): destroys items (attributes) that are specific to this item; deallocates memory</li>
 *      <li>deglobalize()</li>
 *      <li>unbehave()</li>
 *      <li>unconstrain()</li>
 *      <li>unposition()</li>
 *      <li>decategorize()</li>
 *      <li>uninherit()</li>
 *      <li>unname()</li>
 *      <li>deabstract()</li>
 *      <li>destructor(): called without any parameters; not available for Java where a garbage collector destroys objects incidentally!</li>
 *  </ul>
 *
 * Only globalize and initialize relate to the dynamic instance creation.
 * All other methods are for specifying the static category.
 *
 * @version $Revision: 1.9 $ $Date: 2003-07-22 15:05:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemHandler {

    /** The xml parser. */
    static java.lang.Object xml_parser;

    //
    // Item container management.
    //

    /**
     * Creates an item container.
     *
     * @return the item container
     */
    static ItemContainer create_item_container() {

        ItemContainer c = new ItemContainer();

        if (c != null) {

            c.abstractions = MapHandler.create_map();
            c.categories = MapHandler.create_map();
            c.positions = MapHandler.create_map();
            c.items = MapHandler.create_map();

        } else {

            java.lang.System.out.println("ERROR: Could not create item container. The item container is null.");
        }

        return c;
    }

    /**
     * Destroys the item container.
     *
     * @param c the item container
     */
    static void destroy_item_container(ItemContainer c) {

        if (c != null) {

            Map items = c.items;
            c.items = null;
            MapHandler.destroy_map_container(items);

            Map positions = c.positions;
            c.positions = null;
            MapHandler.destroy_map_container(positions);

            Map categories = c.categories;
            c.categories = null;
            MapHandler.destroy_map_container(categories);

            Map abstractions = c.abstractions;
            c.abstractions = null;
            MapHandler.destroy_map_container(abstractions);

        } else {

            java.lang.System.out.println("ERROR: Could not destroy item container. The item container is null.");
        }
    }

    //
    // Item element management.
    //

    /**
     * Creates an item element.
     *
     * @param a the abstraction
     * @param c the category
     * @return the item element
     */
    static java.lang.Object create_item_element(java.lang.Object a, java.lang.Object c) {

        java.lang.Object item = null;

        if (abstraction != null) {

            if (abstraction.equals(Statics.INTEGER_PRIMITIVE)) {

                item = PrimitiveHandler.create_integer_primitive(category);

            } else if (abstraction.equals(Statics.FLOAT_PRIMITIVE)) {

                item = PrimitiveHandler.create_float_primitive(category);

            } else if (abstraction.equals(Statics.CHAR_PRIMITIVE)) {

                item = PrimitiveHandler.create_character_primitive(category);

            } else if (abstraction.equals(Statics.STRING_PRIMITIVE)) {

                item = PrimitiveHandler.create_string_primitive(category);

            } else if (abstraction.equals(Statics.COMPLEX)) {

                item = ItemHandler.create_item_container();
                ItemHandler.initialize(item, category);
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not create item element. The abstraction is null.");
        }

        return item;
    }

    /**
     * Sets the item element.
     *
     * @param c the item container
     * @param e the item element
     */
    static void set_item_element(java.lang.Object c, java.lang.Object e) {

        ItemContainer ic = (ItemContainer) c;
        
        if (ic != null) {
            
            ItemElement ie = (ItemElement) e;
            
            if (ie != null) {

                MapHandler.set_map_element(ic.abstractions, ie.name, e.abstraction);
                MapHandler.set_map_element(ic.categories, ie.name, e.category);
                MapHandler.set_map_element(ic.positions, ie.name, e.position);
                MapHandler.set_map_element(ic.items, ie.name, e.item);

            } else {
    
                java.lang.System.out.println("ERROR: Could not set item element. The item element is null.");
            }

        } else {

            java.lang.System.out.println("ERROR: Could not set item element. The item container is null.");
        }
    }

    /**
     * Adds the item element.
     *
     * @param c the item container
     * @param n the base name
     * @param c the item
     * @return the item name
     */
    static java.lang.Object add_item_element(java.lang.Object c, java.lang.Object n, java.lang.Object c) {

        java.lang.Object cn = null;
        Map m = getItem();

        if (m != null) {

            cn = m.add(n, c);

        } else {

            java.lang.System.out.println("ERROR: Could not add item element. The item element is null.");
        }
        
        return cn;
    }

    /**
     * Removes the item element.
     *
     * @param c the item container
     * @param i the index
     */
    static void remove_item_element(java.lang.Object c, int i) {

        Map m = getItem();

        if (m != null) {

            m.remove(i);

        } else {

            java.lang.System.out.println("ERROR: Could not remove item element. The item element is null.");
        }
    }

    /**
     * Removes the item element.
     *
     * @param c the item container
     * @param n the name
     */
    static void remove_item_element(java.lang.Object c, java.lang.Object n) {

        Map m = getItem();

        if (m != null) {

            m.remove(n);

        } else {

            java.lang.System.out.println("ERROR: Could not remove item element. The item element is null.");
        }
    }

    /**
     * Returns the item element.
     *
     * @param c the item container
     * @param i the index
     * @return the item
     */
    static ItemContainer get_item_element(java.lang.Object c, int i) {

        ItemContainer c = null;
        Map m = getItem();

        if (m != null) {

            c = (ItemContainer) m.get(i);

        } else {

            java.lang.System.out.println("ERROR: Could not get item element. The item element is null.");
        }

        return c;
    }

    /**
     * Returns the item element.
     *
     * @param c the item container
     * @param n the name
     * @return the item
     */
    static ItemContainer get_item_element(java.lang.Object c, java.lang.Object n) {

        ItemContainer c = null;
        Map m = getItem();

        if (m != null) {

            c = (ItemContainer) m.get(n);

        } else {

            java.lang.System.out.println("ERROR: Could not get item element. The item element is null.");
        }

        return c;
    }

    /**
     * Returns the item element.
     *
     * @param c the item container
     * @param n the name
     * @param d the default item
     * @return the item
     */
    static ItemContainer get_item_element(java.lang.Object c, java.lang.Object n, java.lang.Object d) {

        ItemContainer c = getItem(n);

        if (c == null) {

            c = d;
        }

        return c;
    }

    /**
     * Returns the number of items whose name starts with the given name as word base.
     *
     * @param c the item container
     * @param n the name
     */
    static int get_element_count(java.lang.Object c, java.lang.Object n) {

        int c = -1;
        Map m = getItem();

        if (m != null) {

            c = m.getCount(n);

        } else {

            java.lang.System.out.println("ERROR: Could not get item element count. The item element is null.");
        }
        
        return c;
    }

    //
    // Initialization.
    //
    
    /**
     * Initializes the item.
     *
     * Parses the file of the given category.
     *
     * @param i the item
     * @param c the category
     */
    static void initialize(java.lang.Object i, java.lang.Object c) throws Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) ItemHandler.xml_parser;

        if (p != null) {
            
            java.lang.String f = c + ".cybol";

            p.parse(f);
            java.lang.System.out.println("INFO: Parsed file: " + f);
            
            org.w3c.dom.Document d = p.getDocument();

            ItemHandler.process_document(i, d);
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item. The parser is null.");
        }
    }

    /**
     * Processes the item document.
     *
     * @param i the item
     * @param d the document
     */
    static void process_document(java.lang.Object item, java.lang.Object d) {

        org.w3c.dom.Document doc = (org.w3c.dom.Document) d;

        if (doc != null) {
            
            doc.normalize();
    
            org.w3c.dom.NodeList l = null;

            l = doc.getElementsByTagName("name");
            ItemHandler.process_name(i, l);
            
            l = doc.getElementsByTagName("super");
            ItemHandler.process_super(i, l);
                
            l = doc.getElementsByTagName("item");
            ItemHandler.process_items(i, l);

        } else {
            
            java.lang.System.out.println("ERROR: The document is null.");
        }
    }
    
    /**
     * Processes the name node element.
     *
     * @param i the item
     * @param l the node list
     */
    static void process_name(java.lang.Object i, java.lang.Object l) {

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.Object name = n.getNodeValue();
                java.lang.System.out.println("INFO: Read name: " + name);
                
            } else {
                
                java.lang.System.out.println("ERROR: Could not process the name. The node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not process the name. The node list is null.");
        }
    }

    /**
     * Processes the super node element.
     *
     * @param i the item
     * @param l the node list
     */
    static void process_super(java.lang.Object i, java.lang.Object l) {

        if (l != null) {
        
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.Object super_category = n.getNodeValue();
                java.lang.System.out.println("INFO: Read super: " + super_category);
                
            } else {
                
                java.lang.System.out.println("ERROR: Could not process the super. The node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not process the super. The node list is null.");
        }
    }

    /**
     * Processes the item node elements.
     *
     * @param i the item
     * @param l the node list
     */
    static void process_items(java.lang.Object i, java.lang.Object l) {

        if (l != null) {
        
            int j = 0;
            int size = l.getLength();
            org.w3c.dom.Node n = null;
            org.w3c.dom.NamedNodeMap m = null;
            java.lang.Object item = null;

            while (j < size) {
            
                n = l.item(j);

                if (n != null) {

                    // Read and process attributes.
                    m = n.getAttributes();
                    process_node_map(i, m);

/*??
                    // Read serialized child items.
                    item = n.getNodeValue();
                    java.lang.System.out.println("INFO: Read item.");
*/
                
                } else {
                    
                    java.lang.System.out.println("ERROR: Could not process the items. The node is null.");
                }
                
                i++;
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not process the items. The node list is null.");
        }
    }

    /**
     * Processes the attribute node map.
     *
     * @param i the item
     * @param m the node map
     */
    static void process_node_map(java.lang.Object i, java.lang.Object m) {

        name = ItemHandler.getAttribute(m, ItemElement.NAME);
        
        category_abstraction = ItemHandler.getAttribute(m, ItemElement.CATEGORY_ABSTRACTION);
        category = ItemHandler.getAttribute(m, ItemElement.CATEGORY);
        java.lang.Object category_child = create_item_element(category_abstraction, category);
        add_item_element(item, name, category_child);
        
        space_abstraction = ItemHandler.getAttribute(m, ItemElement.SPACE_ABSTRACTION);
        space = ItemHandler.getAttribute(m, ItemElement.SPACE);
        java.lang.Object space_child = create_item_element(space_abstraction, space);
        add_item_element(item, name, space_child);
        
        time_abstraction = ItemHandler.getAttribute(m, ItemElement.TIME_ABSTRACTION);
        time = ItemHandler.getAttribute(m, ItemElement.TIME);
        java.lang.Object time_child = create_item_element(time_abstraction, time);
        add_item_element(item, name, time_child);
        
        java.lang.System.out.println("INFO: Successfully read item: " + name);
    }

    /**
     * Returns the attribute.
     *
     * @param m the node map
     * @param n the name
     * @return the attribute
     */
    static java.lang.Object get_attribute(java.lang.Object m, java.lang.Object n) {
    
        java.lang.Object a = null;
        org.w3c.dom.NamedNodeMap am = (org.w3c.dom.NamedNodeMap) m;

        if (am != null) {
    
            org.w3c.dom.Node e = am.getNamedItem(n);
            
            if (e != null) {
                
                a = e.getNodeValue();
        
            } else {
                
                java.lang.System.out.println("ERROR: Could not get attribute. The attribute element is null.");
            }
        
        } else {
            
            java.lang.System.out.println("ERROR: Could not get attribute. The node map is null.");
        }

        return a;
    }
    
    /**
     * Finalizes this item.
     *
     * This method's name is <code>finalizz</code> and not <code>finalize</code>
     * because the java computer language already uses <code>finalize</code> in
     * its <code>java.lang.Object</code> class.
     *
     * This method will be renamed to <code>finalize</code> as soon as the new
     * and simplified CYBOL computer language is used.
     */
    static void finalizz() {
    }

    //
    // Functionality.
    //

    /**
     * Returns the item at the given position.
     *
     * @param p the position relative to this container item
     * @return the item
     */
/*??
    static Item getChild(Space p) {

        Item child = null;
        Item[] c = getChildren();

        if (c != null) {

            int no = getChildrenNumber();
            Item item = null;
            Space rp = null;
            Integer n = null;
            int i = 0;

            while (i < no) {

                item = c[i];

                // Transform position into a position relative to (within) the child item.
                rp = new Space(); //?? p.subtract(originPositionDesChildItems);

                if (item != null) {

                    if (item.contains(rp)) {

                        // Set resulting child item to the current item by default.
                        // If the current item does not have children or none of the
                        // child items contains the position, then the child item is
                        // returned itself.
                        // For example, a mouse may be clicked on a panel, in the gap between
                        // two buttons. Then, none of the buttons contains the given position
                        // but the panel as parent container of the buttons does.
                        child = item;
                        n = item.getChildrenNumber();
    
                        if (n != null) {
                            
                            if (n.isGreaterThan(0)) {
    
                                // The child item has children, so call this method
                                // recursively on child item, to get the child item's
                                // child item which is located at the given position.
                                child = item.getChild(rp);
                            }
                        }
                    }
    
                } else {
        
                    java.lang.System.out.println("Could not get child item. An item is null.");
                }
                
                i++;
            }

        } else {

            java.lang.System.out.println("Could not get child item. The children array is null.");
        }

        return child;
    }

    /**
     * Checks whether or not this item contains the given position.
     *
     * @param p the position relative to this item
     * @return true if this item contains the given position;
     * false otherwise
     */
/*??
    static boolean contains(Structure p) {

        boolean b = false;
        Structure s = null; //?? getChild(Item.SPACE);

        if (s != null) {

            b = s.contains(p);

        } else {

            java.lang.System.out.println("Could not check position. The space is null.");
        }

        return b;
    }
*/
}

