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
 * @version $RCSfile: copying_filer.c,v $ $Revision: 1.4 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COPYING_FILER_SOURCE
#define COPYING_FILER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/command_option/unix/copy_unix_command_option_name.c"
#include "../../constant/name/cybol/operation/file/copy_file_operation_cybol_name.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/**
 * Copies the file resource.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void file_copying(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Copy file resource.");

    // The recursive name, abstraction, model, details.
    void** recursiven = NULL_POINTER_MEMORY_MODEL;
    void** recursivenc = NULL_POINTER_MEMORY_MODEL;
    void** recursivens = NULL_POINTER_MEMORY_MODEL;
    void** recursivea = NULL_POINTER_MEMORY_MODEL;
    void** recursiveac = NULL_POINTER_MEMORY_MODEL;
    void** recursiveas = NULL_POINTER_MEMORY_MODEL;
    int** recursivem = (int**) NULL_POINTER_MEMORY_MODEL;
    void** recursivemc = NULL_POINTER_MEMORY_MODEL;
    void** recursivems = NULL_POINTER_MEMORY_MODEL;
    void** recursived = NULL_POINTER_MEMORY_MODEL;
    void** recursivedc = NULL_POINTER_MEMORY_MODEL;
    void** recursiveds = NULL_POINTER_MEMORY_MODEL;
    // The source name, abstraction, model, details.
    void** sourcen = NULL_POINTER_MEMORY_MODEL;
    void** sourcenc = NULL_POINTER_MEMORY_MODEL;
    void** sourcens = NULL_POINTER_MEMORY_MODEL;
    void** sourcea = NULL_POINTER_MEMORY_MODEL;
    void** sourceac = NULL_POINTER_MEMORY_MODEL;
    void** sourceas = NULL_POINTER_MEMORY_MODEL;
    int** sourcem = (int**) NULL_POINTER_MEMORY_MODEL;
    void** sourcemc = NULL_POINTER_MEMORY_MODEL;
    void** sourcems = NULL_POINTER_MEMORY_MODEL;
    void** sourced = NULL_POINTER_MEMORY_MODEL;
    void** sourcedc = NULL_POINTER_MEMORY_MODEL;
    void** sourceds = NULL_POINTER_MEMORY_MODEL;
    // The destination name, abstraction, model, details.
    void** destinationn = NULL_POINTER_MEMORY_MODEL;
    void** destinationnc = NULL_POINTER_MEMORY_MODEL;
    void** destinationns = NULL_POINTER_MEMORY_MODEL;
    void** destinationa = NULL_POINTER_MEMORY_MODEL;
    void** destinationac = NULL_POINTER_MEMORY_MODEL;
    void** destinationas = NULL_POINTER_MEMORY_MODEL;
    int** destinationm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** destinationmc = NULL_POINTER_MEMORY_MODEL;
    void** destinationms = NULL_POINTER_MEMORY_MODEL;
    void** destinationd = NULL_POINTER_MEMORY_MODEL;
    void** destinationdc = NULL_POINTER_MEMORY_MODEL;
    void** destinationds = NULL_POINTER_MEMORY_MODEL;

    // Get recursive option.
    get_universal_compound_element_by_name(
        (void*) &recursiven, (void*) &recursivenc, (void*) &recursivens,
        (void*) &recursivea, (void*) &recursiveac, (void*) &recursiveas,
        (void*) &recursivem, (void*) &recursivemc, (void*) &recursivems,
        (void*) &recursived, (void*) &recursivedc, (void*) &recursiveds,
        p0, p1,
        (void*) RECURSIVE_COPY_FILE_OPERATION_CYBOL_NAME, (void*) RECURSIVE_COPY_FILE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get source option.
    get_universal_compound_element_by_name(
        (void*) &sourcen, (void*) &sourcenc, (void*) &sourcens,
        (void*) &sourcea, (void*) &sourceac, (void*) &sourceas,
        (void*) &sourcem, (void*) &sourcemc, (void*) &sourcems,
        (void*) &sourced, (void*) &sourcedc, (void*) &sourceds,
        p0, p1,
        (void*) SOURCE_COPY_FILE_OPERATION_CYBOL_NAME, (void*) SOURCE_COPY_FILE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get destination option.
    get_universal_compound_element_by_name(
        (void*) &destinationn, (void*) &destinationnc, (void*) &destinationns,
        (void*) &destinationa, (void*) &destinationac, (void*) &destinationas,
        (void*) &destinationm, (void*) &destinationmc, (void*) &destinationms,
        (void*) &destinationd, (void*) &destinationdc, (void*) &destinationds,
        p0, p1,
        (void*) DESTINATION_COPY_FILE_OPERATION_CYBOL_NAME, (void*) DESTINATION_COPY_FILE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Append command.
    overwrite_array((void*) &arg, (void*) COPY_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) COPY_UNIX_COMMAND_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);

    if (*recursivem != *NULL_POINTER_MEMORY_MODEL) {

        if (**recursivem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Append recursive option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);
            overwrite_array((void*) &arg, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);
        }
    }

    if (*sourcem != *NULL_POINTER_MEMORY_MODEL) {

        if (**sourcem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Append source option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);
            overwrite_array((void*) &arg, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);
        }
    }

    if (*destinationm != *NULL_POINTER_MEMORY_MODEL) {

        if (**destinationm == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Append source option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);
            overwrite_array((void*) &arg, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &argc, (void*) &args);
        }
    }

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* COPYING_FILER_SOURCE */
#endif
