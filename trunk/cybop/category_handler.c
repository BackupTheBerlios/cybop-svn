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

/**
 * This is a category handler.
 *
 * @version $Revision: 1.2 $ $Date: 2003-09-22 06:50:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The cybol path. */
static const char[] PATH = "/home/cybop/lib/";

/** The cybol file suffix. */
static const char[] CYBOL = ".cybol";

/** The super category. */
static const char[] SUPER_CATEGORY = "super";

/** The category. */
static const char[] CATEGORY = "category";

/** The attribute. */
static const char[] ATTRIBUTE = "attribute";

/** The null value. */
static const char[] NULL_VALUE = "null";

/** The item. */
static const char[] ITEM = "item";

/** The name. */
static const char[] NAME = "name";

/** The item category. */
static const char[] ITEM_CATEGORY = "item_category";

/** The item abstraction. */
static const char[] ITEM_ABSTRACTION = "item_abstraction";

/** The position category. */
static const char[] POSITION_CATEGORY = "position_category";

/** The position abstraction. */
static const char[] POSITION_ABSTRACTION = "position_abstraction";

/** The instance category. */
static const char[] INSTANCE_CATEGORY = "instance_category";

/** The instance abstraction. */
static const char[] INSTANCE_ABSTRACTION = "instance_abstraction";

/** The interaction category. */
static const char[] INTERACTION_CATEGORY = "interaction_category";

/** The interaction abstraction. */
static const char[] INTERACTION_ABSTRACTION = "interaction_abstraction";

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
void initialize_category(int p0, int p1) {

    org.apache.xerces.parsers.DOMParser p = (org.apache.xerces.parsers.DOMParser) xml_parser;

    if (p != NULL) {
        
        log(INFO_LOG_LEVEL, "Initialize category: " + p1);
        p.parse(PATH + p1 + CYBOL);
        read_document(p0, (org.apache.xerces.dom.DocumentImpl) p.getDocument());

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize category elements. The xml parser is NULL.");
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
void finalize_category(int p0, int p1) {
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
void read_document(int p0, int p1) {

    org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

    if (doc != NULL) {
        
        log(INFO_LOG_LEVEL, "Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = NULL;

        if (p0 != NULL) {
            
            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(SUPER_CATEGORY);
            initialize_super_category(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(JAVA_OBJECT);
            initialize_java_objects(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(ITEM);
            initialize_items(((Item) p0).items, l);

        } else {
            
            log(ERROR_LOG_LEVEL, "Could not read document. The category is NULL.");
        }

    } else {
        
        log(ERROR_LOG_LEVEL, "Could not read document. The document is NULL.");
    }
}

/**
 * Writes the document.
 *
 * @param p0 the category
 * @param p1 the document
 */
void write_document(int p0, int p1) {
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
void initialize_super_category(int p0, int p1) {

    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != NULL) {

            log(INFO_LOG_LEVEL, "Initialize super category.");
            int s = read_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), CATEGORY);
            initialize_category(p0, s);
            
        } else {
            
            log(WARNING_LOG_LEVEL, "Could not initialize super category. The super category node is NULL.");
        }
        
    } else {
        
        log(WARNING_LOG_LEVEL, "Could not initialize super category. The super category list is NULL.");
    }
}

/**
 * Finalizes the super category.
 *
 * @param p0 the category
 * @param p1 the super category list
 */
void finalize_super_category(int p0, int p1) {
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
void initialize_items(int p0, int p1) {

    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL) {
        
        log(INFO_LOG_LEVEL, "Initialize items.");
        int count = 0;
        int size = l.getLength();
        org.apache.xerces.dom.NodeImpl n = NULL;
        item i = NULL;
        int name = NULL;

        while (count < size) {
        
            n = (org.apache.xerces.dom.NodeImpl) l.item(count);

            if (n != NULL) {
                    
                i = new Item();
                initialize_item_containers(i);
                initialize_item(i, n);

                if (i != NULL) {
                        
                    name = get_map_element(i.items, NAME);
                    set_map_element(p0, name, i);
                    
/*??
                    // Initialize serialized item.
                    i = n.getNodeValue();
*/
            
                } else {
                    
                    log(ERROR_LOG_LEVEL, "Could not initialize items. An item is NULL.");
                }
        
            } else {
                
                log(INFO_LOG_LEVEL, "Could not initialize items. The category item node is NULL.");
            }
                    
            count++;
        }
        
    } else {
        
        log(ERROR_LOG_LEVEL, "Could not initialize items. The category items list is NULL.");
    }
}

/**
 * Finalizes the items.
 *
 * @param p0 the category items
 * @param p1 the category items list
 */
void finalize_items(int p0, int p1) {
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
void initialize_item(int p0, int p1) {
    
    Item i = (Item) p0;
    
    if (i != NULL) {
    
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
        
        if (n != NULL) {
            
            log(INFO_LOG_LEVEL, "Initialize item.");
            initialize_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
    
        } else {
            
            log(WARNING_LOG_LEVEL, "Could not initialize item. The item node is NULL.");
        }

    } else {
        
        log(WARNING_LOG_LEVEL, "Could not initialize item. The item is NULL.");
    }
}

/**
 * Finalizes the item.
 *
 * @param p0 the item
 * @param p1 the item node
 */
void finalize_item(int p0, int p1) {
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
void initialize_attributes(int p0, int p1) {

    log(INFO_LOG_LEVEL, "Initialize attributes.");
    int a = NULL;

    a = read_attribute(p1, NAME);
    set_map_element(p0, NAME, a);

    a = read_attribute(p1, ITEM_CATEGORY);
    set_map_element(p0, ITEM_CATEGORY, a);

    a = read_attribute(p1, ITEM_ABSTRACTION);
    set_map_element(p0, ITEM_ABSTRACTION, a);

    a = read_attribute(p1, POSITION_CATEGORY);
    set_map_element(p0, POSITION_CATEGORY, a);

    a = read_attribute(p1, POSITION_ABSTRACTION);
    set_map_element(p0, POSITION_ABSTRACTION, a);

    a = read_attribute(p1, INSTANCE_CATEGORY);
    set_map_element(p0, INSTANCE_CATEGORY, a);

    a = read_attribute(p1, INSTANCE_ABSTRACTION);
    set_map_element(p0, INSTANCE_ABSTRACTION, a);

    a = read_attribute(p1, INTERACTION_CATEGORY);
    set_map_element(p0, INTERACTION_CATEGORY, a);

    a = read_attribute(p1, INTERACTION_ABSTRACTION);
    set_map_element(p0, INTERACTION_ABSTRACTION, a);
}

/**
 * Finalizes the attributes.
 *
 * @param p0 the attribute items
 * @param p1 the attributes map
 */
void finalize_attributes(int p0, int p1) {
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
int read_attribute(int p0, int p1) {

    int a = NULL;
    org.apache.xerces.dom.NamedNodeMapImpl m = (org.apache.xerces.dom.NamedNodeMapImpl) p0;

    if (m != NULL) {

        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) m.getNamedItem((char[]) p1);
        
        if (n != NULL) {
            
            log(INFO_LOG_LEVEL, "Read attribute.");
            a = n.getNodeValue();
    
        } else {
            
            log(WARNING_LOG_LEVEL, "Could not read attribute. The attribute node is NULL.");
        }
    
    } else {
        
        log(WARNING_LOG_LEVEL, "Could not read attribute. The attributes map is NULL.");
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
void write_attribute(int p0, int p1, int p2) {
}

