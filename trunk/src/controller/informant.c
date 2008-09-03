/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: informant.c,v $ $Revision: 1.4 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INFORMANT_SOURCE
#define INFORMANT_SOURCE

#include "../globals/constants/character/code/wide_character_code_constants.c"
#include "../globals/constants/cyboi/cyboi_identification_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../memoriser/array.c"

/**
 * Writes cyboi information message to given output stream.
 *
 * @param p0 the output stream
 */
void inform(void* p0) {

    // The message.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The cyboi name + space + version + line feed + copyright + line feed + licence + line feed + termination.
    int ms = *CYBOI_NAME_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *CYBOI_VERSION_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *CYBOI_COPYRIGHT_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *CYBOI_LICENCE_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // The index.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate message.
    allocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Copy name.
    set_array_elements(m, (void*) &i, (void*) CYBOI_NAME, (void*) CYBOI_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *CYBOI_NAME_COUNT;
    // Copy space wide character.
    set_array_elements(m, (void*) &i, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy version.
    set_array_elements(m, (void*) &i, (void*) CYBOI_VERSION, (void*) CYBOI_VERSION_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *CYBOI_VERSION_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy copyright.
    set_array_elements(m, (void*) &i, (void*) CYBOI_COPYRIGHT, (void*) CYBOI_COPYRIGHT_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *CYBOI_COPYRIGHT_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy licence.
    set_array_elements(m, (void*) &i, (void*) CYBOI_LICENCE, (void*) CYBOI_LICENCE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *CYBOI_LICENCE_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy null termination wide character.
    set_array_elements(m, (void*) &i, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Log message.
    log_write_terminated_message(p0, m);

    // Deallocate message.
    deallocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/* INFORMANT_SOURCE */
#endif
