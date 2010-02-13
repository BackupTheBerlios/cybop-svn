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

#ifndef ALLOCATOR_SOURCE
#define ALLOCATOR_SOURCE

#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/abstraction/memory/array_memory_abstraction.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../memoriser/allocator/character_vector_allocator.c"
#include "../memoriser/allocator/complex_allocator.c"
#include "../memoriser/allocator/compound_allocator.c"
#include "../memoriser/allocator/date_time_allocator.c"
#include "../memoriser/allocator/double_vector_allocator.c"
#include "../memoriser/allocator/fraction_allocator.c"
#include "../memoriser/allocator/integer_vector_allocator.c"
#include "../memoriser/allocator/internal_memory_allocator.c"
#include "../memoriser/allocator/part_allocator.c"
#include "../memoriser/allocator/pointer_vector_allocator.c"
#include "../memoriser/allocator/signal_memory_allocator.c"
#include "../memoriser/allocator/unsigned_long_vector_allocator.c"
#include "../memoriser/allocator/wide_character_vector_allocator.c"
#include "../memoriser/array.c"

/**
 * Reallocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void reallocate(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Reallocate.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_character_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_complex(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_compound(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_date_time(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) DOUBLE_VECTOR_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_double_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_wide_character_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_fraction(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_integer_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_internal_memory(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_wide_character_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_wide_character_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) PART_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_part(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            reallocate_pointer_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_signal_memory(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) UNSIGNED_LONG_VECTOR_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_unsigned_long_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) &r, p2, p3, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            reallocate_wide_character_vector(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not reallocate. The abstraction is unknown.");
    }
}

/* ALLOCATOR_SOURCE */
#endif
