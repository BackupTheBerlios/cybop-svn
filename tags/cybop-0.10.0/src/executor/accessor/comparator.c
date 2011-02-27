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
 * @version $RCSfile: comparator.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARATOR_SOURCE
#define COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder.c"
#include "../../executor/comparator/equality/character_equality_comparator.c"
#include "../../executor/comparator/equality/double_equality_comparator.c"
#include "../../executor/comparator/equality/integer_equality_comparator.c"
#include "../../executor/comparator/equality/pointer_equality_comparator.c"
#include "../../executor/comparator/equality/unsigned_long_equality_comparator.c"
#include "../../executor/comparator/equality/wide_character_equality_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares the element.
 *
 * @param p0 the result (number 1 if equal; unchanged otherwise)
 * @param p1 the left element
 * @param p2 the left element count
 * @param p3 the right element
 * @param p4 the right element count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
/*??
void compare_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare element.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_array(p0, p1, p2, p3, p4, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) COMPLEX_MEMORY_ABSTRACTION, (void*) COMPLEX_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_complex_element(*d, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_compound_element(*d, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) DATETIME_MEMORY_ABSTRACTION, (void*) DATETIME_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_datetime_element(*d, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) DOUBLE_MEMORY_ABSTRACTION, (void*) DOUBLE_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_array(*d, p1, p2, p3, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_fraction_element(*d, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_array(*d, p1, p2, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_internal_memory_element(*d, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_part(*d, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_array(*d, p1, p2, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            set_signal_memory_element(*d, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_array(*d, p1, p2, p3, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p4, p5, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            replace_array(*d, p1, p2, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not replace elements. The abstraction is unknown.");
    }
}

/**
 * Compares the elements.
 *
 * @param p0 the result (number 1 if equal; unchanged otherwise)
 * @param p1 the left element (Hand over as reference!)
 * @param p3 the right element (Hand over as reference!)
 * @param p4 the remaining element count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
/*??
void compare_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** rep = (void**) p6;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                void** lep = (void**) p6;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare elements.");

                    if (*rem > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        compare_element(p0, le, re, p5, p6);

                        // Decrement remaining elements count.
                        add_integer(p4, (void*) NUMBER_MINUS_ONE_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // The left element.
                            void* le = *lep;
                            // The right element.
                            void* re = *rep;

                            // Add offset to left element.
                            add_integer((void*) &le, p7, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                            // Add offset to right element.
                            add_integer((void*) &re, p7, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                            // Recursively call compare function.
                            compare_elements();
                        }
                    }
    }
}

/**
 * Compares the elements and their counts.
 *
 * @param p0 the result (number 1 if equal; unchanged otherwise)
 * @param p1 the left element
 * @param p2 the left element count
 * @param p3 the right element
 * @param p4 the right element count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
/*??
void compare(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare elements and their counts.");

        compare_primitive(p0, p2, p4, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (*r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Only compare elements if their counts are equal.
            compare_elements(p0, p1, p3, p4, p5, p6);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare arrays for equality. The right array count is null.");
    }
}

/* COMPARATOR_SOURCE */
#endif
