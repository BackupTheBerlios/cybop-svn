/*
 * $RCSfile: dynamics_cybol_model_handler.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 *
 * This file handles a dynamics cybol file.
 *
 * It contains read and write procedures.
 *
 * @version $Revision: 1.9 $ $Date: 2004-04-21 11:06:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DYNAMICS_CYBOL_MODEL_HANDLER_SOURCE
#define DYNAMICS_CYBOL_MODEL_HANDLER_SOURCE

//?? #include <libxml.h>


//
// Source model.
//

/**
 * Initializes the source model.
 *
 * Reads the file of the given model.
 *
 * @param p0 the model
 * @param p1 the model name
 */
//?? void initialize_source_model(void* p0, void* p1) {

/*??
    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize model: " + p1);

    void* s = parse_file(PATH + p1 + CYBOL);
    read_structure(p0, s);
*/
//?? }

/**
 * Finalizes the source model.
 *
 * Writes the file of the given model.
 *
 * @param p0 the model
 * @param p1 the model name
 */
//?? void finalize_source_model(void* p0, void* p1) {
//?? }

//
// Model.
//

/**
 * Reads the structure.
 *
 * @param p0 the model
 * @param p1 the structure
 */
//?? void read_structure(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

    if (doc != NULL_POINTER) {
        
        log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = NULL_POINTER;

        if (p0 != NULL_POINTER) {
            
            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(SUPER_CATEGORY);
            initialize_super_category(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(JAVA_OBJECT);
            initialize_java_objects(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(ITEM);
            initialize_items(((Item) p0).items, l);

        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read structure. The model is null.");
        }

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read structure. The structure is null.");
    }
*/
//?? }

/**
 * Writes the structure.
 *
 * @param p0 the model
 * @param p1 the structure
 */
/*??
void write_structure(void* p0, void* p1) {
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
/*??
void initialize_super_model(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL_POINTER) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != NULL_POINTER) {

            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize super model.");
            int s = read_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), CATEGORY);
            initialize_category(p0, s);
            
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize super model. The super model node is null.");
        }
        
    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize super model. The super model list is null.");
    }
*/
/*??
}

/**
 * Finalizes the super model.
 *
 * @param p0 the model
 * @param p1 the super model list
 */
/*??
void finalize_super_model(void* p0, void* p1) {
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
/*??
void initialize_children_models(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL_POINTER) {
        
        log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize children models.");
        int count = 0;
        int size = l.getLength();
        org.apache.xerces.dom.NodeImpl n = NULL_POINTER;
        item i = NULL_POINTER;
        int name = 0;

        while (count < size) {
        
            n = (org.apache.xerces.dom.NodeImpl) l.item(count);

            if (n != NULL_POINTER) {
                    
                i = new Item();
                initialize_item_containers(i);
                initialize_item(i, n);

                if (i != NULL_POINTER) {
                        
                    name = get_map_element(i.items, NAME);
                    set_map_element(p0, name, i);
                    
/*??
                    // Initialize serialized item.
                    i = n.getNodeValue();
*/

/*??
                } else {
                    
                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize children models. A model is null.");
                }
        
            } else {
                
                log_message((void*) &INFO_LOG_LEVEL, (void*) &"Could not initialize children models. The model item node is null.");
            }
                    
            count++;
        }
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize children models. The model items list is null.");
    }
*/
/*??
}

/**
 * Finalizes the children models.
 *
 * @param p0 the children models
 * @param p1 the children models list
 */
/*??
void finalize_items(void* p0, void* p1) {
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
/*??
void initialize_child_model(void* p0, void* p1) {
    
/*??
    Item i = (Item) p0;
    
    if (i != NULL_POINTER) {
    
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
        
        if (n != NULL_POINTER) {
            
            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize child model.");
            initialize_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
    
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize child model. The child model node is null.");
        }

    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize child model. The child model is null.");
    }
*/
/*??
}

/**
 * Finalizes the child model.
 *
 * @param p0 the child model
 * @param p1 the child model node
 */
/*??
void finalize_child_model(void* p0, void* p1) {
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
/*??
void initialize_child_attributes(void* p0, void* p1) {

/*??
    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize child attributes.");
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
/*??
}

/**
 * Finalizes the child attributes.
 *
 * @param p0 the child attribute items
 * @param p1 the child attributes map
 */
/*??
void finalize_child_attributes(void* p0, void* p1) {
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
/*??
void read_child_attribute(void* p0, void* p1, void* p2) {

/*??
    org.apache.xerces.dom.NamedNodeMapImpl m = (org.apache.xerces.dom.NamedNodeMapImpl) p0;

    if (m != NULL_POINTER) {

        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) m.getNamedItem((char[]) p1);
        
        if (n != NULL_POINTER) {
            
            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read child attribute.");
            p2 = n.getNodeValue();
    
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not read child attribute. The child attribute node is null.");
        }
    
    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not read child attribute. The child attributes map is null.");
    }
*/
/*??
}

/**
 * Writes the child attribute.
 *
 * @param p0 the child attributes map
 * @param p1 the child attribute name
 * @param p2 the child attribute
 */
/*??
void write_child_attribute(void* p0, void* p1, void* p2) {
}

/* DYNAMICS_CYBOL_MODEL_HANDLER_SOURCE */
#endif
