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
 * @version $RCSfile: copying_memoriser.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REMOVE_SOURCE
#define REMOVE_SOURCE

#include "../../applicator/memoriser/copying/boolean_copying_memoriser.c"
#include "../../applicator/memoriser/copying/character_vector_copying_memoriser.c"
#include "../../applicator/memoriser/copying/integer_vector_copying_memoriser.c"
#include "../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/copy_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Removes count elements from the part.
 *
 * Expected parametres:
 * - part (required): the part
 * - count (optional; if null, ALL elements will be removed):
 *   the number of elements to be removed
 * - index (optional; if null, the index of the LAST element will be used instead):
 *   the index from where to start removing elements from
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_remove(void* p0, int* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply remove.");

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The count part.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The index part.
    void* i = *NULL_POINTER_MEMORY_MODEL;

    // The part abstraction, model.
    void* pa = *NULL_POINTER_MEMORY_MODEL;
    void* pm = *NULL_POINTER_MEMORY_MODEL;
    // The count part model.
    void* cm = *NULL_POINTER_MEMORY_MODEL;
    // The index part model.
    void* im = *NULL_POINTER_MEMORY_MODEL;

    // The part abstraction data, model count.
    void* pad = *NULL_POINTER_MEMORY_MODEL;
    void* pmc = *NULL_POINTER_MEMORY_MODEL;
    // The count part model data.
    void* cmd = *NULL_POINTER_MEMORY_MODEL;
    // The index part model data.
    void* imd = *NULL_POINTER_MEMORY_MODEL;

    // Get part.
    get_name_array((void*) &p, p0, (void*) PART_REMOVE_OPERATION_CYBOL_NAME, (void*) PART_REMOVE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get count part.
    get_name_array((void*) &c, p0, (void*) COUNT_REMOVE_OPERATION_CYBOL_NAME, (void*) COUNT_REMOVE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get index part.
    get_name_array((void*) &i, p0, (void*) INDEX_REMOVE_OPERATION_CYBOL_NAME, (void*) INDEX_REMOVE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get part abstraction, model.
    copy_array_forward((void*) &pa, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get count part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get index part model.
    copy_array_forward((void*) &im, i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get part abstraction data, model count.
    copy_array_forward((void*) &pad, pa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get count part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get index part model data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int index = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the part model count (all elements), by default.
    copy_integer((void*) &count, pmc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the part model's last element index (count - 1), by default.
    copy_integer((void*) &index, pmc);
    subtract_integer_from_integer((void*) &index, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    // Use the explicit index that was given as parametre.
    copy_integer((void*) &index, imd);

    // Remove elements from part.
    remove_part(p, pad, (void*) &count, (void*) &index);
}

/* REMOVE_SOURCE */
#endif
