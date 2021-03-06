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
 * @version $RCSfile: inline_communicator.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INLINE_SENDER_SOURCE
#define INLINE_SENDER_SOURCE

#include <stdio.h>

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Sends an inline stream that was read from an array.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source wide character array
 * @param p4 the source wide character array count
 */
void send_inline(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send inline.");

    overwrite_array(p0, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
}

/**
 * Sends a knowledge model to the receiving array.
 *
 * @param p0 the destination receiving wide character array (Hand over as reference!)
 * @param p1 the destination receiving wide character array count
 * @param p2 the destination receiving wide character array size
 * @param p3 the source message abstraction
 * @param p4 the source message abstraction count
 * @param p5 the source message model
 * @param p6 the source message model count
 * @param p7 the source message details
 * @param p8 the source message details count
 * @param p9 the source metadata abstraction
 * @param p10 the source metadata abstraction count
 * @param p11 the source metadata model
 * @param p12 the source metadata model count
 * @param p13 the source metadata details
 * @param p14 the source metadata details count
 * @param p15 the language
 * @param p16 the language count
 */
void apply_send_inline(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply send inline message.");

    // The converted array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;

    // Allocate array.
    allocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Encode source knowledge model into array.
    encode((void*) &a, ac, as,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p3, p4, p5, p6, p7, p8,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p9, p10, p11, p12, p13, p14,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p15, p16);

/*??
    fwprintf(stdout, L"TEST sending inline a: %ls\n", (wchar_t*) a);
    fwprintf(stdout, L"TEST sending inline ac: %i\n", *((int*) ac));
*/

    // Write encoded array into destination array.
    send_data(p0, p1, p2, a, ac, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT);

/*??
    fwprintf(stdout, L"TEST sending inline p0: %ls\n", *((wchar_t**) p0));
    fwprintf(stdout, L"TEST sending inline p1: %i\n", *((int*) p1));
*/

    // Deallocate array.
    deallocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* INLINE_SENDER_SOURCE */
#endif
