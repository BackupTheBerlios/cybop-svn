/*
 * $RCSfile: pointer_creator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.4 $ $Date: 2005-01-17 23:46:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_CREATOR_SOURCE
#define POINTER_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the pointer.
 *
 * @param p0 the model (Hand over as reference!)
 */
void create_pointer(void* p0) {

    log_message_debug("Create pointer.");

    // Create pointer array containing the actual pointer value.
    create_array(p0, (void*) POINTER_COUNT, (void*) POINTER_ARRAY);
}

/**
 * Destroys the pointer.
 *
 * @param p0 the model (Hand over as reference!)
 */
void destroy_pointer(void* p0) {

    log_message_debug("Destroy pointer.");

    // Destroy pointer array containing the actual pointer value.
    destroy_array(p0, (void*) POINTER_COUNT, (void*) POINTER_ARRAY);
}

/* POINTER_CREATOR_SOURCE */
#endif
