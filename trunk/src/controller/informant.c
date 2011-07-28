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
 * @version $RCSfile: informant.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INFORMANT_SOURCE
#define INFORMANT_SOURCE

#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/cyboi/identification_cyboi_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../executor/modifier/overwriter/array_overwriter.c"
#include "../executor/memoriser/allocator/array_allocator.c"
#include "../executor/memoriser/deallocator/array_deallocator.c"

/**
 * Writes cyboi information message to given output stream.
 *
 * @param p0 the output stream
 */
void inform(void* p0) {

    // The message.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // Set size to arbitrary big value, so that message does
    // not have to be reallocated for every character below.
    // This lets the programme run faster.
    int ms = *NUMBER_1000_INTEGER_MEMORY_MODEL;

    // Allocate message.
    allocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Copy name.
    overwrite_array((void*) &m, (void*) NAME_IDENTIFICATION_CYBOI_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NAME_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy space wide character.
    overwrite_array((void*) &m, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy version.
    overwrite_array((void*) &m, (void*) VERSION_IDENTIFICATION_CYBOI_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy line feed control wide character.
    overwrite_array((void*) &m, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy slogan.
    overwrite_array((void*) &m, (void*) SLOGAN_IDENTIFICATION_CYBOI_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SLOGAN_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy line feed control wide character.
    overwrite_array((void*) &m, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy copyright.
    overwrite_array((void*) &m, (void*) COPYRIGHT_IDENTIFICATION_CYBOI_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy line feed control wide character.
    overwrite_array((void*) &m, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy licence.
    overwrite_array((void*) &m, (void*) LICENCE_IDENTIFICATION_CYBOI_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy line feed control wide character.
    overwrite_array((void*) &m, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);
    // Copy null termination wide character.
    overwrite_array((void*) &m, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &mc, (void*) &ms);

    // Log message.
    log_write_terminated_message(p0, m);

    // Deallocate message.
    deallocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* INFORMANT_SOURCE */
#endif
