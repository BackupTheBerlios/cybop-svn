/*
 * $RCSfile: run_list_directory_contents.c,v $
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
 * @version $Revision: 1.21 $ $Date: 2008-07-08 17:55:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_LIST_DIRECTORY_CONTENTS_SOURCE
#define RUN_LIST_DIRECTORY_CONTENTS_SOURCE

#include <unistd.h>
#include "../../applicator/run/run_execute.c"
#include "../../globals/constants/boolean/boolean_constants.c"
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
 * Runs the list directory contents command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_list_directory_contents(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Run list directory contents command.");

    // The all name, abstraction, model, details.
    void** alln = NULL_POINTER;
    void** allnc = NULL_POINTER;
    void** allns = NULL_POINTER;
    void** alla = NULL_POINTER;
    void** allac = NULL_POINTER;
    void** allas = NULL_POINTER;
    int** allm = (int**) NULL_POINTER;
    void** allmc = NULL_POINTER;
    void** allms = NULL_POINTER;
    void** alld = NULL_POINTER;
    void** alldc = NULL_POINTER;
    void** allds = NULL_POINTER;

    // The long listing name, abstraction, model, details.
    void** longlistingn = NULL_POINTER;
    void** longlistingnc = NULL_POINTER;
    void** longlistingns = NULL_POINTER;
    void** longlistinga = NULL_POINTER;
    void** longlistingac = NULL_POINTER;
    void** longlistingas = NULL_POINTER;
    int** longlistingm = (int**) NULL_POINTER;
    void** longlistingmc = NULL_POINTER;
    void** longlistingms = NULL_POINTER;
    void** longlistingd = NULL_POINTER;
    void** longlistingdc = NULL_POINTER;
    void** longlistingds = NULL_POINTER;

    // Get all option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME, (void*) RUN_LIST_DIRECTORY_CONTENTS_ALL_NAME_COUNT,
        (void*) &alln, (void*) &allnc, (void*) &allns,
        (void*) &alla, (void*) &allac, (void*) &allas,
        (void*) &allm, (void*) &allmc, (void*) &allms,
        (void*) &alld, (void*) &alldc, (void*) &allds,
        p2, p3);

    // Get long listing option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME, (void*) RUN_LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_COUNT,
        (void*) &longlistingn, (void*) &longlistingnc, (void*) &longlistingns,
        (void*) &longlistinga, (void*) &longlistingac, (void*) &longlistingas,
        (void*) &longlistingm, (void*) &longlistingmc, (void*) &longlistingms,
        (void*) &longlistingd, (void*) &longlistingdc, (void*) &longlistingds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER;
    int argc = *NUMBER_0_INTEGER;
    int args = *NUMBER_0_INTEGER;

    // Determine arguments size.
    args = *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Assemble arguments by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(arg, (void*) &argc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    argc = argc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT;

    //
    // All option.
    //

    if (*allm != *NULL_POINTER) {

        if (**allm == *TRUE_BOOLEAN) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT;
        }
    }

    //
    // Long listing option.
    //

    if (*longlistingm != *NULL_POINTER) {

        if (**longlistingm == *TRUE_BOOLEAN) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            argc = argc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT;
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
    set_array_elements(arg, (void*) &argc, (void*) NULL_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
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
    set_array_elements(shell, (void*) &shellc, (void*) NULL_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
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
    set_array_elements(character, (void*) &characterc, (void*) NULL_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    characterc = characterc + *PRIMITIVE_COUNT;

    // Increase arguments vector size for shell character argument.
    args++;

    //
    // Command.
    //

    // Determine command size.
    commands = *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) WIDE_CHARACTER_ARRAY);

    // Assemble command by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // All option.
    //

    if (*allm != *NULL_POINTER) {

        if (**allm == *TRUE_BOOLEAN) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT;
        }
    }

    //
    // Long listing option.
    //

    if (*longlistingm != *NULL_POINTER) {

        if (**longlistingm == *TRUE_BOOLEAN) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATION_FACTOR + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT, (void*) WIDE_CHARACTER_ARRAY);
            commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT;
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
    set_array_elements(command, (void*) &commandc, (void*) NULL_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
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

/* RUN_LIST_DIRECTORY_CONTENTS_SOURCE */
#endif
