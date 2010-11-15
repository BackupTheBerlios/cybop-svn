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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_REPLACER_SOURCE
#define COMPOUND_REPLACER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/compound_memory_name.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Replaces the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void replace_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace compound element by name.");
//??    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) (char*) p6);

/*??
    // The element name index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Get compound element index.
    //
    // CAUTION! The name is given WITHOUT prefix here!
    // Correct example: "patient"
    // Incorrect examples: ".patient", "#patient"
    get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

//??    fwprintf(stdout, L"TEST part index %i\n", i);

    if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not replace compound element by name. A compound element with that name does already exist.");

    } else {

        // Could not get compound element index. An element with that name does not exist.
        // Therefore, add compound element by name.
        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add compound model element by name.");
        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) (char*) e);

        // CAUTION! Use compound count as index for adding new elements.
        // CAUTION! Do NOT use e, ec and es as name parameters!
        // These were created only locally in this procedure and
        // will thus be destroyed when the procedure is left.
        // DO USE the name, name count and name size that were
        // handed over as parameters to this procedure!
        // They were allocated by a translator while parsing CYBOL files.
        set_compound_element_by_index(p0, p1, p2, p1, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
    }
*/
}

/* COMPOUND_REPLACER_SOURCE */
#endif
