/*
 * $RCSfile: run_execute.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2006-03-13 23:16:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_EXECUTE_SOURCE
#define RUN_EXECUTE_SOURCE

#ifdef LINUX_OPERATING_SYSTEM
#include <sys/types.h>
#include <sys/wait.h>
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"

/**
 * Execute command as process.
 *
 * @param p0 the arguments
 */
void run_execute(void* p0) {

    log_message_debug("Execute command as process.");

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
        // execl(SYSTEM_SHELL, SYSTEM_SHELL, "-c", ARCHIVE_UNIX_SHELL_COMMAND, NULL_POINTER);
        execv(SYSTEM_SHELL, (char**) p0);

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

            log_message_debug("Error: Could not run archive command. The process fork failed.");

        } else {

            // Get status id.
            // In the GNU C library, pid_t corresponds to the int type.
            pid_t s = waitpid(pid, NULL_POINTER, 0);

            if (s != pid) {

                // This is the parent process.

                log_message_debug("Error: Could not run archive command. Have to wait for the child process to complete.");
            }
        }
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* RUN_EXECUTE_SOURCE */
#endif
