/*
 * $RCSfile: xml_attribute.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2004-07-25 15:48:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_ATTRIBUTE
#define XML_ATTRIBUTE

#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Creates the xml attribute.
 *
 * @param p0 the xml attribute
 * @param p1 the xml attribute size
 */
void create_xml_attribute(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Create xml attribute.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNT);

    // Initialize xml attribute name, value
    // and their counts.
    void* nv = NULL_POINTER;
    void* c = NULL_POINTER;

    // Create xml attribute name, value
    // and their counts.
    create_array((void*) &nv, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &c, (void*) &INTEGER_ARRAY, p1);

    //
    // Use ascending order.
    //

    // Set xml attribute name, value
    // and their counts.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_NAME_VALUE_INDEX, (void*) &nv);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNTS_INDEX, (void*) &c);
}

/**
 * Destroys the xml attribute.
 *
 * @param p0 the xml attribute
 * @param p1 the xml attribute size
 */
void destroy_xml_attribute(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE, (void*) &CREATE_SIGNAL_MEMORY_MESSAGE_COUNT);

    // Initialize xml attribute name, value
    // and their counts.
    void* nv = NULL_POINTER;
    void* c = NULL_POINTER;

    // Get xml attribute name, value
    // and their counts.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_NAME_VALUE_INDEX, (void*) &nv);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNTS_INDEX, (void*) &c);

    //
    // Use descending order.
    //

    // Remove xml attribute name, value
    // and their counts.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNT, (void*) &XML_ATTRIBUTE_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNT, (void*) &XML_ATTRIBUTE_NAME_VALUE_INDEX);

    // Destroy xml attribute name, value
    // and their counts.
    destroy_array((void*) &nv, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &c, (void*) &INTEGER_ARRAY, p1);

    // Destroy xml attribute.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &XML_ATTRIBUTE_COUNT);
}

/* XML_ATTRIBUTE */
#endif
