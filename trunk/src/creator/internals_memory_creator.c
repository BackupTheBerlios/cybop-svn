/*
 * $RCSfile: internals_memory_creator.c,v $
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
 * This file handles cyboi internal variables which are needed to communicate
 * with underlying sub systems or hardware directly. Various platforms and
 * user interfaces are considered.
 *
 * Variables belong to for example:
 * - Socket
 * - TCP/IP
 * - X-Windows
 * - Macintosh
 * - MS Windows
 *
 * @version $Revision: 1.1 $ $Date: 2004-12-20 21:06:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNALS_MEMORY_CREATOR_SOURCE
#define INTERNALS_MEMORY_CREATOR_SOURCE

#include "../array/array.c"
#include "../cyboi/integer_internals.c"
#include "../cyboi/double_internals.c"
#include "../cyboi/character_internals.c"
#include "../cyboi/pointer_internals.c"
#include "../global/constant.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Creates the internals memory.
 *
 * @param p0 the internals memory
 * @param p1 the internals memory size
 */
void create_internals_memory(void* p0, const void* p1) {

    log_message_debug("Create internals memory.");

    // Create internals memory.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_MEMORY_COUNT);

    // The values, types.
    void* v = NULL_POINTER;
    void* t = NULL_POINTER;

    // Create values, types.
    create_array((void*) &v, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &t, (void*) &POINTER_ARRAY, p1);

    // Set values, types.
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_VALUES_INDEX, (void*) &v, (void*) &ONE_ELEMENT_COUNT);
    set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_TYPES_INDEX, (void*) &t, (void*) &ONE_ELEMENT_COUNT);
}

/**
 * Destroys the internals memory.
 *
 * @param p0 the internals memory
 * @param p1 the internals memory size
 */
void destroy_internals_memory(void* p0, const void* p1) {

    log_message_debug("Destroy internals memory.");

    // The values, types.
    void* v = NULL_POINTER;
    void* t = NULL_POINTER;

    // Get values, types.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_VALUES_INDEX, (void*) &v, (void*) &ONE_ELEMENT_COUNT);
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_TYPES_INDEX, (void*) &t, (void*) &ONE_ELEMENT_COUNT);

    // Remove values, types.
    // CAUTION! Use descending order as compared to creation, for faster removal.
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_MEMORY_COUNT, (void*) &INTERNALS_TYPES_INDEX, (void*) &ONE_ELEMENT_COUNT);
    remove_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_MEMORY_COUNT, (void*) &INTERNALS_VALUES_INDEX, (void*) &ONE_ELEMENT_COUNT);

    // Destroy values, types.
    destroy_array((void*) &v, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &t, (void*) &POINTER_ARRAY, p1);

    // Destroy internals memory.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_MEMORY_COUNT);
}

/* INTERNALS_MEMORY_CREATOR_SOURCE */
#endif
