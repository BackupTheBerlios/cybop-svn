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
 * entity which contains items is called their. Containers have a contract
 * with the items they contain, in that methods are called in a specific order,
 * called a lifecycle.<br><br>
 *
 * By calling the lifecycle methods, a ensures the proper startup and
 * shutdown of each item, to work correctly. One or more methods can be called
 * by the, but the order must be the same.<br>
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
 * @version $Revision: 1.16 $ $Date: 2003-07-25 23:47:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemHandler {

    //
    // Constants.
    //
    
    /** The cybol file suffix. */
    static java.lang.String CYBOL = ".cybol";

    /** The cybol path. */
    static java.lang.String PATH = "/home/cybop/src/";

    /** The name. */
    static java.lang.String NAME = "name";

    /** The super. */
    static java.lang.String SUPER = "super";

    /** The java object. */
    static java.lang.String JAVA_OBJECT = "java_object";

    /** The item. */
    static java.lang.String ITEM = "item";

    /** The item abstraction. */
    static java.lang.String ITEM_ABSTRACTION = "item_abstraction";

    /** The item category. */
    static java.lang.String ITEM_CATEGORY = "item_category";

    /** The space abstraction. */
    static java.lang.String SPACE_ABSTRACTION = "space_abstraction";

    /** The space category. */
    static java.lang.String SPACE_CATEGORY = "space_category";

    /** The time abstraction. */
    static java.lang.String TIME_ABSTRACTION = "time_abstraction";

    /** The time category. */
    static java.lang.String TIME_CATEGORY = "time_category";

    /** The xml parser. */
    static java.lang.Object xml_parser;

    //
    // XML parser.
    //

    /**
     * Creates an xml parser.
     *
     * @return the xml parser
     */
    static java.lang.Object create_xml_parser() throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = new org.apache.xerces.parsers.DOMParser();

        if (p != null) {
            
            p.setFeature("http://xml.org/sax/features/validation", true);
            
        } else {
            
            java.lang.System.out.println("ERROR: The parser is null.");
        }
        
        return p;
    }

    /**
     * Destroys the xml parser.
     *
     * @param p the xml parser
     */
    static void destroy_xml_parser(java.lang.Object p) {
    }

    //
    // Item management.
    //

    /**
     * Creates an item.
     *
     * @return the item
     */
    static java.lang.Object create_item() {

        Item c = new Item();

        if (c != null) {

            java.lang.System.out.println("INFO: Create item.");
            c.item_abstractions = MapHandler.create_map();
            c.items = MapHandler.create_map();
            c.space_abstractions = MapHandler.create_map();
            c.spaces = MapHandler.create_map();
            c.time_abstractions = MapHandler.create_map();
            c.times = MapHandler.create_map();
            c.force_abstractions = MapHandler.create_map();
            c.forces = MapHandler.create_map();

        } else {

            java.lang.System.out.println("ERROR: Could not create item. The item is null.");
        }

        return c;
    }

    /**
     * Destroys the item.
     *
     * @param c the item
     */
    static void destroy_item(java.lang.Object c) {

        Item ic = (Item) c;
        
        if (ic != null) {

            java.lang.System.out.println("INFO: Destroy item.");
            java.lang.Object forces = ic.forces;
            ic.forces = null;
            MapHandler.destroy_map(forces);

            java.lang.Object force_abstractions = ic.force_abstractions;
            ic.force_abstractions = null;
            MapHandler.destroy_map(force_abstractions);

            java.lang.Object times = ic.times;
            ic.times = null;
            MapHandler.destroy_map(times);

            java.lang.Object time_abstractions = ic.time_abstractions;
            ic.time_abstractions = null;
            MapHandler.destroy_map(time_abstractions);

            java.lang.Object spaces = ic.spaces;
            ic.spaces = null;
            MapHandler.destroy_map(spaces);

            java.lang.Object space_abstractions = ic.space_abstractions;
            ic.space_abstractions = null;
            MapHandler.destroy_map(space_abstractions);

            java.lang.Object items = ic.items;
            ic.items = null;
            MapHandler.destroy_map(items);

            java.lang.Object item_abstractions = ic.item_abstractions;
            ic.item_abstractions = null;
            MapHandler.destroy_map(item_abstractions);

        } else {

            java.lang.System.out.println("ERROR: Could not destroy item. The item is null.");
        }
    }

    //
    // Item element management.
    //

    /**
     * Creates an element.
     *
     * @param a the abstraction
     * @param c the category
     * @return the element
     */
    static java.lang.Object create_item_element(java.lang.Object a, java.lang.Object c) throws java.lang.Exception {

        java.lang.Object i = null;

        if (a != null) {

            if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                i = PrimitiveHandler.create_integer_primitive(c);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                i = PrimitiveHandler.create_float_primitive(c);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                i = PrimitiveHandler.create_character_primitive(c);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                i = PrimitiveHandler.create_string_primitive(c);

            } else if (a.equals(Statics.COMPLEX)) {

                i = ItemHandler.create_item();
                ItemHandler.initialize(i, c);
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not create element. The abstraction is null.");
        }

        return i;
    }

    /**
     * Destroys the element.
     *
     * @param a the abstraction
     * @param c the category
     * @param i the element
     */
    static java.lang.Object destroy_item_element(java.lang.Object a, java.lang.Object c, java.lang.Object i) throws java.lang.Exception {

        if (a != null) {

            if (a.equals(Statics.INTEGER_PRIMITIVE)) {

                PrimitiveHandler.destroy_integer_primitive(i);

            } else if (a.equals(Statics.FLOAT_PRIMITIVE)) {

                PrimitiveHandler.destroy_float_primitive(i);

            } else if (a.equals(Statics.CHAR_PRIMITIVE)) {

                PrimitiveHandler.destroy_character_primitive(i);

            } else if (a.equals(Statics.STRING_PRIMITIVE)) {

                PrimitiveHandler.destroy_string_primitive(i);

            } else if (a.equals(Statics.COMPLEX)) {

                ItemHandler.finalizz(i, c);
                ItemHandler.destroy_item(i);
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not destroy element. The abstraction is null.");
        }

        return i;
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
    static void initialize(java.lang.Object i, java.lang.Object c) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) ItemHandler.xml_parser;

        if (p != null) {
            
            java.lang.String f = ItemHandler.PATH + c + ItemHandler.CYBOL;

            java.lang.System.out.println("INFO: Parse file: " + f);
            p.parse(f);
            
            org.w3c.dom.Document d = p.getDocument();

            ItemHandler.read_document(i, d);
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize item. The parser is null.");
        }
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
     *
     * @param i the item
     * @param c the category
     */
    static void finalizz(java.lang.Object i, java.lang.Object c) {
    }

    //
    // XML document.
    //
    
    /**
     * Reads the document.
     *
     * @param i the item
     * @param d the document
     */
    static void read_document(java.lang.Object i, java.lang.Object d) throws java.lang.Exception {

        org.w3c.dom.Document doc = (org.w3c.dom.Document) d;

        if (doc != null) {
            
            doc.normalize();
    
            org.w3c.dom.NodeList l = null;

            l = doc.getElementsByTagName(ItemHandler.NAME);
            ItemHandler.read_name(i, l);
            
            l = doc.getElementsByTagName(ItemHandler.SUPER);
            ItemHandler.read_super(i, l);
                
            l = doc.getElementsByTagName(ItemHandler.JAVA_OBJECT);
            ItemHandler.read_java_object(i, l);
                
            l = doc.getElementsByTagName(ItemHandler.ITEM);
            ItemHandler.read_items(i, l);

        } else {
            
            java.lang.System.out.println("ERROR: The document is null.");
        }
    }
    
    //
    // Name.
    //
    
    /**
     * Reads the name.
     *
     * @param i the item
     * @param l the name node list
     */
    static void read_name(java.lang.Object i, java.lang.Object l) {
        
        org.w3c.dom.NodeList nl = (org.w3c.dom.NodeList) l;

        if (nl != null) {
            
            org.w3c.dom.Node n = nl.item(0);
            
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

    //
    // Super.
    //
    
    /**
     * Reads the super.
     *
     * @param i the item
     * @param l the super node list
     */
    static void read_super(java.lang.Object i, java.lang.Object l) {

        org.w3c.dom.NodeList nl = (org.w3c.dom.NodeList) l;

        if (nl != null) {
            
            org.w3c.dom.Node n = nl.item(0);
            
            if (n != null) {
                
                java.lang.Object super_category = n.getNodeValue();
                java.lang.System.out.println("INFO: Read super: " + super_category);
                
            } else {
                
                java.lang.System.out.println("WARNING: Could not process the super. The node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not process the super. The node list is null.");
        }
    }

    //
    // Java object.
    //
    
    /**
     * Reads the java object.
     *
     * @param i the item
     * @param l the java object node list
     */
    static void read_java_object(java.lang.Object i, java.lang.Object l) throws java.lang.Exception {

        org.w3c.dom.NodeList nl = (org.w3c.dom.NodeList) l;

        if (nl != null) {
            
            org.w3c.dom.Node n = nl.item(0);
            java.lang.System.out.println("INFO: Read java object: " + n);
            
            if (n != null) {
                
                // Read and process attributes.
                org.w3c.dom.NamedNodeMap m = n.getAttributes();
                read_java_object_attributes(i, m);
                
            } else {
                
                java.lang.System.out.println("WARNING: Could not process the java object. The node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not process the java object. The node list is null.");
        }
    }

    /**
     * Reads the java object attributes.
     *
     * @param o the item
     * @param m the attributes node map
     */
    static void read_java_object_attributes(java.lang.Object o, java.lang.Object m) throws java.lang.Exception {

        Item i = (Item) o;
        
        if (i != null) {
                
            java.lang.Object c = ItemHandler.read_attribute(m, JavaObjectHandler.CATEGORY);
            java.lang.System.out.println("INFO: Read java object category: " + c);
            java.lang.Object jo = JavaObjectHandler.create_java_object(c);
            i.java_object = jo;

            ItemHandler.initialize_java_object(i.java_object, m);

        } else {
            
            java.lang.System.out.println("ERROR: Could not read java object attributes. The item is null.");
        }
    }

    /**
     * Initializes the java object.
     *
     * @param o the java object
     * @param m the attributes node map
     */
    static void initialize_java_object(java.lang.Object o, java.lang.Object m) throws java.lang.Exception {

        if (o != null) {

            java.lang.System.out.println("INFO: Initialize java object.");
            
            if (o instanceof javax.swing.JFrame) {
                    
                java.lang.String width = (java.lang.String) ItemHandler.read_attribute(m, JavaObjectHandler.WIDTH);
                java.lang.String height = (java.lang.String) ItemHandler.read_attribute(m, JavaObjectHandler.HEIGHT);
                ((javax.swing.JFrame) o).setSize(java.lang.Integer.parseInt(width), java.lang.Integer.parseInt(height));
                ((javax.swing.JFrame) o).setVisible(true);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java object. The java object is null.");
        }
    }

    //
    // Items.
    //
    
    /**
     * Reads the items.
     *
     * @param i the item
     * @param l the items node list
     */
    static void read_items(java.lang.Object i, java.lang.Object l) throws java.lang.Exception {

        org.w3c.dom.NodeList nl = (org.w3c.dom.NodeList) l;

        if (nl != null) {
            
            int j = 0;
            int size = nl.getLength();
            org.w3c.dom.Node n = null;
            org.w3c.dom.NamedNodeMap m = null;
            java.lang.Object item = null;

            while (j < size) {
            
                n = nl.item(j);

                if (n != null) {

                    // Read and process attributes.
                    m = n.getAttributes();
                    read_item_attributes(i, m);

/*??
                    // Read serialized child items.
                    item = n.getNodeValue();
                    java.lang.System.out.println("INFO: Read item.");
*/
                
                } else {
                    
                    java.lang.System.out.println("ERROR: Could not process the items. The node is null.");
                }
                
                j++;
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not process the items. The node list is null.");
        }
    }

    /**
     * Reads the item attributes.
     *
     * @param o the item
     * @param m the attributes node map
     */
    static void read_item_attributes(java.lang.Object o, java.lang.Object m) throws java.lang.Exception {

        Item i = (Item) o;
        
        if (i != null) {
                
            java.lang.Object n = ItemHandler.read_attribute(m, ItemHandler.NAME);
            java.lang.Object a = null;
            java.lang.Object c = null;
            java.lang.Object it = null;
            
            a = ItemHandler.read_attribute(m, ItemHandler.ITEM_ABSTRACTION);
            c = ItemHandler.read_attribute(m, ItemHandler.ITEM_CATEGORY);
            it = ItemHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.items, n, it);
            
            a = ItemHandler.read_attribute(m, ItemHandler.SPACE_ABSTRACTION);
            c = ItemHandler.read_attribute(m, ItemHandler.SPACE_CATEGORY);
            it = ItemHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.spaces, n, it);
            
            if ("date".equals(n)) {
            
                java.lang.System.out.println("\n\n\n");
                
                for (int x = 0; x < ArrayHandler.get_array_size(((Map) i.items).names); x++) {
                    
//??                    java.lang.Object test = MapHandler.get_map_element(i.items, n);
                    java.lang.Object test1 = MapHandler.get_map_element(i.items, x);
                    java.lang.System.out.println(test1);

                    java.lang.Object test2 = ArrayHandler.get_array_element(((Map) i.items).names, x);
                    java.lang.System.out.println(test2);
                }
                
                java.lang.System.out.println("\n\n\n");
                java.lang.System.exit(0);
            }

            a = ItemHandler.read_attribute(m, ItemHandler.TIME_ABSTRACTION);
            c = ItemHandler.read_attribute(m, ItemHandler.TIME_CATEGORY);
            it = ItemHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.times, n, it);
            
            java.lang.System.out.println("INFO: Read item: " + n);
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not read item attributes. The item is null.");
        }
    }

    /**
     * Reads the attribute.
     *
     * @param o the attributes node map
     * @param n the name
     * @return the attribute
     */
    static java.lang.Object read_attribute(java.lang.Object o, java.lang.Object n) {
    
        java.lang.Object a = null;
        org.w3c.dom.NamedNodeMap m = (org.w3c.dom.NamedNodeMap) o;

        if (m != null) {
    
            org.w3c.dom.Node e = m.getNamedItem((java.lang.String) n);
            
            if (e != null) {
                
                a = e.getNodeValue();
        
            } else {
                
                java.lang.System.out.println("WARNING: Could not get attribute. The attribute element is null.");
            }
        
        } else {
            
            java.lang.System.out.println("ERROR: Could not get attribute. The node map is null.");
        }

        return a;
    }
    
    //
    // Functionality.
    //

    /**
     * Returns the item at the given position.
     *
     * @param p the position relative to this item
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
                        // but the panel as parent of the buttons does.
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

