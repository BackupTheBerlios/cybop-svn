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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_SETTER_SOURCE
#define COMPOUND_SETTER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/model_memory_name.c"
#include "../../../executor/comparator/count_array_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sets the source part to the destination compound at position index.
 *
 * CAUTION! The destination already HAS TO EXIST and has to have a NAME.
 * The source name is NOT copied into the destination name.
 *
 * CAUTION! The size of the destination model has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination compound
 * @param p1 the source part
 * @param p2 the destination index
 */
void set_compound_part(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set compound part.");

    // The destination names, abstractions, models, details.
    void* dn = *NULL_POINTER_MEMORY_MODEL;
    void* da = *NULL_POINTER_MEMORY_MODEL;
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
/*??
    // The source name, abstraction, model, details.
    void* sn = *NULL_POINTER_MEMORY_MODEL;
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;
*/

    // Get destination names, abstractions, models, details.
    get_item((void*) &dn, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NAMES_COMPOUND_MEMORY_NAME_NEW);
    get_item((void*) &da, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME_NEW);
    get_item((void*) &dm, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) MODELS_COMPOUND_MEMORY_NAME_NEW);
    get_item((void*) &dd, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) DETAILS_COMPOUND_MEMORY_NAME_NEW);
/*??
    // Get source name, abstraction, model, details.
    get_item((void*) &sn, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NAME_PART_MEMORY_NAME);
    get_item((void*) &sa, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ABSTRACTION_PART_MEMORY_NAME);
    get_item((void*) &sm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) MODEL_PART_MEMORY_NAME);
    get_item((void*) &sd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) DETAILS_PART_MEMORY_NAME);
*/

    // Set source part to destination compound.
    set_item(dn, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) NAME_PART_MEMORY_NAME);
    set_item(da, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) ABSTRACTION_PART_MEMORY_NAME);
    set_item(dm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) MODEL_PART_MEMORY_NAME);
    set_item(dd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) DETAILS_PART_MEMORY_NAME);
/*??
    // Set source part to destination compound.
    set_item(dn, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
    set_item(da, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
    set_item(dm, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
    set_item(dd, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
*/
}

/* COMPOUND_SETTER_SOURCE */
#endif
