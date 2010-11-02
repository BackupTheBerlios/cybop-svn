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
 * @version $RCSfile: getting_memoriser.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GETTING_MEMORISER_SOURCE
#define GETTING_MEMORISER_SOURCE

#include "../../applicator/memoriser/getting/abstraction_getting_memoriser.c"
#include "../../applicator/memoriser/getting/name_getting_memoriser.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/cybol/get_description_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/get_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../logger/logger.c"

/**
 * Gets a description (meta information) of the part at the given index.
 *
 * Expected parameters:
 * - compound (required): the compound whose element is to be retrieved
 * - index (required): the index of the element to be retrieved, within the compound
 * - description (required): the kind of data (name, abstraction) to retrieve from the compound's part
 * - result (required): the result knowledge model in which to store the retrieved element
 *
 * CAUTION! Do NOT rename this procedure to "get",
 * as that name is already used by the corresponding executor operation.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void memorise_getting(void* p0, int* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get standard meta information.");

    // The compound name, abstraction, model, details.
    void** cn = NULL_POINTER_MEMORY_MODEL;
    void** cnc = NULL_POINTER_MEMORY_MODEL;
    void** cns = NULL_POINTER_MEMORY_MODEL;
    void** ca = NULL_POINTER_MEMORY_MODEL;
    void** cac = NULL_POINTER_MEMORY_MODEL;
    void** cas = NULL_POINTER_MEMORY_MODEL;
    void** cm = NULL_POINTER_MEMORY_MODEL;
    void** cmc = NULL_POINTER_MEMORY_MODEL;
    void** cms = NULL_POINTER_MEMORY_MODEL;
    void** cd = NULL_POINTER_MEMORY_MODEL;
    void** cdc = NULL_POINTER_MEMORY_MODEL;
    void** cds = NULL_POINTER_MEMORY_MODEL;
    // The index name, abstraction, model, details.
    void** in = NULL_POINTER_MEMORY_MODEL;
    void** inc = NULL_POINTER_MEMORY_MODEL;
    void** ins = NULL_POINTER_MEMORY_MODEL;
    void** ia = NULL_POINTER_MEMORY_MODEL;
    void** iac = NULL_POINTER_MEMORY_MODEL;
    void** ias = NULL_POINTER_MEMORY_MODEL;
    void** im = NULL_POINTER_MEMORY_MODEL;
    void** imc = NULL_POINTER_MEMORY_MODEL;
    void** ims = NULL_POINTER_MEMORY_MODEL;
    void** id = NULL_POINTER_MEMORY_MODEL;
    void** idc = NULL_POINTER_MEMORY_MODEL;
    void** ids = NULL_POINTER_MEMORY_MODEL;
    // The description name, abstraction, model, details.
    void** dn = NULL_POINTER_MEMORY_MODEL;
    void** dnc = NULL_POINTER_MEMORY_MODEL;
    void** dns = NULL_POINTER_MEMORY_MODEL;
    void** da = NULL_POINTER_MEMORY_MODEL;
    void** dac = NULL_POINTER_MEMORY_MODEL;
    void** das = NULL_POINTER_MEMORY_MODEL;
    void** dm = NULL_POINTER_MEMORY_MODEL;
    void** dmc = NULL_POINTER_MEMORY_MODEL;
    void** dms = NULL_POINTER_MEMORY_MODEL;
    void** dd = NULL_POINTER_MEMORY_MODEL;
    void** ddc = NULL_POINTER_MEMORY_MODEL;
    void** dds = NULL_POINTER_MEMORY_MODEL;
    // The result name, abstraction, model, details.
    void** rn = NULL_POINTER_MEMORY_MODEL;
    void** rnc = NULL_POINTER_MEMORY_MODEL;
    void** rns = NULL_POINTER_MEMORY_MODEL;
    void** ra = NULL_POINTER_MEMORY_MODEL;
    void** rac = NULL_POINTER_MEMORY_MODEL;
    void** ras = NULL_POINTER_MEMORY_MODEL;
    void** rm = NULL_POINTER_MEMORY_MODEL;
    void** rmc = NULL_POINTER_MEMORY_MODEL;
    void** rms = NULL_POINTER_MEMORY_MODEL;
    void** rd = NULL_POINTER_MEMORY_MODEL;
    void** rdc = NULL_POINTER_MEMORY_MODEL;
    void** rds = NULL_POINTER_MEMORY_MODEL;

    // Get compound.
    get_universal_compound_element_by_name(
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p0, p1,
        (void*) COMPOUND_GET_FLOW_OPERATION_CYBOL_NAME, (void*) COMPOUND_GET_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get index.
    get_universal_compound_element_by_name(
        (void*) &in, (void*) &inc, (void*) &ins,
        (void*) &ia, (void*) &iac, (void*) &ias,
        (void*) &im, (void*) &imc, (void*) &ims,
        (void*) &id, (void*) &idc, (void*) &ids,
        p0, p1,
        (void*) INDEX_GET_FLOW_OPERATION_CYBOL_NAME, (void*) INDEX_GET_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get description.
    get_universal_compound_element_by_name(
        (void*) &dn, (void*) &dnc, (void*) &dns,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        p0, p1,
        (void*) DESCRIPTION_GET_FLOW_OPERATION_CYBOL_NAME, (void*) DESCRIPTION_GET_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);
    // Get result.
    get_universal_compound_element_by_name(
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p0, p1,
        (void*) RESULT_GET_FLOW_OPERATION_CYBOL_NAME, (void*) RESULT_GET_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, *dm, *dmc, (void*) NAME_GET_DESCRIPTION_CYBOL_MODEL, (void*) NAME_GET_DESCRIPTION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Use references not only for the model, but also for count and size!
            memorise_getting_name((void*) rm, *rmc, *rms, *cm, *cmc, *im, *imc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, *dm, *dmc, (void*) ABSTRACTION_GET_DESCRIPTION_CYBOL_MODEL, (void*) ABSTRACTION_GET_DESCRIPTION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Use references not only for the model, but also for count and size!
            memorise_getting_abstraction((void*) rm, *rmc, *rms, *cm, *cmc, *im, *imc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get standard meta information. The description model is unknown.");
    }
}

/* GETTING_MEMORISER_SOURCE */
#endif
