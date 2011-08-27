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
 * @version $RCSfile: executing_runner.c,v $ $Revision: 1.7 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EXECUTE_SOURCE
#define EXECUTE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/command_option/unix/shell_unix_command_option_name.c"
#include "../../executor/converter/decoder/utf_8_unicode_character_decoder.c"
#include "../../logger/logger.c"

/**
 * Executes the command as process.
 *
 * @param p0 the command array
 * @param p1 the command array count
 */
void apply_execute(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply execute.");

    //?? TODO: Figure out if assembling a shell command line is necessary at all!
    //?? The "system" function call further below does search programmes internally
    //?? and by default uses the "sh" to execute commands.
    //?? Therefore, the prefix "sh" and the rest assembled below may be superfluous.

    // The shell command line.
    void* cl = *NULL_POINTER_MEMORY_MODEL;
    int clc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cls = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate shell command line.
    allocate_array((void*) &cl, (void*) &cls, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Append shell command.
    overwrite_array((void*) &cl, (void*) SHELL_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SHELL_UNIX_COMMAND_MODEL_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    // Append shell command.
    overwrite_array((void*) &cl, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    overwrite_array((void*) &cl, (void*) CHARACTER_SHELL_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CHARACTER_SHELL_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    // Append user command.
    overwrite_array((void*) &cl, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    overwrite_array((void*) &cl, (void*) QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    overwrite_array((void*) &cl, p0, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p1, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    overwrite_array((void*) &cl, (void*) QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);
    // Append null character as string termination.
    overwrite_array((void*) &cl, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &clc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &clc, (void*) &cls);

/*??
    fwprintf(stdout, L"TEST dir: %ls\n", (wchar_t*) cl);
    fwprintf(stdout, L"TEST dir count: %i\n", clc);
*/

    // The encoded shell command line.
    void* ecl = *NULL_POINTER_MEMORY_MODEL;
    int eclc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ecls = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate encoded shell command line.
    allocate((void*) &ecl, (void*) &ecls, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Encode encoded shell command line.
    encode_utf_8_unicode_character_vector((void*) &ecl, (void*) &eclc, (void*) &ecls, cl, (void*) &clc);

    // Deallocate shell command line.
    deallocate_array((void*) &cl, (void*) &cls, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Initialise error number.
    // It is a global variable/ function and other operations
    // may have set some value that is not wanted here.
    errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Run a command/ program as shell command in an own process.
    //
    // The "system" function provides a simple, portable mechanism for running
    // another program; it does all three steps (fork/execv/wait) automatically.
    // The function does all the work of running a subprogram, but it doesn't
    // give much control over the details. One has to wait until the subprogram
    // terminates before being able to do anything else.
    // In the GNU C library, it always uses the default shell "sh" to run the command.
    // In particular, it searches the directories in "PATH" to find programs to execute.
    // The return value is -1 if it wasn't possible to create the shell process,
    // and otherwise is the status of the shell process.
    //
    // CAUTION! The command line MUST NOT be given as wide character array!
    // This is just because the "system" function call expects an ASCII string.
    int r = system(ecl);

    if (r == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not execute command/ program as process. A negative value was returned.");

        if (errno == EINTR) {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"The function was interrupted by delivery of a signal to the calling process.");

        } else if (errno == ECHILD) {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"There are no child processes to wait for, or the specified pid is not a child of the calling process.");

        } else if (errno == EINVAL) {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"An invalid value was provided for the options argument.");

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"An unknown error occured.");
        }

    } else {

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Successfully executed command/ program as process. The child process was left; the parent process continues.");
    }

    // Deallocate encoded shell command line.
    deallocate((void*) &ecl, (void*) &ecls, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

/*??
    //?? The following block implements the same three primitive functions
    //?? (fork/execv/wait) that the "system" function calls automatically.
    //?? The block was commented out since it did not function reliably.
    //?? The bug could not be found, but presumably it has to do with the
    //?? threads/ mutexes/ signal checker loop running in CYBOI.
    //?? Therefore, the "system" function (see above) was used for now.
    //?? It might be even better, since it is platform-neutral (portable).

    fwprintf(stdout, L"TEST pre-fork: %i\n", p0);

    // Fork a new process and remember its process identification (PID).
    // In the GNU C library, pid_t corresponds to the int type.
    // Fork clones a copy of the current (future parent) process,
    // including all data, code, environment variables, and open files.
    // The child process is a duplicate of the parent (except for a few details).
    pid_t pid = fork();

    fwprintf(stdout, L"TEST post-fork pid: %i\n", pid);

    if (pid == *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST pid == 0 pid: %i\n", pid);

        // The "fork" was successful.
        // This is the child process.
        // The following code is only executed by the child process.
        // CAUTION! Remember that BOTH processes are now executing!
        // Do therefore NOT USE logging functionality of the parent here!

        // There are two reasons why POSIX programmers call "fork":
        // 1 Create a new thread of control within the same program
        //   (which was originally only possible in POSIX by creating a new process)
        // 2 Create a new process running a different program.
        //   In this case, the call to "fork" is soon followed by a call
        //   to one of the "exec" functions.
        //
        // The general problem with making "fork" work in a multi-threaded world is:
        // "What to do with all of the threads?". There are two alternatives:
        // 1 Copy all of the threads into the new process, using "pthread_create".
        //   This causes the programmer or implementation to deal with (duplicated)
        //   threads that are suspended on system calls or that might be about to
        //   execute system calls that should not be executed in the new process.
        // 2 The other alternative is to copy only the thread that calls "fork".
        //   This creates the difficulty that the state of process-local resources
        //   is usually held in process memory.
        //   If a thread that is not calling "fork" holds a resource, that resource
        //   is NEVER RELEASED in the child process because the thread whose job
        //   it is to release the resource does not exist in the child process.
        //   The "fork" function is used only to run new programs, and the
        //   effects of calling functions that require certain resources between
        //   the call to "fork" and the call to an "exec" function are undefined.
        //   In other words, the "fork" child is only allowed to call
        //   async-signal-safe functions until it performs an "exec".
        //
        // http://www.opengroup.org/onlinepubs/009695399/functions/fork.html
        //
        // CYBOI uses many threads, one for each input mechanism.
        // The second alternative is used here. A simple "fork" was used,
        // so that only the main thread (the one calling "fork") gets
        // duplicated in the child process.
        // It was taken care, that NONE of the CYBOI threads allocates any resources.
        // All resources needed within a thread of the parent process have been
        // created at service startup and will be deallocated at service shutdown.
        // Thus, there is NO NEED to deallocate any thread resources here
        // (that is in the child process), since there are none.

        //?? TEMPORARY TEST!
        wchar_t** args = (wchar_t**) p0;
        fwprintf(stdout, L"TEST args 0: %s\n", *(args + 0));
        fwprintf(stdout, L"TEST args 1: %s\n", *(args + 1));
        fwprintf(stdout, L"TEST args 2: %s\n", *(args + 2));
        fwprintf(stdout, L"TEST args 3: %s\n", *(args + 3));
        if (*(args + 3) == *NULL_POINTER_MEMORY_MODEL) {
            fwprintf(stdout, L"TEST args 3 IS null pointer: %i\n", *(args + 3));
        } else {
            fwprintf(stdout, L"TEST args 3 is NOT null pointer: %i\n", *(args + 3));
        }

    fwprintf(stdout, L"TEST pre-exec: %i\n", p0);

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Execute file (given as first parameter) as new process image.
        //
        // The "exec" function may be used to make a child process
        // execute a new program after it has been forked.
        // By the call to "exec", the child replaces itself with the code
        // of a different program (specified by the file to be executed).
        // In other words, the new program overlays the existing program, so one
        // can never return to the original code unless the call to "exec" fails.
        // The new child process will have the same files open as the parent,
        // except those whose close-on-exec flag was set with fcntl.
        //
        // The point at which the file is closed again is not specified,
        // but is at some point before the child process exits
        // or before another child process image is executed.
        //
        // Since the program to be executed cannot be predicted, a system shell
        // is executed instead, and the program (as its command) within the shell.
        // Arguments are specified individually and handed over as strings.
        // The first argument represents the name of the program being executed.
        // That is why the SHELL_SYSTEM_EXECUTABLE constant is supplied once to name
        // the program to execute and a second time to supply a value for argv[0].
        // A null pointer must be passed as the last such argument, to indicate the end!
        //
        // Example:
        // execl(SHELL_SYSTEM_EXECUTABLE, SHELL_SYSTEM_EXECUTABLE, "-c", ARCHIVE_UNIX_SHELL_COMMAND, *NULL_POINTER_MEMORY_MODEL);
        // execl(SHELL_SYSTEM_EXECUTABLE, SHELL_SYSTEM_EXECUTABLE, "-c", "xdosemu", *NULL_POINTER_MEMORY_MODEL);
        int e = execv(SHELL_SYSTEM_EXECUTABLE, (wchar_t**) p0);

    fwprintf(stdout, L"TEST post-exec e: %i\n", e);

        // A value of -1 is returned in the event of a failure.
        if (e == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST e == -1 errno: %i\n", errno);

            //
            // The five "usual file name errors":
            //

            if (errno == EACCES) {

        fwprintf(stdout, L"TEST EACCES errno: %i\n", errno);

                // The process does not have search permission for a
                // directory component of the file name.

            } else if (errno == ENAMETOOLONG) {

        fwprintf(stdout, L"TEST ENAMETOOLONG errno: %i\n", errno);

                // This error is used when either the total length of a file name
                // is greater than PATH_MAX, or when an individual file name component
                // has a length greater than NAME_MAX.
                // In the GNU system, there is no imposed limit on overall file name length,
                // but some file systems may place limits on the length of a component.

            } else if (errno == ENOENT) {

        fwprintf(stdout, L"TEST ENOENT errno: %i\n", errno);

                // This error is reported when a file referenced as a directory component
                // in the file name doesn't exist, or when a component is a symbolic link
                // whose target file does not exist.

            } else if (errno == ENOTDIR) {

        fwprintf(stdout, L"TEST ENOTDIR errno: %i\n", errno);

                // A file that is referenced as a directory component in the file name
                // exists, but it isn't a directory.

            } else if (errno == ELOOP) {

        fwprintf(stdout, L"TEST ELOOP errno: %i\n", errno);

                // Too many symbolic links were resolved while trying to look up the file name.
                // The system has an arbitrary limit on the number of symbolic links
                // that may be resolved in looking up a single file name,
                // as a primitive way to detect loops.

            //
            // Three additional, "exec"-specific errors.
            //

            } else if (errno == E2BIG) {

        fwprintf(stdout, L"TEST E2BIG errno: %i\n", errno);

                // The combined size of the new program's argument list and
                // environment list is larger than ARG_MAX bytes.
                // The GNU system has no specific limit on the argument list size,
                // so this error code cannot result, but one may get ENOMEM
                // instead if the arguments are too big for available memory.

            } else if (errno == ENOEXEC) {

        fwprintf(stdout, L"TEST ENOEXEC errno: %i\n", errno);

                // The specified file can't be executed because
                // it isn't in the right format.

            } else if (errno == ENOMEM) {

        fwprintf(stdout, L"TEST ENOMEM errno: %i\n", errno);

                // Executing the specified file requires more storage than is available.

            //
            // Other errors.
            //

            } else if (errno == EFAULT) {

        fwprintf(stdout, L"TEST EFAULT errno: %i\n", errno);

                // Bad address; an invalid pointer was detected.
                // In the GNU system, this error never happens;
                // one gets a signal instead.
            }

            // Exit the child process.
            //
            // The "exec" call in the child process doesn't return if it is successful,
            // which means the child has to exit independently from its original parent.
            // So the following call to "_exit" should NORMALLY NOT be reached.
            // If "exec" fails, something must be done to make the child process terminate.
            // Just returning a bad status code with "return" would leave TWO PROCESSES
            // running the original program. Instead, the right behavior is for the
            // child process to report failure to its parent process.
            //
            // CAUTION! Call "_exit" to accomplish this!
            // The reason for using "_exit" instead of "exit" is to avoid flushing
            // fully buffered streams such as stdout. The buffers of these streams
            // probably contain data that was copied from the parent process by the
            // fork, data that will be output eventually by the parent process.
            // Calling "exit" in the child would output the data twice.
            //
            // Another reason why _exit() should be called instead of exit(),
            // is that exit() calls all the installed atexit() handlers, including
            // the one that shuts down the X connection with the X display.
            // So if the child calls exit(), it shuts down the parents X
            // connection and the parent will no longer be able to display.
            //
            // The C library function exit() calls the kernel system call _exit()
            // internally. The kernel system call _exit() will cause the kernel to
            // close descriptors, free memory, and perform the kernel terminating
            // process clean-up. The C library function exit() call will flush I/O
            // buffers and perform aditional clean-up before calling _exit() internally.
            //
            // Set return value to 1, indicating that an error occured in the child process.
            _exit(*NUMBER_1_INTEGER_MEMORY_MODEL);
        }

    fwprintf(stdout, L"TEST post-exit errno: %i\n", errno);

    } else if (pid < *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST pid < 0 pid: %i\n", pid);

        // The "fork" did not succeed. An error occured.
        // This is still the parent process.
        // A child process could not be created.

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not execute command as process. The process fork failed.");

    } else {

        // The "fork" was successful.
        // This is the parent process.
        // The following code is only executed by the parent process.
        // A pid > 0 represents the child process's id.

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Executed command as process. The process fork succeeded. Now waiting for the child process to exit.");

    fwprintf(stdout, L"TEST pid > 0 pid: %i\n", pid);

        // Request status information from child process.
        // In the GNU C library, pid_t corresponds to the int type.
        waitpid(pid, (int*) *NULL_POINTER_MEMORY_MODEL, *NUMBER_0_INTEGER_MEMORY_MODEL);

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"The child process exited. Continue executing parent process.");

    fwprintf(stdout, L"TEST post-waitpid pid: %i\n", pid);
    }
*/
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* EXECUTE_SOURCE */
#endif
