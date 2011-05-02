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
 * @version $RCSfile: signal_memory_accessor.c,v $ $Revision: 1.29 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_REPLACER_SOURCE
#define PART_REPLACER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/signal_memory_memory_name.c"
#include "../../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../../executor/memoriser/reallocator/signal_memory_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Replaces the part element at the given index.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source element
 * @param p2 the source element count
 * @param p3 the index
 */
void replace_part(void* p0, void* p1, void* p2, void* p3) {

/*??
    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sms = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* smc = (int*) p1;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace part element.");

            replace(MODEL);
            replace_array(*n, (void*) &p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace part element. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace part element. The signal memory size is null.");
    }
*/
}

/* PART_REPLACER_SOURCE */
#endif
