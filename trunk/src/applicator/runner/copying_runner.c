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
 * @version $RCSfile: copying_runner.c,v $ $Revision: 1.6 $ $Date: 2008-09-16 22:47:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COPYING_RUNNER_SOURCE
#define COPYING_RUNNER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/command_option/unix/copy_unix_command_option_name.c"
#include "../../constant/name/cybol/operation/run/copy_run_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../variable/reallocation_factor.c"

/**
 * Runs the copy command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_copying(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Run copy command.");

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
    get_universal_compound_element_by_name(p0, p1,
        (void*) RECURSIVE_COPY_RUN_OPERATION_CYBOL_NAME, (void*) RECURSIVE_COPY_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &recursiven, (void*) &recursivenc, (void*) &recursivens,
        (void*) &recursivea, (void*) &recursiveac, (void*) &recursiveas,
        (void*) &recursivem, (void*) &recursivemc, (void*) &recursivems,
        (void*) &recursived, (void*) &recursivedc, (void*) &recursiveds,
        p2, p3);

    // Get source option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SOURCE_COPY_RUN_OPERATION_CYBOL_NAME, (void*) SOURCE_COPY_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &sourcen, (void*) &sourcenc, (void*) &sourcens,
        (void*) &sourcea, (void*) &sourceac, (void*) &sourceas,
        (void*) &sourcem, (void*) &sourcemc, (void*) &sourcems,
        (void*) &sourced, (void*) &sourcedc, (void*) &sourceds,
        p2, p3);

    // Get destination option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) DESTINATION_COPY_RUN_OPERATION_CYBOL_NAME, (void*) DESTINATION_COPY_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &destinationn, (void*) &destinationnc, (void*) &destinationns,
        (void*) &destinationa, (void*) &destinationac, (void*) &destinationas,
        (void*) &destinationm, (void*) &destinationmc, (void*) &destinationms,
        (void*) &destinationd, (void*) &destinationdc, (void*) &destinationds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine arguments size.
    args = *SHELL_UNIX_COMMAND_MODEL_COUNT;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Assemble arguments by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(arg, (void*) &argc, (void*) SHELL_UNIX_COMMAND_MODEL, (void*) SHELL_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    argc = argc + *SHELL_UNIX_COMMAND_MODEL_COUNT;

    //
    // Recursive option.
    //

    if (*recursivem != *NULL_POINTER_MEMORY_MODEL) {

        if (**recursivem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;
        }
    }

    //
    // Source option.
    //

    if (*sourcem != *NULL_POINTER_MEMORY_MODEL) {

        if (**sourcem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;
        }
    }

    //
    // Destination option.
    //

    if (*destinationm != *NULL_POINTER_MEMORY_MODEL) {

        if (**destinationm == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;
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
    commands = *SHELL_UNIX_COMMAND_MODEL_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Assemble command by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(command, (void*) &commandc, (void*) SHELL_UNIX_COMMAND_MODEL, (void*) SHELL_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    commandc = commandc + *SHELL_UNIX_COMMAND_MODEL_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // Recursive option.
    //

    if (*recursivem != *NULL_POINTER_MEMORY_MODEL) {

        if (**recursivem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;
        }
    }

    //
    // Source option.
    //

    if (*sourcem != *NULL_POINTER_MEMORY_MODEL) {

        if (**sourcem == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;
        }
    }

    //
    // Destination option.
    //

    if (*destinationm != *NULL_POINTER_MEMORY_MODEL) {

        if (**destinationm == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT;
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

/* COPYING_RUNNER_SOURCE */
#endif
