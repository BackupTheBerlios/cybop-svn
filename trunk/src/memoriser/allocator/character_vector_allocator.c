/*
 * $RCSfile: character_vector_allocator.c,v $
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
 * This file contains the functionality to:
 * - create a string model in memory
 *
 * @version $Revision: 1.1 $ $Date: 2005-08-09 13:04:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_VECTOR_ALLOCATOR_SOURCE
#define CHARACTER_VECTOR_ALLOCATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the character vector.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_character_vector(void* p0, void* p1) {

    log_message_debug("Allocate character vector.");

    allocate_array(p0, p1, (void*) CHARACTER_ARRAY);
}

/**
 * Deallocates the character vector.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void deallocate_character_vector(void* p0, void* p1) {

    log_message_debug("Deallocate character vector.");

    deallocate_array(p0, p1, (void*) CHARACTER_ARRAY);
}

/* CHARACTER_VECTOR_ALLOCATOR_SOURCE */
#endif
