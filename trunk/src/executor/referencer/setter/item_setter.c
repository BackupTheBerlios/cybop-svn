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

#ifndef ITEM_SETTER_SOURCE
#define ITEM_SETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/modifier/assigner.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Sets source count source array elements into the destination array
 * at position index.
 *
 * @param p0 the destination item
 * @param p1 the source item
 * @param p2 the count
 * @param p3 the destination item index
 * @param p4 the abstraction
 */
void set_item(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set item.");

    // The destination data, count.
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    // The source data, count.
    void* sd = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;

    // Get destination data, count.
    get((void*) &dd, p0, (void*) DATA_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &dc, p0, (void*) COUNT_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get source data, count.
    get((void*) &sd, p1, (void*) DATA_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &sc, p1, (void*) COUNT_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // Set source- to destination data.
    set_array(dd, sd, p2, p3, p4);

    // Add source- to destination count.
    add_integer(dc, sc, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* ITEM_SETTER_SOURCE */
#endif
