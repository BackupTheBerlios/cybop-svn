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

#ifndef OFFSET_VALUE_COPIER_SOURCE
#define OFFSET_VALUE_COPIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_multiplier.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../executor/copier/value_copier.c"
#include "../../logger/logger.c"

/**
 * Copies the source- to the destination value
 * using the given index to calculate an offset.
 *
 * @param p0 the destination value
 * @param p1 the source value
 * @param p2 the operand abstraction
 * @param p3 the destination index
 * @param p4 the source index
 */
void copy_value_offset(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy value offset.");

    // The destination value, source value.
    // CAUTION! They HAVE TO BE initialised with p0 and p1,
    // since an offset is added below.
    void* d = p0;
    void* s = p1;

    // Add offset.
    add_offset((void*) &d, p2, p3);
    add_offset((void*) &s, p2, p4);

    // Set source value to destination value.
    copy_value(d, s, p2);
}

/* OFFSET_VALUE_COPIER_SOURCE */
#endif
