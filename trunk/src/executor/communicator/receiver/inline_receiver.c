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

#ifndef INLINE_RECEIVER_SOURCE
#define INLINE_RECEIVER_SOURCE

#include <stdio.h>

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Receives an inline stream and writes it into an array.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the details (Hand over as reference!)
 * @param p4 the details count
 * @param p5 the details size
 * @param p6 the message
 * @param p7 the message count
 * @param p8 the language
 * @param p9 the language count
 */
void receive_inline(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive inline.");

    // The data array, count, size.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate data array.
    allocate_array((void*) &a, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Receive data array, count, size.
    overwrite_array((void*) &a, p6, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p7, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &c, (void*) &s);

    // CAUTION! Do NOT try to decode from UTF-8 or other formats here!
    // In other words, do NOT call a function such as this:
    // decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, rm, (void*) &rmc);
    //
    // The reason is that each cybol file is already decoded from a multibyte
    // character array into a wide character array at once when being read.
    // Therefore, data do NOT have to be decoded once more when being
    // evaluated as inline wide character array.

    // Decode data array according to given document type.
    decode(p0, p1, p2, p3, p4, p5, a, (void*) &c, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p8, p9);

    // Deallocate data array.
    deallocate_array((void*) &a, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* INLINE_RECEIVER_SOURCE */
#endif
