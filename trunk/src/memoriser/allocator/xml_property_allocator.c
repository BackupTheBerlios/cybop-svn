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
 * @version $RCSfile: xml_property_allocator.c,v $ $Revision: 1.14 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_PROPERTY_ALLOCATOR_SOURCE
#define XML_PROPERTY_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the xml property.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_xml_property(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate xml property.");

    // Create xml attribute.
    allocate_array(p0, p1, (void*) POINTER_ARRAY);

    // Initialise xml attribute name, value.
    void* nv = *NULL_POINTER_MEMORY_MODEL;
    void* c = *NULL_POINTER_MEMORY_MODEL;

    // Create xml attribute name, value.
    allocate_array((void*) &nv, p1, (void*) POINTER_ARRAY);
    allocate_array((void*) &c, p1, (void*) INTEGER_ARRAY);

    //
    // Use ascending order.
    //

    // Set xml attribute name, value.
//??    set_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_ATTRIBUTE_NAME_VALUE_INDEX, (void*) &nv);
//??    set_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNTS_INDEX, (void*) &c);
}

/**
 * Deallocates the xml property.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void deallocate_xml_property(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Deallocate xml property.");

    // Initialise xml attribute name, value.
    void* nv = *NULL_POINTER_MEMORY_MODEL;
    void* c = *NULL_POINTER_MEMORY_MODEL;

    // Get xml attribute name, value.
//??    get_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_ATTRIBUTE_NAME_VALUE_INDEX, (void*) &nv);
//??    get_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNTS_INDEX, (void*) &c);

    //
    // Use descending order.
    //

    // Remove xml attribute name, value.
//??    remove_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNT, (void*) &XML_ATTRIBUTE_COUNTS_INDEX);
//??    remove_array_elements(p0, (void*) POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNT, (void*) &XML_ATTRIBUTE_NAME_VALUE_INDEX);

    // Destroy xml attribute name, value.
    deallocate_array((void*) &nv, p1, (void*) POINTER_ARRAY);
    deallocate_array((void*) &c, p1, (void*) INTEGER_ARRAY);

    // Destroy xml attribute.
    deallocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/* XML_PROPERTY_ALLOCATOR_SOURCE */
#endif
