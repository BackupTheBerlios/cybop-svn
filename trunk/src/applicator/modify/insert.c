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

#ifndef INSERT_SOURCE
#define INSERT_SOURCE

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
 * Inserts the source- into the destination part.
 *
 * Expected parameters:
 * - destination (required): the destination part
 * - source (required): the source part
 * - abstraction (required): the type of data
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be inserted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start copying elements to
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_insert(void* p0, int* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply insert.");

    // The destination part.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    // The source part.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The abstraction part.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The count part.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The destination index part.
    void* di = *NULL_POINTER_MEMORY_MODEL;
    // The source index part.
    void* si = *NULL_POINTER_MEMORY_MODEL;

    // The source part model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    // The abstraction part model.
    void* am = *NULL_POINTER_MEMORY_MODEL;
    // The count part model.
    void* cm = *NULL_POINTER_MEMORY_MODEL;
    // The destination index part model.
    void* dim = *NULL_POINTER_MEMORY_MODEL;
    // The source index part model.
    void* sim = *NULL_POINTER_MEMORY_MODEL;

    // The source part model count.
    void* smc = *NULL_POINTER_MEMORY_MODEL;
    // The abstraction part model data.
    void* amd = *NULL_POINTER_MEMORY_MODEL;
    // The count part model data.
    void* cmd = *NULL_POINTER_MEMORY_MODEL;
    // The destination index part model data.
    void* dimd = *NULL_POINTER_MEMORY_MODEL;
    // The source index part model data.
    void* simd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination part.
    get_name_array((void*) &d, p0, (void*) DESTINATION_OVERWRITE_OPERATION_CYBOL_NAME, (void*) DESTINATION_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get source part.
    get_name_array((void*) &s, p0, (void*) SOURCE_OVERWRITE_OPERATION_CYBOL_NAME, (void*) SOURCE_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get abstraction part.
    get_name_array((void*) &a, p0, (void*) ABSTRACTION_OVERWRITE_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get count part.
    get_name_array((void*) &c, p0, (void*) COUNT_OVERWRITE_OPERATION_CYBOL_NAME, (void*) COUNT_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get destination index part.
    get_name_array((void*) &di, p0, (void*) DESTINATION_INDEX_OVERWRITE_OPERATION_CYBOL_NAME, (void*) DESTINATION_INDEX_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get source index part.
    get_name_array((void*) &si, p0, (void*) SOURCE_INDEX_OVERWRITE_OPERATION_CYBOL_NAME, (void*) SOURCE_INDEX_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get source part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get abstraction part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get count part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get destination index part model.
    copy_array_forward((void*) &dim, di, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get source index part model.
    copy_array_forward((void*) &sim, si, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get source part model count.
    copy_array_forward((void*) &smc, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get abstraction part model data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get count part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get destination index part model data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get source index part model data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int destination_index = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int source_index = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit destination index that was given as parametre.
    copy_integer((void*) &destination_index, dimd);
    // Use the explicit source index that was given as parametre.
    copy_integer((void*) &source_index, simd);

    // Insert the source- into the destination part.
    insert_part(d, s, amd, (void*) &count, (void*) &destination_index, (void*) &source_index);
}

/* INSERT_SOURCE */
#endif
