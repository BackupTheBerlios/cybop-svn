/*
 * $RCSfile: unsigned_long_allocator.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-07-27 13:30:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNSIGNED_LONG_ALLOCATOR_SOURCE
#define UNSIGNED_LONG_ALLOCATOR_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the unsigned long.
 *
 * @param p0 the model (Hand over as reference!)
 */
void allocate_unsigned_long(void* p0) {

    log_message_debug("Allocate unsigned long.");

    // Create unsigned long array containing the actual value.
    allocate_array(p0, (void*) UNSIGNED_LONG_COUNT, (void*) UNSIGNED_LONG_ARRAY);
}

/**
 * Deallocates the unsigned long.
 *
 * @param p0 the model (Hand over as reference!)
 */
void deallocate_unsigned_long(void* p0) {

    log_message_debug("Deallocate unsigned long.");

    // Destroy unsigned long array containing the actual value.
    deallocate_array(p0, (void*) UNSIGNED_LONG_COUNT, (void*) UNSIGNED_LONG_ARRAY);
}

/* UNSIGNED_LONG_ALLOCATOR_SOURCE */
#endif
