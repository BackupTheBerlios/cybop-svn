/*
 * $RCSfile: CategoryHandler.java,v $
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
 * This is a category handler.
 *
 * @version $Revision: 1.1 $ $Date: 2003-07-27 22:50:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class CategoryHandler {

    //
    // Constants.
    //
    
    /** The cybol file suffix. */
    static java.lang.String CYBOL = ".cybol";

    /** The cybol path. */
    static java.lang.String PATH = "/home/cybop/src/";

    /** The super category. */
    static java.lang.String SUPER_CATEGORY = "super_category";

    /** The java object. */
    static java.lang.String JAVA_OBJECT = "java_object";

    /** The item category. */
    static java.lang.String ITEM_CATEGORY = "item_category";

    /** The item abstraction. */
    static java.lang.String ITEM_ABSTRACTION = "item_abstraction";

    /** The position category. */
    static java.lang.String POSITION_CATEGORY = "position_category";

    /** The position abstraction. */
    static java.lang.String POSITION_ABSTRACTION = "position_abstraction";

    /** The instance category. */
    static java.lang.String INSTANCE_CATEGORY = "instance_category";

    /** The instance abstraction. */
    static java.lang.String INSTANCE_ABSTRACTION = "instance_abstraction";

    /** The interaction category. */
    static java.lang.String INTERACTION_CATEGORY = "interaction_category";

    /** The interaction abstraction. */
    static java.lang.String INTERACTION_ABSTRACTION = "interaction_abstraction";

    /** The xml parser. */
    static java.lang.Object xml_parser;

    //
    // Category management.
    //

    /**
     * Creates a category.
     *
     * @return the category
     */
    static java.lang.Object create_category() {

        Category c = new Category();

        if (c != null) {

            java.lang.System.out.println("INFO: Create category.");

            c.items = MapHandler.create_map();

        } else {

            java.lang.System.out.println("ERROR: Could not create category. The category is null.");
        }

        return c;
    }

    /**
     * Destroys the category.
     *
     * @param o the category
     */
    static void destroy_category(java.lang.Object o) {

        Category c = (Category) o;
        
        if (c != null) {

            java.lang.System.out.println("INFO: Destroy category.");

            java.lang.Object items = c.items;
            c.items = null;
            MapHandler.destroy_map(items);

        } else {

            java.lang.System.out.println("ERROR: Could not destroy category. The category is null.");
        }
    }

    /**
     * Initializes the category.
     *
     * Parses the file of the given category.
     *
     * @param p1 the item
     * @param p2 the category
     */
    static void initialize_category(java.lang.Object p1, java.lang.Object p2) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) ItemHandler.xml_parser;
        java.lang.String f = ItemHandler.PATH + c + ItemHandler.CYBOL;

        if (p != null) {
            
            java.lang.System.out.println("INFO: Initialize item: " + c);

            p.parse(f);
            ItemHandler.read_document(i, p.getDocument());
            
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

        java.lang.System.out.println("INFO: Finalize item: " + c);
    }

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
            
            java.lang.System.out.println("INFO: Read document.");

            doc.normalize();
    
            org.w3c.dom.NodeList l = null;

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
                
                java.lang.System.out.println("INFO: Read super.");
                java.lang.Object super_category = n.getNodeValue();
                
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
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Read java object.");
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
                
            java.lang.System.out.println("INFO: Read java object attributes.");
            java.lang.Object c = ItemHandler.read_attribute(m, JavaObjectHandler.CATEGORY);
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
            
            java.lang.System.out.println("INFO: Read items.");

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
                
            java.lang.System.out.println("INFO: Read item attributes.");

            java.lang.Object n = ItemHandler.read_attribute(m, ItemHandler.NAME);
            java.lang.Object a = null;
            java.lang.Object c = null;
            java.lang.Object it = null;
            
            a = ItemHandler.read_attribute(m, ItemHandler.ITEM_ABSTRACTION);
            c = ItemHandler.read_attribute(m, ItemHandler.ITEM_CATEGORY);
            it = ItemHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.items, n, it);

            /*??
                The following lines cause problems!
                For some reason, all new items are added to all of
                i.items, i.spaces, i.times
                Or, also possible, that all three point to the same map.
                But all maps are created correctly, independently. Hm :-(
            */            
/*??
            a = ItemHandler.read_attribute(m, ItemHandler.SPACE_ABSTRACTION);
            c = ItemHandler.read_attribute(m, ItemHandler.SPACE_CATEGORY);
            it = ItemHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.spaces, n, it);
            
            a = ItemHandler.read_attribute(m, ItemHandler.TIME_ABSTRACTION);
            c = ItemHandler.read_attribute(m, ItemHandler.TIME_CATEGORY);
            it = ItemHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.times, n, it);
*/
            
/*??
            if (n.equals("date")) {
            
                java.lang.System.out.println("\n\n\n");
                
                for (int x = 0; x < ArrayHandler.get_array_size(((Map) i.times).names); x++) {
                    
                    java.lang.System.out.println(i.times);

                    java.lang.Object test1 = ArrayHandler.get_array_element(((Map) i.times).names, x);
                    java.lang.System.out.println(test1);

                    java.lang.Object test2 = MapHandler.get_map_element(i.times, x);
                    java.lang.System.out.println(test2);
                }
                
                java.lang.System.out.println("\n\n\n");
                java.lang.System.exit(0);
            }
*/

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
                
                java.lang.System.out.println("INFO: Read attribute.");

                a = e.getNodeValue();
        
            } else {
                
                java.lang.System.out.println("WARNING: Could not get attribute. The attribute element is null.");
            }
        
        } else {
            
            java.lang.System.out.println("ERROR: Could not get attribute. The node map is null.");
        }

        return a;
    }
}

