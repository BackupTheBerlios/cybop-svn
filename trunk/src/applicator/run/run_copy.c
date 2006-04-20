/*
 * $RCSfile: run_copy.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_COPY_SOURCE
#define RUN_COPY_SOURCE

#include <unistd.h>
#include "../../applicator/run/run_execute.c"
#include "../../globals/constants/shell_command/unix_shell_command_constants.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/ascii_character_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/allocator/character_vector_allocator.c"

/**
 * Runs the copy command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 */
void run_copy(void* p0, void* p1) {

    log_message_debug("Run copy command.");

    // The recursive abstraction.
    void** recursivea = &NULL_POINTER;
    void** recursiveac = &NULL_POINTER;
    void** recursiveas = &NULL_POINTER;
    // The recursive model.
    int** recursivem = (int**) &NULL_POINTER;
    void** recursivemc = &NULL_POINTER;
    void** recursivems = &NULL_POINTER;
    // The recursive details.
    void** recursived = &NULL_POINTER;
    void** recursivedc = &NULL_POINTER;
    void** recursiveds = &NULL_POINTER;

    // The source abstraction.
    void** sourcea = &NULL_POINTER;
    void** sourceac = &NULL_POINTER;
    void** sourceas = &NULL_POINTER;
    // The source model.
    int** sourcem = (int**) &NULL_POINTER;
    void** sourcemc = &NULL_POINTER;
    void** sourcems = &NULL_POINTER;
    // The source details.
    void** sourced = &NULL_POINTER;
    void** sourcedc = &NULL_POINTER;
    void** sourceds = &NULL_POINTER;

    // The destination abstraction.
    void** destinationa = &NULL_POINTER;
    void** destinationac = &NULL_POINTER;
    void** destinationas = &NULL_POINTER;
    // The destination model.
    int** destinationm = (int**) &NULL_POINTER;
    void** destinationmc = &NULL_POINTER;
    void** destinationms = &NULL_POINTER;
    // The destination details.
    void** destinationd = &NULL_POINTER;
    void** destinationdc = &NULL_POINTER;
    void** destinationds = &NULL_POINTER;

    // Get recursive option.
    get_compound_element_by_name(p0, p1,
        (void*) RUN_COPY_RECURSIVE_NAME, (void*) RUN_COPY_RECURSIVE_NAME_COUNT,
        (void*) &recursivea, (void*) &recursiveac, (void*) &recursiveas,
        (void*) &recursivem, (void*) &recursivemc, (void*) &recursivems,
        (void*) &recursived, (void*) &recursivedc, (void*) &recursiveds);

    // Get source option.
    get_compound_element_by_name(p0, p1,
        (void*) RUN_COPY_SOURCE_NAME, (void*) RUN_COPY_SOURCE_NAME_COUNT,
        (void*) &sourcea, (void*) &sourceac, (void*) &sourceas,
        (void*) &sourcem, (void*) &sourcemc, (void*) &sourcems,
        (void*) &sourced, (void*) &sourcedc, (void*) &sourceds);

    // Get destination option.
    get_compound_element_by_name(p0, p1,
        (void*) RUN_COPY_DESTINATION_NAME, (void*) RUN_COPY_DESTINATION_NAME_COUNT,
        (void*) &destinationa, (void*) &destinationac, (void*) &destinationas,
        (void*) &destinationm, (void*) &destinationmc, (void*) &destinationms,
        (void*) &destinationd, (void*) &destinationdc, (void*) &destinationds);

    // The arguments vector.
    void* arg = NULL_POINTER;
    int argc = *NUMBER_0_INTEGER;
    int args = *NUMBER_0_INTEGER;

    // The system shell as null terminated string.
    void* shell = NULL_POINTER;
    int shellc = *NUMBER_0_INTEGER;
    int shells = *NUMBER_0_INTEGER;
    // The character argument as null terminated string.
    void* character = NULL_POINTER;
    int characterc = *NUMBER_0_INTEGER;
    int characters = *NUMBER_0_INTEGER;
    // The command as null terminated string.
    void* command = NULL_POINTER;
    int commandc = *NUMBER_0_INTEGER;
    int commands = *NUMBER_0_INTEGER;

    // Allocate arguments vector.
    allocate_pointer_vector((void*) &arg, (void*) &args);

    //
    // System shell.
    //

    // Determine shell size.
    shells = *SYSTEM_SHELL_COUNT + *PRIMITIVE_COUNT;

    // Allocate shell.
    allocate_array((void*) &shell, (void*) &shells, (void*) CHARACTER_ARRAY);

    // Assemble shell by first copying the actual shell command
    // and then adding the null termination character.
    set_array_elements(shell, (void*) &shellc, (void*) SYSTEM_SHELL, (void*) SYSTEM_SHELL_COUNT, (void*) CHARACTER_ARRAY);
    shellc = shellc + *SYSTEM_SHELL_COUNT;
    set_array_elements(shell, (void*) &shellc, (void*) NULL_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
    shellc = shellc + *PRIMITIVE_COUNT;

    // Increase arguments vector size for shell argument.
    args++;

    //
    // System shell character argument.
    //

    // Determine character argument size.
    characters = *SYSTEM_SHELL_CHARACTER_ARGUMENT_COUNT + *PRIMITIVE_COUNT;

    // Allocate character argument.
    allocate_array((void*) &character, (void*) &characters, (void*) CHARACTER_ARRAY);

    // Assemble character argument by first copying the actual argument
    // and then adding the null termination character.
    set_array_elements(character, (void*) &characterc, (void*) SYSTEM_SHELL_CHARACTER_ARGUMENT, (void*) SYSTEM_SHELL_CHARACTER_ARGUMENT_COUNT, (void*) CHARACTER_ARRAY);
    characterc = characterc + *SYSTEM_SHELL_CHARACTER_ARGUMENT_COUNT;
    set_array_elements(character, (void*) &characterc, (void*) NULL_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
    characterc = characterc + *PRIMITIVE_COUNT;

    // Increase arguments vector size for shell character argument.
    args++;

    //
    // Command.
    //

    // Determine command size.
    commands = *COPY_UNIX_SHELL_COMMAND_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) CHARACTER_ARRAY);

    // Assemble command by first copying the actual command
    // and then adding the null termination character.
    set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND, (void*) COPY_UNIX_SHELL_COMMAND_COUNT, (void*) CHARACTER_ARRAY);
    commandc = commandc + *COPY_UNIX_SHELL_COMMAND_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // Recursive option.
    //

    if (*recursivem != NULL_POINTER) {

        if (**recursivem == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble recursive option by first copying the actual argument
            // and then adding the null termination character.
            set_array_elements(command, (void*) &commandc, (void*) SPACE_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND_RECURSIVE, (void*) COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT;
        }
    }

    //
    // Source option.
    //

    if (*sourcem != NULL_POINTER) {

        if (**sourcem == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by first copying the actual argument
            // and then adding the null termination character.
            set_array_elements(command, (void*) &commandc, (void*) SPACE_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND_SOURCE, (void*) COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT;
        }
    }

    //
    // Destination option.
    //

    if (*destinationm != NULL_POINTER) {

        if (**destinationm == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by first copying the actual argument
            // and then adding the null termination character.
            set_array_elements(command, (void*) &commandc, (void*) SPACE_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) COPY_UNIX_SHELL_COMMAND_DESTINATION, (void*) COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT, (void*) CHARACTER_ARRAY);
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
        commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT;

        reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
    }

    // Assemble command option by adding the null termination character.
    set_array_elements(command, (void*) &commandc, (void*) NULL_CONTROL_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
    commandc = commandc + *PRIMITIVE_COUNT;

    fprintf(stdout, "TEST command %s\n", (char*) command);

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
    set(arg, (void*) &argc, (void*) &shell, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Set character shell argument.
    set(arg, (void*) &argc, (void*) &character, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Set command.
    set(arg, (void*) &argc, (void*) &command, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Set null pointer argument.
    // CAUTION! The null pointer always has to be the last argument.
    set(arg, (void*) &argc, (void*) &NULL_POINTER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Execute command as process.
    run_execute(arg);

    if (shell != NULL_POINTER) {

        // Deallocate shell argument.
        deallocate_array((void*) &shell, (void*) &shells, (void*) CHARACTER_ARRAY);
    }

    if (character != NULL_POINTER) {

        // Deallocate character argument.
        deallocate_array((void*) &character, (void*) &characters, (void*) CHARACTER_ARRAY);
    }

    if (command != NULL_POINTER) {

        // Deallocate command argument.
        deallocate_array((void*) &command, (void*) &commands, (void*) CHARACTER_ARRAY);
    }

    // Deallocate arguments vector.
    deallocate_pointer_vector((void*) &arg, (void*) &args);
}

/* RUN_COPY_SOURCE */
#endif
