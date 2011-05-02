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

#ifndef OFFSET_ARRAY_COMPARATOR_SOURCE
#define OFFSET_ARRAY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/comparator/array_comparator.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Compares left and right array, starting from the given offset.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the count
 * @param p6 the index
 */
void compare_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array offset.");

    // The offset (memory area).
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    determine_size((void*) &o, p4);

    // Calculate offset.
    multiply_with_integer((void*) &o, p6, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // The left array, right array.
    // CAUTION! They HAVE TO BE initialised with p1 and p2,
    // since an offset is added below.
    void* la = p1;
    void* ra = p2;

    // Add offset to left array, right array.
    add_integer((void*) &la, (void*) &o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    add_integer((void*) &ra, (void*) &o, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    compare_array(p0, la, ra, p3, p4, p5);
}

/* OFFSET_ARRAY_COMPARATOR_SOURCE */
#endif
