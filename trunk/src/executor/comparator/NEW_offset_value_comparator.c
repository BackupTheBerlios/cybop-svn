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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OFFSET_VALUE_COMPARATOR_SOURCE
#define OFFSET_VALUE_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../executor/referencer/setter/value_setter.c"
#include "../../logger/logger.c"

/**
 * Compares the left- with the right value
 * using the given index to calculate an offset.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the index
 * @param p4 the operand abstraction
 * @param p5 the operand abstraction count
 * @param p6 the operation abstraction
 * @param p7 the operation abstraction count
 */
void compare_value_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare value offset.");

    // The offset.
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    determine_size_NEW((void*) &o, p4, p5);

    // Calculate offset (memory area).
    multiply_with_integer((void*) &o, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Determine destination.
    void* l = p1 + o;
    // Determine source.
    void* r = p2 + o;

    // Set source- to destination value (memory area).
    compare_value(p0, l, r, p4, p5, p6, p7);
}

/* OFFSET_VALUE_COMPARATOR_SOURCE */
#endif