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
 * @version $RCSfile: detector.c,v $ $Revision: 1.3 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POSITION_MOVER_SOURCE
#define POSITION_MOVER_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/calculator/integer_adder/pointer_integer_adder.c"
#include "../../../executor/calculator/integer_multiplier/integer_integer_multiplier.c"
#include "../../../executor/calculator/integer_subtracter/integer_integer_subtracter.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

/**
 * Moves the current parsing position by element count
 * and also adapts the remaining element count.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the abstraction
 * @param p3 the count
 */
void move_position(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Move position.");

    // The memory area.
    int m = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    determine_size((void*) &m, p2);
    // Calculate memory area.
    multiply_integer_with_integer((void*) &m, p3);
    // Add memory area to current position.
    add_integer_to_pointer(p0, (void*) &m);
    // Subtract count from remaining count.
    subtract_integer_from_integer(p1, p3);
}

/* POSITION_MOVER_SOURCE */
#endif
