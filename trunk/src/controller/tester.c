/*
 * Copyright (C) 1999-2010. Christian Heller.
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

/*??
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
*/
/*??
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/memory/double_memory_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
*/
#include "../controller/tester/accessor_tester.c"
#include "../controller/tester/arithmetiser_tester.c"
#include "../controller/tester/assembler_tester.c"
#include "../controller/tester/communicator_tester.c"
#include "../controller/tester/comparator_tester.c"
#include "../controller/tester/constant_tester.c"
#include "../controller/tester/converter_tester.c"
#include "../controller/tester/logger_tester.c"
#include "../controller/tester/memoriser_tester.c"
#include "../controller/tester/pointer_tester.c"
#include "../controller/tester/preprocessor_tester.c"
#include "../controller/tester/variable_tester.c"
/*??
#include "../executor/accessor/getter/compound_getter.c"
#include "../executor/comparator/array_equality_comparator.c"
#include "../executor/converter/decoder/integer_decoder.c"
#include "../executor/converter/encoder/integer_encoder.c"
#include "../executor/converter/decoder.c"
#include "../executor/converter/encoder.c"
#include "../executor/memoriser/allocator/array_allocator.c"
#include "../executor/memoriser/deallocator/array_deallocator.c"
#include "../executor/memoriser/allocator.c"
#include "../executor/memoriser/deallocator.c"
#include "../variable/primitive_type_size.c"
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
    test_memoriser();
}

/* TESTER_SOURCE */
#endif
