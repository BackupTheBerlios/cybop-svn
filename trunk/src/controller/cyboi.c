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
 * @version $RCSfile: cyboi.c,v $ $Revision: 1.47 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SOURCE
#define CYBOI_SOURCE

#include <string.h>

#include "../constant/model/cyboi/operation_mode_cyboi_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../controller/globaliser.c"
#include "../controller/helper.c"
#include "../controller/informant.c"
#include "../controller/manager.c"
#include "../controller/optionaliser.c"
#include "../controller/orienter.c"
#include "../controller/tester.c"
#include "../controller/unglobaliser.c"
#include "../variable/log_setting.c"

//
// This is the main file of the Cybernetics Oriented Interpreter (CYBOI).
// CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
// which adhere to the Extensible Markup Language (XML) syntax.
//

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
    // There is no point in freeing blocks at the end of an application programme,
    // because all of the programme's space is given back to the operating system
    // when the process terminates.
    // Of course, all dynamically allocated memory should also be freed properly.
    // However, if some memory to be freed is forgotten accidentally, it will
    // not harm the operating system, as the memory occupied by the application
    // will be freed automatically on process shutdown.
    //
    // TODO: YET TO ANSWER: How is that with forgotten threads?
    // Are they killed automatically when a process is shut down?

    // Return 1 to indicate an error, by default.
    int r = *NUMBER_1_INTEGER_MEMORY_MODEL;

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        // log_write_terminated_message(stdout, L"Information: Execute cyboi.\n");

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
        // especially for the standard streams stdin, stdout, and stdout.
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
        orient((void*) stdin, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
        orient((void*) stdout, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
        orient((void*) stderr, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

        // The operation mode.
        //
        // CAUTION! It is initialised with the help operation mode,
        // in order to display the help message by default,
        // if no command line argument is given by the user.
        int m = *HELP_OPERATION_MODE_CYBOI_MODEL;

        // The cybol knowledge file path.
        void* k = *NULL_POINTER_MEMORY_MODEL;
        int kc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int ks = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Allocate cybol knowledge file path.
        allocate((void*) &k, (void*) &ks, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Optionalise command line argument options.
        optionalise((void*) &m, (void*) &k, (void*) &kc, (void*) &ks, (void*) LOG_LEVEL, (void*) &LOG_OUTPUT, (void*) p1, (void*) &p0);

        // Orient log output file stream.
        //
        // CAUTION! This can only be done AFTER having read the command line options,
        // since one of the options determines the log output file name.
        orient((void*) LOG_OUTPUT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Run cyboi.");
        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Globalised global variables already.");
        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Optionalised log file already.");

        if (m == *VERSION_OPERATION_MODE_CYBOI_MODEL) {

            inform((void*) stdout);

        } else if (m == *HELP_OPERATION_MODE_CYBOI_MODEL) {

            help((void*) stdout);

        } else if (m == *TEST_OPERATION_MODE_CYBOI_MODEL) {

            // Call test function.
            test();

        } else if (m == *KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL) {

            if ((k != *NULL_POINTER_MEMORY_MODEL) && (kc >= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                // Manage system startup and shutdown using the given cybol knowledge file.
                manage(k, (void*) &kc);

            } else {

                log_write_terminated_message(stdout, L"Error: Could not execute cyboi in knowledge operation mode. A cybol file name needs to be given behind the '--knowledge' command line argument.\n");

                help((void*) stdout);
            }
        }

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Deoptionalise log file yet.");
        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Unglobalise global variables yet.");
        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Exit cyboi normally afterwards.");

        // Deoptionalise command line argument options.
        // CAUTION! Hand over the LOG_OUTPUT variable AS REFERENCE!
        // This is necessary, because it is reset to null internally.
        // If this was not done, subsequent logger calls would cause segmentation faults,
        // because the null pointer test within the logger would be successful,
        // even though the LOG_OUTPUT pointer would be invalid.
        deoptionalise((void*) &LOG_OUTPUT);

        // Deallocate cybol knowledge file path.
        deallocate((void*) &k, (void*) &ks, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Shutdown global variables.
        unglobalise();

        log_write_terminated_message(stdout, L"\nInformation: Exit cyboi normally.\n");

        // Set return value to 0, to indicate proper shutdown.
        r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    } else {

        log_write_terminated_message(stdout, L"Error: Could not execute cyboi. The command line argument vector is null.\n");
    }

    return r;
}

/* CYBOI_SOURCE */
#endif
