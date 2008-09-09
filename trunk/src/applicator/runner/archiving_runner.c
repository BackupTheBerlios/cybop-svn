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
 * @version $RCSfile: archiving_runner.c,v $ $Revision: 1.5 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARCHIVE_RUNNER_SOURCE
#define ARCHIVE_RUNNER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/run/archive_run_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../memoriser/allocator/pointer_vector_allocator.c"
#include "../../variable/reallocation_factor.c"

/**
 * Runs the archive command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_archive(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Run archive command.");

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

    // Get bzip2 option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) BZIP2_ARCHIVE_RUN_OPERATION_CYBOL_NAME, (void*) BZIP2_ARCHIVE_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &bzip2n, (void*) &bzip2nc, (void*) &bzip2ns,
        (void*) &bzip2a, (void*) &bzip2ac, (void*) &bzip2as,
        (void*) &bzip2m, (void*) &bzip2mc, (void*) &bzip2ms,
        (void*) &bzip2d, (void*) &bzip2dc, (void*) &bzip2ds,
        p2, p3);

    // Get create option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) CREATE_ARCHIVE_RUN_OPERATION_CYBOL_NAME, (void*) CREATE_ARCHIVE_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &createn, (void*) &createnc, (void*) &createns,
        (void*) &createa, (void*) &createac, (void*) &createas,
        (void*) &createm, (void*) &createmc, (void*) &createms,
        (void*) &created, (void*) &createdc, (void*) &createds,
        p2, p3);

    // Get update option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) UPDATE_ARCHIVE_RUN_OPERATION_CYBOL_NAME, (void*) UPDATE_ARCHIVE_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &updaten, (void*) &updatenc, (void*) &updatens,
        (void*) &updatea, (void*) &updateac, (void*) &updateas,
        (void*) &updatem, (void*) &updatemc, (void*) &updatems,
        (void*) &updated, (void*) &updatedc, (void*) &updateds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine arguments size.
    args = *ARCHIVE_UNIX_COMMAND_MODEL_COUNT;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Assemble arguments by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_COMMAND_MODEL, (void*) ARCHIVE_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    argc = argc + *ARCHIVE_UNIX_COMMAND_MODEL_COUNT;

    //
    // Create option.
    //

    if (*createm != *NULL_POINTER_MEMORY_MODEL) {

        if (**createm == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_COMMAND_MODEL_CREATE, (void*) ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT;
        }
    }

    //
    // Update option.
    //

    if (*updatem != *NULL_POINTER_MEMORY_MODEL) {

        if (**updatem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_COMMAND_MODEL_UPDATE, (void*) ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT;
        }
    }

    //
    // Bzip2 option.
    //

    if (*bzip2m != *NULL_POINTER_MEMORY_MODEL) {

        if (**bzip2m == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_COMMAND_MODEL_BZIP2, (void*) ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT;
        }
    }

    //
    // Null termination.
    //

    // Resize arguments, if necessary.
    // One extra place for null termination character.
    if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT) >= args) {

        // Determine arguments size.
        args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT;

        reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
    }

    // Assemble arguments by adding the null termination character.
    set_array_elements(arg, (void*) &argc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;

    // Execute arguments as process.
    run_execute(arg);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

/*??
    //?? The following block assembles all arguments for using "fork/execv/wait" in "run_execute.c".
    //?? But since "run_execute.c" is using system("program_name"),
    //?? this block has been commented out.
    //?? It may be either reactivated together with "fork/execv/wait"
    //?? in "run_execute.c" or deleted later.

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The system shell as null terminated string.
    void* shell = *NULL_POINTER_MEMORY_MODEL;
    int shellc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int shells = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The character argument as null terminated string.
    void* character = *NULL_POINTER_MEMORY_MODEL;
    int characterc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int characters = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The command as null terminated string.
    void* command = *NULL_POINTER_MEMORY_MODEL;
    int commandc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int commands = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate arguments vector.
    allocate_pointer_vector((void*) &arg, (void*) &args);

    //
    // System shell.
    //

    // Determine shell size.
    shells = *SHELL_SYSTEM_EXECUTABLE_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT;

    // Allocate shell.
    allocate_array((void*) &shell, (void*) &shells, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Assemble shell by first copying the actual shell command
    // and then adding the null termination character.
    set_array_elements(shell, (void*) &shellc, (void*) SHELL_SYSTEM_EXECUTABLE, (void*) SHELL_SYSTEM_EXECUTABLE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    shellc = shellc + *SHELL_SYSTEM_EXECUTABLE_COUNT;
    set_array_elements(shell, (void*) &shellc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    shellc = shellc + *PRIMITIVE_MEMORY_MODEL_COUNT;

    // Increase arguments vector size for shell argument.
    args++;

    //
    // System shell character argument.
    //

    // Determine character argument size.
    characters = *SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT;

    // Allocate character argument.
    allocate_array((void*) &character, (void*) &characters, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Assemble character argument by first copying the actual argument
    // and then adding the null termination character.
    set_array_elements(character, (void*) &characterc, (void*) SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT, (void*) SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    characterc = characterc + *SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT;
    set_array_elements(character, (void*) &characterc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    characterc = characterc + *PRIMITIVE_MEMORY_MODEL_COUNT;

    // Increase arguments vector size for shell character argument.
    args++;

    //
    // Command.
    //

    // Determine command size.
    commands = *ARCHIVE_UNIX_COMMAND_MODEL_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Assemble command by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_COMMAND_MODEL, (void*) ARCHIVE_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    commandc = commandc + *ARCHIVE_UNIX_COMMAND_MODEL_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // Create option.
    //

    if (*createm != *NULL_POINTER_MEMORY_MODEL) {

        if (**createm == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_COMMAND_MODEL_CREATE, (void*) ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *ARCHIVE_UNIX_COMMAND_MODEL_CREATE_COUNT;
        }
    }

    //
    // Update option.
    //

    if (*updatem != *NULL_POINTER_MEMORY_MODEL) {

        if (**updatem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_COMMAND_MODEL_UPDATE, (void*) ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *ARCHIVE_UNIX_COMMAND_MODEL_UPDATE_COUNT;
        }
    }

    //
    // Bzip2 option.
    //

    if (*bzip2m != *NULL_POINTER_MEMORY_MODEL) {

        if (**bzip2m == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_COMMAND_MODEL_BZIP2, (void*) ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *ARCHIVE_UNIX_COMMAND_MODEL_BZIP2_COUNT;
        }
    }

    //
    // Null termination.
    //

    // Resize command, if necessary.
    // One extra place for null termination character.
    if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT) >= commands) {

        // Determine command size.
        commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT;

        reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
    }

    // Assemble command by adding the null termination character.
    set_array_elements(command, (void*) &commandc, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;

    //
    // Null pointer argument.
    //

    // Increase arguments vector size for null pointer argument.
    args++;

    //
    // Assemble arguments vector.
    //

    // Resize arguments vector, if necessary.
    reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);

    // Set shell.
    // CAUTION! The shell command always has to be the first argument.
    set_element(arg, (void*) &argc, (void*) &shell, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    argc++;

    // Set character shell argument.
    set_element(arg, (void*) &argc, (void*) &character, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    argc++;

    // Set command.
    set_element(arg, (void*) &argc, (void*) &command, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    argc++;

    // Set null pointer argument.
    // CAUTION! The null pointer always has to be the last argument.
    set_element(arg, (void*) &argc, NULL_POINTER_MEMORY_MODEL, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    argc++;

    // Execute command as process.
    run_execute(arg);

    if (shell != *NULL_POINTER_MEMORY_MODEL) {

        // Deallocate shell argument.
        deallocate_array((void*) &shell, (void*) &shells, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    }

    if (character != *NULL_POINTER_MEMORY_MODEL) {

        // Deallocate character argument.
        deallocate_array((void*) &character, (void*) &characters, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    }

    if (command != *NULL_POINTER_MEMORY_MODEL) {

        // Deallocate command argument.
        deallocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    }

    // Deallocate arguments vector.
    deallocate_pointer_vector((void*) &arg, (void*) &args);
*/
}

/* ARCHIVE_RUNNER_SOURCE */
#endif
