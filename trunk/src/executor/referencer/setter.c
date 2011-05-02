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

#ifndef SETTER_SOURCE
#define SETTER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/count_array_comparator.c"
#include "../../executor/memoriser/reallocator.c"
#include "../../executor/modifier/replacer/array_replacer.c"
#include "../../executor/modifier/replacer/compound_replacer.c"
#include "../../executor/modifier/replacer/part_replacer.c"
#include "../../executor/modifier/replacer/signal_memory_replacer.c"

/**
 * Sets count source elements into the destination at position index.
 *
 * @param p0 the destination
 * @param p1 the source
 * @param p2 the count
 * @param p3 the destination index
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void set(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_complex(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_datetime(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_fraction(p0, p1);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) MODEL_MEMORY_ABSTRACTION, (void*) MODEL_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_model(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_signal_memory(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, p4, p5, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set_array(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not set. The abstraction is unknown.");
    }
}

/* SETTER_SOURCE */
#endif
