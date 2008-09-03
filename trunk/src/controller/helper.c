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
 * @version $RCSfile: helper.c,v $ $Revision: 1.4 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HELPER_SOURCE
#define HELPER_SOURCE

#include "../globals/constants/character/code/wide_character_code_constants.c"
#include "../globals/constants/cyboi/cyboi_identification_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../memoriser/array.c"

/**
 * Writes cyboi help message to given output stream.
 *
 * @param p0 the output stream
 */
void help(void* p0) {

    // The message.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The message + line feed + termination.
    int ms = *CYBOI_HELP_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // The index.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate message.
    allocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Copy message.
    set_array_elements(m, (void*) &i, (void*) CYBOI_HELP, (void*) CYBOI_HELP_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *CYBOI_HELP_COUNT;
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

/* HELPER_SOURCE */
#endif
