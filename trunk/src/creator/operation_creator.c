/*
 * $RCSfile: operation_creator.c,v $
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
 * This file contains the functionality to:
 * - create an operation model in memory
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-15 22:11:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_CREATOR_SOURCE
#define OPERATION_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the operation.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void create_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_OPERATION_MESSAGE, (void*) &CREATE_OPERATION_MESSAGE_COUNT);

    // Create operation.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT);

    // Initialize elements.
    void* p = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* ps = NULL_POINTER;

    // Create elements.
    create_array((void*) &p, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &ps, (void*) &INTEGER_ARRAY, p1);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);
}

/**
 * Destroys the operation.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void destroy_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_OPERATION_MESSAGE, (void*) &DESTROY_OPERATION_MESSAGE_COUNT);

    // Initialize elements.
    void* p = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* ps = NULL_POINTER;

    // Get elements.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT, (void*) &PARAMETERS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT, (void*) &PARAMETERS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT, (void*) &PARAMETERS_INDEX);

    // Destroy elements.
    destroy_array((void*) &p, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &ps, (void*) &INTEGER_ARRAY, p1);

    // Destroy operation.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT);
}

/* OPERATION_CREATOR_SOURCE */
#endif
