/*
 * $RCSfile: integer_creator.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-01-10 14:46:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_CREATOR_SOURCE
#define INTEGER_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the integer.
 *
 * @param p0 the model
 */
void create_integer(void* p0) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_INTEGER_MESSAGE, (void*) &CREATE_INTEGER_MESSAGE_COUNT);

    // Create integer array containing the actual integer value.
    create_array(p0, (void*) &INTEGER_ARRAY, (void*) &INTEGER_COUNT);
}

/**
 * Destroys the integer.
 *
 * @param p0 the model
 */
void destroy_integer(void* p0) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_INTEGER_MESSAGE, (void*) &DESTROY_INTEGER_MESSAGE_COUNT);

    // Destroy integer array containing the actual integer value.
    destroy_array(p0, (void*) &INTEGER_ARRAY, (void*) &INTEGER_COUNT);
}

/* INTEGER_CREATOR_SOURCE */
#endif
