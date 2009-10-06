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
 * @version $RCSfile: archiving_filer.c,v $ $Revision: 1.4 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARCHIVING_FILER_SOURCE
#define ARCHIVING_FILER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/file/archive_file_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../memoriser/allocator/pointer_vector_allocator.c"
#include "../../variable/reallocation_factor.c"

/**
 * Archives the given data into a file.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void file_archiving(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Archive data into a file.");

    // The create name, abstraction, model, details.
    void** createn = NULL_POINTER_MEMORY_MODEL;
    void** createnc = NULL_POINTER_MEMORY_MODEL;
    void** createns = NULL_POINTER_MEMORY_MODEL;
    void** createa = NULL_POINTER_MEMORY_MODEL;
    void** createac = NULL_POINTER_MEMORY_MODEL;
    void** createas = NULL_POINTER_MEMORY_MODEL;
    int** createm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** createmc = NULL_POINTER_MEMORY_MODEL;
    void** createms = NULL_POINTER_MEMORY_MODEL;
    void** created = NULL_POINTER_MEMORY_MODEL;
    void** createdc = NULL_POINTER_MEMORY_MODEL;
    void** createds = NULL_POINTER_MEMORY_MODEL;
    // The update name, abstraction, model, details.
    void** updaten = NULL_POINTER_MEMORY_MODEL;
    void** updatenc = NULL_POINTER_MEMORY_MODEL;
    void** updatens = NULL_POINTER_MEMORY_MODEL;
    void** updatea = NULL_POINTER_MEMORY_MODEL;
    void** updateac = NULL_POINTER_MEMORY_MODEL;
    void** updateas = NULL_POINTER_MEMORY_MODEL;
    int** updatem = (int**) NULL_POINTER_MEMORY_MODEL;
    void** updatemc = NULL_POINTER_MEMORY_MODEL;
    void** updatems = NULL_POINTER_MEMORY_MODEL;
    void** updated = NULL_POINTER_MEMORY_MODEL;
    void** updatedc = NULL_POINTER_MEMORY_MODEL;
    void** updateds = NULL_POINTER_MEMORY_MODEL;
    // The bzip2 name, abstraction, model, details.
    void** bzip2n = NULL_POINTER_MEMORY_MODEL;
    void** bzip2nc = NULL_POINTER_MEMORY_MODEL;
    void** bzip2ns = NULL_POINTER_MEMORY_MODEL;
    void** bzip2a = NULL_POINTER_MEMORY_MODEL;
    void** bzip2ac = NULL_POINTER_MEMORY_MODEL;
    void** bzip2as = NULL_POINTER_MEMORY_MODEL;
    int** bzip2m = (int**) NULL_POINTER_MEMORY_MODEL;
    void** bzip2mc = NULL_POINTER_MEMORY_MODEL;
    void** bzip2ms = NULL_POINTER_MEMORY_MODEL;
    void** bzip2d = NULL_POINTER_MEMORY_MODEL;
    void** bzip2dc = NULL_POINTER_MEMORY_MODEL;
    void** bzip2ds = NULL_POINTER_MEMORY_MODEL;

    // Get create option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &createn, (void*) &createnc, (void*) &createns,
        (void*) &createa, (void*) &createac, (void*) &createas,
        (void*) &createm, (void*) &createmc, (void*) &createms,
        (void*) &created, (void*) &createdc, (void*) &createds,
        p2, p3);

    // Get update option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &updaten, (void*) &updatenc, (void*) &updatens,
        (void*) &updatea, (void*) &updateac, (void*) &updateas,
        (void*) &updatem, (void*) &updatemc, (void*) &updatems,
        (void*) &updated, (void*) &updatedc, (void*) &updateds,
        p2, p3);

    // Get bzip2 option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &bzip2n, (void*) &bzip2nc, (void*) &bzip2ns,
        (void*) &bzip2a, (void*) &bzip2ac, (void*) &bzip2as,
        (void*) &bzip2m, (void*) &bzip2mc, (void*) &bzip2ms,
        (void*) &bzip2d, (void*) &bzip2dc, (void*) &bzip2ds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    // Append command.
    append((void*) &arg, (void*) &argc, (void*) &args, (void*) ARCHIVE_UNIX_COMMAND_MODEL, (void*) ARCHIVE_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);

    if (*createm != *NULL_POINTER_MEMORY_MODEL) {

        if (**createm == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Append create option.
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
        }
    }

    if (*updatem != *NULL_POINTER_MEMORY_MODEL) {

        if (**updatem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Append update option.
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
        }
    }

    if (*bzip2m != *NULL_POINTER_MEMORY_MODEL) {

        if (**bzip2m == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Append bzip2 option.
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
            append((void*) &arg, (void*) &argc, (void*) &args, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
        }
    }

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION);
}

/* ARCHIVING_FILER_SOURCE */
#endif
