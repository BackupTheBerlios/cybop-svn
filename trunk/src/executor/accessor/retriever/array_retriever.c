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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_RETRIEVER_SOURCE
#define ARRAY_RETRIEVER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder/integer_integer_adder.c"
#include "../../../executor/arithmetiser/integer_adder/pointer_integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/comparator/equality/array_equality_comparator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Retrieves the element at position index.
 *
 * @param p0 the destination element (Hand over as reference!)
 * @param p1 the source array
 * @param p2 the source array index
 * @param p3 the element abstraction
 */
void retrieve_array(void* p0, void* p1, void* p2, void* p3) {

    // CAUTION! This test is important!
    // The destination is initialised with the source below.
    // A source with "null" value would cause an error
    // (segmentation fault) when trying to add the offset.
    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** d = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Retrieve array element.");

            // The offset.
            int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Determine abstraction (type) size.
            determine_size((void*) &o, p3);

            // Calculate memory area (destination offset).
            multiply_with_integer((void*) &o, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

            // The destination elements.
            // CAUTION! It HAS TO BE initialised with p1,
            // since an offset is added to it below.
            *d = p1;

            // Add offset to destination elements.
            // The destination is set to source pointer plus offset.
            // That's all.
            add_integer_to_pointer(p0, (void*) &o);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not retrieve array element. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not retrieve array element. The source array is null.");
    }
}

/* ARRAY_RETRIEVER_SOURCE */
#endif
