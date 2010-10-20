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

#ifndef PREPROCESSOR_TESTER
#define PREPROCESSOR_TESTER

#include "../../logger/logger.c"

/**
 * Tests the preprocessor directives.
 */
void test_preprocessor_directives() {

    log_write_terminated_message((void*) stdout, L"Test preprocessor directives:\n");

#ifdef GNU_LINUX_OPERATING_SYSTEM
    log_write_terminated_message((void*) stdout, L"GNU_LINUX\n");
#elif WINDOWS_OPERATING_SYSTEM
    log_write_terminated_message((void*) stdout, L"WINDOWS\n");
#else
    log_write_terminated_message((void*) stdout, L"OTHER\n");
/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/**
 * Tests the preprocessor.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_preprocessor() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test preprocessor.");

//    test_preprocessor_directives();
}

/* PREPROCESSOR_TESTER */
#endif
