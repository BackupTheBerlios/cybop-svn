/*
 * $RCSfile: wide_character_vector_accessor.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2008-05-04 00:18:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIDE_CHARACTER_VECTOR_ACCESSOR_SOURCE
#define WIDE_CHARACTER_VECTOR_ACCESSOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Sets the wide character vector element.
 *
 * @param p0 the wide character vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void set_wide_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Set wide character vector element.");

    set_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER, (void*) WIDE_CHARACTER_ARRAY);
}

/**
 * Removes the wide character vector element.
 *
 * @param p0 the wide character vector
 * @param p1 the size
 * @param p2 the index
 */
void remove_wide_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Remove wide character vector element.");

    remove_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER, (void*) WIDE_CHARACTER_ARRAY);
}

/**
 * Gets the wide character vector element.
 *
 * @param p0 the wide character vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void get_wide_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Get wide character vector element.");

    get_array_elements(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);
}

/* WIDE_CHARACTER_VECTOR_ACCESSOR_SOURCE */
#endif
