/*
 * $RCSfile: xml_node_creator.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2004-12-19 00:53:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_NODE_CREATOR_SOURCE
#define XML_NODE_CREATOR_SOURCE

#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the xml node.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void create_xml_node(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTEGER_MESSAGE, (void*) &CREATE_INTEGER_MESSAGE_COUNT);

    // Create xml node.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_COUNT);

    // Initialize xml node name, attributes, value.
    void* nav = NULL_POINTER;
    void* c = NULL_POINTER;

    // Create xml tag name, attributes, value.
    create_array((void*) &nav, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &c, (void*) &INTEGER_ARRAY, p1);

    //
    // Use ascending order.
    //

    // Set xml tag name, attributes, value.
//??    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX, (void*) &nav);
//??    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_COUNTS_INDEX, (void*) &c);
}

/**
 * Destroys the xml node.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void destroy_xml_node(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_INTEGER_MESSAGE, (void*) &DESTROY_INTEGER_MESSAGE_COUNT);

    // Initialize xml tag name, attributes, value.
    void* nav = NULL_POINTER;
    void* c = NULL_POINTER;

    // Get xml tag name, attributes, value.
//??    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX, (void*) &nav);
//??    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_COUNTS_INDEX, (void*) &c);

    //
    // Use descending order.
    //

    // Remove xml tag name, attributes, value.
//??    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_COUNT, (void*) &XML_TAG_COUNTS_INDEX);
//??    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_COUNT, (void*) &XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX);

    // Destroy xml tag name, attributes, value.
    destroy_array((void*) &nav, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &c, (void*) &INTEGER_ARRAY, p1);

    // Destroy xml tag.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &XML_TAG_COUNT);
}

/* XML_NODE_CREATOR_SOURCE */
#endif
