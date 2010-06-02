/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: all_counting_memoriser.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ALL_COUNTING_MEMORISER_SOURCE
#define ALL_COUNTING_MEMORISER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/decoder.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"

/**
 * Counts all compound parts.
 *
 * @param p0 the result
 * @param p1 the result count
 * @param p2 the result size
 * @param p3 the compound
 * @param p4 the compound count
 */
void memorise_counting_all(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** r = (void**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Count all compound parts.");

        // Set result to compound count value.
        // A loop is not needed here, since the compound count already contains
        // the number of parts within that compound.
        set(*r, p1, p2, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, INTEGER_NUMBER_CYBOL_ABSTRACTION, INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not count all compound parts. The result is null.");
    }
}

/* ALL_COUNTING_MEMORISER_SOURCE */
#endif
