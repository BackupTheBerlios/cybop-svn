/*
 * $RCSfile: cyboi.c,v $
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
 * This is the main file of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.32 $ $Date: 2008-05-12 10:58:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <string.h>
#include "../controller/globaliser.c"
#include "../controller/manager.c"
#include "../controller/optionaliser.c"
#include "../controller/orienter.c"
#include "../controller/tester.c"
#include "../globals/constants/cyboi/cyboi_identification_constants.c"
#include "../globals/constants/cyboi/cyboi_operation_mode_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/variables/log_variables.c"

/**
 * The main entry function.
 *
 * It reads the command line parameters that were handed over and
 * takes care about basic system parameters:
 * - create global variables
 * - create internal memory
 * - handle system
 * - destroy internal memory
 * - destroy global variables
 *
 * @param p0 the argument count (argc)
 * @param p1 the argument vector (argv), the first argument being the command
 * @return the return value (0 for normal shutdown; 1 for error)
 */
int main(int p0, char** p1) {

    // One note about dynamic memory allocation:
    // There is no point in freeing blocks at the end of a program, because all
    // of the program's space is given back to the system when the process terminates.
    // Of course, all dynamically allocated memory should also be freed properly.
    // However, if some memory to be freed is forgotten, it will not harm
    // the operating system, as it will be freed automatically on process shutdown.
    //
    // YET TO ANSWER: How is that with forgotten threads?
    // Are they killed automatically when a process is shut down?

    // Return 1 to indicate an error, by default.
    int r = *NUMBER_1_INTEGER;

    if (p1 != *NULL_POINTER) {

        // fputws(L"Information: Execute cyboi.\n", stdout);

        // Startup global variables.
        globalise();

        // Orient streams.
        //
        // CAUTION! This is important for internationalisation!
        // A stream can be used either for wide operations or for normal operations.
        // Once it is decided there is no way back.
        // Only a call to freopen or freopen64 can reset the orientation.
        //
        // The orientation can be decided in three ways:
        // * If any of the normal character functions is used (this includes the fread and fwrite functions) the stream is marked as not wide oriented.
        // * If any of the wide character functions is used the stream is marked as wide oriented.
        // * The fwide function can be used to set the orientation either way.
        //
        // It is important to never mix the use of wide and not wide operations on a stream.
        // There are no diagnostics issued. The application behavior will simply be strange
        // or the application will simply crash. The "fwide" function can help avoiding this.
        //
        // int function>fwide/function> (FILE *stream, int mode)
        // The fwide function can be used to set and query the state of the orientation of the stream stream.
        // If the mode parameter has a positive value the streams get wide oriented, for negative values narrow oriented.
        // It is not possible to overwrite previous orientations with fwide.
        // I.e., if the stream stream was already oriented before the call nothing is done.
        //
        // If mode is zero the current orientation state is queried and nothing is changed.
        // The fwide function returns a negative value, zero, or a positive value if the stream is narrow, not at all, or wide oriented respectively.
        // This function was introduced in Amendment 1 to ISO C90 and is declared in wchar.h.
        //
        // It is generally a good idea to orient a stream as early as possible.
        // This can prevent surprise especially for the standard streams stdin, stdout, and stderr.
        // If some library function in some situations uses one of these streams
        // and this use orients the stream in a different way the rest of the
        // application expects it one might end up with hard to reproduce errors.
        // Remember that no errors are signal if the streams are used incorrectly.
        // Leaving a stream unoriented after creation is normally only necessary for
        // library functions which create streams which can be used in different contexts.
        //
        // When writing code which uses streams and which can be used in different contexts
        // it is important to query the orientation of the stream before using it
        // (unless the rules of the library interface demand a specific orientation).
        // The following little, silly function illustrates this.
        //
        // void print_f (FILE *fp) {
        //     if (fwide (fp, 0)  0)
        //         /* Positive return value means wide orientation. */
        //         fputwc (L'f', fp);
        //     else
        //         fputc ('f', fp);
        // }
        //
        // Note that in this case the function print_f decides about
        // the orientation of the stream if it was unoriented before
        // (will not happen if the advise above is followed).
        //
        // The encoding used for the wchar_t values is unspecified
        // and the user must not make any assumptions about it.
        // For I/O of wchar_t values this means that it is impossible
        // to write these values directly to the stream.
        // This is not what follows from the ISO C locale model either.
        // What happens instead is that the bytes read from or written
        // to the underlying media are first converted into the internal
        // encoding chosen by the implementation for wchar_t.
        // The external encoding is determined by the LC_CTYPE category
        // of the current locale or by the ccs part of the mode specification
        // given to fopen, fopen64, freopen, or freopen64.
        // How and when the conversion happens is unspecified and it happens invisible to the user.
        //
        // Since a stream is created in the unoriented state
        // it has at that point no conversion associated with it.
        // The conversion which will be used is determined by the
        // LC_CTYPE category selected at the time the stream is oriented.
        // If the locales are changed at the runtime this might
        // produce surprising results unless one pays attention.
        // This is just another good reason to orient the stream
        // explicitly as soon as possible, perhaps with a call to fwide.
        orient((void*) NUMBER_1_INTEGER);

        // The operation mode.
        //
        // CAUTION! It is initialised with the help operation mode,
        // in order to display the help message by default,
        // if no command line argument is given by the user.
        int m = *HELP_CYBOI_OPERATION_MODE;

        // The cybol knowledge file path.
        void* k = *NULL_POINTER;
        int kc = *NUMBER_0_INTEGER;

        // Optionalise command line argument options.
        optionalise((void*) &m, (void*) &k, (void*) &kc, (void*) &LOG_LEVEL, (void*) &LOG_OUTPUT, (void*) p1, (void*) &p0);

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Run cyboi.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Globalised global variables already.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Optionalised log file already.");

        if (m == *VERSION_CYBOI_OPERATION_MODE) {

            // Write cyboi name, version, copyright and licence to standard output.
            write(fileno(stdout), (void*) CYBOI_NAME, *CYBOI_NAME_COUNT);
            write(fileno(stdout), (void*) SPACE_CHARACTER, *PRIMITIVE_COUNT);
            write(fileno(stdout), (void*) CYBOI_VERSION, *CYBOI_VERSION_COUNT);
            write(fileno(stdout), (void*) LINE_FEED_CONTROL_CHARACTER, *PRIMITIVE_COUNT);
            write(fileno(stdout), (void*) CYBOI_COPYRIGHT, *CYBOI_COPYRIGHT_COUNT);
            write(fileno(stdout), (void*) LINE_FEED_CONTROL_CHARACTER, *PRIMITIVE_COUNT);
            write(fileno(stdout), (void*) CYBOI_LICENCE, *CYBOI_LICENCE_COUNT);
            write(fileno(stdout), (void*) LINE_FEED_CONTROL_CHARACTER, *PRIMITIVE_COUNT);

        } else if (m == *HELP_CYBOI_OPERATION_MODE) {

            // Write cyboi help message to standard output.
            write(fileno(stdout), (void*) CYBOI_HELP, *CYBOI_HELP_COUNT);
            write(fileno(stdout), (void*) LINE_FEED_CONTROL_CHARACTER, *PRIMITIVE_COUNT);

        } else if (m == *TEST_CYBOI_OPERATION_MODE) {

            // Call test function.
            test();

        } else if (m == *KNOWLEDGE_CYBOI_OPERATION_MODE) {

            if ((k != *NULL_POINTER) && (kc >= *NUMBER_0_INTEGER)) {

                // Manage system startup and shutdown using the given cybol knowledge file.
                manage(k, (void*) &kc);

            } else {

                fputws(L"Error: Could not execute cyboi in knowledge operation mode. A cybol file name needs to be given behind the '--knowledge' command line argument.\n", stdout);

                // Write cyboi help message to standard output.
                write(fileno(stdout), (void*) CYBOI_HELP, *CYBOI_HELP_COUNT);
                write(fileno(stdout), (void*) LINE_FEED_CONTROL_CHARACTER, *PRIMITIVE_COUNT);
            }
        }

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Deoptionalise log file yet.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Unglobalise global variables yet.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Exit cyboi normally afterwards.");

        // Deoptionalise command line argument options.
        deoptionalise((void*) &LOG_OUTPUT);

        // Shutdown global variables.
        unglobalise();

        // fputws(L"Information: Exit cyboi normally.\n", stdout);

        // Set return value to 0, to indicate proper shutdown.
        r = *NUMBER_0_INTEGER;

    } else {

        fputws(L"Error: Could not execute cyboi. The command line argument vector is null.\n", stdout);
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
