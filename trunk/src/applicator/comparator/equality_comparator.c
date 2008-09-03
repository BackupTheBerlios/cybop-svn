/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: equality_comparator.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:03:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EQUALITY_COMPARATOR_SOURCE
#define EQUALITY_COMPARATOR_SOURCE

#include "../../applicator/comparator/equality/all_equality_comparator.c"
#include "../../applicator/comparator/equality/part_equality_comparator.c"
#include "../../applicator/comparator/equality/prefix_equality_comparator.c"
#include "../../applicator/comparator/equality/suffix_equality_comparator.c"
#include "../../globals/constants/boolean/boolean_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Compares if the left parameter is equal to the right parameter.
 *
 * The result parameter's abstraction must be BOOLEAN.
 * The left side- and right side parameters' abstractions have to be equal.
 * They can be one of:
 * - CHARACTER
 * - INTEGER
 * - DOUBLE
 *
 * @param p0 the left side parameter abstraction
 * @param p1 the left side parameter abstraction count
 * @param p2 the left side parameter abstraction size
 * @param p3 the left side parameter model
 * @param p4 the left side parameter model count
 * @param p5 the left side parameter model size
 * @param p6 the left side parameter details
 * @param p7 the left side parameter details count
 * @param p8 the left side parameter details size
 * @param p9 the right side parameter abstraction
 * @param p10 the right side parameter abstraction count
 * @param p11 the right side parameter abstraction size
 * @param p12 the right side parameter model
 * @param p13 the right side parameter model count
 * @param p14 the right side parameter model size
 * @param p15 the right side parameter details
 * @param p16 the right side parameter details count
 * @param p17 the right side parameter details size
 * @param p18 the result parameter abstraction
 * @param p19 the result parameter abstraction count
 * @param p20 the result parameter abstraction size
 * @param p21 the result parameter model
 * @param p22 the result parameter model count
 * @param p23 the result parameter model size
 * @param p24 the result parameter details
 * @param p25 the result parameter details count
 * @param p26 the result parameter details size
 * @param p27 the selection parameter model
 * @param p28 the selection parameter model count
 */
void compare_equal(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14,
    void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20,
    void* p21, void* p22, void* p23,
    void* p24, void* p25, void* p26,
    void* p27, void* p28) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare if left parameter is equal to right parameter.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p27, p28, (void*) COMPARE_ALL_SELECTION_MODEL, (void*) COMPARE_ALL_SELECTION_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_all(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                p9, p10, p11, p12, p13, p14, p15, p16, p17,
                p18, p19, p20, p21, p22, p23, p24, p25, p26);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p27, p28, (void*) COMPARE_PREFIX_SELECTION_MODEL, (void*) COMPARE_PREFIX_SELECTION_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_prefix(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                p9, p10, p11, p12, p13, p14, p15, p16, p17,
                p18, p19, p20, p21, p22, p23, p24, p25, p26);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p27, p28, (void*) COMPARE_SUFFIX_SELECTION_MODEL, (void*) COMPARE_SUFFIX_SELECTION_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_suffix(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                p9, p10, p11, p12, p13, p14, p15, p16, p17,
                p18, p19, p20, p21, p22, p23, p24, p25, p26);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p27, p28, (void*) COMPARE_PART_SELECTION_MODEL, (void*) COMPARE_PART_SELECTION_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_part(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                p9, p10, p11, p12, p13, p14, p15, p16, p17,
                p18, p19, p20, p21, p22, p23, p24, p25, p26);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare if left parameter is equal to right parameter. The selection parameter model is unknown.");
    }
}

/* EQUALITY_COMPARATOR_SOURCE */
#endif
