/*
 * $RCSfile: statics_cybol_model_handler.c,v $
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
 * This file handles a statics cybol file.
 *
 * It contains read and write procedures.
 *
 * @version $Revision: 1.11 $ $Date: 2004-04-21 11:10:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATICS_CYBOL_MODEL_HANDLER_SOURCE
#define STATICS_CYBOL_MODEL_HANDLER_SOURCE

//?? #include <libxml.h>

//
// Statics cybol attribute.
//

/**
 * Reads the statics cybol attribute.
 *
 * @param p0 the statics cybol attributes
 * @param p1 the statics cybol attribute name
 * @param p2 the statics cybol source attribute
 */
void read_statics_cybol_attribute(void* p0, void* p1, void* p2) {

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
}

/**
 * Writes the statics cybol attribute.
 *
 * @param p0 the statics cybol attributes
 * @param p1 the statics cybol attribute name
 * @param p2 the statics cybol source attribute
 */
void write_statics_cybol_attribute(void* p0, void* p1, void* p2) {
}

//
// Statics cybol attributes.
//

/**
 * Reads the statics cybol attributes.
 *
 * @param p0 the statics cybol attributes
 * @param p1 the statics cybol source attributes
 */
void read_statics_cybol_attributes(void* p0, void* p1) {

/*??
    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read statics cybol attributes.");
    int a = 0;

    a = read_statics_cybol_attribute(p1, NAME);
    set_map_element_with_name(p0, NAME, a);

    a = read_statics_cybol_attribute(p1, PART_MODEL);
    set_map_element_with_name(p0, PART_MODEL, a);

    a = read_statics_cybol_attribute(p1, PART_ABSTRACTION);
    set_map_element_with_name(p0, PART_ABSTRACTION, a);

    a = read_statics_cybol_attribute(p1, POSITION_MODEL);
    set_map_element_with_name(p0, POSITION_MODEL, a);

    a = read_statics_cybol_attribute(p1, POSITION_ABSTRACTION);
    set_map_element_with_name(p0, POSITION_ABSTRACTION, a);
*/
}

/**
 * Writes the statics cybol attributes.
 *
 * @param p0 the statics cybol attributes
 * @param p1 the statics cybol source attributes
 */
void write_statics_cybol_attributes(void* p0, void* p1) {
}

//
// Statics cybol part model.
//

/**
 * Reads the statics cybol part model.
 *
 * @param p0 the statics cybol part model
 * @param p1 the statics cybol part source model
 */
void read_statics_cybol_part_model(void* p0, void* p1) {
    
/*??
    Item i = (Item) p0;
    
    if (i != NULL_POINTER) {
    
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
        
        if (n != NULL_POINTER) {
            
            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read statics cybol part model.");
            read_statics_cybol_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
    
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize child model. The child model node is null.");
        }

    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize child model. The child model is null.");
    }
*/
}

/**
 * Writes the statics cybol part model.
 *
 * @param p0 the statics cybol part model
 * @param p1 the statics cybol part source model
 */
void write_statics_cybol_part_model(void* p0, void* p1) {
}

//
// Statics cybol super models.
//

/**
 * Reads the statics cybol super models.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol super source models
 */
void read_statics_cybol_super_models(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != NULL_POINTER) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != NULL_POINTER) {

            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize cybol super models.");
            int s = read_statics_cybol_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), MODEL);
            initialize_statics_cybol_model(p0, s);
            
        } else {
            
            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize super model. The super model node is null.");
        }
        
    } else {
        
        log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize super model. The super model list is null.");
    }
*/
}

/**
 * Writes the statics cybol super models.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol super models
 */
void write_statics_cybol_super_models(void* p0, void* p1) {
}

//
// Statics cybol part models.
//

/**
 * Reads the statics cybol part models.
 *
 * @param p0 the statics cybol part models
 * @param p1 the statics cybol part source models
 */
void read_statics_cybol_part_models(void* p0, void* p1) {

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
}

/**
 * Writes the statics cybol part models.
 *
 * @param p0 the statics cybol part models
 * @param p1 the statics cybol part source models
 */
void write_statics_cybol_part_models(void* p0, void* p1) {
}

//
// Statics cybol source.
//

/**
 * Reads the statics cybol source.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol source
 */
void read_statics_cybol_source(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

    if (doc != NULL_POINTER) {
        
        log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = NULL_POINTER;

        if (p0 != NULL_POINTER) {
            
            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(SUPER_CATEGORY);
            initialize_statics_cybol_super_models(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(ITEM);
            initialize_statics_cybol_part_models(((Item) p0).items, l);

        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read structure. The model is null.");
        }

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read structure. The structure is null.");
    }
*/
}

/**
 * Writes the statics cybol source.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol source
 */
void write_statics_cybol_source(void* p0, void* p1) {
}

//
// Statics cybol model.
//

/**
 * Initializes the statics cybol model.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol model name
 */
void initialize_statics_cybol_model(void* p0, void* p1) {

/*??
    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize statics cybol model: " + p1);

    void* s = parse_file(PATH + p1 + CYBOL);
    read_statics_cybol_source(p0, s);
*/
}

/**
 * Finalizes the statics cybol model.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol model name
 */
void finalize_statics_cybol_model(void* p0, void* p1) {
}

/* STATICS_CYBOL_MODEL_HANDLER_SOURCE */
#endif
