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
 * @version $Revision: 1.6 $ $Date: 2003-08-01 09:25:04 $ $Author: christian $
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
    static java.lang.String SUPER_CATEGORY = "super";

    /** The category. */
    static java.lang.String CATEGORY = "category";

    /** The java object. */
    static java.lang.String JAVA_OBJECT = "javaobject";

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

    /** The xml parser. */
    static java.lang.Object xml_parser;

    //
    // Category.
    //

    /**
     * Initializes the category.
     *
     * @param p0 the category
     * @param p1 the category name
     */
    static void initialize_category(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        java.lang.System.out.println("INFO: Initialize category.");
        
        CategoryHandler.initialize_category_containers(p0);
        CategoryHandler.initialize_category_elements(p0, p1);
    }

    /**
     * Finalizes the category.
     *
     * @param p0 the category
     * @param p1 the category name
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

            c.java_object = new CategoryJavaObject();
            CategoryJavaObjectHandler.initialize_category_java_object(c.java_object);

            c.items = new Map();
            MapHandler.initialize_map(c.items);

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

            MapHandler.finalize_map(c.items);
            c.items = null;

            CategoryJavaObjectHandler.finalize_category_java_object(c.java_object);
            c.java_object = null;

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
     * @param p1 the category name
     */
    static void initialize_category_elements(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = new org.apache.xerces.parsers.DOMParser();
        CategoryHandler.initialize_xml_parser(p);
    
        if (p != null) {
            
            java.lang.System.out.println("INFO: Initialize category elements.");

            p.parse(CategoryHandler.PATH + p1 + CategoryHandler.CYBOL);
            CategoryHandler.initialize_document(p0, p.getDocument());
    
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize category elements. The xml parser is null.");
        }
        
        CategoryHandler.finalize_xml_parser(p);
        p = null;
    }

    /**
     * Finalizes the category elements.
     *
     * Writes the file of the given category.
     *
     * @param p0 the category
     * @param p1 the category name
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

            Category c = (Category) p0;
            
            l = doc.getElementsByTagName(CategoryHandler.SUPER_CATEGORY);
            CategoryHandler.initialize_super_category(c, l);

            if (p0 != null) {
                    
                l = doc.getElementsByTagName(CategoryHandler.JAVA_OBJECT);
                CategoryHandler.initialize_java_object(c.java_object, l);
                    
                l = doc.getElementsByTagName(CategoryHandler.ITEM);
                CategoryHandler.initialize_items(c.items, l);

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

            Category c = (Category) p0;
            
            l = doc.getElementsByTagName(CategoryHandler.SUPER_CATEGORY);
            CategoryHandler.finalize_super(c, l);
                
            l = doc.getElementsByTagName(CategoryHandler.JAVA_OBJECT);
            CategoryHandler.finalize_java_object(c, l);
                
            l = doc.getElementsByTagName(CategoryHandler.ITEM);
            CategoryHandler.finalize_items(c, l);

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
    static void initialize_super_category(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {

                Category c = (Category) p0;
                
                if (c != null) {
                    
                    java.lang.System.out.println("INFO: Initialize super category.");
                    
                    java.lang.Object s = CategoryHandler.read_attribute(n.getAttributes(), CategoryHandler.CATEGORY);
                    CategoryHandler.initialize_category(p0, s);
                
                } else {
                    
                    java.lang.System.out.println("WARNING: Could not initialize super category. The category is null.");
                }
                
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
     * @param p0 the category java object
     * @param p1 the category java object list
     */
    static void initialize_java_object(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            org.w3c.dom.Node n = l.item(0);
            
            if (n != null) {
                
                java.lang.System.out.println("INFO: Initialize java object.");
                
                java.lang.Object a = n.getAttributes();
                CategoryHandler.initialize_java_object_attributes(p0, a);
                java.lang.System.out.println("---------- \n\n\nTEST wrapper: " + ((CategoryJavaObject) p0).category);
                
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
     * @param p0 the category java object
     * @param p1 the category java object list
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
     * @param p0 the category java object
     * @param p1 the category java object attributes
     */
    static void initialize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        CategoryJavaObject o = (CategoryJavaObject) p0;
        
        if (o != null) {
        
            java.lang.System.out.println("INFO: Initialize java object attributes.");
            
            o.category = read_attribute(p1, CategoryHandler.CATEGORY);
            java.lang.System.out.println("--\nTEST inner: " + o.category);
            org.w3c.dom.NamedNodeMap m = (org.w3c.dom.NamedNodeMap) p1;
    
            if (m != null) {
        
                int i = 0;
                int size = m.getLength();
                org.w3c.dom.Node n = null;
                
                while (i < size) {
                        
                    n = m.item(i);
                    
                    if (n != null) {
                        
                        MapHandler.add_map_element(o.attributes, n.getNodeValue(), "attribute");
                
                    } else {
                        
                        java.lang.System.out.println("WARNING: Could not initialize java object attributes. An attribute node is null.");
                    }
                }
            
            } else {
                
                java.lang.System.out.println("WARNING: Could not initialize java object attributes. The node map is null.");
            }
    
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java object attributes. The java object is null.");
        }
    }

    //
    // Items.
    //
    
    /**
     * Initializes the items.
     *
     * @param p0 the category items
     * @param p1 the item list
     */
    static void initialize_items(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.w3c.dom.NodeList l = (org.w3c.dom.NodeList) p1;

        if (l != null) {
            
            java.lang.System.out.println("INFO: Initialize items.");

            int count = 0;
            int size = l.getLength();
            org.w3c.dom.Node n = null;
            CategoryItem i = null;

            while (count < size) {
            
                n = l.item(count);

                if (n != null) {

                    // Initialize attributes.
                    i = new CategoryItem();
                    CategoryHandler.initialize_category_item(i, n.getAttributes());
                    
                    if (i != null) {
                    
                        MapHandler.add_map_element(p0, i, i.name);

                    } else {
                        
                        java.lang.System.out.println("ERROR: Could not initialize items. The item node is null.");
                    }

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
    // Category item.
    //
    
    /**
     * Initializes the category item.
     *
     * @param p0 the category item
     * @param p1 the item attributes
     */
    static void initialize_category_item(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        CategoryItem ci = (CategoryItem) p0;
        
        if (ci != null) {
                
            ci.name = CategoryHandler.read_attribute(p1, CategoryHandler.NAME);
            java.lang.System.out.println("INFO: Initialize category item: " + ci.name);

            ci.item_abstraction = CategoryHandler.read_attribute(p1, CategoryHandler.ITEM_ABSTRACTION);
            java.lang.System.out.println("TEST item_abstraction: " + ci.item_abstraction);
            ci.item_category = CategoryHandler.read_attribute(p1, CategoryHandler.ITEM_CATEGORY);
            java.lang.System.out.println("TEST item_category: " + ci.item_category);
            ci.position_abstraction = CategoryHandler.read_attribute(p1, CategoryHandler.POSITION_ABSTRACTION);
            ci.position_category = CategoryHandler.read_attribute(p1, CategoryHandler.POSITION_CATEGORY);
            ci.instance_abstraction = CategoryHandler.read_attribute(p1, CategoryHandler.INSTANCE_ABSTRACTION);
            ci.instance_category = CategoryHandler.read_attribute(p1, CategoryHandler.INSTANCE_CATEGORY);
            ci.interaction_abstraction = CategoryHandler.read_attribute(p1, CategoryHandler.INTERACTION_ABSTRACTION);
            ci.interaction_category = CategoryHandler.read_attribute(p1, CategoryHandler.INTERACTION_CATEGORY);

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize category item. The category item is null.");
        }
    }

    //
    // Attribute.
    //
    
    /**
     * Reads the attribute.
     *
     * @param p0 the attributes
     * @param p1 the name
     * @return the attribute
     */
    static java.lang.Object read_attribute(java.lang.Object p0, java.lang.Object p1) {
    
        java.lang.Object a = null;
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
            
            java.lang.System.out.println("WARNING: Could not read attribute. The node map is null.");
        }
        
        return a;
    }
}

