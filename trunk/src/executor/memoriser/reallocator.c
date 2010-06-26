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
 * @version $RCSfile: allocator.c,v $ $Revision: 1.34 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REALLOCATOR_SOURCE
#define REALLOCATOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../executor/memoriser/allocator.c"
#include "../../executor/memoriser/allocator/complex_allocator.c"
#include "../../executor/memoriser/allocator/compound_allocator.c"
#include "../../executor/memoriser/allocator/date_time_allocator.c"
#include "../../executor/memoriser/allocator/double_vector_allocator.c"
#include "../../executor/memoriser/allocator/fraction_allocator.c"
#include "../../executor/memoriser/allocator/integer_vector_allocator.c"
#include "../../executor/memoriser/allocator/internal_memory_allocator.c"
#include "../../executor/memoriser/allocator/part_allocator.c"
#include "../../executor/memoriser/allocator.c"
#include "../../executor/memoriser/allocator/signal_memory_allocator.c"
#include "../../executor/memoriser/allocator/unsigned_long_vector_allocator.c"
#include "../../executor/memoriser/allocator/wide_character_vector_allocator.c"
#include "../../executor/comparator/array_equality_comparator.c"

/**
 * Reallocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the abstraction
 */
void reallocate(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Reallocate.");

        if (*a == *CHARACTER_MEMORY_ABSTRACTION) {

//??            reallocate_character_vector(p0, p1, p2);

        } else if (*a == *COMPLEX_MEMORY_ABSTRACTION) {

//??            reallocate_complex(p0, p1, p2);

        } else if (*a == *COMPOUND_MEMORY_ABSTRACTION) {

//??            reallocate_compound(p0, p1, p2);

        } else if (*a == *DATETIME_MEMORY_ABSTRACTION) {

//??            reallocate_date_time(p0, p1, p2);

        } else if (*a == *DOUBLE_MEMORY_ABSTRACTION) {

//??            reallocate_double_vector(p0, p1, p2);

        } else if (*a == *ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION) {

//??            reallocate_wide_character_vector(p0, p1, p2);

        } else if (*a == *FRACTION_MEMORY_ABSTRACTION) {

//??            reallocate_fraction(p0, p1, p2);

        } else if (*a == *INTEGER_MEMORY_ABSTRACTION) {

//??            reallocate_integer_vector(p0, p1, p2);

        } else if (*a == *INTERNAL_MEMORY_MEMORY_ABSTRACTION) {

//??            reallocate_internal_memory(p0, p1, p2);

        } else if (*a == *KNOWLEDGE_PATH_MEMORY_ABSTRACTION) {

//??            reallocate_wide_character_vector(p0, p1, p2);

        } else if (*a == *OPERATION_MEMORY_ABSTRACTION) {

//??            reallocate_wide_character_vector(p0, p1, p2);

        } else if (*a == *PART_MEMORY_ABSTRACTION) {

//??            reallocate_part(p0, p1, p2);

        } else if (*a == *POINTER_MEMORY_ABSTRACTION) {

            reallocate_pointer_vector(p0, p1, p2);

        } else if (*a == *SIGNAL_MEMORY_MEMORY_ABSTRACTION) {

//??            reallocate_signal_memory(p0, p1, p2);

        } else if (*a == *UNSIGNED_LONG_MEMORY_ABSTRACTION) {

//??            reallocate_unsigned_long_vector(p0, p1, p2);

        } else if (*a == *WIDE_CHARACTER_MEMORY_ABSTRACTION) {

//??            reallocate_wide_character_vector(p0, p1, p2);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not reallocate. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate. The abstraction is null.");
    }
}

/* REALLOCATOR_SOURCE */
#endif
