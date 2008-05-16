/*
 * $RCSfile: helper.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2008-05-16 00:20:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HELPER_SOURCE
#define HELPER_SOURCE

#include "../globals/constants/character/wide_character_constants.c"
#include "../globals/constants/cyboi/cyboi_identification_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../memoriser/array.c"

/**
 * Writes cyboi help message to given output stream.
 *
 * @param p0 the output stream
 */
void help(void* p0) {

    // The message.
    void* m = *NULL_POINTER;
    // The message + line feed + termination.
    int ms = *CYBOI_HELP_COUNT + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT;
    // The index.
    int i = *NUMBER_0_INTEGER;

    // Allocate message.
    allocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY);

    // Copy message.
    set_array_elements(m, (void*) &i, (void*) CYBOI_HELP, (void*) CYBOI_HELP_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    // Increment index.
    i = i + *CYBOI_HELP_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    // Increment index.
    i = i + *PRIMITIVE_COUNT;
    // Copy null termination wide character.
    set_array_elements(m, (void*) &i, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);

    // Log message.
    log_write_terminated_message(p0, m);

    // Deallocate message.
    deallocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY);
}

/* HELPER_SOURCE */
#endif
