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

#ifndef COMPARATOR_TESTER
#define COMPARATOR_TESTER

#include "../../logger/logger.c"

/**
 * Tests the ascii character - wide character equality.
 */
void test_ascii_character_wide_character_equality() {

    log_write_terminated_message((void*) stdout, L"Test ascii character - wide character equality:\n");

    char test = 'a';

    if (test = *LATIN_SMALL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL) {

        log_write_terminated_message((void*) stdout, L"Characters ARE equal.\n");

    } else {

        log_write_terminated_message((void*) stdout, L"Characters are NOT equal.\n");
    }
}

/**
 * Tests the comparator.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_comparator() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test comparator.");

//    test_ascii_character_wide_character_equality();
}

/* COMPARATOR_TESTER */
#endif
