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
 * @version $RCSfile: file_system_receiving_communicator.c,v $ $Revision: 1.17 $ $Date: 2009-01-09 23:15:15 $ $Author: christian $
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

    fwprintf(stdout, L"TEST receive file lc: %i\n", *((int*) p9));
    fwprintf(stdout, L"TEST receive file l: %ls\n", (wchar_t*) p8);

    // The encoded character array.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int es = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate encoded character array.
    allocate((void*) &e, (void*) &es, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST receive file 0: %i\n", *((int*) p9));

    // Write file into encoded character array.
    read_data((void*) &e, (void*) &ec, (void*) &es, p6, p7, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);

    fwprintf(stdout, L"TEST receive file 1: %i\n", *((int*) p9));

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST receive file 2: %i\n", *((int*) p9));

    // Decode encoded character array into serialised wide character array.
    decode_utf_8_unicode_character_vector((void*) &s, (void*) &sc, (void*) &ss, e, (void*) &ec);

    fwprintf(stdout, L"TEST receive file 3: %i\n", *((int*) p9));

    // Deallocate encoded character array.
    deallocate((void*) &e, (void*) &es, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST receive file 4: %i\n", *((int*) p9));

    // Deserialise serialised wide character array into destination knowledge model.
    decode(p0, p1, p2, p3, p4, p5, s, (void*) &sc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p8, p9);

    fwprintf(stdout, L"TEST receive file 5: %i\n", *((int*) p9));

    // Deallocate serialised wide character array.
    deallocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST receive file 6: %i\n", *((int*) p9));

//?? TEST BEGIN
    fwprintf(stdout, L"TEST model diagram mc: %i\n", *((int*) p1));
    fwprintf(stdout, L"TEST model diagram dc: %i\n", *((int*) p4));
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    fwprintf(stdout, L"TEST model diagram between dc: %i\n", *((int*) p4));
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                p0, p1, p3, p4);
    fwprintf(stdout, L"TEST model diagram mdc: %i\n", mdc);
    fwprintf(stdout, L"TEST model diagram md: %ls\n", (wchar_t*) md);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
    fwprintf(stdout, L"TEST model diagram mbc: %i\n", mbc);
            // The file name.
            void* fn = L"TEST_CREATE.txt";
            int fnc = *NUMBER_15_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_16_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    fwprintf(stdout, L"TEST model diagram end: %i\n", mdc);
//?? TEST END
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_SYSTEM_RECEIVING_COMMUNICATOR_SOURCE */
#endif
