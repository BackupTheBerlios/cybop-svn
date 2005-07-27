/*
 * $RCSfile: xml_property_allocator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2005-07-27 13:30:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_PROPERTY_ALLOCATOR_SOURCE
#define XML_PROPERTY_ALLOCATOR_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the xml property.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_xml_property(void* p0, void* p1) {

    log_message_debug("Allocate xml property.");

    // Create xml attribute.
    allocate_array(p0, (void*) XML_ATTRIBUTE_COUNT, (void*) POINTER_ARRAY);

    // Initialise xml attribute name, value.
    void* nv = NULL_POINTER;
    void* c = NULL_POINTER;

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

    log_message_debug("Deallocate xml property.");

    // Initialise xml attribute name, value.
    void* nv = NULL_POINTER;
    void* c = NULL_POINTER;

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
    deallocate_array(p0, (void*) XML_ATTRIBUTE_COUNT, (void*) POINTER_ARRAY);
}

/* XML_PROPERTY_ALLOCATOR_SOURCE */
#endif
