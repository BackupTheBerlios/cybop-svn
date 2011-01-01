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
 * @version $RCSfile: inline_receiving_communicator.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INLINE_RECEIVING_COMMUNICATOR_SOURCE
#define INLINE_RECEIVING_COMMUNICATOR_SOURCE

#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../executor/converter/decoder.c"
#include "../../../logger/logger.c"

/**
 * Receives a message from inline, that is from a string of characters.
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
void communicate_receiving_inline(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Receive inline message.");

    // The read model.
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    int rmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int rms = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate read model.
    allocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Read persistent byte stream over channel.
    receive_data((void*) &rm, (void*) &rmc, (void*) &rms, p6, p7, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) INLINE_CYBOL_CHANNEL, (void*) INLINE_CYBOL_CHANNEL_COUNT);

    // CAUTION! Do NOT try to decode from UTF-8 or other formats here!
    // In other words, do NOT call a function such as this:
    // decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, rm, (void*) &rmc);
    //
    // The reason is that each file is already decoded when being read,
    // from a multibyte character array into a wide character array.
    // Therefore, data do NOT have to be decoded once more when being
    // evaluated as inline wide character array.

    // Decode byte stream according to given document type.
    decode(p0, p1, p2, p3, p4, p5, rm, (void*) &rmc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p8, p9);

    // Deallocate read model.
    deallocate((void*) &rm, (void*) &rms, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* INLINE_RECEIVING_COMMUNICATOR_SOURCE */
#endif
