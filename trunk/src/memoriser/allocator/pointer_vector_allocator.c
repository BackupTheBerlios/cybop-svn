/*
 * $RCSfile: pointer_vector_allocator.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2007-04-16 15:50:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_VECTOR_ALLOCATOR_SOURCE
#define POINTER_VECTOR_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the pointer vector.
 *
 * @param p0 the vector (Hand over as reference!)
 * @param p1 the vector size
 */
void allocate_pointer_vector(void* p0, void* p1) {

    log_message_debug("Allocate pointer vector.");

    allocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/**
 * Deallocates the pointer vector.
 *
 * @param p0 the vector (Hand over as reference!)
 * @param p1 the vector size
 */
void deallocate_pointer_vector(void* p0, void* p1) {

    log_message_debug("Deallocate pointer vector.");

    deallocate_array(p0, p1, (void*) POINTER_ARRAY);
}

/**
 * Reallocates the pointer vector.
 *
 * @param p0 the vector (Hand over as reference!)
 * @param p1 the vector count
 * @param p2 the vector size
 */
void reallocate_pointer_vector(void* p0, void* p1, void* p2) {

    log_message_debug("Reallocate pointer vector.");

    reallocate_array(p0, p1, p2, (void*) POINTER_ARRAY);
}

/* POINTER_VECTOR_ALLOCATOR_SOURCE */
#endif
