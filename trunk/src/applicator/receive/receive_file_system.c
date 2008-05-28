/*
 * $RCSfile: receive_file_system.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.24 $ $Date: 2008-05-28 22:39:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_FILE_SYSTEM_SOURCE
#define RECEIVE_FILE_SYSTEM_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
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

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Receive file system message.");

    //?? The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = *NUMBER_0_INTEGER;
    //?? If the abstraction is "compound", then a cybol (xml) file representing
    //?? a compound model is expected, so that the libxml2 parser is to be used.
    //?? Otherwise, the flag remains zero and the file is read and parsed normally.
    compare_arrays(p8, p9, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &w, (void*) WIDE_CHARACTER_ARRAY);

    if (w != *NUMBER_0_INTEGER) {

        decode(p0, p1, p2, p3, p4, p5, p6, p7, *NULL_POINTER, *NULL_POINTER, p8, p9);

    } else {

        //
        // Read.
        //

        // The read model.
        void* rm = *NULL_POINTER;
        int rmc = *NUMBER_0_INTEGER;
        int rms = *NUMBER_0_INTEGER;

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

/* RECEIVE_FILE_SYSTEM_SOURCE */
#endif
