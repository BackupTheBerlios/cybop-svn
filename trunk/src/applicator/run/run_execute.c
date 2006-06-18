/*
 * $RCSfile: run_execute.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2006-06-18 14:57:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RUN_EXECUTE_SOURCE
#define RUN_EXECUTE_SOURCE

#ifdef LINUX_OPERATING_SYSTEM
#include <errno.h>
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

    fprintf(stdout, "TEST pre-fork: %i\n", p0);

    // Fork a new process and remember its process identification (PID).
    // In the GNU C library, pid_t corresponds to the int type.
    // Fork clones a copy of the current (future parent) process,
    // including all data, code, environment variables, and open files.
    // The child process is a duplicate of the parent (except for a few details).
    pid_t pid = fork();

    fprintf(stdout, "TEST post-fork pid: %i\n", pid);

    if (pid == 0) {

    fprintf(stdout, "TEST pid == 0 pid: %i\n", pid);

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
        char** args = (char**) p0;
        fprintf(stdout, "TEST args 0: %s\n", *(args + 0));
        fprintf(stdout, "TEST args 1: %s\n", *(args + 1));
        fprintf(stdout, "TEST args 2: %s\n", *(args + 2));
        fprintf(stdout, "TEST args 3: %s\n", *(args + 3));
        if (*(args + 3) == NULL_POINTER) {
            fprintf(stdout, "TEST args 3 IS null pointer: %i\n", *(args + 3));
        } else {
            fprintf(stdout, "TEST args 3 is NOT null pointer: %i\n", *(args + 3));
        }

    fprintf(stdout, "TEST pre-exec: %i\n", p0);

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        errno = 0;

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
        // That is why the SYSTEM_SHELL constant is supplied once to name the
        // program to execute and a second time to supply a value for argv[0].
        // A null pointer must be passed as the last such argument, to indicate the end!
        //
        // Example:
        // execl(SYSTEM_SHELL, SYSTEM_SHELL, "-c", ARCHIVE_UNIX_SHELL_COMMAND, NULL_POINTER);
        // execl(SYSTEM_SHELL, SYSTEM_SHELL, "-c", "xdosemu", NULL_POINTER);
        int e = execv(SYSTEM_SHELL, (char**) p0);

    fprintf(stdout, "TEST post-exec e: %i\n", e);

        // A value of -1 is returned in the event of a failure.
        if (e == -1) {

    fprintf(stdout, "TEST e == -1 errno: %i\n", errno);

            //
            // The five "usual file name errors":
            //

            if (errno == EACCES) {

        fprintf(stdout, "TEST EACCES errno: %i\n", errno);

                // The process does not have search permission for a
                // directory component of the file name.

            } else if (errno == ENAMETOOLONG) {

        fprintf(stdout, "TEST ENAMETOOLONG errno: %i\n", errno);

                // This error is used when either the total length of a file name
                // is greater than PATH_MAX, or when an individual file name component
                // has a length greater than NAME_MAX.
                // In the GNU system, there is no imposed limit on overall file name length,
                // but some file systems may place limits on the length of a component.

            } else if (errno == ENOENT) {

        fprintf(stdout, "TEST ENOENT errno: %i\n", errno);

                // This error is reported when a file referenced as a directory component
                // in the file name doesn't exist, or when a component is a symbolic link
                // whose target file does not exist.

            } else if (errno == ENOTDIR) {

        fprintf(stdout, "TEST ENOTDIR errno: %i\n", errno);

                // A file that is referenced as a directory component in the file name
                // exists, but it isn't a directory.

            } else if (errno == ELOOP) {

        fprintf(stdout, "TEST ELOOP errno: %i\n", errno);

                // Too many symbolic links were resolved while trying to look up the file name.
                // The system has an arbitrary limit on the number of symbolic links
                // that may be resolved in looking up a single file name,
                // as a primitive way to detect loops.

            //
            // Three additional, "exec"-specific errors.
            //

            } else if (errno == E2BIG) {

        fprintf(stdout, "TEST E2BIG errno: %i\n", errno);

                // The combined size of the new program's argument list and
                // environment list is larger than ARG_MAX bytes.
                // The GNU system has no specific limit on the argument list size,
                // so this error code cannot result, but one may get ENOMEM
                // instead if the arguments are too big for available memory.

            } else if (errno == ENOEXEC) {

        fprintf(stdout, "TEST ENOEXEC errno: %i\n", errno);

                // The specified file can't be executed because
                // it isn't in the right format.

            } else if (errno == ENOMEM) {

        fprintf(stdout, "TEST ENOMEM errno: %i\n", errno);

                // Executing the specified file requires more storage than is available.

            //
            // Other errors.
            //

            } else if (errno == EFAULT) {

        fprintf(stdout, "TEST EFAULT errno: %i\n", errno);

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
            _exit(1);
        }

    fprintf(stdout, "TEST post-exit errno: %i\n", errno);

    } else if (pid < 0) {

    fprintf(stdout, "TEST pid < 0 pid: %i\n", pid);

        // The "fork" did not succeed. An error occured.
        // This is still the parent process.
        // A child process could not be created.

        log_message_debug("Error: Could not execute command as process. The process fork failed.");

    } else {

        // The "fork" was successful.
        // This is the parent process.
        // The following code is only executed by the parent process.
        // A pid > 0 represents the child process's id.

        log_message_debug("Information: Executed command as process. The process fork succeeded. Now waiting for the child process to exit.");

    fprintf(stdout, "TEST pid > 0 pid: %i\n", pid);

        // Request status information from child process.
        // In the GNU C library, pid_t corresponds to the int type.
        waitpid(pid, (int*) NULL_POINTER, 0);

        log_message_debug("Information: The child process exited. Continue executing parent process.");

    fprintf(stdout, "TEST post-waitpid pid: %i\n", pid);
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* RUN_EXECUTE_SOURCE */
#endif
