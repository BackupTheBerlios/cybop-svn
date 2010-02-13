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
 * @version $RCSfile: counting_memoriser.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNTING_MEMORISER_SOURCE
#define COUNTING_MEMORISER_SOURCE

#include "../../applicator/memoriser/counting/all_counting_memoriser.c"
#include "../../applicator/memoriser/counting/prefix_counting_memoriser.c"
#include "../../applicator/memoriser/counting/suffix_counting_memoriser.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/cybol/count_selection_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/count_memory_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"

/**
 * Counts compound parts.
 *
 * Expected parameters:
 * - compound (required): the compound whose parts are to be counted
 * - selection (required): the kind of filter to be applied for counting the compound's parts
 * - filter (required): the filter to compare the compound parts' names with;
 *   only those parts will be counted whose name (full, prefix, suffix, part) matches the filter string
 * - result (required): the knowledge model in which to store the result
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void memorise_counting(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Count compound parts.");

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
    // The selection name, abstraction, model, details.
    void** sn = NULL_POINTER_MEMORY_MODEL;
    void** snc = NULL_POINTER_MEMORY_MODEL;
    void** sns = NULL_POINTER_MEMORY_MODEL;
    void** sa = NULL_POINTER_MEMORY_MODEL;
    void** sac = NULL_POINTER_MEMORY_MODEL;
    void** sas = NULL_POINTER_MEMORY_MODEL;
    void** sm = NULL_POINTER_MEMORY_MODEL;
    void** smc = NULL_POINTER_MEMORY_MODEL;
    void** sms = NULL_POINTER_MEMORY_MODEL;
    void** sd = NULL_POINTER_MEMORY_MODEL;
    void** sdc = NULL_POINTER_MEMORY_MODEL;
    void** sds = NULL_POINTER_MEMORY_MODEL;
    // The filter name, abstraction, model, details.
    void** fn = NULL_POINTER_MEMORY_MODEL;
    void** fnc = NULL_POINTER_MEMORY_MODEL;
    void** fns = NULL_POINTER_MEMORY_MODEL;
    void** fa = NULL_POINTER_MEMORY_MODEL;
    void** fac = NULL_POINTER_MEMORY_MODEL;
    void** fas = NULL_POINTER_MEMORY_MODEL;
    void** fm = NULL_POINTER_MEMORY_MODEL;
    void** fmc = NULL_POINTER_MEMORY_MODEL;
    void** fms = NULL_POINTER_MEMORY_MODEL;
    void** fd = NULL_POINTER_MEMORY_MODEL;
    void** fdc = NULL_POINTER_MEMORY_MODEL;
    void** fds = NULL_POINTER_MEMORY_MODEL;
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
        (void*) COMPOUND_MEMORY_MODEL_COUNT_FLOW_OPERATION_CYBOL_NAME, (void*) COMPOUND_MEMORY_MODEL_COUNT_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);
    // Get selection.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SELECTION_COUNT_FLOW_OPERATION_CYBOL_NAME, (void*) SELECTION_COUNT_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);
    // Get filter.
    get_universal_compound_element_by_name(p0, p1,
        (void*) FILTER_COUNT_FLOW_OPERATION_CYBOL_NAME, (void*) FILTER_COUNT_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &fn, (void*) &fnc, (void*) &fns,
        (void*) &fa, (void*) &fac, (void*) &fas,
        (void*) &fm, (void*) &fmc, (void*) &fms,
        (void*) &fd, (void*) &fdc, (void*) &fds,
        p2, p3);
    // Get result.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RESULT_COUNT_FLOW_OPERATION_CYBOL_NAME, (void*) RESULT_COUNT_FLOW_OPERATION_CYBOL_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) ALL_COUNT_SELECTION_CYBOL_MODEL, (void*) ALL_COUNT_SELECTION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_counting_all(rm, *rmc, *rms, *cm, *cmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) PREFIX_COUNT_SELECTION_CYBOL_MODEL, (void*) PREFIX_COUNT_SELECTION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_counting_prefix(rm, *rmc, *rms, *cm, *cmc, *fm, *fmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) SUFFIX_COUNT_SELECTION_CYBOL_MODEL, (void*) SUFFIX_COUNT_SELECTION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_counting_suffix(rm, *rmc, *rms, *cm, *cmc, *fm, *fmc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not count compound parts. The selection model is unknown.");
    }
}

/* COUNTING_MEMORISER_SOURCE */
#endif
