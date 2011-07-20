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

#ifndef PART_COPIER_SOURCE
#define PART_COPIER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../executor/modifier/copier/item_copier.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Allocates a new destination part for the given source part.
 *
 * Copies the source part's name, abstraction, model, details
 * into the destination part.
 *
 * If the source part's abstraction is "part", then the source
 * part model is a pointer array referencing child parts.
 * In this case, ALL children and their children et cetera
 * will be copied to the destination as well (after having
 * allocated the corresponding destination child nodes).
 *
 * This is DEEP COPYING.
 *
 * CAUTION! The size of the destination has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_part(void* p0, void* p1) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part.");

    // The source part name, abstraction, model, details.
    void* sn = *NULL_POINTER_MEMORY_MODEL;
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;
    // The source part elements data, count.
    void* snd = *NULL_POINTER_MEMORY_MODEL;
    void* snc = *NULL_POINTER_MEMORY_MODEL;
    void* sad = *NULL_POINTER_MEMORY_MODEL;
    void* sac = *NULL_POINTER_MEMORY_MODEL;
    void* smd = *NULL_POINTER_MEMORY_MODEL;
    void* smc = *NULL_POINTER_MEMORY_MODEL;
    void* sdd = *NULL_POINTER_MEMORY_MODEL;
    void* sdc = *NULL_POINTER_MEMORY_MODEL;
    // The source part abstraction primitive.
    int sap = NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The destination part.
    void* dp = *NULL_POINTER_MEMORY_MODEL;

/*??
    // Get source part name, abstraction, model, details.
    copy_array_forward((void*) &sn, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &sa, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &sm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &sd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get source name count, abstraction count, model count, details count.
    copy_array_forward((void*) &snd, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &snc, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sad, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sac, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sdd, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sdc, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Decode abstraction.
    decode_abstraction((void*) &sap, sad, sac);

    //?? TODO: Possibly extend function "copy_item" and use it
    // here instead of all the single function calls above!

    // Allocate destination part.
    // CAUTION! Use source part abstraction for allocation!
    allocate_part_NEW((void*) &dp, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &sap);
    // Copy source part content into destination part.
    overwrite_part_element(dp, snd, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, snc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(dp, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(dp, (void*) L"Hello, ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    overwrite_part_element(dp, (void*) L"Hello, ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
--
    copy_array_forward((void*) &snc, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sac, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &sdc, sd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

--
    // The destination name, abstraction, model, details.
    void* dn = *NULL_POINTER_MEMORY_MODEL;
    void* da = *NULL_POINTER_MEMORY_MODEL;
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination name, abstraction, model, details.
    copy_array_forward((void*) &dn, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &da, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &dm, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &dd, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Set source- to destination name, abstraction, model, details.
    copy_item(dn, sn, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, snc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    copy_item(da, sa, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, sac, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    copy_item(dm, sm, sa, smc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    copy_item(dd, sd, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION, sdc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
*/
}

/* PART_COPIER_SOURCE */
#endif
