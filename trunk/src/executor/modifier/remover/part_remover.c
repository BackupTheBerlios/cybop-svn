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
 * @version $RCSfile: accessor.c,v $ $Revision: 1.24 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_REMOVER_SOURCE
#define PART_REMOVER_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/memory_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../executor/modifier/remover/item_remover.c"
#include "../../../logger/logger.c"

/**
 * Removes count elements from the part.
 *
 * The name, abstraction and details of the part
 * remain unchanged. Only the model gets removed.
 *
 * The count and size are adjusted automatically.
 *
 * @param p0 the part
 * @param p1 the operand abstraction
 * @param p2 the count
 * @param p3 the index
 */
void remove_part(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove part.");

    // The part model.
    void* m = *NULL_POINTER_MEMORY_MODEL;

    // Get part model.
    copy_array_forward((void*) &m, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Remove elements from part model.
    remove_item(m, p1, p2, p3);
}

/* PART_REMOVER_SOURCE */
#endif
