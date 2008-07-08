/*
 * $RCSfile: run_copy.c,v $
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
 * @version $Revision: 1.18 $ $Date: 2008-07-08 07:11:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_COPY_SOURCE
#define RUN_COPY_SOURCE

#include <unistd.h>
#include "../../applicator/run/run_execute.c"
#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/constants/shell_command/unix_shell_command_constants.c"
#include "../../globals/constants/system/system_executable_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/allocator/character_vector_allocator.c"

/**
 * Runs the copy command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_copy(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Run copy command.");

    // The recursive name, abstraction, model, details.
    void** recursiven = NULL_POINTER;
    void** recursivenc = NULL_POINTER;
    void** recursivens = NULL_POINTER;
    void** recursivea = NULL_POINTER;
    void** recursiveac = NULL_POINTER;
    void** recursiveas = NULL_POINTER;
    int** recursivem = (int**) NULL_POINTER;
    void** recursivemc = NULL_POINTER;
    void** recursivems = NULL_POINTER;
    void** recursived = NULL_POINTER;
    void** recursivedc = NULL_POINTER;
    void** recursiveds = NULL_POINTER;
    // The source name, abstraction, model, details.
    void** sourcen = NULL_POINTER;
    void** sourcenc = NULL_POINTER;
    void** sourcens = NULL_POINTER;
    void** sourcea = NULL_POINTER;
    void** sourceac = NULL_POINTER;
    void** sourceas = NULL_POINTER;
    int** sourcem = (int**) NULL_POINTER;
    void** sourcemc = NULL_POINTER;
    void** sourcems = NULL_POINTER;
    void** sourced = NULL_POINTER;
    void** sourcedc = NULL_POINTER;
    void** sourceds = NULL_POINTER;
    // The destination name, abstraction, model, details.
    void** destinationn = NULL_POINTER;
    void** destinationnc = NULL_POINTER;
    void** destinationns = NULL_POINTER;
    void** destinationa = NULL_POINTER;
    void** destinationac = NULL_POINTER;
    void** destinationas = NULL_POINTER;
    int** destinationm = (int**) NULL_POINTER;
    void** destinationmc = NULL_POINTER;
    void** destinationms = NULL_POINTER;
    void** destinationd = NULL_POINTER;
    void** destinationdc = NULL_POINTER;
    void** destinationds = NULL_POINTER;

    // Get recursive option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_COPY_RECURSIVE_NAME, (void*) RUN_COPY_RECURSIVE_NAME_COUNT,
        (void*) &recursiven, (void*) &recursivenc, (void*) &recursivens,
        (void*) &recursivea, (void*) &recursiveac, (void*) &recursiveas,
        (void*) &recursivem, (void*) &recursivemc, (void*) &recursivems,
        (void*) &recursived, (void*) &recursivedc, (void*) &recursiveds,
        p2, p3);

    // Get source option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_COPY_SOURCE_NAME, (void*) RUN_COPY_SOURCE_NAME_COUNT,
        (void*) &sourcen, (void*) &sourcenc, (void*) &sourcens,
        (void*) &sourcea, (void*) &sourceac, (void*) &sourceas,
        (void*) &sourcem, (void*) &sourcemc, (void*) &sourcems,
        (void*) &sourced, (void*) &sourcedc, (void*) &sourceds,
        p2, p3);

    // Get destination option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_COPY_DESTINATION_NAME, (void*) RUN_COPY_DESTINATION_NAME_COUNT,
        (void*) &destinationn, (void*) &destinationnc, (void*) &destinationns,
        (void*) &destinationa, (void*) &destinationac, (void*) &destinationas,
        (void*) &destinationm, (void*) &destinationmc, (void*) &destinationms,
        (void*) &destinationd, (void*) &destinationdc, (void*) &destinationds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER;
    int argc = *NUMBER_0_INTEGER;
    int args = *NUMBER_0_INTEGER;

    // Determine arguments size.
    args = *COPY_UNIX_SHELL_COMMAND_COUNT;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Assemble arguments by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(arg, (void*) &argc, (void*) COPY_UNIX_SHELL_COMMAND, (void*) COPY_UNIX_SHELL_COMMAND_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    argc = argc + *COPY_UNIX_SHELL_COMMAND_COUNT;

    //
    // Recursive option.
    //

    if (*recursivem != *NULL_POINTER) {

        if (**recursivem == *NUMBER_1_INTEGER) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) COPY_UNIX_SHELL_COMMAND_RECURSIVE, (void*) COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT;
        }
    }

    //
    // Source option.
    //

    if (*sourcem != *NULL_POINTER) {

        if (**sourcem == *NUMBER_1_INTEGER) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) COPY_UNIX_SHELL_COMMAND_SOURCE, (void*) COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT;
        }
    }

    //
    // Destination option.
    //

    if (*destinationm != *NULL_POINTER) {

        if (**destinationm == *NUMBER_1_INTEGER) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) COPY_UNIX_SHELL_COMMAND_DESTINATION, (void*) COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT;
        }
    }

    //
    // Null termination.
    //

    // Resize arguments, if necessary.
    // One extra place for null termination character.
    if ((argc + *PRIMITIVE_COUNT) >= args) {

        // Determine arguments size.
        args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT;

        reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
    }

    // Assemble arguments by adding the null termination character.
    set_array_elements(arg, (void*) &argc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    argc = argc + *PRIMITIVE_COUNT;

    // Execute arguments as process.
    run_execute(arg);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

/*??
    //?? The following block assembles all arguments for using "fork/execv/wait" in "run_execute.c".
    //?? But since "run_execute.c" is using system("program_name"),
    //?? this block has been commented out.
    //?? It may be either reactivated together with "fork/execv/wait"
    //?? in "run_execute.c" or deleted later.

    // The arguments vector.
    void* arg = *NULL_POINTER;
    int argc = *NUMBER_0_INTEGER;
    int args = *NUMBER_0_INTEGER;

    // The system shell as null terminated string.
    void* shell = *NULL_POINTER;
    int shellc = *NUMBER_0_INTEGER;
    int shells = *NUMBER_0_INTEGER;
    // The character argument as null terminated string.
    void* character = *NULL_POINTER;
    int characterc = *NUMBER_0_INTEGER;
    int characters = *NUMBER_0_INTEGER;
    // The command as null terminated string.
    void* command = *NULL_POINTER;
    int commandc = *NUMBER_0_INTEGER;
    int commands = *NUMBER_0_INTEGER;

    // Allocate arguments vector.
    allocate_pointer_vector((void*) &arg, (void*) &args);

    //
    // System shell.
    //

    // Determine shell size.
    shells = *SHELL_SYSTEM_EXECUTABLE_COUNT + *PRIMITIVE_COUNT;

    // Allocate shell.
    allocate_array((void*) &shell, (void*) &shells, (void*) WIDE_CHARACTER_ARRAY);

    // Assemble shell by first copying the actual shell command
    // and then adding the null termination character.
    set_array_elements(shell, (void*) &shellc, (void*) SHELL_SYSTEM_EXECUTABLE, (void*) SHELL_SYSTEM_EXECUTABLE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    shellc = shellc + *SHELL_SYSTEM_EXECUTABLE_COUNT;
    set_array_elements(shell, (void*) &shellc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    shellc = shellc + *PRIMITIVE_COUNT;

    // Increase arguments vector size for shell argument.
    args++;

    //
    // System shell character argument.
    //

    // Determine character argument size.
    characters = *SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT + *PRIMITIVE_COUNT;

    // Allocate character argument.
    allocate_array((void*) &character, (void*) &characters, (void*) WIDE_CHARACTER_ARRAY);

    // Assemble character argument by first copying the actual argument
    // and then adding the null termination character.
    set_array_elements(character, (void*) &characterc, (void*) SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT, (void*) SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    characterc = characterc + *SHELL_SYSTEM_EXECUTABLE_CHARACTER_ARGUMENT_COUNT;
    set_array_elements(character, (void*) &characterc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    characterc = characterc + *PRIMITIVE_COUNT;

    // Increase arguments vector size for shell character argument.
    args++;

    //
    // Command.
    //

    // Determine command size.
    commands = *COPY_UNIX_SHELL_COMMAND_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY);

    // Assemble command by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND, (void*) COPY_UNIX_SHELL_COMMAND_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    commandc = commandc + *COPY_UNIX_SHELL_COMMAND_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // Recursive option.
    //

    if (*recursivem != *NULL_POINTER) {

        if (**recursivem == *NUMBER_1_INTEGER) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND_RECURSIVE, (void*) COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT;
        }
    }

    //
    // Source option.
    //

    if (*sourcem != *NULL_POINTER) {

        if (**sourcem == *NUMBER_1_INTEGER) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND_SOURCE, (void*) COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT;
        }
    }

    //
    // Destination option.
    //

    if (*destinationm != *NULL_POINTER) {

        if (**destinationm == *NUMBER_1_INTEGER) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND_DESTINATION, (void*) COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT;
        }
    }

    //
    // Null termination.
    //

    // Resize command, if necessary.
    // One extra place for null termination character.
    if ((commandc + *PRIMITIVE_COUNT) >= commands) {

        // Determine command size.
        commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT;

        reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
    }

    // Assemble command by adding the null termination character.
    set_array_elements(command, (void*) &commandc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    commandc = commandc + *PRIMITIVE_COUNT;

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
    set_element(arg, (void*) &argc, (void*) &shell, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Set character shell argument.
    set_element(arg, (void*) &argc, (void*) &character, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Set command.
    set_element(arg, (void*) &argc, (void*) &command, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Set null pointer argument.
    // CAUTION! The null pointer always has to be the last argument.
    set_element(arg, (void*) &argc, NULL_POINTER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Execute command as process.
    run_execute(arg);

    if (shell != *NULL_POINTER) {

        // Deallocate shell argument.
        deallocate_array((void*) &shell, (void*) &shells, (void*) WIDE_CHARACTER_ARRAY);
    }

    if (character != *NULL_POINTER) {

        // Deallocate character argument.
        deallocate_array((void*) &character, (void*) &characters, (void*) WIDE_CHARACTER_ARRAY);
    }

    if (command != *NULL_POINTER) {

        // Deallocate command argument.
        deallocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY);
    }

    // Deallocate arguments vector.
    deallocate_pointer_vector((void*) &arg, (void*) &args);
*/
}

/* RUN_COPY_SOURCE */
#endif
