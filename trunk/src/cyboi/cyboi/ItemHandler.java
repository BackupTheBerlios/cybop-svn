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
 * @version $Revision: 1.8 $ $Date: 2003-07-22 12:04:39 $ $Author: christian $
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
            
            java.lang.System.out.println("ERROR: The abstraction is null.");
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
     * @param item the item
     * @param c the category
     */
    static void initialize(java.lang.Object item, java.lang.Object c) throws Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) ItemHandler.xml_parser;
        org.w3c.dom.Document doc = new org.apache.xerces.dom.DocumentImpl();
        java.lang.String f = c + ".cybol";

        if (p != null) {
            
            p.parse(f);
            java.lang.System.out.println("INFO: Parsed file: " + f);
            
            doc = p.getDocument();
            
            if (doc != null) {
                
                doc.normalize();
        
                org.w3c.dom.NodeList l = null;
                org.w3c.dom.Node n = null;

/*??
                l = doc.getElementsByTagName("name");
                
                if (l != null) {
                    
                    n = l.item(0);
                    
                    if (n != null) {
                        
                        String name = n.getNodeValue();
                        java.lang.System.out.println("INFO: Read name: " + name);
                        
                    } else {
                        
                        java.lang.System.out.println("ERROR: The node is null.");
                    }
                    
                } else {
                    
                    java.lang.System.out.println("ERROR: The node list is null.");
                }
                    
                l = doc.getElementsByTagName("super");
                
                if (l != null) {
                    
                    n = l.item(0);
                    
                    if (n != null) {
                        
                        String superCategory = n.getNodeValue();
                        java.lang.System.out.println("INFO: Read super: " + superCategory);
                        
                    } else {
                        
                        java.lang.System.out.println("ERROR: The node is null.");
                    }
                    
                } else {
                    
                    java.lang.System.out.println("ERROR: The node list is null.");
                }
*/
                    
                l = doc.getElementsByTagName("item");

                if (l != null) {
                    
                    int size = l.getLength();
                    int i = 0;
                    org.w3c.dom.NamedNodeMap m = null;
                    int msize = 0;
                    int j = 0;
                    org.w3c.dom.Node a = null;
                    java.lang.String name = null;
                    java.lang.String abstraction = null;
                    java.lang.String category = null;
       
                    while (i < size) {
                    
                        n = l.item(i);

                        if (n != null) {
                                
/*??
                            item = n.getNodeValue();
                            java.lang.System.out.println("INFO: Read item: " + item);
*/
                        
                            m = n.getAttributes();
    
                            name = ItemHandler.getAttribute(m, "name");
                            java.lang.System.out.println(name);
    
                            category_abstraction = ItemHandler.getAttribute(m, "category_abstraction");
                            java.lang.System.out.println(category_abstraction);
                            category = ItemHandler.getAttribute(m, "category");
                            java.lang.System.out.println(category);
                            java.lang.Object category_child = create_item_element(category_abstraction, category);
                            add_item_element(item, name, category_child);
    
                            space_abstraction = ItemHandler.getAttribute(m, "space_abstraction");
                            java.lang.System.out.println(space_abstraction);
                            space = ItemHandler.getAttribute(m, "space");
                            java.lang.System.out.println(space);
                            java.lang.Object space_child = create_item_element(space_abstraction, space);
                            add_item_element(item, name, space_child);

                            time_abstraction = ItemHandler.getAttribute(m, "time_abstraction");
                            java.lang.System.out.println(time_abstraction);
                            time = ItemHandler.getAttribute(m, "time");
                            java.lang.System.out.println(time);
                            java.lang.Object time_child = create_item_element(time_abstraction, time);
                            add_item_element(item, name, time_child);

                        } else {
                            
                            java.lang.System.out.println("ERROR: The node is null.");
                        }
                        
                        i++;
                    }
                    
                } else {
                    
                    java.lang.System.out.println("ERROR: The node list is null.");
                }

            } else {
                
                java.lang.System.out.println("ERROR: The document is null.");
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: The parser is null.");
        }
            
/*??
        File f = new File(c);
        XmlItem xml = null;

        while (f != eof) {

            xml = readNextItem(f);

            initialize(i, xml);
        }
*/

/*??
        File f = new File("/home/cybop/src/cybol/cybol/test.xml");
        FileReader r = new FileReader(f);
        int ci;
        
        while (true) {
        
            ci = r.read();
            
            if (ci != -1) {
            
               System.out.println(ci);
            
            } else {
                
                break;
            }
        }
        
        r.close();
*/
    }

    /**
     * Returns the attribute.
     *
     * @param c the attributes container
     * @param n the name
     * @return the attribute
     */
    static java.lang.Object get_attribute(java.lang.Object c, java.lang.Object n) {
    
        java.lang.Object a = null;
        org.w3c.dom.NamedNodeMap ac = (org.w3c.dom.NamedNodeMap) c;

        if (ac != null) {
    
            org.w3c.dom.Node e = ac.getNamedItem(n);
            
            if (e != null) {
                
                a = e.getNodeValue();
        
            } else {
                
                java.lang.System.out.println("ERROR: Could not get attribute. The attribute element is null.");
            }
        
        } else {
            
            java.lang.System.out.println("ERROR: Could not get attribute. The attributes container is null.");
        }

        return a;
    }
    
    /**
     * Reads a sub array as a sequence of bytes.
     *
     * @param b the byte array into which the data are written
     * @param o the offset in the data
     * @param n the number of bytes to be written
     */
/*??
    static void readbytes(byte[] b, int o, int n) {

        // Code.
        
        // See: Aelfred XMLParser!
    }

    /**
     * Initializes the item.
     *
     * @param i the item
     * @param c the category
     */
/*??
    static void initialize(java.lang.Object i, java.lang.Object c) {

        String name = tmp.name;
        String abstraction = tmp.abstraction;
        String category = tmp.category;
        String position = tmp.position;

        if (abstraction != null) {

            if (abstraction.equals(Main.INTEGER_PRIMITIVE)) {

                i = createIntegerPrimitive(category);

            } else if (abstraction.equals(Main.FLOAT_PRIMITIVE)) {

                i = createFloatPrimitive(category);

            } else if (abstraction.equals(Main.CHAR_PRIMITIVE)) {

                i = createCharPrimitive(category);

            } else if (abstraction.equals(Main.STRING_PRIMITIVE)) {

                i = createStringPrimitive(category);

            } else if (abstraction.equals(Main.COMPLEX)) {

                i = createItem(category);
            }
            
            add(i);

        } else {

            java.lang.System.out.println("ERROR: Could not read item. The abstraction is null.");
        }
    }
*/

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
/*??
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

