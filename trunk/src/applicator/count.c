/*
 * $RCSfile: count.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.28 $ $Date: 2008-05-04 00:18:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_SOURCE
#define COUNT_SOURCE

#include "../applicator/count/count_all.c"
#include "../applicator/count/count_prefix.c"
#include "../applicator/count/count_suffix.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/array.c"
#include "../memoriser/communicator.c"
#include "../memoriser/converter.c"

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
void count(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Count compound parts.");

    // The compound name, abstraction, model, details.
    void** cn = NULL_POINTER;
    void** cnc = NULL_POINTER;
    void** cns = NULL_POINTER;
    void** ca = NULL_POINTER;
    void** cac = NULL_POINTER;
    void** cas = NULL_POINTER;
    void** cm = NULL_POINTER;
    void** cmc = NULL_POINTER;
    void** cms = NULL_POINTER;
    void** cd = NULL_POINTER;
    void** cdc = NULL_POINTER;
    void** cds = NULL_POINTER;
    // The selection name, abstraction, model, details.
    void** sn = NULL_POINTER;
    void** snc = NULL_POINTER;
    void** sns = NULL_POINTER;
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;
    // The filter name, abstraction, model, details.
    void** fn = NULL_POINTER;
    void** fnc = NULL_POINTER;
    void** fns = NULL_POINTER;
    void** fa = NULL_POINTER;
    void** fac = NULL_POINTER;
    void** fas = NULL_POINTER;
    void** fm = NULL_POINTER;
    void** fmc = NULL_POINTER;
    void** fms = NULL_POINTER;
    void** fd = NULL_POINTER;
    void** fdc = NULL_POINTER;
    void** fds = NULL_POINTER;
    // The result name, abstraction, model, details.
    void** rn = NULL_POINTER;
    void** rnc = NULL_POINTER;
    void** rns = NULL_POINTER;
    void** ra = NULL_POINTER;
    void** rac = NULL_POINTER;
    void** ras = NULL_POINTER;
    void** rm = NULL_POINTER;
    void** rmc = NULL_POINTER;
    void** rms = NULL_POINTER;
    void** rd = NULL_POINTER;
    void** rdc = NULL_POINTER;
    void** rds = NULL_POINTER;

    // Get compound.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COUNT_COMPOUND_NAME, (void*) COUNT_COMPOUND_NAME_COUNT,
        (void*) &cn, (void*) &cnc, (void*) &cns,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);
    // Get selection.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COUNT_SELECTION_NAME, (void*) COUNT_SELECTION_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);
    // Get filter.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COUNT_FILTER_NAME, (void*) COUNT_FILTER_NAME_COUNT,
        (void*) &fn, (void*) &fnc, (void*) &fns,
        (void*) &fa, (void*) &fac, (void*) &fas,
        (void*) &fm, (void*) &fmc, (void*) &fms,
        (void*) &fd, (void*) &fdc, (void*) &fds,
        p2, p3);
    // Get result.
    get_universal_compound_element_by_name(p0, p1,
        (void*) COUNT_RESULT_NAME, (void*) COUNT_RESULT_NAME_COUNT,
        (void*) &rn, (void*) &rnc, (void*) &rns,
        (void*) &ra, (void*) &rac, (void*) &ras,
        (void*) &rm, (void*) &rmc, (void*) &rms,
        (void*) &rd, (void*) &rdc, (void*) &rds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) COUNT_ALL_SELECTION_MODEL, (void*) COUNT_ALL_SELECTION_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            count_all(rm, *rmc, *rms, *cm, *cmc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) COUNT_PREFIX_SELECTION_MODEL, (void*) COUNT_PREFIX_SELECTION_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            count_prefix(rm, *rmc, *rms, *cm, *cmc, *fm, *fmc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) COUNT_SUFFIX_SELECTION_MODEL, (void*) COUNT_SUFFIX_SELECTION_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            count_suffix(rm, *rmc, *rms, *cm, *cmc, *fm, *fmc);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) L"Could not count compound parts. The selection model is unknown.");
    }
}

/* COUNT_SOURCE */
#endif
