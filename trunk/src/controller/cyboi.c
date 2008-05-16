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
 * @version $Revision: 1.34 $ $Date: 2008-05-16 23:15:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <string.h>
#include "../controller/globaliser.c"
#include "../controller/helper.c"
#include "../controller/informant.c"
#include "../controller/manager.c"
#include "../controller/optionaliser.c"
#include "../controller/orienter.c"
#include "../controller/tester.c"
#include "../globals/constants/cyboi/cyboi_operation_mode_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/variables/log_variables.c"

/**
 * The main entry function.
 *
 * @param p0 the arguments count (argc)
 * @param p1 the arguments vector (argv), the first argument being the command;
 *           the pointer array p1 contains strings, i.e. character arrays/ pointers;
 *           since cyboi uses wide characters everywhere possible,
 *           and also for standard input- and output streams,
 *           it can be expected that argv contains multibyte strings which
 *           have to be converted into wide character strings before being processed;
 *           this is done in module "optionaliser.c"
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
        // A stream can be used EITHER for wide operations OR for normal operations.
        // Once it is decided there is no way back.
        // Only a call to freopen or freopen64 can reset the orientation.
        //
        // The orientation can be decided in three ways:
        // 1 If any of the normal character functions is used
        //   (this includes the fread and fwrite functions)
        //   the stream is marked as not wide oriented.
        // 2 If any of the wide character functions is used the stream is marked as wide oriented.
        // 3 The fwide function can be used to set the orientation either way.
        //
        // It is important to NEVER MIX the use of wide and not wide operations on a stream!
        // There are no diagnostics issued. The application behavior will simply be strange
        // or the application will simply crash. The "fwide" function can help avoiding this.
        // It can be used to set and query the state of the orientation of a stream.
        // Note, that it is NOT possible to overwrite previous orientations with "fwide".
        // That is, if a stream was already oriented before, NOTHING is done!
        //
        // It is generally a good idea to orient a stream as early as possible.
        // This can prevent surprise and hard to reproduce errors,
        // especially for the standard streams stdin, stdout, and stderr.
        //
        // Since a stream is created in the unoriented state
        // it has at that point no conversion associated with it.
        // The conversion which will be used is determined by the
        // LC_CTYPE category selected at the time the stream is oriented.
        // If the locales are changed at the runtime this might
        // produce surprising results unless one pays attention.
        // This is just another good reason to orient the stream
        // explicitly as soon as possible, perhaps with a call to "fwide".
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
        // CAUTION! The orientations of the following streams have to be set HERE,
        // because command line parameters will be expected to be multibyte characters,
        // read from the standard input stream in function "optionalise" further below.
        // They will also get converted into wide characters of type "wchar_t" there.
        orient((void*) stdin, (void*) NUMBER_1_INTEGER);
        orient((void*) stdout, (void*) NUMBER_1_INTEGER);
        orient((void*) stderr, (void*) NUMBER_1_INTEGER);

        // The operation mode.
        //
        // CAUTION! It is initialised with the help operation mode,
        // in order to display the help message by default,
        // if no command line argument is given by the user.
        int m = *HELP_CYBOI_OPERATION_MODE;

        // The cybol knowledge file path.
        void* k = *NULL_POINTER;
        int kc = *NUMBER_0_INTEGER;
        int ks = *NUMBER_0_INTEGER;

        // Allocate cybol knowledge file path.
        allocate((void*) &k, (void*) &ks, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST pre: %i\n", k);

        // Optionalise command line argument options.
        optionalise((void*) &m, (void*) k, (void*) &kc, (void*) &ks, (void*) LOG_LEVEL, (void*) &LOG_OUTPUT, (void*) p1, (void*) &p0);

    fwprintf(stderr, L"TEST post: %i\n", k);

        // Orient log output file stream.
        //
        // CAUTION! This can only be done AFTER having read the command line options,
        // since one of the options determines the log output file name.
        orient((void*) LOG_OUTPUT, (void*) NUMBER_1_INTEGER);

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Run cyboi.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Globalised global variables already.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Optionalised log file already.");

        if (m == *VERSION_CYBOI_OPERATION_MODE) {

            inform((void*) stdout);

        } else if (m == *HELP_CYBOI_OPERATION_MODE) {

            help((void*) stdout);

        } else if (m == *TEST_CYBOI_OPERATION_MODE) {

            // Call test function.
            test();

        } else if (m == *KNOWLEDGE_CYBOI_OPERATION_MODE) {

            if ((k != *NULL_POINTER) && (kc >= *NUMBER_0_INTEGER)) {

                // Manage system startup and shutdown using the given cybol knowledge file.
                manage(k, (void*) &kc);

            } else {

                fputws(L"Error: Could not execute cyboi in knowledge operation mode. A cybol file name needs to be given behind the '--knowledge' command line argument.\n", stdout);

                help((void*) stdout);
            }
        }

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Deoptionalise log file yet.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Unglobalise global variables yet.");
        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Exit cyboi normally afterwards.");

        // Deoptionalise command line argument options.
        deoptionalise((void*) LOG_OUTPUT);

        // Deallocate cybol knowledge file path.
        deallocate((void*) &k, (void*) &ks, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

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
