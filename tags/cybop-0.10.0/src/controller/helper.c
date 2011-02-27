/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: helper.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HELPER_SOURCE
#define HELPER_SOURCE

#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/cyboi/identification_cyboi_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../executor/modifier/replacer/array_replacer.c"
#include "../executor/comparator/array_equality_comparator.c"
#include "../executor/memoriser/allocator/model_allocator.c"
#include "../executor/memoriser/deallocator/model_deallocator.c"

/**
 * Writes cyboi help message to given output stream.
 *
 * @param p0 the output stream
 */
void help(void* p0) {

    // The message.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* ms = *NULL_POINTER_MEMORY_MODEL;

    // The size: message + line feed + termination
    int s = *HELP_IDENTIFICATION_CYBOI_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // The index.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate message.
    allocate_model((void*) &m, (void*) &mc, (void*) &ms, (void*) &s, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Copy message.
    replace_array(m, (void*) HELP_IDENTIFICATION_CYBOI_MODEL, (void*) HELP_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &i, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *HELP_IDENTIFICATION_CYBOI_MODEL_COUNT;
    // Copy line feed control wide character.
    replace_array(m, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Increment index.
    i = i + *PRIMITIVE_MEMORY_MODEL_COUNT;
    // Copy null termination wide character.
    replace_array(m, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Log message.
    log_write_terminated_message(p0, m);

    // Deallocate message.
    deallocate_model((void*) &m, (void*) &mc, (void*) &ms, (void*) &s, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* HELPER_SOURCE */
#endif
