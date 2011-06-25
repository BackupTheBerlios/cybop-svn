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
 * @version $RCSfile: compound_allocator.c,v $ $Revision: 1.18 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ALLOCATOR_SOURCE
#define COMPOUND_ALLOCATOR_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/compound_memory_name.c"
#include "../../../executor/comparator/count_array_comparator.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../logger/logger.c"

/**
 * Allocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the compound size
 */
void allocate_compound(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** c = (void**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate compound.");

        // Allocate compound.
        allocate_array(p0, (void*) COMPOUND_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // The names, abstractions, models, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ns = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* as = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* ms = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* ds = *NULL_POINTER_MEMORY_MODEL;

        // Allocate names, abstractions, models, details.
        allocate_model((void*) &n, (void*) &nc, (void*) &ns, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        allocate_model((void*) &a, (void*) &ac, (void*) &as, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        allocate_model((void*) &m, (void*) &mc, (void*) &ms, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        allocate_model((void*) &d, (void*) &dc, (void*) &ds, p1, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        // Set names, abstractions, models, details.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        replace_array(*c, (void*) &n, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &nc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &ns, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &ac, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &as, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &mc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &ms, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &dc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        replace_array(*c, (void*) &ds, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate compound. The compound is null.");
    }
}

/**
 * Allocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the size
 */
void allocate_compound_NEW(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** c = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate compound.");

        // Allocate compound.
        allocate_array(p0, (void*) COMPOUND_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // The names, abstractions, models, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;

        // Allocate names, abstractions, models, details.
        allocate_item((void*) &n, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &a, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &m, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &d, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Set names, abstractions, models, details.
        copy_array_offset(*c, (void*) &n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NAMES_COMPOUND_MEMORY_NAME_NEW, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        copy_array_offset(*c, (void*) &a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME_NEW, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        copy_array_offset(*c, (void*) &m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) MODELS_COMPOUND_MEMORY_NAME_NEW, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        copy_array_offset(*c, (void*) &d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DETAILS_COMPOUND_MEMORY_NAME_NEW, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The model is null.");
    }
}

/* COMPOUND_ALLOCATOR_SOURCE */
#endif
