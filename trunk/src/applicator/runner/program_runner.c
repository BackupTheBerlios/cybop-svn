/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: program_runner.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROGRAM_RUNNER_SOURCE
#define PROGRAM_RUNNER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/run/program_run_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../variable/reallocation_factor.c"

/**
 * Runs a program.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_program(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Run program command.");

    // The program name, abstraction, model, details.
    void** programn = NULL_POINTER_MEMORY_MODEL;
    void** programnc = NULL_POINTER_MEMORY_MODEL;
    void** programns = NULL_POINTER_MEMORY_MODEL;
    void** programa = NULL_POINTER_MEMORY_MODEL;
    void** programac = NULL_POINTER_MEMORY_MODEL;
    void** programas = NULL_POINTER_MEMORY_MODEL;
    void** programm = NULL_POINTER_MEMORY_MODEL;
    void** programmc = NULL_POINTER_MEMORY_MODEL;
    void** programms = NULL_POINTER_MEMORY_MODEL;
    void** programd = NULL_POINTER_MEMORY_MODEL;
    void** programdc = NULL_POINTER_MEMORY_MODEL;
    void** programds = NULL_POINTER_MEMORY_MODEL;

    // Get program option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) PROGRAM_RUN_OPERATION_CYBOL_NAME, (void*) PROGRAM_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &programn, (void*) &programnc, (void*) &programns,
        (void*) &programa, (void*) &programac, (void*) &programas,
        (void*) &programm, (void*) &programmc, (void*) &programms,
        (void*) &programd, (void*) &programdc, (void*) &programds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    // Append command.
    append((void*) &arg, (void*) &argc, (void*) &args, *programm, *programmc, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
}

/* PROGRAM_RUNNER_SOURCE */
#endif
