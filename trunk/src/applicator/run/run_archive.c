/*
 * $RCSfile: run_archive.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.11 $ $Date: 2007-05-16 19:29:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_ARCHIVE_SOURCE
#define RUN_ARCHIVE_SOURCE

#include <unistd.h>
#include "../../applicator/run/run_execute.c"
#include "../../globals/constants/shell_command/unix_shell_command_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator/character_vector_allocator.c"
#include "../../memoriser/allocator/pointer_vector_allocator.c"

/**
 * Runs the archive command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 */
void run_archive(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Run archive command.");

    // The create name, abstraction, model, details.
    void** createn = NULL_POINTER;
    void** createnc = NULL_POINTER;
    void** createns = NULL_POINTER;
    void** createa = NULL_POINTER;
    void** createac = NULL_POINTER;
    void** createas = NULL_POINTER;
    int** createm = (int**) NULL_POINTER;
    void** createmc = NULL_POINTER;
    void** createms = NULL_POINTER;
    void** created = NULL_POINTER;
    void** createdc = NULL_POINTER;
    void** createds = NULL_POINTER;
    // The update name, abstraction, model, details.
    void** updaten = NULL_POINTER;
    void** updatenc = NULL_POINTER;
    void** updatens = NULL_POINTER;
    void** updatea = NULL_POINTER;
    void** updateac = NULL_POINTER;
    void** updateas = NULL_POINTER;
    int** updatem = (int**) NULL_POINTER;
    void** updatemc = NULL_POINTER;
    void** updatems = NULL_POINTER;
    void** updated = NULL_POINTER;
    void** updatedc = NULL_POINTER;
    void** updateds = NULL_POINTER;
    // The bzip2 name, abstraction, model, details.
    void** bzip2n = NULL_POINTER;
    void** bzip2nc = NULL_POINTER;
    void** bzip2ns = NULL_POINTER;
    void** bzip2a = NULL_POINTER;
    void** bzip2ac = NULL_POINTER;
    void** bzip2as = NULL_POINTER;
    int** bzip2m = (int**) NULL_POINTER;
    void** bzip2mc = NULL_POINTER;
    void** bzip2ms = NULL_POINTER;
    void** bzip2d = NULL_POINTER;
    void** bzip2dc = NULL_POINTER;
    void** bzip2ds = NULL_POINTER;

    // Get create option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_ARCHIVE_CREATE_NAME, (void*) RUN_ARCHIVE_CREATE_NAME_COUNT,
        (void*) &createn, (void*) &createnc, (void*) &createns,
        (void*) &createa, (void*) &createac, (void*) &createas,
        (void*) &createm, (void*) &createmc, (void*) &createms,
        (void*) &created, (void*) &createdc, (void*) &createds,
        p2, p3);

    // Get update option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_ARCHIVE_UPDATE_NAME, (void*) RUN_ARCHIVE_UPDATE_NAME_COUNT,
        (void*) &updaten, (void*) &updatenc, (void*) &updatens,
        (void*) &updatea, (void*) &updateac, (void*) &updateas,
        (void*) &updatem, (void*) &updatemc, (void*) &updatems,
        (void*) &updated, (void*) &updatedc, (void*) &updateds,
        p2, p3);

    // Get bzip2 option.
    get_universal_compound_element_by_name(p0, p1,
        (void*) RUN_ARCHIVE_BZIP2_NAME, (void*) RUN_ARCHIVE_BZIP2_NAME_COUNT,
        (void*) &bzip2n, (void*) &bzip2nc, (void*) &bzip2ns,
        (void*) &bzip2a, (void*) &bzip2ac, (void*) &bzip2as,
        (void*) &bzip2m, (void*) &bzip2mc, (void*) &bzip2ms,
        (void*) &bzip2d, (void*) &bzip2dc, (void*) &bzip2ds,
        p2, p3);

    // The arguments vector.
    void* arg = *NULL_POINTER;
    int argc = *NUMBER_0_INTEGER;
    int args = *NUMBER_0_INTEGER;

    // Determine arguments size.
    args = *ARCHIVE_UNIX_SHELL_COMMAND_COUNT;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Assemble arguments by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_SHELL_COMMAND, (void*) ARCHIVE_UNIX_SHELL_COMMAND_COUNT, (void*) CHARACTER_ARRAY);
    argc = argc + *ARCHIVE_UNIX_SHELL_COMMAND_COUNT;

    //
    // Create option.
    //

    if (*createm != *NULL_POINTER) {

        if (**createm == 1) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_SHELL_COMMAND_CREATE, (void*) ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT, (void*) CHARACTER_ARRAY);
            argc = argc + *ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT;
        }
    }

    //
    // Update option.
    //

    if (*updatem != *NULL_POINTER) {

        if (**updatem == 1) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_SHELL_COMMAND_UPDATE, (void*) ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT, (void*) CHARACTER_ARRAY);
            argc = argc + *ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT;
        }
    }

    //
    // Bzip2 option.
    //

    if (*bzip2m != *NULL_POINTER) {

        if (**bzip2m == 1) {

            // Resize arguments, if necessary.
            // One extra place for space character.
            if ((argc + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT) >= args) {

                // Determine arguments size.
                args = argc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT;

                reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(arg, (void*) &argc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            argc = argc + *PRIMITIVE_COUNT;
            set_array_elements(arg, (void*) &argc, (void*) ARCHIVE_UNIX_SHELL_COMMAND_BZIP2, (void*) ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT, (void*) CHARACTER_ARRAY);
            argc = argc + *ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT;
        }
    }

    //
    // Null termination.
    //

    // Resize arguments, if necessary.
    // One extra place for null termination character.
    if ((argc + *PRIMITIVE_COUNT) >= args) {

        // Determine arguments size.
        args = argc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT;

        reallocate_pointer_vector((void*) &arg, (void*) &argc, (void*) &args);
    }

    // Assemble arguments by adding the null termination character.
    set_array_elements(arg, (void*) &argc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
    argc = argc + *PRIMITIVE_COUNT;

    // Execute arguments as process.
    run_execute(arg);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

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
    shells = *SYSTEM_SHELL_COUNT + *PRIMITIVE_COUNT;

    // Allocate shell.
    allocate_array((void*) &shell, (void*) &shells, (void*) CHARACTER_ARRAY);

    // Assemble shell by first copying the actual shell command
    // and then adding the null termination character.
    set_array_elements(shell, (void*) &shellc, (void*) SYSTEM_SHELL, (void*) SYSTEM_SHELL_COUNT, (void*) CHARACTER_ARRAY);
    shellc = shellc + *SYSTEM_SHELL_COUNT;
    set_array_elements(shell, (void*) &shellc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
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
    set_array_elements(character, (void*) &characterc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
    characterc = characterc + *PRIMITIVE_COUNT;

    // Increase arguments vector size for shell character argument.
    args++;

    //
    // Command.
    //

    // Determine command size.
    commands = *ARCHIVE_UNIX_SHELL_COMMAND_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) CHARACTER_ARRAY);

    // Assemble command by copying the actual command.
    // A null termination character is added behind the last argument, see below!
    set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_SHELL_COMMAND, (void*) ARCHIVE_UNIX_SHELL_COMMAND_COUNT, (void*) CHARACTER_ARRAY);
    commandc = commandc + *ARCHIVE_UNIX_SHELL_COMMAND_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // Create option.
    //

    if (*createm != *NULL_POINTER) {

        if (**createm == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_SHELL_COMMAND_CREATE, (void*) ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT;
        }
    }

    //
    // Update option.
    //

    if (*updatem != *NULL_POINTER) {

        if (**updatem == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_SHELL_COMMAND_UPDATE, (void*) ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT;
        }
    }

    //
    // Bzip2 option.
    //

    if (*bzip2m != *NULL_POINTER) {

        if (**bzip2m == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble option by copying the actual argument.
            // A null termination character is added behind the last argument, see below!
            set_array_elements(command, (void*) &commandc, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) ARCHIVE_UNIX_SHELL_COMMAND_BZIP2, (void*) ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT;
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

    // Assemble command by adding the null termination character.
    set_array_elements(command, (void*) &commandc, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
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
    set(arg, (void*) &argc, NULL_POINTER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    argc++;

    // Execute command as process.
    run_execute(arg);

    if (shell != *NULL_POINTER) {

        // Deallocate shell argument.
        deallocate_array((void*) &shell, (void*) &shells, (void*) CHARACTER_ARRAY);
    }

    if (character != *NULL_POINTER) {

        // Deallocate character argument.
        deallocate_array((void*) &character, (void*) &characters, (void*) CHARACTER_ARRAY);
    }

    if (command != *NULL_POINTER) {

        // Deallocate command argument.
        deallocate_array((void*) &command, (void*) &commands, (void*) CHARACTER_ARRAY);
    }

    // Deallocate arguments vector.
    deallocate_pointer_vector((void*) &arg, (void*) &args);
*/
}

/* RUN_ARCHIVE_SOURCE */
#endif
