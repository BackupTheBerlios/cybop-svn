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
 * @version $RCSfile: file_system_sending_communicator.c,v $ $Revision: 1.5 $ $Date: 2008-09-14 21:29:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SYSTEM_SENDER_SOURCE
#define FILE_SYSTEM_SENDER_SOURCE

#include <stdio.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/allocator.c"
#include "../../../memoriser/converter.c"
#include "../../../memoriser/communicator.c"

/**
 * Sends a knowledge model as byte stream to the operating system's file system.
 *
 * @param p0 the internal memory
 * @param p1 the source name
 * @param p2 the source name count
 * @param p3 the source abstraction
 * @param p4 the source abstraction count
 * @param p5 the source model
 * @param p6 the source model count
 * @param p7 the source details
 * @param p8 the source details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the language model
 * @param p12 the language model count
 * @param p13 the source clean flag
 * @param p14 the source clean flag count
 * @param p15 the file name
 * @param p16 the file name count
 */
void send_file_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send file system message.");

    // The encoded string array to be sent to the file.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int ac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int as = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate array.
    allocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Encode knowledge model into model diagram (hierarchical text).
    encode((void*) &a, (void*) &ac, (void*) &as, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    // Write encoded array as message to file system.
    write_data((void*) &p15, p16, *NULL_POINTER_MEMORY_MODEL, a, (void*) &ac, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);

    // Deallocate array.
    deallocate((void*) &a, (void*) &as, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
}

/* FILE_SYSTEM_SENDER_SOURCE */
#endif
