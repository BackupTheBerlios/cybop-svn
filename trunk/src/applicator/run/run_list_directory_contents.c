/*
 * $RCSfile: run_list_directory_contents.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2006-02-20 16:17:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_LIST_DIRECTORY_CONTENTS_SOURCE
#define RUN_LIST_DIRECTORY_CONTENTS_SOURCE

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
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
 * Runs the list directory contents command.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 */
void run_list_directory_contents(void* p0, void* p1) {

    log_message_debug("Run list directory contents command.");

    // The all abstraction.
    void** alla = &NULL_POINTER;
    void** allac = &NULL_POINTER;
    void** allas = &NULL_POINTER;
    // The all model.
    int** allm = (int**) &NULL_POINTER;
    void** allmc = &NULL_POINTER;
    void** allms = &NULL_POINTER;
    // The all details.
    void** alld = &NULL_POINTER;
    void** alldc = &NULL_POINTER;
    void** allds = &NULL_POINTER;

    // The long listing abstraction.
    void** longlistinga = &NULL_POINTER;
    void** longlistingac = &NULL_POINTER;
    void** longlistingas = &NULL_POINTER;
    // The long listing model.
    int** longlistingm = (int**) &NULL_POINTER;
    void** longlistingmc = &NULL_POINTER;
    void** longlistingms = &NULL_POINTER;
    // The long listing details.
    void** longlistingd = &NULL_POINTER;
    void** longlistingdc = &NULL_POINTER;
    void** longlistingds = &NULL_POINTER;

    // Get all option.
    get_compound_element_by_name(p0, p1,
        (void*) LIST_DIRECTORY_CONTENTS_ALL_NAME, (void*) LIST_DIRECTORY_CONTENTS_ALL_NAME_COUNT,
        (void*) &alla, (void*) &allac, (void*) &allas,
        (void*) &allm, (void*) &allmc, (void*) &allms,
        (void*) &alld, (void*) &alldc, (void*) &allds);

    // Get long listing option.
    get_compound_element_by_name(p0, p1,
        (void*) LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME, (void*) LIST_DIRECTORY_CONTENTS_LONG_LISTING_NAME_COUNT,
        (void*) &longlistinga, (void*) &longlistingac, (void*) &longlistingas,
        (void*) &longlistingm, (void*) &longlistingmc, (void*) &longlistingms,
        (void*) &longlistingd, (void*) &longlistingdc, (void*) &longlistingds);

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
    commands = *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT;

    // Allocate command.
    allocate_array((void*) &command, (void*) &commands, (void*) CHARACTER_ARRAY);

    // Assemble command by first copying the actual command
    // and then adding the null termination character.
    set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT, (void*) CHARACTER_ARRAY);
    commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT;

    // Increase arguments vector size for command argument.
    args++;

    //
    // All option.
    //

    if (*allm != NULL_POINTER) {

        if (**allm == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble all option by first copying the actual argument
            // and then adding the null termination character.
            set_array_elements(command, (void*) &commandc, (void*) SPACE_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT;
        }
    }

    //
    // Long listing option.
    //

    if (*longlistingm != NULL_POINTER) {

        if (**longlistingm == 1) {

            // Resize command, if necessary.
            // One extra place for space character.
            if ((commandc + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT) >= commands) {

                // Determine command size.
                commands = commandc * *POINTER_VECTOR_REALLOCATE_FACTOR + *PRIMITIVE_COUNT + *LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT;

                reallocate_pointer_vector((void*) &command, (void*) &commandc, (void*) &commands);
            }

            // Assemble long listing option by first copying the actual argument
            // and then adding the null termination character.
            set_array_elements(command, (void*) &commandc, (void*) SPACE_ASCII_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
            commandc = commandc + *PRIMITIVE_COUNT;
            set_array_elements(command, (void*) &commandc, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING, (void*) LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT, (void*) CHARACTER_ARRAY);
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

    //
    // Command execution.
    //

    // Fork a new process and remember its identification.
    // In the GNU C library, pid_t corresponds to the int type.
    pid_t pid = fork();

    if (pid == 0) {

        // This is the child process.

        // Execute file (given as first parameter) as a new process image.
        // In this case, it is the system shell executing a command.
        // Arguments are specified individually and handed over as strings.
        // The first argument represents the name of the program being executed.
        // That is why the SYSTEM_SHELL constant is supplied once to name the
        // program to execute and a second time to supply a value for argv[0].
        // A null pointer must be passed as the last such argument, to indicate the end!
        //
        // Example:
        // execl(SYSTEM_SHELL, SYSTEM_SHELL, "-c", LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND, NULL_POINTER);
        execv(SYSTEM_SHELL, (char**) arg);

        // Exit the child process.
        // The execl call in the child process doesn't return if it is successful.
        // If it fails, something must be done to make the child process terminate.
        // Just returning a bad status code with return would leave two processes
        // running the original program. Instead, the right behavior is for the
        // child process to report failure to its parent process.
        // CAUTION! Call "_exit" to accomplish this!
        // The reason for using "_exit" instead of "exit" is to avoid flushing
        // fully buffered streams such as stdout. The buffers of these streams
        // probably contain data that was copied from the parent process by the
        // fork, data that will be output eventually by the parent process.
        // Calling "exit" in the child would output the data twice.
        _exit(1);

    } else {

        if (pid < 0) {

            log_message_debug("Error: Could not run list files command. The process fork failed.");

        } else {

            // Get status id.
            // In the GNU C library, pid_t corresponds to the int type.
            pid_t s = waitpid(pid, NULL_POINTER, 0);

            if (s != pid) {

                // This is the parent process.

                log_message_debug("Error: Could not run list files command. Have to wait for the child process to complete.");
            }
        }
    }

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

/* RUN_LIST_DIRECTORY_CONTENTS_SOURCE */
#endif