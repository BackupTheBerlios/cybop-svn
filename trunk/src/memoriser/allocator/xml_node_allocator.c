/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: xml_node_allocator.c,v $ $Revision: 1.13 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_NODE_ALLOCATOR_SOURCE
#define XML_NODE_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the xml node.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_xml_node(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate xml node.");

    // Create xml node.
    allocate_array(p0, p1, (void*) POINTER_ARRAY);

    // Initialise xml node name, attributes, value.
    void* nav = *NULL_POINTER_MEMORY_MODEL;
    void* c = *NULL_POINTER_MEMORY_MODEL;

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

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Deallocate xml node.");

    // Initialise xml tag name, attributes, value.
    void* nav = *NULL_POINTER_MEMORY_MODEL;
    void* c = *NULL_POINTER_MEMORY_MODEL;

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
