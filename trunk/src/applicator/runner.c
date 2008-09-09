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
 * @version $RCSfile: runner.c,v $ $Revision: 1.4 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUNNER_SOURCE
#define RUNNER_SOURCE

#include "../applicator/runner/archiving_runner.c"
#include "../applicator/runner/copying_runner.c"
#include "../applicator/runner/directory_contents_listing_runner.c"
#include "../applicator/runner/program_runner.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/model/cybol/operation/run_operation_cybol_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/name/cybol/operation_cybol_name.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"

/**
 * Runs command on shell.
 *
 * Expected parameters:
 * - type (required): the type of the operation
 * - ... (depending on the type, further parameters may have to be given)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void run(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Run command.");

    // The operation type name, abstraction, model, details.
    void** tn = NULL_POINTER_MEMORY_MODEL;
    void** tnc = NULL_POINTER_MEMORY_MODEL;
    void** tns = NULL_POINTER_MEMORY_MODEL;
    void** ta = NULL_POINTER_MEMORY_MODEL;
    void** tac = NULL_POINTER_MEMORY_MODEL;
    void** tas = NULL_POINTER_MEMORY_MODEL;
    void** tm = NULL_POINTER_MEMORY_MODEL;
    void** tmc = NULL_POINTER_MEMORY_MODEL;
    void** tms = NULL_POINTER_MEMORY_MODEL;
    void** td = NULL_POINTER_MEMORY_MODEL;
    void** tdc = NULL_POINTER_MEMORY_MODEL;
    void** tds = NULL_POINTER_MEMORY_MODEL;

    // Get operation type.
    get_universal_compound_element_by_name(p0, p1,
        (void*) TYPE_OPERATION_CYBOL_NAME, (void*) TYPE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &tn, (void*) &tnc, (void*) &tns,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) ARCHIVE_RUN_OPERATION_CYBOL_MODEL, (void*) ARCHIVE_RUN_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            run_archive(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) COPY_RUN_OPERATION_CYBOL_MODEL, (void*) COPY_RUN_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            run_copy(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) LIST_DIRECTORY_CONTENTS_RUN_OPERATION_CYBOL_MODEL, (void*) LIST_DIRECTORY_CONTENTS_RUN_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            run_list_directory_contents(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) PROGRAM_RUN_OPERATION_CYBOL_MODEL, (void*) PROGRAM_RUN_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            run_program(p0, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not run command. The operation type is unknown.");
    }
}

/* RUNNER_SOURCE */
#endif
