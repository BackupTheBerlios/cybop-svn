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

#ifndef COPYING_MEMORISER_SOURCE
#define COPYING_MEMORISER_SOURCE

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
#include "../../executor/comparator/count_array_comparator.c"
#include "../../logger/logger.c"

/**
 * Copies a primitive model.
 *
 * Expected parameters:
 * - abstraction (required): the type of data
 * - source (required): the source value
 * - destination (required): the destination value
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void memorise_copying(void* p0, int* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Copy primitive model.");

    // The source name, abstraction, model, details.
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
    // The destination name, abstraction, model, details.
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
    // The abstraction name, abstraction, model, details.
    void** an = NULL_POINTER_MEMORY_MODEL;
    void** anc = NULL_POINTER_MEMORY_MODEL;
    void** ans = NULL_POINTER_MEMORY_MODEL;
    void** aa = NULL_POINTER_MEMORY_MODEL;
    void** aac = NULL_POINTER_MEMORY_MODEL;
    void** aas = NULL_POINTER_MEMORY_MODEL;
    void** am = NULL_POINTER_MEMORY_MODEL;
    void** amc = NULL_POINTER_MEMORY_MODEL;
    void** ams = NULL_POINTER_MEMORY_MODEL;
    void** ad = NULL_POINTER_MEMORY_MODEL;
    void** adc = NULL_POINTER_MEMORY_MODEL;
    void** ads = NULL_POINTER_MEMORY_MODEL;

    // Get source.
    get_universal_compound_element_by_name(
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p0, p1,
        (void*) SOURCE_COPY_TRANSFER_OPERATION_CYBOL_NAME, (void*) SOURCE_COPY_TRANSFER_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get destination.
    get_universal_compound_element_by_name(
        (void*) &dn, (void*) &dnc, (void*) &dns,
        (void*) &da, (void*) &dac, (void*) &das,
        (void*) &dm, (void*) &dmc, (void*) &dms,
        (void*) &dd, (void*) &ddc, (void*) &dds,
        p0, p1,
        (void*) DESTINATION_COPY_TRANSFER_OPERATION_CYBOL_NAME, (void*) DESTINATION_COPY_TRANSFER_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get abstraction.
    get_universal_compound_element_by_name(
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p0, p1,
        (void*) ABSTRACTION_COPY_TRANSFER_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_COPY_TRANSFER_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, *am, *amc, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_copying_boolean(dm, *dmc, *dms, *sm, *smc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, *am, *amc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_copying_character_vector(dm, *dmc, *dms, *sm, *smc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_count((void*) &r, *am, *amc, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise_copying_integer_vector(dm, *dmc, *dms, *sm, *smc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not copy primitive model. The abstraction model is unknown.");
    }
}

/* COPYING_MEMORISER_SOURCE */
#endif
