/*
 * $RCSfile: xml_handler.c,v $
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

//?? #include <libxml.h>

/**
 * This is a category handler.
 *
 * @version $Revision: 1.10 $ $Date: 2003-10-13 13:55:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The cybol path. */
static const void* CYBOL_PATH = "/home/cybop/lib/";

/** The cybol file suffix. */
static const void* FILE_SUFFIX = ".cybol";

/** The super model. */
static const void* SUPER_MODEL = "super";

/** The null model. */
static const void* NULL_MODEL = "null";

/** The child. */
static const void* CHILD = "child";

/** The name. */
static const void* NAME = "name";

/** The child model. */
static const void* CHILD_MODEL = "child_model";

/** The child abstraction. */
static const void* CHILD_ABSTRACTION = "child_abstraction";

/** The position model. */
static const void* POSITION_MODEL = "position_model";

/** The position abstraction. */
static const void* POSITION_ABSTRACTION = "position_abstraction";

/** The instance model. */
static const void* INSTANCE_MODEL = "instance_model";

/** The instance abstraction. */
static const void* INSTANCE_ABSTRACTION = "instance_abstraction";

/** The interaction model. */
static const void* INTERACTION_MODEL = "interaction_model";

/** The interaction abstraction. */
static const void* INTERACTION_ABSTRACTION = "interaction_abstraction";

//
// Model.
//

/**
 * Initializes the model.
 *
 * Reads the file of the given model.
 *
 * @param p0 the model
 * @param p1 the model name
 */
static void initialize_model(void* p0, void* p1) {

/*??
    log((void*) &INFO_LOG_LEVEL, "Initialize model: " + p1);

    void* s = parse_file(PATH + p1 + CYBOL);
    read_structure(p0, s);
*/
}

/**
 * Finalizes the model.
 *
 * Writes the file of the given model.
 *
 * @param p0 the model
 * @param p1 the model name
 */
static void finalize_model(void* p0, void* p1) {
}

//
// Model.
//

/**
 * Reads the structure.
 *
 * @param p0 the model
 * @param p1 the structure
 */
static void read_structure(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

    if (doc != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = 0;

        if (p0 != 0) {
            
            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(SUPER_CATEGORY);
            initialize_super_category(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(JAVA_OBJECT);
            initialize_java_objects(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(ITEM);
            initialize_items(((Item) p0).items, l);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not read structure. The model is null.");
        }

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not read structure. The structure is null.");
    }
*/
}

/**
 * Writes the structure.
 *
 * @param p0 the model
 * @param p1 the structure
 */
static void write_structure(void* p0, void* p1) {
}

//
// Super model.
//

/**
 * Initializes the super model.
 *
 * @param p0 the model
 * @param p1 the super model list
 */
static void initialize_super_model(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != 0) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != 0) {

            log((void*) &INFO_LOG_LEVEL, "Initialize super model.");
            int s = read_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), CATEGORY);
            initialize_category(p0, s);
            
        } else {
            
            log((void*) &WARNING_LOG_LEVEL, "Could not initialize super model. The super model node is null.");
        }
        
    } else {
        
        log((void*) &WARNING_LOG_LEVEL, "Could not initialize super model. The super model list is null.");
    }
*/
}

/**
 * Finalizes the super model.
 *
 * @param p0 the model
 * @param p1 the super model list
 */
static void finalize_super_model(void* p0, void* p1) {
}

//
// Children.
//

/**
 * Initializes the children.
 *
 * @param p0 the model children
 * @param p1 the model children list
 */
static void initialize_children_models(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize children models.");
        int count = 0;
        int size = l.getLength();
        org.apache.xerces.dom.NodeImpl n = 0;
        item i = 0;
        int name = 0;

        while (count < size) {
        
            n = (org.apache.xerces.dom.NodeImpl) l.item(count);

            if (n != 0) {
                    
                i = new Item();
                initialize_item_containers(i);
                initialize_item(i, n);

                if (i != 0) {
                        
                    name = get_map_element(i.items, NAME);
                    set_map_element(p0, name, i);
                    
/*??
                    // Initialize serialized item.
                    i = n.getNodeValue();
*/

/*??
                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not initialize children models. A model is null.");
                }
        
            } else {
                
                log((void*) &INFO_LOG_LEVEL, "Could not initialize children models. The model item node is null.");
            }
                    
            count++;
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize children models. The model items list is null.");
    }
*/
}

/**
 * Finalizes the children models.
 *
 * @param p0 the children models
 * @param p1 the children models list
 */
static void finalize_items(void* p0, void* p1) {
}

//
// Child model.
//

/**
 * Initializes the child model.
 *
 * @param p0 the child model
 * @param p1 the child model node
 */
static void initialize_child_model(void* p0, void* p1) {
    
/*??
    Item i = (Item) p0;
    
    if (i != 0) {
    
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
        
        if (n != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Initialize child model.");
            initialize_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
    
        } else {
            
            log((void*) &WARNING_LOG_LEVEL, "Could not initialize child model. The child model node is null.");
        }

    } else {
        
        log((void*) &WARNING_LOG_LEVEL, "Could not initialize child model. The child model is null.");
    }
*/
}

/**
 * Finalizes the child model.
 *
 * @param p0 the child model
 * @param p1 the child model node
 */
static void finalize_child_model(void* p0, void* p1) {
}

//
// Attributes.
//

/**
 * Initializes the child attributes.
 *
 * @param p0 the child attribute items
 * @param p1 the child attributes map
 */
static void initialize_child_attributes(void* p0, void* p1) {

/*??
    log((void*) &INFO_LOG_LEVEL, "Initialize child attributes.");
    int a = 0;

    a = read_child_attribute(p1, NAME);
    set_map_element(p0, NAME, a);

    a = read_child_attribute(p1, ITEM_CATEGORY);
    set_map_element(p0, ITEM_CATEGORY, a);

    a = read_child_attribute(p1, ITEM_ABSTRACTION);
    set_map_element(p0, ITEM_ABSTRACTION, a);

    a = read_child_attribute(p1, POSITION_CATEGORY);
    set_map_element(p0, POSITION_CATEGORY, a);

    a = read_child_attribute(p1, POSITION_ABSTRACTION);
    set_map_element(p0, POSITION_ABSTRACTION, a);

    a = read_child_attribute(p1, INSTANCE_CATEGORY);
    set_map_element(p0, INSTANCE_CATEGORY, a);

    a = read_child_attribute(p1, INSTANCE_ABSTRACTION);
    set_map_element(p0, INSTANCE_ABSTRACTION, a);

    a = read_child_attribute(p1, INTERACTION_CATEGORY);
    set_map_element(p0, INTERACTION_CATEGORY, a);

    a = read_child_attribute(p1, INTERACTION_ABSTRACTION);
    set_map_element(p0, INTERACTION_ABSTRACTION, a);
*/
}

/**
 * Finalizes the child attributes.
 *
 * @param p0 the child attribute items
 * @param p1 the child attributes map
 */
static void finalize_child_attributes(void* p0, void* p1) {
}

//
// Attribute.
//

/**
 * Reads the child attribute.
 *
 * @param p0 the child attributes map
 * @param p1 the child attribute name
 * @param p2 the child attribute
 */
static void read_child_attribute(void* p0, void* p1, void* p2) {

/*??
    org.apache.xerces.dom.NamedNodeMapImpl m = (org.apache.xerces.dom.NamedNodeMapImpl) p0;

    if (m != 0) {

        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) m.getNamedItem((char[]) p1);
        
        if (n != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Read child attribute.");
            p2 = n.getNodeValue();
    
        } else {
            
            log((void*) &WARNING_LOG_LEVEL, "Could not read child attribute. The child attribute node is null.");
        }
    
    } else {
        
        log((void*) &WARNING_LOG_LEVEL, "Could not read child attribute. The child attributes map is null.");
    }
*/
}

/**
 * Writes the child attribute.
 *
 * @param p0 the child attributes map
 * @param p1 the child attribute name
 * @param p2 the child attribute
 */
static void write_child_attribute(void* p0, void* p1, void* p2) {
}

