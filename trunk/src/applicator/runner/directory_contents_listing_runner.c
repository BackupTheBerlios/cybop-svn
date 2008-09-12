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
 * @version $RCSfile: directory_contents_listing_runner.c,v $ $Revision: 1.5 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIST_DIRECTORY_CONTENTS_RUNNER_SOURCE
#define LIST_DIRECTORY_CONTENTS_RUNNER_SOURCE

#include <unistd.h>
#include "../../applicator/runner/executing_runner.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/run/list_run_operation_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../variable/reallocation_factor.c"

/**
 * Runs the list directory contents command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_list_directory_contents(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Run list directory contents command.");

    // The all name, abstraction, model, details.
    void** alln = NULL_POINTER_MEMORY_MODEL;
    void** allnc = NULL_POINTER_MEMORY_MODEL;
    void** allns = NULL_POINTER_MEMORY_MODEL;
    void** alla = NULL_POINTER_MEMORY_MODEL;
    void** allac = NULL_POINTER_MEMORY_MODEL;
    void** allas = NULL_POINTER_MEMORY_MODEL;
    int** allm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** allmc = NULL_POINTER_MEMORY_MODEL;
    void** allms = NULL_POINTER_MEMORY_MODEL;
    void** alld = NULL_POINTER_MEMORY_MODEL;
    void** alldc = NULL_POINTER_MEMORY_MODEL;
    void** allds = NULL_POINTER_MEMORY_MODEL;

    // The long listing name, abstraction, model, details.
    void** longlistingn = NULL_POINTER_MEMORY_MODEL;
    void** longlistingnc = NULL_POINTER_MEMORY_MODEL;
    void** longlistingns = NULL_POINTER_MEMORY_MODEL;
    void** longlistinga = NULL_POINTER_MEMORY_MODEL;
    void** longlistingac = NULL_POINTER_MEMORY_MODEL;
    void** longlistingas = NULL_POINTER_MEMORY_MODEL;
    int** longlistingm = (int**) NULL_POINTER_MEMORY_MODEL;
    void** longlistingmc = NULL_POINTER_MEMORY_MODEL;
    void** longlistingms = NULL_POINTER_MEMORY_MODEL;
    void** longlistingd = NULL_POINTER_MEMORY_MODEL;
    void** longlistingdc = NULL_POINTER_MEMORY_MODEL;
    void** longlistingds = NULL_POINTER_MEMORY_MODEL;

    // Get all option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) ALL_LIST_RUN_OPERATION_CYBOL_NAME, (void*) ALL_LIST_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &alln, (void*) &allnc, (void*) &allns,
        (void*) &alla, (void*) &allac, (void*) &allas,
        (void*) &allm, (void*) &allmc, (void*) &allms,
        (void*) &alld, (void*) &alldc, (void*) &allds,
        p2, p3);

    // Get long listing option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) LONG_LISTING_LIST_RUN_OPERATION_CYBOL_NAME, (void*) LONG_LISTING_LIST_RUN_OPERATION_CYBOL_NAME_COUNT,
        (void*) &longlistingn, (void*) &longlistingnc, (void*) &longlistingns,
        (void*) &longlistinga, (void*) &longlistingac, (void*) &longlistingas,
        (void*) &longlistingm, (void*) &longlistingmc, (void*) &longlistingms,
        (void*) &longlistingd, (void*) &longlistingdc, (void*) &longlistingds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER_MEMORY_MODEL;
    int argc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int args = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine arguments size.
    args = *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Assemble arguments by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(arg, (void*) &argc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    argc = argc + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT;

    //
    // All option.
    //

    if (*allm != *NULL_POINTER_MEMORY_MODEL) {

        if (**allm == *TRUE_BOOLEAN_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT;
        }
    }

    //
    // Long listing option.
    //

    if (*longlistingm != *NULL_POINTER_MEMORY_MODEL) {

        if (**longlistingm == *TRUE_BOOLEAN_MEMORY_MODEL) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            argc = argc + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT;
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
    commands = *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Assemble command by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // All option.
    //

    if (*allm != *NULL_POINTER_MEMORY_MODEL) {

        if (**allm == *TRUE_BOOLEAN_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ALL_COUNT;
        }
    }

    //
    // Long listing option.
    //

    if (*longlistingm != *NULL_POINTER_MEMORY_MODEL) {

        if (**longlistingm == *TRUE_BOOLEAN_MEMORY_MODEL) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_MEMORY_MODEL_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *PRIMITIVE_MEMORY_MODEL_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_LONG_LISTING_COUNT;
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

/* LIST_DIRECTORY_CONTENTS_RUNNER_SOURCE */
#endif