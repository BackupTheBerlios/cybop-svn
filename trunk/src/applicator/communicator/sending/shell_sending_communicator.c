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
 * @version $RCSfile: shell_sending_communicator.c,v $ $Revision: 1.12 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHELL_SENDING_COMMUNICATOR_SOURCE
#define SHELL_SENDING_COMMUNICATOR_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/stream_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../executor/converter/decoder.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sends a knowledge model to the operating system shell's standard output.
 *
 * @param p0 the internal memory
 * @param p1 the source abstraction
 * @param p2 the source abstraction count
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source details
 * @param p6 the source details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 * @param p9 the language model
 * @param p10 the language model count
 * @param p11 the source clean flag
 * @param p12 the source clean flag count
 * @param p13 the source new line flag
 * @param p14 the source new line flag count
 */
void communicate_sending_shell(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send shell message.");

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

    // Serialise source knowledge model into serialised wide character array.
    encode((void*) &s, (void*) &sc, (void*) &ss, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

    if (p13 != *NULL_POINTER_MEMORY_MODEL) {

        int* nl = (int*) p13;

        if (*nl != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append((void*) &s, (void*) &sc, (void*) &ss, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    // The encoded character array.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int es = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate encoded character array.
    allocate((void*) &e, (void*) &es, (void*) CHARACTER_MEMORY_ABSTRACTION);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8_unicode_character_vector((void*) &e, (void*) &ec, (void*) &es, s, (void*) &sc);

    // Deallocate serialised wide character array.
    deallocate((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

    // Write encoded array as message to shell standard output.
    write_data((void*) &STANDARD_OUTPUT_STREAM_MODEL, (void*) STANDARD_OUTPUT_STREAM_MODEL_COUNT, *NULL_POINTER_MEMORY_MODEL, e, (void*) &ec, (void*) FILE_CYBOL_CHANNEL, (void*) FILE_CYBOL_CHANNEL_COUNT);

    // Deallocate encoded character array.
    deallocate((void*) &e, (void*) &es, (void*) CHARACTER_MEMORY_ABSTRACTION);
}

/* SHELL_SENDING_COMMUNICATOR_SOURCE */
#endif
