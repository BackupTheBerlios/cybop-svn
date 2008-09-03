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
 * @version $RCSfile: file_system_receiving_communicator.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:03:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SYSTEM_RECEIVER_SOURCE
#define FILE_SYSTEM_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter/compound_converter.c"
#include "../../memoriser/converter.c"

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
void receive_file_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive file system message.");

    //?? The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = *NUMBER_0_INTEGER_MEMORY_MODEL;
    //?? If the abstraction is "compound", then a cybol (xml) file representing
    //?? a compound model is expected, so that the libxml2 parser is to be used.
    //?? Otherwise, the flag remains zero and the file is read and parsed normally.
    compare_arrays(p8, p9, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &w, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    if (w != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        decode(p0, p1, p2, p3, p4, p5, p6, p7, *NULL_POINTER, *NULL_POINTER, p8, p9);

    } else {

        //
        // Read.
        //

        // The read model.
        void* rm = *NULL_POINTER_MEMORY_MODEL;
        int rmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int rms = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Allocate read model of type character, to read single bytes.
        allocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

        // Read persistent byte stream over channel.
        read_data((void*) &rm, (void*) &rmc, (void*) &rms, p6, p7, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT);

        //
        // Decode.
        //

        // Decode byte stream according to given document type.
        decode(p0, p1, p2, p3, p4, p5, rm, (void*) &rmc, *NULL_POINTER, *NULL_POINTER, p8, p9);

        // Deallocate read model.
        deallocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_SYSTEM_RECEIVER_SOURCE */
#endif
