/*
 * $RCSfile: category_handler.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2003-09-17 18:45:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class CategoryHandler {

    //
    // Constants.
    //
    
    /** The cybol path. */
    java.lang.String PATH = "/home/cybop/lib/";

    /** The cybol file suffix. */
    java.lang.String CYBOL = ".cybol";

    /** The super category. */
    java.lang.String SUPER_CATEGORY = "super";

    /** The java object. */
    java.lang.String JAVA_OBJECT = "javaobject";

    /** The category. */
    java.lang.String CATEGORY = "category";

    /** The attribute. */
    java.lang.String ATTRIBUTE = "attribute";

    /** The null. */
    java.lang.String NULL = "null";

    /** The item. */
    java.lang.String ITEM = "item";

    /** The name. */
    java.lang.String NAME = "name";

    /** The item category. */
    java.lang.String ITEM_CATEGORY = "item_category";

    /** The item abstraction. */
    java.lang.String ITEM_ABSTRACTION = "item_abstraction";

    /** The position category. */
    java.lang.String POSITION_CATEGORY = "position_category";

    /** The position abstraction. */
    java.lang.String POSITION_ABSTRACTION = "position_abstraction";

    /** The instance category. */
    java.lang.String INSTANCE_CATEGORY = "instance_category";

    /** The instance abstraction. */
    java.lang.String INSTANCE_ABSTRACTION = "instance_abstraction";

    /** The interaction category. */
    java.lang.String INTERACTION_CATEGORY = "interaction_category";

    /** The interaction abstraction. */
    java.lang.String INTERACTION_ABSTRACTION = "interaction_abstraction";

    //
    // Attributes.
    //

    /** The xml parser. */    
    java.lang.Object xml_parser;
    
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
    void initialize_category(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) CategoryHandler.xml_parser;
    
        if (p != null) {
            
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize category: " + p1);
            p.parse(CategoryHandler.PATH + p1 + CategoryHandler.CYBOL);
            CategoryHandler.read_document(p0, (org.apache.xerces.dom.DocumentImpl) p.getDocument());
    
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize category elements. The xml parser is null.");
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
    void finalize_category(java.lang.Object p0, java.lang.Object p1) {
    }

    //
    // XML Parser.
    //

    /**
     * Initializes the xml parser.
     *
     * @param p0 the xml parser
     */
    void initialize_xml_parser(java.lang.Object p0) throws java.lang.Exception {

        org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) p0;

        if (p != null) {
            
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize xml parser.");
            p.setFeature("http://xml.org/sax/features/validation", true);
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize xml parser. The xml parser is null.");
        }
    }

    /**
     * Finalizes the xml parser.
     *
     * @param p0 the xml parser
     */
    void finalize_xml_parser(java.lang.Object p0) {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Finalize xml parser.");
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
    void read_document(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

        if (doc != null) {
            
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Read document.");
            doc.normalize();
            org.apache.xerces.dom.DeepNodeListImpl l = null;

            if (p0 != null) {
                
                l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(CategoryHandler.SUPER_CATEGORY);
                CategoryHandler.initialize_super_category(p0, l);
    
                l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(CategoryHandler.JAVA_OBJECT);
                CategoryHandler.initialize_java_objects(p0, l);

                l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(CategoryHandler.ITEM);
                CategoryHandler.initialize_items(((Item) p0).items, l);

            } else {
                
                LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not read document. The category is null.");
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not read document. The document is null.");
        }
    }

    /**
     * Writes the document.
     *
     * @param p0 the category
     * @param p1 the document
     */
    void write_document(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
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
    void initialize_super_category(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

        if (l != null) {
            
            org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
            
            if (n != null) {

                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize super category.");
                java.lang.Object s = CategoryHandler.read_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), CategoryHandler.CATEGORY);
                CategoryHandler.initialize_category(p0, s);
                
            } else {
                
                LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize super category. The super category node is null.");
            }
            
        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize super category. The super category list is null.");
        }
    }

    /**
     * Finalizes the super category.
     *
     * @param p0 the category
     * @param p1 the super category list
     */
    void finalize_super_category(java.lang.Object p0, java.lang.Object p1) {
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
    void initialize_java_objects(java.lang.Object p0, java.lang.Object p1) {

        org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

        if (l != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize java objects.");
            org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);

            if (n != null) {
                    
                Item c = (Item) p0;
                
                if (c != null) {

                    Item o = null;

                    // Sometimes, a super category sets a java object that is not
                    // wanted in a sub category. In this case, it can be set to null:
                    // <javaobject category="null"/>
                    if (CategoryHandler.is_java_object_null(n) == false) {
                            
                        o = new Item();
                        ItemHandler.initialize_item_containers(o);
                        CategoryHandler.initialize_java_object(o, n);
                        
                    } else {
                        
                        o = null;
                    }
            
                    c.java_object = o;

                } else {
                    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize java objects. The category is null.");
                }
            
            } else {
                
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Could not initialize java objects. The java object node is null.");
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize java objects. The java objects list is null.");
        }
    }

    /**
     * Finalizes the java objects.
     *
     * @param p0 the category items
     * @param p1 the category java objects list
     */
    void finalize_java_objects(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
    }

    /**
     * Checks if java object is null.
     *
     * @param p0 the category items
     * @return true if the java object is null; false otherwise
     */
    boolean is_java_object_null(java.lang.Object p0) {

        boolean b = false;
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p0;

        if (n != null) {
            
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Check if java object is null.");
            org.apache.xerces.dom.NamedNodeMapImpl m = (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes();
            java.lang.String a = (java.lang.String) CategoryHandler.read_attribute(m, CategoryHandler.CATEGORY);
        
            if (a.equals(CategoryHandler.NULL)) {
                
                b = true;
            }

        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize java object. The java object node is null.");
        }
        
        return b;
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
    void initialize_java_object(java.lang.Object p0, java.lang.Object p1) {
        
        Item o = (Item) p0;
        
        if (o != null) {
        
            org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
            
            if (n != null) {
                
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize java object.");
                CategoryHandler.initialize_java_object_attributes(o.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
        
            } else {
                
                LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize java object. The java object node is null.");
            }

        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize java object. The java object is null.");
        }
    }
    
    /**
     * Finalizes the java object.
     *
     * @param p0 the java object
     * @param p1 the java object node
     */
    void finalize_java_object(java.lang.Object p0, java.lang.Object p1) {
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
    void initialize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize java object attributes.");
        java.lang.Object a = null;

        a = CategoryHandler.read_attribute(p1, CategoryHandler.CATEGORY);
        MapHandler.set_map_element(p0, CategoryHandler.CATEGORY, a);

        a = CategoryHandler.read_attribute(p1, JavaObjectHandler.NAME);
        MapHandler.set_map_element(p0, JavaObjectHandler.NAME, a);

        a = CategoryHandler.read_attribute(p1, JavaObjectHandler.WIDTH);
        MapHandler.set_map_element(p0, JavaObjectHandler.WIDTH, a);

        a = CategoryHandler.read_attribute(p1, JavaObjectHandler.HEIGHT);
        MapHandler.set_map_element(p0, JavaObjectHandler.HEIGHT, a);

        a = CategoryHandler.read_attribute(p1, JavaObjectHandler.KEY_BINDING);
        MapHandler.set_map_element(p0, JavaObjectHandler.KEY_BINDING, a);
    }

    /**
     * Finalizes the java object attributes.
     *
     * @param p0 the attribute items
     * @param p1 the attributes map
     */
    void finalize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) {
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
    void initialize_items(java.lang.Object p0, java.lang.Object p1) {

        org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

        if (l != null) {
            
            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize items.");
            int count = 0;
            int size = l.getLength();
            org.apache.xerces.dom.NodeImpl n = null;
            Item i = null;
            java.lang.Object name = null;

            while (count < size) {
            
                n = (org.apache.xerces.dom.NodeImpl) l.item(count);

                if (n != null) {
                        
                    i = new Item();
                    ItemHandler.initialize_item_containers(i);
                    CategoryHandler.initialize_item(i, n);

                    if (i != null) {
                            
                        name = MapHandler.get_map_element(i.items, CategoryHandler.NAME);
                        MapHandler.set_map_element(p0, name, i);
                        
/*??
                        // Initialize serialized item.
                        i = n.getNodeValue();
*/
                
                    } else {
                        
                        LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize items. An item is null.");
                    }
            
                } else {
                    
                    LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Could not initialize items. The category item node is null.");
                }
                        
                count++;
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize items. The category items list is null.");
        }
    }

    /**
     * Finalizes the items.
     *
     * @param p0 the category items
     * @param p1 the category items list
     */
    void finalize_items(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
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
    void initialize_item(java.lang.Object p0, java.lang.Object p1) {
        
        Item i = (Item) p0;
        
        if (i != null) {
        
            org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
            
            if (n != null) {
                
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize item.");
                CategoryHandler.initialize_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
        
            } else {
                
                LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize item. The item node is null.");
            }

        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not initialize item. The item is null.");
        }
    }
    
    /**
     * Finalizes the item.
     *
     * @param p0 the item
     * @param p1 the item node
     */
    void finalize_item(java.lang.Object p0, java.lang.Object p1) {
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
    void initialize_attributes(java.lang.Object p0, java.lang.Object p1) {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize attributes.");
        java.lang.Object a = null;

        a = CategoryHandler.read_attribute(p1, CategoryHandler.NAME);
        MapHandler.set_map_element(p0, CategoryHandler.NAME, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.ITEM_CATEGORY);
        MapHandler.set_map_element(p0, CategoryHandler.ITEM_CATEGORY, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.ITEM_ABSTRACTION);
        MapHandler.set_map_element(p0, CategoryHandler.ITEM_ABSTRACTION, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.POSITION_CATEGORY);
        MapHandler.set_map_element(p0, CategoryHandler.POSITION_CATEGORY, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.POSITION_ABSTRACTION);
        MapHandler.set_map_element(p0, CategoryHandler.POSITION_ABSTRACTION, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INSTANCE_CATEGORY);
        MapHandler.set_map_element(p0, CategoryHandler.INSTANCE_CATEGORY, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INSTANCE_ABSTRACTION);
        MapHandler.set_map_element(p0, CategoryHandler.INSTANCE_ABSTRACTION, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INTERACTION_CATEGORY);
        MapHandler.set_map_element(p0, CategoryHandler.INTERACTION_CATEGORY, a);

        a = CategoryHandler.read_attribute(p1, CategoryHandler.INTERACTION_ABSTRACTION);
        MapHandler.set_map_element(p0, CategoryHandler.INTERACTION_ABSTRACTION, a);
    }

    /**
     * Finalizes the attributes.
     *
     * @param p0 the attribute items
     * @param p1 the attributes map
     */
    void finalize_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {
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
    java.lang.Object read_attribute(java.lang.Object p0, java.lang.Object p1) {
    
        java.lang.Object a = null;
        org.apache.xerces.dom.NamedNodeMapImpl m = (org.apache.xerces.dom.NamedNodeMapImpl) p0;

        if (m != null) {
    
            org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) m.getNamedItem((java.lang.String) p1);
            
            if (n != null) {
                
                LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Read attribute.");
                a = n.getNodeValue();
        
            } else {
                
                LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not read attribute. The attribute node is null.");
            }
        
        } else {
            
            LogHandler.log(LogHandler.WARNING_LOG_LEVEL, "Could not read attribute. The attributes map is null.");
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
    void write_attribute(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {
    }
}

