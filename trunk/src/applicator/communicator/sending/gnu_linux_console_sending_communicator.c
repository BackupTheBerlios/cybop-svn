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
 * @version $RCSfile: gnu_linux_console_sending_communicator.c,v $ $Revision: 1.14 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GNU_LINUX_CONSOLE_SENDING_COMMUNICATOR_SOURCE
#define GNU_LINUX_CONSOLE_SENDING_COMMUNICATOR_SOURCE

#include <stdio.h>
#include <unistd.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/internal_memory_memory_name.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../executor/converter/decoder.c"
#include "../../../executor/converter/encoder/gnu_linux_console_encoder.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../executor/memoriser/deallocator.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sends a textual user interface (tui) via gnu/linux console.
 *
 * @param p0 the internal memory
 * @param p1 the source root abstraction
 * @param p2 the source root abstraction count
 * @param p3 the source root model (root window compound model)
 * @param p4 the source root model count
 * @param p5 the source root details (meta properties of root window compound model)
 * @param p6 the source root details count
 * @param p7 the source area to be repainted part name
 * @param p8 the source area to be repainted part name count
 * @param p9 the source clean flag
 * @param p10 the source clean flag count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 */
void communicate_sending_gnu_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send gnu/linux console message.");

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    if (p9 != *NULL_POINTER_MEMORY_MODEL) {

        int* f = (int*) p9;

        if (*f != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append((void*) &s, sc, ss, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            append((void*) &s, sc, ss, (void*) ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL, (void*) ERASE_DISPLAY_ESCAPE_CONTROL_SEQUENCE_GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        }
    }

    // Encode textual user interface (tui) into array.
    encode_gnu_linux_console((void*) &s, sc, ss, p1, p2, p3, p4, p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p7, p8, p11, p12);

    // The encoded character array.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    void* ec = *NULL_POINTER_MEMORY_MODEL;
    void* es = *NULL_POINTER_MEMORY_MODEL;

    // Allocate encoded character array.
    //
    // CAUTION! Use a standard (non-wide) character vector here,
    // because the source is handed over as utf-8 encoded multibyte characters
    // and will be forwarded as such to the gnu linux console!
    allocate_model((void*) &e, (void*) &ec, (void*) &es, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8_unicode_character_vector((void*) &e, ec, es, s, sc);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

    // The gnu/linux console output stream.
    void** op = NULL_POINTER_MEMORY_MODEL;

    // Get gnu/linux console output stream.
    get_array_elements((void*) &op, p0, (void*) GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

    // Send encoded array as message to shell standard output.
    send_data((void*) op, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, e, ec, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

    // Deallocate encoded character array.
    deallocate_model((void*) &e, (void*) &ec, (void*) &es, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
}

/* GNU_LINUX_CONSOLE_SENDING_COMMUNICATOR_SOURCE */
#endif
