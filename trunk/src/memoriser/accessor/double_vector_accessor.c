/*
 * $RCSfile: double_vector_accessor.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-07-28 12:52:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_ACCESSOR_SOURCE
#define DOUBLE_VECTOR_ACCESSOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Sets the double vector element.
 *
 * @param p0 the double vector
 * @param p1 the index
 * @param p2 the element
 */
void set_double_vector_element(void* p0, void* p1, void* p2) {

    log_message_debug("Set double vector element.");

    set_array_elements(p0, p1, (void*) &p2, (void*) NUMBER_1_INTEGER, (void*) DOUBLE_ARRAY);
}

/**
 * Removes the double vector element.
 *
 * @param p0 the double vector
 * @param p1 the size
 * @param p2 the index
 */
void remove_double_vector_element(void* p0, void* p1, void* p2) {

    log_message_debug("Remove double vector element.");

    remove_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER, (void*) DOUBLE_ARRAY);
}

/**
 * Gets the double vector element.
 *
 * @param p0 the double vector
 * @param p1 the index
 * @param p2 the vector element (Hand over as reference!)
 */
void get_double_vector_element(void* p0, void* p1, void* p2) {

    log_message_debug("Get double vector element.");

    get_array_elements(p0, p1, p2, (void*) DOUBLE_ARRAY);
}

/* DOUBLE_VECTOR_ACCESSOR_SOURCE */
#endif