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
 * @version $Revision: 1.7 $ $Date: 2003-08-05 00:00:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class CategoryHandler {

    //
    // Constants.
    //
    
    /** The cybol path. */
    static java.lang.String PATH = "/home/cybop/src/";

    /** The cybol file suffix. */
    static java.lang.String CYBOL = ".cybol";

    /** The super category. */
    static java.lang.String SUPER_CATEGORY = "super";

    /** The java object. */
    static java.lang.String JAVA_OBJECT = "javaobject";

    /** The category. */
    static java.lang.String CATEGORY = "category";

    /** The attribute. */
    static java.lang.String ATTRIBUTE = "attribute";

    /** The item. */
    static java.lang.String ITEM = "item";

    /** The name. */
    static java.lang.String NAME = "name";

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

    //
    // Global variables.
    //
    
    /** The xml parser. */
    static java.lang.Object xml_parser;

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
            
            java.lang.System.out.println("INFO: Initialize xml parser.");
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

        java.lang.System.out.println("INFO: Finalize xml parser.");
    }

    //
    // Category.
    //
    
    /**
     * Initializes the category.
     *
     * Reads the file of the given category.
     *
     * @param p0 the category
     * @param p1 the category name
     */
    static void initialize_category(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) CategoryHandler.xml_parser;
    
        if (p != null) {
            
            java.lang.System.out.println("INFO: Initialize category.");
            p.parse(CategoryHandler.PATH + p1 + CategoryHandler.CYBOL);
            CategoryHandler.read_document(p0, p.getDocument());
    
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize category elements. The xml parser is null.");
        }
    }

    /**
     * Finalizes the category.
     *
     * Writes the file of the given category.
     *
     * @param p0 the category
     * @param p1 the category name
     */
    static void finalize_category(java.lang.Object p0, java.lang.Object p1) {
    }

    //
    // Document.
    //
    
    /**
     * Reads the document.
     *
     * @param p0 the category
     * @param p1 the document
     */
    static void read_document(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("TEST document: " + p1);
        org.w3c.dom.Document doc = (org.w3c.dom.Document) p1;

        if (doc != null) {
            
            java.lang.System.out.println("INFO: Read document.");
            doc.normalize();

            org.w3c.dom.NodeList l = doc.getElementsByTagName(CategoryHandler.SUPER_CATEGORY);
            CategoryHandler.initialize_super_category(p0, l);

            l = doc.getElementsByTagName(CategoryHandler.JAVA_OBJECT);
            CategoryHandler.initialize_java_object(p0, l);
                
            Item c = (Item) p0;

            if (c != null) {
                    
                l = doc.getElementsByTagName(CategoryHandler.ITEM);
                CategoryHandler.initialize_items(c.items, l);

            } else {
                
                java.lang.System.out.println("ERROR: Could not read document. The category is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not read document. The document is null.");
        }
    }

    /**
     * Writes the document.
     *
     * @param p0 the category
     * @param p1 the document
     */
    static void write_document(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
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
    static void initialize_super_category(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("TEST nodelist 1: " + p1);
        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {

                java.lang.System.out.println("INFO: Initialize super category.");
                java.lang.Object s = CategoryHandler.read_attribute(n.getAttributes(), CategoryHandler.CATEGORY);
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
    }

    //
    // Java objects.
    //
    
    /**
     * Initializes the java objects.
     *
     * @param p0 the category
     * @param p1 the category java objects list
     */
    static void initialize_java_objects(java.lang.Object p0, java.lang.Object p1) {

        Item i = (Item) p0;
        
        if (i != null) {
            
            java.lang.System.out.println("TEST nodelist 2: " + p1);
            org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;
    
            if (l != null) {
    
                java.lang.System.out.println("INFO: Initialize java objects.");
                org.w3c.dom.Node n = l.item(0);

                if (n != null) {
                        
                    Item o = new Item();
                    ItemHandler.initialize_item_containers(o);
                    CategoryHandler.initialize_java_object(o, n);
                    i.java_object = o;
                    
                } else {
                    
                    java.lang.System.out.println("WARNING: Could not initialize java objects. The java object node is null.");
                }
                
            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize java objects. The java objects list is null.");
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java objects. The category is null.");
        }
    }

    /**
     * Finalizes the java objects.
     *
     * @param p0 the category items
     * @param p1 the category java objects list
     */
    static void finalize_java_objects(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
    }

    //
    // Java object.
    //
    
    /**
     * Initializes the java object.
     *
     * @param p0 the java object
     * @param p1 the java object node
     */
    static void initialize_java_object(java.lang.Object p0, java.lang.Object p1) {
        
        Item o = (Item) p0;
        
        if (o != null) {
        
            org.w3c.dom.Node n = (org.apache.xerces.dom.DeepNodeListImpl) p1;
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Initialize java object.");
                CategoryHandler.initialize_java_object_attributes(o.items, n.getAttributes());
        
            } else {
                
                java.lang.System.out.println("WARNING: Could not initialize java object. The java object node is null.");
            }

        } else {
            
            java.lang.System.out.println("WARNING: Could not initialize java object. The java object is null.");
        }
    }
    
    /**
     * Finalizes the java object.
     *
     * @param p0 the java object
     * @param p1 the java object node
     */
    static void finalize_java_object(java.lang.Object p0, java.lang.Object p1) {
    }
    
    //
    // Java object attributes.
    //
    
    /**
     * Initializes the java object attributes.
     *
     * @param p0 the attribute items
     * @param p1 the attributes map
     */
    static void initialize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) {

        java.lang.System.out.println("INFO: Initialize java object attributes.");
        java.lang.Object a = null;

        a = CategoryHandler.read_attribute(p1, CategoryHandler.CATEGORY);
        MapHandler.set_map_element(p0, a, CategoryHandler.CATEGORY);

        a = CategoryHandler.read_attribute(p1, JavaObjectHandler.WIDTH);
        MapHandler.set_map_element(p0, a, JavaObjectHandler.WIDTH);

        a = CategoryHandler.read_attribute(p1, JavaObjectHandler.HEIGHT);
        MapHandler.set_map_element(p0, a, JavaObjectHandler.HEIGHT);
    }

    /**
     * Finalizes the java object attributes.
     *
     * @param p0 the attribute items
     * @param p1 the attributes map
     */
    static void finalize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) {
    }

    //
    // Items.
    //
    
    /**
     * Initializes the items.
     *
     * @param p0 the category items
     * @param p1 the category items list
     */
    static void initialize_items(java.lang.Object p0, java.lang.Object p1) {

        java.lang.System.out.println("TEST nodelist 3: " + p1);
        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            java.lang.System.out.println("INFO: Initialize items.");
            int count = 0;
            int size = l.getLength();
            org.w3c.dom.Node n = null;
            Item i = null;

            while (count < size) {
            
                n = l.item(count);

                i = new Item();
                ItemHandler.initialize_item_containers(i);
                CategoryHandler.initialize_item(i, n);
                MapHandler.add_map_element(p0, i, CategoryHandler.ITEM);

/*??
                // Initialize serialized item.
                i = n.getNodeValue();
*/
                
                count++;
            }
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize items. The category items list is null.");
        }
    }

    /**
     * Finalizes the items.
     *
     * @param p0 the category items
     * @param p1 the category items list
     */
    static void finalize_items(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
    }

    //
    // Item.
    //
    
    /**
     * Initializes the item.
     *
     * @param p0 the item
     * @param p1 the item node
     */
    static void initialize_item(java.lang.Object p0, java.lang.Object p1) {
        
        Item o = (Item) p0;
        
        if (o != null) {
        
            java.lang.System.out.println("TEST node: " + p1);
            org.w3c.dom.Node n = (org.w3c.dom.Node) p1;
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Initialize item.");
                CategoryHandler.initialize_attributes(o.items, n.getAttributes());
        
            } else {
                
                java.lang.System.out.println("WARNING: Could not initialize item. The item node is null.");
            }

        } else {
            
            java.lang.System.out.println("WARNING: Could not initialize item. The item is null.");
        }
    }
    
    /**
     * Finalizes the item.
     *
     * @param p0 the item
     * @param p1 the item node
     */
    static void finalize_item(java.lang.Object p0, java.lang.Object p1) {
    }
    
    //
    // Attributes.
    //
    
    /**
     * Initializes the attributes.
     *
     * @param p0 the attribute items
     * @param p1 the attributes map
     */
    static void initialize_attributes(java.lang.Object p0, java.lang.Object p1) {

        java.lang.System.out.println("INFO: Initialize attributes.");
        java.lang.Object a = null;

        a = CategoryHandler.read_attribute(p1, CategoryHandler.ITEM_CATEGORY);
        MapHandler.set_map_element(p0, a, CategoryHandler.ITEM_CATEGORY);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.ITEM_ABSTRACTION);
        MapHandler.set_map_element(p0, a, CategoryHandler.ITEM_ABSTRACTION);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.POSITION_CATEGORY);
        MapHandler.set_map_element(p0, a, CategoryHandler.POSITION_CATEGORY);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.POSITION_ABSTRACTION);
        MapHandler.set_map_element(p0, a, CategoryHandler.POSITION_ABSTRACTION);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INSTANCE_CATEGORY);
        MapHandler.set_map_element(p0, a, CategoryHandler.INSTANCE_CATEGORY);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INSTANCE_ABSTRACTION);
        MapHandler.set_map_element(p0, a, CategoryHandler.INSTANCE_ABSTRACTION);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INTERACTION_CATEGORY);
        MapHandler.set_map_element(p0, a, CategoryHandler.INTERACTION_CATEGORY);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INTERACTION_ABSTRACTION);
        MapHandler.set_map_element(p0, a, CategoryHandler.INTERACTION_ABSTRACTION);
    }

    /**
     * Finalizes the attributes.
     *
     * @param p0 the attribute items
     * @param p1 the attributes map
     */
    static void finalize_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
    }

    //
    // Attribute.
    //
    
    /**
     * Reads the attribute.
     *
     * @param p0 the attributes map
     * @param p1 the attribute name
     * @return the attribute
     */
    static java.lang.Object read_attribute(java.lang.Object p0, java.lang.Object p1) {
    
        java.lang.Object a = null;
        java.lang.System.out.println("TEST nodemap: " + p0);
        org.w3c.dom.NamedNodeMap m = (org.w3c.dom.NamedNodeMap) p0;

        if (m != null) {
    
            org.w3c.dom.Node n = m.getNamedItem((java.lang.String) p1);
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Read attribute.");
                a = n.getNodeValue();
        
            } else {
                
                java.lang.System.out.println("WARNING: Could not read attribute. The attribute node is null.");
            }
        
        } else {
            
            java.lang.System.out.println("WARNING: Could not read attribute. The attributes map is null.");
        }
        
        return a;
    }

    /**
     * Writes the attribute.
     *
     * @param p0 the attributes map
     * @param p1 the attribute name
     * @param p2 the attribute
     */
    static void write_attribute(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {
    }
}

