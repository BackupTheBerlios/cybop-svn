/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: informant.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INFORMANT_SOURCE
#define INFORMANT_SOURCE

#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/cyboi/identification_cyboi_model.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
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
    int ms = *NAME_IDENTIFICATION_CYBOI_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // The index.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate message.
    allocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Copy name.
    set_array_elements(m, (void*) &i, (void*) NAME_IDENTIFICATION_CYBOI_MODEL, (void*) NAME_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *NAME_IDENTIFICATION_CYBOI_MODEL_COUNT;
    // Copy space wide character.
    set_array_elements(m, (void*) &i, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy version.
    set_array_elements(m, (void*) &i, (void*) VERSION_IDENTIFICATION_CYBOI_MODEL, (void*) VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy copyright.
    set_array_elements(m, (void*) &i, (void*) COPYRIGHT_IDENTIFICATION_CYBOI_MODEL, (void*) COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy licence.
    set_array_elements(m, (void*) &i, (void*) LICENCE_IDENTIFICATION_CYBOI_MODEL, (void*) LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT;
    // Copy line feed control wide character.
    set_array_elements(m, (void*) &i, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy null termination wide character.
    set_array_elements(m, (void*) &i, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Log message.
    log_write_terminated_message(p0, m);

    // Deallocate message.
    deallocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/* INFORMANT_SOURCE */
#endif
