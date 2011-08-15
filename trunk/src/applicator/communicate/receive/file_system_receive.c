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
 * @version $RCSfile: file_system_receiving_communicator.c,v $ $Revision: 1.20 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SYSTEM_RECEIVE_SOURCE
#define FILE_SYSTEM_RECEIVE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/decoder.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Applies the receive file system operation.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the message (file name)
 * @param p7 the message (file name) count
 * @param p8 the language
 * @param p9 the language count
 */
void apply_receive_file_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply receive file system.");

    // The encoded array, count, size.
    void* ea = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int es = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate encoded array.
    allocate_array((void*) &ea, (void*) &es, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Write file into encoded array.
    receive_data((void*) &ea, (void*) &ec, (void*) &es, p6, p7, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) FILE_SYSTEM_CYBOL_CHANNEL, (void*) FILE_SYSTEM_CYBOL_CHANNEL_COUNT);

//??fwprintf(stdout, L"TEST char: %s\n", (char*) ea);

    // The decoded array, count, size.
    void* da = *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate decoded array.
    allocate_array((void*) &da, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Decode encoded character array into decoded wide character array.
    decode_utf_8_unicode_character_vector((void*) &da, (void*) &dc, (void*) &ds, ea, (void*) ec);

//??fwprintf(stdout, L"TEST w_char: %ls\n", (wchar_t*) da);

    // Deallocate encoded array.
    deallocate_array((void*) &ea, (void*) &es, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Deserialise serialised wide character array into destination knowledge model.
    decode(p0, p1, p2, p3, p4, p5, da, (void*) &dc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p8, p9);

    // Deallocate decoded array.
    deallocate_array((void*) &da, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_SYSTEM_RECEIVE_SOURCE */
#endif
