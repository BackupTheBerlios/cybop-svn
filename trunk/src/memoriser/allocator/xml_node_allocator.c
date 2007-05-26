/*
 * $RCSfile: xml_node_allocator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.10 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_NODE_ALLOCATOR_SOURCE
#define XML_NODE_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the xml node.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_xml_node(void* p0, void* p1) {

    log_message_debug("Allocate xml node.");

    // Create xml node.
    allocate_array(p0, p1, (void*) POINTER_ARRAY);

    // Initialise xml node name, attributes, value.
    void* nav = *NULL_POINTER;
    void* c = *NULL_POINTER;

    // Create xml tag name, attributes, value.
    allocate_array((void*) &nav, p1, (void*) POINTER_ARRAY);
    allocate_array((void*) &c, p1, (void*) INTEGER_ARRAY);

    //
    // Use ascending order.
    //

    // Set xml tag name, attributes, value.
//??    set_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX, (void*) &nav);
//??    set_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_TAG_COUNTS_INDEX, (void*) &c);
}

/**
 * Deallocates the xml node.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void deallocate_xml_node(void* p0, void* p1) {

    log_message_debug("Deallocate xml node.");

    // Initialise xml tag name, attributes, value.
    void* nav = *NULL_POINTER;
    void* c = *NULL_POINTER;

    // Get xml tag name, attributes, value.
//??    get_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX, (void*) &nav);
//??    get_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_TAG_COUNTS_INDEX, (void*) &c);

    //
    // Use descending order.
    //

    // Remove xml tag name, attributes, value.
//??    remove_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_TAG_COUNT, (void*) &XML_TAG_COUNTS_INDEX);
//??    remove_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_TAG_COUNT, (void*) &XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX);

    // Destroy xml tag name, attributes, value.
    deallocate_array((void*) &nav, p1, (void*) POINTER_ARRAY);
    deallocate_array((void*) &c, p1, (void*) INTEGER_ARRAY);

    // Destroy xml tag.
    deallocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/* XML_NODE_ALLOCATOR_SOURCE */
#endif
