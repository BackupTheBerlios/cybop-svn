/*
 * $RCSfile: internals_memory_accessor.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2004-12-21 10:24:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNALS_MEMORY_ACCESSOR_SOURCE
#define INTERNALS_MEMORY_ACCESSOR_SOURCE

#include "../array/array.c"
#include "../cyboi/integer_internals.c"
#include "../cyboi/double_internals.c"
#include "../cyboi/character_internals.c"
#include "../cyboi/pointer_internals.c"
#include "../global/constant.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Sets the internal.
 *
 * @param p0 the internals memory
 * @param p1 the value
 * @param p2 the type
 * @param p3 the index
 */
void set_internal(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Set internal.");

    // The value, type.
    void* v = NULL_POINTER;
    void* t = NULL_POINTER;

    // Get value, type.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_VALUES_INDEX, (void*) &v, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_TYPES_INDEX, (void*) &t, (void*) &ONE_ELEMENT_COUNT);

    // Set value, type.
    set_array_elements((void*) &v, (void*) &POINTER_ARRAY, p3, p1, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements((void*) &t, (void*) &POINTER_ARRAY, p3, p2, (void*) &ONE_ELEMENT_COUNT);
}

/**
 * Gets the internal.
 *
 * @param p0 the internals memory
 * @param p1 the value
 * @param p2 the type
 * @param p3 the index
 */
void get_internal(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Get internal.");

    // The value, type.
    void* v = NULL_POINTER;
    void* t = NULL_POINTER;

    // Get value, type.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_VALUES_INDEX, (void*) &v, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_TYPES_INDEX, (void*) &t, (void*) &ONE_ELEMENT_COUNT);

    // Get value, type.
    get_array_elements((void*) &v, (void*) &POINTER_ARRAY, p3, p1, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements((void*) &t, (void*) &POINTER_ARRAY, p3, p2, (void*) &ONE_ELEMENT_COUNT);
}

/* INTERNALS_MEMORY_ACCESSOR_SOURCE */
#endif
