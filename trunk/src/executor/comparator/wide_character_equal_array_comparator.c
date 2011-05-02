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

#ifndef WIDE_CHARACTER_EQUAL_ARRAY_COMPARATOR_SOURCE
#define WIDE_CHARACTER_EQUAL_ARRAY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

//
// Actually, the "array_comparator.c" file should be used for array comparison.
// However, there are two reasons why a simplified comparison function like the
// one introduced in this file is necessary:
//
// 1 Efficiency
//
// A comparison for equality happens VERY often in cyboi source code, most
// commonly with an abstraction (type) parametre given as wide character array.
// The standard comparison file "array_comparator.c" expects parametres for
// the operation abstraction and operand abstraction.
// These have to be compared each time, which slows down runtime performance.
//
// 2 Avoidance of circular references
//
// The standard comparison functions e.g. in file "item_comparator.c" rely on
// other container functions like "get" and "set" which are using array
// comparison functions in turn (for comparing given "abstraction" parametres).
// This would lead to circular (bi-directional) references.
//

/**
 * Compares two wide character values for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_array_equal_wide_character_value(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        wchar_t* rv = (wchar_t*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* lv = (wchar_t*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array equal wide character value.");

                if (*lv == *rv) {

                    *r = *NUMBER_1_INTEGER_MEMORY_MODEL;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character value. The result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character value. The left value is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character value. The right value is null.");
    }
}

/**
 * Compares one element of the left- with one of the right array for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the index
 */
void compare_array_equal_wide_character_element(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array equal wide character element.");

    // The offset (memory area).
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    determine_size((void*) &o, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Calculate offset.
    multiply_with_integer((void*) &o, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // The left array, right array.
    // CAUTION! They HAVE TO BE initialised with p1 and p2,
    // since an offset is added below.
    void* la = p1;
    void* ra = p2;

    // Add offset to left array, right array.
    add_integer((void*) &la, (void*) &o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    add_integer((void*) &ra, (void*) &o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    compare_array_equal_wide_character_value(p0, la, ra);
}

/**
 * Compares all elements of the given arrays for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the count
 */
void compare_array_equal_wide_character_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array equal wide character elements.");

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The element comparison result.
                    int er = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                            break;
                        }

                        // Reset comparison result.
                        er = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // CAUTION! This function does not change the result flag, if unequal.
                        // Therefore, the result flag always has to be initialised with zero before!
                        compare_array_equal_wide_character_element((void*) &er, p1, p2, (void*) &j);

                        if (er == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Stop comparison if two elements are not equal,
                            // because then the two arrays are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character elements. The result is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character elements. The left array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character elements. The right array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character elements. The array count is null.");
    }
}

/**
 * Compares two wide character arrays for equality.
 *
 * This function compares only the array counts.
 * The actual elements comparison happens in another function.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the left array count
 * @param p3 the right array
 * @param p4 the right array count
 */
void compare_array_equal_wide_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* lc = (int*) p2;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array equal wide character.");

            if (*lc == *rc) {

                compare_array_equal_wide_character_elements(p0, p1, p3, p4);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character. The left array count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array equal wide character. The right array count is null.");
    }
}

/* WIDE_CHARACTER_EQUAL_ARRAY_COMPARATOR_SOURCE */
#endif
