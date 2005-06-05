/*
 * $RCSfile: character_creator.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-06-05 00:07:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_CREATOR_SOURCE
#define CHARACTER_CREATOR_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memory/array/array.c"

/**
 * Creates the character.
 *
 * @param p0 the model (Hand over as reference!)
 */
void create_character(void* p0) {

    log_message_debug("Create character.");

    // Create character array containing the actual character value.
    create_array(p0, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
}

/**
 * Destroys the character.
 *
 * @param p0 the model (Hand over as reference!)
 */
void destroy_character(void* p0) {

    log_message_debug("Destroy character.");

    // Destroy character array containing the actual character value.
    destroy_array(p0, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
}

/* CHARACTER_CREATOR_SOURCE */
#endif
