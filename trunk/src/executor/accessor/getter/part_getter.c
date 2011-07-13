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

#ifndef PART_GETTER_SOURCE
#define PART_GETTER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/accessor/getter/item_getter.c"
#include "../../../executor/comparator/count_array_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Gets the array as element from the part container.
 *
 * @param p0 the array
 * @param p1 the part container
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the array index
 * @param p5 the part container index
 * @param p6 the part container element index
 */
void get_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get part element.");

    // The part container element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get part container element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Get item from part container element.
    // The count is adjusted automatically.
    get_item_element(p0, e, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/* PART_GETTER_SOURCE */
#endif
