/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: getting_memoriser.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GETTER_SOURCE
#define GETTER_SOURCE

#include "../applicator/getter/abstraction_getter.c"
#include "../applicator/getter/name_getter.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

/**
 * Gets a description (meta information) of the part at the given index.
 *
 * Expected parameters:
 * - compound (required): the compound whose element is to be retrieved
 * - index (required): the index of the element to be retrieved, within the compound
 * - description (required): the kind of data (name, abstraction) to retrieve from the compound's part
 * - result (required): the result knowledge model in which to store the retrieved element
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void get(void* p0, int* p1, void* p2, void* p3, void* p4) {

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
    get_universal_compound_element_by_name(p0, p1,
        (void*) GET_COMPOUND_NAME, (void*) GET_COMPOUND_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);
    // Get index.
    get_universal_compound_element_by_name(p0, p1,
        (void*) GET_INDEX_NAME, (void*) GET_INDEX_NAME_COUNT,
        (void*) &in, (void*) &inc, (void*) &ins,
        (void*) &ia, (void*) &iac, (void*) &ias,
        (void*) &im, (void*) &imc, (void*) &ims,
        (void*) &id, (void*) &idc, (void*) &ids,
        p2, p3);
    // Get description.
    get_universal_compound_element_by_name(p0, p1,
        (void*) GET_DESCRIPTION_NAME, (void*) GET_DESCRIPTION_NAME_COUNT,
        (void*) &dn, (void*) &dnc, (void*) &dns,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        p2, p3);
    // Get result.
    get_universal_compound_element_by_name(p0, p1,
        (void*) GET_RESULT_NAME, (void*) GET_RESULT_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*dm, *dmc, (void*) GET_NAME_DESCRIPTION_MODEL, (void*) GET_NAME_DESCRIPTION_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Use references not only for the model, but also for count and size!
            get_name((void*) rm, *rmc, *rms, *cm, *cmc, *im, *imc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*dm, *dmc, (void*) GET_ABSTRACTION_DESCRIPTION_MODEL, (void*) GET_ABSTRACTION_DESCRIPTION_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // CAUTION! Use references not only for the model, but also for count and size!
            get_abstraction((void*) rm, *rmc, *rms, *cm, *cmc, *im, *imc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get standard meta information. The description model is unknown.");
    }
}

/* GETTER_SOURCE */
#endif
