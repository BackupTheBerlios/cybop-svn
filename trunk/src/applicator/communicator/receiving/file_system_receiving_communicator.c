/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: file_system_receiving_communicator.c,v $ $Revision: 1.12 $ $Date: 2008-11-03 23:16:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SYSTEM_RECEIVING_COMMUNICATOR_SOURCE
#define FILE_SYSTEM_RECEIVING_COMMUNICATOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/accessor/compound_accessor.c"
#include "../../../memoriser/allocator.c"
#include "../../../memoriser/array.c"
#include "../../../memoriser/communicator.c"
#include "../../../memoriser/converter/cybol_converter.c"
#include "../../../memoriser/converter.c"

/**
 * Receives a message from the file system.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count
 * @param p2 the model size
 * @param p3 the details (Hand over as reference!)
 * @param p4 the details count
 * @param p5 the details size
 * @param p6 the message (file name)
 * @param p7 the message (file name) count
 * @param p8 the language
 * @param p9 the language count
 */
void communicate_receiving_file_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive file system message.");

    // The read model.
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    int rmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int rms = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate read model.
    allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Read persistent byte stream over channel.
    read_data((void*) &rm, (void*) &rmc, (void*) &rms, p6, p7, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);

    fwprintf(stderr, L"TEST receive file system rms: %i\n", rms);
    fwprintf(stderr, L"TEST receive file system rmc: %i\n", rmc);
//??    fwprintf(stderr, L"TEST receive file system rm: %s\n", (char*) rm);

    // The wide character model.
    void* wm = *NULL_POINTER_MEMORY_MODEL;
    int wmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int wms = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate wide character model.
    allocate((void*) &wm, (void*) &wms, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, rm, (void*) &rmc);
    //?? TEST only! DELETE LATER!
//??    decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, (void*) ASCII_CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST receive file system wmc: %i\n", wmc);
//??    fwprintf(stderr, L"TEST receive file system wm: %ls\n", (wchar_t*) wm);

    // Deallocate read model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST receive file system l: %ls\n", (wchar_t*) p8);
    fwprintf(stderr, L"TEST receive file system lc: %i\n", *((int*) p9));

    // Decode byte stream according to given document type.
    decode(p0, p1, p2, p3, p4, p5, wm, (void*) &wmc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p8, p9);

    fwprintf(stderr, L"TEST receive file system decode mc: %i\n", *((int*) p1));
    fwprintf(stderr, L"TEST receive file system decode dc: %i\n", *((int*) p4));

    // Deallocate wide character model.
    deallocate((void*) &wm, (void*) &wms, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_SYSTEM_RECEIVING_COMMUNICATOR_SOURCE */
#endif
