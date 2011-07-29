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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OFFSET_ADDER_SOURCE
#define OFFSET_ADDER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder/pointer_integer_adder.c"
#include "../../executor/arithmetiser/integer_multiplier/integer_integer_multiplier.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Adds an offset to the given pointer.
 *
 * @param p0 the pointer (Hand over as reference!)
 * @param p1 the abstraction
 * @param p2 the index
 */
void add_offset(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add offset.");

    // The offset (memory area).
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    determine_size((void*) &o, p1);

    // Calculate offset.
    // CAUTION! The POINTER_PRIMITIVE_MEMORY_ABSTRACTION is NOT needed here,
    // since this is only the offset integer value and not a pointer.
    multiply_integer_with_integer((void*) &o, p2);

    // Add offset to pointer.
    // CAUTION! The POINTER_PRIMITIVE_MEMORY_ABSTRACTION IS needed here,
    // since p0 is a pointer to which the offset is added.
    add_integer_to_pointer(p0, (void*) &o);
}

/* OFFSET_ADDER_SOURCE */
#endif
