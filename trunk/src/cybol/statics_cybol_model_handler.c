/*
 * $RCSfile: statics_cybol_model_handler.c,v $
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

#ifndef STATICS_CYBOL_MODEL_HANDLER_SOURCE
#define STATICS_CYBOL_MODEL_HANDLER_SOURCE

//?? #include <libxml.h>

/**
 * This is the statics cybol model handler.
 *
 * It can read and write CYBOL source files.
 * CYBOL's syntax is based on the Extensible Markup Language (XML).
 *
 * @version $Revision: 1.3 $ $Date: 2003-12-09 15:49:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

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
static void read_statics_cybol_attribute(void* p0, void* p1, void* p2) {

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
 * Writes the statics cybol attribute.
 *
 * @param p0 the statics cybol attributes
 * @param p1 the statics cybol attribute name
 * @param p2 the statics cybol source attribute
 */
static void write_statics_cybol_attribute(void* p0, void* p1, void* p2) {
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
static void read_statics_cybol_attributes(void* p0, void* p1) {

/*??
    log((void*) &INFO_LOG_LEVEL, "Read statics cybol attributes.");
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
static void write_statics_cybol_attributes(void* p0, void* p1) {
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
static void read_statics_cybol_part_model(void* p0, void* p1) {
    
/*??
    Item i = (Item) p0;
    
    if (i != 0) {
    
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) p1;
        
        if (n != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Read statics cybol part model.");
            read_statics_cybol_attributes(i.items, (org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes());
    
        } else {
            
            log((void*) &WARNING_LOG_LEVEL, "Could not initialize child model. The child model node is null.");
        }

    } else {
        
        log((void*) &WARNING_LOG_LEVEL, "Could not initialize child model. The child model is null.");
    }
*/
}

/**
 * Writes the statics cybol part model.
 *
 * @param p0 the statics cybol part model
 * @param p1 the statics cybol part source model
 */
static void write_statics_cybol_part_model(void* p0, void* p1) {
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
static void read_statics_cybol_super_models(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DeepNodeListImpl l = (org.apache.xerces.dom.DeepNodeListImpl) p1;

    if (l != 0) {
        
        org.apache.xerces.dom.NodeImpl n = (org.apache.xerces.dom.NodeImpl) l.item(0);
        
        if (n != 0) {

            log((void*) &INFO_LOG_LEVEL, "Initialize cybol super models.");
            int s = read_statics_cybol_attribute((org.apache.xerces.dom.NamedNodeMapImpl) n.getAttributes(), MODEL);
            initialize_statics_cybol_model(p0, s);
            
        } else {
            
            log((void*) &WARNING_LOG_LEVEL, "Could not initialize super model. The super model node is null.");
        }
        
    } else {
        
        log((void*) &WARNING_LOG_LEVEL, "Could not initialize super model. The super model list is null.");
    }
*/
}

/**
 * Writes the statics cybol super models.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol super models
 */
static void write_statics_cybol_super_models(void* p0, void* p1) {
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
static void read_statics_cybol_part_models(void* p0, void* p1) {

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
 * Writes the statics cybol part models.
 *
 * @param p0 the statics cybol part models
 * @param p1 the statics cybol part source models
 */
static void write_statics_cybol_part_models(void* p0, void* p1) {
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
static void read_statics_cybol_source(void* p0, void* p1) {

/*??
    org.apache.xerces.dom.DocumentImpl doc = (org.apache.xerces.dom.DocumentImpl) p1;

    if (doc != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Read document.");
        doc.normalize();
        org.apache.xerces.dom.DeepNodeListImpl l = 0;

        if (p0 != 0) {
            
            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(SUPER_CATEGORY);
            initialize_statics_cybol_super_models(p0, l);

            l = (org.apache.xerces.dom.DeepNodeListImpl) doc.getElementsByTagName(ITEM);
            initialize_statics_cybol_part_models(((Item) p0).items, l);

        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not read structure. The model is null.");
        }

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not read structure. The structure is null.");
    }
*/
}

/**
 * Writes the statics cybol source.
 *
 * @param p0 the statics cybol model
 * @param p1 the statics cybol source
 */
static void write_statics_cybol_source(void* p0, void* p1) {
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
static void initialize_statics_cybol_model(void* p0, void* p1) {

/*??
    log((void*) &INFO_LOG_LEVEL, "Initialize statics cybol model: " + p1);

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
static void finalize_statics_cybol_model(void* p0, void* p1) {
}

/* STATICS_CYBOL_MODEL_HANDLER_SOURCE */
#endif

