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
 * @version $RCSfile: tester.c,v $ $Revision: 1.35 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TESTER_SOURCE
#define TESTER_SOURCE

#include "../controller/tester/accessor_tester.c"
#include "../controller/tester/arithmetiser_tester.c"
#include "../controller/tester/assembler_tester.c"
#include "../controller/tester/communicator_tester.c"
#include "../controller/tester/comparator_tester.c"
#include "../controller/tester/constant_tester.c"
#include "../controller/tester/converter_tester.c"
#include "../controller/tester/copier_tester.c"
#include "../controller/tester/finder_tester.c"
#include "../controller/tester/logger_tester.c"
#include "../controller/tester/memoriser_tester.c"
#include "../controller/tester/modifier_tester.c"
#include "../controller/tester/pointer_tester.c"
#include "../controller/tester/preprocessor_tester.c"
#include "../controller/tester/variable_tester.c"

//
// Examples for source code testing via log messages.
//
// fwprintf(stdout, L"TEST integer: %i\n", x);
// fwprintf(stdout, L"TEST pointer: %i\n", x);
// fwprintf(stdout, L"TEST w_char array string: %ls\n", (wchar_t*) x);
// fwprintf(stdout, L"TEST string literal: %ls\n", "string");
//

//
// Write some character data into a test file.
//

/*
    // --- START TEST ---
    // The log file name.
    char* n = "http_response";
    // The log file status flags.
    int status = O_TRUNC | O_CREAT | O_WRONLY;
    // The log file.
    int f = open(n, status);

    if (f >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The file owner.
        int o = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // The file group.
        int g = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Set file owner.
        chown(n, o, g);

        // The file access rights.
        //?? TODO: When trying to cross-compile cyboi for windows,
        //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
        int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

        // Set file access rights.
        chmod(n, r);

        // Log html to output.
        write(f, p13, *((int*) p14));

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        log_write_terminated_message(stdout, L"Error: Could not open socket sending http_response file. A file error occured.\n");
    }
    // --- END TEST ---
*/

/**
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test cyboi.");

    // How to use printf to check parameter values.
    // The printf function uses stdout for output, but nothing appears on console.
    // Therefore, fprintf is used and stdout is given for output.
    // Example:
    // int x = *NUMBER_2_INTEGER_MEMORY_MODEL;
    // fwprintf(stdout, L"The value of x is: %d\n", x);

    // Globals.
    test_constant();
    test_variable();
    test_assembler();
    test_pointer();
    test_preprocessor();

    // Logger.
    test_logger();

    // Executor.
    test_accessor();
    test_arithmetiser();
    test_communicator();
    test_comparator();
    test_converter();
    test_copier();
    test_finder();
    test_memoriser();
    test_modifier();
}

/* TESTER_SOURCE */
#endif
