/*
 * $RCSfile: xml_node_creator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.5 $ $Date: 2005-01-17 23:46:29 $ $Author: christian $
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
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void create_xml_node(void* p0, const void* p1) {

    log_message_debug("Create xml node.");

    // Create xml node.
    create_array(p0, (void*) XML_TAG_COUNT, (void*) POINTER_ARRAY);

    // Initialize xml node name, attributes, value.
    void* nav = NULL_POINTER;
    void* c = NULL_POINTER;

    // Create xml tag name, attributes, value.
    create_array((void*) &nav, p1, (void*) POINTER_ARRAY);
    create_array((void*) &c, p1, (void*) INTEGER_ARRAY);

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
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void destroy_xml_node(void* p0, const void* p1) {

    log_message_debug("Destroy xml node.");

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
    destroy_array((void*) &nav, p1, (void*) POINTER_ARRAY);
    destroy_array((void*) &c, p1, (void*) INTEGER_ARRAY);

    // Destroy xml tag.
    destroy_array(p0, (void*) XML_TAG_COUNT, (void*) POINTER_ARRAY);
}

/* XML_NODE_CREATOR_SOURCE */
#endif
