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
 * @version $Revision: 1.2 $ $Date: 2003-07-28 22:15:54 $ $Author: christian $
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
    // Category.
    //

    /**
     * Initializes the category.
     *
     * @param p0 the category
     * @param p1 the category location
     */
    static void initialize_category(java.lang.Object p0, java.lang.Object p1) {

        java.lang.System.out.println("INFO: Initialize category.");
        
        CategoryHandler.initialize_category_containers(p0);
        CategoryHandler.initialize_category_elements(p0, p1);
    }

    /**
     * Finalizes the category.
     *
     * @param p0 the category
     * @param p1 the category location
     */
    static void finalize_category(java.lang.Object p0, java.lang.Object p1) {

        java.lang.System.out.println("INFO: Finalize category.");
        
        CategoryHandler.finalize_category_elements(p0, p1);
        CategoryHandler.finalize_category_containers(p0);
    }

    //
    // Category containers.
    //

    /**
     * Initializes the category containers.
     *
     * @param p0 the category
     */
    static void initialize_category_containers(java.lang.Object p0) {

        Category c = (Category) p0;

        if (c != null) {

            java.lang.System.out.println("INFO: Initialize category containers.");

            c.items = MapHandler.create_map();

        } else {

            java.lang.System.out.println("ERROR: Could not initialize category containers. The category is null.");
        }
    }

    /**
     * Finalizes the category containers.
     *
     * @param p0 the category
     */
    static void finalize_category_containers(java.lang.Object p0) {

        Category c = (Category) p0;
        
        if (c != null) {

            java.lang.System.out.println("INFO: Finalize category containers.");

            java.lang.Object items = c.items;
            c.items = null;
            MapHandler.destroy_map(items);

        } else {

            java.lang.System.out.println("ERROR: Could not finalize category containers. The category is null.");
        }
    }

    //
    // Category elements.
    //
    
    /**
     * Initializes the category elements.
     *
     * Reads the file of the given category.
     *
     * @param p0 the category
     * @param p1 the category location
     */
    static void initialize_category_elements(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = new org.apache.xerces.parsers.DOMParser();
        CategoryHandler.initialize_xml_parser(p);
    
        if (p != null) {
            
            java.lang.System.out.println("INFO: Initialize category elements.");

            p.parse(CategoryHandler.PATH + p1 + CategoryHandler.CYBOL);
            CategoryHandler.initialize_document(p0, p.getDocument());
            
            CategoryHandler.finalize_xml_parser(p);
            p = null;
    
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize category elements. The xml parser is null.");
        }
    }

    /**
     * Finalizes the category elements.
     *
     * Writes the file of the given category.
     *
     * @param p0 the category
     * @param p1 the category location
     */
    static void finalize_category_elements(java.lang.Object p0, java.lang.Object p1) {

/*??
        org.apache.xerces.parsers.DOMWriter p = new org.apache.xerces.parsers.DOMWriter();
        CategoryHandler.initialize_xml_writer(p);
    
        if (p != null) {
            
            java.lang.System.out.println("INFO: Finalize category elements.");

            p.write(CategoryHandler.PATH + p1 + CategoryHandler.CYBOL);
            CategoryHandler.finalize_document(p0, p.getDocument());
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not finalize category elements. The xml writer is null.");
        }
*/
    }

    //
    // Parser.
    //

    /**
     * Initializes the xml parser.
     *
     * @param p0 the xml parser
     */
    static void initialize_xml_parser(java.lang.Object p0) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) p0;

        if (p != null) {
            
            p.setFeature("http://xml.org/sax/features/validation", true);
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize xml parser. The xml parser is null.");
        }
    }

    /**
     * Finalizes the xml parser.
     *
     * @param p0 the xml parser
     */
    static void finalize_xml_parser(java.lang.Object p0) {
    }

    //
    // Document.
    //
    
    /**
     * Initializes the document.
     *
     * @param p0 the category
     * @param p1 the document
     */
    static void initialize_document(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.w3c.dom.Document doc = (org.w3c.dom.Document) p1;

        if (doc != null) {
            
            java.lang.System.out.println("INFO: Initialize document.");

            doc.normalize();
    
            org.w3c.dom.NodeList l = null;

            l = doc.getElementsByTagName(CategoryHandler.SUPER);
            CategoryHandler.initialize_super_category(p0, l);
            
            if (p0 != null) {
                    
                l = doc.getElementsByTagName(CategoryHandler.JAVA_OBJECT);
                CategoryHandler.initialize_java_object(p0.java_object, l);
                    
                l = doc.getElementsByTagName(CategoryHandler.ITEM);
                CategoryHandler.initialize_items(p0.items, l);

            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize document. The category is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize document. The document is null.");
        }
    }

    /**
     * Finalizes the document.
     *
     * @param p0 the category
     * @param p1 the document
     */
    static void finalize_document(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

/*??
        org.w3c.dom.Document doc = (org.w3c.dom.Document) p1;

        if (doc != null) {
            
            java.lang.System.out.println("INFO: Finalize document.");

            doc.normalize();
    
            org.w3c.dom.NodeList l = null;

            l = doc.getElementsByTagName(CategoryHandler.SUPER);
            CategoryHandler.finalize_super(p0, l);
                
            l = doc.getElementsByTagName(CategoryHandler.JAVA_OBJECT);
            CategoryHandler.finalize_java_object(p0, l);
                
            l = doc.getElementsByTagName(CategoryHandler.ITEM);
            CategoryHandler.finalize_items(p0, l);

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize document. The document is null.");
        }
*/
    }
    
    //
    // Super category.
    //
    
    /**
     * Initializes the super category.
     *
     * @param p0 the category
     * @param p1 the super category list
     */
    static void initialize_super_category(java.lang.Object p0, java.lang.Object p1) {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Initialize super category.");
                
                java.lang.Object s = n.getNodeValue();
                CategoryHandler.initialize_category(p0, s);
                
            } else {
                
                java.lang.System.out.println("WARNING: Could not initialize super category. The super category node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not initialize super category. The super category list is null.");
        }
    }

    /**
     * Finalizes the super category.
     *
     * @param p0 the category
     * @param p1 the super category list
     */
    static void finalize_super_category(java.lang.Object p0, java.lang.Object p1) {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Finalize super category.");
                
                java.lang.Object s = n.getNodeValue();
                CategoryHandler.finalize_category(p0, s);
                
            } else {
                
                java.lang.System.out.println("WARNING: Could not finalize super category. The super category node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not finalize super category. The super category list is null.");
        }
    }

    //
    // Java object.
    //
    
    /**
     * Initializes the java object.
     *
     * @param p0 the java object
     * @param p1 the java object list
     */
    static void initialize_java_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Initialize java object.");
                
                java.lang.Object a = n.getAttributes();
                CategoryHandler.initialize_java_object_attributes(p0, a);
                
            } else {
                
                java.lang.System.out.println("WARNING: Could not initialize java object. The java object node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not initialize java object. The java object list is null.");
        }
    }

    /**
     * Finalizes the java object.
     *
     * @param p0 the java object
     * @param p1 the java object list
     */
    static void finalize_java_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

/*??
        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Finalize java object.");
                
                java.lang.Object a = n.getAttributes();
                CategoryHandler.initialize_java_object_attributes(p0, a);
                
            } else {
                
                java.lang.System.out.println("WARNING: Could not finalize java object. The java object node is null.");
            }
            
        } else {
            
            java.lang.System.out.println("WARNING: Could not finalize java object. The java object list is null.");
        }
*/
    }

    //
    // Java object attributes.
    //
    
    /**
     * Initializes the java object attributes.
     *
     * @param p0 the java object
     * @param p1 the java object attributes map
     */
    static void initialize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.Object o = p0;
        
        if (o != null) {
                
            java.lang.System.out.println("INFO: Initialize java object attributes.");
            
            java.lang.Object c = CategoryHandler.read_attribute(p1, JavaObjectHandler.CATEGORY);
            java.lang.Object jo = JavaObjectHandler.create_java_object(c);
            i.java_object = jo;

            CategoryHandler.initialize_java_object(i.java_object, p1);

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java object attributes. The java object is null.");
        }
    }

    /**
     * Initializes the java object.
     *
     * @param p0 the java object
     * @param m the attributes node map
     */
    static void initialize_java_object(java.lang.Object o, java.lang.Object m) throws java.lang.Exception {

        if (o != null) {

            java.lang.System.out.println("INFO: Initialize java object.");
            
            if (o instanceof javax.swing.JFrame) {
                    
                java.lang.String width = (java.lang.String) CategoryHandler.read_attribute(m, JavaObjectHandler.WIDTH);
                java.lang.String height = (java.lang.String) CategoryHandler.read_attribute(m, JavaObjectHandler.HEIGHT);
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
     * Initializes the items.
     *
     * @param p0 the category
     * @param p1 the items list
     */
    static void initialize_items(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            java.lang.System.out.println("INFO: Initialize items.");

            int count = 0;
            int size = l.getLength();
            org.w3c.dom.Node n = null;
            org.w3c.dom.NamedNodeMap m = null;
            java.lang.Object i = null;

            while (count < size) {
            
                n = l.item(count);

                if (n != null) {

                    // Initialize attributes.
                    m = n.getAttributes();
                    initialize_item_attributes(p0, m);

/*??
                    // Initialize serialized item.
                    i = n.getNodeValue();
*/
                
                } else {
                    
                    java.lang.System.out.println("ERROR: Could not initialize items. The item node is null.");
                }
                
                count++;
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize items. The items list is null.");
        }
    }

    //
    // Item attributes.
    //
    
    /**
     * Initializes the item attributes.
     *
     * @param p0 the category
     * @param p1 the item attributes map
     */
    static void initialize_item_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        Category i = (Category) p0;
        
        if (i != null) {
                
            java.lang.System.out.println("INFO: Initialize item attributes.");

            java.lang.Object n = CategoryHandler.read_attribute(m, CategoryHandler.NAME);
            java.lang.Object a = null;
            java.lang.Object c = null;
            java.lang.Object it = null;
            
            a = CategoryHandler.read_attribute(m, CategoryHandler.ITEM_ABSTRACTION);
            c = CategoryHandler.read_attribute(m, CategoryHandler.ITEM_CATEGORY);
            it = CategoryHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.items, n, it);

            /*??
                The following lines cause problems!
                For some reason, all new items are added to all of
                i.items, i.spaces, i.times
                Or, also possible, that all three point to the same map.
                But all maps are created correctly, independently. Hm :-(
            */            
/*??
            a = CategoryHandler.read_attribute(m, CategoryHandler.SPACE_ABSTRACTION);
            c = CategoryHandler.read_attribute(m, CategoryHandler.SPACE_CATEGORY);
            it = CategoryHandler.create_item_element(a, c);
            MapHandler.add_map_element(i.spaces, n, it);
            
            a = CategoryHandler.read_attribute(m, CategoryHandler.TIME_ABSTRACTION);
            c = CategoryHandler.read_attribute(m, CategoryHandler.TIME_CATEGORY);
            it = CategoryHandler.create_item_element(a, c);
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
            
            java.lang.System.out.println("ERROR: Could not initialize item attributes. The category is null.");
        }
    }

    //
    // Item attribute.
    //
    
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

