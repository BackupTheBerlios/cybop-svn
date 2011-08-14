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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_NAME_FINDER_SOURCE
#define PART_NAME_FINDER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Finds a part with the searched name array in the investigated part.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated part (each element pointing to a part)
 * @param p2 the searched name array
 * @param p3 the searched name array count
 * @param p4 the investigated part element index
 */
void find_name_part_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Find name part element.");

    // The investigated part.
    void* i = *NULL_POINTER_MEMORY_MODEL;

    // Get investigated part.
    copy_array_forward((void*) &i, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p4);

    // Find the searched item in the investigated item.
    find_name_item_element(p0, i, p2, p3);
}

/**
 * Finds a part with the searched name part in the investigated part.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated part (each element pointing to a part)
 * @param p2 the searched name part
 */
void find_name_part(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Find name part.");

    // The investigated part.
    void* i = *NULL_POINTER_MEMORY_MODEL;
    // The searched name part name.
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // Get investigated part.
    copy_array_forward((void*) &i, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get searched name part name.
    copy_array_forward((void*) &s, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);

    // Find the searched name item in the investigated item.
    find_name_item(p0, i, s);
}

/* PART_NAME_FINDER_SOURCE */
#endif
