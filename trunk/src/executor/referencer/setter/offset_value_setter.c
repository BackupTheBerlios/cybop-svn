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

#ifndef OFFSET_VALUE_SETTER_SOURCE
#define OFFSET_VALUE_SETTER_SOURCE

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
 * Sets the source- to the destination value
 * using the given index to calculate an offset.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the index
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void set_value_offset(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set value offset.");

    // The offset.
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine abstraction (type) size.
    determine_size_NEW((void*) &o, p3, p4);

    // Calculate offset (memory area).
    multiply_with_integer((void*) &o, p2, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Determine destination.
    void* d = p0 + o;
    // Determine source.
    void* s = p1 + o;

    // Set source- to destination value (memory area).
    set_value(d, s, p3, p4);
}

/* OFFSET_VALUE_SETTER_SOURCE */
#endif
