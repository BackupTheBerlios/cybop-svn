/*
 * $RCSfile: integer_allocator.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-07-27 23:10:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_ALLOCATOR_SOURCE
#define INTEGER_ALLOCATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the integer.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void allocate_integer(void* p0, void* p1) {

    log_message_debug("Allocate integer.");

    // Create integer array containing the actual integer value.
    allocate_array(p0, p1, (void*) INTEGER_ARRAY);
}

/**
 * Deallocates the integer.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 */
void deallocate_integer(void* p0, void* p1) {

    log_message_debug("Deallocate integer.");

    // Destroy integer array containing the actual integer value.
    deallocate_array(p0, p1, (void*) INTEGER_ARRAY);
}

/* INTEGER_ALLOCATOR_SOURCE */
#endif
