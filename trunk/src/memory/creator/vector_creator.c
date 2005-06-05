/*
 * $RCSfile: vector_creator.c,v $
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
 * - create a vector model in memory
 *
 * @version $Revision: 1.1 $ $Date: 2005-06-05 00:07:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VECTOR_CREATOR_SOURCE
#define VECTOR_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the vector.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void create_vector(void* p0, const void* p1) {

    log_message_debug("Create vector.");

    //?? OPEN QUESTION:
    //?? Should vector always be 3-dimensional,
    //?? or better of dynamic size?
    //?? If dynamic, then use p1 as size.

    // Create vector.
    create_array(p0, (void*) VECTOR_COUNT, (void*) INTEGER_ARRAY);
}

/**
 * Destroys the vector.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void destroy_vector(void* p0, const void* p1) {

    log_message_debug("Destroy vector.");

    // Destroy vector.
    destroy_array(p0, (void*) VECTOR_COUNT, (void*) INTEGER_ARRAY);
}

/* VECTOR_CREATOR_SOURCE */
#endif
