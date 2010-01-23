/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: building_memoriser.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUILDING_MEMORISER_SOURCE
#define BUILDING_MEMORISER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/build_memory_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/allocator.c"

/**
 * Builds a list name.
 *
 * Expected parameters:
 * - ?? (required): ?? (description)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void memorise_building(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Build list name.");

    // The basisname name, abstraction, model, details.
    void** bnn = NULL_POINTER_MEMORY_MODEL;
    void** bnnc = NULL_POINTER_MEMORY_MODEL;
    void** bnns = NULL_POINTER_MEMORY_MODEL;
    void** bna = NULL_POINTER_MEMORY_MODEL;
    void** bnac = NULL_POINTER_MEMORY_MODEL;
    void** bnas = NULL_POINTER_MEMORY_MODEL;
    void** bnm = NULL_POINTER_MEMORY_MODEL;
    void** bnmc = NULL_POINTER_MEMORY_MODEL;
    void** bnms = NULL_POINTER_MEMORY_MODEL;
    void** bnd = NULL_POINTER_MEMORY_MODEL;
    void** bndc = NULL_POINTER_MEMORY_MODEL;
    void** bnds = NULL_POINTER_MEMORY_MODEL;
    // The index name, abstraction, model, details.
    void** idxn = NULL_POINTER_MEMORY_MODEL;
    void** idxnc = NULL_POINTER_MEMORY_MODEL;
    void** idxns = NULL_POINTER_MEMORY_MODEL;
    void** idxa = NULL_POINTER_MEMORY_MODEL;
    void** idxac = NULL_POINTER_MEMORY_MODEL;
    void** idxas = NULL_POINTER_MEMORY_MODEL;
    void** idxm = NULL_POINTER_MEMORY_MODEL;
    void** idxmc = NULL_POINTER_MEMORY_MODEL;
    void** idxms = NULL_POINTER_MEMORY_MODEL;
    void** idxd = NULL_POINTER_MEMORY_MODEL;
    void** idxdc = NULL_POINTER_MEMORY_MODEL;
    void** idxds = NULL_POINTER_MEMORY_MODEL;
    // The result name, abstraction, model, details.
    void** resn = NULL_POINTER_MEMORY_MODEL;
    void** resnc = NULL_POINTER_MEMORY_MODEL;
    void** resns = NULL_POINTER_MEMORY_MODEL;
    void** resa = NULL_POINTER_MEMORY_MODEL;
    void** resac = NULL_POINTER_MEMORY_MODEL;
    void** resas = NULL_POINTER_MEMORY_MODEL;
    void** resm = NULL_POINTER_MEMORY_MODEL;
    void** resmc = NULL_POINTER_MEMORY_MODEL;
    void** resms = NULL_POINTER_MEMORY_MODEL;
    void** resd = NULL_POINTER_MEMORY_MODEL;
    void** resdc = NULL_POINTER_MEMORY_MODEL;
    void** resds = NULL_POINTER_MEMORY_MODEL;

    // get the basisname
    get_universal_compound_element_by_name(p0, p1,
        (void*) BASE_BUILD_FLOW_OPERATION_CYBOL_NAME, (void*) BASE_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &bnn, (void*) &bnnc, (void*) &bnns,
        (void*) &bna, (void*) &bnac, (void*) &bnas,
        (void*) &bnm, (void*) &bnmc, (void*) &bnms,
        (void*) &bnd, (void*) &bndc, (void*) &bnds,
        p2, p3);

    // get the index
    get_universal_compound_element_by_name(p0, p1,
        (void*) INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME, (void*) INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &idxn, (void*) &idxnc, (void*) &idxns,
        (void*) &idxa, (void*) &idxac, (void*) &idxas,
        (void*) &idxm, (void*) &idxmc, (void*) &idxms,
        (void*) &idxd, (void*) &idxdc, (void*) &idxds,
        p2, p3);

    // get the result
    get_universal_compound_element_by_name(p0, p1,
        (void*) COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME, (void*) COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &resn, (void*) &resnc, (void*) &resns,
        (void*) &resa, (void*) &resac, (void*) &resas,
        (void*) &resm, (void*) &resmc, (void*) &resms,
        (void*) &resd, (void*) &resdc, (void*) &resds,
        p2, p3);

    //check the abstraction for the operation element
    int comp_res1 = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int comp_res2 = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int comp_res3 = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Create compare string.
    wchar_t* int_string = *NULL_POINTER_MEMORY_MODEL;
    // todo Konstante noch definieren
    int int_string_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int int_string_size = *NUMBER_10_INTEGER_MEMORY_MODEL;

    allocate_array((void*) &int_string, (void*) &int_string_size, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    int_string_count = swprintf(int_string, int_string_size, L"%i", *((int*) *idxm));

    // destination size
    *(int*)*resms = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + int_string_count;
    *(int*)*resmc = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + int_string_count;

    // Reallocate result array.
    reallocate_array(resm, *resms, *resms, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // set the result array
    set_array_elements(*resm, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, *bnm, *bnmc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    set_array_elements(*resm, *bnmc, LIST_SEPARATOR_CYBOL_NAME, LIST_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    int temp_index = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT;

    set_array_elements(*resm, &temp_index, int_string, &int_string_count, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Destroy int_string array.
    deallocate_array((void*) &int_string, (void*) &int_string_size, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/* BUILDING_MEMORISER_SOURCE */
#endif
